//Name: Jingtao Cheng
//Data: May 4 2017
//Course: CS 163
//PSU ID: 940067494

#include "queue.h"

queue::queue() //constructor 
{
    rear = NULL;
}

queue::~queue() //destructor
{
    if(!rear)
        return;
    
    delete_all(rear);
    rear = NULL;
}

void queue::delete_all(queue_node *& rear) //delete all for destructor
{
    if(!rear)
	    return;

    queue_node * temp = rear;
    rear = rear -> next;
    delete temp;
    temp = NULL;
    return delete_all(rear);
    
}

bool queue::enqueue(char * Name) //function for enqueue 
{
    if(!rear)
    {
	rear = new queue_node;
	rear -> next = rear;
	rear -> man.copy_name(Name);
	rear -> man.copy_row(1);
	rear -> man.copy_letter('A');
	return true;
    }
    return enqueue(Name,rear);
}
bool queue::enqueue(char * Name, queue_node *& rear)
{
    
	queue_node * temp = new queue_node;
	temp -> next = rear -> next;
	temp -> man.copy_name(Name);
	rear -> next = temp;
    rear = temp;
	return true;
}

bool queue::get_number(int MAX, int total) //function for calculate  seat number 
{
    if(!rear)
        return false;
    queue_node * head = rear -> next;
    return get_number(head,rear, MAX, total);
}

bool queue::get_number(queue_node * head,queue_node * signal, int MAX, int total)
{
    int row = total/(2*MAX);
    int boarding = 0;
    
    for(int j = 1; j <= row; ++j)
    {

        for(int i = 0; i < MAX; i++) //right side isle
        {
        
            
            boarding = total - MAX + i + 1;
            
            head -> man.copy_row(j);
            head -> man.copy_letter('A'+i);
            head -> man.copy_boarding(boarding);
            head = head -> next;
            if(head == signal)
                return true;
        }
        total = total - MAX;
        for(int i = 0; i < MAX; i++) //left side isle
        {
        
            
            boarding = total - i;
            head -> man.copy_row(j);
            head -> man.copy_letter('E'+i);
            head -> man.copy_boarding(boarding);
            head = head -> next;
            
        }
        total = total - MAX;
        
    }
    return true;
}


void queue::display_all()       //display all the passenger
{
    if(rear -> next == rear)
    {
        rear -> man.display();
        
        return;
    }
    queue_node * signal = rear;
    display_all(rear->next,signal);
}

void queue::display_all(queue_node * head, queue_node * signal) //display all the passenger
{
    if(head == signal)
    {
        head -> man.display();
        return;
    }
    head -> man.display();
    
    return display_all(head -> next, signal);
}
//display second queue
void queue::display_2()
{
    if(rear -> next == rear)
    {
        rear -> man.display();
        
        return;
    }
    queue_node * signal = rear;
    display_2(rear->next,signal);
}

void queue::display_2(queue_node * head, queue_node * signal)
{
    if(head == signal)
    {
        head -> man.display();
        return;
    }
    display_2(head->next,signal);
    
    head -> man.display();
}

bool queue::dequeue()   /*remove one node for the CLL of queue*/
{
    if(!rear)
	    return false;

    if(rear -> next == rear)
    {
	    
	    delete rear;
	    rear = NULL;
	    return false;
    }
    else
    {
        queue_node * temp;
	    temp = rear -> next;
	    rear -> next = temp -> next;
	    
	    delete temp;
	    return true;
    }
}

person queue::peek()        /*get the top data in the CLL**/
{
    
    return rear -> next -> man;
}

bool queue::get_inline(queue & from)
{
    if(!from.rear)
        return false;
    
    queue_node * signal = from.rear;
    return get_inline(rear, from.rear->next, signal);
}

//get data into queue

bool queue::get_inline(queue_node *& rear, queue_node * from_head, queue_node * signal)
{
    
    if(!rear)
    {
        rear = new queue_node;
	    rear -> next = rear;

	    rear -> man = from_head -> man;
	    return get_inline(rear,from_head->next,signal);
	}
    
    queue_node * temp = new queue_node;
    temp -> man = from_head -> man;
    temp -> next = rear -> next;
    rear -> next = temp;
    rear = temp;
    if(from_head == signal)
        return true;
    return get_inline(rear,from_head->next,signal);
}

//get data into stack

    bool queue::push_stack(stack & seat)
    {
        if(!rear)
            return false;
        queue_node * signal = rear;
        return push_stack(rear->next, signal, seat);
    }
    
    
    bool queue::push_stack(queue_node * head, queue_node * signal, stack & seat)
    {
        char * Name = head -> man.get_name();
        int number = head -> man.get_row();
	    char letter = head -> man.get_letter();
	    int boarding = head -> man.get_board();
        
        seat.push(Name,number,letter,boarding);
        
        if(rear == signal)
            return true;
        return push_stack(head->next, signal, seat);
    }