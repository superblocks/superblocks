// Get Next Block Reward: [RED] Redcoin 
// Superblocks - Version 0.4.3

#include "superblocks.hpp" 

void Superblocks::init() {

  coin = "RED"; 
	coin_name = "Redcoin";

	hash_length = 64;

	// normal (step 0)
	reward[0] = 50;
		secondary_rand[0] = 1;
		cutout_start[0] = 6;
		cutout_length[0] = 7;
		secondary_rand_type[0] = SECONDARY_REWARD_PLUS_RAND_MINUS_X;
		secondary_rand_low[0] = 0;
		secondary_rand_high[0] = 100;
		secondary_rand_x[0] = 0;

	// superblock (step 1)
	seed_type[1] = SEED_WITH_PREVIOUS_BLOCK_HASH;
	cutout_start[1] = 1;
	cutout_length[1] = 7;
	rnd_range_low[1] = 0;
	rnd_range_high[1] = 99999;
	luck_type[1] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[1] = 30000;
	luck_y[1] = 30006;
		secondary_rand[1] = 1;
		secondary_rand_type[1] = SECONDARY_REWARD_PLUS_RAND_MINUS_X;
		secondary_rand_low[1] = 0;
		secondary_rand_high[1] = 5000;
		secondary_rand_x[1] = 0;
	reward[1] = 5000;

}

