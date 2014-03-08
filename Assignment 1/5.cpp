#include<iostream>
using namespace std;
#define n 20
//Data Structure for Node
struct link{link *next; int value=2; bool lazy_del=0;};

//Pointer to first element of the list
link *first;

//Mark lazy bit of element of the list to 1
link del(link *ptr){
    (*ptr).lazy_del=1;
}

//Adds a new element to the Front of the list
link add(link *ptr, int value){
    link *new_link;
    new_link = new link;
    (*new_link).next= (*ptr).next;
    (*new_link).value = value;
    (*ptr).next= new_link;
}

//Adds a new element to the Front of the list
link add_new(int value){
    link *new_link;
    new_link = new link;
    (*new_link).next= (first);
    (*new_link).value = value;
    first = new_link;
}

//Delete all the elements with lazy bit == 1 in 1 sweep of the list, O(n)
link sweep(){
    link *new_link;
    link *del_link;
    link *stable_link;

    new_link=first;
    stable_link=NULL;
    while( new_link!=NULL){
        if((*new_link).lazy_del==1){
            del_link = new_link;
            new_link=(*new_link).next;
            delete &del_link;
        }
        else{
            if(stable_link==NULL){
                first=new_link;
                stable_link=new_link;
                new_link=(*new_link).next;
            }
            else{
                (*stable_link).next=new_link;
                stable_link=new_link;
                new_link=(*new_link).next;
            }
        }
    }
}


main(){
    link *new_link;
    (first)=NULL;
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
        new_link=(*new_link).next;
    }


    //Examples of addition of node to linked list
    add((*first).next,15);//node added after the 'node pointed by first node'
    add(first,17);//nodes added after 'first node'

    //Example of addition of a new element value front of the linked list
    add_new(21);//Node with value 21 is added to front of the linked list

    new_link=first;
    //For all elements whose value is odd mark lazy bit ==0
    while( new_link!=NULL){
        if((*new_link).value%2){
            (*new_link).lazy_del=1;
        }
        new_link=(*new_link).next;
    }

    cout<<"\nModified Linked List: ";
    new_link=first;
    while( new_link!=NULL){
        cout<<(*new_link).value<<" ";
        new_link=(*new_link).next;
    }

    //Delete all elements whose lazy bit is set to 1
    sweep();

    cout<<"\nAfter Deletion, Linked List: ";
    new_link=first;
    while( new_link!=NULL){
        cout<<(*new_link).value<<" ";
        new_link=(*new_link).next;
    }


}
