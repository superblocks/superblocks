// Get Next Block Reward: [LKY] Luckycoin
// Superblocks - Version 0.4.2

#include "superblocks.hpp" 

void Superblocks::init() {

	coin = "LKY"; 
	coin_name = "Luckycoin";

	hash_length = 64;

	// normal (step 0)
	reward[0] = 88;

	// superblock (step 1)
	seed_type[1] = SEED_WITH_PREVIOUS_BLOCK_HASH;
	cutout_start[1] = 8;
	cutout_length[1] = 7;
	rnd_range_low[1] = 1;
	rnd_range_high[1] = 100000;
	luck_type[1] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[1] = 30000;
	luck_y[1] = 35001;
	reward[1] = 176;

	// superblock (step 2)
	luck_type[2] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[2] = 70000;
	luck_y[2] = 71001;
	reward[2] = 440;

	// superblock (step 3)
	luck_type[3] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[3] = 50000;
	luck_y[3] = 50011;
	reward[3] = 5104;

}

