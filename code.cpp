#include <iostream>
#include <vector>
using namespace std;

// Template class for Student Management
template <typename T>
class StudentManagement {
private:
    struct Student {
        int id;
        string name;
    };
    
    vector<Student> students;

public:
    // Add a student to the list
    void addStudent(int id, string name) {
        students.push_back({id, name});
        cout << "Student added successfully!"<<endl;
    }
    
    // Display all students
    void displayStudents() {
        if (students.empty()) {
            cout << "No students found!"<<endl;
            return;
        }
        cout << "\nList of Students:" << endl;
        for (const auto& student : students) {
            cout << "ID: " << student.id << ", Name: " << student.name  << endl;
        }
    }
    
    // Remove student by ID
    void removeStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student removed successfully!"<<endl;
                return;
            }
        }
        cout << "Student with ID " << id << " not found!"<<endl;
    }
    
    // Search student by ID
    void searchStudent(int id) {
        for (const auto& student : students) {
            if (student.id == id) {
                cout << "Student Found - ID: " << student.id << ", Name: " << student.name<< endl;
                return;
            }
        }
        cout << "Student with ID " << id << " not found!\n";
    }
};

int main() {
    StudentManagement<double> sm; 
    int choice, id;
    string name;
    
    while (true) {
        cout << "\nStudent Management System";
        cout << "\n1. Add Student\n2. Display Students\n3. Remove Student by ID\n4. Search Student by ID\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                sm.addStudent(id, name);
                break;
            case 2:
                sm.displayStudents();
                break;
            case 3:
                cout << "Enter Student ID to Remove: ";
                cin >> id;
                sm.removeStudent(id);
                break;
            case 4:
                cout << "Enter Student ID to Search: ";
                cin >> id;
                sm.searchStudent(id);
                break;
            case 5:
                cout << "Exiting program..."<<endl;
                return 0;
            default:
                cout << "Invalid choice, try again!"<<endl;
        }
    }
    return 0;
}
