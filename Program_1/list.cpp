#include "list.h"


//class person function declaration

person::person()
{
	name = NULL;
	email = NULL;	
}

person::~person()
{
	if(name != NULL)
		delete [] name;
	if(email != NULL)
		delete [] email;
	email = NULL;
	name = NULL;
}

person::person(char * Name, char * Email)
{
	name = new char[strlen(Name)+1];
	email= new char[strlen(Email)+1];
	strcpy(name,Name);
	strcpy(email,Email);
}



bool person::compare(char * Name)
{
	if(!strcmp(name,Name))
		return true;
	return false;
}

//class message function definition

mess::mess()
{
	head = NULL;
}

mess::~mess()
{	
	//deallocate(head);
}

//deallocate all the data
void mess::deallocate(mess_node *& head)
{
	if(!head)
		return;
	if(head->message != NULL)
		delete [] head->message;
	if(head->time != NULL)
		delete [] head->time;
	mess_node * temp = head;
	head = head -> next;
	delete temp;
	temp = NULL;
	return deallocate(head->next);
}

//definition of class room

room::room()
{
	head = NULL;
	//head->user = new person[SIZE];
}

room::~room()
{
	//deallo(head);
}

void room::deallo(room_node *& head)
{
	if(!head)
		return;
	if(head->name != NULL)
	{
		delete [] head->name;
		head->name = NULL;
	}
	if(head->description != NULL)
	{
		delete [] head->description;
		head->description = NULL;
	}
	if(head->user != NULL)
	{
		delete [] head->user;
		head->user = NULL;
	}
	room_node * temp = head;
	head = head -> next;
	delete temp;
	temp = NULL;
	return deallo(head->next);
}

// add new chat room

bool room::creat_room(char * Name, char * descrip)
{
	return creat_room(Name, descrip, head);
}

bool room::creat_room(char * Name, char * descrip, room_node *& head)
{
	if(!head)
	{
		head = new room_node;
		head->name = new char[strlen(Name)+1];
		strcpy(head->name,Name);
		head->description = new char[strlen(descrip)+1];
		strcpy(head->description,descrip);
		return true;
	}
	return creat_room(Name, descrip, head->next);
}

//show all room's name

bool room::show_all_room()
{
	if(!head)
		return false;
	return show_all_room(head);
}

bool room::show_all_room(room_node * head)
{
	if(!head)
		return false;
	cout<<"Room { "<<head->name<<" };"<<endl;
	return show_all_room(head->next);
}
//post message

bool mess::post_mess(char * Message, char * Time)
{
	if(!Message||!Time)
		return false;
	return post_mess(Message, Time, head);
}

bool mess::post_mess(char * Message, char * Time, mess_node *& head)
{
	mess_node * temp = new mess_node;
	temp -> next = head;
	head = temp;

	head->message = new char[strlen(Message)+1];
	strcpy(head->message, Message);

	head->time = new char[strlen(Time)+1];
	strcpy(head->time, Time);
	return true;
}

bool room::post_mess_this_room(char * Room_name, char * Message, char * Time)
{
	if(!head)
		return false;
	return post_mess_this_room(Room_name, Message, Time, head);
}

bool room::post_mess_this_room(char * Room_name, char * Message, char * Time, room_node *& head)
{
	if(!head)
		return false;
	if(!strcmp(head->name, Room_name))
	{
		if(head->mess_list.post_mess(Message, Time))
			return true;
		return false;
	}
	return post_mess_this_room(Room_name, Message, Time, head->next);
}

//display all message for particular chat room

bool mess::display_all_mess()
{
	if(!head)
	{	
		cout<<"!!!!!!!";	
		return false;
	}
	return display_all_mess(head);
}

bool mess::display_all_mess(mess_node * head)
{
	if(!head)
	{
		//cout<<"~~~~~~~";
		return false;
	}
	cout<<"Mess from TIME: "<<head->time<<"."<<endl;
	cout<<head->message<<endl;
	return display_all_mess(head->next)+true;
}

bool room::show_mess_this_room(char * Name)
{
	if(!head)
		return false;
	return show_mess_this_room(Name, head);
}

bool room::show_mess_this_room(char * Name, room_node * head)
{
	if(!head)
		return false;
	if(!strcmp(head -> name, Name))
	{
		head -> mess_list.display_all_mess();
			return show_mess_this_room(Name, head->next)+true;
	}
	return show_mess_this_room(Name, head->next);
}

//display all message contain particular keyword

bool mess::display_key_mess(char * keyword)
{
	if(!head)
		return false;
	return display_key_mess(keyword, head);
}

bool mess::display_key_mess(char * keyword, mess_node * head)
{
	if(!head)
		return false;
	char * same_start = new char[strlen(head->message)+1];
	same_start = strstr(head -> message,keyword);
	if(same_start)
	{
		cout<<"Time: "<<head->time<<endl;
		cout<<"Same as:"<<same_start<<endl;
		return true;
	}
	return display_key_mess(keyword, head->next);
}

bool room::show_mess_keyword(char * key)
{
	if(!head)
		return false;
	return show_mess_keyword(key, head);
}

bool room::show_mess_keyword(char * key, room_node * head)
{
	if(!head)
		return false;
	if(head->mess_list.display_key_mess(key))
		return show_mess_keyword(key, head->next)+true;
	return show_mess_keyword(key, head->next);
}


//Insert User into room, using dynamic array.

//used to check if the reference passed in or not
void person::display()
{
	if(name)
		cout<<name<<endl;
	else
		cout<<"xxxxxxxxxxxxxxxx"<<endl;
}

void person::copy(char * NAME, char * EMAIL)
{
	if(!NAME||!EMAIL)
		return;
	if(name)
		delete [] name;
	if(email)
		delete [] name;
	char * name = new char[strlen(NAME)+1];
	char * email = new char[strlen(EMAIL)+1];
	strcpy(name,NAME);
	strcpy(email,EMAIL);
	cout<<"***********"<<name<<"***********"<<endl;
}

bool room::insert_user(char * Room_name, person * User, int num)
{
	if(!head)
		return false;
	return insert_user(Room_name, User, num, head);
}

bool room::insert_user(char * Room_name, person * User,int num, room_node * head)
{
	if(!head)
		return false;
	head->NUM = num;
	
	if(!strcmp(Room_name, head->name))
	{
		//cout<<"111";
		User[0].display();
		//cout<<"222";
		head->user = new person[num];
		//cout<<"333";
		for(int i=0;i<num;i++)
		{
			head->user[i] = User[i];
		}

		//cout<<"-------------"<<endl;
		//head->user = User;
		head->user[0].display();
		
		return insert_user(Room_name,User,num,head->next)+true;
	}
	return insert_user(Room_name, User, num, head->next);
}

// display all room has particular user

bool room::show_room_this_user(char * Name)
{
	if(!head||!Name)
	{
		return false;
	}
	return show_room_this_user(Name, head);
}


bool room::show_room_this_user(char * Name, room_node * head)
{
	if(!head)
	{
		return false;
	}
	if(!head->NUM)
	{
		return false;
	}
	for(int i=0; i<head->NUM; i++)
	{
		if(!head->user)
			return false;
		//if(!head->user[i])
		//	return false;
		//if(head->user[i].compare(Name))
		{
			cout<<"Room { "<<head->name<<" };"<<endl;
			return show_room_this_user(Name, head->next)+true;
		}
	}
	return show_room_this_user(Name, head->next);
}

//remove everything older than a specific time

bool mess::remove_older(char * Time)
{
	if(!head)
	{
		cout<<"No message";
		return false;
	}
	return remove_older(Time, head);
}

bool mess::remove_older(char * Time, mess_node *& head)
{
	if(!head)
	{
		cout<<"!!!!!"<<endl;
		return false;
	}
	if(head->time < Time)
	{
		if(!head->next)
		{
			delete head;
			head = NULL;
			return true;
		}
		else
		{
			mess_node * temp = head;
			head = head -> next;
			delete temp;
			temp = NULL;
			//cout<<"!"<<endl;
			return remove_older(Time,head)+true;
		}
	}
	else
		return remove_older(Time,head->next);
}

bool room::remove_older_time(char * Time)
{
	if(!head)
	{	
		cout<<"No node";
		return false;
	}
	return remove_older_time(Time,head);
}

bool room::remove_older_time(char * Time, room_node * head)
{
	if(!head)
		return false;
	if(head->mess_list.remove_older(Time))
		return remove_older_time(Time,head->next)+true;
	else
		return remove_older_time(Time, head->next);
}
