#!/bin/bash

echo -e "\n\033[1;95mPUSH SWAP TESTER"

if [ $1 -a !SIZE ];
then
	SIZE=$1;
else
	SIZE=0
fi

export VAR="$(seq -2500 2500 | shuf -n $SIZE | tr '\n' ' ')"

echo -e "\n" > tmp.log
./push_swap $VAR >> tmp.log

print() {
	echo -ne "\033[1;97m$1: \033[1;93m$2  \033[1;m"
}

SA=$(cat tmp.log | grep -zPo '\nsa\n'| wc -w)
SB=$(cat tmp.log | grep -zPo '\nsb\n'| wc -w)
SS=$(cat tmp.log | grep -zPo '\nss\n'| wc -w)
PA=$(cat tmp.log | grep -zPo '\npa\n'| wc -w)
PB=$(cat tmp.log | grep -zPo '\npb\n'| wc -w)
RA=$(cat tmp.log | grep -zPo '\nra\n'| wc -w)
RB=$(cat tmp.log | grep -zPo '\nrb\n'| wc -w)
RR=$(cat tmp.log | grep -zPo '\nrr\n'| wc -w)
RRA=$(cat tmp.log | grep -zPo '\nrra\n'| wc -w)
RRB=$(cat tmp.log | grep -zPo '\nrrb\n'| wc -w)
RRR=$(cat tmp.log | grep -zPo '\nrrr\n'| wc -w)
TOTAL=$(($(cat tmp.log | wc -l) - 2))

if [ $SA -gt 0 ];
then
	print 'SA' $SA
fi

if [ $SB -gt 0 ];
then
	print 'SB' $SB
fi

if [ $SS -gt 0 ];
then
	print 'SS' $SB
fi

if [ $PA -gt 0 ];
then
	print 'PA' $PA
fi

if [ $PB -gt 0 ];
then
	print 'PB' $PB
fi

if [ $RA -gt 0 ];
then
	print 'RA' $RA
fi

if [ $RB -gt 0 ];
then
	print 'RB' $RB
fi

if [ $RR -gt 0 ];
then
	print 'RR' $RR
fi

if [ $RRA -gt 0 ];
then
	print 'RRA' $RRA
fi

if [ $RB -gt 0 ];
then
	print 'RRB' $RRB
fi

if [ $RRR -gt 0 ];
then
	print 'RRR' $RRR
fi

echo -e ""
print 'SIZE' $SIZE
#echo -e ""

print 'MOVES' $TOTAL

STATUS=$(./push_swap $VAR | ./checker_linux $VAR)

echo -ne "\033[1mSTATUS: "

if [[ $STATUS == "OK" || $STATUS == "" ]];
then
	echo -e "\033[1;92mOK\033[1m";
else
	echo -e "\033[1;91mKO\033[1m";
fi

if [ $SIZE -lt 101 ];
then
	if [ $TOTAL -lt 701 ];
	then
		echo -e "\033[1;92mSUCCESS\033[1m";
	else
		echo -e "\033[1;91mFAIL\033[1m";
		echo -e $VAR >> fail.log;
	fi
elif [ $SIZE -lt 501 ];
then
	if [ $TOTAL -lt 5501 ]
	then
		echo -e "\033[1;92mSUCCESS\033[1m\n";
	else
		echo -e "\033[1;91mFAIL\033[1m\n";
		echo -e $VAR >> fail.log;
	fi
else
	exit
fi

SIZE=100

sleep 1
./push_swap_tester.sh $SIZE
