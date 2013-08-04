// SXC superblocks list
// Superblocks - Version 0.4
//
// verify: explorer: http://sexcoin.lavajumper.com:9950/
//
#include <iostream>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
using namespace std;
using namespace boost;

int list_length = 100000;

int main() {
  cout << "[SXC] Sexcoin - Superblock list" << endl << endl;
	cout << "BLOCK, REWARD" << endl;
        for (int nHeight = 0; nHeight <= list_length; nHeight++) {
		random::mt19937 gen(nHeight);
		random::uniform_int_distribution<> dist(1, 100000);
		int rand = dist(gen);
		if(rand > 99990)
                        cout << nHeight << ", 5000" << endl;
		else if (rand < 2001) 
                        cout << nHeight << ", 500" << endl;

	}
	return 0;
}

