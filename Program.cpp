#include <iostream>
#include <iomanip>

class Program {
private:
    std::string name, author, dueDate;
    int greetingFields = 3;

    std::string greetingData[3][3] = {
        {"Welcome to the", "Author:", "Due Date:"},
        {name, author, dueDate}
    };

    static const std::string 
        RTF, RCF, LCF;

public:
    Program();
    Program(std::string n, std::string a, std::string d);

    void setName(std::string n);
    std::string getName();

    void setAuthor(std::string a);
    std::string getAuthor();

    void setDueDate(std::string d);
    std::string getDueDate();

    void setGreetingFields();

    void printGreeting();
};

const std::string Program::RTF = "\033[0m";
const std::string Program::RCF = "\033[1;97m";
const std::string Program::LCF = "\033[1;31m";

Program::Program() {
    name = "Program Name";
    author = "Author Name";
    dueDate = "Due Date";
 }

Program::Program(std::string n, std::string a, std::string d) {
    name = n;
    author = a;
    dueDate = d;
}

void Program::setName(std::string n) { name = n; }
std::string Program::getName() { return name; }

void Program::setAuthor(std::string a) { author = a; }
std::string Program::getAuthor() { return author; }

void Program::setDueDate(std::string d) { dueDate = d; }
std::string Program::getDueDate() { return dueDate; }

void Program::setGreetingFields() {
    greetingData[1][0] = name;
    greetingData[1][1] = author;
    greetingData[1][2] = dueDate;
}

void Program::printGreeting() {
    // Main greeting message
    std::string greetingMessage = LCF + greetingData[0][0] + ' ' + RCF + name + '\n';

    //  Stores length of longest field for spacing in menu
    size_t longestField = 0;

    // Finds longest string in GREETING_DATA 2D array
    for (int i = 1; i < greetingFields; i++)
        if (greetingData[0][i].length() > longestField) 
            longestField = greetingData[0][i].length();

    // Prints program's start up message
    std::cout << greetingMessage;
    for (int i = 1; i < greetingFields; i++)
        std::cout  
            << LCF << std::setw(longestField) << greetingData[0][i] 
            << RCF << ' ' + greetingData[1][i] << RTF
        << std::endl; 
}