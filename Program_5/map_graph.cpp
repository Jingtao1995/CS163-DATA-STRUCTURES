//
//  graph.cpp
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

//constructor , initial the graph
map :: map(int size)
{
    list_size = size;
    vertex_list = new vertex[size];
    for(int i = 0; i < list_size; i++)
    {
	vertex_list[i].head = NULL;
	
	//vertex_list[i].visit = 'n';
	
	vertex_list[i].info = NULL;
	vertex_list[i].name = NULL;
    }
}

/*
int map :: initial_visit()
{
    for(int i = 0; i < list_size; i++)
    {
	    vertex_list[i].visit = 'n';
    }
    return 1;
}
*/

/*The destructor of map class, to remove all the element dynamically allocated*/
map :: ~map()
{

    for(int i = 0; i < list_size; ++i)
    {
        delete_all(vertex_list[i].head);
        
	    delete []vertex_list[i].name;
	    vertex_list[i].name = NULL;
	    delete []vertex_list[i].info;
	    vertex_list[i].info = NULL;
	    
	    delete vertex_list[i].head;
	    vertex_list[i].head = NULL; 
    }
    delete []vertex_list;
    vertex_list = NULL; 

}

//remove function, used to assist destructor
bool map :: delete_all(node *& current)
{
    if(!current)
        return true;
    node * temp = current;
    current = current -> next;
    delete temp;
    temp = NULL;
    return delete_all(current);
}

//insert function for insert vertex by name and information
int map :: insert_vertex(char * Name, char * Info)
{
    for(int i = 0; i < list_size; ++i)
    {
	    if(!vertex_list[i].name && !vertex_list[i].info)
	    {
	        vertex_list[i].name = new char[strlen(Name) + 1];
	        strcpy(vertex_list[i].name, Name);
	        
	        vertex_list[i].info = new char[strlen(Info) + 1];
	        strcpy(vertex_list[i].info, Info);
	        return 1;
	    }
    }
    return 0;
}

//function used to get the vertex's index and adress
int map :: get_vertex(char * key)
{
    for(int i = 0; i < list_size; ++i)
    {
        if(!strcmp(vertex_list[i].name, key))
            return i;
    }
    return 0;
}

//insert function for insert adjacency, through the current vertex's name and
//the adjacent vertex's name to make the edge list. -- Wrapper
int map :: insert_edge(char * current_vertex,char * connect_vertex, char * desc, int len)
{

    int refer = get_vertex( connect_vertex );
  
    for(int i = 0; i < list_size; ++i)
    {
        if(!strcmp(current_vertex, vertex_list[i].name))
        {
          
            insert_edge(vertex_list[i].head, refer, desc, len);

        }
    }
    return 1;
}

//insert function for insert adjacency, through the current vertex's name and
//the adjacent vertex's name to make the edge list.
int map :: insert_edge( node *& head, int refer, char * desc, int len)
{
    node * temp = new node; 

    temp -> edge = & vertex_list[refer];

    //strcpy(temp -> description, desc);

    temp -> length = len;
    temp -> next = head;
    head = temp;

    return 1;
}

//For a particular trailhead, display all of the paths that the walker could take
//Wrapper
bool map :: display_all_path(char * current_vertex)
{
    //initial_visit();
    for(int i = 0; i < list_size; ++i)
    {
        if(vertex_list[i].name)
        {
            if(!strcmp(vertex_list[i].name, current_vertex))
            {
                display_all_connections(vertex_list[i].head);
                return true;
            }
        }
        return false;
    }
    return false;
}

//For a particular trailhead, display all of the paths that the walker could take
bool map :: display_all_path(node * head)
{
    if(!head)
        return false;
    cout<<"Path : "<<head -> edge -> name<<endl;
    cout<<"Length : "<<head -> length<<endl;
    return display_all_connections(head -> next)+true; 
}

//Display all connecting vertices from a specified vertex -- Wrapper
bool map :: display_all_connections(char * current_vertex)
{

    for(int i = 0; i < list_size; ++i)
    {
        if(vertex_list[i].name)
        {

            if(!strcmp(vertex_list[i].name, current_vertex))
            {

                display_all_connections(vertex_list[i].head);
                return true;
            }
        }
        return false;
    }
    return false;
}
//Display all connecting vertices from a specified vertex (recursive function)
bool map :: display_all_connections(node * head)
{

    if(!head)
    {

        return false;
    }
    cout<<"vertex : "<<head -> edge -> name<<endl;
    return display_all_connections(head -> next)+true;    
}

//============================test function==============================
/*
void map :: display()
{
    for(int i =0; i < list_size; ++i)
    {
        if(!vertex_list[i].name)
            return;
        cout << vertex_list[i].name <<endl;
    }
}
*/