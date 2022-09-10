
#include "ResponsibleStudent.h"

void ResponsibleStudent::sendingMessage(vector<Student *> studentArray, const int size, string message)
{
	int i;
	for (i = 0; i < size; i++)
	{
		string newMessage = m_firstName + " " + m_lastName + ":" + message;
		studentArray[i]->setMessages(newMessage);
	}
}
