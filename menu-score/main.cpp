#include <iostream>
#include <fstream>
using namespace std;

void menu() {
    cout << "=== SNAKE GAME ===\n";
    cout << "1. Start Game\n";
    cout << "2. High Score\n";
    cout << "3. Exit\n";
    cout << "Choose: ";
}

void saveScore(int score) {
    int high;
    ifstream in("high.txt");
    in >> high;
    in.close();

    if (score > high) {
        ofstream out("high.txt");
        out << score;
        out.close();
        cout << "New High Score!\n";
    }
}

void showHighScore() {
    int high;
    ifstream in("high.txt");
    if (in >> high)
        cout << "High Score: " << high << endl;
    else
        cout << "No high score yet.\n";
    in.close();
}

int main() {
    int choice, score;

    do {
        menu();
        cin >> choice;

        if (choice == 1) {
            score = 0;
            cout << "Your Score: " << score << endl;
            saveScore(score);
        } else if (choice == 2) {
            showHighScore();
        }

    } while (choice != 3);

    return 0;
}
