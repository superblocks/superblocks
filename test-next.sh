#!/bin/sh

#DEBUG=debug
DEBUG=''

BINDIR="./bin/"

echo "#"
echo "# Superblocks: getnextblockreward"
echo "#"

cd $BINDIR



echo; echo "# [GIL] Gil - explorer: http://altcha.in/chain/Gil";
echo "#"

echo '# Block 42767(seed), 42768(result) reward: 49'
./getnextblockreward-gil 0de77ba66fcf1e44ec98e5f82b0c32492c442831f366084395947c1b08cbc253 $DEBUG

echo '# Block 42781(seed), 42782(result) reward: 48' 
./getnextblockreward-gil 3ee95e9047f0f1c3d14034350295583eb46c2934135b999a8e726117bc32e7cd $DEBUG

echo '# Block 42777(seed), 42778(result) reward: 30'
./getnextblockreward-gil 83914dbe56c386fc067394236460ccd5a871ba308e38104ba6c32bcc2e5ce2ac $DEBUG

echo '# Block 42518(seed), 42519(result) reward: 10'
./getnextblockreward-gil f9ea17d688f21a0cd7e75fad942a05e31b70d6fc4e7f9df71499745fc0d6ca3e $DEBUG

echo; echo "# [NUG] Nuggets - explorer: http://altcha.in/chain/Nuggets";
echo "#"

echo '# Block 8317(seed), 8318(superblock) reward: 10045'
./getnextblockreward-nug e6e1b004b56961cf6056f536776500e89cc3442daf5dd9ab328d44de5e13aeda $DEBUG

echo '# Block 8333(seed), 8334(normal) reward: 49'
./getnextblockreward-nug 18fb2bc9417a012b80a69701af574b450b71804de4cae80c65de9e9c2282d140 $DEBUG


echo; echo "# [SPT] Spots - explorer: http://altcha.in/chain/Spots";
echo "#"

echo '# Block TEST(seed), TEST+1(superblock) reward: 10045'
./getnextblockreward-spt 00000000fffc6b70000000000000000000000000000000000000000000000000 $DEBUG

echo '# Block 5800(seed), 5801(normal) reward: 49'
./getnextblockreward-spt 85c2ec05dbbe6fa3ca07a06d0ac26e070813fc30de6a9001f0a140de3b2e3d05 $DEBUG


echo; echo "#[LKY] Luckycoin - explorer: http://altcha.in/chain/LuckyCoin";
echo "#"

echo '# Block 58519(seed), 58520(superblock) reward: 5104'
./getnextblockreward-lky 96914a4ee8d61a9044ef9d4dca099a8ada52def2b6fed197146da9b831c28557 $DEBUG

echo '# Block 59288(seed), 59289(superblock) reward: 440'
./getnextblockreward-lky 9eb77e860c78360500ea08892233c59a326bb7ab2d592ab8d5725292c6170d05 $DEBUG

echo '# Block 59278(seed), 59279(superblock) reward: 176' 
./getnextblockreward-lky afdf2de7538fa36e713f9c626a171d965a39d54299ad103a1018793a606743c9 $DEBUG

echo '# Block 59333(seed), 59334(normal) reward: 88' 
./getnextblockreward-lky 85ac264a92ff47f29a55b0daea6366da2f89573fb897f1660d7f46cff9cd845f $DEBUG


echo; echo "END"

