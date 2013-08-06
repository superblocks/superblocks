#!/bin/bash

# getnextblockreward test
# Superblocks - Version 0.4.3

#DEBUG=debug
DEBUG=''

BINDIR="./bin/"
#BINDIR=


COIN=$1
if [ -z "$COIN" ]; then 
  echo "usage: $0 <coin>"
	echo "<coin> values: all, cdc, elp, gdc, gil, grw, lky, nug, red, spt, str"
	exit
fi

echo "# Superblocks: test: getnextblockreward: $COIN"

cd $BINDIR

if [[ "$COIN" = "cdc" || "$COIN" = "all" ]]; then

echo; echo "# [CDC] Cloudcoin - explorer: ?"
echo '# TODO: superblock tests'
echo '# ? CDC from Block ?, seeded from Block ?'
./getnextblockreward-cdc 0000000000000000000000000000000000000000000000000000000000000000 $DEBUG

fi

if [[ "$COIN" = "grw" || "$COIN" = "all" ]]; then

echo; echo "# [GRW] Growthcoin - explorer: ?"
echo '# TODO: superblock tests'
echo '# ? GRW from Block ?, seeded from Block ?'
./getnextblockreward-grw 0000000000000000000000000000000000000000000000000000000000000000 $DEBUG

fi

if [[ "$COIN" = "gdc" || "$COIN" = "all" ]]; then

echo; echo "# [GDC] Grandcoin - explorer: http://grandcoin.org/blocks/"
echo '# TODO: superblock tests'
echo '# 1000 GDC from Block 39333, seeded from Block 39332'
./getnextblockreward-gdc cd8242ee63eeb11e03e23dbd59633d956dd421943808026375fb220972d01624 $DEBUG

fi

if [[ "$COIN" = "str" || "$COIN" = "all" ]]; then

echo; echo "# [STR] Starcoin - explorer: ?"
echo '# TODO: full superblock tests'
echo '# ?723 STR from Block ?46074, seeded from Block ?46073' 
./getnextblockreward-str 0000000000000000000000000000000000000000000000000000000000000000 $DEBUG
echo '# 100 STR from Block 46500, seeded from Block 46499' 
./getnextblockreward-str 0000000230251ebb27b15e9d40f1580c505c68c1303d1021e34f0e151159d310 $DEBUG

fi

if [[ "$COIN" = "red" || "$COIN" = "all" ]]; then

echo; echo "# [RED] Recoin - explorer: http://redcoin.pw/bc/"
echo '# TODO: superblock tests'
echo '# 120 RED from Block 48258, seeded from Block 48257' 
./getnextblockreward-red 344ede77632d976b4c52ed52457acd4cd2b136432254655e495e5ce5f658914c $DEBUG
echo '# 102 RED from Block 48360, seeded from Block 48359' 
./getnextblockreward-red b9fe644db13c583a6379e27a33f0ab34d14e97cd13066b79cbae3b776b9ac718 $DEBUG

fi

if [[ "$COIN" = "elp" || "$COIN" = "all" ]]; then

echo; echo "# [ELP] Elephantcoin - explorer: http://exploretheblocks.com/elephantcoin/block_crawler.php"
echo '# TODO: 1000+ superblock test, 10,000+ superblock test' 
echo '# 413 ELP from Block 85915, seeded from Block 85914' 
./getnextblockreward-elp d6f5ffc75164c59067fcd747ac6afd4aa01535d30911c40e9e2dc67a9719ea0a $DEBUG
echo '# 327 ELP from Block 85929, seeded from Block 85928' 
./getnextblockreward-elp d0747ba46e43335af0e68b6c3a13adc9cd973e3956d6e34cf2921dac78f04357 $DEBUG
echo '# 50 ELP from Block 85901, seeded from Block 85900' 
./getnextblockreward-elp b3233178cb619e538ca29a50fcaf9039d422cd66f90141fe948410cf4ae09b08 $DEBUG

fi

if [[ "$COIN" = "gil" || "$COIN" = "all" ]]; then

echo; echo "# [GIL] Gil - explorer: http://altcha.in/chain/Gil"
echo '# 49 GIL from Block 42768, seeded from Block 42767'
./getnextblockreward-gil 0de77ba66fcf1e44ec98e5f82b0c32492c442831f366084395947c1b08cbc253 $DEBUG
echo '# 48 GIL from Block 42782, seeded from Block 42781'
./getnextblockreward-gil 3ee95e9047f0f1c3d14034350295583eb46c2934135b999a8e726117bc32e7cd $DEBUG
echo '# 30 GIL from Block 42776, seeded from Block 42777'
./getnextblockreward-gil 83914dbe56c386fc067394236460ccd5a871ba308e38104ba6c32bcc2e5ce2ac $DEBUG
echo '# 10 GIL from Block 42519, seeded from Block 42518'
./getnextblockreward-gil f9ea17d688f21a0cd7e75fad942a05e31b70d6fc4e7f9df71499745fc0d6ca3e $DEBUG

fi

if [[ "$COIN" = "nug" || "$COIN" = "all" ]]; then

echo; echo "# [NUG] Nuggets - explorer: http://altcha.in/chain/Nuggets"
echo '# 10045 NUG from Block 8318, seeded from Block 8317'
./getnextblockreward-nug e6e1b004b56961cf6056f536776500e89cc3442daf5dd9ab328d44de5e13aeda $DEBUG
echo '# 49 NUG from Block 8334, seeded from Block 8333'
./getnextblockreward-nug 18fb2bc9417a012b80a69701af574b450b71804de4cae80c65de9e9c2282d140 $DEBUG

fi

if [[ "$COIN" = "spt" || "$COIN" = "all" ]]; then

echo; echo "# [SPT] Spots - explorer: http://altcha.in/chain/Spots"
echo '# 10045 SPT from Block TEST, seeded from Block TEST-1 [cutout: fffc6b7]'
./getnextblockreward-spt 00000000fffc6b70000000000000000000000000000000000000000000000000 $DEBUG
echo '# 49 SPT from Block 5801, seeded from Block 5800'
./getnextblockreward-spt 85c2ec05dbbe6fa3ca07a06d0ac26e070813fc30de6a9001f0a140de3b2e3d05 $DEBUG

fi

if [[ "$COIN" = "lky" || "$COIN" = "all" ]]; then

echo; echo "#[LKY] Luckycoin - explorer: http://altcha.in/chain/LuckyCoin"
echo '# 5104 LKY from Block 58520, seeded from Block 58519'
./getnextblockreward-lky 96914a4ee8d61a9044ef9d4dca099a8ada52def2b6fed197146da9b831c28557 $DEBUG
echo '# 440 LKY from Block 59289, seeded from Block 59288'
./getnextblockreward-lky 9eb77e860c78360500ea08892233c59a326bb7ab2d592ab8d5725292c6170d05 $DEBUG
echo '# 176 LKY from Block 59279, seeded from Block 59278'
./getnextblockreward-lky afdf2de7538fa36e713f9c626a171d965a39d54299ad103a1018793a606743c9 $DEBUG
echo '# 88 LKY from Block 59334, seeded from Block 59333'
./getnextblockreward-lky 85ac264a92ff47f29a55b0daea6366da2f89573fb897f1660d7f46cff9cd845f $DEBUG

fi
