//Name: Jingtao Cheng
//Data: May 4 2017
//Course: CS 163
//PSU ID: 940067494

#include "queue.h"

int main()
{
	stack plane_seat;
    queue arrive_queue;
    queue boarding_queue;
    
    char name[20];
    int row = 0;
    int column = 0;
    
    cout << "Please input how many rows in the plane: ";
    cin >> row;
    cout << endl << "Please input how many columns in the plane: ";
    cin >> column;
    cout << endl;
    
    
    int count = 0;
    
    do
    {
	cout<<"Please enter name: ";
	cin >> name;
	cin.ignore(100, '\n');
	arrive_queue.enqueue( name );
	
	++count;
	
    }while(again());
    
    int operater = 0;
    
    do{
 
	//======================================================================================================
	
	cout<<"#1. display queue 1"<<endl;
	cout<<"#2. display queue 2"<<endl;
	cout<<"#3. display stack"<<endl;

	//======================================================================================================
	

		cout<<"-------------Please input your choice------------"<<endl;
		cin >> operater;
		cin.ignore();
		switch (operater)
		{
            case 1 :
            {
                arrive_queue.get_number(column,count);
                arrive_queue.display_all();
                
                break;
            }
            case 2 :
            {
                boarding_queue.get_inline(arrive_queue);
                
                boarding_queue.display_2();
                break;
            }
            case 3 :
	        {

	            boarding_queue.push_stack(plane_seat);
	            boarding_queue.display_2();
	            break;
	        }
	        default :
				cout<<"Something Wrong with your input"<<endl;
		}
		}while(again());
	return 0;
}
