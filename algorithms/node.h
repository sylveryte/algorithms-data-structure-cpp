/*
 * node.h
 * Copyright (C) 2020 sylveryte <sylveryte@archred>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef NODE_H
#define NODE_H

typedef struct node{
	int value;
	struct node* leftchild;
	struct node* rightchild;
	struct node* parent;
	node(int value);
	node();
}node;

#endif /* !NODE_H */
