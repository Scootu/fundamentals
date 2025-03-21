#include <bits/stdc++.h>
using namespace std;

class StudentGradesInfo
{
private:
	string student_id;
	vector<double> grades;
	vector<string> courses_names;
	const int MAX_GRADE_PER_COURSE = 100.0;

	// It seems developer wants to keep track of how many times this function is called
	// Proper way to maintain a static counter inside the class

	// Side note: in real life, we applications keep track of what users do and analyze it
	// This allows discovering what users do/don't so that we improve their experience
	static int statistics_total_prints;

	// Several issues in this function
	// 1- It is public, although for internal usage! Move to private
	// 2- It doesn't change class variables! Make it const. Another way is just to change it to void AdjustGrade(double & grade)
	// 3- It uses a magic number:
	// A magic number is a numeric literal (for example, 8080 , 2048 ) that is used in the middle of a block of code without explanation.
	// It is considered good practice to avoid magic numbers by assigning the numbers to named constants and using the named constants instead
	// 4- Also: if requirement changed 100 to say 50, we will do a lot of code changes!
	// 5: bug, it should be double not int (in parameter and return)
	// 6: bug in if (grade < 0) => should return 0
	double AdjustGrade(double grade) const
	{
		if (grade < 0)
			return 0;
		if (grade > MAX_GRADE_PER_COURSE)
			return MAX_GRADE_PER_COURSE;
		return grade;
	}

public:
	// It seems developer wants to prevent users from using empty constructor
	// Just asserting will break the program
	// Removing this constructor will disallow the default constructor!
	// StudentGradesInfo() {
	//	assert(false);
	//}

	// Seems string name_ is not used! Don't add what is not useful!
	// Use initializer list as possible!
	StudentGradesInfo(string student_id) : student_id(student_id) // we need a test
	{
	}

	bool AddGrade(double grade, const string &course_name)
	{
		grade = AdjustGrade(grade);

		// Very big bug. A lot of run time errors will happen!
		// needed to move to end of function
		// grades.push_back(grade);

		for (int i = 0; i < (int)courses_names.size(); ++i)
			if (course_name == courses_names[i])
				return false; // already added

		grades.push_back(grade);
		courses_names.push_back(course_name);

		return true;
	}

	// Make const!
	// Use variables names that are understandable!
	// Good function and variable names are key in clear code
	void PrintAllCourses() const
	{
		++statistics_total_prints;

		// If there is a getter/setter for a data member, use it
		cout << "Grades for student: " << GetStudentId() << "\n";
		for (int course_idx = 0; course_idx < (int)courses_names.size(); ++course_idx)
			cout << "\t" << courses_names[course_idx] << " = " << grades[course_idx] << "\n";
	}

	// const!
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

	// const!
	string GetStudentId() const
	{
		return student_id;
	}

	// const!
	int GetTotalCoursesCount() const
	{
		return grades.size();
	}

	// const!
	pair<double, double> GetTotalGradesSum() const
	{
		double sum = 0, total = 0;
		for (int grade_idx = 0; grade_idx < (int)grades.size(); ++grade_idx)
			sum += grades[grade_idx], total += MAX_GRADE_PER_COURSE;
		return make_pair(sum, total);
	}
};

int StudentGradesInfo::statistics_total_prints = 0;

class StudentGradesInfoBlackBoxtexter
{
public:
	StudentGradesInfo st;

	// Constructor initializes `st` with a student ID
	StudentGradesInfoBlackBoxtexter(const string &student_id) : st(student_id)
	{
	}

private:
	void testStudentId()
	{
		string id = st.GetStudentId();

		if (id.empty())
		{
			assert(false && "Student ID doesn't exist!");
			return;
		}

		if (id[0] != 'S')
		{
			printf("Student ID must start with 'S'\n");
			return;
		}

		if (id.length() > 7)
		{
			printf("Student ID must not exceed 7 characters\n");
			return;
		}

		string number = id.substr(1); // Extract digits after 'S'

		try
		{
			int num = stoi(number);
			if (num <= 0 || num > 999999)
			{
				assert(false && "Error: ID number out of range!");
				return;
			}
		}
		catch (exception &e)
		{
			assert(false && "Error: Invalid ID format!");
			return;
		}
		printf("Test id successed!\n");
	}
	void testAddGrade()
	{
		bool added = st.AddGrade(85.0, "Math");
		assert(added && "Failed to add a new course!");

		// Adding a duplicate course should fail
		bool duplicate = st.AddGrade(90.0, "Math");
		assert(!duplicate && "Duplicate course added!");

		printf("testAddGrade passed!\n");
	}
	void testGetCourseGradeInfo()
	{
		pair<string, double> result;
		bool found = st.GetCourseGradeInfo(0, result);
		assert(found && "Valid course not found!");
		assert(result.first == "Math" && result.second == 85.0 && "Incorrect course info!");

		// Test out-of-bounds cases
		bool notFound = st.GetCourseGradeInfo(100, result);
		assert(!notFound && "Invalid index should return false!");

		printf("testGetCourseGradeInfo passed!\n");
	}
	void testTotalCoursesCount()
	{
		int count = st.GetTotalCoursesCount();
		assert(count == 1 && "Incorrect course count!");

		printf("testTotalCoursesCount passed!\n");
	}
	void testTotalGradesSum()
	{
		pair<double, double> sum = st.GetTotalGradesSum();
		assert(sum.first == 85.0 && "Incorrect sum of grades!");

		printf("testTotalGradesSum passed!\n");
	}
	void Test_PrintAllCourses() {
		cout << __func__ << "\n";
	
		// Redirect stdout to a file
		freopen("test_output.txt", "w", stdout);
	
		StudentGradesInfo st1("S000123");
		st1.AddGrade(95, "Math");
		st1.AddGrade(88, "Physics");
		st1.PrintAllCourses();
	
		// Restore stdout
		freopen("/dev/tty", "w", stdout);
	
		// Read file content
		ifstream infile("test_output.txt");
		stringstream buffer;
		buffer << infile.rdbuf();
		string output = buffer.str();
	
		// Expected output
		string expected = "Grades for student: S000123\n\tMath = 95\n\tPhysics = 88\n";
	
		// Compare results
		assert(output == expected);
	
		cout << "Test_PrintAllCourses passed.\n";
	}

public:
	void TestAll()
	{
		testStudentId();
		testAddGrade();
		testGetCourseGradeInfo();
		testTotalCoursesCount();
		testTotalGradesSum();
		Test_PrintAllCourses();
	}
};

int main()
{
	StudentGradesInfo st1("S000123");

	st1.AddGrade(70, "Math");
	st1.AddGrade(70, "programming 1");
	st1.AddGrade(85, "programming 2");

	st1.PrintAllCourses();

	pair<double, double> p = st1.GetTotalGradesSum();
	cout << p.first << "/" << p.second << "\n";

	cout << "Bye\n";
	// test
	StudentGradesInfoBlackBoxtexter testS1(st1.GetStudentId());
	testS1.TestAll();
	return 0;
}