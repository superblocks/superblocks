//
// Predict next block reward for: Nuggets (NUG)
// reward -  normal: 49 - superblock: 10045 - repo: https://bitbucket.org/mytwobits/nuggets/
//
// Version 0.4
//
// superblock test:  ./nug 86b707fad8477ce7c30bcfdf90e4371bc45751bf76f4b3c3253e3d16a7cc4be3 debug
//
#include <stdio.h>
#include <string.h>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
using namespace std;
using namespace boost;

int static generateMTRandom(unsigned int s, int range) {
        random::mt19937 gen(s);
        random::uniform_int_distribution<> dist(1, range);
        return dist(gen);
}

static const long hextable[] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,         // 10-19
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,         // 30-39
        -1, -1, -1, -1, -1, -1, -1, -1,  0,  1,
         2,  3,  4,  5,  6,  7,  8,  9, -1, -1,         // 50-59
        -1, -1, -1, -1, -1, 10, 11, 12, 13, 14,
        15, -1, -1, -1, -1, -1, -1, -1, -1, -1,         // 70-79
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, 10, 11, 12,         // 90-99
        13, 14, 15, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,         // 110-109
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,         // 130-139
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,         // 150-159
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,         // 170-179
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,         // 190-199
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,         // 210-219
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,         // 230-239
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1 };

long hex2long(const char* hexString) {
        long ret = 0;
        while (*hexString && ret >= 0) {
                ret = (ret << 4) | hextable[*hexString++];
        }
        return ret;
}

int main( int argc, char **argv ) {

        std::string altcoin("NUG");

        int debug = 0;
        int hash_len = 64;

        int substr_start = 55;
        int substr_len = 7;

        int rnd_limit = 1000000;
        int rnd_lucky = 9723;

        int reward_normal = 49;
        int reward_superblock = 10045;

        std::string assuming("nHeight > 6678 && nHeight <= 14726880");

        //////////////////////////////////////

        if( !argv[1] ) { printf("error: missing hash for previous %s block\n", altcoin.c_str()); return 0; }
        if( argv[2] ) { debug = 1; }

        if( debug ) { printf("Predicting next %s block reward:\n", altcoin.c_str()); }
        if( debug ) { printf("Assuming: %s\n", assuming.c_str()); }

        const char* prevHash = argv[1];
        int phlen = strlen(prevHash);
        if( phlen != hash_len ) { printf("error: hash length not %d\n", hash_len); return 0; }
        if( debug ) { printf("prevHash: %s\n", prevHash); }

        std::string prevHash_string(argv[1]);
        std::string cseed_str = prevHash_string.substr( substr_start, substr_len);
        const char* cseed = cseed_str.c_str();
        if( debug ) { printf("cseed: %s\n", cseed); }

        long seed = hex2long(cseed);
        if( debug ) { printf("seed: %d\n", seed); }

        int rand = generateMTRandom(seed, rnd_limit);
        if( debug ) { printf("rand: %d\n", rand); }

        int nSubsidy;

        if( rand < rnd_lucky )
                nSubsidy = reward_superblock;
        else
                nSubsidy = reward_normal;

        if( debug ) { printf("Next %s Block Reward: ", altcoin.c_str()); }
        printf("%d", nSubsidy);

        return 0;
}
