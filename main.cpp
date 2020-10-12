#include <iostream>
#include <string>
#include <sstream>

using namespace std;

char game[100];
char player1 = 'x', player2 = 'o';

//resets gamespace
void reset(void)
{
  int i;
  for (i = 0; i < 9; i++)
  {
    game[i] = i + 49;
  }
}

//draws the current tic tac toe game with borders & markers
void draw()
{
  int i, n = 0;
  cout << "-----------\n";
  for (i = 0; i < 7; i = i + 3) 
  {
    cout << " " << game[i] << " | " << game[i+1] << " | " << game[i+2] << " \n";
    cout << "-----------\n";
    n++;
  }
}

bool valid(int move) 
//checks if indicated space is full 
{
  if (game[move] == player1 || game[move] == player2) 
  {
    return false;
  }
  return true;
}


bool win(char player)
//checks if current player has won
{
  int i;
  for (i = 0; i < 3; i++) 
  {
    if (game[i] == player && game[i+3] == player && game[i+6] == player) 
    {
      return true;
      //vertical win
    }
  }
    for (i = 0; i < 3; i = i+3) 
    {
      if (game[i] == player && game[i+1] == player && game[i+2] == player) 
      {
        return true;
        //horizontal win
      }
  }
  if(game[0] == player && game[4] == player && game[8] == player)
  {
    return true;
}
  if(game[2] == player && game[4] == player && game[6] == player)
  {
    return true;
    //diagonal top-right to bottom-left win
}
    return false;
}

bool full()
//checks if all spots are occupied 
{
  int c = 0, i;
  for (i = 0; i < 9; i++) 
  {
    if (valid(i) == true)
    {
      c ++;
    }
  }
  if (c == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int over(char player)
//checks if game is over. returns 0 if game isn't over, and 1 if current player wins and -1 if draw
{
  if (full())
  {
    return -1;
  }
  if (win(player))
   {
    return 1;
  }
  else
  {
    return 0;
  }
}

void playmove(char player, int move)
//edits array game to reflect player input
{
    game[move] = player;
}

int get()
//gets next move from player & checks for invalid input
{
  int c = 0, move, scan;
  string input = " ";

  while (c == 0) 
  {
    cout << "please input your next move: ";
    getline(cin, input);
    stringstream mystream(input);

    if (mystream >> move && move>0 && move<10) 
    {
      move--;
      if (valid(move)==true)
      {
        c++;
      }
      else
      {
        cout << "invalid move. please try again\n\n";
      }
    }
    else
    {
      cout <<"invalid move. please try again\n\n";
    }
    cin.clear();
  }
  return move;
}

void newgame(string player1_name, string player2_name)
//starts a new game & resets gamespace
{
  char current_player;
  string current_player_name;
  int move;
  reset();
  current_player = player2;
  while (over(current_player) == 0)
  {
    if (current_player == player2) 
    {
      current_player = player1;
      current_player_name = player1_name;
    }
    else
    {
      current_player = player2;
      current_player_name = player2_name;
    }
    cout << "it's " << current_player_name << "'s turn.\n";
    draw();
    move = get();
    playmove(current_player, move);
  }
  if (over(current_player) == -1) 
  {
    draw();
    cout << "it's a tie!\n";
  }
  if (over(current_player) == 1) 
  {
    draw();
    cout << current_player_name << " wins!\n";
  }
}
bool play_again()
//asks player if they'd like to play again & error-checks input
{
  int c = 0;
  string input;
  char response;
  while (true) 
  {
    cout << "play again? (y/n)\n";
    getline(cin, input);
    if (input.length() == 1 )
    {
      response = input[0];
      if (response == 'y') 
      {
      return true;
    }
    if (response == 'n') 
    {
      break;
    }
    }
    printf("please enter either 'y' or 'n'\n");
    }
    return false;
  }

int main(void)
//asks for players' names & starts new game

{
  string player1_name, player2_name;

  cout << "player 1, please enter your name (you'll play as 'x'): ";
  getline(cin, player1_name);
  cout << "player 2, please enter your name (you'll play as 'o'): ";
  getline(cin, player2_name);
  do 
  {
newgame(player1_name, player2_name);
  } while(play_again());

return EXIT_SUCCESS;
}
