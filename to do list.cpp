#include <iostream>
#include <vector>

struct operation {
    std::string description;
};

class TodoList {
private:
    std::vector<operation> operations;

public:
    void addoperation(const std::string& description) {
        operation newoperation;
        newoperation.description = description;
        operations.push_back(newoperation);
        std::cout << "operation added successfull!\n";
    }

    void viewoperations() {
        if (operations.empty()) {
            std::cout << "No operation available.\n";
            return;
        }

        std::cout << "Tasks:\n";
        for (size_t W = 0; W < operations.size(); ++W) {
            std::cout << W + 1 << ". " << operations[W].description << "\n";
        }
    }

    void deleteoperation(size_t index) {
        if (index >= 0 && index < operations.size()) {
            operations.erase(operations.begin() + index);
            std::cout << "operation deleted successfully!\n";
        } else {
            std::cout << "Invalid operation index.\n";
        }
    }
};

int main() {
    TodoList todoList;
    int choice;

    do {
        std::cout << "\nTodo List Manager\n";
        std::cout << "1. Add operation\n";
        std::cout << "2. display operation\n";
        std::cout << "3. Delete operation\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore(); 
                std::getline(std::cin, description);
                todoList.addoperation(description);
                break;
            }
            case 2:
                todoList.viewoperations();
                break;
            case 3: {
                size_t index;
                std::cout << "Enter task index to delete: ";
                std::cin >> index;
                todoList.deleteoperation(index - 1);
                break;
            }
            case 4:
                std::cout << "Exiting Todo List Manager.\n";
                break;
            default:
                std::cout << "Invalid choice. try again.\n";
        }
    } while (choice != 4);

    return 0;
}
