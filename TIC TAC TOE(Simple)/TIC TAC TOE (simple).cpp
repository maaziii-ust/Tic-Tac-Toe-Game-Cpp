#include<iostream>
using namespace std;

int currentplayer;
char currentmarker;
char board[3][3] = { 
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'}
};


void drawboard(){
    cout << "____" << board[0][0] << "|____" << board[0][1] << "|____" << board[0][2] << endl;
    cout << "____" << board[1][0] << "|____" << board[1][1] << "|____" << board[1][2] << endl;
    cout << "    " << board[2][0] << "|    " << board[2][1] << "|    " << board[2][2] << endl;
}


bool placemarker(int slot){
    int row = (slot-1)/3;
    int col = (slot-1)%3;

    if (board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = currentmarker;
        return true;
    }
    else{
        return false;
    }
}


int winner(){
    // Rows
    for(int i=0; i<3; i++){
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return currentplayer;
        }
    }
    // Columns
    for(int i=0; i<3; i++){
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return currentplayer;
        }
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return currentplayer;
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2]){
        return currentplayer;
    }

    return 0;
}


void swapplayermarker(){
    if (currentplayer == 1){
        currentplayer = 2;
        currentmarker = (currentmarker == 'X') ? 'O' : 'X';
    }
    else{
        currentplayer = 1;
        currentmarker = (currentmarker == 'X') ? 'O' : 'X';
    }
}




int main(){
    
    cout << "Player 1: Choose your marker 'X' or 'O': ";
    char markerP1;
    cin >> markerP1;

    
    while(markerP1 != 'X' && markerP1 != 'O'){
        cout << "Invalid marker! Choose 'X' or 'O': ";
        cin >> markerP1;
    }

    currentplayer = 1;
    currentmarker = markerP1;

    drawboard();
    int playerwon = 0;

    for(int i=0; i<9; i++){
        int slot;
        cout << "\nPlayer " << currentplayer << "'s turn. Enter Slot(1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9){
            cout << "Invalid slot! Enter again.\n";
            i--;
            continue;
        }

        if (!placemarker(slot)){
            cout << "Slot already occupied! Enter again.\n";
            i--;
            continue;
        }

        drawboard();
        playerwon = winner();

        if (playerwon != 0){
            cout << "\nPlayer " << playerwon << " wins!\n";
            break;
        }

        swapplayermarker();
    }

    if (playerwon == 0){
        cout << "\nIt's a tie!\n";
    }
    
    return 0;
}
