// Get Next Block Reward: [GDC] Grandcoin 
// Superblocks - Version 0.4.3

#include "superblocks.hpp" 

void Superblocks::init() {

  coin = "GDC"; 
	coin_name = "Grandcoin";

	hash_length = 64;

	// normal (step 0)
	reward[0] = 1000;

	// superblocks

	seed_type[1] = SEED_WITH_PREVIOUS_BLOCK_HASH;
	cutout_start[1] = 3;
	cutout_length[1] = 7;
	rnd_range_low[1] = 1;
	rnd_range_high[1] = 19199;
	luck_type[1] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[1] = 10000;
	luck_y[1] = 10011;
		secondary_rand[1] = 1;
		secondary_rand_type[1] = SECONDARY_REWARD_PLUS_RAND_MINUS_X;
		secondary_rand_low[1] = 1;
		secondary_rand_high[1] = 5000;
		secondary_rand_x[1] = 0;
	reward[1] = 5000;


	seed_type[2] = SEED_WITH_PREVIOUS_BLOCK_HASH;
	cutout_start[2] = 6;
	cutout_length[2] = 7;
	rnd_range_low[2] = 1;
	rnd_range_high[2] = 134399;
	luck_type[2] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[2] = 60000;
	luck_y[2] = 60011;
		secondary_rand[2] = 1;
		secondary_rand_type[2] = SECONDARY_REWARD_PLUS_RAND_MINUS_X;
		secondary_rand_low[2] = 1;
		secondary_rand_high[2] = 50000;
		secondary_rand_x[2] = 0;
	reward[2] = 50000;


}

