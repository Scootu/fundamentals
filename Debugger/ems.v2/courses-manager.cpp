
#include "courses-manager.h"
#include "doctors-manager.h"
#include "students-manager.h"

#include <iostream>
#include <cassert>
#include <iomanip>
using std::cout;
using std::cin;

#include "assignment.h"
#include "helper.h"

namespace Faculty {

shared_ptr<CoursesManager> gCoursesManager(new CoursesManager());

void CoursesManager::AddCourse() {
  shared_ptr<Course> course(new Course());

  cout << "Enter course name: ";
  cin >> course->name_;

  cout << "Enter course code: ";
  cin >> course->code_;

  courses_.push_back(course);
}

void CoursesManager::ShowCourses() {
  for (auto course : courses_) {
    cout << "Course name = " << std::left << std::setw(5) << course->name_ << "\tCode = " << course->code_ << " - Taught by Dr: " << course->doctor_->name_
         << "\n";

    cout << "\tRegistered students ID:";

    for (auto student : course->registered_students_)
      cout << " " << student->id_;
    cout << "\n";
  }

  cout << "\n******************************************************************\n";
}

/*
 * TODO: Have new user type (admin), let it has menu option to add courses.
 */
void CoursesManager::AddDummyData() {
  shared_ptr<Course> course01(new Course());
  course01->name_ = "Prog 1", course01->code_ = "CS111";
  courses_.push_back(course01);

  shared_ptr<Course> course02(new Course());
  course02->name_ = "Prog 2", course02->code_ = "CS112";
  courses_.push_back(course02);

  shared_ptr<Course> course03(new Course());
  course03->name_ = "Math 1", course03->code_ = "CS123";
  courses_.push_back(course03);

  shared_ptr<Course> course04(new Course());
  course04->name_ = "Math 2", course04->code_ = "CS333";
  courses_.push_back(course04);

  shared_ptr<Course> course05(new Course());
  course05->name_ = "Prog 3", course05->code_ = "CS136";
  courses_.push_back(course05);

  shared_ptr<Course> course06(new Course());
  course06->name_ = "Stat 1", course06->code_ = "CS240";
  courses_.push_back(course06);

  shared_ptr<Course> course07(new Course());
  course07->name_ = "Stat 2", course07->code_ = "CS350";
  courses_.push_back(course07);

  // later fix further data, e.g. assignments, students, doctor
}

void CoursesManager::AddDummyRelationshipsData() {
  for (auto course : courses_) {
    // Generate 75% of students per course
    int registered_students_cnt = gStudentsManager->students_vec_.size() * 75.0 / 100.0;

    course->registered_students_ = Helper::GetRandomSubset(gStudentsManager->students_vec_, registered_students_cnt);
    course->doctor_ = Helper::GetRandomSubset(gDoctorsManager->doctors_vec_, 1)[0];

    for (int r = 1 + rand() % 5; r; r--) {
      shared_ptr<Assignment> assign(new Assignment());

      course->assignments_.push_back(assign);
      assign->content_ = "Assign " + Helper::ToString(r, 3);
      assign->max_grade_ = 10 + rand() % 50;
      assign->course_ = course;  // fix connections :)

      int solved_students_cnt = course->registered_students_.size() * 60.0 / 100.0;
      vector<shared_ptr<Student>> some_registered_students = Helper::GetRandomSubset(course->registered_students_, solved_students_cnt);

      for (auto student : some_registered_students) {
        shared_ptr<AssignmentSolution> assign_solution(new AssignmentSolution());

        assign->assignment_solutions_.push_back(assign_solution);

        assign_solution->student_ = student;
        assign_solution->answer_ = Helper::ToString(rand() % 10000, 4) + Helper::ToString(rand() % 10000, 4) + Helper::ToString(rand() % 10000, 4);
        assign_solution->assignment_ = assign;

        if (Helper::Probability() > 0.5) {
          assign_solution->is_graded = true;
          assign_solution->grade_ = rand() % (1 + assign->max_grade_);
        }

        // Fix student assignment data
        assign_solution->student_->assignments_solutions_.push_back(assign_solution);
      }
    }

    // Fix doctor courses data
    course->doctor_->teaching_courses_.push_back(course);

    // Fix students courses data
    for (auto student : course->registered_students_)
      student->registered_courses_.push_back(course);
  }
}

vector<shared_ptr<Course>> CoursesManager::GetComplimentCourses(vector<shared_ptr<Course>> courses) {
  vector<shared_ptr<Course>> ret_courses;

  // For each course, find if it is in the given courses...if not so, add it
  for (auto course : courses_) {
    bool is_found = false;

    for (auto param_course : courses) {
      //if (param_course->code_ == course->code_) // right way
      if (param_course == course)  // As we know they are same pointers, we can compare addresses too
          {
        is_found = true;
        break;
      }
    }
    if (!is_found)
      ret_courses.push_back(course);
  }

  return ret_courses;
}

}
