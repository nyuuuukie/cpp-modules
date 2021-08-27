#!/bin/bash

PROGRAM=megaphone

declare -a input=(
    "shhhhh... I think the students are asleep..."
    "Damnit ! Sorry students, I thought this thing was off."
    ""
    "There IS AN ERROR IN YOUR PROGRAM!!"
)

declare -a output=(
    "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
    "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
    "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
    "THERE IS AN ERROR IN YOUR PROGRAM!!"
)

for i in "${!input[@]}"
do
    echo -n "Test $i: "
    if [ "${input[$i]}" != "" ]; then
       ./"${PROGRAM}" "${input[$i]}" > out.txt
    else
       ./"${PROGRAM}" > out.txt
    fi
    res="$(cat out.txt)"
    if [ "$res" = "${output[$i]}" ]; then
        echo -n "OK"
    else
        echo -n "KO"
    fi
    echo " | $res"
done

rm out.txt