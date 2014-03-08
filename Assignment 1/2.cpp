#include<iostream>
using namespace std;

//Implemented using Doubly Linked List Made from Scratch

//Data Structure Node for Doubly Linked List
struct link{link *next=NULL; link *prev=NULL; int value=2; bool lazy_del=0;};
link *first;
link *last;


main(){
    int value,op;
    link *new_link;
    first=NULL;
    last=NULL;
    while(1){
        do{
            cout<<"\nOperation (1=Push, 2=Pop, 3=Insert, 4=Eject, 5=Diplay List):";
            cin>>op;
        }while(op<1 && op > 4);
        switch (op){
            case 1://Push
                cout<<"\nEnter Element to be Pushed:";
                cin>>value;
                new_link = new link;
                if(first!=NULL){
                    (*new_link).prev=(first);
                    (*first).next=new_link;
                    first = new_link;
                    (*first).value=value;
                }
                else{
                    first = new link;
                    last = first;
                    (*first).value=value;
                }
                break;
            case 2://Pop
                if(last==first && first!=NULL){
                    cout<<"Out = "<<(*first).value<<endl;
                    delete &first;
                    first=NULL;
                    last=NULL;
                }
                else if(first!=NULL){
                    cout<<"Out = "<<(*first).value<<endl;
                    new_link = first;
                    first = (*first).prev;
                    (*first).next=NULL;
                    delete &new_link;
                }
                else{
                    cout<<"Empty List"<<endl;
                }

                break;
            case 3://Insert
                cout<<"\nEnter Element to be Inserted:";
                cin>>value;
                new_link = new link;
                if(last!=NULL){
                    (*new_link).next=(last);
                    (*last).prev=new_link;
                    last = new_link;
                    (*last).value=value;
                }
                else{
                    last = new link;
                    first = last;
                    (*last).value=value;
                }
                break;
            case 4://Eject
                if(last==first && last!=NULL){
                    cout<<"Out = "<<(*last).value<<endl;
                    delete &last;
                    first=NULL;
                    last=NULL;

                }
                else if(last!=NULL){
                    cout<<"Out = "<<(*last).value<<endl;
                    new_link = last;
                    last = (*last).next;
                    (*last).prev=NULL;
                    delete &new_link;

                }
                else{
                    cout<<"Empty List"<<endl;

                }
                break;
            case 5://Display List
                if(first==NULL){
                    cout<<"Empty List !!!"<<endl;
                }
                else{
                    new_link=first;
                    cout<<"List : ";
                    while(new_link!=NULL){
                        cout<<(*new_link).value<<" ";
                        new_link= (*new_link).prev;
                    }
                    cout<<endl;

                }
                break;
        }

    }
}
