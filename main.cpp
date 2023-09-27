#include <iostream>

using namespace std;

// Define the size of the board
const int SIZE = 3;

// Define the symbols for the players and the empty cell
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';

// Declare a global variable to store the board
char board[SIZE][SIZE];

// Initialize the board with empty cells
void init_board() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = EMPTY;
    }
  }
}

// Display the board on the console
void display_board() {
  cout << "\n";
  cout << "  1 2 3\n";
  for (int i = 0; i < SIZE; i++) {
    cout << char(i + 'A') << " ";
    for (int j = 0; j < SIZE; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

// Get the input from the current player and validate it
bool get_input(char player) {
  char row, col;
  int r, c;
  cout << "Player " << player << ", enter your move (row col): ";
  cin >> row >> col;
  r = row - 'A';
  c = col - '1';
  if (r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == EMPTY) {
    board[r][c] = player;
    return true;
  } else {
    cout << "Invalid move. Try again.\n";
    return false;
  }
}

// Check if a player has won by forming a line of their symbol
bool check_win(char player) {
  // Check rows
  for (int i = 0; i < SIZE; i++) {
    bool win = true;
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] != player) {
        win = false;
        break;
      }
    }
    if (win){ return true;}
    else {}
  }


  // Check columns
  for (int i = 0; i < SIZE; i++) {
    bool win = true;
    for (int j = 0; j < SIZE; j++) {
      if (board[j][i] != player) {
        win = false;
        break;
      }
    }
    if (win) return true;
  }

  // Check diagonals
  bool win = true;
  for (int i = 0; i < SIZE; i++) {
    if (board[i][i] != player) {
      win = false;
      break;
    }
  }
  if (win) {return true;}
  else
  {return false;}
 // win = true;
}

int main (){
    char player1[20] ;
    char player2[20] ;

    bool check_o =false;
    bool check_x =false ;
    bool flag = true ;
    cout<<"Enter name O player : ";
    cin>>player1;
    cout<<endl;
    cout<<"Enter name X player : ";
    cin>>player2;
    cout<<endl;
//    Sleep(500);
    cout<<"READYY "<<player1<<" VS "<<player2<<endl;
  //  Sleep(2000);
  //   std ::cout<<"3"<<endl;
  //  Sleep(1000);
  //   std ::cout<<"2"<<endl;
  //  Sleep(1000);
   //  std ::cout<<"1"<<endl;
   // Sleep(1000);

init_board();
display_board();

bool check_ip_o =get_input(O);
if(check_ip_o){
   display_board();
   }
   else {get_input(O);
   display_board();}

for(int i=0 ; i< 4 ;i++)
{
   bool check_ip_x = get_input(X);
   if(check_ip_x){
   display_board();
   check_x = check_win(X);
   }
   else{
    get_input(X);
    display_board();
   }

if(check_x){
    cout<<"Congratulations !! "<<player2<<" win"<<endl;
    flag = false ;
    break;
}

   check_ip_o = get_input(O);
   if(check_ip_o){
   display_board();
   check_o = check_win(O);
   }
   else {get_input(O);
   display_board();}

 if (check_o){
    cout<<"Congratulations !! "<<player1<<" win"<<endl;
    flag = false ;
    break;
}
}
if (flag){
    cout<<" Draw "<<endl;
}
else{}

}
