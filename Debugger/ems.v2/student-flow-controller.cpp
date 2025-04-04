
#include "student-flow-controller.h"
#include "students-manager.h"
#include "courses-manager.h"
#include "helper.h"

#include <iostream>
#include <cassert>
using std::cout;
using std::cin;

/*
 * This class is complete. It should be good reference to implement the similar ones
 */
namespace Faculty {

shared_ptr<StudentFlowController> gStudentFlowController(new StudentFlowController());

bool StudentFlowController::IsValidUser(string user_name, string password) {
  return gStudentsManager->GetUser(user_name, password) != nullptr;
}

void StudentFlowController::TakeControl(string user_name, string password) {
  current_student_ = gStudentsManager->GetUser(user_name, password);

  cout << "\n\nWelcomme " << current_student_->name_ << ". You are logged in\n";

  ShowMainMenu();
}

void StudentFlowController::ShowMainMenu() {
  vector<string> menu = { "Register in Course", "List My Courses", "View Course", "Grades Report", "Log out" };

  // what about doing vector of menus and calling it? May be complex on students!
  //std::function<void()> f_ShowMainMenu = std::bind(&StudentFlowController::ShowMainMenu, this);

  while (true) {
    int choice = Helper::RunMenu(menu);

    if (choice == 1)
      RegisterInCourse();
    else if (choice == 2)
      ListMyCourses();
    else if (choice == 3)
      ViewCourse();
    else if (choice == 4)
      ShowGradesReport();
    else
      break;  // log out
  }
}

void StudentFlowController::ShowCourseMenu() {
  vector<string> menu = { "UnRegister from Course", "Submit solution", "Back" };

  while (true) {
    int choice = Helper::RunMenu(menu);

    if (choice == 1) {
      UnRegisterFromCourse();
      break;
    } else if (choice == 2)
      SubmitCourseAssignment();
    else
      break;  // go to the previous menu
  }
}

void StudentFlowController::RegisterInCourse() {
  vector<shared_ptr<Course>> other_courses = gCoursesManager->GetComplimentCourses(current_student_->registered_courses_);

  cout << "\nAvailable Courses for you: \n";

  int pos = 0;

  for (auto course : other_courses)
    printf("%d) Course %s - Code %s\n", ++pos, course->name_.c_str(), course->code_.c_str());

  printf("Which ith [1 - %d] course to register? ", pos);

  int choice = Helper::ReadInt(1, pos) - 1;

  // Link course - student
  current_student_->registered_courses_.push_back(other_courses[choice]);
  other_courses[choice]->registered_students_.push_back(current_student_);

  cout<<"\nRegistered Successfully\n";
}

void StudentFlowController::ListMyCourses() {
  cout << "\n\nMy Courses list: \n";

  int pos = 1;

  for (auto course : current_student_->registered_courses_)
    printf("%d) Course %s - Code %s\n", pos++, course->name_.c_str(), course->code_.c_str());
}

void StudentFlowController::ViewCourse() {

  // Clever engineer...takes care of special cases
  if (current_student_->registered_courses_.size() == 0) {
    cout << "No registered courses\n";
    return;
  }

  ListMyCourses();

  printf("\nWhich ith [1 - %d] course to view? ", (int) current_student_->registered_courses_.size());

  int choice = Helper::ReadInt(1, current_student_->registered_courses_.size()) - 1;
  current_course_ = current_student_->registered_courses_[choice];

  // Print course summary
  printf("\nCourse %s with Code %s - ", current_course_->name_.c_str(), current_course_->code_.c_str());
  printf("taught by Doctor %s\n", current_course_->doctor_->name_.c_str());
  printf("Course has %d assignment\n", (int) current_course_->assignments_.size());

  int pos = 0;
  for (auto assignment : current_course_->assignments_) {
    cout << "Assignment " << ++pos << " ";

    shared_ptr<AssignmentSolution> sol = current_student_->GetAssignmentSolution(assignment);

    if (sol == nullptr)
      cout << "NOT submitted - NA";
    else {
      cout << "submitted - ";

      if (sol->is_graded)
        cout << sol->grade_;
      else
        cout << "NA";
    }
    cout << " / " << assignment->max_grade_ << "\n";
  }

  ShowCourseMenu();
}

void StudentFlowController::ShowGradesReport() {
  vector<tuple<string, int, int, int>> stat_vec = current_student_->ComputeGradesStatistic();

  printf("\n");

  for (auto tuple_data : stat_vec) {
    using std::get;

    printf("Course code %s - Total submitted %d assignments - Grade %d / %d\n", get<0>(tuple_data).c_str(), get<1>(tuple_data), get<2>(tuple_data),
           get<3>(tuple_data));
  }
}

void StudentFlowController::SubmitCourseAssignment() {
  printf("\nWhich ith [1 - %d] assignment to submit? ", (int) current_course_->assignments_.size());

  int choice = Helper::ReadInt(1, current_course_->assignments_.size()) - 1;

  shared_ptr<AssignmentSolution> assign_solution(new AssignmentSolution());

  cout << "Enter the solution (no space)\n";
  cin>>assign_solution->answer_;

  assign_solution->student_ = current_student_;
  assign_solution->assignment_ = current_course_->assignments_[choice];
  assign_solution->is_graded = false;

  // If we submitted solution before, remove it
  // ...forgetting that is bug may cause student to get full marks easily
  // Let's make a small reference instead of big name
  vector<shared_ptr<AssignmentSolution>> &sols1 = current_student_->assignments_solutions_;

  for (int i = 0; i < (int) sols1.size(); ++i) {
    if (sols1[i]->assignment_ == current_course_->assignments_[choice]) {
      // then, we have solution already. Let's remove it in 2 places
      // Get solutions of this assignment, remove me from them
      vector<shared_ptr<AssignmentSolution>> &sols2 = current_course_->assignments_[choice]->assignment_solutions_;

      for (int j = 0; j < (int)sols2.size(); ++j) {
        if (sols1[i] == sols2[j]) {
          sols2.erase(sols2.begin() + j);
          break;
        }
      }
      // Now remove this solution from the students list
      sols1.erase(sols1.begin() + i);
      break;
    }
  }
  // Add solution - 2 ways: one for the students list...and one for the courses assignment solution list
  current_course_->assignments_[choice]->assignment_solutions_.push_back(assign_solution);
  current_student_->assignments_solutions_.push_back(assign_solution);
}

void StudentFlowController::UnRegisterFromCourse() {
  // Remove the course from the 2 sides
  Helper::RemoveElement(current_course_->registered_students_, current_student_);
  Helper::RemoveElement(current_student_->registered_courses_, current_course_);
}

/*
 * TODO: We shouldn't allow duplicate email or ID. We shouldn't allow invalid email. Use C++11 Regex.
 */
void StudentFlowController::DoSignUp() {
  shared_ptr<Student> student(new Student());

  while (true) {
    // More clever handling is needed...e.hg. input spaces
    cout << "Enter user name: ";
    cin >> student->user_name_;

    cout << "Enter password: ";
    cin >> student->password_;

    if (IsValidUser(student->user_name_, student->password_))
      cout << "\nERROR: User already exist...Try again\n\n";
    else
      break;
  }

  cout << "Enter Full Name: ";
  // getline reads last \n
  do {
    getline(cin, student->name_);
  } while (student->name_.size() == 0);

  cout << "Enter Student ID: ";
  cin >> student->id_;

  cout << "Enter Email: ";
  cin >> student->email_;

  gStudentsManager->students_vec_.push_back(student);
}

}
