#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
#define MAX 10
#define SIZE 30
#define Ip_MAX 100

class person
{
private:
	char * name;
	char * email;
public:
	person();
	~person();

	person(char *, char *);
	//copy NAME and EMAIL into private member
	void copy(char * NAME, char * EMAIL);
	//compare the reference to private member
	bool compare(char * Name);
	//check if the private member is NULL or have not		//be allocated
	void display();
};



struct mess_node
{
	char * message;
	char * time;

	mess_node * next;
};



class mess
{
private:
	mess_node * head;
	
	//deallocate all the data
	void deallocate(mess_node *& head);

	//post message, get message and time from public
	//function
	bool post_mess(char * Message, char * Time, mess_node *& head);
	
	//display all messages for particular chat 
	//room
	bool display_all_mess(mess_node * head);
	
	//display all message contain particluar keyword
	bool display_key_mess(char * keyword, mess_node * head);

	//remove everything older than the Time which 
	//input from the client program
	bool remove_older(char * Time, mess_node *& head);

public:
	mess();
	~mess();
	
	//post message, get message and time from client
	//program
	bool post_mess(char * Message, char * Time);

	//display all messages for particular chat room
	bool display_all_mess();

	//display all message contain particluar keyword
	bool display_key_mess(char * keyword);

	//remove everything older than the Time which
	//come from the client program 
	bool remove_older(char * Time);
};



struct room_node
{
	char * name;	
	char * description;

	person * user;
	int NUM;
	mess mess_list;

	room_node * next;
};



class room
{
private:
	room_node * head;

	void deallo(room_node *& head);

	bool creat_room(char * Name, char * descrip, room_node *& head);

	bool show_all_room(room_node * head);

	bool post_mess_this_room(char * Room_name, char * Message, char * Time, room_node *& head);

	bool show_mess_this_room(char * Name, room_node * head);

	bool show_mess_keyword(char * key, room_node * head);

	bool insert_user(char * Room_name, person * User, int num, room_node * head);

	bool show_room_this_user(char * Name, room_node * head);

	bool remove_older_time(char * Time, room_node * head);
	
public:
	room();
	~room();

	//creat a new chat room 
	bool creat_room(char * Name, char * descrip);
	
	//show all room's name
	bool show_all_room();
	
	//post message to existing room
	bool post_mess_this_room(char * Room_name, char * Message, char * Time);

	//display all message in a particluar room
	//find the room by their name
	bool show_mess_this_room(char * Name);

	//display all the message that contain a particul
	//keyword, find them by keyword
	bool show_mess_keyword(char * Key);

	//insert new user to existing chat room
	//find room by their name
	bool insert_user(char * Room_name, person * User, int num);

	//display all the room that contain a particular
	//user, find the user by his name (assume 
	// nobody has the same name)
	bool show_room_this_user(char * Name);
	
	//remove everything older than particular time 
	//stamp, find and delete all the message by time
	bool remove_older_time(char * Time);

};


