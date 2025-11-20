// X And O.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void drawboard(char board[3][3])

{
    // draw stages
    for (int i = 0; i < 7; i++)
    {

        if (i % 2 == 0)
        {
            for (int j = 0; j < 13; j++)
            {
                cout << "-";
            }
            
        }
        else
        {
            for (int j = 0; j < 4; j++)
            {
                if (j < 3)
                {
                    cout << "| " << board[i / 2][j] << " ";
                }
                else
                {
                    cout << "|   ";

                }

            }
        }
        cout << endl;
    }





}
char CheckWinner(char board[3][3])
{
    //check virtical
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
        {
            return board[0][i];
        }
    }
    //check horizontal
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
        {
            return board[i][0];
        }
    }
    //check diagonal
    
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        {
            return board[0][0];
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        {
            return board[0][2];
        }
        return ' ';
}


int main()
{
    
    char gameover = ' ';
    char board[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    bool isx = true;
    drawboard(board);
    int placed = 0;
    do
    {
        cout << "choose your place" << endl;
        int x, y;
        cin >> x >> y;
        while (board[x][y] != ' ' || x > 2 || x < 0 || y>2 || x < 0)
        {
            cout << "invalid place or filled place ! please choose again " << endl;
            cin >> x >> y;
        }

        if (isx)
        {
            board[x][y] = 'x';
        }
        else
        {
            board[x][y] = 'o';
        }
        placed++;
        drawboard(board);
        gameover = CheckWinner(board);

        if (placed == 9 && gameover == ' ')
        {
            cout << "No one won ! Game Over" << endl;
        }
        isx = !isx;
    } while (gameover == ' ');

    if (gameover == 'x')
    {
        cout << "x won" << endl;
    }
    if (gameover == 'o')
    {
        cout << "o won " << endl;
    }
    drawboard(board);


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
