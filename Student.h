#ifndef STUDENT_H_
#define STUDENT_H_
#include <string.h>
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Room;

class Student
{
protected:
	string m_firstName;
	string m_lastName;
	int m_id;
	int m_avg;
	vector<string> messages;
	int messageNum;
	int m_roomNum;
	Room *m_room;

public:
	Student(string firstName, string lastName, int id, int avg);
	void printStudent() const;
	virtual void isCrying() const = 0;
	virtual void isWorking() const = 0;
	virtual void sendingMessage(vector<Student *> studentArray, const int size, string message) = 0; // number of student in the room
	int getID() const { return this->m_id; };
	int getRoomNum() const { return this->m_roomNum; };
	int getMessageNum() const { return this->messageNum; };
	void setMessageNum(int newNum) { messageNum = newNum; };
	vector<string> getMessages() const { return messages; };
	// first const - can't change the content , can change the address. second cost - can't change the address, can change the content
	void setMessages(string newMessage);
	void setRoom(Room *newRoom) { this->m_room = newRoom; };
	void setRoomId(int newId) { this->m_roomNum = newId; };
	virtual ~Student();
	virtual void addStudentToLazyRoom(Room *room) = 0;
	virtual void addStudentToWorkerRoom(Room *room) = 0;
	void addStudentToStandardRoom(Room *room);
	void printStudentWithoutMessages() const;
};

#endif /* STUDENT_H_ */
