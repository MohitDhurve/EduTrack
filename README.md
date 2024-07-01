# Student-Management-System
  <p>This C++ project is a simple <strong>Student Management System</strong> that allows you to perform basic operations such as adding, updating, deleting, and displaying student records. The project uses file handling to save and load student data from a text file.</p>
        
   <h2>Features</h2>
        <ul>
            <li>Add a new student</li>
            <li>Update an existing student's details</li>
            <li>Delete a student</li>
            <li>Display all students</li>
        </ul>
      <h2>How to Run</h2>
        <p>To compile and run this project, follow these steps:</p>
        <ol>
            <li>Clone the repository to your local machine.</li>
            <li>Open a terminal and navigate to the project directory.</li>
            <li>Compile the project using a C++ compiler, for example:</li>
            <pre><code>g++ -o student_management_system main.cpp</code></pre>
            <li>Run the executable:</li>
            <pre><code>./student_management_system</code></pre>
        </ol>

   <h2>Code Explanation</h2>
        <p>The main components of the project are:</p>
        <ul>
            <li><code>Student</code> class: Represents a student with attributes like name, age, class, and grade. It includes methods for inputting and displaying student details.</li>
            <li><code>StudentManagementSystem</code> class: Manages a collection of <code>Student</code> objects. It includes methods for adding, updating, deleting, and displaying students, as well as saving and loading student data to and from a file.</li>
            <li><code>main</code> function: Provides a simple command-line interface for interacting with the student management system.</li>
        </ul>

  <h2>Example</h2>
        <p>Here's a snippet of the <code>Student</code> class:</p>
        <pre><code>class Student
{
public:
    std::string name;
    int age;
    std::string grade;
    std::string studentClass;

   void input()
    {
        std::cout << "Enter name: ";
        std::getline(std::cin >> std::ws, name);
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
};</code></pre>

   <p>For more details, please check the full source code in the repository.</p>
      <p >Note: Ensure you have a C++ compiler installed on your machine to compile and run the code.</p>
    
