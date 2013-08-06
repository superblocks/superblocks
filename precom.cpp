// precom.cpp
// Superblocks - Version 0.4.3

#include "superblocks.hpp"

int main( int argc, char **argv )
{

  Superblocks s;
	s.timer_start();
	s.init();
	s.debug = 0;

	int step = 1;
	cout << "# Lucky Hash Cut Outs" << endl;
	cout << "# for: [" << s.coin << "] " << s.coin_name << endl;
	cout << "# cutout: start: " << s.cutout_start[step] << endl;
	cout << "# cutout: length: " << s.cutout_length[step] << endl;
	cout << "# reward[0]: " << s.reward[0] << endl;

	cout << "# CUTOUT, reward" << endl;

	int found = 0;
	long x;

	int seed_low  = 0; // = 0000000
	int seed_high = 268435455; // = fffffff
	//int seed_high = 12356; // test

	for (x = seed_low; x <= seed_high; x++) {

		int rand = s.generateMTRandom(x, s.rnd_range_low[step], s.rnd_range_high[step]);

		switch( s.luck_type[step] ) {
			default: 
				cout << "error: unknown luck type" << endl;
				return 0;
			case 1: // LUCK_WITH_LESS_THAN_X
				if( rand < s.luck_x[step] ) { 
					found++; 
					//printf("%07x, %d, %d\n", x, x, rand); 
					printf("%07x, %d\n", x, s.reward[step]); 
				}	
				break;
			case 3: // LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y
				if( rand > s.luck_x[step] && rand < s.luck_y[step] ) { 
					found++; 
					//printf("%07x, %d, %d\n", x, x, rand); 
					printf("%07x, %d\n", x, s.reward[step]); 
				}	
				break;
		}

	}

	cout << "# found: " << found << endl;
	cout << "# seconds: " << s.timer_end() << endl;

	return 0;

}

