#include <iostream>
using namespace std;

char grid[3][3];
char player_one = 'X';
char player_two = 'O';
int player_one_score = 0;
int player_two_score = 0;
bool no_winner = true;

void display_grid()
{
     cout<<endl;
     for(int i = 0; i<3 ; i++)
     {
          cout<<"\t \t|\t \t|\t";
          cout<<endl;
          for (int j = 0; j<3; j++)
          {

               cout<<"\t";
               cout<<grid[i][j];
               cout<<"\t";
               if (j<2)
               {
                    cout<<"|";
               }
          }
          if (i<2){
          cout<<endl;
          cout<<"   _____________|_______________|________________";
          cout<<endl;
          }
          else
          {
               cout<<endl;
               cout<<"\t \t|\t \t|\t";
          }
          }

     }

void printing (string s, int n)
{
     for( int i =0; i<n; i++)
     {
          cout<<s;
     }
}

void start()
{
     char k = '1';
     for(int i = 0; i<3 ; i++)
     {
          for (int j = 0; j<3; j++)
          {
               grid[i][j]=k++;

          }
     }
     printing("-",30);
     cout<<"Welcome to Tic-Tac-Toe game.";
     printing("-",30);
     cout<<endl<<endl;
     display_grid();
}

bool check(char c)
{
     if (c =='X' || c=='O')
          {
               cout<<endl;
          cout<<"----->Invalid position. please choose a vacant position."<<endl;
          return false;
          }
     else
     {
          return true;;
     }

}
bool position_selection(char p, char player)
{
     bool valid;
     switch(p){
     case '1': valid = check(grid[0][0]);
     if (valid)
     {
         grid[0][0] = player;
     }
     else
     {
          return false;
     }
     break;
     case '2': valid = check(grid[0][1]);
     if (valid)
     {
         grid[0][1] = player;
     }
     else
     {
          return false;
     }
     break;
     case '3': valid = check(grid[0][2]);
     if (valid)
     {
         grid[0][2] = player;
     }
     else
     {
          return false;
     }
     break;
     case '4': valid = check(grid[1][0]);
     if (valid)
     {
         grid[1][0] = player;
     }
     else
     {
          return false;
     }
     break;
     case '5': valid = check(grid[1][1]);
     if (valid)
     {
         grid[1][1] = player;
     }
     else
     {
          return false;
     }
     break;
     case '6': valid = check(grid[1][2]);
     if (valid)
     {
         grid[1][2] = player;
     }
     else
     {
          return false;
     }
     break;
     case '7': valid = check(grid[2][0]);
     if (valid)
     {
         grid[2][0] = player;
     }
     else
     {
          return false;
     }
     break;
     case '8': valid = check(grid[2][1]);
     if (valid)
     {
         grid[2][1] = player;
     }
     else
     {
          return false;
     }
     break;
     case '9': valid = check(grid[2][2]);
     if (valid)
     {
         grid[2][2] = player;
     }
     else
     {
          return false;
     }
     break;
     default: cout<<"Invalid choice. Please choose a vacant position."; }

}
bool players (int turn)
{
     bool valid;
     char position;
     cout<<endl<<endl;
     if (turn % 2 == 0)
     {
     cout<<"Second Player. Enter your move: ";
     cin>>position;
     valid = position_selection(position, player_two);
     }
     else
     {
     cout<<"First Player. Enter your move: ";
     cin>>position;
     valid = position_selection(position, player_one);
     }
     display_grid();
     return valid;
}
bool check_winner()
{
     if ((grid[0][0] == grid[0][1] && grid[0][0] == grid[0][2]) ||
         (grid[1][0] == grid[1][1] && grid[1][0] == grid[1][2]) ||
         (grid[2][0] == grid[2][1] && grid[2][0] ==  grid[2][2]) ||
         (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) ||
         (grid[0][2] == grid[0][1] && grid[0][2] ==  grid[2][0]) ||
         (grid[0][0] == grid[1][0] && grid[0][0] ==  grid[2][0]) ||
         (grid[0][1] == grid[1][1] && grid[0][1] ==  grid[2][1]) ||
         (grid[0][2] == grid[1][2] && grid[0][2] ==  grid[2][2]))
     {
          return true;
     }
     return false;
}
bool check_draw()
{
     for (int i = 0; i<3; i++)
     {
          for (int j =0; j<3; j++)
          {
               if (grid[i][j] != 'X' )
               {
                    if (grid [i][j] !='O')
                   {
                    return false;}
               }
          }
     }
     return true;
}
bool check_play_again()
{
     int again;
     cout<<endl;
     cout<<"Do you want to play again? (Yes(type 1) / No (type 0))."<<endl;
     cin>> again;
     if (again == 1)
     {
          system("cls");
          start();
          cout<<endl<<endl;
          cout<<"Players switched X and O"<<endl;
          char temp;
          temp = player_one;
          player_one= player_two;
          player_two=temp;
          return true;
     }
     else
     {
          system("cls");
          if (player_one_score > player_two_score)
          {
               cout<<"------------>Player one won!."<<endl;
          }
          else
          {
                cout<<"------------>Player Two won!."<<endl;
          }
          cout<<endl;
          printing("-",30);
          cout<<">Good Bye<";
          printing("-",30);
          cout<<endl;
          no_winner = false;
          return false;
     }
}

