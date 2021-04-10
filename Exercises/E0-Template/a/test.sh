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


echo "\033[33mCompiling your program...\n\033[0;0m"

./input.sh > input.txt

if ! clang -o user main.c; then 
	rm input.txt
	exit 1
fi

echo "\033[33m\nCompiled successfully!\033[0;0m"


while read f; do
	echo "\n=====================\n"

	printf "$f" | xargs ./user > output.txt
	printf "$f" | xargs ./correct > correct-output.txt

	printf "\033[33mYour output: \n\033[0;0m"
	cat output.txt
	printf "\033[33m\nCorrect output: \n\033[0;0m"
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
