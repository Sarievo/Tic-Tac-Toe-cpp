#include <iostream>
#include <vector>

void stateWinner(int state);

using namespace std;

void printBoard(vector<vector<int>> board) {
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ":||";
        for (int j = 0; j < 3; j++) {
            if (j != 0) cout << '|';
            switch (board[i][j]) {
                case 1:
                    cout << 'X';
                    break;
                case 2:
                    cout << 'O';
                    break;
                default:
                    cout << ' ';
            }
        }
        cout << "||" << endl;
    }
    cout << "===========" << endl;
}

//  check state, return 0 if nothing happens, 1 if X wins, and 2 if O wins;
int checkState(vector<vector<int>> board) {
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        if (board[1][1] == 1) return 1;
        if (board[1][1] == 2) return 2;
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        if (board[1][1] == 1) return 1;
        if (board[1][1] == 2) return 2;
    }
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            if (board[i][1] == 1) return 1;
            if (board[i][1] == 2) return 2;
        }
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            if (board[1][i] == 1) return 1;
            if (board[1][i] == 2) return 2;
        }
    }
    return 0;
}

int main() {
    cout << "Tic-Tac-Toe\n";
    vector<vector<int>> board(3, vector<int>(3, 0)); // type(size, default_value)
    bool onX = true;
    int round = 0; // init at 0, inc at every move, if it reaches 9 and nobody wins, the game ends as draw.
    while (true) {
        printBoard(board);
        cout << "current move: " << (onX ? "(X)" : "(O)") << "\n";
        cout << "choose the coordinate <x, y> separate by space:";
        int x, y;
        cin >> x >> y;
        if (x < 1 || x > 3 || y < 1 || y > 3) {
            cout << "Invalid output (out-of-bound).\n\n";
            continue;
        }
        x--; y--;
        if (board[x][y] != 0) {
            cout << "Invalid output (occupied).\n\n";
            continue;
        }
        cout << endl;

        board[x][y] = onX ? 1 : 2;

        int state = checkState(board);
        if (state != 0) {
            stateWinner(state);
            break;
        }
        if (++round == 9) break;
        onX = !onX;
    }
    cout << "Thanks for playing.\n";
}

void stateWinner(int state) {
    cout << "The Winner is: ";
    if (state == 1) {
        cout << "(X)!";
    } else {
        cout << "(O)!";
    }
    cout << endl;
}
