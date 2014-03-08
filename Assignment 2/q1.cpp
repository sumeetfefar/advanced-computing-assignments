//MIN - HEAP
//Sumeet Fefar, 10D070001
#include <iostream>
#include <stdio.h>

using namespace std;

class heap{
private:

	int n = 30;
	int s = 0;
	int offset = 0;
	int array[30];



	void array_swap(int a, int b){
		int temp = array[a];
		array[a] = array[b];
		array[b] = temp;
	}

	int child_min(int a){
		if (a<s)
			if(array[a] > array[a+1]) return a+1;
			else return a;
		else if(a==s) return a;
		else  return s+1;
	}
	int parent_of(int child){ return ((child+1)/2 -1);}
	int children_of(int parent){ return (2*parent + 1);}

	void bubbleup(int child){
		if(child > 0){
			int parent_s=parent_of(child);

			if(array[child] < array[parent_s]){
				array_swap(child, parent_s);
				bubbleup(parent_s);
			}
		}
	};
	void bubbledown(int parent){
		if(parent < s){
			int child_s = child_min(children_of(parent));
			if(child_s <= s) {
				array_swap(parent,child_s);
				bubbledown(child_s);
			}

		}

	};


public:
	void ShowArray(void){ //Print array with Size
		cout<<endl<< "array :";
		for(int i=0; i<s;i++){
			cout <<" "<<array[i]+offset;
		}
		cout << " | size :" <<s;
	}
	int Size(void){
		return s;
	}
	bool isEmpty(void){
		return (s==0);
	}
	int Get(void){
		if(s>0){
			int ans = array[0]+offset;
			array[0] = array[s-1];
			s--;

			bubbledown(0);
			return ans;
		}
		else{
			ShowArray();
			return 0;
		}

	}
	void Add(int x){
		if (s<n){
			array[s]=x-offset;
			bubbleup(s);
			s++;
		}


	}
	void DecreaseAllKeys(int delta){
		offset = offset - delta;
	}

	void Initialize(int a, int b){
		for(int i=a; i<=b;i++){
			Add(i);
		}

	}

};

int main(){

	heap a;

	//Test Case
	cout<<"**Min-Heap**"<<endl;
	a.Initialize(5,18);
	a.ShowArray();
	a.DecreaseAllKeys(2);
	a.ShowArray();
	a.Add(19);
	a.ShowArray();
	a.Add(18);
	a.ShowArray();

	cout<<"\nGet :"<<a.Get();
	a.ShowArray();
	cout<<"\nGet :"<<a.Get();
	a.ShowArray();
	cout<<"\nGet :"<<a.Get();
	a.ShowArray();
}
