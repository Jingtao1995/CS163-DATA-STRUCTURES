/**************************************/
/*Fenting Lin CS163 Program#2**********/
/*This program is a fictional delivery*/
/**************************************/

#include "stack.h"
#include "queue.h"

int main()
{
    stack a_stack;
    queue a_queue;

    char destination[50][50];
    char sender[21];
    char recipient[21];
    int size_package;
    int i = 0;

    do
    {
	cout<<"Please enter sender: ";
	cin.get(sender, 21,'\n');
	cin.ignore(100, '\n');

	cout<<"Please enter recipient: ";
	cin.get(recipient, 21, '\n');
	cin.ignore(100, '\n');

	cout<<"Please enter the size of package: ";
	cin>>size_package;
	cin.ignore(100, '\n');
	a_stack.push(sender, recipient, size_package);
	
	strcpy(destination[i],recipient); 
	++i;
    }while(again());
    
    for(int j = i-1;j>-1;--j )
    {
	a_queue.enqueue(destination[j]);
    }

    char response;
    int choice;
    while(response != 'Y' && response != 'y')
    {
	cout<<"[1].Display all packages' information\n"
	    <<"[2].Display all recipients\n"
	    <<"[3].Display next delivered package\n"
	    <<"[4].Remove package had delivered\n\n";
    
	cin>>choice;
	cin.ignore(100,'\n');

	if(choice == 1)
	{
	     cout<<"\n\nAll packages' information: \n";
	     a_stack.display();
	}
	else if(choice == 2)
	{
	    cout<<"\n\nAll recipient: \n";
	    a_queue.display();
	}
	else if(choice == 3)
	{
	    cout<<"\n\nThe package which will be delivery is :\n";
	    a_stack.peek().display();
	    cout<<"\n\nThe next recipient is: "<<a_queue.peek()<<endl;
	}
	else if(choice == 4)
	{
	     do
	     {
		if(a_stack.pop() && a_queue.dequeue())
		{
		    cout<<"\n\nAfter delivering, the rest packages are: \n";
		    a_stack.display();
		    cout<<"After delivering, the rest recipients are: \n";
		    a_queue.display();
		}
		else
		    cout<<"NOTHING TO DELIVER!\n\n";
		
	     }while(again());
    
	}
	else
	    cout<<"Error!!!\n";

	cout<<"Do u want quit? ";
	cin>>response;
	cin.ignore(100,'\n');
    }    
      
    return 0;
}
