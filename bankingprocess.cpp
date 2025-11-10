#include <iostream>
#include <iomanip>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main()
{
   double balance = 0;
   int operation = 0;
   

   do{
    std::cout << "1. Show Balance\n";
    std::cout << "2. Withdraw Money\n";
    std::cout << "3. Deposit Money\n";
    std::cout << "4. Exit\n";
    std::cout << "----------------------\n";
    std::cout << "Enter your Operation: ";
    std::cin >> operation;
    std::cout << "----------------------\n";
    
    std::cin.clear();  //USED TO CLEAR INPUT BUFFER
    fflush(stdin);

    switch (operation){
    case 1:
        showBalance(balance);
        break;
    case 2:
        balance -= withdraw(balance);
        showBalance(balance);
        break;
    case 3:
        balance += deposit();
        showBalance(balance);
        break;
    case 4:
        std::cout << "----------------------\n";
        std::cout << "Thanks for Visting!\n";
        std::cout << "----------------------\n";  
        break;
    default:
        std::cout << "Please enter a valid Operation\n";
        break;
    }
   }while (operation != 4);

   return 0;
    
  
}

void showBalance(double balance){
    std::cout << "Balance = $" << std::setprecision(2) << std::fixed << balance << "\n";
    std::cout << "------------------\n";
}
double deposit(){

    double amount = 0;
    std::cout << "Enter the Deposit Amount: ";
    std::cin >> amount;

    if(amount > 0){
        return amount;
    }
    else{
        std::cout << "Enter a Valid Deposit Amount!!\n";
        return 0;
    }

}
double withdraw(double balance){
    double amount = 0;
    std::cout << "Enter the Withdrawal Amount: ";
    std::cin >> amount;

    if(amount > balance){
        std::cout << "Insufficient Funds!\n";
        return 0;
    }
    else if(amount < 0){
        std::cout << "Enter a Valid Withdrawal Amount!!\n";
        return 0;
    }
    else{
        return amount;
    }
}
