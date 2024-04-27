#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include<graphics.h>
using namespace std;

void seedRandom() {
    srand(time(0));
}

int image(){
 	initwindow(600, 600, "SnakeAndLadder");
    readimagefile("sndlpic.jpg",50, 50, 500, 500);   
	return 0;
}

int dice() {
    int total = 0;
    while (true) {
        int roll = (rand() % 6) + 1;
        total += roll;
        if (roll != 6)
            break;
    }
    return total;
}

int traps(int z) {
    switch (z) {
        case 4:
            return 25;
        case 13:
            return 46;
        case 27:
            return 5;
        case 33:
            return 49;
        case 40:
            return 3;
        case 42:
            return 63;
        case 43:
            return 18;
        case 50:
            return 69;
        case 54:
            return 31;
        case 62:
            return 81;
        case 66:
            return 45;
        case 74:
            return 92;
        case 76:
            return 58;
        case 89:
            return 53;
        case 99:
            return 41;
        default:
            return z;
    }
}

void player() {
    int p1s = 0, p2s = 0, n = 0, p;
    do {
        int m = 0;
        if (n % 2 == 0) {
            cout << "Player 1's turn\n";
            m = dice();
            cout << "Dice = " << m << "\n";
            p1s += m;
            p1s = traps(p1s);
            cout << "Player 1: " << p1s << endl;
            cout << "Enter 2 for player 2's turn: ";
            cin >> p;
        } else {
            cout << "Player 2's turn\n";
            m = dice();
            cout << "Dice = " << m << "\n";
            p2s += m;
            p2s = traps(p2s);
            cout << "Player 2: " << p2s << endl;
            cout << "Enter 1 for player 1's turn: ";
            cin >> p;
        }
        n++;
    } while (p1s < 100 && p2s < 100);
    if (p1s >= 100) {
        cout << "Player 1 is the winner!\n";
    } else if (p2s >= 100) {
        cout << "Player 2 is the winner!\n";
    }
}

int main() {
	image();
    seedRandom();
    player();
    
    return 0;
}

