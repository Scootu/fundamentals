
#include "students-manager.h"

#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

#include "course.h"
#include "assignment.h"
#include "assignment-solution.h"
#include "helper.h"

namespace Faculty {

shared_ptr<StudentsManager> gStudentsManager(new StudentsManager());

shared_ptr<Student> StudentsManager::GetUser(string user_name, string password) {
  for (auto student : students_vec_) {
    if (student->IsMyAuthData(user_name, password))
      return student;
  }

  return nullptr;
}

void StudentsManager::ShowStudents() {
  for (auto student : students_vec_) {
    // pritnf is C function that makes things easy in print..Think cout
    // %15s means print it in window of 15 spaces. -15 means left justified. Think setw
    printf("Student %-15s with ID %s registered in %d courses.\n", student->name_.c_str(), student->id_.c_str(), (int) student->registered_courses_.size());

    if (student->registered_courses_.size() > 0) {
      printf("\tCourses list:");

      for (auto course : student->registered_courses_)
        cout << " " << course->code_;
      cout << endl;
    }
  }
  cout << "\n******************************************************************\n";
}

void StudentsManager::AddDummyData() {
  vector<string> names = { "Ali", "Mostafa", "Hani", "Mohamed", "Ashraf", "Samy", "Morad", "Sayed", "Hussien" };
  for (int i = 1; i <= 20; ++i) {
    shared_ptr<Student> student(new Student());

    student->user_name_ = "s" + Helper::ToString(i, 3);
    student->password_ = "s" + Helper::ToString(i, 3);
    student->name_ = names[rand() % (names.size())] + " " + names[rand() % (names.size())];
    student->id_ = Helper::ToString(i, 3) + Helper::ToString((i * 12345) % 10000, 5);
    student->email_ = Helper::ToString(i, 3) + "@gmail.com";

    students_vec_.push_back(student);
  }
}

}