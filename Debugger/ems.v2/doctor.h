#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED
namespace Faculty {
struct Course;
struct Doctor {
  string user_name_;
  string password_;
  string name_;

  vector<shared_ptr<Course>> teaching_courses_;
};
}
#endif // DOCTOR_H_INCLUDED
