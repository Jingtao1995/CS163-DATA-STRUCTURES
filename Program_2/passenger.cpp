//Name: Jingtao Cheng
//Data: May 4 2017
//Course: CS 163
//PSU ID: 940067494

#include "passenger.h"

person::person()
{
    name = NULL;
    row_number = 0;
    seat_letter = '\0';
    boarding_number = 0;
}

person::~person()
{
    if(name)
        delete [] name;
        //delete seat_letter; 
}

bool person::copy_name(char * Name)
{
    if(Name)
    {
        name = new char[strlen(Name)+1];
        strcpy(name, Name);
        
    }
    else
        return false;
    if(name == NULL)
        return false;
    else
        return true;
}
bool person::copy_row(int Row_number)
{
    row_number = Row_number;
    return true;
}

bool person::copy_letter(char Seat_letter)
{
    seat_letter = Seat_letter;
    return true;
}

bool person::copy_boarding(int Boarding_number)
{
    boarding_number = Boarding_number;
    return true;
}
/*
bool person::copy_seat(char * Seat_number)
{
    if(Seat_number)
    {
        seat_number = new char[strlen(Seat_number)+1];
        strcpy(seat_number, Seat_number);
        
    }
    else
        return false;
    if(seat_number == NULL)
        return false;
    else
        return true;
}

bool person::copy_boarding(char * Boarding_number)
{
    if(Boarding_number)
    {
        boarding_number = new char[strlen(Boarding_number)+1];
        strcpy(boarding_number, Boarding_number);
        
    }
    else
        return false;
    if(boarding_number == NULL)
        return false;
    else
        return true;
}
*/
bool person::copy_pasger(char * Name, int row, char letter, int Boarding_number)
{
    if(Name)
    {
        name = new char[strlen(Name)+1];
        strcpy(name, Name);
        
    }
    else
        return false;
        
    row_number = row;
    
    seat_letter = letter;
    
    boarding_number = Boarding_number;

    if(name == NULL)
        return false;
    else
        return true;
}

void person::display()
{
    if(name)
    {
    cout<<"-----Name: "<<name<<endl<<"Seat Number: "
    <<row_number<<seat_letter<<endl<<"Boarding Number: "<<boarding_number<<endl;
    }
    else
        cout<<"NONE <-> ";
}

char * person::get_name()
{
    return name;
}

int person::get_row()
{
    return row_number;
}

char person::get_letter()
{
    return seat_letter;
}

int person::get_board()
{
    return boarding_number;
}
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