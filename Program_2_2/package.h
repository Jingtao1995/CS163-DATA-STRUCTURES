/**************************************/
/*Fenting Lin CS163 Program#2**********/
/*This program is a fictional delivery*/
/**************************************/

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

class Package
{
    public:
	Package();				//Constructor
	~Package();				//Destructor
	void display();				//To display one package's info
	int copy_package(char *, char *, int);	//To make deep copy form data
    private:
	char * sender;				
	char * recipient;
	int size_package;
};

bool again();
