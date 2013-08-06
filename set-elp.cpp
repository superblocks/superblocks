// Get Next Block Reward: [ELP] Elephantcoin 
// Superblocks - Version 0.4.3

#include "superblocks.hpp" 

void Superblocks::init() {

	coin = "ELP"; 
	coin_name = "Elephantcoin";

	hash_length = 64;

	// normal (step 0)
	reward[0] = 50;

	// superblock (step 1)
	seed_type[1] = SEED_WITH_PREVIOUS_BLOCK_HASH;
	cutout_start[1] = 5;
	cutout_length[1] = 7;
	rnd_range_low[1] = 1;
	rnd_range_high[1] = 600000;
	luck_type[1] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[1] = 300000;
	luck_y[1] = 300021;
	//reward[1] = "rand1 = generateMTRandom(rand, 10001); nSubsidy = (10000 + rand1 - 1) * COIN;";
		secondary_rand[1] = 1;
		secondary_rand_type[1] = SECONDARY_REWARD_PLUS_RAND_MINUS_X;
		secondary_rand_low[1] = 1;
		secondary_rand_high[1] = 10001;
		secondary_rand_x[1] = 1;
	reward[1] = 10000;

	// superblock (step 2+)

	luck_type[2] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[2] = 100000;
	luck_y[2] = 100301;
	//reward[2] = "rand1 = generateMTRandom(rand, 4001); nSubsidy = (1000 + rand1 - 1) * COIN;";
		secondary_rand[2] = 1;
		secondary_rand_type[2] = SECONDARY_REWARD_PLUS_RAND_MINUS_X;
		secondary_rand_low[2] = 1;
		secondary_rand_high[2] = 4001;
		secondary_rand_x[2] = 1;
	reward[2] = 1000;

	luck_type[3] = LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y;
	luck_x[3] = 500000;
	luck_y[3] = 506001;
	//reward[3] = "rand1 = generateMTRandom(rand, 401); nSubsidy = (100 + rand1 - 1) * COIN;";
		secondary_rand[3] = 1;
		secondary_rand_type[3] = SECONDARY_REWARD_PLUS_RAND_MINUS_X;
		secondary_rand_low[3] = 1;
		secondary_rand_high[3] = 401;
		secondary_rand_x[3] = 1;
	reward[3] = 100;

}

