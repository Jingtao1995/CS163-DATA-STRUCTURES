/**************************************/
/*Fenting Lin CS163 Program#2**********/
/*This program is a fictional delivery*/
/**************************************/

#include "stack.h"

/*********************************/
/*The constructor for stack class*/
/*********************************/

stack::stack()
{
    top_index = 0;
    head = NULL;
}

/********************************/
/*The destructor for stack class*/
/********************************/

stack::~stack()
{
    delete_all(head);
}

/************************************/
/*The delete all function************/
/*is used to delete the LLL of stack*/
/************************************/

void stack::delete_all(stack_node *& head)
{
    if(!head)
	return;

    delete_all(head -> next);

    delete [] head -> package;
    delete head;
    head = NULL;
}

/*************************************/
/*The push fucntion is used to********/
/*insert node at the beginning of LLL*/
/*************************************/

int stack::push(char * sender, char * recipient, int size_package)
{
    if(!head)
    {
	head = new stack_node;
	head -> package = new Package[MAX];
	head -> next = NULL;

	top_index = 0;

	if(head -> package[top_index].copy_package(sender, recipient, size_package))
	    ++top_index;
	return 1;
    }

    if(top_index < MAX)
    {	
	if(head -> package[top_index].copy_package(sender, recipient, size_package))
	    ++top_index;
	return 1;
    }
    else
    {
	top_index = 0;
	stack_node * temp = new stack_node;
	temp -> package = new Package[MAX];
	//head -> next = NULL;
	if(temp -> package[top_index].copy_package(sender, recipient, size_package))
	    ++top_index;
 
	temp -> next = head;
	head = temp;

	return 1;
   }
}

/*****************************************/
/*The pop function is used to*************/
/*remove the top data in the LLL of stack*/
/*****************************************/

int stack::pop()
{
    if(!head)
	return 0;

    if(top_index > 0)
    {
	--top_index;
    }
    else
    {
	stack_node * temp = head;
	head = head -> next;
	delete []temp -> package;
	delete temp;
	top_index = MAX - 1;
	return 1;
    }

}

/**********************************/
/*The peek fucntion is used to*****/
/*get the top data of LLL of stack*/
/**********************************/

Package stack::peek()
{
   return head -> package[top_index-1]; 
}

/***********************************/
/*The display fucntion is used to***/
/*display all package's information*/
/***********************************/

void stack::display(stack_node * head)
{
    if(!head -> next)
    {  
	for(int i = 0; i < MAX; ++i)
	{
	    head->package[i].display();
	}

	return;
    }
    
    for(int i = 0; i < MAX; ++i)
    {
	head->package[i].display();
    }
    display(head->next);
}

/********************************************************************/
/*The display function is used to************************************/
/*let other function call the display function without pass argument*/
/********************************************************************/

void stack::display()
{   
    if(!head)
	return;

    
    for(int i = 0; i < top_index; ++i)
    {
	head->package[i].display();
    }
    	
    if(head -> next)
	display(head -> next);

    return;
}
