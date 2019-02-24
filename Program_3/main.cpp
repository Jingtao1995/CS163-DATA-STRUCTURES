//
//  main.cpp
//
//  Created by Jingtao Cheng on 5/18/17.
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
    
    
    table new_hash_table;
    
    new_hash_table.read_file();
    
    do
    {
        cout<<"[1].Display Events\n"
	        <<"[2].Insert new Events\n"
	        <<"[3].Remove one Event by keywords\n"
	        <<"[4].Retrieve one Event by keywords\n";
	 
	    int choice = 0;
	    cin >> choice;
	    switch(choice)
	    {
	        case 1:
	        {
	            cout<<"[1].Display one event use keywords to search\n"
		            <<"[2].Display all events\n";
		        int i = 0;
		        cin >> i;
		        if(i == 1)
		        {
		            display_by_keywords(new_hash_table);
		            break;
		        }
		        if(i == 2)
		        {
		            new_hash_table.display_all();
		            break;
		        }
	    	    else
	    	    {
	    	        cout<<"1.Something wrong with your input, please try again."<<endl;
	    	    }
	    	    break;
	        }
	        case 2:
	        {
	            input(new_hash_table);
	            break;
	        }
	        case 3:
	        {
	            if(input_keywords_remove(new_hash_table))
	                cout<<"Success\n";
	            break;
	        }
            case 4:
	        {
	            if(input_keywords_retrieve(new_hash_table))
	                cout<<"Success\n";
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