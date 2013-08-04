// superblocks.hpp 
// Superblocks - Version 0.4.2

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

// Secondary Luck Types:
#define SECONDARY_REWARD_PLUS_RAND_MINUS_X 1

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

    int secondary_rand[LUCK_STEPS]; // do secondary rand step?
    int secondary_rand_type[LUCK_STEPS]; 
    int secondary_rand_low[LUCK_STEPS];
    int secondary_rand_high[LUCK_STEPS];
    int secondary_rand_x[LUCK_STEPS];

    int luck_type[LUCK_STEPS];

    int luck_x[LUCK_STEPS];
    int luck_y[LUCK_STEPS];

    int reward[LUCK_STEPS];

    void init();

    int getnextblockreward( const char* hash ); // in superblocks.cpp

    int getsecondaryreward( int seed, int step ); // in superblocks.cpp

    int static generateMTRandom(unsigned int s, int range); // in utils.cpp

    long hex2long(const char* hexString); // in utils.cpp


  string getseedtype( int type ) 
	{
		switch( type ) {
			case 1: return "SEED_WITH_BLOCK_HEIGHT";
			case 2: return "SEED_WITH_PREVIOUS_BLOCK_HASH";
			default: return "error";
		}	
	}
	string getlucktype( int type ) 
	{
		switch( type ) {
			case 1: return "LUCK_WITH_LESS_THAN_X";
			case 2: return "LUCK_WITH_MORE_THAN_X";
			case 3: return "LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y";
			default: return "error";
		}
	}
	string getsecondarylucktype( int type ) 
	{
		switch( type ) {
			case 1: return "SECONDARY_REWARD_PLUS_RAND_MINUS_X";
			default: return "error";
		}
	}

};

