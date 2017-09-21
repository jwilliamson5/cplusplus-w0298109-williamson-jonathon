#include <iostream>
#include <vector>
#include <conio.h>
//TODO: Make game re-playable
using namespace std;
static int player = 1;
static int ai = 2;
/* Notes
 *
 * 0 = Empty
 * 1 = 0
 * 2 = X
 *
 */

class gameBoard {

private:
    vector<vector<int>> squares; //2D Array
    int rowSize = 3;
    int colSize = 3;

public:
    gameBoard() {

        squares.resize(3);

        for(int x = 0; x < 3; x++) {
            squares[x].assign(3, 0);
        }
    }
    int getSquare(int x, int y) {
        return squares[x][y];
    }
    int getSquareStatus(int i) {
        int x = 0;
        int y = 0;

        while(i-3 > 0) {
            x += 1;
            i -= 3;
        }
        y = i - 1;
        return squares[x][y];

    }

    string getBoardString() {
        string rtnString;
        int i = 1;
        for(int x = 0; x < squares.capacity(); x++) {
            for(int y = 0; y < squares.capacity(); y++) {
                if(squares[x][y] == player) {
                    rtnString += " X ";
                } else if(squares[x][y] == ai) {
                    rtnString += " O ";
                } else {
                    rtnString += " " + to_string(i) + " ";
                }
                i++;
            }
            rtnString += "\n";
        }
        return rtnString;
    }

    void play(int playerOrAI, int selection) {
        int x = 0;
        int y = 0;

        while(selection-3 > 0) {
            x += 1;
            selection -= 3;
        }
        y = selection - 1;

        squares[x][y] = playerOrAI;
    }

};//end board class

void winner(int playerOrAI) {
    if(playerOrAI == ai) {
        cout << "The AI wins!\n";
    } else {
        cout << "You win! ...wait that's not supposed to happen.\n";
    }
    getch();
}

int main() {

    string turnChoice;
    int turn = 0;
    string gridSelectionString;
    int gridSelection = 0;

    gameBoard board = gameBoard();



    cout << "Welcome to tic-tac-toe! Enter 1 to go first, or 2 to go second.\n";
    while(true) {

        getline(cin, turnChoice);
        try {
            if(stoi(turnChoice) == 1 || stoi(turnChoice) == 2) {
                turn = stoi(turnChoice);
            } else {
                throw exception();
            }
        } catch (...) {
            cout << "Please enter 1 to go first or 2 to go second.\n";
            continue;
        }
        bool gameRunning = true;
        while(gameRunning) {

            cout << board.getBoardString();

            int i = 1;
            //Check for a win
            //Check horizontals first
            while(i<8) {
                if((board.getSquareStatus(i) == board.getSquareStatus(i+1)) && (board.getSquareStatus(i+1) == board.getSquareStatus(i+2)) && board.getSquareStatus(i) != 0) {
                    winner(board.getSquareStatus(i));
                    gameRunning = false;
                }
                i += 3;
            }
            i = 1;
            //Check verticals
            while(i<3) {
                if((board.getSquareStatus(i) == board.getSquareStatus(i+3)) && (board.getSquareStatus(i+3) == board.getSquareStatus(i+6)) && board.getSquareStatus(i) != 0) {
                    winner(board.getSquareStatus(i));
                    gameRunning = false;
                }
                i += 1;
            }
            //Check diagonals
            if((board.getSquareStatus(1) == board.getSquareStatus(5)) && (board.getSquareStatus(5) == board.getSquareStatus(9)) && board.getSquareStatus(1) != 0) {
                winner(board.getSquareStatus(1));
                gameRunning = false;
            } else if((board.getSquareStatus(3) == board.getSquareStatus(5)) && ((board.getSquareStatus(5)) == board.getSquareStatus(7))  && board.getSquareStatus(3) != 0) {
                winner(board.getSquareStatus(3));
                gameRunning = false;
            }
            if(!gameRunning) {
                break;
            }

            if(turn == player) {

                cout << "Your turn, please select a number that is available on the grid.\n";
                while(true) {
                    getline(cin, gridSelectionString);
                    try {
                        gridSelection = stoi(gridSelectionString);
                        if(board.getSquareStatus(gridSelection) == 0) {
                            board.play(player, gridSelection);
                        } else {
                            throw exception();
                            continue;
                        }
                        break;
                    } catch(...) {
                        cout << "Please select a number that is available.\n";
                    }
                }
                turn = ai;
                continue;
            } else if(turn == ai) {
                //TODO: AI's turn
                cout << "AI's turn...\n";
                gridSelection = 1;
                while(true) {
                    if(board.getSquareStatus(gridSelection) == 0) {
                        board.play(ai, gridSelection);
                        break;
                    } else {
                        gridSelection += 1;
                        continue;
                    }
                }
                turn = player;
                continue;
            }//end if

            break;
        }//end while



        break;
    }//end while


    return 0;
}//end main