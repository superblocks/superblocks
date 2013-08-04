# makefile 
# Superblocks - version 0.4

CC=g++

#FLAGS=-Wall
FLAGS=

BINDIR=./bin/
#BINDIR=

all:
  # GIL - Gil - Get Next Block Reward
	$(CC) $(FLAGS) -DLUCK_STEPS=42 superblocks.cpp utils.cpp next-gil.cpp -o $(BINDIR)getnextblockreward-gil

	# LKY - Luckycoin - Get Next Block Reward
	$(CC) $(FLAGS) -DLUCK_STEPS=4 superblocks.cpp utils.cpp next-lky.cpp -o $(BINDIR)getnextblockreward-lky

	# NUG - Nuggets - Get Next Block Reward
	$(CC) $(FLAGS) -DLUCK_STEPS=2 superblocks.cpp utils.cpp next-nug.cpp -o $(BINDIR)getnextblockreward-nug

	# SPT - Spots - Get Next Block Reward
	$(CC) $(FLAGS) -DLUCK_STEPS=2 superblocks.cpp utils.cpp next-spt.cpp -o $(BINDIR)getnextblockreward-spt


	# JKC - Junkcoin - Generate Reward List
	$(CC) $(FLAGS) list-jkc.cpp -o $(BINDIR)rewardlist-jkc

	# SXC - Sexcoin - Generate Reward List
	$(CC) $(FLAGS) list-jkc.cpp -o $(BINDIR)rewardlist-sxc


	# NUG - Nuggets - Precompute all lucky hash cutouts
	$(CC) $(FLAGS) precom-nug.cpp -o $(BINDIR)precompute-nug

	# SPT - Nuggets - Precompute all lucky hash cutouts
	$(CC) $(FLAGS) precom-spt.cpp -o $(BINDIR)precompute-spt


