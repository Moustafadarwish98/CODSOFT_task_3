#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
     start();
     int turn = 1;
     bool go_to_other_player = true;
     bool won = false;
     bool draw = false;
     bool play_again = false;
     while (no_winner)
     {
          go_to_other_player = players(turn);
          won = check_winner();
          draw = check_draw();
          if (won)
          {
               if (turn % 2 == 0)
               {
                    cout<<endl;
                    cout<<"----->Player two has won."<<endl<<endl;
                    player_two_score++;
               }
               else
               {
                   cout<<endl;
                   cout<<"----->Player one has won."<<endl<<endl;
                   player_one_score++;
               }
               cout<<"--------------->Player one score: "<<player_one_score<<endl;
               cout<<"--------------->Player two score: "<<player_two_score<<endl;
               play_again = check_play_again();
          }
          else if (draw)
          {
                   cout<<endl<<endl;
                   cout<<"-------------->Draw"<<endl;
                   play_again = check_play_again();

          }
          if (play_again)
                   {
                        turn = 1;
                        printing("-",30);
                        cout<<"New round.";
                        printing("-",30);
                        cout<<endl;
                        play_again = false;
                        continue;
                   }
          if (go_to_other_player)
          {turn++;}
     }}






