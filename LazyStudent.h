#ifndef LAZYSTUDENT_H_
#define LAZYSTUDENT_H_

#include "Student.h"
#include "Error.h"
class LazyStudent : public Student
{
public:
	LazyStudent(string firstName, string lastName, int id, int avg) : Student(firstName, lastName, id, avg){};
	virtual void isCrying() const;
	virtual ~LazyStudent(){};
	virtual void isWorking() const {};
	virtual void sendingMessage(vector<Student *> studentArray, const int size, string message);
	virtual void addStudentToLazyRoom(Room *room);
	virtual void addStudentToWorkerRoom(Room *room){};
};

#endif /* LAZYSTUDENT_H_ */
