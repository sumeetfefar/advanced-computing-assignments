#include<iostream>
//#include<stack>
using namespace std;
#define n 15

//With Custom Made Data Structures Stack And Queue

class node{
public:
    int value;
    node *next;
    node *prev;
};

class queue{
public:
    node *first;
    node *last;
    void enqueue(int val);
    int dequeue(void);
    void init(void);
};
void queue::init(void){
    first=NULL;
    last=NULL;
}
void queue::enqueue(int val){
        if(first==last && first==NULL){
            first = new node;
            last=first;
            (*first).value = val;
            (*first).next = NULL;
            (*first).prev = NULL;
        }
        else{
            node *new_node;
            new_node = new node;
            (*new_node).value = val;
            (*new_node).next = last;
            (*new_node).prev = NULL;
            (*last).prev = new_node;
            last = new_node;
        }
}
int queue::dequeue(void){
        if(first==last && first ==NULL){
            cout<<"\nEmpty Queue";
            return NULL;
        }
        if(first==last && first !=NULL){
            int temp;
            temp = (*first).value;
            delete &first;
            first=NULL;
            last=NULL;
            return temp;
        }
        else{
            int temp;
            node *new_node;
            temp = (*first).value;
            new_node = first;
            first = (*first).prev;
            (*first).next = NULL;
            delete &new_node;
            return temp;
        }
}


class link{
public:
    int value;
    link *next;
};
class stack{
public:
    link *top;
    void push(int val);
    int pop(void);
    void init(void);
};
void stack::init(void){
    top=NULL;
}
void stack::push(int val){
    if(top==NULL){
        top = new link;
        (*top).value=val;
    }
    else{
        link *new_link;
        new_link = new link;
        (*new_link).value=val;
        (*new_link).next=top;
        top = new_link;
    }
}
int stack::pop(void){
    if(top==NULL){
        cout<<"\nEmpty List";
        return NULL;
    }
    else{
        int temp;
        temp = (*top).value;
        link *new_link;
        new_link = top;
        top = (*top).next;
        delete &new_link;
        return temp;
    }
}

main(){
    queue a;
    a.init();
    stack S;
    S.init();
    int temp;
    cout<<"Queue a : \n";
    for (int i=1; i <n; i++){
        a.enqueue(i);
        cout<<i<<" ";
    }

    cout<<"\nOriginal Queue";
    //Algorithm starts from here

    //Deque entire queue a and push it into the stack S, O(n)
    for(int i =1; i<n;i++){
        //O(n) Stack Push
        S.push(a.dequeue());
        //O(n) Queue dequeue
        //a.pop();
    }
    //a[n-1] is on top of Stack S, a[1] is at the bottom

    //Pop entire stack S and enque into Queue a, O(n)
    for(int i =1; i<n;i++){
        //O(n) Queue Enqueue
        a.enqueue(S.pop());
        //O(n) Stack Pop

    }
    //Now a[1] is at the end of the queu and a[n-1] is at the start

    //Deque entire queue a and push it into the stack S, O(n)
    for(int i =1; i<n;i++){
        //O(n) Stack Push
        S.push(a.dequeue());
        //O(n) Queue dequeue
        //a.pop();
    }
    //Below Lines of Code shows elements in stack S with its elements (first-to-last) := (Top-to-Bottom)
    cout<<"\nStack S (from top to bottom) : \n";
    for (int i=1; i <n; i++){
        cout<<S.pop()<<" ";

    }

}
