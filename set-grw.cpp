// Get Next Block Reward: [GRW] Growthcoin 
// Superblocks - Version 0.4.3

#include "superblocks.hpp" 

void Superblocks::init() {

  coin = "GRW"; 
	coin_name = "Growthcoin";

	hash_length = 64;

	// normal (step 0)
	reward[0] = 100;

	// superblocks

	seed_type[1] = SEED_WITH_PREVIOUS_BLOCK_HASH;
	cutout_start[1] = 7;
	cutout_length[1] = 7;
	rnd_range_low[1] = 1;
	rnd_range_high[1] = 8000;
	luck_type[1] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[1] = 5000;
	luck_y[1] = 5101;
		secondary_rand[1] = 1;
		secondary_rand_type[1] = SECONDARY_REWARD_PLUS_RAND_MINUS_X;
		secondary_cutout_start[1] = 10;
		secondary_cutout_length[1] = 7; 
		secondary_rand_low[1] = 1;
		secondary_rand_high[1] = 501;
		secondary_rand_x[1] = 0;
	reward[1] = 499;

}

