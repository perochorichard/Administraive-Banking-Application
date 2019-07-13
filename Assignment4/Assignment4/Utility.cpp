#include <algorithm>
#include "Node.h"
#include "Utility.h"

Node* Utility::mergeSort(Node* start) {
	if (start == NULL || start->next == NULL) {
		return start;
	}
	Node* middle = getMiddle(start);
	Node* nextOfMiddle = middle->next;
	middle->next = NULL;
	Node* left = mergeSort(start);
	Node* right = mergeSort(nextOfMiddle);
	Node* sorted;
	sorted = merge(left, right);
	return sorted;
}

Node* Utility::merge(Node* a, Node* b) {
	// base cases
	if (a == NULL) {
		return b;
	}
	if (b == NULL) {
		return a;
	}

	std::string nameA = a->account->getUsername();
	std::string nameB = b->account->getUsername();
	nameA = normalizeAscii(nameA);
	nameB = normalizeAscii(nameB);

	// if A should be before B (ie. A: 'aa' B: 'ab')
	if (nameA.compare(nameB) <= 0) {
		a->next = merge(a->next, b);
		a->next->prev = a;
		a->prev = NULL;
		return a;
	}
	b->next = merge(a, b->next);
	b->next->prev = b;
	b->prev = NULL;
	return b;
}
// finds middle of the sorted linkedlist
Node* Utility::getMiddle(Node* start) {
	if (start == NULL) {
		return start;
	}
	Node* slowIterator = start;
	Node* fastIterator = start->next;
	while (fastIterator != NULL) {
		fastIterator = fastIterator->next;
		if (fastIterator != NULL) {
			slowIterator = slowIterator->next;
			fastIterator = fastIterator->next;
		}
	}
	return slowIterator;
}
// lowecases all alpha chars for fair ascii comparison
std::string Utility::normalizeAscii(std::string name) {
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);
	return name;
}

// returns JSON format of a single UserAccount
std::string Utility::format(UserAccount* account) {
	std::string formatted = "";
	formatted.append("{\n")
		.append("\"Username\": \"" + account->getUsername() + "\",\n")
		.append("\"Client Name\": \"" + account->getClientName() + "\",\n")
		.append("\"Password\": \"" + account->getPassword() + "\",\n")
		.append("\"Balance\": \"" + std::to_string(account->getBalance()) + "\"\n")
		.append("}");
	return formatted;
}

/*
	All of these methods are fully operational. These were BST related
	methods as I originally intended to use BST as a means of finding
	elements quickly. I was successful, however, I discovered that the program
	was converting from BST to sorted and sorted to BST very frequently,
	making each operation have a worse time-complexity. Therefore, I decided
	to exclude BST from my project. However, I did spend several hours
	implementing BST, so I have decided to leave the BST code here.

	Node* Utility::sortedToBST(Node* first) {
		int n = countNodes(first);

		Node* root = createBST(&first, n);
		return root;
	}

	// recusive call to create sub-trees
	Node* Utility::createBST(Node** rootptr, int n) {
		// base case
		if (n <= 0) {
			return NULL;
		}
		// create left subtree
		Node* left = createBST(rootptr, n / 2);
		// set root
		Node* root = *rootptr;
		// connect left leaf to root
		root->prev = left;
		// update root position for parent calls
		*rootptr = (*rootptr)->next;
		// create right subtree
		root->next = createBST(rootptr, n - (n / 2) - 1);

		return root;
	}

	// in-order traversal conversion
	Node* Utility::BSTToSorted(Node* curr, Node* head) {
		// nil leaf has been reached
		if (curr == NULL) {
			return NULL;
		}
		static Node* prev = NULL;
		// step 1. go to left
		BSTToSorted(curr->prev, head);
		// step 2. process current node
		if (prev == NULL) {
			head = curr;
		}
		else {
			curr->prev = prev;
			prev->next = curr;
		}
		prev = curr;
		// step 3. go to right
		BSTToSorted(curr->next, head);
		return head;
	}

	int Utility::countNodes(Node* first) {
		Node* iterator = first;
		int n = 0;
		while (iterator != NULL) {
			iterator = iterator->next;
			n++;
		}
		return n;
	}
*/