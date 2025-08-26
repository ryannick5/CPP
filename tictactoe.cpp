

#include <iostream>

using namespace std;

void Draw () {
    for (int i = 0; i < 4; i++) {
        cout << " ";
    } cout << "#";
    for (int i = 0; i < 4; i++) {
        cout << " ";
    } cout << "#";
    for (int i = 0; i < 4; i++) {
        cout << " ";
    }
    cout << "\n";
}

void Draw2 () {
    Draw();
    Draw();
    Draw();
    for (int i = 0; i < 14; i++) {
        cout << "#";
    }
    cout << "\n";
}

void Draw3 () {
    Draw2();
    Draw2();
    Draw();
    Draw();
    Draw();
}

int main()
{
    Draw3();

    return 0;
}

