// Get Next Block Reward: [GIL] Gil
// Superblocks - Version 0.4.3

#include "superblocks.hpp"

void Superblocks::init() {

	coin = "GIL";
	coin_name = "Gil";

	hash_length = 64;

	// normal (step 0)
	reward[0] = 0;

	// variable block (step 1)
	reward[1] = 10;
	seed_type[1] = SEED_WITH_PREVIOUS_BLOCK_HASH;
	cutout_start[1] = 8;
	cutout_length[1] = 7;
	rnd_range_low[1] = 1;
	rnd_range_high[1] = 400000;
	reward[1]  = 10;  luck_x[1] =  10000; luck_type[1]  = LUCK_WITH_LESS_THAN_X;

	// variable blocks (step 2+)
	reward[2]  = 11; luck_x[2]  =  20000; luck_type[2]  = LUCK_WITH_LESS_THAN_X;
	reward[3]  = 12; luck_x[3]  =  30000; luck_type[3]  = LUCK_WITH_LESS_THAN_X;
	reward[4]  = 13; luck_x[4]  =  40000; luck_type[4]  = LUCK_WITH_LESS_THAN_X;
	reward[5]  = 14; luck_x[5]  =  50000; luck_type[5]  = LUCK_WITH_LESS_THAN_X;
	reward[6]  = 15; luck_x[6]  =  60000; luck_type[6]  = LUCK_WITH_LESS_THAN_X;
	reward[7]  = 16; luck_x[7]  =  70000; luck_type[7]  = LUCK_WITH_LESS_THAN_X;
	reward[8]  = 17; luck_x[8]  =  80000; luck_type[8]  = LUCK_WITH_LESS_THAN_X;
	reward[9]  = 18; luck_x[9]  =  90000; luck_type[9]  = LUCK_WITH_LESS_THAN_X;
	reward[10] = 19; luck_x[10] = 100000; luck_type[10] = LUCK_WITH_LESS_THAN_X;
	reward[11] = 20; luck_x[11] = 110000; luck_type[11] = LUCK_WITH_LESS_THAN_X;
	reward[12] = 21; luck_x[12] = 120000; luck_type[12] = LUCK_WITH_LESS_THAN_X;
	reward[13] = 22; luck_x[13] = 130000; luck_type[13] = LUCK_WITH_LESS_THAN_X;
	reward[14] = 23; luck_x[14] = 140000; luck_type[14] = LUCK_WITH_LESS_THAN_X;
	reward[15] = 24; luck_x[15] = 150000; luck_type[15] = LUCK_WITH_LESS_THAN_X;
	reward[16] = 25; luck_x[16] = 160000; luck_type[16] = LUCK_WITH_LESS_THAN_X;
	reward[17] = 26; luck_x[17] = 170000; luck_type[17] = LUCK_WITH_LESS_THAN_X;
	reward[18] = 27; luck_x[18] = 180000; luck_type[18] = LUCK_WITH_LESS_THAN_X;
	reward[19] = 28; luck_x[19] = 190000; luck_type[19] = LUCK_WITH_LESS_THAN_X;
	reward[20] = 29; luck_x[20] = 200000; luck_type[20] = LUCK_WITH_LESS_THAN_X;
	reward[21] = 30; luck_x[21] = 210000; luck_type[21] = LUCK_WITH_LESS_THAN_X;
	reward[22] = 31; luck_x[22] = 220000; luck_type[22] = LUCK_WITH_LESS_THAN_X;
	reward[23] = 32; luck_x[23] = 230000; luck_type[23] = LUCK_WITH_LESS_THAN_X;
	reward[24] = 33; luck_x[24] = 240000; luck_type[24] = LUCK_WITH_LESS_THAN_X;
	reward[25] = 34; luck_x[25] = 250000; luck_type[25] = LUCK_WITH_LESS_THAN_X;
	reward[26] = 35; luck_x[26] = 260000; luck_type[26] = LUCK_WITH_LESS_THAN_X;
	reward[27] = 36; luck_x[27] = 270000; luck_type[27] = LUCK_WITH_LESS_THAN_X;
	reward[28] = 37; luck_x[28] = 280000; luck_type[28] = LUCK_WITH_LESS_THAN_X;
	reward[29] = 38; luck_x[29] = 290000; luck_type[29] = LUCK_WITH_LESS_THAN_X;
	reward[30] = 39; luck_x[30] = 300000; luck_type[30] = LUCK_WITH_LESS_THAN_X;
	reward[31] = 40; luck_x[31] = 310000; luck_type[31] = LUCK_WITH_LESS_THAN_X;
	reward[32] = 41; luck_x[32] = 320000; luck_type[32] = LUCK_WITH_LESS_THAN_X;
	reward[33] = 42; luck_x[33] = 330000; luck_type[33] = LUCK_WITH_LESS_THAN_X;
	reward[34] = 43; luck_x[34] = 340000; luck_type[34] = LUCK_WITH_LESS_THAN_X;
	reward[35] = 44; luck_x[35] = 350000; luck_type[35] = LUCK_WITH_LESS_THAN_X;
	reward[36] = 45; luck_x[36] = 360000; luck_type[36] = LUCK_WITH_LESS_THAN_X;
	reward[37] = 46; luck_x[37] = 370000; luck_type[37] = LUCK_WITH_LESS_THAN_X;
	reward[38] = 47; luck_x[38] = 380000; luck_type[38] = LUCK_WITH_LESS_THAN_X;
	reward[39] = 48; luck_x[39] = 390000; luck_type[39] = LUCK_WITH_LESS_THAN_X;
	reward[40] = 49; luck_x[40] = 400000; luck_type[40] = LUCK_WITH_LESS_THAN_X;
	reward[41] = 50; luck_x[41] = 410001; luck_type[41] = LUCK_WITH_LESS_THAN_X;
 
}

