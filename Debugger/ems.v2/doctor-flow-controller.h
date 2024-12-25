#ifndef DOCTOR-FLOW-CONTROLLER_H_INCLUDED
#define DOCTOR-FLOW-CONTROLLER_H_INCLUDED



#include <string>
#include <memory>
#include <vector>
using std::vector;
using std::string;
using std::shared_ptr;

#include "student.h"
#include "doctor.h"

namespace Faculty {

struct DoctorsFlowController {
  bool IsValidUser(string user_name, string password);
  void TakeControl(string user_name, string password);
  void ShowMainMenu();
  void ShowCoureOperationsMenu();
  void ShowAssignmentOperationsMenu();
  void ShowAssignmentSolutionOperationsMenu();

  shared_ptr<Doctor> current_doctor_;
};

extern shared_ptr<DoctorsFlowController> gDoctorFlowController;


}

#endif // DOCTOR-FLOW-CONTROLLER_H_INCLUDED
