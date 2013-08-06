// utils.cpp 
// Superblocks - Version 0.4.3

#include "superblocks.hpp"

void Superblocks::timer_start() 
{
	cstart = clock();
}

float Superblocks::timer_end()
{
	cend = clock() - cstart;
	return (double)cend / ((double)CLOCKS_PER_SEC);
}

long Superblocks::gethashcutout( int step, const char* hash ) 
{
	if( debug ) { 
		cout << "gethashcutout: step: " << step << endl; 
		cout << "gethashcutout: cutout_start: "  << cutout_start[step] << endl;
		cout << "gethashcutout: cutout_length: " << cutout_length[step] << endl; 
	}

	int hlen = strlen(hash);
	if( debug ) { cout << "gethashcutout: srlen(hash): " << hlen << endl; }
	if( hlen != hash_length ) {
		cout << "gethashcutout: error: hash length not " << hash_length << endl;
		return 0;
	}
	if( debug ) { cout << "gethashcutout: hash: " << hash << endl; }
	string hash_string(hash);
	if( debug ) { cout << "gethashcutout: hash_string: " << hash_string << endl; }
	std::string cseed_str = hash_string.substr( cutout_start[step], cutout_length[step]);
	const char* cseed = cseed_str.c_str();
	if( debug ) { cout << "gethashcutout: cseed: " << cseed << endl; }
	long seed = hex2long(cseed);
	if( debug ) { cout << "gethashcutout: return: seed: " << seed << endl; }
	return seed;
}


int /*static*/ Superblocks::generateMTRandom(unsigned int s, int range_low, int range_high) 
{
	if( debug ) { 
		cout << "generateMTRandom: seed: " << s << endl;
		cout << "generateMTRandom: range_low: " << range_low << endl;
		cout << "generateMTRandom: range_high: " << range_high << endl;
	}
	random::mt19937 gen(s);
	random::uniform_int_distribution<> dist(range_low, range_high);
	int result = dist(gen);
	if( debug ) { cout << "generateMTRandom: result: " << result << endl; }	
	return result;
}

long Superblocks::hex2long(const char* hexString) 
{
	static const long hextable[] = {
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		 // 10-19
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		 // 30-39
		-1, -1, -1, -1, -1, -1, -1, -1,  0,  1,
		 2,  3,  4,  5,  6,  7,  8,  9, -1, -1,		 // 50-59
		-1, -1, -1, -1, -1, 10, 11, 12, 13, 14,
		15, -1, -1, -1, -1, -1, -1, -1, -1, -1,		 // 70-79
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, 10, 11, 12,		 // 90-99
		13, 14, 15, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		 // 110-109
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		 // 130-139
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		 // 150-159
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		 // 170-179
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		 // 190-199
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		 // 210-219
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		 // 230-239
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1 
	};

	long ret = 0;
	while (*hexString && ret >= 0) {
		ret = (ret << 4) | hextable[*hexString++];
	}
	return ret;
}

