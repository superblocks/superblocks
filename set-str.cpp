// Get Next Block Reward: [STR] Starcoin 
// Superblocks - Version 0.4.3

#include "superblocks.hpp" 

void Superblocks::init() {

  coin = "STR"; 
	coin_name = "Starcoin";

	hash_length = 64;

	// normal (step 0)
	reward[0] = 100;

	// superblocks

	seed_type[1] = SEED_WITH_PREVIOUS_BLOCK_HASH;
	cutout_start[1] = 5;
	cutout_length[1] = 7;
	rnd_range_low[1] = 1;
	rnd_range_high[1] = 14400;
	luck_type[1] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[1] = 10000;
	luck_y[1] = 10121;
		secondary_rand[1] = 1;
		secondary_rand_type[1] = SECONDARY_REWARD_PLUS_RAND_MINUS_X;
		secondary_cutout_start[1] = 6;
		secondary_cutout_length[1] = 7; 
		secondary_rand_low[1] = 1;
		secondary_rand_high[1] = 601;
		secondary_rand_x[1] = 1;
	reward[1] = 200;


	seed_type[2] = SEED_WITH_PREVIOUS_BLOCK_HASH;
	cutout_start[2] = 5;
	cutout_length[2] = 7;
	rnd_range_low[2] = 1;
	rnd_range_high[2] = 14400;
	luck_type[2] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[2] = 4000;
	luck_y[2] = 4011;
		secondary_rand[2] = 1;
		secondary_rand_type[2] = SECONDARY_REWARD_PLUS_RAND_MINUS_X;
		secondary_cutout_start[2] = 7;
		secondary_cutout_length[2] = 7;
		secondary_rand_low[2] = 1;
		secondary_rand_high[2] = 6001;
		secondary_rand_x[2] = 1;
	reward[2] = 2000;


	seed_type[3] = SEED_WITH_PREVIOUS_BLOCK_HASH;
	cutout_start[3] = 6;
	cutout_length[3] = 7;
	rnd_range_low[3] = 1;
	rnd_range_high[3] = 500000;
	luck_type[3] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[3] = 300000;
	luck_y[3] = 300026;
		secondary_rand[3] = 1;
		secondary_rand_type[3] = SECONDARY_REWARD_PLUS_RAND_MINUS_X;
		secondary_cutout_start[3] = 4;
		secondary_cutout_length[3] = 7;
		secondary_rand_low[3] = 1;
		secondary_rand_high[3] = 20001;
		secondary_rand_x[3] = 1;
	reward[3] = 10000;


	seed_type[4] = SEED_WITH_PREVIOUS_BLOCK_HASH;
	cutout_start[4] = 6;
	cutout_length[4] = 7;
	rnd_range_low[4] = 1;
	rnd_range_high[4] = 500000;
	luck_type[4] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[4] = 460000;
	luck_y[4] = 460003;
	reward[4] = 100000;



}

