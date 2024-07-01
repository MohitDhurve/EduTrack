#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class Student
{
public:
    std::string name;
    int age;
    std::string grade;
    std::string studentClass;

    void input()
    {
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter age: ";
        std::cin >> age;
        while (age <= 0)
        {
            std::cout << "Invalid age. Enter again: ";
            std::cin >> age;
        }
        std::cout << "Enter class: ";
        std::cin >> studentClass;
        std::cout << "Enter grade: ";
        std::cin >> grade;
    }

    void display() const
    {
        std::cout << "Name: " << name << ", Age: " << age
                  << ", Class: " << studentClass << ", Grade: " << grade << std::endl;
    }
};

class StudentManagementSystem
{
    std::vector<Student> students;

    void saveToFile()
    {
        std::ofstream file("students.txt");
        for (const auto &student : students)
        {
            file << student.name << " " << student.age << " "
                 << student.studentClass << " " << student.grade << "\n";
        }
    }

    void loadFromFile()
    {
        std::ifstream file("students.txt");
        Student student;
        while (file >> student.name >> student.age >> student.studentClass >> student.grade)
        {
            students.push_back(student);
        }
    }

public:
    StudentManagementSystem()
    {
        loadFromFile();
    }

    ~StudentManagementSystem()
    {
        saveToFile();
    }

    void addStudent()
    {
        Student student;
        student.input();
        students.push_back(student);
    }

    void updateStudent(const std::string &name)
    {
        auto it = std::find_if(students.begin(), students.end(),
                               [&name](const Student &student)
                               { return student.name == name; });
        if (it != students.end())
        {
            it->input();
        }
        else
        {
            std::cout << "Student not found!\n";
        }
    }

    void deleteStudent(const std::string &name)
    {
        auto it = std::remove_if(students.begin(), students.end(),
                                 [&name](const Student &student)
                                 { return student.name == name; });
        if (it != students.end())
        {
            students.erase(it, students.end());
            std::cout << "Student deleted!\n";
        }
        else
        {
            std::cout << "Student not found!\n";
        }
    }

    void displayStudents() const
    {
        for (const auto &student : students)
        {
            student.display();
        }
    }
};

int main()
{
    StudentManagementSystem sms;
    std::cout << "Enter student Name in this form : first_Last Name....\n";
    int choice;
    do
    {
        std::cout << "1. Add Student\n2. Update Student\n3. Delete Student\n4. Display Students\n5. Exit\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            sms.addStudent();
            break;
        case 2:
            std::cout << "Enter student name to update: ";
            {
                std::string name;
                std::cin >> name;
                sms.updateStudent(name);
            }
            break;
        case 3:
            std::cout << "Enter student name to delete: ";
            {
                std::string name;
                std::cin >> name;
                sms.deleteStudent(name);
            }
            break;
        case 4:
            sms.displayStudents();
            break;
        case 5:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
