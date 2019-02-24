//
//  hash_table.cpp
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

table :: table(int size)    //constructor, initial hash_table 
{
    //Allocate the hash table and initialize each
    //element and data member.
    hash_table_size = size;
    hash_table = new node*[hash_table_size];
    for(int i = 0; i < size; i++)
    {
        *(hash_table + i) = NULL;
    }
}

table :: ~table()   //destructor, deallocate the memory
{
    for(int i = 0; i < hash_table_size; ++i)
    {
	if(hash_table[i])
	    delete_table(hash_table[i]);
    }
    
    delete []hash_table;
}

void table :: delete_table(node *& temp)    //delete function, use to help deallocate and remove
{
    if(!temp)
	    return;

    delete_table(temp -> next);

    delete []temp -> name;
    delete []temp -> location;
    delete []temp -> date;
    delete []temp -> time;
    delete []temp -> description;
    delete []temp -> keywords;
    
    delete temp;
    temp = NULL;
}

// read information from event.txt and store into hash table
void table :: read_file()
{
    char Name[SIZE_name];
    char Location[SIZE_location];
    char Date[SIZE_date];
    char Time[SIZE_time];
    char Description[SIZE_description];
    char Keywords[SIZE_keywords];
    
    ifstream f_in("event.txt");
    if(f_in)
    {
        
        while(!f_in.eof())
        {   
            f_in.get(Name, SIZE_name, '|');
            f_in.ignore();
            
            f_in.get(Location, SIZE_location, '|');
            f_in.ignore();
            
            f_in.get(Date, SIZE_date, '|');
            f_in.ignore();
            
            f_in.get(Time, SIZE_time, '|');
            f_in.ignore();
            
            f_in.get(Description, SIZE_description, '|');
            f_in.ignore();
            
            f_in.get(Keywords, SIZE_keywords, '|');
            f_in.ignore();
            
            //insert function at here
            insert(Name, Location, Date, Time, Description, Keywords);
            
        }
        cout<<"**********-----  Reading 'event.txt' File  -----********** \n";
    }
    else
        cout<<"!!!!!!!!!!----- Can't Open 'event.txt' File -----!!!!!!!!!! \n";
    f_in.close();
}

// create file and load information into this file
void table :: create_file(char * Name, char * Location, char * Date, char * Time, char * Description, char * Keywords)
{
    
    ofstream f_out;
    f_out.open("event.txt", ios::app);
    if(f_out)
    {
        f_out << Name << '|';
        f_out << Location << '|';
        f_out << Date << '|';
        f_out << Time << '|';
        f_out << Description << '|';
        f_out << Keywords << '|';

        cout<<"**********-----  Loading 'event.txt' File  -----********** \n";
    }
    else
        cout<<"!!!!!!!!!!-----Can't Open 'event.txt' File-----!!!!!!!!!! \n";    
    f_out.close();
}

//hash function, used to locate the position to store
int table :: hash_function(char * key_value)
{
    int len = strlen(key_value);
    
    char * key = new char[len + 1];
    strcpy(key, key_value);
        
    int hash = 0;
	hash = key[0] % hash_table_size;
    
    delete []key;
    return hash;
}

//insert function
bool table :: insert(char * Name, char * Loca, char * Date, char * Time, char * Desc, char * Keywords)
{
    node * head = new node;
    head -> next = NULL;
    
    head -> name = new char[strlen(Name) + 1];
    strcpy(head -> name, Name);
    
    head -> location = new char[strlen(Loca) + 1];
    strcpy(head -> location, Loca);
    
    head -> date = new char[strlen(Date) + 1];
    strcpy(head -> date, Date);
    
    head -> time =  new char[strlen(Time) + 1];
    strcpy(head -> time, Time);
    
    head -> description =  new char[strlen(Desc) + 1];
    strcpy(head -> description, Desc);
    
    head -> keywords =  new char[strlen(Keywords) + 1];
    strcpy(head -> keywords, Keywords);
       
    int key_value = hash_function(Name);
    head -> next = hash_table[ key_value ];
    hash_table[ key_value ] = head;
        
    return true;
}

//retrieve function by name - wrapper
bool table :: retrieve(char * find)
{
    int i = hash_function(find);
    return retrieve(find, hash_table[ i ]);
}

//retrieve function by name - recursion
bool table :: retrieve(char * find_name, node * head)
{
    if(!head)
        return false;
    if(!strcmp(find_name, head -> name)||!strcmp(find_name, head -> keywords))
    {
        display(head);
        return true;
    }
    else
        return false;
    return retrieve(find_name, head -> next);
}

//retrieve function by keywords - wrapper
bool table :: retrieve2(char * find)
{
    for(int i = 0; i < hash_table_size; ++i)
    {
        retrieve(find, hash_table[ i ]);
    }
    return true;
}

//retrieve function by keywords - recursion
bool table :: retrieve2(char * find, node * head)
{
    if(!head)
        return false;
    if(!strcmp(find, head -> name)||!strcmp(find, head -> keywords))
    {
        display(head);
        return true;
    }
    else
        return false;
    return retrieve2(find, head -> next);
}

//remove function wrapper
//remove node by keywords
bool table :: remove(char * delete_find)
{
    int i = hash_function(delete_find);
    return remove(delete_find, hash_table[ i ]);
}

//remove function recursive
bool table :: remove(char * delete_find, node *& head)
{
    if(!head)
        return false;
    if(!strcmp(delete_find, head -> name)||!strcmp(delete_find, head -> keywords))
    {   
        node * temp = head;
        delete []temp -> name;
        delete []temp -> location;
        delete []temp -> date;
        delete []temp -> time;
        delete []temp -> description;
        delete []temp -> keywords;
        
        head = head -> next;
        delete temp;
        temp = NULL;
        return true;
    }
    return remove(delete_find, head -> next);
}

//display function - assistance function
void table :: display(node * head)
{
    if(!head)
        return;
    cout<<"Event Name: "<<head -> name<<endl;
    cout<<"Event Location: "<<head -> location<<endl;
    cout<<"Event Date: "<<head -> date<<endl;
    cout<<"Event Time: "<<head -> time<<endl;
    cout<<"Event Description: "<<head -> description<<endl;
    cout<<"Event Keywords: "<<head -> keywords<<endl;
}

//display all events - wrapper
void table :: display_all()
{
    for(int i = 0; i < hash_table_size; ++i)
    {
        cout<<"****************Line [ "<<i<<" ] of Array****************"<<endl;
        display_all(hash_table[ i ], 0);
    }
}

//display all events - recursive function
void table :: display_all(node * head, int count)
{
    if(!head)
        return;
    cout<<"--------------------< "<<count<<" >--------------------"<<endl;
    display(head);
    return display_all(head -> next, ++count);
}
