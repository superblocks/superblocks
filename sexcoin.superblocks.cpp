// SXC superblocks
#include <stdio.h>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
using namespace std;
using namespace boost;
int main() {
        int nHeight, rand;
        for (nHeight = 0; nHeight <= 100000; nHeight++) {
                random::mt19937 gen(nHeight);
                random::uniform_int_distribution<> dist(1, 100000);
                rand = dist(gen);
                if(rand > 99990) {
                        printf("nHeight %d: nSubsidy *= 50 (rand=%d)\n", nHeight, rand);
                } else if (rand < 2001) {
                        printf("nHeight %d: nSubsidy *= 5 (rand=%d)\n", nHeight, rand);
                }
        }
        return 0;
}
