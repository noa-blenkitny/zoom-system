#include "LazyRoom.h"

void LazyRoom::addToLazy(Student *newStudent)
{
	newStudent->addStudentToLazyRoom(this);
}
