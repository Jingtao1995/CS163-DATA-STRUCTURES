//
//  BST.h
//
//  Created by Jingtao Cheng on 5/31/17.
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

    node * left;
    node * right;
};

class tree
{
public:
    tree();
    ~tree();
        
    bool insert(char *, char *, char *, char *, char *, char *);    //add an event into the tree
    
    bool display_name(node *); //display specific event
    
    node * retrieve(char *);  //retrieve all events based on the name supplied
    
    node *& remove(char *);    //remove an event that has past the name supplied by the client
    
    node *& remove_all(char *);    //remove all events have specific keywords
    
    bool display_all();     //display all events without keywords
    
    bool read_file();   //read the data from extra file
    
    bool create_file(char * Name, char * Location, char * Date, char * Time, char * Description, char * Keywords);  //write the data into extra file
    
private:
    node * root;

    node * inorder_successor(node *& root);     //function to find the inorder successor
    
    bool delete_all(node *&);       //function used to deallocate all the dynamically allocate element
    
    bool display(node *);       //function used to help display specific information
    
    bool deallocate_node(node *&);      //function used to help delete nodes
    
    bool copy(node * , node *);     //function used to copy information from other nodes
    
    bool insert(char *, char *, char *, char *, char *, char *, node *&); //recursive function for inserting
    
    bool delete_tree(node *&);     // function used to delete tree

    node * retrieve(char *, node *);      //recursive function for retrieve by name

    node *& remove(char *, node *&);       //remove function based on name
    
    node *& remove_all(char *, node *&);    //remove all events based on keywords
    
    bool display_all(node *);      //display all event recursively
};
