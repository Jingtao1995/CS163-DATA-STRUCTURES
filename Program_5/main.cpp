//
//  main.cpp
//
//  Created by Jingtao Cheng on 6/2/17.
//
//  PSU ID: 940067494
//
//  Course: CS 163
//
//  Copyright © 2017 Jingtao Cheng. All rights reserved.
//

#include "map_graph.h"

int main()
{

    cout<<"Welcome!\n\n"
        <<"Please input how many vertex do you want \n";
    int size = 10;
    cin >> size;
    cout <<"\n\n";
    
    map new_map(size);
    
    char check = 'y';
    
	do{
	    cout<<"[1]. Insert Vertex \n"
	        <<"[2]. Insert Edge \n"
	        <<"[3]. Display all of the paths that the walker could take from a particular trailhead \n"
	        <<"[4]. Display all connecting vertices from a specified vertex \n"
	        <<"[5]. Close program \n";
	    int choice = 0;
	    cin>>choice;
	    switch(choice)
	    {
	        case 1:
	        {
	            char Name[SIZE_name];
	            char Info[SIZE_info];
	            cin.ignore();
                cout << "Please input vertex's name : ";
                cin.get( Name, SIZE_name, '\n');
                cin.ignore(100,'\n');
                cout << endl;
                
                cout << "Please input vertex's info : ";
                cin.get( Info, SIZE_info, '\n');
                cin.ignore(100,'\n');
                cout << endl;
                
                new_map.insert_vertex(Name, Info);

	            break;
	        }
	        case 2:
	        {
	            char Current_name[SIZE_name];
	            char Connected_name[SIZE_name];
	            char Description[SIZE_description];
	            int Length;
	            cin.ignore();
                cout << "Please input current vertex's name : ";
                cin.get( Current_name, SIZE_name, '\n');
                cin.ignore(100,'\n');
                cout << endl;
                

                cout << "Please input connected vertex's name : ";
                cin.get( Connected_name, SIZE_name, '\n');
                cin.ignore(100,'\n');
                cout << endl;
                

                cout << "Please input edge's description : ";
                cin.get( Description, SIZE_description, '\n');
                cin.ignore(100,'\n');
                cout << endl;
                
                //cin.ignore();
                cout << "Please input edge's length : ";
                cin >> Length;
                cout << endl;
                new_map.insert_edge(Current_name, Connected_name, Description, Length);
	            break;
	        }
	        case 3:
	        {
	            char Current_name[SIZE_name];
	            cin.ignore();
                cout << "Please input current vertex's name : ";
                cin.get( Current_name, SIZE_name, '\n');
                cin.ignore(100,'\n');
                cout << endl;
                
                new_map.display_all_path(Current_name);
	            break;
	        }
	        case 4:
	        {
	            char Current_name[SIZE_name];
	            cin.ignore();
                cout << "Please input current vertex's name : ";
                cin.get( Current_name, SIZE_name, '\n');
                cin.ignore(100,'\n');
                cout << endl;
                
                new_map.display_all_connections(Current_name);
	            break;
	        }
	        case 5:
	        {
	            return 0;
	        }
	        default:
	        {
	           cout<<"2.Something wrong with your input, please try again."<<endl;
	        }
	        
	    }
	    //new_map.display();
    }while(check == 'y'||check == 'Y');
    
}