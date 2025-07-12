#include <iostream>
#include <limits>  

/*
 * Simple Calculator Program
 */
void display_menu() {
    std::cout << "\n=== SIMPLE CALCULATOR ===\n";
    std::cout << "Operations available:\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";
    std::cout << "5. Exit\n";
    std::cout << "=========================\n";
}


double get_number(const std::string& prompt) {
    double num;
    while (true) {
        std::cout << prompt;
        std::cin >> num;
        
        if (std::cin.fail()) {
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            std::cout << "Invalid input. Please enter a number.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            return num;
        }
    }
}

int main() {
    while (true) {
        display_menu();
        
        
        int choice;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;
        
        
        if (choice < 1 || choice > 5) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please select 1-5.\n";
            continue;
        }
        
        
        if (choice == 5) {
            std::cout << "Exiting calculator. Goodbye!\n";
            break;
        }
        
        
        double num1 = get_number("Enter first number: ");
        double num2 = get_number("Enter second number: ");
        
        
        double result;
        std::string operation_symbol;
        bool valid_operation = true;
        
        switch (choice) {
            case 1:  
                result = num1 + num2;
                operation_symbol = "+";
                break;
            case 2:  
                result = num1 - num2;
                operation_symbol = "-";
                break;
            case 3: 
                result = num1 * num2;
                operation_symbol = "*";
                break;
            case 4:  
                if (num2 == 0) {
                    std::cout << "Error: Division by zero is not allowed.\n";
                    valid_operation = false;
                } else {
                    result = num1 / num2;
                    operation_symbol = "/";
                }
                break;
            default:
                valid_operation = false;
                break;
        }
        
        
        if (valid_operation) {
            std::cout << "\nResult: " << num1 << " " << operation_symbol << " " 
                      << num2 << " = " << result << "\n";
        }
    }
    
    return 0;
}

