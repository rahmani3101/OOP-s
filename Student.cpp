#include <iostream>
using namespace std;

class Student 
{
    private:
        string studentName;
        string studentID;
        float mtaScore;
        float esaScore;

    public:
        Student(string studentName , string studentID , float mtaScore , float esaScore)
        {
            this->studentName= studentName;
            this->studentID = studentID;
            this->mtaScore=mtaScore;
            this->esaScore=esaScore;
        }  

        ~Student()
        {
            cout << " Deleted Student : " << studentName <<endl;

        }

        void printStudent()
        {
            cout << "------------------------------------------- \n";
            cout << " Name : " << studentName<<endl;
            cout << " Id :" << studentID << endl;
            cout << " MTA Score : " << mtaScore<<endl;
            cout << " ESA Score : " << esaScore<<endl;
            cout << " Final Score :"<< esaScore+mtaScore<<endl;
            cout << "------------------------------------------- \n";
        }

};

int main()
{
    Student s1(" ASAD ","TIU1234",20,80);
    Student s2("Anis ", "CSB004",20,60);
    Student s3("Moin "," CSB014",18,54);

    Student *stp = new Student("Mouzam ", "CSB018",15,70);

    s1.printStudent();
    s2.printStudent();
    s3.printStudent();

    stp->printStudent();
}
