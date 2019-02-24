//Name: Jingtao Cheng
//Data: May 4 2017
//Course: CS 163
//PSU ID: 940067494

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class person
{	
public:
	person();       //constructor
	~person();      //destructor
	void display();     //display passenger's info
	bool copy_name(char *);        //make deep copy from data
    bool copy_row(int);
    bool copy_letter(char);
    bool copy_boarding(int);

	bool copy_pasger(char *, int , char, int);
	
	char * get_name();
	int get_row();
	char get_letter();
	int get_board();
private:
	char * name;
	int  row_number;
	char seat_letter;
	int boarding_number;
	
	
};

bool again();