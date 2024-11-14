#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string Name;
    Person(string name="Ö£Æß",string gender="ÄÐ",int age=22)
    {
        Name=name;
        Gender=gender;
        Age=age;
        cout<<"Person"<<Name<<"constructed"<<endl;
    }
    ~Person()
    {
        cout<<"Person"<<Name<<"destructed"<<endl;
    }
    
    protected:
    string Gender;
    int Age;
};
class StudentRecord:virtual public Person
{
public:
    int Number;
    string ClassName;
    int TotalCount;
protected:
    int Score;
    StudentRecord(string name="Ö£Æß",string gender="ÄÐ",int age=22,int number=2010123,string className="Èí20101",int totalCount=1,int score=89):Person(name,gender,age),TotalCount(totalCount)
    {
        Number=number;
        ClassName=className;
        Score=score;
        cout<<"Student"<<Name<<"constructed"<<endl;
    }
    ~StudentRecord()
    {
        cout<<"Student"<<Name<<"destructed"<<endl;
    }
};
class TeacherRecord :virtual public Person
{
public:
    string CollegeName;
    string DepartmentName;
protected:
    int Year;
    TeacherRecord(string name="Ö£Æß",string gender="ÄÐ",int age=22,int number=2010123,string collegeName="ÐÅÏ¢",string departmentName="Èí¼þ",int year=1):Person(name,gender,age)
    {
        {
            CollegeName=collegeName;
            DepartmentName=departmentName;
            Year=year;
            cout<<"teacher"<<Name<<"constructed\n";
        }

    }
    ~TeacherRecord()
    {
        cout<<"teacher"<<Name<<"destructed\n";
    }
};

class TeachingAssistant:virtual public StudentRecord,virtual public TeacherRecord
{
public:
    string LectureName;
    TeachingAssistant(string lectureName="Êý¾Ý½á¹¹",string name="Ö£Æß",string gender="ÄÐ",int age=22,int number=2010123,string collegeName="ÐÅÏ¢",string departmentName="Èí¼þ",int year=1,string className="Èí20101",int totalCount=1,int score=89):StudentRecord(name, gender, age, number, className, totalCount, score),TeacherRecord(name,gender,age,number,collegeName,departmentName,year)
    {
        LectureName=lectureName;
        cout<<"teachingassistant"<<Name<<"constructed"<<endl;
    }
    void show()
    {
        cout<<"Name:"<<Name<<" ";
        cout<<"Gender:"<<Gender<<" ";
        cout<<"Age:"<<Age<<" ";
        cout<<"Number:"<<Number<<" ";
        cout<<"ClassName:"<<ClassName<<" ";
        cout<<"TotalCount:"<<TotalCount<<" ";
        cout<<"Score:"<<Score<<" ";
        cout<<"CollegeName:"<<CollegeName<<" ";
        cout<<"DepartmentName:"<<DepartmentName<<" ";
        cout<<"Year:"<<Year<<" ";
        cout<<"LectureName:"<<LectureName<<"\n";
    }
    void SetName(string name)
    {
        Name=name;
    }
    ~TeachingAssistant()
    {
        cout<<"teachingassistant"<<Name<<"destructed\n";
    }
};

int main()
{
    TeachingAssistant a1;
    a1.show();
    a1.SetName("Ö£°Ë");
    a1.show();
    return 0;
}
