#include "WorkerRoom.h"

void WorkerRoom::addToWorker(Student *newStudent)
{
	newStudent->addStudentToWorkerRoom(this);
}
