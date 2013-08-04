# makefile 
# Superblocks - Version 0.4.2

CC=g++

#FLAGS=-Wall
FLAGS=

BINDIR=./bin/
#BINDIR=

all:
	# Superblocks

	# Get Next Block Reward - ELP - Elephantcoin
	$(CC) $(FLAGS) -DLUCK_STEPS=4 superblocks.cpp utils.cpp next-elp.cpp -o $(BINDIR)getnextblockreward-elp

	# Get Next Block Reward - GIL - Gil
	$(CC) $(FLAGS) -DLUCK_STEPS=42 superblocks.cpp utils.cpp next-gil.cpp -o $(BINDIR)getnextblockreward-gil

	# Get Next Block Reward - LKY - Luckycoin
	$(CC) $(FLAGS) -DLUCK_STEPS=4 superblocks.cpp utils.cpp next-lky.cpp -o $(BINDIR)getnextblockreward-lky

	# Get Next Block Reward - NUG - Nuggets
	$(CC) $(FLAGS) -DLUCK_STEPS=2 superblocks.cpp utils.cpp next-nug.cpp -o $(BINDIR)getnextblockreward-nug

	# Get Next Block Reward - SPT - Spots
	$(CC) $(FLAGS) -DLUCK_STEPS=2 superblocks.cpp utils.cpp next-spt.cpp -o $(BINDIR)getnextblockreward-spt


	# Generate Reward List - JKC - Junkcoin
	$(CC) $(FLAGS) list-jkc.cpp -o $(BINDIR)rewardlist-jkc

	# Generate Reward List - SXC - Sexcoin
	$(CC) $(FLAGS) list-sxc.cpp -o $(BINDIR)rewardlist-sxc


	# Precompute lucky hash cutouts - NUG - Nuggets
	$(CC) $(FLAGS) precom-nug.cpp -o $(BINDIR)precompute-nug

	# Precompute lucky hash cutouts - SPT - Nuggets
	$(CC) $(FLAGS) precom-spt.cpp -o $(BINDIR)precompute-spt

