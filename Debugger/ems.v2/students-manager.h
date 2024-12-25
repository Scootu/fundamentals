#ifndef STUDENTS_MANAGER_H_INCLUDED
#define STUDENTS_MANAGER_H_INCLUDED


#include <string>
#include <memory>
#include <vector>
using std::vector;
using std::string;
using std::shared_ptr;

#include "student.h"
namespace Faculty {


struct StudentsManager {
  shared_ptr<Student> GetUser(string user_name, string password);
  shared_ptr<Student> GetStudent(string student_id);	//Todo implement if needed
  int GetTotalSystemStudents();							//Todo implement if needed
  void AddDummyData();
  void ShowStudents();

  vector<shared_ptr<Student>> students_vec_;
};

extern shared_ptr<StudentsManager> gStudentsManager;

}
#endif // STUDENTS_MANAGER_H_INCLUDED
