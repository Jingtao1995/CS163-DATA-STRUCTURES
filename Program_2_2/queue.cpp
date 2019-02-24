/**************************************/
/*Fenting Lin CS163 Program#2**********/
/*This program is a fictional delivery*/
/**************************************/

#include "queue.h"

/*********************************/
/*The constructor for queue class*/
/*********************************/

queue::queue()
{
    rear = NULL;
}

/********************************/
/*The destructor for queue class*/
/********************************/

queue::~queue()
{
    if(!rear)
	return;

    queue_node * head = rear -> next;
    rear -> next = NULL;

    delete_all(head);
    head = NULL;
}

/***************************************/
/*The delete all function is used to****/
/*delete circular linked list for queue*/
/***************************************/

void queue::delete_all(queue_node * rear)
{
    if(!rear)
	return;

    delete_all(rear -> next);

    delete [] rear -> data;    
    delete rear;
    
    rear = NULL;

}

/***********************************/
/*The enqueue function is used to***/
/*insert the node at the end of CLL*/
/***********************************/

int queue::enqueue(char * recipient)
{
    if(!rear)
    {
	rear = new queue_node;
	rear -> next = rear;
	rear -> data = recipient;
	int len = strlen(recipient);
	rear -> data = new char[len+1];
	strcpy(rear -> data, recipient);
	return 1;
    }
    else
    {
	queue_node * temp = rear -> next;
	rear -> next = new queue_node;
	rear = rear -> next;
	int len = strlen(recipient);
	rear -> data = new char[len+1];
	strcpy(rear -> data, recipient);
	rear -> next = temp;
	return 1;
    }
}
/*****************************************/
/*The display function is used to*********/
/*display all the recipients' information*/
/*****************************************/

void queue::display(queue_node * rear)
{
    if(rear -> next == rear)
    {
	cout<<rear -> data<<endl;
    }
    else
    {
    	queue_node * head = rear -> next;
	queue_node * current = head;
	rear -> next = NULL;
	while(current)
	{
	    cout<<current -> data<<endl;
	    current = current -> next;
	}
	rear -> next = head;
    }
}

/********************************************************************/
/*The display function is used to************************************/
/*let other function call the display function without pass argument*/
/********************************************************************/

void queue::display()
{
    display(rear);
}

/**************************************/
/*The dequeue function is used to******/
/*remove one node for the CLL of queue*/
/**************************************/

int queue::dequeue()
{
    if(!rear)
	return 0;
    queue_node * temp;

    if(rear -> next == rear)
    {
	delete []rear -> data;
	delete rear;
	rear = NULL;
	return 0;
    }
    else
    {
	temp = rear -> next;
	rear -> next = temp -> next;
	delete []temp -> data;
	delete temp;
	return 1;
    }
}

/******************************/
/*The peek function is used to*/
/*get the top data in the CLL**/
/******************************/

char * queue::peek()
{
    return rear -> next -> data;
}
