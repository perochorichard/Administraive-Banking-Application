#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H
#include "UserAccount.h"
#include "Node.h"
class AccountList {
private:
	Node* first;
	Node* create_node(UserAccount*);
public:
	AccountList();
	bool add(UserAccount*);
	bool remove(std::string);
	Node* find(std::string);
	bool save();
	void sort();
	std::string display();
	std::string retrieveFile();
};

#endif // !ACCOUNTLIST_H