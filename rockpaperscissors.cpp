#include <iostream>
#include <ctime>
using namespace std;

string userchoice;
string Computerchoice;  
int random_number;
string restart;

int main()
{
    do{
    do{
    cout << "======================ROCK, PAPER & SCISSORS==================\n";
    cout << "Enter r FOR Rock p FOR Paper s FOR Scissor: ";
    cin >> userchoice;
    if (userchoice == "R")
    {
        userchoice = "r";
    }
    else if(userchoice == "P")
    {
        userchoice = "p";
    }
    else if(userchoice == "S")
    {
        userchoice = "s";
    }
    }while(userchoice != "r" && userchoice != "p" && userchoice != "s");

    if(userchoice == "r")
    {
        userchoice = "rock";
    }
    else if(userchoice == "p")
    {
        userchoice = "paper";
    }
    else if(userchoice == "s")
    {
        userchoice = "scissors";
    }


    srand(time(0));
    random_number = rand() % 3 + 1;

    if(random_number == 1)
    {
        Computerchoice = "rock";
    }
    else if(random_number == 2)
    {
        Computerchoice = "paper";
    }
    else
    {
        Computerchoice = "scissors";
    }

    if(userchoice == Computerchoice)
    {
        cout << "DRAW\n";
        cout << "Computer Choiced: "<< Computerchoice << "\n";
        cout << "===========================================\n";
    }
    else if((userchoice == "rock" && Computerchoice == "scissors") || 
            (userchoice == "paper" && Computerchoice == "rock") || 
            (userchoice == "scissors" && Computerchoice == "paper"))
    {
        cout << "You WIN!\n";
        cout << "Computer Choiced: "<< Computerchoice << "\n";
        cout << "===========================================\n";
    }
    else
    {
        cout << "Oh! Computer Win\n";
        cout << "You Loss\n";
        cout << "Computer Choiced: "<< Computerchoice << "\n";
        cout << "===========================================\n";
    }
    cout << "Do you want to play again(y/n): ";
    cin >> restart;
 
    }while(restart == "y" || restart == "Y");


    return 0;


}