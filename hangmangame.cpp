#include <iostream>
#include <ctime>
using namespace std;

class Hangman
{
    private:
    string secretWord;
    string hiddenWord;
    int lives;
    string wrongletters;
    char playerGuess;
    
    public:
    Hangman();
    void display();
    void drawHangingMan();
    void getGuess();
    void updateGame();
    bool isWin();
    bool isLoss();
    
};

Hangman::Hangman(){
    secretWord = "computer";
    hiddenWord = "";
    for(int i = 0 ; i < secretWord.length() ; i++)
    {   
        hiddenWord += "_";
    }
    lives = 6;
    wrongletters = "";    
}

void Hangman::display(){
    cout << hiddenWord << endl;
    cout << "Lives: " << lives << endl;
    if(wrongletters != ""){
        cout << "Wrong letters: " << wrongletters << endl;
    }
}

void Hangman::drawHangingMan(){
    switch(lives){

        case 6:
        cout << " _____" << endl;
        cout << "|     |"<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        break;

        case 5:
        cout << " _____" << endl;
        cout << "|     |"<< endl;
        cout << "|     O"<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        break;

        case 4:
        cout << " _____" << endl;
        cout << "|     |"<< endl;
        cout << "|     O"<< endl;
        cout << "|    / "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        break;

        case 3:
        cout << " _____" << endl;
        cout << "|     |"<< endl;
        cout << "|     O"<< endl;
        cout << "|    /| "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        break;

        case 2:
        cout << " _____" << endl;
        cout << "|     |"<< endl;
        cout << "|     O"<< endl;
        cout << "|    /|\\"<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        break;

        case 1:
        cout << " _____" << endl;
        cout << "|     |"<< endl;
        cout << "|     O"<< endl;
        cout << "|    /|\\"<< endl;
        cout << "|    / "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        break;

        case 0:
        cout << " _____" << endl;
        cout << "|     |"<< endl;
        cout << "|     O"<< endl;
        cout << "|    /|\\"<< endl;
        cout << "|    / \\"<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        break;
    }
}

void Hangman::getGuess(){
    cout << "Enter a letter: ";
    cin >> playerGuess;

    playerGuess = tolower(playerGuess);

    while(!isalpha(playerGuess)){
        cout << "===================================\n";
        cout << "Invalid input! Enter only letters: ";
        cin >> playerGuess;
        playerGuess = tolower(playerGuess);
    }

    if(hiddenWord.find(playerGuess) != string::npos || wrongletters.find(playerGuess) != string::npos){
        cout << "==================================\n";
        cout << "You already guessed this letter!\n";
        getGuess();
        return;
    }
}

void Hangman::updateGame(){
    bool correct = false;

    for(int i = 0; i < secretWord.size(); i++){
        if(secretWord[i] == playerGuess){
            hiddenWord[i] = playerGuess;
            correct = true;
        }
    }

    if(!correct){
        lives--;
        wrongletters += playerGuess;
        cout << "===========================================\n";
        cout << "Wrong Guess! Lives left: " << lives << endl;
        drawHangingMan();
    }
}

bool Hangman::isWin(){
    return hiddenWord == secretWord;
}

bool Hangman::isLoss(){
    return lives == 0;
}

int main(){
    Hangman game;

    while(!game.isWin() && !game.isLoss()){
        game.display();
        game.getGuess();
        game.updateGame();
    }

    if(game.isWin()){
        cout << "====================\n";
        cout << "Congrats YOU WON!\n";
    }
    if(game.isLoss()){
        cout << "====================\n";
        cout << "YOU LOSS!\n";
        cout << "You ran out of lives.\n";
    }
    
    return 0;
}
