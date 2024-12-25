#ifndef ASSIGNMENT_H_INCLUDED
#define ASSIGNMENT_H_INCLUDED

#include <string>
#include <vector>
#include <memory>
using std::vector;
using std::string;
using std::shared_ptr;


//#include "course.h"	we will use forward declaration instead
namespace Faculty {

struct Course;
struct AssignmentSolution;

struct Assignment {
  string content_;
  int max_grade_;
  shared_ptr<Course> course_;
  vector<shared_ptr<AssignmentSolution>> assignment_solutions_;

};

}
#endif // ASSIGNMENT_H_INCLUDED
