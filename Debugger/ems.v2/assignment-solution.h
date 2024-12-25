#ifndef ASSIGNMENT_SOLUTION_H_INCLUDED
#define ASSIGNMENT_SOLUTION_H_INCLUDED

#include <string>
#include <memory>
#include <vector>
using std::vector;
using std::string;
using std::shared_ptr;

namespace Faculty {
struct Student;
struct Assignment;

struct AssignmentSolution {
  int grade_;
  bool is_graded;
  string answer_;
  string staff_comments;
  shared_ptr<Assignment> assignment_;
  shared_ptr<Student> student_;
};
}
#endif // ASSIGNMENT_SOLUTION_H_INCLUDED
