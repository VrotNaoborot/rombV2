#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

bool isBorders(int y, int x, const vector<vector<char>>& a) {
    int ln = a.size() / 2;
    return (ln < x + y && x + y < ln * 3) && (abs(x - y) < ln) && a[y][x] == ' ';
}

int main() {
    vector<vector<char>> a = {
            {' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' '},
            {' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' '},
            {' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' '},
            {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'},
            {' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' '},
            {' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' '},
            {' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' '}
    };
//    vector<vector<char>> a = {
//            {' ', ' ', ' ', '*', ' ', ' ', ' '},
//            {' ', ' ', '*', ' ', '*', ' ', ' '},
//            {' ', '*', ' ', ' ', ' ', '*', ' '},
//            {'*', ' ', ' ', '*', ' ', ' ', '*'},
//            {' ', '*', ' ', ' ', ' ', '*', ' '},
//            {' ', ' ', '*', ' ', '*', ' ', ' '},
//            {' ', ' ', ' ', '*', ' ', ' ', ' '}
//    };
//    vector<vector<char>> a = {
//            {' ', ' ', '*', ' ', ' '},
//            {' ', '*', ' ', '*', ' '},
//            {'*', ' ', '*', ' ', '*'},
//            {' ', '*', ' ', '*', ' '},
//            {' ', ' ', '*', ' ', ' '}
//    };

    int currentX = a.size() / 2;
    int currentY = a.size() / 2;

    while (true) {
        int leftX = currentX - 1;
        int leftY = currentY;

        int leftUpX = currentX - 1;
        int leftUpY = currentY - 1;

        int UpX = currentX;
        int UpY = currentY - 1;

        int RightUpX = currentX + 1;
        int RightUpY = currentY - 1;

        int rightX = currentX + 1;
        int rightY = currentY;

        int DownRightX = currentX + 1;
        int DownRightY = currentY + 1;

        int DownX = currentX;
        int DownY = currentY + 1;

        int LeftDownX = currentX - 1;
        int LeftDownY = currentY + 1;

        if (isBorders(leftUpY, leftUpX, a)) {
            currentX = leftUpX;
            currentY = leftUpY;
            a[currentY][currentX] = '*';
            continue;
        } else if (isBorders(UpY, UpX, a)) {
            currentX = UpX;
            currentY = UpY;
            a[currentY][currentX] = '*';
            continue;
        } else if (isBorders(RightUpY, RightUpX, a)) {
            currentX = RightUpX;
            currentY = RightUpY;
            a[currentY][currentX] = '*';
            continue;
        } else if (isBorders(rightY, rightX, a)) {
            currentX = rightX;
            currentY = rightY;
            a[currentY][currentX] = '*';
            continue;
        } else if (isBorders(DownRightY, DownRightX, a)) {
            currentX = DownRightX;
            currentY = DownRightY;
            a[currentY][currentX] = '*';
            continue;
        } else if (isBorders(DownY, DownX, a)) {
            currentX = DownX;
            currentY = DownY;
            a[currentY][currentX] = '*';
            continue;
        } else if (isBorders(LeftDownY, LeftDownX, a)) {
            currentX = LeftDownX;
            currentY = LeftDownY;
            a[currentY][currentX] = '*';
            continue;
        } else if (isBorders(leftY, leftX, a)) {
            currentX = leftX;
            currentY = leftY;
            a[currentY][currentX] = '*';
            continue;
        } else {
            break;
        }
    }

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}