#include <iostream>
using namespace std;

class Contact{
private:
    string name;
    string phone;
    string email;
    
public:
    void input();
    void display();
    void edit();
};

void Contact::input(){
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Contact No: ";
    cin >> phone;

    cout << "Enter Email Id: ";
    cin >> email;
}

void Contact::display(){
    cout << "NAME: " << name << endl;

    cout << "PHONE NO. " << phone << endl;

    cout << "EMAIL ID: " << email << endl;
}

class ContactManager{
private:
    Contact* contacts;
    int contactCount;
public:
    ContactManager();
    void addContact();
    void viewContact();
    void removeContact();
    void editContact();
    void run();
    ~ContactManager();
};

ContactManager::ContactManager(){
    contacts = nullptr;
    contactCount = 0;
}

void ContactManager::addContact(){
    Contact temp;
    temp.input();
    
    Contact* newArr = new Contact[contactCount + 1];

    for(int i = 0; i < contactCount; i++){
        *(newArr + i) = *(contacts + i);
    }

    *(newArr + contactCount) = temp;

    delete[] contacts;

    contacts = newArr;
    contactCount++;

    cout << "Contact Added Successfully" << endl;

}

void ContactManager::viewContact(){
    if(contactCount == 0){
        cout << "No Contact Available" << endl;
        return;
    }

    for(int i = 0; i < contactCount; i++){
        cout << "\nContact " << i + 1 << ":\n";
        (contacts + i)->display();  // (ptr->method()) or not a cleaner version this (*(contacts + i)).display();
    }
}

void ContactManager::removeContact(){
    if(contactCount == 0){
        cout << "No Contact Available" << endl;
        return;
    }

    int removeContact;
    cout << "Enter Contact Number to Remove: ";
    cin >> removeContact;

    while(removeContact < 1 || removeContact > contactCount){
        cout << "Invalid number! Enter again: ";
        cin >> removeContact;
    }

    removeContact--;

    Contact* newArr = new Contact[contactCount - 1];
    
    int j = 0;
    for(int i = 0; i < contactCount; i++){
        if(i == removeContact) continue;
        *(newArr + j) = *(contacts + i);
        j++;
    }

    delete[] contacts;
    
    contacts = newArr;
    contactCount--;

    cout << "Contact Removed Successfully" << endl;

}

void ContactManager::editContact(){
    if(contactCount == 0){
        cout << "No Contact Available" << endl;
        return;
    }
    
    int editContact;
    cout << "Enter Contact Number to Edit: ";
    cin >> editContact;

    while(editContact < 1 || editContact > contactCount){
        cout << "Invalid number! Enter Again: ";
        cin >> editContact;
    }

    editContact--;

    (contacts + editContact)->input(); // Updates the Contact, Short-hand for (*(contacts + editContact)).input()

    cout << "Contact Updated Successfully!" << endl;
}

void ContactManager::run(){
    int choice;
    do{
        cout << "----Contacts Manager----" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View All Contacts" << endl;
        cout << "3. Remove Contact" << endl;
        cout << "4. Edit Contact" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
            addContact();
            break;

            case 2:
            viewContact();
            break;

            case 3:
            removeContact();
            break;

            case 4:
            editContact();
            break;

            case 5:
            cout << "Exiting Program..." << endl;
            break;

            default:
            cout << "Invalid Choice" << endl;
        }
    }while(choice != 5);
    
}

ContactManager::~ContactManager(){
    delete[] contacts;
}

int main(){
    ContactManager obj;
    obj.run();
    return 0;
}