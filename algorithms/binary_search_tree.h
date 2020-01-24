/*
 * binary_search_tree.h
 * Copyright (C) 2020 sylveryte <sylveryte@archred>
 *
 * Distributed under terms of the MIT license.
 */


#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "node.h"
#include "node.cpp"

typedef struct binary_search_tree{

	node* head;
	int size;
	int inorder_index;

	binary_search_tree(int);

	void insert(int);
	void inorder_traverse(int*, node*);
	void get_sorted_array(int*);
	void print_node(node*);
	void print_tree();
}binary_search_tree;



#endif /* !BINARY_SEARCH_TREE_H */
