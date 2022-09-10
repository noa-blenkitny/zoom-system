#ifndef LAZYROOM_H_
#define LAZYROOM_H_

#include "Room.h"

class LazyRoom : public Room
{
public:
	LazyRoom() : Room(){};
	virtual void addToLazy(Student *newStudent);
	virtual void addToWorker(Student *newStudent){};
	virtual ~LazyRoom(){};
};

#endif /* LAZYROOM_H_ */
