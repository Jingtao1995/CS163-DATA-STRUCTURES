/**************************************/
/*Fenting Lin CS163 Program#2**********/
/*This program is a fictional delivery*/
/**************************************/

#include "package.h"

/***********************************/
/*The constructor for Package class*/
/***********************************/

Package::Package()
{
    sender = NULL;
    recipient = NULL;
    size_package = 0;
}

/***********************************/
/*The destructor for Package class*/
/***********************************/

Package::~Package()
{
    if(sender)
	delete [] sender;
    if(recipient)
	delete [] recipient;
}

/*****************************/
/*The copy_package is used to*/
/*make the deep copy the data*/
/*****************************/

int Package::copy_package(char * i_sender, char * i_recipient, int i_size_package)
{
    if(i_sender)
    {
	sender = new char[strlen(i_sender) + 1];
	strcpy(sender, i_sender);
    }

    if(i_recipient)
    {
	recipient = new char[strlen(i_recipient) + 1];
	strcpy(recipient, i_recipient);
    }
    
    if(i_size_package)
	size_package = i_size_package;
    
    if(sender == NULL || recipient == NULL || size_package == 0)
	return 0;
    else
	return 1;
}

/***********************************/
/*The display function is used to***/
/*display one package's information*/
/***********************************/

void Package::display()
{
    cout<<"Sender: "<<sender<<endl
	<<"Recipient: "<<recipient<<endl
	<<"Size of package: "<<size_package<<endl<<endl;
}

/********************************************/
/*The again function is used to**************/
/*ask user whether they want do again or not*/
/********************************************/

bool again()
{
    char response;

    cout<<"Again? Y/N";
    cin>>response;
    cin.ignore(100, '\n');

    if(response == 'Y' || response == 'y')
	return true;
    else
	return false;
}
