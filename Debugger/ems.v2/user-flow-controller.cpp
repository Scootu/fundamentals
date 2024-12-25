
#include "user-flow-controller.h"

#include <iostream>
#include <cassert>
using std::cout;
using std::cin;

#include "helper.h"
#include "student-flow-controller.h"
#include "doctor-flow-controller.h"

namespace Faculty {

shared_ptr<UserFlowController> gUserFlowController(new UserFlowController());

void UserFlowController::ShowMainMenu()
{
  while(true)
  {
    cout<<"\n\nPlease make a choice:\n";
    cout<<"\t1 - Login\n";
    cout<<"\t2 - Sign up\n";
    cout<<"\t3 - Shutdown system\n";
    cout<<"\tEnter Choice: ";

    int option =  Helper::ReadInt(1, 3);

    if(option == 1)
      DoLogin();
    else if(option == 2)
      DoSignUp();
    else if(option == 3)
      break;
    else
      assert(false);  // Shouldn't happen or code bug!
  }
}


void UserFlowController::DoLogin()
{
  cout<<"\nPlease enter user name and password:\n";

  string username;
  string password;

  cout<<"User Name: ";
  cin>>username;

  cout<<"Password: ";
  cin>>password;

  if(gStudentFlowController->IsValidUser(username, password))
    gStudentFlowController->TakeControl(username, password);
  else if(gDoctorFlowController->IsValidUser(username, password))
    gDoctorFlowController->TakeControl(username, password);
  else
  {
    cout<<"ERROR: Invalid login data...Try again\n";
    DoLogin();
  }

  // If we are here, user made logout
}

void UserFlowController::DoSignUp()
{
  cout<<"Please enter user type: (1 - student), (2 - doctor):\n";
  int type = Helper::ReadInt(1, 2);

  if(type == 1)
    gStudentFlowController->DoSignUp();
  else
    assert(false);
}

}
