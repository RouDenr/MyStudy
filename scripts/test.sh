#!/bin/bash
YELLOW='\033[38;05;228m'
GREEN='\033[38;05;120m'
RED='\033[38;05;196m'
WALL="\033[38;05;51m|\033[0m"
WALL_W="\033[38;05;51m|---------------|\033[0m"
ENDCOLOR="\033[0m"
x=1
k=$1
cou=0;
retry=$2
max=0;
min=90000000000
echo -e $WALL_W
while [ $x -le $retry ]
do
	ARG=$(python3.7 test_rand.py $k)
	cur=$(./push_swap $ARG | wc -l)
	echo -e $WALL$cur '\t\t'$WALL
	res=$( ./push_swap $ARG )
	if [[ $? != 0 ]]; then
		echo -e $RED $ARG '\nError.' $? $ENDCOLOR
	fi
	let cou=$(($cou+$cur))
	if [ $cur -gt $max ]; then
	max=$cur
	fi
	if [ $cur -le $min ]; then
	min=$cur
	fi
	x=$(( $x + 1 ))
done
cou=$(($cou/$retry));
echo -e $WALL_W
echo -e $WALL' max :'$RED$max$ENDCOLOR '\t'$WALL
echo -e $WALL' avr :'$YELLOW $cou$ENDCOLOR '\t'$WALL
echo -e $WALL' min :'$GREEN$min$ENDCOLOR '\t'$WALL
echo -e $WALL_W
