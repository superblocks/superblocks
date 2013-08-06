# makefile 
# Superblocks - Version 0.4.3

CC=g++

#FLAGS=-Wall
FLAGS=

BINDIR=./bin/
#BINDIR=

all:

	# Coins that seed with previous Block Hash

	# [CDC] Cloudcoin 
	$(CC) $(FLAGS) -DLUCK_STEPS=4 next.cpp utils.cpp set-cdc.cpp -o $(BINDIR)getnextblockreward-cdc
	$(CC) $(FLAGS) -DLUCK_STEPS=4 precom.cpp utils.cpp set-cdc.cpp -o $(BINDIR)precompute-cdc

	# [ELP] Elephantcoin
	$(CC) $(FLAGS) -DLUCK_STEPS=4 next.cpp utils.cpp set-elp.cpp -o $(BINDIR)getnextblockreward-elp
	$(CC) $(FLAGS) -DLUCK_STEPS=4 precom.cpp utils.cpp set-elp.cpp -o $(BINDIR)precompute-elp

	# [GDC] Grandcoin
	$(CC) $(FLAGS) -DLUCK_STEPS=3 next.cpp utils.cpp set-gdc.cpp -o $(BINDIR)getnextblockreward-gdc
	$(CC) $(FLAGS) -DLUCK_STEPS=3 precom.cpp utils.cpp set-gdc.cpp -o $(BINDIR)precompute-gdc

	# [GIL] Gil
	$(CC) $(FLAGS) -DLUCK_STEPS=42 next.cpp utils.cpp set-gil.cpp -o $(BINDIR)getnextblockreward-gil
	$(CC) $(FLAGS) -DLUCK_STEPS=42 precom.cpp utils.cpp set-gil.cpp -o $(BINDIR)precompute-gil

	# [GRW] Growthcoin
	$(CC) $(FLAGS) -DLUCK_STEPS=2 next.cpp utils.cpp set-grw.cpp -o $(BINDIR)getnextblockreward-grw
	$(CC) $(FLAGS) -DLUCK_STEPS=2 precom.cpp utils.cpp set-grw.cpp -o $(BINDIR)precompute-grw

	# [LKY] Luckycoin
	$(CC) $(FLAGS) -DLUCK_STEPS=4 next.cpp utils.cpp set-lky.cpp -o $(BINDIR)getnextblockreward-lky
	$(CC) $(FLAGS) -DLUCK_STEPS=4 precom.cpp utils.cpp set-lky.cpp -o $(BINDIR)precompute-lky

	# [NUG] Nuggets
	$(CC) $(FLAGS) -DLUCK_STEPS=2 next.cpp utils.cpp set-nug.cpp -o $(BINDIR)getnextblockreward-nug
	$(CC) $(FLAGS) -DLUCK_STEPS=2 precom.cpp utils.cpp set-nug.cpp -o $(BINDIR)precompute-nug

	# [RED] Redcoin
	$(CC) $(FLAGS) -DLUCK_STEPS=2 next.cpp utils.cpp set-red.cpp -o $(BINDIR)getnextblockreward-red
	$(CC) $(FLAGS) -DLUCK_STEPS=2 precom.cpp utils.cpp set-red.cpp -o $(BINDIR)precompute-red

	# [SPT] Spots
	$(CC) $(FLAGS) -DLUCK_STEPS=2 next.cpp utils.cpp set-spt.cpp -o $(BINDIR)getnextblockreward-spt
	$(CC) $(FLAGS) -DLUCK_STEPS=2 precom.cpp utils.cpp set-spt.cpp -o $(BINDIR)precompute-spt

	# [STR] Starcoin
	$(CC) $(FLAGS) -DLUCK_STEPS=5 next.cpp utils.cpp set-str.cpp -o $(BINDIR)getnextblockreward-str
	$(CC) $(FLAGS) -DLUCK_STEPS=5 precom.cpp utils.cpp set-str.cpp -o $(BINDIR)precompute-str


	# Coins that seed with Block Height

	# [JKC] Junkcoin
	$(CC) $(FLAGS) list-jkc.cpp -o $(BINDIR)rewardlist-jkc

	# [SXC] Sexcoin
	$(CC) $(FLAGS) list-sxc.cpp -o $(BINDIR)rewardlist-sxc

