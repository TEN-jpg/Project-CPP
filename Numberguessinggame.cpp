#include <iostream>
#include <ctime>

int main()
{

    int Number;
    int guess;
    int tries = 0;
    
    srand(time(NULL));
    Number = (rand() % 100) + 1;

    std::cout << "----------NUMBER GUESSING GAME------------\n";
    do{
       std::cout << "Enter a guess (1-100): ";
       std::cin >> guess;
       tries++;

       if(guess < Number){
          std::cout << "Too Low!\n";
        }
       else if(guess > Number){
          std::cout << "Too High!\n";
        }
       else{
          std::cout << "CORRECT! You guessed the number in " << tries << " " << "tries\n";
        }

    }while (guess != Number);

    std::cout << "----------------------------------------------";


     return 0;

}