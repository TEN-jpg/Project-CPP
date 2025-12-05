#include <iostream>
using namespace std;


class ToDoList{
    private:
    string* tasks;
    int taskCount;

    public:
    ToDoList();
    void addTask();
    void viewTasks();
    void removeTask();
    void run();
    ~ToDoList();
};
ToDoList::ToDoList(){
    tasks = nullptr;
    taskCount = 0;
}

void ToDoList::addTask(){
    string newTask;

    cout<< "Enter a Task: ";
    cin.ignore();
    getline(cin, newTask);

    string* newArr = new string[taskCount + 1];

    for(int i = 0; i < taskCount; i++){
        *(newArr + i) = *(tasks + i);
    }

    *(newArr + taskCount) = newTask;

    delete[]tasks;

    tasks = newArr;
    taskCount++;

    cout << "Task added Successfully!\n";
}

void ToDoList::viewTasks(){
    if (taskCount == 0){
        cout << "No Task Found!\n";
        return;
    }

    for(int i = 0; i < taskCount; i++){
        cout << i + 1 <<"."<< *(tasks + i) << endl;
    }
}

void ToDoList::removeTask(){

    if (taskCount == 0){
        cout << "No Tasks Found!\n";
        return;
    }

    int removeTask;
    cout << "Enter task number to remove: ";
    cin >> removeTask;

    while (removeTask < 1 || removeTask > taskCount){
        cout << "Invalid number! Enter again: ";
        cin >> removeTask;
    }

    removeTask--; // converts to zero-based Indexing
    
    string* newArr = new string[taskCount - 1];
    
    int j = 0;
    for(int i=0; i < taskCount; i++){
        if(i == removeTask) continue;
        *(newArr + j) = *(tasks + i);
        j++;
    }

    delete[]tasks;

    tasks = newArr;
    taskCount--;

    cout << "Task removed Successfully!\n";   
}

void ToDoList::run(){
    
    int choice;

    do{
        cout << "\n-----TO-DO List-----\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Remove Task\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice){
            case 1:
              addTask();
              break;

            case 2:
              viewTasks();
              break;

            case 3:
              removeTask();
              break;

            case 4:
              cout << "Exiting Program...\n";
              break;

            default:
              cout << "Invalid choice! Try again.\n";
        }
    }while(choice != 4);
}

ToDoList::~ToDoList() {
    delete[] tasks;
    cout << "\nMemory cleaned successfully!\n";
}

int main() {
    ToDoList todo;
    todo.run();
    return 0;
}

