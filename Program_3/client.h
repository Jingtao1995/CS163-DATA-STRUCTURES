//
//  client.h
//
//  Created by Jingtao Cheng on 5/18/17.
//
//  PSU ID: 940067494
//
//  Course: CS 163
//
//  Copyright © 2017 Jingtao Cheng. All rights reserved.
//

#include "hash_table.h"

void input(table & new_hash_table)      //function used to implement input
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
    
    new_hash_table.create_file(Name, Location, Date, Time, Description, Keywords);
    if(new_hash_table.insert(Name, Location, Date, Time, Description, Keywords))
        cout<<"Insert success\n";
    else
        cout<<"Insert failed\n";
}

//function used for input keywords
//and call remove function
bool input_keywords_remove(table & new_hash_table)
{
    char Keywords[SIZE_keywords];
    cout << "Please input keywords : ";
    cin.ignore();
    cin.get( Keywords, SIZE_keywords, '\n');    
    cin.ignore(100,'\n');
    cout << endl;
    return new_hash_table.remove(Keywords);
}

//function used to input 
//and call retrieve function
bool input_keywords_retrieve(table & new_hash_table)
{
    char Keywords[SIZE_keywords];
    cout << "Please input keywords : ";
    cin.ignore();
    cin.get( Keywords, SIZE_keywords, '\n');    
    cin.ignore(100,'\n');
    cout << endl;
    return new_hash_table.retrieve(Keywords);
}

//function used to input
//and call display function
void display_by_keywords(table & new_hash_table)
{
    char Keywords[SIZE_keywords];
    cout << "Please input keywords : ";
    cin.ignore();
    cin.get( Keywords, SIZE_keywords, '\n');    
    cin.ignore(100,'\n');
    cout << endl;
    new_hash_table.retrieve2(Keywords);
}

//function used to check input
//and return true or false for determin
//the loop to continue or stop
bool again()
{
    char check = 'n';
    cout<<"If continue, press any key, else press 'n'\n";
    cin >> check;
    if(check == 'n')
        return false;
    else
        return true;
}