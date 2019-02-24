//
//  BST.cpp
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

tree::tree()    //constructor
{
    root = NULL;
}

tree::~tree()   //destructor
{
    delete_all(root);
}

bool tree::delete_all(node *& root) //function used to deallocate all the dynamically allocate element
{
    if(!root)
	    return false;
    delete_all(root -> left);
    delete_all(root -> right);

    deallocate_node(root);
    
	
    delete root;
    root = NULL;

    return true;
}

// read information from event.txt and store into binary search tree
bool tree :: read_file()
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
    {
        cout<<"!!!!!!!!!!-----Can't Open 'event.txt' File-----!!!!!!!!!! \n";
        f_in.close();
        return false;
    }   
    f_in.close();
    return true;  
}

// create file and load information into this file
bool tree :: create_file(char * Name, char * Location, char * Date, char * Time, char * Description, char * Keywords)
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
    {
        cout<<"!!!!!!!!!!-----Can't Open 'event.txt' File-----!!!!!!!!!! \n";
        f_out.close();
        return false;
    }   
    f_out.close();
    return true;
}

//insert function - Wrapper
bool tree :: insert(char * Name, char * Loca, char * Date, char * Time, char * Desc, char * Keywords)
{
    return insert(Name, Loca, Date, Time, Desc, Keywords, root);
}

//insert function
bool tree :: insert(char * Name, char * Loca, char * Date, char * Time, char * Desc, char * Keywords, node *& root)
{
    if(!root)
    {
        node * temp = new node;
        temp -> left = NULL;
        temp -> right = NULL;
        
        temp -> name = new char[strlen(Name) + 1];
        strcpy(temp -> name, Name);
        
        temp -> location = new char[strlen(Loca) + 1];
        strcpy(temp -> location, Loca);
        
        temp -> date = new char[strlen(Date) + 1];
        strcpy(temp -> date, Date);
    
        temp -> time =  new char[strlen(Time) + 1];
        strcpy(temp -> time, Time);
    
        temp -> description =  new char[strlen(Desc) + 1];
        strcpy(temp -> description, Desc);
    
        temp -> keywords =  new char[strlen(Keywords) + 1];
        strcpy(temp -> keywords, Keywords);
        
        root = temp;
        return true;
    }
    
    else if(strcmp(root -> name, Name) > 0)
	    insert(Name, Loca, Date, Time, Desc, Keywords, root -> left);
    else
	    insert(Name, Loca, Date, Time, Desc, Keywords, root -> right);
	return true;
}

//find the inorder successor
node * tree :: inorder_successor(node *& root)
{
    if(!root)
    {
	    root = NULL;
	    return root;
    }
    if(root -> left == NULL)
    {
	    return root;
    }
    else
	    return inorder_successor(root -> left);
}

//remove by name
node *& tree :: remove(char * Name)
{
    return remove(Name, root);
}

//remove all event has particular keywords
node *& tree :: remove_all(char * Keywords)
{
    return remove(Keywords, root);
}

//deallocate the data dynamically allocated in the node
bool tree :: deallocate_node(node *& root)
{
    if(!root)
        return false;
    delete []root -> name;
    delete []root -> location;
    delete []root -> date;
    delete []root -> time;
    delete []root -> description;
    delete []root -> keywords;
    
    root ->  name= NULL;
	root ->  location= NULL;
	root ->  date= NULL;
	root ->  time= NULL;
	root ->  description= NULL;
	root ->  keywords= NULL;
    return true;
}

//copy date from other node
bool tree :: copy(node * root, node * from)
{
    if(!root)
        return false;
    strcpy(root -> name, from -> name);
    strcpy(root -> location, from -> location);
    strcpy(root -> date, from -> date);
    strcpy(root -> time, from -> time);
    strcpy(root -> description, from -> description);
    strcpy(root -> keywords, from -> keywords);

    return true;
}

//remove by name recursively
node *& tree :: remove(char * Name, node *& root)
{
    if(!root)
	    return root;

    //Three cases for removing one node in the tree

    if(strcmp(Name,root -> name) == 0)
    { 
	    //[1]. NO CHILDREN
	    if(!root -> left && !root -> right)
	    {
	        deallocate_node(root);
	        
	        delete root;
	        root = NULL;
	        
	        return root;
	    }
	    //[2]. ONE CHILDREN
	    else if(!root -> left && root -> right)
	    {
	        node * temp = root;
	        root = root -> right;
	        deallocate_node(temp);
	        delete temp;
	        temp = NULL;
	        
	        return root;
	    }
	    
	    else if(!root -> right && root -> left)
	    {
	        node * temp = root;
            root = root -> left;
	        deallocate_node(temp);
	        delete temp;
	        temp = NULL;
	        
	        return root;
	    }
	
	    //[3]. TWO CHILDREN
	    else
	    {
	        node * temp = inorder_successor(root -> right);
	        //copy data
	        copy(root,temp);
            root->right = remove(temp -> name, root->right);
	    }
	
    }
    if(Name[0] < root -> name[0])
	    return remove(Name,root -> left);
    else
	    return remove(Name,root -> right);
	return root;
}


//remove all events based on keywords
node *& tree :: remove_all(char * Keywords, node *& root)
{
    if(!root)
	    return root;

    //Three cases for removing one node in the tree

    if(strcmp(Keywords,root -> keywords) == 0)
    { 
	    //[1]. NO CHILDREN
	    if(!root -> left && !root -> right)
	    {
	        deallocate_node(root);
	        
	        delete root;
	        root = NULL;
	        
	        return root;
	    }
	    //[2]. ONE CHILDREN
	    else if(!root -> left && root -> right)
	    {
	        node * temp = root;
	        root = root -> right;
	        deallocate_node(temp);
	        delete temp;
	        temp = NULL;
	        
	        return remove_all(Keywords, root);
	    }
	    
	    else if(!root -> right && root -> left)
	    {
	        node * temp = root;
            	root = root -> left;
	        deallocate_node(temp);
	        delete temp;
	        temp = NULL;
	        
	        return remove_all(Keywords, root);
	    }
	
	    //[3]. TWO CHILDREN
	    else
	    {
	        node * temp = inorder_successor(root -> right);
	        //copy data
	        copy(root,temp);
            root->right = remove_all(temp -> keywords, root->right);
            
            if(Keywords[0] < root -> keywords[0])
	            return remove_all(Keywords,root -> left);
            else
	            return remove_all(Keywords,root -> right);
	    }
	
    }
    if(Keywords[0] < root -> keywords[0])
	    return remove_all(Keywords,root -> left);
    else
	    return remove_all(Keywords,root -> right);
	return root;
}


//retrieve function - Wrapper
node * tree :: retrieve(char * Name)
{
    return retrieve(Name,root);
}

//retrieve function recursively
node * tree :: retrieve(char * Name, node * root)
{
    if(!root)
    {
	    root = NULL;
	    return root;
    }
    if(strcmp(Name,root -> name) == 0)
	    return root;
    
    if(Name[0] < root -> name[0])
	    return retrieve(Name,root -> left);
    else
	    return retrieve(Name,root -> right);
}

//display specific event by name
bool tree :: display_name(node * root)
{
    return display(root);
}

//function used to help display specific information
bool tree :: display(node * root)
{
    if(!root)
        return false;
    cout<<"Event Name: "<<root -> name<<endl;
    cout<<"Event Location: "<<root -> location<<endl;
    cout<<"Event Date: "<<root -> date<<endl;
    cout<<"Event Time: "<<root -> time<<endl;
    cout<<"Event Description: "<<root -> description<<endl;
    cout<<"Event Keywords: "<<root -> keywords<<endl;
    return true;
}

//display all event Wrapper
bool tree :: display_all()
{
    return display_all(root);
}

//display all event recursively
bool tree :: display_all(node * root)
{
    if(!root)
        return false;
    display_all(root->left);
    display(root);
    display_all(root->right);
    return true;
}
