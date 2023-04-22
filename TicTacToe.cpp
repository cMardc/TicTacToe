#include "TicTacToe.h"
using namespace std;


int main()
{
    vector<vector<char>> board;
    vector<char> ln1 = { '-', '-', '-' };
    vector<char> ln2 = { '-', '-', '-' };
    vector<char> ln3 = { '-', '-', '-' };
    board.push_back(ln1);
    board.push_back(ln2);
    board.push_back(ln3);

    bool turn = true;
    cout << "Game Started!\n\n";

    while (true)
    {
        int x, y;
        if (turn)
        {
            setColor("blue");
            cout << "Enter X (row, column): ";
            cin >> x >> y;

            if (x >= 0 && x < 3 && y >= 0 && y < 3 && board[x][y] == '-')
            {
                board[x][y] = 'X';
                turn = false;
            }
            else
            {
                cout << "Invalid move, try again.\n";
                continue;
            }
        }
        else
        {
            setColor("red");
            cout << "Enter O (row, column): ";
            cin >> x >> y;

            if (x >= 0 && x < 3 && y >= 0 && y < 3 && board[x][y] == '-')
            {
                board[x][y] = 'O';
                turn = true;
            }
            else
            {
                cout << "Invalid move, try again.\n";
                continue;
            }
        }

        // Print the board
        cout << "\n";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 'X')
                {
                    setColor("blue");
                }
                else if (board[i][j] == 'O')
                {
                    setColor("red");
                }
                else
                {
                    setColor("white");
                }
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        // Check for winner
        if (isWinner(board))
        {
            setColor("white");
            cout << "Congratulations! ";
            if (!turn)
            {
                setColor("blue");
                cout << "X is the winner!\n";
            }
            else
            {
                setColor("red");
                cout << "O is the winner!\n";
            }
            break;
        }

        //Check If Tie
        bool tie = true;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '-')
                {
                    tie = false;
                }
            }
            cout << "\n";
        }
        cout << "\n";

        if (tie)
        {
            cout << "\nTIE!\n";
            break;
        }
    }
    setColor("white");
    string anything;
    cout << "\nEnter Anything To Exit.\n";
    cin >> anything;
    return 0;
}