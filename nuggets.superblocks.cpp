// NUG superblocks
#include <stdio.h>
#include <string>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
using namespace std;
using namespace boost;

int main( int argc, char **argv ) {

        const char* prevHash = argv[1];
        printf("prevHash: %s\n", prevHash);

        string prevHash_string(argv[1]);

        std::string cseed_str = prevHash_string.substr(55,7);
        const char* cseed = cseed_str.c_str();
        printf("cseed: %s\n", cseed);

//      long seed = hex2long(cseed);
        static const long hextable[] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 10-19
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 30-39
        -1, -1, -1, -1, -1, -1, -1, -1, 0, 1,
        2, 3, 4, 5, 6, 7, 8, 9, -1, -1, // 50-59
        -1, -1, -1, -1, -1, 10, 11, 12, 13, 14,
        15, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 70-79
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, 10, 11, 12, // 90-99
        13, 14, 15, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 110-109
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 130-139
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 150-159
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 170-179
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 190-199
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 210-219
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 230-239
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1
        };

        long seed = 0;
        while (*cseed && seed >= 0) {
                seed = (seed << 4) | hextable[*cseed++];
        }

        printf("seed: %d\n", seed);

        // int rand = generateMTRandom(seed, 1000000);
        random::mt19937 gen(seed);
        random::uniform_int_distribution<> dist(1, 1000000);
        int rand = dist(gen);
        printf("rand: %d\n", rand);

        int lucky = 9723;
        printf("lucky: < %d\n", lucky);
        if(rand < lucky) {
                printf("Next Block: nSubsidy = 10045 * COIN\n");
        } else {
                printf("Next Block: normal\n");
        }

        return 0;
}

