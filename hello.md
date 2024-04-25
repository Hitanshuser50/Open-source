#hello

aNotepadaNotepad
Toggle navigation
Unix2new
# Unix

i) Write a shell script to perform arithmetic operations.

#!/bin/bash

# Function to perform addition
addition() {
    result=$(($1 + $2))
    echo "Result of addition: $result"
}

# Function to perform subtraction
subtraction() {
    result=$(($1 - $2))
    echo "Result of subtraction: $result"
}

# Function to perform multiplication
multiplication() {
    result=$(($1 * $2))
    echo "Result of multiplication: $result"
}

# Function to perform division
division() {
    if [ $2 -eq 0 ]; then
        echo "Error: Division by zero is not allowed."
    else
        result=$(($1 / $2))
        echo "Result of division: $result"
    fi
}

# Main script
echo "Enter two numbers:"
read num1
read num2

echo "Choose an operation:"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read choice

case $choice in
    1) addition $num1 $num2 ;;
    2) subtraction $num1 $num2 ;;
    3) multiplication $num1 $num2 ;;
    4) division $num1 $num2 ;;
    *) echo "Invalid choice" ;;
esac

2)  Write a shell script to calculate simple interest.  

#!/bin/bash

# Function to calculate simple interest

calculate_simple_interest() {
principal=$1
rate=$2
time=$3

 
interest=$((principal * rate * time / 100))
echo $interest

 

}

# Prompt user for input

echo "Enter the principal amount: "
read principal

echo "Enter the rate of interest: "
read rate

echo "Enter the time in years: "
read time

# Calculate simple interest using the function

result=$(calculate_simple_interest $principal $rate $time)

# Display the result

echo "The simple interest is: $result"

Write a shell script to determine the largest among three integer numbers. 

#!/bin/bash

# Function to find the largest among three numbers

find_largest() {
if [ $1 -gt $2 ] && [ $1 -gt $3 ]; then
echo "$1 is the largest."
elif [ $2 -gt $1 ] && [ $2 -gt $3 ]; then
echo "$2 is the largest."
else
echo "$3 is the largest."
fi
}

# Main script

echo "Enter three integer numbers:"
read num1
read num2
read num3

find_largest $num1 $num2 $num3

Write a shell script to determine if a given year is leap year or not. 

#!/bin/bash

# Function to determine if a year is a leap year
is_leap_year() {
    year=$1

    # Check if the year is divisible by 4 and not divisible by 100,
    # or if it is divisible by 400
    if [ $((year % 4)) -eq 0 ] && [ $((year % 100)) -ne 0 ] || [ $((year % 400)) -eq 0 ]; then
        echo "$year is a leap year."
    else
        echo "$year is not a leap year."
    fi
}

# Main script
echo "Enter the year:"
read year

is_leap_year $year

Write a shell script to print the multiplication table of given numbers using while statement.

#!/bin/bash

# Function to print multiplication table of a given number

print_multiplication_table() {
number=$1
i=1

 
echo "Multiplication table of $number:"

# Use a while loop to print the multiplication table
while [ $i -le 10 ]; do
    result=$((number * i))
    echo "$number x $i = $result"
    i=$((i + 1))
done

 

}

# Main script

echo "Enter a number to print its multiplication table:"
read number

print_multiplication_table $number

Write a shell script to search whether an element is present in the list or not. 

#!/bin/bash

# Function to search for an element in the list
search_element() {
    element=$1
    shift
    list=("$@")

    # Loop through the list to search for the element
    for item in "${list[@]}"; do
        if [ "$item" = "$element" ]; then
            echo "Element $element is present in the list."
            return 0  # Element found, exit with success status
        fi
    done

    # Element not found
    echo "Element $element is not present in the list."
    return 1  # Element not found, exit with error status
}

# Main script
echo "Enter the list of elements (space-separated):"
read -a input_list

echo "Enter the element to search for:"
read search_element

# Call the function to search for the element in the list
search_element $search_element "${input_list[@]}"

Write a shell script to compare two strings. 

#!/bin/bash

# Function to compare two strings

compare_strings() {
string1=$1
string2=$2

 
# Check if the strings are equal
if [ "$string1" = "$string2" ]; then
    echo "Strings are equal."
else
    echo "Strings are not equal."
fi

 

}

# Main script

echo "Enter the first string:"
read string1

echo "Enter the second string:"
read string2

# Call the function to compare the strings

compare_strings "$string1" "$string2"

Write a shell script to read and check if the directory / file exists or not, if not make the directory / file. 

#!/bin/bash

# Function to check if directory or file exists and create if not

check_and_create() {
path=$1

 
# Check if the path exists
if [ -e "$path" ]; then
    echo "$path already exists."
else
    # Check if it's a directory or file
    if [ -d "$path" ]; then
        mkdir -p "$path"
        echo "Directory $path created."
    else
        touch "$path"
        echo "File $path created."
    fi
fi

 

}

# Main script

echo "Enter the directory or file path:"
read path

check_and_create "$path"

Write a shell script to implement a menu-driven calculator using case statements.

#!/bin/bash

# Function to perform addition
add() {
    result=$(($1 + $2))
    echo "Result: $result"
}

# Function to perform subtraction
subtract() {
    result=$(($1 - $2))
    echo "Result: $result"
}

# Function to perform multiplication
multiply() {
    result=$(($1 * $2))
    echo "Result: $result"
}

# Function to perform division
divide() {
    if [ $2 -eq 0 ]; then
        echo "Error: Division by zero is not allowed."
    else
        result=$(($1 / $2))
        echo "Result: $result"
    fi
}

# Main script
while true; do
    echo "Menu-Driven Calculator"
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Exit"
    echo "Enter your choice:"
    read choice

    case $choice in
        1)
            echo "Enter two numbers:"
            read num1
            read num2
            add $num1 $num2
            ;;
        2)
            echo "Enter two numbers:"
            read num1
            read num2
            subtract $num1 $num2
            ;;
        3)
            echo "Enter two numbers:"
            read num1
            read num2
            multiply $num1 $num2
            ;;
        4)
            echo "Enter two numbers:"
            read num1
            read num2
            divide $num1 $num2
            ;;
        5)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please enter a number from 1 to 5."
            ;;
    esac
done

Write a shell script to print following pattern: 
*
**

***

Print the pattern using a shell script:

#!/bin/bash

# Function to print the pattern
print_pattern() {
    rows=$1

    for ((i = 1; i <= rows; i++)); do
        for ((j = 1; j <= i; j++)); do
            echo -n "* "
        done
        echo
    done
}

# Main script
rows=3
print_pattern $rows

---

Write a shell script to perform operations on directory like: display name of current directory, display
list of directory contents, create another directory — write contents on that and copy it to a suitable location
in your home directory, etc.

#!/bin/bash

# Function to display the name of the current directory

display_current_directory() {
current_dir=$(pwd)
echo "Current directory: $current_dir"
}

# Function to display the list of directory contents

display_directory_contents() {
echo "Contents of the current directory:"
ls -l
}

# Function to create another directory, write contents, and copy it to a suitable location in the home directory

perform_operations() {
echo "Enter the name of the new directory to create:"
read new_dir

 
# Create the new directory
mkdir "$new_dir"

# Write contents to the new directory
echo "Enter the contents for the new directory:"
read contents
echo "$contents" > "$new_dir/contents.txt"

# Copy the new directory to a suitable location in the home directory
cp -r "$new_dir" ~/Desktop/
echo "Directory '$new_dir' copied to ~/Desktop/"

 

}

# Main script

echo "Menu:"
echo "1. Display name of current directory"
echo "2. Display list of directory contents"
echo "3. Create another directory, write contents, and copy it to a suitable location in your home directory"
echo "4. Exit"

while true; do
echo "Enter your choice:"
read choice

 
case $choice in
    1) display_current_directory ;;
    2) display_directory_contents ;;
    3) perform_operations ;;
    4) echo "Exiting..."; exit ;;
    *) echo "Invalid choice. Please enter a number from 1 to 4." ;;
esac

 

done

Write a script using grep command to find the number of words character, words and lines in a file.

#!/bin/bash

# Prompt the user for the file name

echo "Enter the file name:"
read filename

# Check if the file exists

if [ ! -f "$filename" ]; then
echo "File not found: $filename"
echo "Creating a new file..."
touch "$filename"
fi

# Get the number of words, characters, and lines using wc command

word_count=$(wc -w < "$filename")
char_count=$(wc -m < "$filename")
line_count=$(wc -l < "$filename")

echo "Number of words: $word_count"
echo "Number of characters: $char_count"
echo "Number of lines: $line_count"

—./word_count.sh filename.txt—

Write a script using egrep command to display a list of specific types of files in the directory. 

#!/bin/bash

# Define the directory to search

directory="."

# Display list of specific types of files using egrep

echo "List of specific types of files:"
ls -l "$directory" | egrep -i '\.(txt|pdf|docx)$'

Write a script using sed command to replace all occurrences of a particular word in a given file. 

#!/bin/bash

# Check if the file exists

if [ ! -f "$1" ]; then
echo "File not found: $1"
exit 1
fi

# Prompt the user for the word to replace

echo "Enter the word to replace:"
read old_word

# Prompt the user for the replacement word

echo "Enter the replacement word:"
read new_word

# Replace all occurrences of the old word with the new word using sed command

sed -i "s/$old_word/$new_word/g" "$1"

echo "Occurrences of '$old_word' replaced with '$new_word' in the file."

—-./replace_word.sh filename.txt —-

Write a script using sed command to print duplicate lines in input.

#!/bin/bash

# Check if the file exists

if [ ! -f "$1" ]; then
echo "File not found: $1"
exit 1
fi

# Print duplicate lines using sed command

echo "Duplicate lines in the input:"
sed -n '/^\(.*\)$/{x;s//\n&/;G;s/\(.*\)\n\1$/\1/p;}' "$1"

Execute the following scripts using Awk / Perl languages:
i) Write an Awk script to print all even numbers in a given range.

#!/bin/awk -f

# Function to print even numbers in the given range

function print_even_numbers(start, end) {
for (i = start; i <= end; i++) {
if (i % 2 == 0) {
print i
}
}
}

# Main script

BEGIN {
printf "Enter the start of the range: "
getline start < "-"
printf "Enter the end of the range: "
getline end < "-"
print "Even numbers in the range from", start, "to", end, "are:"
print_even_numbers(start, end)
}

— awk -f print_even.awk —

Write an Awk script to develop a Fibonacci series (take user input for number of terms). 

#!/bin/awk -f

# Function to generate Fibonacci series

function fibonacci_series(num_terms) {
if (num_terms == 0) {
return ""
}
if (num_terms == 1) {
return "0"
}

 
fib_series = "0 1"
a = 0
b = 1
for (i = 2; i < num_terms; i++) {
    c = a + b
    fib_series = fib_series " " c
    a = b
    b = c
}

return fib_series

 

}

# Main script

BEGIN {
printf "Enter the number of terms for Fibonacci series: "
getline num_terms < "-"
printf "Fibonacci series with %d terms:\n", num_terms
print fibonacci_series(num_terms)
}

Write a Perl script to sort elements of an array. 

#!/usr/bin/perl

# Prompt the user to enter elements of the array

print "Enter elements of the array (separated by spaces): ";
my $input = <STDIN>;
chomp $input;

# Split the input string into an array

my @array = split ' ', $input;

# Sort the elements of the array

my @sorted_array = sort @array;

# Print the sorted array

print "Sorted array: @sorted_array\n";

Write a Perl script to check a number is prime or not. 

#!/usr/bin/perl

# Function to check if a number is prime

sub is_prime {
my $num = shift;

 
if ($num <= 1) {
    return 0;  # Not prime
}
elsif ($num == 2) {
    return 1;  # Prime
}

# Check for divisibility by numbers up to the square root of the number
for (my $i = 2; $i <= sqrt($num); $i++) {
    if ($num % $i == 0) {
        return 0;  # Not prime
    }
}

return 1;  # Prime

 

}

# Main script

print "Enter a number to check if it's prime: ";
my $number = <STDIN>;
chomp $number;

if (is_prime($number)) {
print "$number is a prime number.\n";
} else {
print "$number is not a prime number.\n";
}

Thankyou
Public Last updated: 2024-04-24 06:02:31 PM

Comments
Your Name
Comment

Download on the Apple Store   Get it on Google Play

© 2009-2024 aNotepad.com

About | Privacy | Features | Resume Builder | Free Fax | Report Abuse

aNotepad.com is your everyday online notepad. You can take notes and share notes online without having to login.
You can use a rich text editor and download your note as PDF or Word document.
Best of all - aNotepad is a fast, clean, and easy-to-use notepad online.
