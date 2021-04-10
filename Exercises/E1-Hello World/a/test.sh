#!/bin/sh

if ! test -f "main.c"; then
	echo "erorr: No main.c file found!"
	exit 1
fi

if ! test -f "input.sh"; then
	echo "error: Problem not set up properly!"
	echo "	-- No input script"
	exit 1
fi

if ! test -f "correct"; then
	echo "error: Problem not set up properly!"
	echo "	-- No correct executable binary"
	exit 1
fi


echo "Testing your program..."

./input.sh > input.txt

if ! clang -o user main.c; then 
	rm input.txt
	exit 1
fi

echo "Compiled successfully!\n"


while read f; do
	printf "$f" | ./user > output.txt
	printf "$f" | ./correct > correct-output.txt

	printf "Your output: \n\033[0;33m"
	cat output.txt
	printf "\033[0m\nCorrect output: \n\033[0;33m"
	cat correct-output.txt
	printf "\n"

	if diff output.txt correct-output.txt > /dev/null; then
		echo "\033[0;32mCorrect!\033[0m"
	else
		echo "\033[0;31mIncorrect!\033[0m"
	fi
done < input.txt

echo ""


rm input.txt
rm user
rm output.txt
rm correct-output.txt
