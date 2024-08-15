#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer;
void initializeBoard()
{
    for(int i = 0; i < SIZE; ++i)
        {
        for(int j = 0; j < SIZE; ++j)
        {
            board[i][j] = ' ';
        }
    }
}
void displayBoard()
{
    system("clear");
    cout << "  1 2 3" << endl;
    for(int i = 0; i < SIZE; ++i)
        {
        cout << i + 1 << " ";
        for(int j = 0; j < SIZE; ++j)
        {
            cout << board[i][j];
            if(j < SIZE - 1) cout << "|";
        }
        cout << endl;
        if(i < SIZE - 1) cout << "  -----" << endl;
    }
}
bool isMoveValid(int row, int col)
{
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ';
}

bool checkWin()
{
    for(int i = 0; i < SIZE; ++i)
    {
        if((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
           (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
        {
            return true;
        }
    }
    if((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
       (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
    {
        return true;
    }
    return false;
}
bool isDraw()
{
    for(int i = 0; i < SIZE; ++i)
    {
        for(int j = 0; j < SIZE; ++j)
        {
            if(board[i][j] == ' ')
            {

                return false;
            }
        }
    }
    return true;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
void playGame()
{
    initializeBoard();
    currentPlayer = 'X';
    bool gameEnded = false;
    while(!gameEnded)
        {
        int row, col;
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        row--;
        col--;
        if(isMoveValid(row, col))
        {
            board[row][col] = currentPlayer;
            if(checkWin())
            {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameEnded = true;
            }
            else if(isDraw())
            {
                displayBoard();
                cout << "It's a draw!" << endl;
                gameEnded = true;
            } else
            {
                switchPlayer();
            }
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }
}
int main()
{
    char playAgain;
    do
    {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }
    while(playAgain == 'y' || playAgain == 'Y');
    cout << "Thanks for playing!" << endl;
    return 0;
}
