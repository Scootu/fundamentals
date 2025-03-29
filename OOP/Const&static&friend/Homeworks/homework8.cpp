#include <bits/stdc++.h>
using namespace std;

class StudentGradesInfoWrapper;

class StudentGradesInfo
{
private:
    string student_id;
    vector<double> grades;
    vector<string> courses_names;
    const int MAX_GRADE_PER_COURSE = 100.0;

    friend class StudentGradesInfoWhiteBoxTester; // as a friend

    static int statistics_total_prints;

    double AdjustGrade(double grade) const
    {
        if (grade < 0)
            return 0;
        if (grade > MAX_GRADE_PER_COURSE)
            return MAX_GRADE_PER_COURSE;
        return grade;
    }
    friend class StudentGradesInfoWrapper;  

public:
    StudentGradesInfo(string student_id) : student_id(student_id)
    {
    }

    bool AddGrade(double grade, const string &course_name)
    {
        grade = AdjustGrade(grade);

        for (int i = 0; i < (int)courses_names.size(); ++i)
            if (course_name == courses_names[i])
                return false; // already added

        grades.push_back(grade);
        courses_names.push_back(course_name);
        return true;
    }
    void PrintAllCourses() const
    {
        ++statistics_total_prints;

        cout << "Grades for student: " << GetStudentId() << "\n";
        for (int course_idx = 0; course_idx < (int)courses_names.size(); ++course_idx)
            cout << "\t" << courses_names[course_idx] << " = " << grades[course_idx] << "\n";
    }
    bool GetCourseGradeInfo(int pos, pair<string, double> &result) const
    {
        if (pos < 0 || pos >= (int)grades.size())
        {
            result = make_pair("", -1);
            return false;
        }
        result = make_pair(courses_names[pos], grades[pos]);
        return true;
    }

    string GetStudentId() const
    {
        return student_id;
    }

    int GetTotalCoursesCount() const
    {
        return grades.size();
    }

    pair<double, double> GetTotalGradesSum() const
    {
        double sum = 0, total = 0;
        for (int grade_idx = 0; grade_idx < (int)grades.size(); ++grade_idx)
            sum += grades[grade_idx], total += MAX_GRADE_PER_COURSE;
        return make_pair(sum, total);
    }
};

int StudentGradesInfo::statistics_total_prints = 0;

class StudentGradesInfoWrapper
{
private:
    static int statistics_total_students;
    static int statistics_total_AllPrints;
    StudentGradesInfo st;

public:
    StudentGradesInfoWrapper(string id) : st(id)
    {
        ++statistics_total_students;
    }

public:
    bool
    AddGrade(double grade, const string &course_name)
    {
        return st.AddGrade(grade, course_name);
    }

    void PrintAllCourses() const
    {
        st.PrintAllCourses();
    }
    bool GetCourseGradeInfo(int pos, pair<string, double> &result) const
    {
        return st.GetCourseGradeInfo(pos, result);
    }

    string GetStudentId() const
    {
        return st.GetStudentId();
    }

    int GetTotalCoursesCount() const
    {
        return st.GetTotalCoursesCount();
    }

    pair<double, double> GetTotalGradesSum() const
    {
        return st.GetTotalGradesSum();
    }
    static int GetTotalStudents()
    {
        return StudentGradesInfoWrapper::statistics_total_students;
    }
    static int getTotalPrints()
    {
        return StudentGradesInfo::statistics_total_prints;
    }
    static int GetTotalPrints()
    {
        StudentGradesInfoWrapper::statistics_total_AllPrints += getTotalPrints();
        return StudentGradesInfoWrapper::statistics_total_AllPrints;
    }
};
int StudentGradesInfoWrapper::statistics_total_students = 0;
int StudentGradesInfoWrapper::statistics_total_AllPrints = 0;
int main()
{
    StudentGradesInfoWrapper st1("S000123");
    st1.AddGrade(70, "Math");
    st1.AddGrade(70, "programming 1");
    st1.AddGrade(85, "programming 2");

    st1.PrintAllCourses();

    pair<double, double> p = st1.GetTotalGradesSum();
    cout << p.first << "/" << p.second << "\n";

    StudentGradesInfoWrapper st2("S000129");
    st2.PrintAllCourses();
    st2.PrintAllCourses();
    st2.PrintAllCourses();

    cout << "Total Students " << StudentGradesInfoWrapper::GetTotalStudents() << "\n";
    cout << "Total Prints " << StudentGradesInfoWrapper::GetTotalPrints() << "\n";

    cout << "Bye\n";

    return 0;
}