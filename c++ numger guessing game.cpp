/**
 * Number Guessing Game */
#include <iostream>
#include <cstdlib>  
#include <ctime>   

int main() {
   
    std::cout << "\n=== NUMBER GUESSING GAME ===\n";
    std::cout << "I'm thinking of a number between 1 and 100.\n";
    std::cout << "Can you guess what it is?\n\n";

    
    std::srand(static_cast<unsigned>(std::time(NULL))); 
    
    
    const int secret_number = (std::rand() % 100) + 1;
    int user_guess = 0;
    int attempts = 0;
    
    
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> user_guess;
        attempts++;
        
        
        if (std::cin.fail() || user_guess < 1 || user_guess > 100) {
            std::cin.clear();  
            std::cin.ignore(1000, '\n');  
            std::cout << "Please enter a valid number between 1 and 100.\n";
            continue;
        }
        
        
        if (user_guess == secret_number) {
            break;  
        } else if (user_guess < secret_number) {
            std::cout << "Too low! Try a higher number.\n";
        } else {
            std::cout << "Too high! Try a lower number.\n";
        }
    }
    
    
    std::cout << "\nCongratulations! You guessed the number "
              << secret_number << " in " << attempts << " attempts.\n\n";
    
    return 0;
} 

