#include <iostream>
#include <unistd.h>   // for usleep
#include <termios.h>  // for terminal control
#include <fcntl.h>    // for non-blocking
#include <poll.h>     // for poll()

using namespace std;

// --- Terminal settings ---
void setNonCanonicalMode(bool enable) {
    static struct termios oldt, newt;

    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt); // save old settings
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // disable canonical mode and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore old settings
    }
}

// --- Non-blocking keypress ---
bool isKeyPressed() {
    struct pollfd pfd = { STDIN_FILENO, POLLIN, 0 };
    int ret = poll(&pfd, 1, 0);
    return ret > 0;
}

// --- Globals ---
bool gameOver;
bool wrapEnabled = false;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
    gameOver = false;
    dir = STOP;
    wrapEnabled = false;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail = 0;
}

void Draw() {
    system("clear"); // Clear screen (Mac/Linux)

    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        cout << "#"; // Left wall
        for (int j = 0; j < width; j++) {
            if (i == y && j == x)
                cout << "O"; // Snake head
            else if (i == fruitY && j == fruitX)
                cout << "F"; // Fruit
            else {
                bool printed = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        printed = true;
                    }
                }
                if (!printed) cout << " ";
            }
        }
        cout << "#" << endl; // Right wall
    }

    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    cout << "Score: " << score << "  ";
    cout << (wrapEnabled ? "[WRAP MODE ON]" : "[WRAP MODE OFF]") << endl;
}

void Input() {
    if (isKeyPressed()) {
        char key;
        read(STDIN_FILENO, &key, 1);

        switch (key) {
            case 'w':
                dir = UP;
                break;
            case 'a':
                dir = LEFT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'q':
                gameOver = true;
                break;
            case 'e':
                wrapEnabled = !wrapEnabled;
                break;
        }
    }
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    if (wrapEnabled) {
        if (x >= width) x = 0;
        else if (x < 0) x = width - 1;
        if (y >= height) y = 0;
        else if (y < 0) y = height - 1;
    } else {
        if (x >= width || x < 0 || y >= height || y < 0)
            gameOver = true;
    }

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main() {
    setNonCanonicalMode(true); // set terminal to non-canonical mode
    Setup();

    while (!gameOver) {
        Draw();
        Input();
        Logic();
        usleep(100000); // 0.1 seconds
    }

    setNonCanonicalMode(false); // reset terminal settings
    cout << "Game Over! Final Score: " << score << endl;

    return 0;
}
