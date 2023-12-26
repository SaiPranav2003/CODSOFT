#include <bits/stdc++.h>
using namespace std;

void playGame(int lowBo, int uppBo, int max_Attempts);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    do {
        cout << "=== Welcome to the Guess the Number Game ===" << endl;

        //Asking the user to choose the difficulty level of the game.
        cout << "Choose a difficulty level:" << endl;
        cout << "1. Easy (1-50)\n2. Medium (1-100)\n3. Hard (1-200)" << endl;

        int difficulty;
        cin >> difficulty;

        int lowBo, uppBo, max_Attempts;
        switch (difficulty) {
            case 1:
                lowBo = 1;
                uppBo = 50;
                max_Attempts = 10;
                break;
            case 2:
                lowBo = 1;
                uppBo = 100;
                max_Attempts = 7;
                break;
            case 3:
                lowBo = 1;
                uppBo = 200;
                max_Attempts = 5;
                break;
            default:
                cout << "Invalid choice. Defaulting to Medium difficulty." << endl;
                lowBo = 1;
                uppBo = 100;
                max_Attempts = 7;
                break;
        }

        //Starting the game by taking the difficulty level given by the user
        playGame(lowBo, uppBo, max_Attempts);

        
        cout << "Wanna play again? (y/n): ";
        char playAgain;
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            cout << "Thanks for playing. Hope you enjoyed the game. Goodbye!" << endl;
            break;
        }

    } while (true);

    return 0;
}

void playGame(int lowBo, int uppBo, int max_Attempts) {
    int secretNumber = rand() % (uppBo - lowBo + 1) + lowBo;
    int user_GuessedNo;
    int attempts = 0;
    int score = 0;

    cout << "I've picked a number between " << lowBo << " and " << uppBo << ". Can you guess it?" << endl;

    while (attempts < max_Attempts) {
        cout << "Attempt # " << attempts + 1 << ": ";
        cin >> user_GuessedNo;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (user_GuessedNo < lowBo || user_GuessedNo > uppBo) {
            cout << "Out of range! Please guess between " << lowBo << " and " << uppBo << "." << endl;
            continue;
        }

        attempts++;

        if (user_GuessedNo == secretNumber) {
            cout << "Congratulations!!!! You guessed the correct number in " << attempts << " attempts." << endl;
            score = max_Attempts - attempts + 1;
            cout << "Your score: " << score << " out of " << max_Attempts << endl;
            break;
        } else if (user_GuessedNo > secretNumber) {
            cout << "Too high! ";
        } else {
            cout << "Too low! ";
        }

        cout << "Attempts left: " << max_Attempts - attempts << endl;
    }

    if (attempts == max_Attempts) {
        cout << "Sorry, you've run out of attempts. Better luck next time!!!. The correct number was: " << secretNumber << endl;
    }
}
