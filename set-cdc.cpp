// Get Next Block Reward: [CDC] Cloudcoin 
// Superblocks - Version 0.4.3

#include "superblocks.hpp" 

void Superblocks::init() {

  coin = "CDC"; 
	coin_name = "Cloudcoin";

	hash_length = 64;

	// normal (step 0)
	reward[0] = 50;

	// superblocks

	seed_type[1] = SEED_WITH_PREVIOUS_BLOCK_HASH;
	cutout_start[1] = 6;
	cutout_length[1] = 7;
	rnd_range_low[1] = 1;
	rnd_range_high[1] = 14400;
	luck_type[1] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[1] = 10000;
	luck_y[1] = 10011;
	reward[1] = 4400;

	luck_type[2] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[2] = 2000;
	luck_y[2] = 2031;
	reward[2] = 900;

	luck_type[3] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[3] = 8000;
	luck_y[3] = 8101;
	reward[3] = 400;

}

