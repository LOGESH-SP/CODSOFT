#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

/**
 To-Do List Manager
 */

struct Task {
    std::string description;
    bool completed;
};
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void display_menu() {
    std::cout << "\n=== TO-DO LIST MANAGER ===\n";
    std::cout << "1. Add New Task\n";
    std::cout << "2. View All Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Delete Task\n";
    std::cout << "5. Exit\n";
    std::cout << "=========================\n";
    std::cout << "Enter your choice (1-5): ";
}
void add_task(std::vector<Task>& tasks) {
    Task new_task;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "\nEnter task description: ";
    std::getline(std::cin, new_task.description);
    new_task.completed = false;
    
    tasks.push_back(new_task);
    std::cout << "Task added successfully!\n";
}
void view_tasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "\nYour to-do list is empty.\n";
        return;
    }
    
    std::cout << "\n=== YOUR TASKS ===\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        std::cout << "[" << (tasks[i].completed ? "X" : " ") << "] ";
        std::cout << tasks[i].description << "\n";
    }
}
void mark_completed(std::vector<Task>& tasks) {
    view_tasks(tasks);
    if (tasks.empty()) return;
    
    int task_num;
    std::cout << "\nEnter task number to mark as completed: ";
    std::cin >> task_num;
    
    if (task_num < 1 || task_num > static_cast<int>(tasks.size())) {
        std::cout << "Invalid task number!\n";
    } else {
        tasks[task_num - 1].completed = true;
        std::cout << "Task marked as completed!\n";
    }
}
void delete_task(std::vector<Task>& tasks) {
    view_tasks(tasks);
    if (tasks.empty()) return;
    
    int task_num;
    std::cout << "\nEnter task number to delete: ";
    std::cin >> task_num;
    
    if (task_num < 1 || task_num > static_cast<int>(tasks.size())) {
        std::cout << "Invalid task number!\n";
    } else {
        tasks.erase(tasks.begin() + (task_num - 1));
        std::cout << "Task deleted successfully!\n";
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;
    
    clear_screen();
    std::cout << "Welcome to your To-Do List Manager!\n";
    
    do {
        display_menu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                clear_screen();
                add_task(tasks);
                break;
            case 2:
                clear_screen();
                view_tasks(tasks);
                break;
            case 3:
                clear_screen();
                mark_completed(tasks);
                break;
            case 4:
                clear_screen();
                delete_task(tasks);
                break;
            case 5:
                std::cout << "\nExiting To-Do List Manager. Goodbye!\n";
                break;
            default:
                std::cout << "\nInvalid choice. Please try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (choice != 5);
    
    return 0;
}

