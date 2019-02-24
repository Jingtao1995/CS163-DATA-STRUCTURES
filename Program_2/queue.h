//Name: Jingtao Cheng
//Data: May 4 2017
//Course: CS 163
//PSU ID: 940067494

#include "passenger.h"

using namespace std;


struct stack_node        //stack of seat _ linear linked list of array
{
    person * pasger;    //The pointer point to person class
    
    stack_node * next;  //The next point for LLL of stcak
};

class stack
{
public:
    stack();        //constructor
    ~stack();       //destructor
    //void construct( int, int);
    bool push(char *, int, char, int);      //insert at the top
    bool pop();         //remove top data
    person peek();      //get top data
    

    void display_all();
    void display_all(stack_node * head);         //display all person's info
private:
    bool push(char *, int, char, int, stack_node *& head);
    stack_node * head;  //The head pointer to the stack LLL
    int top_index;  //The top_index in the array
    int MAX;    //The max size for the stack
    
    void delete_all(stack_node *&);          //delete LLL of stack
};

    

    
//-----------------------------------------------------------------------

struct queue_node
{
    person man; //The object in the CLL of queue
    
    queue_node * next;      //The next pointer in the CLL of queue
}; 

class queue
{
public:
    queue();        //Constructor
    ~queue();       //Destructor

    bool enqueue(char *);   		//To insert node at the end of CLL
    //bool enqueue_board(char *, char *, char *);
    
    bool get_number(int, int);
    bool dequeue(); //To remove node at the beginning of CLL
    person peek();      //To get the first node in CLL of queue
    void display_all();     //To call the display function without pass rear
    void display_all(queue_node *, queue_node *);       //To display all node in CLL of queue
    void display_2();
    
    bool get_inline(queue & from);  //To pass data into new queue
    bool push_stack(stack &);
    
private:

    queue_node * rear;      //The last ndoe in the CLL of queue
    bool enqueue(char *, queue_node *& rear);
    void display_2(queue_node *, queue_node *);
    void delete_all(queue_node *&);     //To delete the CLL of queue
    bool get_inline(queue_node *&, queue_node *, queue_node *);
    bool get_number(queue_node *,queue_node *, int, int);
    bool push_stack(queue_node *, queue_node *, stack &);
};

