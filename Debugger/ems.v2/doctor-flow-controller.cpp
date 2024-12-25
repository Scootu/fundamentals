
#include "doctor-flow-controller.h"
#include "doctors-manager.h"

#include <iostream>
#include <cassert>
using std::cout;
using std::cin;

#include "helper.h"

// TODO

namespace Faculty {

shared_ptr<DoctorsFlowController> gDoctorFlowController(new DoctorsFlowController());

bool DoctorsFlowController::IsValidUser(string user_name, string password) {
  return gDoctorsManager->GetUser(user_name, password) != nullptr;
}

void DoctorsFlowController::TakeControl(string user_name, string password) {
  current_doctor_ = gDoctorsManager->GetUser(user_name, password);

  cout << "\n\nWelcomme Doctor " << current_doctor_->name_ << ". You are logged in\n";

  cout << "\nTODO - This code block need to be implemented";

  exit(1);
}

void DoctorsFlowController::ShowMainMenu() {
  vector<string> menu = { "List Courses", "Create course", "View Course", "Log out" };

  int choice = Helper::RunMenu(menu);
}

// Run it when user selects View Course...when finish..should back to the Main menu
void DoctorsFlowController::ShowCoureOperationsMenu() {
  vector<string> menu = { "Add TAs", "List Assignments", "Create Assignment", "View Assignment", "Back" };

  int choice = Helper::RunMenu(menu);
}

void DoctorsFlowController::ShowAssignmentOperationsMenu() {
  vector<string> menu = { "Show Info", "Show Grades Report", "List Solutions", "View Solution", "Back" };

  int choice = Helper::RunMenu(menu);
}

void DoctorsFlowController::ShowAssignmentSolutionOperationsMenu() {
  vector<string> menu = { "Show Info", "Set Grade", "Set a Comment", "Back" };

  int choice = Helper::RunMenu(menu);
}

}
