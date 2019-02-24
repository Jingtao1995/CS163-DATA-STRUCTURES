#include "list.h"
int main()
{
	
	int operater = 0;
	room chat_room;
	int AGAIN = 0;
	person * USER;

	//-----------------Note that
	do{
 
	//======================================================================================================
	
	cout<<"#1. Creat a chat room"<<endl;
	cout<<"#2. Creat a new user"<<endl;
	cout<<"#3. Post messages in your favorite chat room"<<endl;
	cout<<"#4. Display all messages of your favorite chat room"<<endl;
	cout<<"#5. Display all messages contain particular keyword"<<endl;
	cout<<"#6. Display all rooms contain particular user"<<endl;
	cout<<"#7. Remove all the things older than particular time"<<endl;
	
	
	//======================================================================================================
	
	//do{

		cout<<"-------------Please input your choice------------"<<endl;
		cin >> operater;
		cin.ignore();
		switch (operater)
		{
			case 1 :
			{
				char Name[SIZE];
				char Descrip[SIZE];
	
				cout<<"Input room's name: ";
				cin.get(Name,SIZE,'\n');
				//cin>>Name;
				cin.ignore();
				cout<<endl;
				cout<<"Input room's description: ";
				cin.get(Descrip,SIZE,'\n');
				//cin>>Descrip;
				cin.ignore();
				cout<<endl;
				if(chat_room.creat_room(Name, Descrip))
					cout<<"SUCCEESE"<<endl;
				else
					cout<<"FAIL"<<endl;
				memset(Name,0,sizeof(Name));
				memset(Descrip,0,sizeof(Descrip));
				
				break;
			}
			case 2 :
			{
				cout<<"How many user do you want?(Must smaller than 10) "<<endl;
				int seq = 0;
				cin>>seq;
				cin.ignore();
				cout<<"Which room do you want to login?"<<endl;
				
				char Name_room[SIZE];
				cin>>Name_room;
				//cin.get(Name_room,SIZE,'\n');
				cin.ignore();
				
				char Email[SIZE];
				char Name_user[SIZE];
				
				USER = new person[seq];

				for(int i=0; i<seq; i++)
				{
					cout<<"Input your name: ";
					cin>>Name_user;
					//cin.get(Name_user,SIZE,'\n');
					cin.ignore();
					cout<<endl;
					//cout<<Name_user<<endl;
					cout<<"Input your E-mail: ";
					cin>>Email;
					//cin.get(Email,SIZE,'\n');
					cin.ignore();
					cout<<endl;

					USER[i].copy(Name_user,Email);
					
				}
//-----------------Note that
				//USER[0].display();
				
				if(chat_room.insert_user(Name_room, USER, seq ))
					cout<<"SUCCESS"<<endl;
				else
					cout<<"FAIL"<<endl;		
				
				break;
			}
			case 3 :
			{
				int again = 0;
				char Name[SIZE];
				cout<<"Which room do you want to post message?"<<endl;
				//cin>>Name;
				cin.get(Name,SIZE,'\n');
				cin.ignore();
				do
				{
					char Message[SIZE];
					char Time[SIZE];
					cout<<"Time :";
					cin.get(Time,SIZE,'\n');
					//cin>>Time;
					cin.ignore();
					cout<<"Mess :";
					cin.get(Message,SIZE,'\n');
					//cin>>Message;
					cin.ignore();
					cout<<endl;

					if(chat_room.post_mess_this_room(Name,Message,Time))
						cout<<"GOOD"<<endl;
					else
						cout<<"SORRY"<<endl;
					memset(Message,0,sizeof(Message));
					memset(Time,0,sizeof(Time));
					cout<<"Do you want to continue post message? if yes input digit 1 or 0 (No)"<<endl;
					cin>>again;
					cin.ignore();
				}while(again);
				memset(Name,0,sizeof(Name));
				break;
			}
			case 4 :
			{
				char name[SIZE];
				cout<<"Which room do you want to review?";
				//cin>>name;
				cin.get(name,SIZE,'\n');
				cin.ignore();
				if(chat_room.show_mess_this_room(name))
					cout<<"SUCCESS"<<endl;
				else
					cout<<"FAIL"<<endl;
				memset(name,0,sizeof(name));
				break;
			}
			case 5 :
			{
				char key[SIZE];
				cout<<"Input keyword :";
				cin.get(key,SIZE,'\n');
				//cin>>key;
				cin.ignore();
				if(chat_room.show_mess_keyword(key))
					cout<<"SUCCESS"<<endl;
				else
					cout<<"BADLY"<<endl;
				memset(key,0,sizeof(key));
				break;
			}
			case 6 :
			{
				char name[SIZE];
				cout<<"Input user's name to retrieve :";
				cin.get(name,SIZE,'\n');
				//cin>>name;
				cin.ignore();
				if(chat_room.show_room_this_user(name))
					cout<<"GREAT"<<endl;
				else
					cout<<"UNFORTUNATELY"<<endl;
				//memset(name,0,sizeof(name));
				break;
			}
			case 7 :
			{
				char time[SIZE];
				cout<<"Input time you want to remove before that time :";
				cin.get(time,SIZE,'\n');
				//cin>>time;
				cin.ignore();
				if(chat_room.remove_older_time(time))
					cout<<"GOOD"<<endl;
				else
					cout<<"SORRY"<<endl;
				memset(time,0,sizeof(time));
				break;
			}
			default :
				cout<<"Something Wrong with your input"<<endl;
		}

		cout<<"We have room :"<<endl;
		chat_room.show_all_room();

		cout<<"Want continue? Please input digital 1, otherwise, input 0"<<endl;
		cin>>AGAIN;
		cin.ignore();
	}while(AGAIN);
	cout<<"-----------------------END-----------------------"<<endl;
	return 0;
}
