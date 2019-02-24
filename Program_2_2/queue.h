/**************************************/
/*Fenting Lin CS163 Program#2**********/
/*This program is a fictional delivery*/
/**************************************/

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

struct queue_node
{
    char * data;			//The data in the CLL of queue
    queue_node * next;			//The next pointer in the CLL of queue
};

class queue
{
    public:
	queue();			//Constructor
	~queue();			//Destructor

	int enqueue(char *);		//To insert node at the end of CLL
	int dequeue();			//To remove node at the beginning of CLL
	char* peek();			//To get the first node in CLL of queue
	void display(queue_node *);	//To display all node in CLL of queue
	void display();			//To call the display function without pass rear
    private:
	void delete_all(queue_node *);	//To delete the CLL of queue
	queue_node * rear;		//The last ndoe in the CLL of queue
};
