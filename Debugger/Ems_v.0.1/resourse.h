#ifndef RESOURSE_H_INCLUDED
#define RESOURSE_H_INCLUDED
#include "doctorsDataCenterfile.h"
#include "StudentDataCenter.h"
#include <string>  // Include this to recognize std::string
#include <vector>
#include <algorithm>

using namespace std;

// Base class
struct Person
{
public:
    virtual ~Person() {} // Virtual destructor for safe deletion
    virtual void PersonHandlerSys() = 0 ; // Pure virtual function
};

void handlePerson(Person* person)
{
    person->PersonHandlerSys();
}
struct course
{
    string name;
    string code;
    string taught;
    vector<string> RegisteredStudentsIds ;
    course(string name, string code, string taught, vector<string> listof)
    {
        this->name = name;  // Use '->' with 'this' pointer
        this->code = code;
        this->taught = taught;
        this->RegisteredStudentsIds = listof;
    }
};
vector<course> listofCourses =
{
    {"Prog 1","CS111","Samy",{"00102345","00204690","01003450","00409380","00501725"}},
    {"Prog 2","CS112","Morad",{"00102345","00204690","00307035","01003450","00409380","00501725"}},
    {"Math 2","CS333","Hani",{"00102345","00204690","00307035","01003450","00409380","00501725"}},
    {"Prog 3","CS136","Sayed",{"00102345","00204690","00307035","01003450","00409380","00501725"}},
    {"Stat 1","CS240","Hussien",{"00102345","00204690","01003450","00501725"}},
    {"Math 1","CS123","Ashraf",{"00204690","01003450","00307035","00409380","00501725"}},
    {"Stat 2","CS350","Morad",{"00102345","00204690","00409380"}},
};

struct Doctors : public Person
{
    std::string fullName;
    std::string password;
    vector<string> arrListofcourses;

    Doctors(string name,string pass,vector<string> listofCourses):fullName(name),password(pass),arrListofcourses(listofCourses) {}
    void PersonHandlerSys() override
    {
        cout << "Welcome Doctor " << fullName <<". You are logged in"<< std::endl;
    }
    void listCourses();
    void CreateCourse();
    void ViewCourse();
};

// Implementations of member functions
void Doctors::listCourses()
{

}
void Doctors::CreateCourse()
{

}
void Doctors::ViewCourse() {}
struct Assignment
{
    string Code;
    bool isSubmited = false;
    string valueofnote = "NA";
    int note;
    string content;

    Assignment(string code,bool issubmited,string value,int note,string content)
    {
        this->Code = code;
        this->isSubmited = issubmited;
        this->valueofnote = value;
        this->note = note;
        this->content = content;
    }
};
struct Student : public Person
{
    string ID;
    std::string fullName;
    std::string password;
    std::string email;
    vector<string> myCourses;
    vector<Assignment> myAssignments;
    // Constructor
    Student(string id,  std::string name,  std::string pass,  std::string mail,vector<string> arr,vector<Assignment> arrofassignments) : ID(id), fullName(name), password(pass), email(mail),myCourses(arr),myAssignments(arrofassignments) {}
    void RegisterInCourse(vector<string> myCourses);
    void ListMyCourses(vector<string> myCourses);
    void ViewCourse(vector<string> myCourses);
    void GradesReport();
    void unRegisterFromCourse(string code);
    void SubmitSolution(string code,int sizeofarr);
    void logOut(bool *stop)
    {
        *stop = true;
    }
    void PersonHandlerSys() override
    {
        cout << "Welcome " << fullName <<". You are logged in"<< std::endl;
        bool stop = false;

        while(!stop)
        {
            int studentChoice;


            cout << "Please make a choice:"<<endl;
            cout << "     "<< "1 - Register in Course \n";
            cout << "     "<< "2 - List My Course \n";
            cout << "     "<< "3 - View Course \n";
            cout << "     "<< "4 - Grades Report \n";
            cout << "     "<< "5 - Log out \n";
            cout << "     "<< "Enter Choice: ";
            cin >>studentChoice;

            switch(studentChoice)
            {
            case 1:
                RegisterInCourse(this->myCourses);
                break;
            case 2:
                ListMyCourses(this->myCourses);
                break;
            case 3:
                ViewCourse(this->myCourses);
                break;
            case 4:
                GradesReport();
            case 5:
                logOut(&stop);
                break;
            default:
                cout<<"Invalid number, please repeat "<<endl;
            }

        }
    }

};
void Student::RegisterInCourse(vector<string> myCourses)
{
    int i = 0 ;
    vector<course>UnregisteredCourses;
    for(auto course : listofCourses)
    {
        auto it = find_if(myCourses.begin(), myCourses.end(), [&course](const string& courseCode)
        {
            return course.code == courseCode; // Compare course codes
        });
        if(it == myCourses.end())
        {
            cout <<++i<<") "<< "Course name = " << course.name   // or (*it).name
                 << "   Code = " << course.code
                 << "   Taught by Dr: " << course.taught << "\n";
            UnregisteredCourses.push_back(course);

        }
    }
    if(UnregisteredCourses.size() != 0)
    {
        int userChoise;
        cout<<"Which ith [1 - "<<i<<"]"<<" course to register on it? ,Enter 0 to go back ";
        cin>>userChoise;
        if(userChoise != 0)
        {
            while(userChoise > (int)UnregisteredCourses.size())
            {
                cout<<"Invalid input course number, please repeat \n";
                cout<<"Which ith [1 - "<<i<<"]"<<" course to register on it? ";
                cin>>userChoise;
            }
            this->myCourses.push_back(UnregisteredCourses[userChoise-1].code);
            cout<<"You are registered with success view your course list ! \n";
        }
    }
    else
    {
        cout<<"You are registered in all courses! \n";
    }
}
void Student::unRegisterFromCourse(string code)
{
    auto it = myCourses.begin();
    for(; it!= myCourses.end(); ++it)
    {
        if(code == (*it))
        {
            myCourses.erase(it);
            break;
        }
    }
}
void Student::SubmitSolution(string code, int sizeofarr)
{
    if(sizeofarr > 0)
    {
        int userChoice;
        cout << "Which ith [1 - "<<sizeofarr<<"] assignment to submit? ";
        cin>>userChoice;
        string content;
        cout<<"Enter the solution (no space) \n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,content);
        auto it = this->myAssignments.begin();
        int i = 1 ;
        for(; it != this->myAssignments.end(); ++it)
        {
            if(it->Code == code && i++ == userChoice)
            {
                it->content = content;
                it->isSubmited = true;
                //now the value of the assignment should be evaluated by the doctor
            }
        }

        cout<<"Solution submitted with success!"<<endl;
    }
    else
    {
        cout<<"You don't have assignments to be submitted yet!"<<endl;
    }
}
void Student::ListMyCourses(vector<string> myCourses)
{
    for (const auto& courseCode : myCourses)
    {
        auto it = find_if(listofCourses.begin(), listofCourses.end(),
                          [&courseCode](const course& course)
        {
            return course.code == courseCode; // Compare course codes
        });

        if (it != listofCourses.end()) // pointer to an attribute
        {
            cout << "Course name = " << it->name   // or (*it).name
                 << "   Code = " << it->code
                 << "   Taught by Dr: " << it->taught << "\n";

        }
    }
}

void Student::ViewCourse(vector<string> myCourses)
{
    int i = 1 ;
    for (const auto& courseCode : myCourses)
    {
        auto it = find_if(listofCourses.begin(), listofCourses.end(),
                          [&courseCode](const course& course)
        {
            return course.code == courseCode; // Compare course codes
        });

        if (it != listofCourses.end()) // pointer to an attribute
        {
            cout <<i<<")"<< " Course name = " << it->name   // or (*it).name
                 << "   Code = " << it->code
                 << "   Taught by Dr: " << it->taught << "\n";
            i++;
        }

    }
    int userChoise;
    cout<<"Which ith [1 - "<<i-1<<"]"<<" course to view? ";
    cin>>userChoise;
    while(userChoise > (int)listofCourses.size())
    {
        cout<<"Invalid input course number, please repeat \n";
        cout<<"Which ith [1 - "<<i-1<<"]"<<" course to view? ";
        cin>>userChoise;
    }


    string courseCode =  myCourses[userChoise-1];
    auto userCourse  = listofCourses.begin();
    for(; userCourse != listofCourses.end(); ++userCourse)
    {
        if(userCourse->code == courseCode)
        {
            cout <<"Course name = " << userCourse->name   // or (*userCourse).name
                 << "   Code = " << userCourse->code
                 << " - Taught by Dr: " << userCourse->taught << "\n";
        }
    }

    int z = 0 ;
    for(const auto& it : this->myAssignments)
    {
        if(it.Code == courseCode)
            z++;
    }
    cout<<"Course has "<<z<<" assignments"<<"\n";
    int t = 1;
    for (const auto& it : this->myAssignments)    // Use reference to avoid copying
    {
        if(it.Code == courseCode)
        {
            cout << "Assignment " << t++ << " ";  // Increment 't' after using it
            (it.isSubmited != true) ? cout << "NOT submitted" : cout << "submitted";  // Correct ternary operator syntax
            cout << " - " << it.valueofnote << " / " << it.note << "\n";  // Use '.' since 'it' is not a pointer
        }
    }
    cout<<"Please make a choice: \n";
    cout << "     "<< "1 - Unregister from Course \n";
    cout << "     "<< "2 - Submit solution \n";
    cout << "     "<< "3 - Back \n";
    cout << "     "<< "Enter Choice: ";
    cin>>userChoise;
    switch(userChoise)
    {
    case 1:
        unRegisterFromCourse(courseCode);
        break;
    case 2:
        SubmitSolution(courseCode,t-1);
        break;
    case 3:
        break;
    default:
        cout<<"Invalid number"<<endl;
    }


}

void Student::GradesReport()
{

    for(const auto& courseCode : this->myCourses)
    {
        int t = 0 ;
        int Grade = 0;
        int totalNote;
        for (const auto& it : this->myAssignments)    // Use reference to avoid copying
        {
            if(it.Code == courseCode && it.valueofnote != "NA")
            {
                ++t;
                Grade+=stoi(it.valueofnote);
                totalNote += it.note;
            }
        }
        if(t!=0)
        {
            cout<<"Course code "<<courseCode<<" - ";
            cout<<t<<" assignments - Grade "<<Grade<<" / "<<totalNote<<"\n\n";
        }
    }
}

std::vector<Doctors> doctorsDataCenter =
{
    {"Ali", "password1", {}},
    {"Mostafa", "password2", {}},
    {"Hani", "password3", {"CS333"}},
    {"Mohamed", "password4", {}},
    {"Ashraf", "password5", {"CS123"}},
    {"Samy", "password6", {"CS111"}},
    {"Morad", "password7", {"CS112", "CS350"}},
    {"Sayed", "password6", {"CS136"}},
    {"Hussien", "password7", {"CS240"}}
};

std::vector<Student> studentDataCenter =
{
    {"00102345", "Hussien Samy", "password1", "hussien.samy@example.com",{"CS111","CS112","CS333","CS136","CS240","CS350"},{{"CS111",true,"36",84,"Hello world"},{"CS111",false,"NA",84,"Hello world"}}},
    {"00409380", "Ali Mohamed", "password2", "ahmed.ali@example.com",{"CS111","CS112","CS123","CS333","CS136","CS350"},{{"CS111",false,"NA",84,"Hello world"}}},
    {"00204690", "Ashraf Sayed", "password3", "sara.mahmoud@example.com",{"CS111","CS112","CS123","CS333","CS136","CS240","CS350"},{{"CS111",false,"NA",84,"Hello world"}}},
    {"00307035", "Mostafa Hussien", "password4", "mostafa.hussien@example.com",{"CS112","CS123","CS333","CS136"},{{"CS112",false,"NA",84,"Hello world"}}},
    {"00501725", "Hani Sayed", "password5", "hani.sayed@example.com",{"CS111","CS112","CS123","CS333","CS136","CS240"},{{"CS111",false,"NA",84,"Hello world"}}},
};
#endif // RESOURSE_H_INCLUDED
