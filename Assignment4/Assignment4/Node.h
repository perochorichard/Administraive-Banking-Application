#ifndef NODE_H
#define NODE_H
#include "UserAccount.h"
struct Node {
	UserAccount* account;
	Node* next;
	Node* prev;
};

#endif // !NODE_H
