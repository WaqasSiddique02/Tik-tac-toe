#include<iostream>
using namespace std;

void print(char print[3][3]);

// Diagonal check 
int diagonal(char toz[3][3]) {
    if (toz[0][0] == 'X' && toz[1][1] == 'X' && toz[2][2] == 'X')
    {
        return 1;
    }

    else if (toz[0][0] == 'O' && toz[1][1] == 'O' && toz[2][2] == 'O')
    {
        return 0;
    }

    else if (toz[0][2] == 'X' && toz[1][1] == 'X' && toz[2][0] == 'X')
    {
        return 1;
    }

    else if (toz[0][2] == 'O' && toz[1][1] == 'O' && toz[2][0] == 'O')
    {
        return 0;
    }
    return -1;
}

void move(char toe[3][3]) {
    int check = -1;
    int rows = 0;
    int columns = 0;
    int movesMade = 0;

    for (int i = 0; i < 5; i++) { // Changed loop boundary to 5
        if (i % 2 == 0) {
            cout << "Player one, enter your move (row column): ";
        }
        else {
            cout << "Player two, enter your move (row column): ";
        }

        cin >> rows >> columns;

        while (rows < 0 || rows > 2 || columns < 0 || columns > 2 || toe[rows][columns] != '*') {
            cout << "Invalid move! Try again (row column): ";
            cin >> rows >> columns;
        }

        toe[rows][columns] = (i % 2 == 0) ? 'X' : 'O';
        print(toe);
        movesMade++;
        check = diagonal(toe);

        if (check == 1) {
            cout << "Player one has won!";
            return;
        }
        else if (check == 0) {
            cout << "Player two has won!";
            return;
        }
    }

    if (movesMade == 9) {
        cout << "It's a tie!";
        return;
    }
}

void print(char print[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << print[i][j] << "|";
        cout << endl;
    }
}

int main() {
    char tictac[3][3] = { {'*','*','*'},{'*','*','*'},{'*','*','*'} };
    print(tictac);
    move(tictac);

    return 0;
}
