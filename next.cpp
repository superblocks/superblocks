// Get Next Block Reward controller
// Superblocks - Version 0.4.3

#include "superblocks.hpp" 

int Superblocks::getnextblockreward( const char* hash )
{

	if( debug ) { cout << "getnextblockreward: LUCK_STEPS: " << LUCK_STEPS << endl; }

	// normal reward - step 0
	int nextreward = reward[0]; 
	if( debug ) { cout << "getnextblockreward: normal reward: " << nextreward << endl; }
	if( secondary_rand[0] == 1 ) {
		if( debug ) { cout << "getnextblockreward: step 0 secondary: ..." << endl; }
		long s_seed = gethashcutout( 0, hash );
//		if( debug ) { cout << "getnextblockreward: step 0 secondary: MT..." << endl; }
//		int s_rand = generateMTRandom(s_seed, secondary_rand_low[0], secondary_rand_high[0]);
		if( debug ) { cout << "getnextblockreward: step 0 secondary: 2nd...." << endl; }
		nextreward = getsecondaryreward( s_seed, 0 );
		if( debug ) { cout << "getnextblockreward: new reward: " << nextreward << endl; }
	}


	// non-normal rewards  
	int step = 1;
	if( debug ) { cout << "getnextblockreward: step: " << step << endl; }

	long seed = gethashcutout( 1, hash );
	if( debug ) { cout << "getnextblockreward: seed: " << seed << endl; }

	int rand = generateMTRandom(seed, rnd_range_low[step], rnd_range_high[step]);
	if( debug ) { cout << "getnextblockreward: rand: " << rand << endl; }

	if( debug ) { cout << "getnextblockreward: luck_type: " << getlucktype(luck_type[step]) << endl; }

	for (int rstep = 1; rstep < LUCK_STEPS ; rstep++) {

		if( debug ) {
			cout << "getnextblockreward: rstep: " << rstep << endl;
			cout << "getnextblockreward: reward: " << reward[rstep] << endl;
			cout << "getnextblockreward: rand: " << rand << endl; 
		}

		switch( luck_type[rstep] ) { 

		default: 
			cout << "getnextblockreward: error: unknown luck type:" << luck_type[rstep] << endl; 
			return 0; 

		case 1: // LUCK_WITH_LESS_THAN_X 

			if( debug ) { cout << "getnextblockreward: luck_x: " << luck_x[rstep] << endl; }
			if( rand < luck_x[rstep] ) {
				nextreward = reward[rstep];
				if( secondary_rand[rstep] == 1 ) { 
					nextreward = getsecondaryreward( rand, rstep );
				}
				goto final_reward;
			}
			break;

		case 2: // LUCK_WITH_MORE_THAN_X 

			cout << "getnextblockreward: TODO luck type 2 MORE THAN X" << endl; 
			if( debug ) { cout << "getnextblockreward: luck_x: " << luck_x[rstep] << endl; }
			return 0;

		case 3: // LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y

			if( debug ) { cout << "getnextblockreward: luck_x: " << luck_x[rstep] << endl; }
			if( debug ) { cout << "getnextblockreward: luck_y: " << luck_y[rstep] << endl; }
			if( rand > luck_x[rstep] && rand < luck_y[rstep] ) {
				nextreward = reward[rstep];
				if( secondary_rand[rstep] == 1 ) {
					nextreward = getsecondaryreward( rand, rstep );
				}
				goto final_reward;
			}
			break;
		}
	}

	final_reward:
	return nextreward;
}

int Superblocks::getsecondaryreward( int seed, int step ) 
{
	if( debug ) { 
		cout << "getsecondaryreward: seed: " << seed << endl; 
		cout << "getsecondaryreward: step: " << step << endl; 
		cout << "getsecondaryreward: reward: " << reward[step] << endl;
		cout << "getsecondaryreward: secondary_rand_low: " << secondary_rand_low[step] << endl; 
		cout << "getsecondaryreward: secondary_rand_high: " << secondary_rand_high[step] << endl; 
		cout << "getsecondaryreward: secondary_rand_type: " 
			<< getsecondarylucktype( secondary_rand_type[step] ) << endl; 
		cout << "getsecondaryreward: secondary_rand_x: " << secondary_rand_x[step] << endl; 
	}

	int rand1 = Superblocks::generateMTRandom(seed, secondary_rand_low[step], secondary_rand_high[step]);

	int secondary_reward;

	switch( secondary_rand_type[step] ) {
		case 1: // SECONDARY_REWARD_PLUS_RAND_MINUS_X 
			secondary_reward = ( reward[step] + rand1 - secondary_rand_x[step] );
			break;
		default: 
			cout << "getsecondaryreward: error: unknown secondary_rand_type!" << endl;
			return 0;
	}

	if( debug ) {
		cout << "getsecondaryreward: rand1: " << rand1 << endl; 
		cout << "getsecondaryreward: secondary_reward: " << secondary_reward << endl; 
	}
	return secondary_reward;
}

int main( int argc, char **argv ) 
{

	Superblocks s;
	s.init();	

	if( !argv[1] ) 
	{
		cout << "usage: " << argv[0];
		switch( s.seed_type[1] ) { 
			default: cout << " <input>"; break;
			case 1: cout << " <block height>"; break;
			case 2: cout << " <block hash>"; break;
		}
		cout << " [debug]" << endl;
		return 0; 
	}

	s.debug = 0;
	if( argv[2] ) { s.debug = 1; }

	int reward = s.getnextblockreward( argv[1] );

	cout << reward << endl;

	return 0;

}

