/**************************************/
/*Fenting Lin CS163 Program#2**********/
/*This program is a fictional delivery*/
/**************************************/

#include "package.h"

struct stack_node
{
    Package * package;			//The pointer point to Package class
    stack_node * next;			//The next point for LLL of stcak
};

const int MAX = 3;			//The size of every array in the LLL

class stack
{
    public:
	stack();    //Constructor
	~stack();   //Destructor

	int push(char *, char *, int);	//To insert node at the beginning
	int pop();			//To remove the top data in LLL
	Package peek();			//To get the top data in LLL
	void display(stack_node *);	//To display all packages' info
	void display();			//To call display fucntion without pass head
    private:
	stack_node * head;		//The head pointer to the stack LLL
	int top_index;			//The top_index in the array
	void delete_all(stack_node *&);	//To delete LLL of stack
};
