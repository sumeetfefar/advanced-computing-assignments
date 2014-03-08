#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define n 20
main(){
    queue<int> a;
    stack<int> S;
    int temp;
    cout<<"Queue a : \n";
    for (int i=1; i <n; i++){
        a.push(i);
        cout<<i<<" ";
    }

    cout<<"\nOriginal Queue";
    //Algorithm starts from here

    //Deque entire queue a and push it into the stack S, O(n)
    for(int i =1; i<n;i++){
        //O(n) Stack Push
        S.push(a.front());
        //O(n) Queue dequeue
        a.pop();
    }
    //a[n-1] is on top of Stack S, a[1] is at the bottom

    //Pop entire stack S and enque into Queue a, O(n)
    for(int i =1; i<n;i++){
        //O(n) Queue Enqueue
        a.push(S.top());
        //O(n) Stack Pop
        S.pop();
    }
    //Now a[1] is at the end of the queu and a[n-1] is at the start

    //Deque entire queue a and push it into the stack S, O(n)
    for(int i =1; i<n;i++){
        //O(n) Stack Push
        S.push(a.front());
        //O(n) Queue dequeue
        a.pop();
    }
    //Below Lines of Code shows elements in stack S with its elements (first-to-last) := (Top-to-Bottom)
    cout<<"\nStack S (from top to bottom) : \n";
    for (int i=1; i <n; i++){
        cout<<S.top()<<" ";
        S.pop();
    }
}
