//
//  graph.h
//
//  Created by Jingtao Cheng on 6/2/17.
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

using namespace std;

#define SIZE_name 50
#define SIZE_description 50
#define SIZE_info 50

struct vertex
{
    char * name;
    
    char * info;
    
    //char visit;
    
    struct node * head; //head used to make edge list
};


struct node
{
    vertex * edge;  //used to make a refer to vertex
    
    char * description;
    
    int length;
    
    node * next;
};

class map
{
    public:
    
	map(int size);
	
	~map();

	int insert_vertex(char *, char *); //insert function for insert vertex by name and information
	
	
//insert function for insert adjacency, through the current vertex's name and
//the adjacent vertex's name to make the edge list. -- Wrapper
	int insert_edge(char * ,char *, char *, int ); 
	
//For a particular trailhead, display all of the paths that the walker could take
	bool display_all_path(char *);
	
	bool display_all_connections(char *);
	
	
//	void display();// only used for test
	
    private:
    
	int list_size;
	
	vertex * vertex_list;

//function used to get the vertex's index
	int get_vertex(char * );
	
//remove function, used to assist destructor
	bool delete_all(node *& );
	
//insert function for insert adjacency, through the current vertex's name and
//the adjacent vertex's name to make the edge list.
	int insert_edge( node *& , int , char * , int );
	
//Display all connecting vertices from a specified vertex (recursive function)
	bool display_all_connections(node *);

//For a particular trailhead, display all of the paths that the walker could take
	bool display_all_path(node *);
};
