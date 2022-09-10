#ifndef WORKERROOM_H_
#define WORKERROOM_H_

#include "Room.h"

class WorkerRoom : public Room
{
public:
	WorkerRoom() : Room(){};
	virtual void addToLazy(Student *newStudent){};
	virtual void addToWorker(Student *newStudent);
	virtual ~WorkerRoom(){};
};

#endif /* WORKERROOM_H_ */
