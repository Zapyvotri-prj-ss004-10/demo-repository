#include <iostream>
#include <conio.h>     
#include <windows.h>   
#include <cstdlib>  
using namespace std;

#define MINX 2
#define MINY 2
#define MAXX 35
#define MAXY 20

struct Point {
    int x, y;
};

Point Qua; 


void Ve(Point Qua) {
    for (int i = 0; i < DoDai; i++) {
        gotoxy(A[i].x, A[i].y);
        cout << "x"; 
    }
    gotoxy(Qua.x, Qua.y);
    cout << "s"; 
}
void Dichuyen(int Huong, Point& Qua) {

    for (int i = DoDai - 1; i > 0; i--) {
        A[i] = A[i - 1];
    }

    if (Huong == 0) A[0].x++;
    if (Huong == 1) A[0].y++;
    if (Huong == 2) A[0].x--;
    if (Huong == 3) A[0].y--;
    
////////////////////// Xu ly An moi
    if (A[0].x == Qua.x && A[0].y == Qua.y) {
        DoDai++; 
        Qua.x = rand() % (MAXX - MINX) + MINX;
        Qua.y = rand() % (MAXY - MINY) + MINY;
    }
}
int main() {
  
    Qua.x = rand() % (MAXX - MINX) + MINX;
    Qua.y = rand() % (MAXY - MINY) + MINY;

    while (true) {
        system("cls");
        Vekhung();     
        r.Ve(Qua);      
        r.Dichuyen(Huong, Qua); 
        Sleep(300);
    }
}
