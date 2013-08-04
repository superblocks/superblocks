// Get Next Block Reward: [SPT] Spots
// Superblocks - Version 0.4

#include "superblocks.hpp" 

void Superblocks::init() {

  coin = "SPT"; 
	coin_name = "Spots";

	hash_length = 64;

	// normal (step 0)
	reward[0] = 49;

	// superblock (step 1)
	reward[1] = 10045; // superblock reward (step 1)
	seed_type[1] = SEED_WITH_PREVIOUS_BLOCK_HASH;
	cutout_start[1] = 8;
	cutout_length[1] = 7;
	rnd_range_low[1] = 1;
	rnd_range_high[1] = 100000;
	luck_type[1] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[1] = 50000;
	luck_y[1] = 50011;

}

