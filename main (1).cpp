/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

********************************************************************************************
#include <iostream>
#include <vector>
#include <iomanip> // For setting precision
using namespace std;

// Define a structure for storing student information
struct Student {
    string name;
    int age;
    float grade;
};

// Global variables
vector<Student> students;
const int MAX_STUDENTS = 5;

// Function to add a student
void addStudent() {
    if (students.size() >= MAX_STUDENTS) {
        cout << "Student limit reached. Cannot add more students.\n\n";
        return;
    }
    
    Student student;
    cout << "Enter student name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, student.name);
    cout << "Enter age: ";
    cin >> student.age;
    
    // Validate grade input (0-100)
    do {
        cout << "Enter grade (0-100): ";
        cin >> student.grade;
        if (student.grade < 0 || student.grade > 100)
            cout << "Invalid grade. Enter a grade between 0 and 100.\n";
    } while (student.grade < 0 || student.grade > 100);
    
    students.push_back(student);
    cout << "Student added successfully!\n\n";
}

// Function to view all students
void viewAllStudents() {
    if (students.empty()) {
        cout << "No students to display.\n\n";
        return;
    }
    
    cout << "All Students:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        cout << i + 1 << ". Name: " << students[i].name 
             << ", Age: " << students[i].age 
             << ", Grade: " << students[i].grade << endl;
    }
    cout << endl;
}

// Function to calculate the average grade
void calculateAverageGrade() {
    if (students.empty()) {
        cout << "No students to calculate the average grade.\n\n";
        return;
    }
    
    float totalGrade = 0;
    for (const auto& student : students) {
        totalGrade += student.grade;
    }
    
    float averageGrade = totalGrade / students.size();
    cout << "Average grade of all students: " << fixed << setprecision(2) << averageGrade << "\n\n";
}

// Main function
int main() {
    int choice;
    
    do {
        cout << "Student Information System:\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Calculate Average Grade\n";
        cout << "4. Exit\n";
        cout << "Choose an option (1-4): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewAllStudents();
                break;
            case 3:
                calculateAverageGrade();
                break;
            case 4:
                cout << "Thank you for using the Student Information System!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n\n";
        }
    } while (choice != 4);
    
    return 0;
}