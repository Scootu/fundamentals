#ifndef STUDENT-FLOW-CONTROLLER_H_INCLUDED
#define STUDENT-FLOW-CONTROLLER_H_INCLUDED


#include <string>
#include <memory>
#include <vector>
using std::vector;
using std::string;
using std::shared_ptr;

#include "student.h"
#include "doctor.h"

namespace Faculty {
/*
 * Take care of flow for 1 student (e.g.show menu
 * / do operations for it)
 */
struct StudentFlowController {
  void DoSignUp();
  bool IsValidUser(string user_name, string password);
  /*
   * If logged in, this function take control
   * 	(e.g. show menu - do operations)..till user logout
   */
  void TakeControl(string user_name, string password);
  void ShowMainMenu();
  void ShowCourseMenu();
  void RegisterInCourse();
  void UnRegisterFromCourse();
  void SubmitCourseAssignment();
  void ListMyCourses();
  void ViewCourse();
  void ShowGradesReport();

  // Temporary variables
  shared_ptr<Student> current_student_;
  shared_ptr<Course> current_course_;
};

extern shared_ptr<StudentFlowController> gStudentFlowController;
}

#endif // STUDENT-FLOW-CONTROLLER_H_INCLUDED
