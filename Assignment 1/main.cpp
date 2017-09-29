#include <iostream>
#include <vector>

using namespace std;

static int player = 1;
static int ai = 2;
/* Notes
 *
 * 0 = Empty
 * 1 = X
 * 2 = O
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

class aiClass {
private:
    int corners [4] = {1,3,7,9};

    int checkForWin(int playerOrAi, gameBoard board) {

        for(int i = 2; i <= 8; i += 3) {
            if(board.getSquareStatus(i) == playerOrAi) {
                if(board.getSquareStatus(i) == board.getSquareStatus(i+1)) {
                    if(board.getSquareStatus(i-1) == 0) {
                        return i - 1;
                    }
                } else if(board.getSquareStatus(i) == board.getSquareStatus(i-1)) {
                    if(board.getSquareStatus(i+1) == 0) {
                        return i + 1;
                    }
                }
            }
        }

        for(int i = 4; i <= 6; i++) {
            if(board.getSquareStatus(i) == playerOrAi) {
                if(board.getSquareStatus(i) == board.getSquareStatus(i+3)) {
                    if(board.getSquareStatus(i-3) == 0) {
                        return i - 3;
                    }
                } else if(board.getSquareStatus(i) == board.getSquareStatus(i-3)) {
                    if(board.getSquareStatus(i+1) == 0) {
                        return i + 3;
                    }
                }
            }

        }

        if(board.getSquareStatus(5) == playerOrAi) {
            for(int i = 0; i < (sizeof(corners)/sizeof(corners[0])); i++) {
                if(board.getSquareStatus(corners[i]) == board.getSquareStatus(5)) {
                    if(board.getSquareStatus(corners[(sizeof(corners)/sizeof(corners[0])) - (i + 1)]) == 0) {
                        return corners[(sizeof(corners)/sizeof(corners[0])) - (i + 1)];
                    }
                }
            }
        }
        return 0;
    }//end checkForWin

public:
    int play(gameBoard board) {

        int playerPieces = 0;
        int aiPieces = 0;

        for(int i = 1; i <= 9; i++) {
            switch(board.getSquareStatus(i)) {
                case 1:
                    playerPieces += 1;
                    break;
                case 2:
                    aiPieces += 1;
                    break;
                default:
                    break;
            }
        }

        int checkWin = checkForWin(ai, board);
        if(checkWin != 0) {
            return checkWin;
        }
        checkWin = checkForWin(player, board);
        if(checkWin != 0) {
            return checkWin;
        }


        switch(playerPieces) {
            case 0:
                return 1;
            case 1:
                if(board.getSquareStatus(5) == player) {
                    switch(aiPieces) {
                        case 0:
                            return 1;
                        case 1:
                            return 9;
                    }
                } else {
                    return 5;
                }
            case 2:
                for(int i : corners) {
                    if(board.getSquareStatus(i) == 0) {
                        return i;
                    }
                }
            default:
                for(int i = 1; i <= 9; i++) {
                    if(board.getSquareStatus(i) == 0) {
                        return i;
                    }
                }
        }

    }

};//and aiClass

bool winner(int playerOrAI) {
    if(playerOrAI == 0) {
        cout << "You tied!\n";
    } else if(playerOrAI == ai) {
        cout << "The AI wins!\n";
    } else if (playerOrAI == player) {
        cout << "You win! ...wait that's not supposed to happen.\n";
    }
    cout << "Enter 1 to play again, or 2 to quit.\n";
    string replayChoice;
    int tmp = 0;
    while(true) {
        getline(cin, replayChoice, '\n');
        tmp = stoi(replayChoice);
        switch(tmp) {
            case 1:
                return true;

            case 2:
                cout << "Goodbye.\n";
                return false;

            default:
                cout << "Please enter 1 to play again, or 2 to exit.\n";
                break;
        }
    }
}//end winner

int main() {

    string turnChoice;
    int turn = 0;
    string gridSelectionString;
    int gridSelection = 0;

    gameBoard board;
    aiClass ai_player = aiClass();

    while(true) {
        board = gameBoard();
        cout << "Welcome to tic-tac-toe! Enter 1 to go first, or 2 to go second.\n";

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
        bool replay = false;
        while(gameRunning) {

            cout << board.getBoardString();

            int i = 1;
            //Check for a win
            //Check horizontals first
            while(i<8) {
                if((board.getSquareStatus(i) == board.getSquareStatus(i+1)) && (board.getSquareStatus(i+1) == board.getSquareStatus(i+2)) && board.getSquareStatus(i) != 0) {
                    replay = winner(board.getSquareStatus(i));
                    gameRunning = false;
                }
                i += 3;
            }
            i = 1;
            //Check verticals
            while(i<3) {
                if((board.getSquareStatus(i) == board.getSquareStatus(i+3)) && (board.getSquareStatus(i+3) == board.getSquareStatus(i+6)) && board.getSquareStatus(i) != 0) {
                    replay = winner(board.getSquareStatus(i));
                    gameRunning = false;
                }
                i += 1;
            }
            //Check diagonals
            if((board.getSquareStatus(1) == board.getSquareStatus(5)) && (board.getSquareStatus(5) == board.getSquareStatus(9)) && board.getSquareStatus(1) != 0) {
                replay = winner(board.getSquareStatus(1));
                gameRunning = false;
            } else if((board.getSquareStatus(3) == board.getSquareStatus(5)) && ((board.getSquareStatus(5)) == board.getSquareStatus(7))  && board.getSquareStatus(3) != 0) {
                replay = winner(board.getSquareStatus(3));
                gameRunning = false;
            }

            //Check for tie
            int emptySpaces = 0;
            for(int i = 1; i <= 9; i++) {
                if(board.getSquareStatus(i) == 0) {
                    emptySpaces += 1;
                }
            }
            if(emptySpaces == 0) {
                replay = winner(0);
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
                cout << "AI's turn...\n";
                board.play(ai, ai_player.play(board));
                turn = player;
                continue;
            }//end if

            break;
        }//end while

        if(replay) {
            continue;
        }

        break;
    }//end while


    return 0;
}//end main