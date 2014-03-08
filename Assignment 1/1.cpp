#include<iostream>
using namespace std;
#define n 10

main(){

    int a[n],stack0,stack1,stack_sel,op;
    int stack_point[2], divide;
    divide = 5;

    stack_point[0] = 4;
    stack_point[1] = 5;

    while(1){
        do{
        cout<<"\nChoose Stack (1 or 0):";
        cin>>stack_sel;
        }while(stack_sel !=0 && stack_sel !=1 );
        do{
        cout<<"\nOperation (1=Push, 2=Pop, 3=Peek, 4=isempty):";
        cin>>op;
        }while(op<1 && op > 4);

        switch (op){
            case 1: // Push
                if(stack_point[0]==-1 && stack_point[1]==n ) cout<<"Stack Overflow";
                else if(stack_sel==0){
                    if(stack_point[0]!=-1){
                        cout<<"\nEnter Element to be pushed in array :";
                        cin>>a[stack_point[0]];
                        stack_point[0]--;
                    }
                    else{
                        for (int i=stack_point[1]-1; i >=0; i--){
                            a[i+1]=a[i];
                        }
                        cout<<"\nEnter Element to be pushed in array :";
                        cin>>a[0];
                        divide++;
                        stack_point[1]++;
                    }
                }
                else if(stack_sel==1){
                    if(stack_point[1]!=(n)){
                        cout<<"\nEnter Element to be pushed in array :";
                        cin>>a[stack_point[1]];
                        stack_point[1]++;
                    }
                    else{
                        for (int i=stack_point[0]+1; i <=n-1; i++){
                            a[i-1]=a[i];
                        }
                        cout<<"\nEnter Element to be pushed in array :";
                        cin>>a[n-1];
                        divide--;
                        stack_point[0]--;
                    }
                }
                break;
            case 2: //Pop
                if(stack_sel==0){
                    if(divide-stack_point[0]==1) cout<<"Stack 0 is empty";
                    else{
                        stack_point[0]++;
                        cout<<a[stack_point[0]];

                    }
                }
                else if(stack_sel==1){
                    if(divide-stack_point[1]==0) cout<<"Stack 1 is empty";
                    else{
                        stack_point[1]--;
                        cout<<a[stack_point[1]];

                    }
                }
                break;
            case 3: //Peek
                if(stack_sel==0){
                    if(divide-stack_point[0]==1) cout<<"Stack 0 is empty";
                    else{
                        cout<<a[stack_point[0]+1];

                    }
                }
                else if(stack_sel==1){
                    if(divide-stack_point[1]==0) cout<<"Stack 1 is empty";
                    else{
                        cout<<a[stack_point[1]-1];

                    }
                }
                break;
            case 4: //isempty
                if(stack_sel==0){
                    if(divide-stack_point[0]==1) cout<<"Stack 0 is empty";
                    else{cout<<"Stack 1 is not empty";
                    }
                }
                else if(stack_sel==1){
                    if(divide-stack_point[1]==0) cout<<"Stack 1 is empty";
                    else{cout<<"Stack 1 is not empty";
                    }
                }
                break;
            case 5://Debug
                cout<<"\n";
                for(int i=0; i<n; i++){
                    cout<<a[i];
                    cout<<" ";
                }
                cout<<"\n";
                cout<<stack_point[0];
                cout<<"\n";
                cout<<stack_point[1];
            }
    }
}
