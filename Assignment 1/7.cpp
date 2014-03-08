#include<iostream>
using namespace std;
#define n 10 // Size of linked list

//Data Structure for Node
struct link{link *next=NULL; int value=2;};

link *first;


int get(int N){
    link *new_link;
    link *carry;
    new_link = first;
    int k =N;
    //Obtain The Node with Index N
    while(N>0){
        if(new_link!=NULL){
            carry=new_link;
            new_link=(*new_link).next;
            N--;
        }
        //If maximum number of Nodes in List exceeds N, Then Index out of Range
        if(new_link==NULL) {
            cout<<"\nIndex Out of Range";
            return NULL;
        }
    }
    //Take the Node to front of the List, if it was not already on the front
    if(k>0){
        (*carry).next=(*new_link).next;
        (*new_link).next=first;
        first=new_link;
    }
    return (*new_link).value;
}

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
    int op;
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

    while(1){
        cout<<"\nGet Index (-1 for entire List): ";
        cin>>op;
        if(op>=0){
            cout<<endl<<get(op);
        }
        else {
            cout<<"\nNew Linked List: ";
            new_link=first;
            while( new_link!=NULL){
                cout<<(*new_link).value<<" ";
                new_link=(*new_link).next;
            }
        }
    }

}
