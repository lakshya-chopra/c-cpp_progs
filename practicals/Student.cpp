#include<iostream>
#include <fstream>

using namespace std;

string file_name = "test.txt";

class Student

{

    int roll_no;
    string name;
    string year;
    float grade;

    public:
    Student(string name, int roll_no, string year, float grade){

        this->name = name;
        this->grade = grade;
        this->roll_no = roll_no;
        this->year = year;

    }

    void storeToFile(fstream &f){

        f.open (file_name, fstream::in | fstream::out | fstream::app);

        f << "\n\nStudent Details:\t"<<"\nName: "<<name<<"\nGrade: "<<grade<<"\nRoll No. "<<roll_no<<"\nYear:"<<year;

        f.close();
    }

};

int main(){

    fstream f;
    Student *s1 = new Student("kriish",115,"2024",8);
    Student *s2 = new Student("Son",116,"2024",7.5);
    Student *s3 = new Student("CR7",18,"2024",10);

    s1->storeToFile(f);
    s2->storeToFile(f);
    s3->storeToFile(f);

    // read from file:
    f.open(file_name, fstream::in | fstream::out);
    
    string line;

    cout<<"\n";

    while(!f.eof()){ 
        //as soon as f.eof() turns true, this while loop's condition becomes false & it stops.
        getline(f,line);
        cout<<line<<endl;

    }
    f.close();
    

    delete s1;
    delete s2;
    delete s3;




}