// superblocks.cpp 
// Superblocks - Version 0.4

#include "superblocks.hpp" 

int Superblocks::getnextblockreward( const char* hash )
{

  int hlen = strlen(hash);
	if( debug ) { 
			cout << "-------------------" << endl; 
			cout << "getnextblockreward" << endl; 
			cout << "srlen(hash): " << hlen << endl; 
	}

		if( hlen != hash_length ) { 
			cout << "error: hash length not " << hash_length << endl;
			return 0;
		}
		if( debug ) { cout << "hash: " << hash << endl; }

		string hash_string(hash);
		if( debug ) { cout << "hash_string: " << hash_string << endl; }

		if( debug ) { cout << "LUCK_STEPS: " << LUCK_STEPS << endl; }

		int step = 1;
		if( debug ) { cout << "step: " << step << endl; }

		if( debug ) { cout << "cutout_start: " << cutout_start[step] << endl; }
		if( debug ) { cout << "cutout_length: " << cutout_length[step] << endl; }

		std::string cseed_str = hash_string.substr( cutout_start[step], cutout_length[step]);
		const char* cseed = cseed_str.c_str();
		if( debug ) { cout << "cseed: " << cseed << endl; }

		long seed = hex2long(cseed);
		if( debug ) { cout << "seed: " << seed << endl; }

		if( debug ) { cout << "rnd_range_low: " << rnd_range_low[step] << endl; }
		if( debug ) { cout << "rnd_range_high: " << rnd_range_high[step] << endl; }
		int rand = generateMTRandom(seed, rnd_range_high[step]);
		if( debug ) { cout << "rand: " << rand << endl; }

		if( debug ) { cout << "luck_type: " << luck_type[step] << endl; }

		int nextreward = reward[0]; // normal reward
		if( debug ) { cout << "normal reward: " << nextreward << endl; }

		for (int rstep = 1; rstep < LUCK_STEPS ; rstep++) {

			if( debug )
				cout << "rstep: " << rstep 
					<< " reward: " << reward[rstep] 
					<< " rand: " << rand << endl; 

			switch( luck_type[rstep] ) { 

				default: 
					cout << "error: unknown luck type:" << luck_type[rstep] << endl; 
					return 0; 

				case 1: // LUCK_WITH_LESS_THAN_X 

					if( debug ) { cout << "luck_x: " << luck_x[rstep] << endl; }
					if( rand < luck_x[rstep] ) {
						nextreward = reward[rstep];
						goto final_reward;
					}
					break;

				case 2: // LUCK_WITH_MORE_THAN_X 

					cout << "TODO luck type 2 MORE THAN X" << endl; 
					if( debug ) { cout << "luck_x: " << luck_x[rstep] << endl; }
					return 0; 

				case 3: // LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y

					if( debug ) { cout << "luck_x: " << luck_x[rstep] << endl; }
					if( debug ) { cout << "luck_y: " << luck_y[rstep] << endl; }
					if( rand > luck_x[rstep] && rand < luck_y[rstep] ) {
						nextreward = reward[rstep];
						goto final_reward;
					}
					break;
			}
		}

		final_reward:
		return nextreward;
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

	if( s.debug ) 
	{ 
		cout << "getnextblockreward" << endl;
		cout << "coin: " << s.coin << endl;
		cout << "coin_name: " << s.coin_name << endl;

		// cout << "debug: " << s.debug << endl;
		cout << "hash_length: " << s.hash_length << endl;

		cout << "LUCK_STEPS: " << LUCK_STEPS << endl;

		for (int step = 0; step < LUCK_STEPS ; step++) 
		{
			cout << "step " << step << " -------------------- " << endl;
			cout << "reward: " << s.reward[step] << " " << s.coin << endl;
			if( step == 0 ) {
				cout << "( Normal Block )" << endl; 
				continue;
			} 


			//cout << "cutout_start: " << s.cutout_start[step] << endl;
			//cout << "cutout_length: " << s.cutout_length[step] << endl;
		
			//cout << "rnd_range_low: " << s.rnd_range_low[step] << endl;
			//cout << "rnd_range_high: " << s.rnd_range_high[step] << endl;

			cout << "seed_type: ";
			switch( s.seed_type[step] ) {
				default: cout << "error" << endl; break;
				case 1: cout << "SEED_WITH_BLOCK_HEIGHT" << endl; break;
				case 2: cout << "SEED_WITH_PREVIOUS_BLOCK_HASH" << endl; break;
			}

			cout << "luck_type: ";
			switch( s.luck_type[step] ) {
				default: cout << "error" << endl; break;
				case 1: 
					cout << "LUCK_WITH_LESS_THAN_X" << endl; 
					cout << "luck_x: " << s.luck_x[step] << endl;
					break; 
				case 2: 
					cout << "LUCK_WITH_MORE_THAN_X" << endl; 
					cout << "luck_x: " << s.luck_x[step] << endl;
					break;
				case 3: 
					cout << "LUCK_WITH_MORE_THAN_X_AND_LESS_THAN_Y" << endl; 
					cout << "luck_x: " << s.luck_x[step] << endl;
					cout << "luck_y: " << s.luck_y[step] << endl;
					break;
			}
		}
	}

	int reward = s.getnextblockreward( argv[1] );

	if( s.debug ) { cout << "getnextblockreward: "; }
	cout << reward << endl;

	return 0;

}
