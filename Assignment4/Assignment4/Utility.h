#ifndef UTILITY_H
#define UTILITY_H
#include "Node.h"
class Utility {
private:
	static Node* getMiddle(Node*);
	static Node* merge(Node*, Node*);
public:
	static Node* mergeSort(Node*);
	static std::string normalizeAscii(std::string);
	static std::string format(UserAccount*);

	/*
		static int countNodes(Node*);
		static Node* createBST(Node**, int);
		static Node* sortedToBST(Node*);
		static Node* BSTToSorted(Node*, Node*);
	*/
};

#endif // !UTILITY_H