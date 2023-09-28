// Guessing Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
using namespace std;

int main(){
    srand((unsigned)time(NULL)); // Initializing random generator
    
    // Initiaizing variables
    int randomNum, inputNum, guesses = 0;
    char reply;
    bool whenToStop = 1;

    // Main user-controlled loop
    while (whenToStop) { // Stops when 'N' or 'n' is inputted
        randomNum = rand() % 1000 + 1; // Creating a random number from 1-1000

        // Guessing the number loop
        do {
            cout << "Guess a number between 1 and 1000 or input 0 to quit: ";
            cin >> inputNum;
            if (inputNum != 0) {
                guesses++;
                if (inputNum == randomNum) {
                    cout << "   GOOD JOB! That's correct! You used " << guesses << " guesses.\n";
                    inputNum = 0;
                }else {
                    cout << "   Your Guess is TOO " << (inputNum > randomNum ? "BIG!\n" : "SMALL!\n");
                }
            }
        } while (inputNum != 0);

        // Asking to play again loop
        cout << '\n' << "Would you like to play again (Y/N): ";
        cin >> reply;
        while (1) {
            if (reply == 'Y' || reply == 'y') {
                cout << '\n';
                break;
            }else if (reply == 'N' || reply == 'n') {
                whenToStop = 0;
                cout << '\n' << "Thanks for playing!\n";
                break;
            }else { // Command if input is invalid
                cout << '\n' << "Please indicate Y or N: ";
                cin >> reply;
            }
        }
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
