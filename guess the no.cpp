#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int guess = rand() % 100 + 1;
    int userguess = 0;
    cout << "Welcome to the Number Guessing Game!" << endl;
    while (true)
    {
        cout << "Enter your guess: ";
        cin >> userguess;
        if (userguess < guess)
        {
            cout << "Your guess is too low. Try again." << endl;
        }
        else if (userguess > guess)
        {
            cout << "Your guess is too high. Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You've guessed the number correctly!" << endl;
            break;
        }
    }
    return 0;
}
