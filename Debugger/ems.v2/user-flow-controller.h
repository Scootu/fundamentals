#ifndef USER-FLOW-CONTROLLER_H_INCLUDED
#define USER-FLOW-CONTROLLER_H_INCLUDED


#include <string>
#include <memory>
#include <vector>
using std::vector;
using std::string;
using std::shared_ptr;

namespace Faculty {

struct UserFlowController {
  void ShowMainMenu();		// Major function to run the application
  void DoLogin();
  void DoSignUp();

};

// Global objects are not preferred. In future, learn singleton design pattern
extern shared_ptr<UserFlowController> gUserFlowController;

}

#endif // USER-FLOW-CONTROLLER_H_INCLUDED
