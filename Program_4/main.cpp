//
//  main.cpp
//
//  Created by Jingtao Cheng on 5/31/17.
//
//  PSU ID: 940067494
//
//  Course: CS 163
//
//  Copyright © 2017 Jingtao Cheng. All rights reserved.
//

#include "client.h"

int main()
{
    
    
    tree new_tree;
    
    new_tree.read_file();
    
    do
    {
        cout<<"[1].Display all Events\n"
	        <<"[2].Insert new Events\n"
	        <<"[3].Remove one Event by name\n"
	        <<"[4].Remove Events by keywords\n"
	        <<"[5].Retrieve one Event by name\n";
	    //cin.ignore();
	    int choice = 0;
	    cin >> choice;
	    switch(choice)
	    {
	        case 1:
	        {
		        if(new_tree.display_all())
		            cout<<"Success\n";
	    	    break;
	        }
	        case 2:
	        {
	            input(new_tree);
	            break;
	        }
	        case 3:
	        {
	            if(input_name_remove(new_tree))
	                cout<<"Success\n";
	            break;
	        }
            case 4:
	        {
	            if(input_keywords_remove(new_tree))
	                cout<<"Success\n";
	            break;
	        }
	        case 5:
	        {
	            if(input_name_retrieve(new_tree))
	            {
	                cout<<"Success\n";
	            }
	            break;
	        }
	        default:
	        {
	           cout<<"2.Something wrong with your input, please try again."<<endl;
	        }
        }
	    
    }while(again());

    
    
    
    
    return 0;
}
