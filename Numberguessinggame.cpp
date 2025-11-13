#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;


int main(){
    cout<<"\033[35m"<< "======================================= NUMBER GUESSING GAME =======================================\n"<<"\033[0m";
    srand(time(NULL));
    int number_to_guess = (rand() % 100) + 1;
    int user_guess;
    int attempt = 0;
    string restart;
    
    do{
        cout<< "\033[33m"<< "Generating a number"<<"\033[0m";
        Sleep(500);
        cout<<".";
        Sleep(500);
        cout<<".";
        Sleep(500);
        cout<<".\n";       
        int number_to_guess = (rand() % 100) + 1;
        attempt = 0;
        user_guess = 0;

    
    do{
        cout<< "Enter your guess(1-100): ";
        cin>> user_guess;
        if(user_guess <= 0 || user_guess > 100){
            cout<<"\033[31m"<<"Invalid Input! Enter a number between (1-100)\n"<<"\033[0m";
        }
        else{
            attempt++;
        if(user_guess > number_to_guess){
            cout<< "Too High!\n";
        }
        else if(user_guess < number_to_guess){
            cout<< "Too Low!\n";
        }
        }
        
        
    }while(user_guess != number_to_guess);
    
    cout<<"\033[32m"<<"Great! You guessd the number "<< "in "<< attempt<< " tries\n"<<"\033[0m";
    cout<<"------------------------------------------------------------\n";
    cout<<"\033[33m"<<"Do you wnat to play again(Y/N): "<<"\033[0m";
    cin>> restart;
    }while(restart == "y" || restart == "Y");
    cout<<"\033[35m"<<"======================================= Thanks for playing! Bye! ======================================="<<"\033[0m";

    return 0;
}