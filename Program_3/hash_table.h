//
//  hash_table.h
//
//  Created by Jingtao Cheng on 5/18/17.
//
//  PSU ID: 940067494
//
//  Course: CS 163
//
//  Copyright © 2017 Jingtao Cheng. All rights reserved.
//

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

#define SIZE_table 26
#define SIZE_name 20
#define SIZE_location 20
#define SIZE_date 20
#define SIZE_time 20
#define SIZE_description 100
#define SIZE_keywords 50

//----------------------------------------------------------------------------------------

struct node
{
    char * name;    //store event's name
    char * location;    //store event's location
    char * date;    //store event's date
    char * time;    //store event's time
    char * description;     //store event's description
    char * keywords;    //store event's keywords for search
    //keys * keyword;

    node * next;
};


//hash table implement

class table
{
public:
    table(int size = SIZE_table); // need to check!!!!!
    ~table(void);   //deallocate the hash table
    
    int hash_function(char *);
    
    bool insert(char *, char *, char *, char *, char *, char *);    //add an event into the hash table
    bool retrieve(char *);  //retrieve all events based on the name supplied
    bool retrieve2(char *);     //second retrieve function, retrieve by keywords supplied
    bool remove(char *);    //remove an event that has past the date supplied by the client
    void display_all();     //display all events without keywords
    void display_by_keywords(char *);      //display events' with specific keywords
    void read_file();   //read the data from extra file
    void create_file(char * Name, char * Location, char * Date, char * Time, char * Description, char * Keywords);  //write the data into extra file
    
private:
    node ** hash_table;     //hash table
    int hash_table_size;    //hash table size
    
    void delete_table(node *&);     // function used to delete table

    bool retrieve(char *, node *);      //recursive function for retrieve by name
    bool retrieve2(char *, node *);     //recursive function for retrieve by keywords
    bool remove(char *, node *&);       //remove function to delete specific event
    void display(node *);   //displaying matches, based on the keyword
    void display_all(node *, int);      //display all event recursively
    void display_by_keywords(char *, node *);   //display events' with specific keywords
};
