
#ifndef ERROR_H_
#define ERROR_H_
#include <iostream>
#include <exception>
using namespace std;

class idException : public exception
{
public:
	virtual const char *what() const throw() { return "Id doesn't exists"; };
};

class studentPermissions : public exception
{
public:
	virtual const char *what() const throw() { return "This student don't have permission"; };
};

class splitPermissions : public exception
{
public:
	virtual const char *what() const throw() { return "This room was split before"; };
};

class invalidDetails : public exception
{
public:
	virtual const char *what() const throw() { return "Please enter valid details"; };
};

#endif /* ERROR_H_ */
