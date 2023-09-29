#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to add a task to the to-do list
void addTask(vector<string>& todoList, const string& task) {
    todoList.push_back(task);
    cout << "Task added: " << task << endl;
}

// Function to remove a task from the to-do list
void removeTask(vector<string>& todoList, int index) {
    if (index >= 0 && index < todoList.size()) {
        cout << "Task removed: " << todoList[index] << endl;
        todoList.erase(todoList.begin() + index);
    } else {
        cout << "Invalid index. Task not removed." << endl;
    }
}

// Function to display the to-do list
void displayTasks(const vector<string>& todoList) {
    if (todoList.empty()) {
        cout << "The to-do list is empty." << endl;
    } else {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < todoList.size(); ++i) {
            cout << i << ". " << todoList[i] << endl;
        }
    }
}

int main() {
    vector<string> todoList;
    int choice;

    cout << "Welcome to the To-Do List Manager!" << endl;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string task;
                    cout << "Enter the task to add: ";
                    cin.ignore();  // Clear newline from previous input
                    getline(cin, task);
                    addTask(todoList, task);
                }
                break;
            case 2:
                {
                    int index;
                    cout << "Enter the index of the task to remove: ";
                    cin >> index;
                    removeTask(todoList, index);
                }
                break;
            case 3:
                displayTasks(todoList);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

