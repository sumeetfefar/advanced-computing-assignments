#include<iostream>
#include<list>
using namespace std;
//Implemented using inbuilt Doubly Linked List
main()
{
    list<int> D; //D is a deque implemented using list data-type of c++ which is doubly linked list
    int op,temp;
    list<int>::iterator it;// iterator used to point elements in list
    while(1){
        do{
            cout<<"\nOperation (1=Push, 2=Pop, 3=Insert, 4=Eject):";
            cin>>op;
        }while(op<1 && op > 4);
        switch (op){
            case 1://Push
                cout<<"\nEnter Element to be Pushed:";
                cin>>temp;
                it=D.begin();
                D.insert(it,temp);
                break;
            case 2://Pop
                it = D.begin();
                cout<<*it;
                D.erase(it);
                break;
            case 3://Insert
                cout<<"\nEnter Element to be Inserted:";
                cin>>temp;
                it = D.end();
                D.insert(it,temp);
                break;
            case 4://Eject
                it = D.end();
                it--;
                cout<<*it;
                D.erase(it);
                break;
        }

    }


}
