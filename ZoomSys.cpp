
#include "ZoomSys.h"

ZoomSys::ZoomSys(string path)
{
	studentNum = 0;
	fstream file;
	string line;
	file.open(path);
	while (file.good())
	{
		string word;
		getline(file, word);
		string firstname, lastname;
		int id, avg;
		char type;
		std::istringstream iss(word);
		iss >> firstname >> lastname >> id >> avg >> type;
		if (iss)
		{
			if (type == 'W')
			{
				try
				{
					Student *s = new WorkerStudent(firstname, lastname, id, avg);
					studentVec.push_back(s);
				}
				catch (bad_alloc &e) // memory problem
				{
					delete this;
					exit(-1);
				}
			}
			else if (type == 'L')
			{
				try
				{
					Student *s = new LazyStudent(firstname, lastname, id, avg);
					studentVec.push_back(s);
				}
				catch (bad_alloc &e) // memory problem
				{
					delete this;
					exit(-1);
				}
			}
			else
			{
				try
				{
					Student *s = new ResponsibleStudent(firstname, lastname, id, avg);
					studentVec.push_back(s);
				}
				catch (bad_alloc &e) // memory problem
				{
					delete this;
					exit(-1);
				}
			}
			studentNum++;
		}
	}
	file.close();
}
int ZoomSys::findStudentInSystem(int ID)
{
	int i;
	for (i = 0; i < studentNum; i++)
	{
		if (studentVec[i]->getID() == ID)
		{
			return i;
		}
	}
	throw idException();
}
void ZoomSys::checkStudentExist(int ID)
{
	int i;
	for (i = 0; i < studentNum; i++)
	{
		if (studentVec[i]->getID() == ID)
		{
			throw invalidDetails();
		}
	}
}
Room *ZoomSys::findRoomInSystem(int ID)
{
	map<int, Room *>::iterator iter = RoomsMap.find(ID);
	if (iter == RoomsMap.end() && ID != -1)
	{
		throw idException();
	}
	else
	{
		return iter->second;
	}
}
void ZoomSys::checkValidDetails(int id, int avg, char type)
{
	checkStudentExist(id);
	if (id < 0 || avg < 0 || avg > 100 || (type != 'R' && type != 'L' && type != 'W'))
	{
		throw invalidDetails();
	}
}
char ZoomSys::checkValidSplitType()
{
	char menuOption;
	cin >> menuOption;
	if (menuOption != '1' && menuOption != '2')
	{
		throw invalidDetails();
	}
	return menuOption;
}
Room *ZoomSys::checkValidRoom(int ID)
{
	map<int, Room *>::iterator iter = RoomsMap.find(ID);
	if (iter == RoomsMap.end())
	{
		throw idException();
	}
	else
	{
		return iter->second;
	}
}
void ZoomSys::addStudent()
{
	string firstname, lastname;
	int id, avg;
	char type;
	cout << "---Create Student---" << endl;
	cout << "First name:" << endl;
	cin >> firstname;
	cout << "Last name:" << endl;
	cin >> lastname;
	cout << "ID:" << endl;
	cin >> id;
	cout << "avg:" << endl;
	cin >> avg;
	cout << "Worker(W) or Lazy(L) or Responsible(R) Student?" << endl;
	cin >> type;
	try
	{
		checkValidDetails(id, avg, type);
		if (type == 'W')
		{
			try
			{
				Student *s = new WorkerStudent(firstname, lastname, id, avg);
				studentVec.push_back(s);
			}
			catch (bad_alloc &e) // memory problem
			{
				delete this;
				exit(-1);
			}
		}
		else if (type == 'L')
		{
			try
			{
				Student *s = new LazyStudent(firstname, lastname, id, avg);
				studentVec.push_back(s);
			}
			catch (bad_alloc &e) // memory problem
			{
				delete this;
				exit(-1);
			}
		}
		else
		{
			try
			{
				Student *s = new ResponsibleStudent(firstname, lastname, id, avg);
				studentVec.push_back(s);
			}
			catch (bad_alloc &e) // memory problem
			{
				delete this;
				exit(-1);
			}
		}
		studentNum++;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}
void ZoomSys::removeStudent()
{
	int id;
	cout << "---Remove Student---" << endl;
	cout << "Enter the id:" << endl;
	cin >> id;

	try
	{
		int index = findStudentInSystem(id);
		Student *s = studentVec[index];
		int roomNum = s->getRoomNum();
		if (roomNum == -1)
		{
			studentVec.erase(studentVec.begin() + index);
			delete s;
			s = nullptr;
			studentNum--;
		}
		else
		{
			RoomsMap[roomNum]->removeStudent(id, -1);
			studentVec.erase(studentVec.begin() + index);
			studentNum--;
			delete s;
			s = nullptr;
		}
	}
	catch (exception &c)
	{
		cout << c.what() << endl;
	}
}
void ZoomSys::assignStudent()
{
	int stuid, roomid;
	cout << "---Assign Student---" << endl;
	cout << "Enter student id:" << endl;
	cin >> stuid;
	cout << "Enter room id:" << endl;
	cin >> roomid;

	try
	{
		int index = findStudentInSystem(stuid);
		findRoomInSystem(roomid);
		Student *s = studentVec[index];
		int roomNum = s->getRoomNum();
		if (roomid == -1)
		{
			RoomsMap[roomNum]->removeStudent(stuid, -1);
			s->setRoom(nullptr);
		}
		else
		{
			if (roomNum == -1)
			{
				RoomsMap[roomid]->addToStandard(s);
			}
			else
			{
				RoomsMap[roomNum]->removeStudent(stuid, roomid);
				RoomsMap[roomid]->addToStandard(s);
			}
		}
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}
void ZoomSys::addRoom()
{
	try
	{
		Room *newRoom = new StandardRoom();
		RoomsMap[newRoom->getRoomID()] = newRoom;
		cout << "New room created" << endl;
	}
	catch (bad_alloc &e) // memory problem
	{
		delete this;
		exit(-1);
	}
}
void ZoomSys::splitRoom()
{
	cout << "---Split Room---" << endl;
	cout << "Room id:" << endl;
	int id;
	cin >> id;
	try
	{
		Room *room = checkValidRoom(id);
		room->getIsSplited();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		return;
	}
	try
	{
		cout << "1.Character split" << endl;
		cout << "2.Size split" << endl;
		char menuOption = checkValidSplitType();
		Room *room = checkValidRoom(id);
		switch (menuOption)
		{
		case '1':
		{
			try
			{
				Room *left = new WorkerRoom();
				Room *right = new LazyRoom();
				RoomsMap[left->getRoomID()] = left;
				RoomsMap[right->getRoomID()] = right;
				room->splitByChar(left, right);
			}
			catch (bad_alloc &e) // memory problem
			{
				delete this;
				exit(-1);
			}
			break;
		}
		case '2':
		{
			try
			{
				Room *left2 = new StandardRoom();
				Room *right2 = new StandardRoom();
				RoomsMap[left2->getRoomID()] = left2;
				RoomsMap[right2->getRoomID()] = right2;
				room->splitByNum(left2, right2);
			}
			catch (bad_alloc &e) // memory problem
			{
				delete this;
				exit(-1);
			}
			break;
		}
		}
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}

void ZoomSys::removeRoom()
{
	cout << "---Remove Room---" << endl;
	cout << "Enter room id:" << endl;
	int id;
	cin >> id;
	try
	{
		Room *room = checkValidRoom(id);
		stack<int> roomsID;
		stack<Room *> rooms;
		room->roomToRemove(rooms, roomsID);
		room->removeRoom();
		while (!roomsID.empty())
		{

			int index = roomsID.top();
			roomsID.pop();
			RoomsMap.erase(index);
		}
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		return;
	}
}

void ZoomSys::work()
{
	int id;
	cout << "Enter the room you want to work:" << endl;
	cin >> id;
	try
	{
		Room *room = checkValidRoom(id);
		room->RoomToWork();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}
void ZoomSys::sendMessage()
{
	int id;
	string message;
	cout << "Enter the id:" << endl;
	cin >> id;
	try
	{
		findStudentInSystem(id);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		return;
	}
	cout << "Enter the message:" << endl;
	getline(cin.ignore(), message);
	// cin >> message;
	try
	{
		int index = findStudentInSystem(id);
		Student *student = studentVec[index];
		if (student->getRoomNum() == -1)
		{
			vector<Student *> temp;
			student->sendingMessage(temp, 0, message);
		}
		else
		{
			Room *room = findRoomInSystem(student->getRoomNum());
			room->roomSendingMessage(student, message);
		}
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}
void ZoomSys::printRooms()
{
	map<int, Room *>::iterator it;
	for (it = RoomsMap.begin(); it != RoomsMap.end(); ++it)
	{
		it->second->printRoom();
	}
}
void ZoomSys::printStudents()
{
	cout << "First name, Last Name, ID, Avg, Room ID" << endl;
	int i;
	for (i = 0; i < studentNum; i++)
	{
		studentVec[i]->printStudentWithoutMessages();
	}
}
void ZoomSys::printStudentDetails()
{
	int id;
	cout << "Enter student id:" << endl;
	cin >> id;
	try
	{
		int index = findStudentInSystem(id);
		studentVec[index]->printStudent();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}
ZoomSys::~ZoomSys()
{
	map<int, Room *>::iterator it;
	for (it = RoomsMap.begin(); it != RoomsMap.end(); ++it)
	{
		delete it->second;
	}
	vector<Student *>::iterator iterStu;
	for (iterStu = studentVec.begin(); iterStu != studentVec.end(); ++iterStu)
	{
		delete *iterStu;
	}
}
