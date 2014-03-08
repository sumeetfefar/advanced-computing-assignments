#include<iostream>
using namespace std;
#define n 10 // Size of linked list

//Data Structure for Node
struct link{link *next=NULL; int value=2; bool lazy_del=0;};

link *first;

//Adds a new element to the Front of the list
link add_new(int value){
    link *new_link;
    new_link = new link;
    (*new_link).next= (first);
    (*new_link).value = value;
    first = new_link;
}


main(){
    link *new_link;
    (first)=NULL;
    //Iteratively Create a Linked List with Nodes whose value increases from 1 upto n.
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
        new_link=(*new_link).next;
    }

    link *carry;
    link *next;
    new_link = (*first).next;
    carry=first;
    while((new_link)!=NULL){
        next = (*new_link).next;
        (*new_link).next=carry;
        carry=new_link;
        new_link=next;
    }
    (*first).next=NULL;
    first=carry;

    //Print Reverse the Linked List
    cout<<"\nReversed Linked List: ";
    new_link=first;
    while( new_link!=NULL){
        cout<<(*new_link).value<<" ";
        new_link=(*new_link).next;
    }
}
