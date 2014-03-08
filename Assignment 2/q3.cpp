// Splay Tree

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

int avg_total=0;
int avg_num=0;

struct node {
	int value;
	node *L=NULL, *R=NULL;
	node *parent=NULL;
};

class Tree{
private:


	void double_rotation(node *q){
		node *p= ((*q).parent);
		node *r= ((*p).parent);
		node *s= ((*r).parent);
		avg_total++;
		if(((* p ).value > (*q).value) && ((* r ).value > (*p).value)){
			node * b =(*q).R;
			node * c =(*p).R;
			if(b != NULL) (*b).parent = p;
			(*p).L = (b);
			if(c != NULL) (*c).parent = r;
			(*r).L = (c);
			(*p).parent = q;
			(*q).R= p;
			(*r).parent = p;
			(*p).R= r;
			if(r == Root){
				Root = q;
				(*q).parent=Root;
			}
			else{
				(*q).parent= s;
				if((*s).value > (*p).value){
					(*s).L = q;
				}
				else{
					(*s).R = q;
				}
				splay(q);
			}
		}
		else if(((* p ).value < (*q).value) && ((* r ).value < (*p).value)){
			node * b =(*q).L;
			node * c =(*p).L;
			if(b != NULL) (*b).parent = p;
			(*p).R = (b);
			if(c != NULL) (*c).parent = r;
			(*r).R = (c);
			(*p).parent = q;
			(*q).L= p;
			(*r).parent = p;
			(*p).L= r;
			if(r == Root){
				Root = q;
				(*q).parent=Root;
			}
			else{
				(*q).parent= s;
				if((*s).value > (*p).value){
					(*s).L = q;
				}
				else{
					(*s).R = q;
				}
				splay(q);
			}
		}
		else if(((* p ).value < (*q).value) && ((* r ).value > (*p).value)){
			node * c =(*q).R;
			node * b =(*q).L;
			if(b != NULL) (*b).parent = p;
			(*p).R = (b);
			if(c != NULL) (*c).parent = r;
			(*r).L = (c);
			(*p).parent = q;
			(*q).L= p;
			(*r).parent = q;
			(*q).R= r;
			if(r == Root){
				Root = q;
				(*q).parent=Root;
			}
			else{
				(*q).parent= s;
				if((*s).value > (*p).value){
					(*s).L = q;
				}
				else{
					(*s).R = q;
				}
				splay(q);
			}
		}
		else if(((* p ).value > (*q).value) && ((* r ).value < (*p).value)){
			node * c =(*q).L;
			node * b =(*q).R;
			if(b != NULL) (*b).parent = p;
			(*p).L = (b);
			if(c != NULL) (*c).parent = r;
			(*r).R = (c);
			(*p).parent = q;
			(*q).R= p;
			(*r).parent = q;
			(*q).L= r;
			if(r == Root){
				Root = q;
				(*q).parent=Root;
			}
			else{
				(*q).parent= s;
				if((*s).value > (*p).value){
					(*s).L = q;
				}
				else{
					(*s).R = q;
				}
				splay(q);
			}
		}

	}

	void single_rotation(node *q){
		avg_total++;
		node *p= ((*q).parent);
		node *r= ((*p).parent);
		if( (* p ).value > (*q).value){
			node * b =(*q).R;
			if(b != NULL) (*b).parent = p;
			(*p).L = (b);
			(*p).parent = q;
			(*q).R= p;
			if(p == Root){
				Root = q;
				(*q).parent=Root;
			}
			else {
				(*q).parent= r;
				if((*r).value > (*p).value){
					(*r).L = q;
				}
				else{
					(*r).R = q;
				}
				splay(q);
			}
		}
		else{
			node *b = (*q).L;
			(*p).parent = q;
			(*q).L = p;
			if(b != NULL) (*b).parent = p;
			(*p).R = b;
			if(p == Root){
				Root =q;
				(*q).parent=Root;
			}
			else {
				(*q).parent= r;
				if((*r).value > (*p).value){
					(*r).L = q;
				}
				else{
					(*r).R = q;
				}
				splay(q);
			}
		}
	}

	//Splay Operation
	void splay(node *q){
			node *p= ((*q).parent);
			if(q !=Root){
				if(p == Root){
					single_rotation(q);
				}
				else {
					double_rotation(q);
				}
			}


		}

	//Private Helper Function
	void add_node(int x, node& b){
		if(b.value > x)
			if(b.L== NULL){
				b.L = new node;
				(*(b.L)).value=x;
				(*(b.L)).parent= &b;
				splay((b.L));
			}
			else {
				add_node(x, *b.L);
			}
		else if(b.value < x){
			if(b.R== NULL){
				b.R = new node;
				(*(b.R)).value=x;
				(*(b.R)).parent= &b;
				splay((b.R));
			}
			else {
				add_node(x, *b.R);
			}
		}
	}

	//Private Helper Function
	node *search_tree(int x, node& b){
		if(b.value > x){
			if(b.L == NULL) {
				splay(&b);
				return NULL;
			}
			else return search_tree(x,*b.L);
		}
		else if(b.value < x){
			if(b.R==NULL){
				splay(&b);
				return NULL;
			}
			else return search_tree(x,*b.R);
		}
		else {
			//splay(&b);
			return &b;
		}
	}
	//Helper Function
	node* find_largest(node *q){

		if(q == NULL){
			return NULL;
		}
		else if((*q).R == NULL){
			return q;
		}
		else if((*q).R!= NULL){
			return find_largest((*q).R);
		}
		else {
			return q;
		}
	}

	node* find_smallest(node *q){

			if(q == NULL){
				return NULL;
			}
			else if((*q).L == NULL){
				return q;
			}
			else if((*q).L!= NULL){
				return find_largest((*q).L);
			}
			else {
				return q;
			}
		}

public:
	node *Root=NULL;
	void DisplayTree(){
		std::queue<node> disp;
		disp.push(*Root);
		node y,z= *Root;
		int Level =0;
		int Last;
		while(!disp.empty()){
			z = y;
			y=disp.front();
			Last = Depth(&y);
			if(Level<=Last){
				if(Level>0)cout<<"| -> Lvl: "<<Level<<endl;
				if(Level==1)cout<<" | ";
				Level++;
			}
			disp.pop();
			if(z.parent != y.parent ) cout<<" | ";
			cout<<(y).value<<" ";
			if(((y).L) != NULL)
				disp.push(*((y).L));
			if(((y).R) != NULL)
				disp.push(*((y).R));
		}
		cout<<"| -> Lvl: "<<Level<<endl;

	}


	void Add(int x){
		avg_num++;
		if (Root ==NULL){
			Root = new node;
			(*Root).value=x;
		}
		else{
			add_node( x, *Root);
			(*Root).parent= Root;
		}
		cout<< "\n# Add : "<<x<<endl;
		DisplayTree();
	}

	bool Search(int x){
		avg_num++;
		if (Root ==NULL){
			cout<< "\n# Search : "<<x<<" Empty"<<endl;
			DisplayTree();
			return false;
		}
		else{
			node *b = search_tree(x, *Root);
			if(b==NULL){
				cout<< "\n# Search : "<<x<<" False"<<endl;
				DisplayTree();
				return false;
			}
			else{
				splay(b);
				cout<< "\n# Search : "<<x<<" True"<<endl;
				DisplayTree();
				return true;
			}
		}

	}

	void Delete(int x){
		avg_num++;
		node *temp = search_tree(x, *Root);
		node *b = ((*temp).parent);
		if(temp==Root){
			if((*temp).L != NULL && (*temp).R != NULL){
				node *trans=find_largest((*temp).L);
				if( (*trans).parent == temp ){
					Root = (trans);
					(*trans).parent= Root;
					(*trans).R= (*temp).R;
					if((*temp).R != NULL) (*((*temp).R)).parent = trans;
				}
				else {
					(*((*trans).parent)).R= (*trans).L;
					if((*trans).L !=NULL) (*((*trans).L)).parent =((*trans).parent);

					Root = trans;
					(*trans).parent= Root;

					(*trans).L= (*temp).L;
					if((*temp).L != NULL) (*((*temp).L)).parent = trans;
					(*trans).R= (*temp).R;
					if((*temp).R != NULL) (*((*temp).R)).parent = trans;
				}

				delete temp;

			}
			else if((*temp).L != NULL){

				Root = (*temp).L;
				(*((*temp).L)).parent = (*temp).L;
				delete temp;
			}
			else if((*temp).R != NULL){
				Root = (*temp).R;
				(*((*temp).R)).parent = (*temp).R;
				delete temp;
			}
			else {
				Root =NULL;
				delete temp;
			}
		}
		else if (temp  != NULL){
			if((*b).value < (*temp).value){
//
//				node *trans=find_smallest((*temp).R);
//				if(trans==NULL){
//					if((*temp).L != NULL)(*((*temp).L)).parent= b;
//					(*b).R= (*temp).L;
//				}
//				else {
//					//cout << (*trans).value;
//					(*((*trans).parent)).L= (*trans).R;
//					if((*trans).R !=NULL) (*((*trans).R)).parent =((*trans).parent);
//
//					(*trans).parent= b;
//					(*b).R= trans;
//
//					(*trans).L= (*temp).L;
//					if((*temp).L != NULL) (*((*temp).L)).parent = trans;
//					(*trans).R= (*temp).R;
//					if((*temp).R != NULL) (*((*temp).R)).parent = trans;
//				}
//				delete temp;
//				splay(b);
				node *trans=find_largest((*temp).L);
				if(trans==NULL){
					if((*temp).R != NULL)(*((*temp).R)).parent= b;
					(*b).R= (*temp).R;
				}
				else if( (*trans).parent == temp ){
					(*trans).parent= b;
					(*b).R= trans;
					(*trans).R= (*temp).R;
					if((*temp).R != NULL) (*((*temp).R)).parent = trans;
				}
				else {
					//cout << (*trans).value;
					(*((*trans).parent)).R= (*trans).L;
					if((*trans).L !=NULL) (*((*trans).L)).parent =((*trans).parent);

					(*trans).parent= b;
					(*b).R= trans;

					(*trans).L= (*temp).L;
					if((*temp).L != NULL) (*((*temp).L)).parent = trans;
					(*trans).R= (*temp).R;
					if((*temp).R != NULL) (*((*temp).R)).parent = trans;
				}
				delete temp;
				splay(b);

			}
			else{
				node *trans=find_largest((*temp).L);
				if(trans==NULL){
					if((*temp).R != NULL)(*((*temp).R)).parent= b;
					(*b).L= (*temp).R;
				}
				else if( (*trans).parent == temp ){
					(*trans).parent= b;
					(*b).L= trans;
					(*trans).R= (*temp).R;
					if((*temp).R != NULL) (*((*temp).R)).parent = trans;
				}
				else {
					//cout << (*trans).value;

					(*((*trans).parent)).R= (*trans).L;
					if((*trans).L !=NULL) (*((*trans).L)).parent =((*trans).parent);

					(*trans).parent= b;
					(*b).L= trans;

					(*trans).L= (*temp).L;
					if((*temp).L != NULL) (*((*temp).L)).parent = trans;
					(*trans).R= (*temp).R;
					if((*temp).R != NULL) (*((*temp).R)).parent = trans;
				}
				delete temp;
				splay(b);
			}
		}
		else cout<<"No Such Element";
		cout<< "\n# Delete : "<<x<<endl;
		DisplayTree();
	}

	void DisplayNode(node K){
    	cout<<((K.L==NULL)?"-": "+")<<" "<<K.value<< " "<<((K.R==NULL)?"-": "+");
    }

	void New(int x, node& b,bool d){
		if(d==0){//New On Left
			b.L = new node;
			(*(b.L)).value=x;
			(*(b.L)).parent= &b;
		}
		else{// New on Right
			b.R = new node;
			(*(b.R)).value=x;
			(*(b.R)).parent= &b;
		}
	}
	int Depth(node *K){
		int Level=0;
		while(K != Root){
			K= (*K).parent;
			Level++;
		}
		return Level;
	}
};

int main(){
	Tree t;

	(t.Root) = new node;
	t.Root->value=8;
	t.Root->parent = t.Root;

	//Initialize Full Tree
	t.Add(8);
	t.New(4,*((t.Root)),0);
	t.New(2,(*(t.Root)->L),0);
	t.New(6,(*(t.Root)->L),1);
	t.New(12,*((t.Root)),1);
	t.New(10,(*(t.Root)->R),0);
	t.New(14,(*(t.Root)->R),1);
	t.New(1,(*(t.Root)->L->L),0);
	t.New(3,(*(t.Root)->L->L),1);
	t.New(5,(*(t.Root)->L->R),0);
	t.New(7,(*(t.Root)->L->R),1);
	t.New(9,(*(t.Root)->R->L),0);
	t.New(11,(*(t.Root)->R->L),1);
	t.New(13,(*(t.Root)->R->R),0);
	t.New(15,(*(t.Root)->R->R),1);
	cout<<"\n# Original Tree :"<< endl;
	t.DisplayTree();
	avg_num=0;
	avg_total=0;

	//Search Operations
	for (int i=15;i>0;i--){
		t.Search(i);
	}
	int avg_total1 = avg_total;
	int avg_num1 = avg_num;
	avg_total=0;
	avg_num=0;

	//Delete Operations
	t.Delete(15);
	t.Delete(14);
	t.Delete(4);
	t.Delete(5);
	t.Delete(1);

	cout<<"\nAverage Rotations for Search Operation:"<<(float)avg_total1/avg_num1;
	cout<<"\nAverage Rotations for Delete Operation:"<<(float)avg_total/avg_num;
//	int a;
//	cout<< "Root :";
//	t.DisplayNode( *(t.Root));
//	node* m =(t.Root);
//	while(1){
//		cout<<endl<<"Enter Selection :";
//		cin>>a;
//		if(a==1){
//			cout<<"Add :";
//			cin>>a;
//			t.Add(a);
//			m =(t.Root);
//		}
//		else if(a==2){//Delete
//			cout<<"Delete :";
//			cin>>a;
//			t.Delete(a);
//			m =(t.Root);
//		}
//		else if(a==3){//Current
//			t.DisplayNode(*m);
//		}
//		else if(a==4){//Root
//			cout<<"Root :";
//			t.DisplayNode( *(t.Root));
//		}
//		else if(a==5){//Left
//			m=(*m).L;
//			t.DisplayNode( *(m));
//		}
//		else if(a==6){//Right
//			m=(*m).R;
//			t.DisplayNode( *(m));
//		}
//		else if(a==7){//Up
//			m=(*m).parent;
//			t.DisplayNode( *(m));
//		}
//
//
//	}

}

