
#include "Room.h"
#include "Error.h"
int Room::roomNum = 0;
Room::Room()
{
	mRoomId = roomNum++;
	isSplited = 0;
	studentsNum = 0;
	vector<Student *> mStudents;
	leftRoom = nullptr;
	rightRoom = nullptr;
	parent = nullptr;
}

bool Room::removeStudent(int id, int newRoomNum)
{
	int i;
	for (i = 0; i < studentsNum; i++)
	{
		if (mStudents[i]->getID() == id)
		{
			mStudents[i]->setRoomId(newRoomNum);
			mStudents.erase(mStudents.begin() + i);
			studentsNum--;
			return true;
		}
	}
	return false;
}
bool Room::removeWhileSplit(int id)
{
	int i;
	for (i = 0; i < this->studentsNum; i++)
	{
		if (mStudents[i] != nullptr)
		{
			if (mStudents[i]->getID() == id)
			{
				mStudents[i] = nullptr;
				return true;
			}
		}
	}
	return false;
}

void Room::splitByNum(Room *left, Room *right)
{
	vector<Student *> temp;
	if (this->isSplited == 0)
	{
		int i;
		for (i = 0; i < this->studentsNum; i++)
		{
			if (i < this->studentsNum / 2)
			{
				left->addToStandard(mStudents[i]);
			}
			else
			{
				right->addToStandard(mStudents[i]);
			}
		}
		this->leftRoom = left;
		this->rightRoom = right;
		left->parent = this;
		right->parent = this;
		this->isSplited = 1;
		this->mStudents = temp;
		this->studentsNum = 0;
	}
}

void Room::splitByChar(Room *left, Room *right)
{
	vector<Student *> temp;
	if (this->isSplited == 0)
	{
		int i;
		for (i = 0; i < this->studentsNum; i++)
		{
			if (mStudents[i] != nullptr)
			{
				left->addToWorker(mStudents[i]);
			}
			if (mStudents[i] != nullptr)
			{
				right->addToLazy(mStudents[i]);
			}
			if (mStudents[i] != nullptr)
			{
				temp.push_back(mStudents[i]);
			}
		}

		this->leftRoom = left;
		this->rightRoom = right;
		left->parent = this;
		right->parent = this;
		this->isSplited = 1;
		this->mStudents = temp;
		this->studentsNum = temp.size();
	}
}

void Room::removeRoom()
{
	if (this->leftRoom != nullptr)
	{
		this->leftRoom->removeRoom();
	}
	if (this->rightRoom != nullptr)
	{
		this->rightRoom->removeRoom();
	}
	int i;
	if (this->parent == nullptr)
	{
		for (i = 0; i < this->studentsNum; i++)
		{
			mStudents[i]->setRoomId(-1);
			mStudents[i]->setRoom(nullptr);
			mStudents[i]->isCrying();
		}
	}
	else
	{
		for (i = 0; i < this->studentsNum; i++)
		{
			this->parent->addToStandard(mStudents[i]);
			mStudents[i]->isCrying();
		}
		if (this->parent->rightRoom == this)
		{
			this->parent->rightRoom = nullptr;
		}
		if (this->parent->leftRoom == this)
		{
			this->parent->leftRoom = nullptr;
		}
	}
	delete this;
}
Room::~Room()
{
}
void Room::printRoom()
{
	cout << "room id:" << this->mRoomId << ", students:"
		 << this->studentsNum << endl;
}

void Room::getIsSplited() const
{
	if (this->isSplited == 1)
		throw splitPermissions();
}
void Room::addToStandard(Student *newStudent)
{
	this->mStudents.push_back(newStudent);
	newStudent->setRoomId(this->mRoomId);
	newStudent->setRoom(this);
	studentsNum++;
}
void Room::RoomToWork() const
{
	int i;
	for (i = 0; i < studentsNum; i++)
	{
		mStudents[i]->isWorking();
	}
}
void Room::roomSendingMessage(Student *student, string message)
{
	student->sendingMessage(mStudents, studentsNum, message);
}

void Room::roomToRemove(stack<Room *> &rooms,
						stack<int> &roomID)
{
	rooms.push(this);
	while (!rooms.empty())
	{
		Room *curr = rooms.top();
		rooms.pop();
		roomID.push(curr->mRoomId);
		if (curr->leftRoom)
		{
			rooms.push(curr->leftRoom);
		}
		if (curr->rightRoom)
		{
			rooms.push(curr->rightRoom);
		}
	}
}
