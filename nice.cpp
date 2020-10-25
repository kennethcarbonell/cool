//Kenneth Carbonell cpsc 120 - 01
#include <iostream>
#include <ctime>
using namespace std;

const string ROCK = "rock";
const string PAPER = "paper";
const string SCISSORS = "scissors";
const string PLAYER = "player";
const string COMPUTER = "computer";
const string TIE = "tie";
const string EASY = "easy";
const string MEDIUM = "medium";
const string IMPOSSIBLE = "impossible";

string GetPlayerChoice()
{
  string player_choice;
  cout << "Enter your choice: ";
  cin >> player_choice;

  if (player_choice != ROCK && player_choice != PAPER && player_choice != SCISSORS)
  {
    cout << "Not a valid choice! You are assigned rock for not following directions." << endl;
    player_choice = ROCK;
  }

  return player_choice;
}

string GetComputerChoice()
{
  srand(time(0));
  int random_choice = rand() % 3;
  string computer_choice;

  if (random_choice == 0)
  {
    computer_choice = ROCK;
  }
  else if (random_choice == 1)
  {
    computer_choice = PAPER;
  }
  else
  {
    computer_choice = SCISSORS;
  }

  return computer_choice;
}

string DetermineWinner(string player_choice, string computer_choice, string difficulty)
{
  if (difficulty == EASY)
  {
    if (player_choice == ROCK)
    {
      computer_choice = SCISSORS;
    }
    else if (player_choice == PAPER)
    {
      computer_choice = ROCK;
    }
    else
    {
      computer_choice = PAPER;
    }
  }

  if (difficulty == IMPOSSIBLE)
  {
    if (player_choice == ROCK)
    {
      computer_choice = PAPER;
    }
    else if (player_choice == PAPER)
    {
      computer_choice = SCISSORS;
    }
    else
    {
      computer_choice = ROCK;
    }
  }

  if (player_choice == computer_choice)
  {
    cout << "You and the computer chose the same thing!" << endl;
    cout << "It's a tie!" << endl;
    return TIE;
  }

  if (player_choice == ROCK)
  {
    cout << "You chose rock" << endl;

    if (computer_choice == PAPER)
    {
      cout << "The computer chose: paper" << endl;
      cout << "Paper beats rock! You lose!" << endl;

      return COMPUTER;
    }
    else
    {
      cout << "The computer chose: scissors" << endl;
      cout << "Rock beats scissors! You win!" << endl;

      return PLAYER;
    }
  }
  else if (player_choice == PAPER)
  {
    cout << "You chose paper" << endl;

    if (computer_choice == ROCK)
    {
      cout << "The computer chose: rock" << endl;
      cout << "Paper beats rock! You win!" << endl;

      return PLAYER;
    }
    else
    {
      cout << "The computer chose: scissors" << endl;
      cout << "Scisors beats paper! You lose!" << endl;

      return COMPUTER;
    }
  }
  else
  {
    cout << "You chose scissors" << endl;

    if (computer_choice == ROCK)
    {
      cout << "The computer chose: rock" << endl;
      cout << "Rock beats scissors! You lose!" << endl;

      return COMPUTER;
    }
    else
    {
      cout << "The computer chose: paper" << endl;
      cout << "Scisors beats paper! You win!" << endl;

      return PLAYER;
    }
  }
}

char PlayAgain()
{
  char play_again_choice;
  cout << endl;
  cout << "Play again? Type (y/n)" << endl;
  cin >> play_again_choice;

  if (play_again_choice == 'n')
  {
    cout << endl;
    cout << "Thanks for playing!" << endl;
    cout << endl;
    return 0;
  }
  else if (play_again_choice != 'y' && play_again_choice != 'n')
  {
    cout << "Invalid response, the game will exit." << endl;
    return 0;
  }

  return play_again_choice;
}

void KeepScore(string determine_winner, int& player_win, int& computer_win, int& tie_win)
{
  if (determine_winner == PLAYER)
  {
    player_win++;
  }
  else if (determine_winner == COMPUTER)
  {
    computer_win++;
  }
  else
  {
    tie_win++;
  }
}

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    cout << "Enter a difficulty either easy, medium, or impossible." << endl;
    return 0;
  }

  string difficulty = argv[1];
  int Win = 0;
  int Loss = 0;
  int Tie = 0;

  do
  {
    string player_choice = GetPlayerChoice();
    string computer_choice = GetComputerChoice();
    string determine_winner = DetermineWinner(player_choice, computer_choice, difficulty);
    KeepScore(determine_winner, Win, Loss, Tie);

    cout << Win << "/" << Loss << "/" << Tie << endl;
  }
  while (PlayAgain() == 'y');

  cout << "The final score is " << Win << " wins, " << Loss << " losses, and " << Tie << " ties." << endl;
}
