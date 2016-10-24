/*
NumberGuessingGame
(c) 2016
original authors: Leigh Raze
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*	This tutorial is a number guessing game where illustrates the use of 
	selection statements and standard output.
*	It relates to the concept of unsigned char, function srand,
	function target, function printf, function rand, function c_str, ternary operator.
	
*/


#include <time.h>
#include <string>
#include <iostream>


typedef unsigned char uchar;	// allows me to use the type specified ("unsigned char") by the identifier I supplied ("uchar")
//	see http://stackoverflow.com/questions/75191/what-is-an-unsigned-char for difference between char, 
//	signed char and unsigned char.
using namespace std;

// Define constants
const uchar NUM_GUESSES = 7;    // actually, use "log[2] (ceil(max-min)+1) -- 2^guesses = range of values if player uses "binary search"
const uchar MIN_VAL = 1;		// initialize a constant "uchar" (unsigned char) variable MIN_VAL, assign 1 to it
const uchar MAX_VAL = 100;		// initialize a constant "uchar" variable variable MAX_VAL, assign 100 to it


int main()
{
	short guess = 0;		// what the user's guess was, 
	short target = -1;		// what the number to guess is
	uchar attempts = 0;		// how many attempts have been made

	// printf(const char*, ...) is a function used to print a formatted string. Originated from C. Looks a bit neater than using cin sometimes.
	printf("Number Guessing Game:\n");	// print out "Number Guessing Game:" 
										// Escape Sequence: https://msdn.microsoft.com/en-us/library/6aw8xdf2.aspx
										// difference between [\n] and [endl]: "\n" is a character, "endl" is a stream manipulator

	printf("You have %i tries to guess a number between %i and %i.\n", NUM_GUESSES, MIN_VAL, MAX_VAL);	
	// format specifier: http://www.cplusplus.com/reference/cstdio/printf/

	srand((unsigned int)time(NULL));	// seeds the rng to ensure different values every time
										// srand: to initialize random number generator: http://www.cplusplus.com/reference/cstdlib/srand/?kw=srand
	target = rand() % 100 + 1;			// target: to get a pointer to target: http://www.cplusplus.com/reference/functional/function/target/
										// rand: to generate random number: http://www.cplusplus.com/reference/cstdlib/rand/
										// put the value of target in the range 1 to 100


	//	Game loop. While you haven't had a correct guess, and still have attempts left...
	cout << "\nGuess a number: ";						// output: Guess a number:

	while (guess != target && attempts < NUM_GUESSES)	// condition: while the user's guess is not right and attempts are less than the maxium of attempts
	{
		string temp;									// temp string to store user input
		cin >> temp;									// gets the input and stores in temp
		guess = atoi(temp.c_str());						// converts the string in temp to a number. can also use stoi() but that does not handle non-convertable strings nicely.
		// stringstream is another option.

		// in C++, NULL == false == 0, and atoi() will return 0 if the conversion failed.
		if (!guess)										// if the conversion fails, !guess becomes true
			cout << "Not a number" << endl;				// output: Not a number

		// check bounds of the guess
		else if (guess < MIN_VAL || guess > MAX_VAL)	// if the guess is less than the value of MIN_VAL and more than the value of MAX_VAL
			cout << "Number out of range." << endl;		// output: Number ut of range.

		// inform user of results of attempt
		else
		{
			++attempts;									// add 1 to the value of attempts
			if (guess < target)							// if the guess number is less than the target number
				cout << "You guessed too low. You have " << (NUM_GUESSES - attempts) << " tries left." << endl;		// hint the user, show the remaining times
			else if (guess > target)					// if the guess number is more than the target number
				cout << "You guessed too high. You have " << (NUM_GUESSES - attempts) << " tries left." << endl;	// hint the user, show the remaining times
			if (guess != target)						// if we reach this point, we need to guess again
				cout << "\nGuess again: ";				// output: Guess again:
		}
	}

	cout << "\nThe target was " << target << "." << endl;						// if the number of attempts reach to the maxium and the guess is not right
																				// output: The target was "the target value"
    if (guess == target)
    {
        cout << "You win." << endl;
    }
    else
    {
        cout << "You lose." << endl;
    }

	system("PAUSE");															// makes the "press any key to continue prompt"
	return 0;
}

