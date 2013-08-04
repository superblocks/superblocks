// superblocks.hpp 
// Superblocks - Version 0.4

#include <iostream>
#include <string>
#include <string.h>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

using namespace std;
using namespace boost;

// Seed Types:
#define SEED_WITH_BLOCK_HEIGHT 1
#define SEED_WITH_PREVIOUS_BLOCK_HASH 2

// Luck Types:
#define LUCK_WITH_LESS_THAN_X 1
#define LUCK_WITH_MORE_THAN_X 2
#define LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y 3

class Superblocks {

  public:

    int debug;

    string coin;
    string coin_name;

    int hash_length;

    int seed_type[LUCK_STEPS];

    int cutout_start[LUCK_STEPS];
    int cutout_length[LUCK_STEPS];

    int rnd_range_low[LUCK_STEPS];
    int rnd_range_high[LUCK_STEPS];

    int luck_type[LUCK_STEPS];

    int luck_x[LUCK_STEPS];
    int luck_y[LUCK_STEPS];

    int reward[LUCK_STEPS];

    void init();

    int getnextblockreward( const char* hash );

    int static generateMTRandom(unsigned int s, int range);

    long hex2long(const char* hexString);


};

