
#include "doctors-manager.h"

#include <iostream>

#include "helper.h"

namespace Faculty {

shared_ptr<DoctorsManager> gDoctorsManager(new DoctorsManager());

void DoctorsManager::AddDummyData() {
  vector<string> names = { "Ali", "Mostafa", "Hani", "Mohamed", "Ashraf", "Samy", "Morad", "Sayed", "Hussien" };

  for (int i = 1; i <= (int) names.size(); ++i) {
    shared_ptr<Doctor> doctor(new Doctor());

    doctor->user_name_ = "d" + Helper::ToString(i, 3);
    doctor->password_ = "d" + Helper::ToString(i, 3);
    doctor->name_ = names[i - 1];

    doctors_vec_.push_back(doctor);
  }
  // For teaching_courses_, it will be filled at CoursesManager::AddDummyRelationshipsData
}

shared_ptr<Doctor> DoctorsManager::GetUser(string user_name, string password) {
  for (auto doctor : doctors_vec_) {
    if (doctor->user_name_ == user_name && doctor->password_ == password)
      return doctor;
  }

  return nullptr;
}

void DoctorsManager::ShowDoctors() {
  for (auto doctor : doctors_vec_) {
    std::cout << "Doctor " << doctor->name_ << " is teaching " << doctor->teaching_courses_.size() << " courses.";

    if (doctor->teaching_courses_.size() > 0) {
      std::cout << " Courses Codes:";

      for (auto course : doctor->teaching_courses_)
        std::cout << " " << course->code_;
    }
    std::cout << "\n";
  }

  std::cout << "\n******************************************************************\n";
}

}
