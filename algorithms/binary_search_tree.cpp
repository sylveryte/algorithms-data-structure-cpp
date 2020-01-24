/*
 * binary_search_tree.cpp
 * Copyright (C) 2020 sylveryte <sylveryte@archred>
 *
 * Distributed under terms of the MIT license.
 */

#include "binary_search_tree.h"
#include "../sylvtools.cpp"

int main(){

	binary_search_tree b(21);
	b.insert(21);
	b.insert(1);
	b.insert(23);
	b.insert(233);
	b.insert(4);
	b.print_tree();

	//to sort
	//yeah!! i'm amazing
	int a[13]={12,24,54,2,452,36,23,6,325732,45,2346234,23,1};
	printa("before",a,13);
	binary_search_tree sor(12);
	for(int i=1;i<13;i++)sor.insert(a[i]);
	sor.print_tree();
	sor.get_sorted_array(a);
	printa("after",a,13);

	return 0;
}


//implementations
binary_search_tree::binary_search_tree(int value){
	this -> head = new node(value);
	this -> size = 1;
}


void binary_search_tree::insert(int value){
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
void binary_search_tree::inorder_traverse(int* a, node* n){
	/* takes an empty array a and node from where sorted array needed.
	 * fills array with ascending order node vallues (sorted array) using inorder_traverssal
	 * */
	if(n-> leftchild != nullptr)inorder_traverse(a,n->leftchild);
	a[this -> inorder_index++]=n->value;
	if(n-> rightchild != nullptr)inorder_traverse(a,n->rightchild);
}
void binary_search_tree::get_sorted_array(int* a){
	this -> inorder_index = 0;
	inorder_traverse(a,this->head);
}

/* printing purpose */
void binary_search_tree::print_node(node* ptr){
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
void binary_search_tree::print_tree(){
	cout << "Tree of size : " << this->size << endl;
	print_node(this->head);
	cout <<endl;
}

