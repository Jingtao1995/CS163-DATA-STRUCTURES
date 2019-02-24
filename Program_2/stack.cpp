//Name: Jingtao Cheng
//Data: May 4 2017
//Course: CS 163
//PSU ID: 940067494

#include "queue.h"

/*The constructor for stack class*/

stack::stack()
{
    top_index = 0;
    head = NULL;
    MAX = 0;
}

/*The constructor for stack class*/
/*
void stack::construct(int row_size, int stack_size)
{
    MAX = stack_size;
    int i=0;
    stack_node * current = head;
    do
    {
        current = new stack_node;
        current -> next = NULL;
        current -> pasger = new person[MAX];
        current = current -> next;
        i++;
    }while(i < row_size*2);
}
*/
/*The destructor for stack class*/

stack::~stack()
{
    delete_all(head);
}

void stack::delete_all(stack_node *& head)
{
    if(!head)
	return;

    delete_all(head -> next);

    delete [] head -> pasger;
    delete head;
    head = NULL;
}


/*insert node at the beginning of LLL*/

bool stack::push(char * Name, int row, char letter, int Board_number)
{
    return push(Name, row, letter, Board_number, head);
}

bool stack::push(char * Name, int row, char letter, int Board_number, stack_node *& head)
{
    if(!head)
    {
        head = new stack_node;
        head -> pasger = new person[MAX];
        head -> next = NULL;
        
        top_index = 0;
        
        if(head -> pasger[top_index].copy_pasger(Name, row, letter, Board_number))
            ++top_index;
        return true;
    }
    
    if(top_index < MAX)
    {
        if(head -> pasger[top_index].copy_pasger(Name, row, letter, Board_number))
            ++top_index;
        return true;
    }
    else
    {
        top_index = 0;
        head = head->next;
        if(head -> pasger[top_index].copy_pasger(Name, row, letter, Board_number))
	        ++top_index;
	    return true;
    }
}
/*remove the top data in the LLL of stack*/

bool stack::pop()
{
    if(!head)
        return false;
    if(top_index > 0)
    {
        --top_index;
    }
    else
    {
        stack_node * temp = head;
        head = head -> next;
        delete []temp -> pasger;
        delete temp;
        top_index = MAX - 1;
        return true;
    }
    return true;
}

/*get the top data of LLL of stack*/

person stack::peek()
{
    return head -> pasger[top_index-1];
}

/*let other function call the display function without pass argument*/

void stack::display_all()
{
    if(!head)
        return;
    return display_all(head);
}

/*display all person's information*/

void stack::display_all(stack_node * head)
{
    if(!head -> next)
    {
        for(int i = 0; i < MAX; ++i)
        {
            head -> pasger[i].display();
        }
        return;
    }
    for(int i = 0; i < MAX; ++i)
    {
        head -> pasger[i].display();
    }
    display_all(head -> next);
}

/*
bool stack::get_inseat(queue & from)
{
    if(!from.rear)
        return false;
    queue_node * signal = from.rear;
    return get_inseat(from.rear -> next,signal);
}

bool stack::get_inseat(queue_node * head,signal)
{
    if(head == signal)
        return true;
    char * Name = head -> man.get_name();
	int * Row = head -> man.get_row();
	char Letter = head -> man.get_letter();
	int Boarding = head -> man.get_board();
	
	if(push(Name, Row, Letter, Boarding))
	    return get_inseat(head -> next,signal);
	return false;

}
*/