#ifndef WORKERSTUDENT_H_
#define WORKERSTUDENT_H_
#include "Student.h"
class WorkerStudent : public Student
{
public:
	WorkerStudent(string firstName, string lastName, int id, int avg) : Student(firstName, lastName, id, avg){};
	virtual void isWorking() const;
	virtual ~WorkerStudent(){};
	virtual void isCrying() const {};
	virtual void sendingMessage(vector<Student *> studentArray, const int size, string message);
	virtual void addStudentToLazyRoom(Room *room){};
	virtual void addStudentToWorkerRoom(Room *room);
};
#endif /* WORKERSTUDENT_H_ */
