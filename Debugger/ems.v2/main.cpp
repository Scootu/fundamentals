#include <iostream>


#include "courses-manager.h"
#include "doctors-manager.h"
#include "students-manager.h"
#include "user-flow-controller.h"

using std::cout;

using Faculty::gCoursesManager;


void GenerateRandomData() {
	// Generate system users
	Faculty::gStudentsManager->AddDummyData();
	Faculty::gDoctorsManager->AddDummyData();

	gCoursesManager->AddDummyData();

	// Connect the objects
	gCoursesManager->AddDummyRelationshipsData();
}


int main()
{
    GenerateRandomData();

    Faculty::gStudentsManager->ShowStudents();
	Faculty::gDoctorsManager->ShowDoctors();
	Faculty::gCoursesManager->ShowCourses();

	Faculty::gUserFlowController->ShowMainMenu();
    return 0;
}
