#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>
#include <vector>
#include <memory>
#include <tuple>
#include <map>
using std::map;
using std::tuple;
using std::vector;
using std::vector;
using std::string;
using std::shared_ptr;


#include "course.h"
#include "assignment-solution.h"
#include "assignment.h"

namespace Faculty {
struct Student {
  bool IsMyAuthData(string user_name, string password);
  /*
   * Return vector about students grades. Vector length is same as registered courses count.
   *
   * Each tuple is 4 values: course code, # submitted assignments, student grades sum, total assignments grades sum
   */
  vector<tuple<string, int, int, int>> ComputeGradesStatistic();

  /*
   * Given an assignment, see if it has solution among this list or not.
   */
  shared_ptr<AssignmentSolution> GetAssignmentSolution(shared_ptr<Assignment> assignment);

  string user_name_;
  string password_;
  string name_;
  string id_;
  string email_;

  vector<shared_ptr<Course>> registered_courses_;
  vector<shared_ptr<AssignmentSolution>> assignments_solutions_;
};

}
#endif // STUDENT_H_INCLUDED
