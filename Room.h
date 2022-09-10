
#ifndef ROOM_H_
#define ROOM_H_
#include "ResponsibleStudent.h"
#include "WorkerStudent.h"
#include "LazyStudent.h"
#include <string.h>
#include <vector>
#include <stack>

class Room
{
protected:
	int mRoomId;
	static int roomNum;
	int isSplited;
	int studentsNum;
	vector<Student *> mStudents;
	Room *leftRoom;
	Room *rightRoom;
	Room *parent;

public:
	Room();
	// uses shallow copy of student
	virtual void addToLazy(Student *newStudent) = 0;
	virtual void addToWorker(Student *newStudent) = 0;
	void addToStandard(Student *newStudent);
	bool removeStudent(int id, int newRoomNum);
	bool removeWhileSplit(int id);
	void splitByNum(Room *left, Room *right);
	void splitByChar(Room *left, Room *right);
	vector<Student *> getStudent() const { return this->mStudents; };
	virtual ~Room();
	void printRoom();
	Room *getLeftRoom() const { return this->leftRoom; };
	Room *getRightRoom() const { return this->rightRoom; };
	Room *getParentRoom() const { return this->parent; };
	void setStudents(vector<Student *> students) { this->mStudents = students; };
	int getStudentNum() const { return this->studentsNum; };
	int getRoomID() const { return this->mRoomId; };
	void getIsSplited() const;
	void RoomToWork() const;
	void roomSendingMessage(Student *student, string message);
	void roomToRemove(stack<Room *> &rooms, stack<int> &roomID);
	void removeRoom();
};

#endif /* ROOM_H_ */
