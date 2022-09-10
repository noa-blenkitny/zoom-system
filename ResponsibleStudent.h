#ifndef RESPONSIBLESTUDENT_H_
#define RESPONSIBLESTUDENT_H_

#include "Student.h"

class ResponsibleStudent : public Student
{
public:
	ResponsibleStudent(string firstName, string lastName, int id, int avg) : Student(firstName, lastName, id, avg){};
	virtual void sendingMessage(vector<Student *> studentArray, const int size, string message);
	virtual ~ResponsibleStudent(){};
	virtual void isCrying() const {};
	virtual void isWorking() const {};
	virtual void addStudentToLazyRoom(Room *room){};
	virtual void addStudentToWorkerRoom(Room *room){};
};

#endif /* RESPONSIBLESTUDENT_H_ */
