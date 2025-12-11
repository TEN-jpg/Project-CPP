#include <iostream>
#include <limits>
using namespace std;

class Person{
    private:
    string name;
    int age;
    string gender;

    public:
    virtual void input() = 0;             
    virtual void display() = 0;
    virtual void showRole() = 0;

    protected:
    void inputBasicDetails();
    void displayBasicDetails(); 
};

void Person::inputBasicDetails(){
    cout << "Enter Name: ";
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Gender: ";
    cin >> gender;
}

void Person::displayBasicDetails(){
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
}

class Student : public Person{
    private:
    int roll;
    string grade;
    int subjectCount;

    public:
    void input();
    void display();
    void showRole(){
        cout << "Role: Student" << endl;
    }
};

void Student::input(){
    inputBasicDetails();

    cout << "Enter Roll NO: ";
    cin >> roll;

    cout << "Enter Class: ";
    cin >> grade;

    cout << "Enter No. of Subjects: ";
    cin >> subjectCount;

}

void Student::display(){
    displayBasicDetails();

    cout << "Roll No: " << roll << endl; 
    cout << "Class: " << grade << endl; 
    cout << "Total Subjects: " << subjectCount << endl; 
}

class Teacher : public Person{
    private:
    int id;
    string subject;
    double salary;

    public:
    void input();
    void display();
    void showRole(){
        cout << "Role: Teacher" << endl;
    }
};

void Teacher::input(){
    inputBasicDetails();

    cout << "Enter ID Number: ";
    cin >> id;

    cout << "Subject Taught: ";
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, subject);

    cout << "Salary: ";
    cin >> salary;
}

void Teacher::display(){
    displayBasicDetails();

    cout << "ID: " << id << endl;
    cout << "Subject: " << subject << endl;
    cout << "Salary: " << "₹" << salary << endl;
}

class Staff : public Person{
    private:
    int emp_id;
    string dep;
    string time;

    public:
    void input();
    void display();
    void showRole(){
        cout << "Role: Staff" << endl;
    }
};

void Staff::input(){
    inputBasicDetails();

    cout << "Enter ID Number: ";
    cin >> emp_id;

    cout << "Enter Department: ";
    cin >> dep;

    cout << "Shift Timing: ";
    cin >> time;
}

void Staff::display(){
    displayBasicDetails();

    cout << "Employee ID: " << emp_id << endl;
    cout << "Department: " << dep << endl;
    cout << "Shift Time: " << time << endl;
}

class SchoolSystem{
    private:
    Person** people;    /*pointer-to-pointer, dynamic array of Person*
                        Base-class pointer can store objects of all derived types
                        It enables polymorphism (showRole(), displayBasicDetails(), etc.)
                        Lets us store a mix of Student, Teacher, Staff in one list*/ 
    int count;

    public:
    SchoolSystem();
    void addStudent();
    void addTeacher();
    void addStaff();
    void viewAll();
    void removePerson();
    void run();
    ~SchoolSystem();
};

SchoolSystem::SchoolSystem(){
    people = nullptr;
    count = 0;
}

void SchoolSystem::addStudent(){
    Person* p = new Student;

    p->input();

    Person** newArr = new Person*[count + 1];

    for(int i=0; i < count; i++){
        *(newArr + i) = *(people + i);
    }

    *(newArr + count) = p;

    delete[]people;

    people = newArr;
    count++;

    cout << "Student Added Successfully!" << endl;
}

void SchoolSystem::addTeacher(){
    Person* p = new Teacher;

    p->input();

    Person** newArr = new Person*[count + 1];

    for(int i=0; i < count; i++){
        *(newArr + i) = *(people + i);
    }

    *(newArr + count) = p;

    delete[]people;

    people = newArr;
    count++;

    cout << "Teacher Added Successfully!" << endl;
}

void SchoolSystem::addStaff(){
    Person* p = new Staff;

    p->input();

    Person** newArr = new Person*[count + 1];

    for(int i=0; i < count; i++){
        *(newArr + i) = *(people + i);
    }

    *(newArr + count) = p;

    delete[]people;

    people = newArr;
    count++;

    cout << "Staff Added Successfully!" << endl;
}

void SchoolSystem::viewAll(){
    if(count == 0){
        cout << "No Record found!" << endl;
        return;
    }

    for(int i = 0; i < count; i++){
        cout << "\nRecord" << i + 1 << ":\n";
        people[i]->showRole();   /*can write like this to (*(people + i)->showRole())
                                  because people is pointer-to-pointer for Person* Array*/
        people[i]->display();
    }
}

void SchoolSystem::removePerson(){
    if(count == 0){
        cout << "No Record Found!" << endl;
        return;
    }

    int remove;
    cout << "Enter Record Number to Remove: ";
    cin >> remove;
    while(remove < 1 || remove > count){
        cout << "Invalid Record Number! Try Again: ";
        cin >> remove;
    }

    remove--;

    delete people[remove];  // Delete the object at that index.Because each entry is a pointer to a dynamically created object(Student,Teacher or Staff)

    Person** newArr = new Person*[count - 1];

    int j = 0;
    for(int i = 0; i < count; i++){
        if(i == remove) continue;
        *(newArr + j) = *(people + i);
        j++;
    }

    people = newArr;
    count--;

    cout << "Record Removed Successfully!" << endl;
}

void SchoolSystem::run(){
    int choice;
    do{
        cout << "\n==== MAIN MENU ====\n";
        cout << "1. Add Student" << endl;
        cout << "2. Add Teacher" << endl;
        cout << "3. Add Staff" << endl;
        cout << "4. View All Records" << endl;
        cout << "5. Remove Record" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            addTeacher();
            break;
        case 3:
            addStaff();
            break;
        case 4:
            viewAll();
            break;
        case 5:
            removePerson();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    }while(choice != 6);
}

SchoolSystem::~SchoolSystem(){
    for(int i=0; i < count; i++){
        delete people[i];   // delete each stored object first
    }
    delete[] people;        // Then delete the array of pointers
}

int main(){
    SchoolSystem obj;
    obj.run();
    return 0;
}