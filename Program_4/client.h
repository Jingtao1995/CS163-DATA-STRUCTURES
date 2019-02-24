//
//  client.h
//
//  Created by Jingtao Cheng on 5/31/17.
//
//  PSU ID: 940067494
//
//  Course: CS 163
//
//  Copyright © 2017 Jingtao Cheng. All rights reserved.
//

#include "BST.h"

bool again()    //function used to check continue or not
{
    char check = 'n';
    cout<<"If continue, press any key, else press 'n'\n";
    cin >> check;
    if(check == 'n')
        return false;
    else
        return true;
}

bool input(tree & new_tree)      //function used to implement input
{
    char Name[SIZE_name];
    char Location[SIZE_location];
    char Date[SIZE_date];
    char Time[SIZE_time];
    char Description[SIZE_description];
    char Keywords[SIZE_keywords];
    
    cin.ignore();
    cout << "Please input event's name : ";
    cin.get( Name, SIZE_name, '\n');
    cin.ignore(100,'\n');
    cout << endl;

    cout << "Please input event's location : ";
    cin.get( Location, SIZE_location, '\n');	
    cin.ignore(100,'\n');
    cout << endl;
    
    cout << "Please input event's date(M/D/Y) : "; 
    cin.get( Date, SIZE_date, '\n');
    cin.ignore(100,'\n');
    cout << endl;
    
    cout << "Please input event's time : ";
    cin.get( Time, SIZE_time, '\n');
    cin.ignore(100,'\n');
    cout << endl;
    
    cout << "Please describe the event : ";
    cin.get( Description, SIZE_description, '\n');
    cin.ignore(100,'\n');
    cout << endl;
    
    cout << "Please input keywords for event : ";
    cin.get( Keywords, SIZE_keywords, '\n');    
    cin.ignore(100,'\n');
    cout << endl;
    
    new_tree.create_file(Name, Location, Date, Time, Description, Keywords);
    if(new_tree.insert(Name, Location, Date, Time, Description, Keywords))
        cout<<"Insert success\n";
    else
    {
        cout<<"Insert failed\n";
        return false;
    }
    return true;
}

bool input_keywords_remove(tree & new_tree)     //function used to get keywords and call the remove funciton
{
    char Keywords[SIZE_keywords];
    cout << "Please input keywords : ";
    cin.ignore();
    cin.get( Keywords, SIZE_keywords, '\n');    
    cin.ignore(100,'\n');
    cout << endl;
    return new_tree.remove_all(Keywords);
}

bool input_name_remove(tree & new_tree)     //function used to get name and call the remove function
{
    char Name[SIZE_name];
    cout << "Please input Name : ";
    cin.ignore();
    cin.get( Name, SIZE_name, '\n');
    cin.ignore(100,'\n');
    cout <<endl;
    return new_tree.remove(Name);
}

bool input_name_retrieve(tree & new_tree)       //function used to get name for retrieve and return the information for dispaly
{
    char Name[SIZE_keywords];
    cout << "Please input name : ";
    cin.ignore();
    cin.get( Name, SIZE_name, '\n');    
    cin.ignore(100,'\n');
    cout << endl;
    cout <<"Adress: "
         << new_tree.retrieve(Name) << endl;
    cout <<"The content as follows : \n"
         <<new_tree.display_name(new_tree.retrieve(Name))
         <<endl;
    return true;
}