
#include "student.h"
#include "assignment.h"
#include "assignment-solution.h"

namespace Faculty {

bool Student::IsMyAuthData(string user_name, string password) {
  return user_name_ == user_name && password_ == password;
}

vector<tuple<string, int, int, int>> Student::ComputeGradesStatistic() {
  vector<tuple<string, int, int, int>> returen_vec;

  // Create 3 maps, to map from course code to 3 things
  // 1) Assignments count of this course
  // 2) The sum of my grades cross all my assignments
  // 3) Sum of max grades of every assignment to know my grade / total
  map<string, int> course_code_to_total_assignments;
  map<string, int> course_code_to_my_grades_sum;
  map<string, int> course_code_to_total_grades_sum;

  for (auto solution : assignments_solutions_) {
    string code = solution->assignment_->course_->code_;

    if(solution->is_graded)
      course_code_to_my_grades_sum[code] += solution->grade_;
    course_code_to_total_grades_sum[code] += solution->assignment_->max_grade_;
    course_code_to_total_assignments[code]++;
  }

  for (auto code_grade_kv : course_code_to_my_grades_sum) {
    string code = code_grade_kv.first.c_str();

    tuple<string, int, int, int> t(code, course_code_to_total_assignments[code], course_code_to_my_grades_sum[code], course_code_to_total_grades_sum[code]);

    returen_vec.push_back(t);
  }

  return returen_vec;
}

shared_ptr<AssignmentSolution> Student::GetAssignmentSolution(shared_ptr<Assignment> assignment) {
  for (auto solution : assignments_solutions_) {
    if (assignment == solution->assignment_)  // memory address compare
      return solution;
  }
  return nullptr;
}

}
