// Precompute superblock hash cutouts: [SPT] Spots
// Superblocks - Version 0.4.2

#include <stdio.h>
#include <string.h>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
using namespace std;
using namespace boost;

int seed_low  = 0;         // = 0000000
int seed_high = 268435455; // = fffffff

std::string coin("SPT cutout 8,7");
int rnd_limit = 100000;
int rnd_lucky;
int rnd_lucky_low = 50000;
int rnd_lucky_high = 50011;
int lucky_type = 2; //  rand > low && rand < high


//////////////////////////

int static generateMTRandom(unsigned int s, int range)
{
	random::mt19937 gen(s);
	random::uniform_int_distribution<> dist(1, range);
	return dist(gen);
}

int main( int argc, char **argv )
{
	printf("START: cutout search: %s\n", coin.c_str());
	printf("START: cutout search: seed_low=%d [%07x], seed_high=%d [%07x]\n", seed_low, seed_low, seed_high, seed_high);
	printf("START: cutout search: lucky_type=%d, rnd_limit=%d, rnd_lucky=%d, rnd_lucky_low=%d, rnd_lucky_high=%d\n", 
		lucky_type, rnd_limit, rnd_lucky, rnd_lucky_low, rnd_lucky_high );
	printf("\nCUTOUT, seed, rand\n");

	int found = 0;
	long x;
	for (x = seed_low; x <= seed_high; x++) {
		int rand = generateMTRandom(x, rnd_limit);
		switch( lucky_type ) {
			default: 
				printf("error: unknown lucky type\n"); 
				return 0;
			case 1:
				if( rand < rnd_lucky ) { found++; printf("%07x, %d, %d\n", x, x, rand); }	
				break;
			case 2:
				if( rand > rnd_lucky_low && rand < rnd_lucky_high ) { found++; printf("%07x, %d, %d\n", x, x, rand); }	
				break;
		}

	}
	printf("END. found=%d\n", found);
	return 0;

}

