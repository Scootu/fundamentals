#ifndef HOMEWORK2_H
#define HOMEWORK2_H

class CommunityMember {};

class Employee : public CommunityMember {};
class Student :  public CommunityMember {};
class Alumnus : public CommunityMember {};

class Faculty : public Employee {};
class Staff : public Employee {};

class Administrator : public Faculty {};
class Teacher : public Faculty {};

class AdministratorTeacher : public Administrator , public Teacher {};

#endif