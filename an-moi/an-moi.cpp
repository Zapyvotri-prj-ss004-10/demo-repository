#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Point {
    int x, y;
};

class CONRAN {
public:
    Point A[100];
    int DoDai;
    int diem;

    CONRAN() {
        DoDai = 3;
        diem = 0;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 9; A[1].y = 10;
        A[2].x = 8; A[2].y = 10;
    }

  
    void Ve() {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); 
        for (int i = 0; i < DoDai; i++) {
            gotoxy(A[i].x, A[i].y);
            cout << "X";
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    }


    void XoaDuoi() {
        gotoxy(A[DoDai - 1].x, A[DoDai - 1].y);
        cout << " ";
    }

    void DiChuyen(int Huong) {
        for (int i = DoDai - 1; i > 0; i--) {
            A[i] = A[i - 1];
        }

        if (Huong == 0) A[0].x++;     
        if (Huong == 1) A[0].y++;     
        if (Huong == 2) A[0].x--;     
        if (Huong == 3) A[0].y--;     
    }

    bool AnMoi(int xMoi, int yMoi) {
        if (A[0].x == xMoi && A[0].y == yMoi) {
            A[DoDai] = A[DoDai - 1]; 
            DoDai++;
            diem += 10;
            return true;
        }
        return false;
    }


    bool ChocTuong() {
        return (A[0].x <= 0 || A[0].x >= 59 || A[0].y <= 0 || A[0].y >= 29);
    }

    bool ChocThan() {
        for (int i = 1; i < DoDai; i++) {
            if (A[0].x == A[i].x && A[0].y == A[i].y)
                return true;
        }
        return false;
    }
};

class Moi {
public:
    int x, y;

    void TaoMoi(CONRAN& ran) {
        bool trung;
        do {
            trung = false;
            x = rand() % 57 + 1;
            y = rand() % 27 + 1;
            for (int i = 0; i < ran.DoDai; i++) {
                if (x == ran.A[i].x && y == ran.A[i].y) {
                    trung = true;
                    break;
                }
            }
        } while (trung);
    }

    void Ve() {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); 
        gotoxy(x, y);
        cout << "*";
    }
};
void ManHinhBatDau() {
    system("cls");
    gotoxy(20, 10); cout << "=== GAME RAN SAN MOI ===";
    gotoxy(18, 12); cout << "Nhan phim bat ky de bat dau...";
    while (!_kbhit()) Sleep(100);
    _getch(); 
    system("cls");
}
int main() {
    system("mode con cols=60 lines=30");
    system("title Snake Game");
    system("color 0A");


    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hOut, &cursorInfo);

    CONRAN r;
    Moi m;
    m.TaoMoi(r);
    ManHinhBatDau();
    int Huong = 0; 
    char t;


    system("cls");
    for (int x = 0; x < 60; x++) {
        gotoxy(x, 0); cout << "#";
        gotoxy(x, 29); cout << "#";
    }
    for (int y = 0; y < 30; y++) {
        gotoxy(0, y); cout << "#";
        gotoxy(59, y); cout << "#";
    }

    gotoxy(2, 1); cout << "DIEM: 0";

    while (true) {

        if (_kbhit()) {
            t = _getch();
            if (t == 'a' && Huong != 0) Huong = 2;
            if (t == 'w' && Huong != 1) Huong = 3;
            if (t == 'd' && Huong != 2) Huong = 0;
            if (t == 's' && Huong != 3) Huong = 1;
        }

        r.XoaDuoi();
        r.DiChuyen(Huong);

        if (r.AnMoi(m.x, m.y)) {
            m.TaoMoi(r);
        }

        r.Ve();
        m.Ve();

        gotoxy(8, 1);
        cout << r.diem << "  ";

        if (r.ChocTuong() || r.ChocThan()) {
            gotoxy(20, 14);
            cout << "GAME OVER! DIEM: " << r.diem;
            gotoxy(20, 16);
            cout << "Nhan phim bat ky de thoat...";
            while (!_kbhit()) Sleep(100);
            break;
        }

        Sleep(150);
    }


    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hOut, &cursorInfo);

    return 0;
}

