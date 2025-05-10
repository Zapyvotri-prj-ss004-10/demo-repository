/*
 * Snake Game - Version 1.0.0 (24/04/2024)
 */
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <fstream>
using namespace std;

#define MINX 2    
#define MINY 2    
#define MAXX 35   
#define MAXY 20  

struct Point {
    int x, y;
};

void gotoxy(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class CONRAN {
public:
    Point A[100];
    int DoDai;
    int diem;
    CONRAN() {
        DoDai = 3;
        diem = 0;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    }

    void Ve() {
        // Dau ran la @
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        gotoxy(A[0].x, A[0].y);
        cout << "@";

        // Than ran la X
        for (int i = 1; i < DoDai; i++) {
            gotoxy(A[i].x, A[i].y);
            cout << "X";
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    }
    // di-chuyen
    void DiChuyen(int Huong) {
        for (int i = DoDai - 1; i > 0; i--)
            A[i] = A[i - 1];
        if (Huong == 0) A[0].x++;
        if (Huong == 1) A[0].y++;
        if (Huong == 2) A[0].x--;
        if (Huong == 3) A[0].y--;
    }
    // an-moi
    bool AnMoi(Point& Qua) {
        if (A[0].x == Qua.x && A[0].y == Qua.y) {
            A[DoDai] = A[DoDai - 1];
            DoDai++;
            diem += 10;
            Qua.x = rand() % (MAXX - MINX - 1) + MINX + 1;
            Qua.y = rand() % (MAXY - MINY - 1) + MINY + 1;
            return true;
        }
        return false;
    }

    bool ChocTuong() {
        return (A[0].x <= MINX || A[0].x >= MAXX || A[0].y <= MINY || A[0].y >= MAXY);
    }

    bool ChocThan() {
        for (int i = 1; i < DoDai; i++) {
            if (A[0].x == A[i].x && A[0].y == A[i].y)
                return true;
        }
        return false;
    }
};
// ve-khung
void VeKhung() {
    for (int i = MINX; i <= MAXX; i++) {
        gotoxy(i, MINY); cout << "-";
        gotoxy(i, MAXY); cout << "-";
    }
    for (int j = MINY; j <= MAXY; j++) {
        gotoxy(MINX, j); cout << "|";
        gotoxy(MAXX, j); cout << "|";
    }

    gotoxy(MINX, MINY); cout << "+";
    gotoxy(MAXX, MINY); cout << "+";
    gotoxy(MINX, MAXY); cout << "+";
    gotoxy(MAXX, MAXY); cout << "+";
}
// menu-score
void menu() {
    cout << "=== SNAKE GAME ===\n";
    cout << "1. Start Game\n";
    cout << "2. High Score\n";
    cout << "3. Exit\n";
    cout << "Choose: ";
}

void saveScore(int score) {
    int high = 0;
    ifstream in("high.txt");
    if (in.is_open()) {
        in >> high;
        in.close();
    }

    if (score > high) {
        ofstream out("high.txt");
        if (out.is_open()) {
            out << score;
            out.close();
            cout << "New High Score!\n";
        }
    }
}

void showHighScore() {
    int high = 0;
    ifstream in("high.txt");
    if (in.is_open()) {
        if (in >> high)
            cout << "High Score: " << high << endl;
        else
            cout << "No high score yet.\n";
        in.close();
    }
    else {
        cout << "No high score yet.\n";
    }
}

int main() {
    int choice = 0;
    bool running = true;

    while (running) {
        system("cls");
        menu();
        cin >> choice;

        switch (choice) {
        case 1: {
            CONRAN r;
            Point Qua;
            Qua.x = rand() % (MAXX - MINX - 1) + MINX + 1;
            Qua.y = rand() % (MAXY - MINY - 1) + MINY + 1;
            int Huong = 0;
            char t;
            bool firstMove = true;

            while (true) {
                if (_kbhit()) {
                    t = _getch();
                    if (t == 'a' || t == 'A') Huong = 2;
                    if (t == 'w' || t == 'W') Huong = 3;
                    if (t == 'd' || t == 'D') Huong = 0;
                    if (t == 's' || t == 'S') Huong = 1;
                }
                //Xoa duoi cu truoc khi move
                gotoxy(r.A[r.DoDai - 1].x, r.A[r.DoDai - 1].y);
                cout << " ";
                r.DiChuyen(Huong);

                if (r.AnMoi(Qua)) {
                    Beep(1000, 100);
                    //ve lai khung va moi khi an moi, khong xoa X
                    Qua.x = rand() % (MAXX - MINX - 1) + MINX + 1;
                    Qua.y = rand() % (MAXY - MINY - 1) + MINY + 1;
                    gotoxy(Qua.x, Qua.y);
                    cout << "*";
                    gotoxy(MINX, MAXY + 2);
                    cout << "Score: " << r.diem << "   ";
                }

                if (!firstMove && (r.ChocTuong() || r.ChocThan())) {
                    gotoxy(MAXX / 2 - 5, MAXY / 2);
                    cout << "GAME OVER!";
                    gotoxy(MAXX / 2 - 8, MAXY / 2 + 1);
                    cout << "Your Score:  " << r.diem << endl;
                    saveScore(r.diem);
                    system("pause");
                    break;
                }

                system("cls");
                VeKhung();
                gotoxy(MINX, MAXY + 2);
                cout << "Score: " << r.diem;
                r.Ve();
                gotoxy(Qua.x, Qua.y);
                cout << "*";
                firstMove = false;
                Sleep(300);
            }
            break;
        }
        case 2:
            showHighScore();
            system("pause");
            break;
        case 3:
            running = false;
            break;
        default:
            cout << "Lua chon khong hop le.\n";
            system("pause");
            break;
        }
    }

    return 0;
}
