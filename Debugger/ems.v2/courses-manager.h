
#ifndef COURSES_MANAGER_H_
#define COURSES_MANAGER_H_

#include <string>
#include <vector>
#include <memory>
using std::vector;
using std::string;
using std::shared_ptr;

#include "course.h"

namespace Faculty {

struct CoursesManager {
	void AddCourse();
	void ShowCourses();
	void AddDummyData();

	/*
	 * Return all courses, except the given ones.
	 */
	vector<shared_ptr<Course>> GetComplimentCourses(vector<shared_ptr<Course>> courses);

	/*
	 * There are circular relationships (course has students and students has course...we can't add all dummy data in same time).
	 *
	 * So we build them in a way that breaks the cycle...we also fix through that the dependent data
	 */
	void AddDummyRelationshipsData();

	vector<shared_ptr<Course>> courses_;
};

extern shared_ptr<CoursesManager> gCoursesManager;

}

#endif /* COURSES_MANAGER_H_ */