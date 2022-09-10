#include "WorkerStudent.h"
#include "Room.h"
#include "Error.h"
void WorkerStudent::isWorking() const
{
	cout << m_firstName << " " << m_lastName << " is working" << endl;
}
void WorkerStudent::sendingMessage(vector<Student *> studentArray, const int size, string message)
{
	throw studentPermissions();
}
void WorkerStudent::addStudentToWorkerRoom(Room *room)
{
	this->m_room->removeWhileSplit(this->m_id);
	addStudentToStandardRoom(room);
}
