#include "LazyStudent.h"
#include "Room.h"

void LazyStudent::isCrying() const
{
	cout << m_firstName << " " << m_lastName << " is crying" << endl;
}
void LazyStudent::sendingMessage(vector<Student *> studentArray, const int size, string message)
{
	throw studentPermissions();
}
void LazyStudent::addStudentToLazyRoom(Room *room)
{
	this->m_room->removeWhileSplit(this->m_id);
	addStudentToStandardRoom(room);
}
