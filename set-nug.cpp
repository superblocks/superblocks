// Get Next Block Reward: [NUG] Nuggets
// Superblocks - Version 0.4.3

#include "superblocks.hpp" 

void Superblocks::init() {

	coin = "NUG"; 
	coin_name = "Nuggets";

	hash_length = 64;

	// normal (step 0)
	reward[0] = 49;

	// superblock (step 1)
	reward[1] = 10045; // superblock reward (step 1)
	seed_type[1] = SEED_WITH_PREVIOUS_BLOCK_HASH;
	cutout_start[1] = 55;
	cutout_length[1] = 7;
	rnd_range_low[1] = 1;
	rnd_range_high[1] = 1000000;
	luck_type[1] = LUCK_WITH_LESS_THAN_X;
	luck_x[1] = 9723;

}

