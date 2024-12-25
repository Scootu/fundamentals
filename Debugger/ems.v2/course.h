#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#include <string>
#include <vector>
#include <memory>
using std::vector;
using std::string;
using std::shared_ptr;
namespace Faculty {

//Forward Declarations
struct Doctor;
struct Student;
struct Assignment;

struct Course {
  string name_;
  string code_;
  shared_ptr<Doctor> doctor_;
  vector<shared_ptr<Student>> registered_students_;
  vector<shared_ptr<Assignment>> assignments_;

  int GetTotalRegisteredStudentsNumber();
  int GetTotalAssigmentsGradesSum();
};
}
#endif // COURSE_H_INCLUDED
