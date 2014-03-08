#include<iostream>
using namespace std;
#define n 20
#define k 4
//Data Structure for Node

class link{
public:
    node *point;
    link *next;
};

class node{
public:
    int value;
    link *next;
    next = new link;
    (*.next).point = NULL;
};

class skip_list{
public:
    node *first[k];
    void add(int val);
};
void skip_list::add(int val){

}

main(){
    //Iteratively Create a Linked List with whose value increases from 1 upto n.
    for(int i=0; i<n;i++){
        if(first == NULL){
            first = new link;
            (*first).value=1;
            (*first).next=NULL;
        }
        else {
            add_new((*first).value+1);
        }
    }
    //Print the Linked List
    cout<<"Original Linked List: ";
    new_link=first;
    while( new_link!=NULL){
        cout<<(*new_link).value<<" ";
        new_link=(*new_link).next[1];
    }




}
