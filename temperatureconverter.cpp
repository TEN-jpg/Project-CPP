#include <iostream>

int main()
{
   double temp;
   char unit;

   std::cout << "----------TEMPERATURE CONVERTER------------\n";

   std::cout << "Fahrenheit = F\n";
   std::cout << "Celsius = C\n";
   std::cout << "Choose a conversion (F or C): ";
   std::cin >> unit;

   if(unit == 'F' || unit == 'f' ){
        std::cout << "Enter the temperature in Celsius: ";
        std::cin >> temp;

        temp = (1.8 * temp) + 32.0;
        std::cout << "Temperature is: " << temp << "F\n";
    }
    else if (unit == 'C' || unit == 'c'){
        std::cout << "Enter the temperature in Fahrenheit: ";
        std::cin >> temp;

        temp = (temp - 32) / 1.8;
        std::cout << "Temperature is: " << temp << "C\n";
    }
    else {
        std::cout << "Please enter Only C or F\n";
    }


    std::cout << "--------------------------------------------";

    return 0;

}