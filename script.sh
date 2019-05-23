# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 16:59:32 by ayguillo          #+#    #+#              #
#    Updated: 2019/04/16 13:34:04 by ayguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

if [ -f lem-in ] && [ -f generator ]
then
	read -p "Generation d'une map flow-one, flow-ten, flow-thousand, big ou big-superposition ? " map
else
	if [ ! -f lem-in ] && [ ! -f generator ]
	then
		echo -e "\033[0;31mGenerateur et lem-in non present !\x1b[0m"
		exit
	elif [ ! -f generator ]
	then
		echo -e "\033[0;31mGenerateur non present !\x1b[0m"
		exit
	else
		echo -e "\033[0;31mlem-in non present !\x1b[0m"
		exit
	fi
fi

if [ -z $map ]
then
	echo -e "\033[0;31mArgument invalide\x1b[0m"
	exit
fi

read -p "Combien de tests voulez-vous faire ? " nb

if [ -z $nb ] || [ "$nb" -le "0" ]
then
	echo -e "\033[0;31mArgument invalide\x1b[0m"
	exit
fi

if let $nb 
then
	echo -e "\n$nb Tests en cours . . .\n"
else
	echo -e "\033[0;31mParametre non numerique.\x1b[0m"
	exit
fi

tot=0


if [ $map = "flow-one" ]
then
	for i in `seq 1 $nb`;
	do
		./generator --flow-one > flowonetest
		debut=`date +%s`
		nbline=`cat flowonetest | wc -l`
		./lem-in < flowonetest > flowoneret
		nblineret=`cat flowoneret | wc -l`
		nblinetot=$(($nblineret-$nbline - 1))
		nblinedem=`grep -m 1 "#Here is the number of lines required: " flowonetest | rev | cut -d " " -f1 | rev`
		nblinediff=$(($nblinetot-$nblinedem))
		if [ "$nblinediff" -lt "-10" ]
		then
			echo -e "\033[0;36mCongratulation ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -lt "0" ] && [ "$nblinediff" -gt "-10" ]
		then
			echo -e "\033[0;34mNice ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -ge "0" ] && [ "$nblinediff" -le "5" ]
		then
			echo -e "\033[0;32mPerfect ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -gt "0" ] && [ "$nblinediff" -lt "10" ]
		then
			echo -e "\033[0;33mGood ! Difference : $nblinediff\x1b[0m"
		else
			echo -e "\033[0;31mWarning ! Difference : $nblinediff\x1b[0m"
			cat flowonetest > flowonedifficult$i
		fi
		tot=$(($tot+$nblinediff))
		fin=`date +%s`
		time=$(($fin-$debut))
		if [ $time -lt "1" ]
		then
			sleep 1
		fi
	done
	echo -e "\n\033[035mMoyenne = \c "
	awk "BEGIN {print ${tot}/${nb}}"
	echo -e "\x1b[0m\c"
	rm flowonetest
	rm flowoneret
	exit
fi

if [ $map = "flow-ten" ]
then
	for i in `seq 1 $nb`;
	do
		./generator --flow-ten > flowtentest
		debut=`date +%s`
		nbline=`cat flowtentest | wc -l`
		./lem-in < flowtentest > flowtenret
		nblineret=`cat flowtenret | wc -l`
		nblinetot=$(($nblineret-$nbline - 1))
		nblinedem=`grep -m 1 "#Here is the number of lines required: " flowtentest | rev | cut -d " " -f1 | rev`
		nblinediff=$(($nblinetot-$nblinedem))
		if [ "$nblinediff" -lt "-10" ]
		then
			echo -e "\033[0;36mCongratulation ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -lt "0" ] && [ "$nblinediff" -gt "-10" ]
		then
			echo -e "\033[0;34mNice ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -ge "0" ] && [ "$nblinediff" -le "5" ]
		then
			echo -e "\033[0;32mPerfect ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -gt "0" ] && [ "$nblinediff" -lt "10" ]
		then
			echo -e "\033[0;33mGood ! Difference : $nblinediff\x1b[0m"
		else
			echo -e "\033[0;31mWarning ! Difference : $nblinediff\x1b[0m"
			cat flowtentest > flowtendifficult$i
		fi
		tot=$(($tot+$nblinediff))
		fin=`date +%s`
		time=$(($fin-$debut))
		if [ $time -lt "1" ]
		then
			sleep 1
		fi
	done
	echo -e "\n\033[035mMoyenne = \c "
	awk "BEGIN {print ${tot}/${nb}}"
	echo -e "\x1b[0m\c"
	rm flowtentest
	rm flowtenret
	exit
fi

if [ $map = "flow-thousand" ]
then
	for i in `seq 1 $nb`;
	do
		./generator --flow-thousand > flowthousandtest
		debut=`date +%s`
		nbline=`cat flowthousandtest | wc -l`
		./lem-in < flowthousandtest > flowthousandret
		nblineret=`cat flowthousandret | wc -l`
		nblinetot=$(($nblineret-$nbline - 1))
		nblinedem=`grep -m 1 "#Here is the number of lines required: " flowthousandtest | rev | cut -d " " -f1 | rev`
		nblinediff=$(($nblinetot-$nblinedem))
		if [ "$nblinediff" -lt "-10" ]
		then
			echo -e "\033[0;36mCongratulation ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -lt "0" ] && [ "$nblinediff" -gt "-10" ]
		then
			echo -e "\033[0;34mNice ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -ge "0" ] && [ "$nblinediff" -le "5" ]
		then
			echo -e "\033[0;32mPerfect ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -gt "0" ] && [ "$nblinediff" -lt "10" ]
		then
			echo -e "\033[0;33mGood ! Difference : $nblinediff\x1b[0m"
		else
			echo -e "\033[0;31mWarning ! Difference : $nblinediff\x1b[0m"
			cat flowthousandtest > flowthousanddifficult$i
		fi
		tot=$(($tot+$nblinediff))
		fin=`date +%s`
		time=$(($fin-$debut))
		if [ $time -lt "1" ]
		then
			sleep $((1-$time))
		fi
		sleep 1
	done
	echo -e "\n\033[035mMoyenne = \c "
	awk "BEGIN {print ${tot}/${nb}}"
	echo -e "\x1b[0m\c"
	rm flowthousandtest
	rm flowthousandret
	exit
fi

if [ $map = "big" ]
then
	for i in `seq 1 $nb`;
	do
		./generator --big > bigtest
		debut=`date +%s`
		nbline=`cat bigtest | wc -l`
		./lem-in < bigtest > bigret
		nblineret=`cat bigret | wc -l`
		nblinetot=$(($nblineret-$nbline - 1))
		nblinedem=`grep -m 1 "#Here is the number of lines required: " bigtest | rev | cut -d " " -f1 | rev`
		nblinediff=$(($nblinetot-$nblinedem))
		if [ "$nblinediff" -lt "-10" ]
		then
			echo -e "\033[0;36mCongratulation ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -lt "0" ] && [ "$nblinediff" -gt "-10" ]
		then
			echo -e "\033[0;34mNice ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -ge "0" ] && [ "$nblinediff" -le "5" ]
		then
			echo -e "\033[0;32mPerfect ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -gt "0" ] && [ "$nblinediff" -lt "10" ]
		then
			echo -e "\033[0;33mGood ! Difference : $nblinediff\x1b[0m"
		else
			echo -e "\033[0;31mWarning ! Difference : $nblinediff\x1b[0m"
			cat bigtest > bigdifficult$i
		fi
		tot=$(($tot+$nblinediff))
		fin=`date +%s`
		time=$(($fin-$debut))
		if [ $time -lt "1" ]
		then
			sleep 1
		fi
	done
	echo -e "\n\033[035mMoyenne = \c "
	awk "BEGIN {print ${tot}/${nb}}"
	echo -e "\x1b[0m\c"
	rm bigtest
	rm bigret
	exit
fi

if [ $map = "big-superposition" ]
then
	for i in `seq 1 $nb`;
	do
		./generator --big-superposition > bigsuperpositiontest
		debut=`date +%s`
		nbline=`cat bigsuperpositiontest | wc -l`
		./lem-in < bigsuperpositiontest > bigsuperpositionret
		nblineret=`cat bigsuperpositionret | wc -l`
		nblinetot=$(($nblineret-$nbline - 1))
		nblinedem=`grep -m 1 "#Here is the number of lines required: " bigsuperpositiontest | rev | cut -d " " -f1 | rev`
		nblinediff=$(($nblinetot-$nblinedem))
		if [ "$nblinediff" -lt "-10" ]
		then
			echo -e "\033[0;36mCongratulation ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -lt "0" ] && [ "$nblinediff" -gt "-10" ]
		then
			echo -e "\033[0;34mNice ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -ge "0" ] && [ "$nblinediff" -le "5" ]
		then
			echo -e "\033[0;32mPerfect ! Difference : $nblinediff\x1b[0m"
		elif [ "$nblinediff" -gt "5" ] && [ "$nblinediff" -lt "10" ]
		then
			echo -e "\033[0;33mGood ! Difference : $nblinediff\x1b[0m"
		else
			echo -e "\033[0;31mWarning ! Difference : $nblinediff\x1b[0m"
			cat bigsuperpositiontest > bigsuperpositiondifficult$i
		fi
		tot=$(($tot+$nblinediff))
		fin=`date +%s`
		time=$(($fin-$debut))
		if [ $time -lt "1" ]
		then
			sleep 1
		fi
	done
	echo -e "\n\033[035mMoyenne = \c "
	awk "BEGIN {print ${tot}/${nb}}"
	echo -e "\x1b[0m\c"
	rm bigsuperpositiontest
	rm bigsuperpositionret
	exit
fi

if [ $map ]
then
	echo -e "\033[0;31mType de map non existante.\x1b[0m"
	exit
fi
