/*
Number Guessing Game
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
*/


#include <time.h>
#include <string>
#include <iostream>


using namespace std;

// Define constants (the const keyword tells the compiler that this variable won't change)
// It's common to name constants with all caps.
const int NUM_GUESSES = 7;  // actually, use "log[2] (ceil(max-min)+1) -- 2^guesses = range of values if player uses "binary search"
const int MIN_VAL = 1;      // initialize a constant variable MIN_VAL, assign 1 to it
const int MAX_VAL = 100;    // initialize a constant variable MAX_VAL, assign 100 to it


int main()
{
    int guess = 0;      // what the user's guess was, 
    int target = -1;    // what the number to guess is
    int attempts = 0;   // how many attempts have been made


    cout << "Number Guessing Game: " << endl;

    // Print out the options for the player.
    cout << "You have " << NUM_GUESSES << " tries to guess a number between " << MIN_VAL << " and " << MAX_VAL << "." << endl;



    srand((unsigned int)time(nullptr)); // seeds the rng to ensure different values every time
                                        // srand: to initialize random number generator: http://www.cplusplus.com/reference/cstdlib/srand/?kw=srand
    target = rand() % 100 + 1;          // rand: to generate random number: http://www.cplusplus.com/reference/cstdlib/rand/
                                        // put the value of target in the range 1 to 100


    //	Game loop. While you haven't had a correct guess, and still have attempts left...
    cout << "\nGuess a number: ";                       // output: Guess a number:

    while (guess != target && attempts < NUM_GUESSES)   // loop while the user's guess is not right and attempts are less than the maxium of attempts
    {
        // If cin errors, print out NAN and wait for more input
        if (!(cin >> guess))
        {
            cin.clear();                                // Clear error flag so cin will still work.
            cin.ignore(10000, '\n');                    // Ignore any remaining input until a newline is reached.
            cout << "\nNot a number" << endl;           // Output error message.
        }
        // check bounds of the guess
        else if (guess < MIN_VAL || guess > MAX_VAL)    // if the guess is less than the value of MIN_VAL and more than the value of MAX_VAL
        {
            cout << "\nNumber out of range." << endl;     // output: Number ut of range.
        }
        // inform user of results of attempt
        else
        {
            attempts++;                                 // Use up one of the guesses.

            if (guess < target)                         // The guess was too low.
            {
                cout << "You guessed too low. You have " << (NUM_GUESSES - attempts) << " tries left." << endl;
            }
            else if (guess > target)                    // The guess was too high.
            {
                cout << "You guessed too high. You have " << (NUM_GUESSES - attempts) << " tries left." << endl;
            }
            if (guess != target)                        // If we reach this point, we need to guess again.
            {
                cout << "\nGuess again: ";
            }
        }
    }

    cout << "\nThe target was " << target << "." << endl;   // if the number of attempts reach to the maxium and the guess is not right
                                                            // output: The target was "the target value"
    if (guess == target)
    {
        cout << "You win." << endl;
    }
    else
    {
        cout << "You lose." << endl;
    }


    cin.ignore(); // ingore newline left in the stream.
    cin.get();    // wait for the user to press enter to exit.
    return 0;
}

