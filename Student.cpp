
#include "Student.h"
#include "Room.h"
Student::Student(string firstName, string lastName, int id, int avg)
{
	m_firstName = firstName;
	m_lastName = lastName;
	m_id = id;
	m_avg = avg;
	vector<string> messages;
	messageNum = 0;
	m_roomNum = -1;
	m_room = nullptr;
}
void Student::printStudent() const
{
	cout << m_firstName << " " << m_lastName << " " << m_id << " " << m_avg << " " << m_roomNum << endl;
	cout << "---Messages---" << endl;
	int i;
	for (i = 0; i < messageNum; i++)
	{
		cout << messages[i] << endl;
	}
}
void Student::setMessages(string newMessage)
{
	this->messages.push_back(newMessage);
	this->messageNum += 1;
}
Student::~Student()
{
}
void Student::addStudentToStandardRoom(Room *room)
{
	room->addToStandard(this);
}
void Student::printStudentWithoutMessages() const
{
	cout << m_firstName << " " << m_lastName << " " << m_id << " " << m_avg << " " << m_roomNum << endl;
}
