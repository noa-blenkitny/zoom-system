#ifndef ZOOMSYS_H_
#define ZOOMSYS_H_
#include "LazyRoom.h"
#include "WorkerRoom.h"
#include "StandardRoom.h"
#include "LazyStudent.h"
#include "ResponsibleStudent.h"
#include "WorkerStudent.h"
#include "Error.h"
#include <fstream>
#include <iostream>
using namespace std;
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class ZoomSys
{
private:
	vector<Student *> studentVec;
	map<int, Room *> RoomsMap;
	int studentNum;

public:
	ZoomSys(string path);
	void addStudent();
	void removeStudent();
	void assignStudent();
	void addRoom();
	void splitRoom();
	void removeRoom();
	void work();
	void sendMessage();
	void printRooms();
	void printStudents();
	void printStudentDetails();
	int findStudentInSystem(int ID);
	Room *findRoomInSystem(int ID);
	void checkValidDetails(int id, int avg, char type);
	char checkValidSplitType();
	void checkStudentExist(int ID);
	Room *checkValidRoom(int ID);
	virtual ~ZoomSys();
};

#endif /* ZOOMSYS_H_ */
