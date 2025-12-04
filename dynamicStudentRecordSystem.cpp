#include <iostream>
using namespace std;

class Student{
    private:
    string name;
    int age;
    double marks;
    
    public:
    void input();
    void display();
};

void Student::input(){
    cout<< "Enter Student Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Age of Student: ";
    cin >> age;

    cout << "Enter MARKS of Student: ";
    cin >> marks;
}

void Student::display(){
    cout<< "NAME : " << name << endl;

    cout << "AGE : " << age << endl;

    cout << "MARKS : " << marks << endl;

    cout << "-----------------------------------\n";
}

class StudentManager{
    private:
    Student* students;
    int totalStudents;

    public:
    ~StudentManager();
    StudentManager();
    void takeInput();
    void displayALL();

};

StudentManager::StudentManager(){
    students = nullptr;
    totalStudents = 0;
}

void StudentManager::takeInput(){
    cout <<"--------------------------------\n";
    cout << "How many Students: ";
    cin >> totalStudents;

    students = new Student[totalStudents];

    for(int i= 0; i < totalStudents; i++){
        cout << "Enter Details of Student: "<< i + 1 <<":\n";
        students[i].input();
        cout << "----------------------------------------\n";
    }
}

void StudentManager::displayALL(){
    for(int i = 0; i < totalStudents; i++){
        cout << "\nStudent " << i + 1 << ":\n";
        students[i].display();
    }
}

StudentManager::~StudentManager(){
    delete[] students;
}

int main(){
    StudentManager manager;
    manager.takeInput();
    manager.displayALL();    
}