#include <iostream>
using namespace std;

class Person
{

public:
    string name;
    Person(){};
    Person(string name)
    {
        this->name = name;
    }
    virtual void display()
    {
        cout << "\nhaha my name: " << name << endl;
    }
    void sayHi()
    {
        cout << "Hi Bruh!" << endl;
    }
};

class Student : public Person
{

public:
    string course;
    float grade;
    string year;

    Student(string name, string course, string year, float grade)
    {

        // constructors are not inherited by default.

        this->name = name;
        this->course = course;
        this->grade = grade;
        this->year = year;
    }

    void display()
    {

        cout << "\nHere are my beautiful details:" << endl;

        cout << "My goodname: " << this->name << endl;
        cout << "Course: " << course << endl;
        cout << "Grade: " << grade << endl;
        cout << "Year: " << year << endl;
    }
};
// use public for "is-a" relationship, and private/protected for "has-a"
class Employee : public Person
{

    string department;
    double salary; // by default: private

public:
    Employee(string name, string department, double salary)
    {

        this->name = name;
        this->department = department;
        this->salary = salary;
    }

private:
    void display()
    {
        cout << "\nmy details" << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: USD" << salary << endl;
    }
public:
    void sayHi(){
        cout<<"\nNo, i wont"<<endl;
    }
};

int main()
{

    Person *p = new Person("hello");
    p->display();

    // run time polymorphism example:
    Person *st = new Student("SteveSmith", "cricket", "2010", 10);
    st->display(); // gotta add the virtual keyword to override.

    Person *employee = new Employee("LakshyaChopra", "Seniormost Engineer & Owner", 15000000);
    employee->display(); //also see, how the Parent reference can access even private members.

    // one could've have accessed the objects of the derived classes with the references of the derived classes as well, in that CASE, we won't have to use the virtual keyword. // for ex: below:
    Employee *new_emp = new Employee("idk","junior",1000);

    // Method HIDING
    new_emp->sayHi();

}