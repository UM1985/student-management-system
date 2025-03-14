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
        T marks;
    };
    
    vector<Student> students;

public:
    // Add a student to the list
    void addStudent(int id, string name, T marks) {
        students.push_back({id, name, marks});
        cout << "Student added successfully!\n";
    }
    
    // Display all students
    void displayStudents() {
        if (students.empty()) {
            cout << "No students found!\n";
            return;
        }
        cout << "\nList of Students:" << endl;
        for (const auto& student : students) {
            cout << "ID: " << student.id << ", Name: " << student.name << ", Marks: " << student.marks << endl;
        }
    }
    
    // Remove student by ID
    void removeStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student removed successfully!\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found!\n";
    }
    
    // Search student by ID
    void searchStudent(int id) {
        for (const auto& student : students) {
            if (student.id == id) {
                cout << "Student Found - ID: " << student.id << ", Name: " << student.name << ", Marks: " << student.marks << endl;
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
    double marks;
    
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
                cout << "Enter Marks: ";
                cin >> marks;
                sm.addStudent(id, name, marks);
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
