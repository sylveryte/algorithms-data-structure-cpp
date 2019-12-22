#include<iostream>
#include "../sylvtools.cpp"

typedef struct node{
	//int subtree_count;//augmenting bst can add additional feature
	int value;
	struct node* leftchild=nullptr;
	struct node* rightchild=nullptr;
	struct node* parent=nullptr;
	node(int value){this->value = value;}
	node(){this->value = -9999;}
}node;

typedef struct bst{
	node* head;
	int size;
	int inorder_index;

	
	bst(int value){
		this -> head = new node(value);
		this -> size = 1;
	}


	void insert(int value){
		node* node_ptr = this -> head;
		while(true)
			if(node_ptr -> value >= value){
				//cout << "arg " << node_ptr-> value << " <= " << value << endl;
				//cout << "adding " << value << " to left" << endl;
				if( node_ptr -> leftchild == nullptr) {
					node_ptr -> leftchild = new node(value);
					node_ptr -> leftchild -> parent = node_ptr;
					this -> size++;
					break;
				}
				node_ptr = node_ptr -> leftchild;
			}
			else{
				//cout << "arg " << node_ptr-> value << " > " << value << endl;
				//cout << "adding " << value << " to rigth" << endl;
				if( node_ptr -> rightchild == nullptr) {
					node_ptr -> rightchild = new node(value);
					node_ptr -> rightchild -> parent = node_ptr;
					this -> size++;
					break;
				}
				node_ptr = node_ptr -> rightchild;
			}
	}
	void inorder_traverse(int* a, node* n){
		if(n-> leftchild != nullptr)inorder_traverse(a,n->leftchild);
		a[this -> inorder_index++]=n->value;
		if(n-> rightchild != nullptr)inorder_traverse(a,n->rightchild);
	}
	void get_sorted_array(int* a){
		this -> inorder_index = 0;
		inorder_traverse(a,this->head);
	}
	void print_node(node* ptr){
		if(ptr -> leftchild == nullptr &&
				ptr -> rightchild == nullptr)return;
		cout << "|| " << ptr -> value << " : ";
		if(ptr->leftchild != nullptr){ 
			cout << ptr-> leftchild-> value ;
		}
		cout<< " _ ";
		if(ptr->rightchild != nullptr){
			cout << ptr-> rightchild-> value ;
		}
		cout << " ||" << endl;
		if(ptr->leftchild != nullptr)print_node(ptr->leftchild);
		if(ptr->rightchild != nullptr)print_node(ptr->rightchild);
	}
	void print_tree(){
		cout << "Tree of size : " << this->size << endl;
		print_node(this->head);
		cout <<endl;
	}
}bst;

int main(){

	bst b(21);
	b.insert(21);
	b.insert(1);
	b.insert(23);
	b.insert(233);
	b.insert(4);
	b.print_tree();

	//to sort
	//fuck!! i'm amazing
	int a[13]={12,24,54,2,452,36,23,6,325732,45,2346234,23,1};
	printa("before",a,13);
	bst sor(12);
	for(int i=1;i<13;i++)sor.insert(a[i]);
	sor.print_tree();
	sor.get_sorted_array(a);
	printa("after",a,13);

	return 0;
}
