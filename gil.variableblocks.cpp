// GIL variable blocks
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

        std::string cseed_str = prevHash_string.substr(8,7);
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

        // int rand = generateMTRandom(seed, 400000);
        random::mt19937 gen(seed);
        random::uniform_int_distribution<> dist(1, 400000);
        int rand = dist(gen);
        printf("rand: %d\n", rand);


        static const int COIN = 1;
        int nSubsidy;

        if(rand < 10000)
                nSubsidy = 10 * COIN;
        else if(rand < 20000)
                nSubsidy = 11 * COIN;
        else if(rand < 30000)
                nSubsidy = 12 * COIN;
        else if(rand < 40000)
                nSubsidy = 13 * COIN;
        else if(rand < 50000)
                nSubsidy = 14 * COIN;
        else if(rand < 60000)
                nSubsidy = 15 * COIN;
        else if(rand < 70000)
                nSubsidy = 16 * COIN;
        else if(rand < 80000)
                nSubsidy = 17 * COIN;
        else if(rand < 90000)
                nSubsidy = 18 * COIN;
        else if(rand < 100000)
                nSubsidy = 19 * COIN;
        else if(rand < 110000)
                nSubsidy = 20 * COIN;
        else if(rand < 120000)
                nSubsidy = 21 * COIN;
        else if(rand < 130000)
                nSubsidy = 22 * COIN;
        else if(rand < 140000)
                nSubsidy = 23 * COIN;
        else if(rand < 150000)
                nSubsidy = 24 * COIN;
        else if(rand < 160000)
                nSubsidy = 25 * COIN;
        else if(rand < 170000)
                nSubsidy = 26 * COIN;
        else if(rand < 180000)
                nSubsidy = 27 * COIN;
        else if(rand < 190000)
                nSubsidy = 28 * COIN;
        else if(rand < 200000)
                nSubsidy = 29 * COIN;
        else if(rand < 210000)
                nSubsidy = 30 * COIN;
        else if(rand < 220000)
                nSubsidy = 31 * COIN;
        else if(rand < 230000)
                nSubsidy = 32 * COIN;
        else if(rand < 240000)
                nSubsidy = 33 * COIN;
        else if(rand < 250000)
                nSubsidy = 34 * COIN;
        else if(rand < 260000)
                nSubsidy = 35 * COIN;
        else if(rand < 270000)
                nSubsidy = 36 * COIN;
        else if(rand < 280000)
                nSubsidy = 37 * COIN;
        else if(rand < 290000)
                nSubsidy = 38 * COIN;
        else if(rand < 300000)
                nSubsidy = 39 * COIN;
        else if(rand < 310000)
                nSubsidy = 40 * COIN;
        else if(rand < 320000)
                nSubsidy = 41 * COIN;
        else if(rand < 330000)
                nSubsidy = 42 * COIN;
        else if(rand < 340000)
                nSubsidy = 43 * COIN;
        else if(rand < 350000)
                nSubsidy = 44 * COIN;
        else if(rand < 360000)
                nSubsidy = 45 * COIN;
        else if(rand < 370000)
                nSubsidy = 46 * COIN;
        else if(rand < 380000)
                nSubsidy = 47 * COIN;
        else if(rand < 390000)
                nSubsidy = 48 * COIN;
        else if(rand < 400000)
                nSubsidy = 49 * COIN;
        else if(rand < 410001)
                nSubsidy = 50 * COIN;

        printf("Assuming nHeight > 3000\n");
        printf("Next Block Reward: %d\n", nSubsidy);
        return 0;
}

