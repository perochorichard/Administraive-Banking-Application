#include "UserAccount.h"
#include "AccountList.h"
#include "Utility.h"
#include <iostream>
#include <fstream>
AccountList::AccountList() {
	this->first = NULL;
}
Node* AccountList::create_node(UserAccount* account) {
	Node* temp;
	temp = new(Node);
	if (temp != NULL && account != NULL) {
		temp->account = account;
		temp->next = NULL;
		temp->prev = NULL;
		return temp;
	}
	return NULL;
}
// return true if add successful, false otherwise
bool AccountList::add(UserAccount* account) {
	Node* temp;
	temp = create_node(account);
	if (temp == NULL) {
		return false;
	}
	if (first == NULL) {
		first = temp;
		return true;
	}
	temp->next = first;
	first->prev = temp;
	first = temp;
	return true;
}
bool AccountList::remove(std::string username) {
	Node* target = find(username);
	
	if (target == NULL) {
		return false;
	}

	if (target == first) {
		first = target->next;
	}

	if (target->prev != NULL) {
		target->prev->next = target->next;
	}

	if (target->next != NULL) {
		target->next->prev = target->prev;
	}
	
	free(target);
	return true;
}

Node* AccountList::find(std::string username) {
	username = Utility::normalizeAscii(username);
	Node* current = first;
	while (current != NULL) {
		std::string currName = current->account->getUsername();
		currName = Utility::normalizeAscii(currName);
		if (currName.compare(username) == 0) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

void AccountList::sort() {
	first = Utility::mergeSort(first);
}
std::string AccountList::display() {
	Node* ptr = first;
	std::string output;
	while (ptr != NULL)
	{
		output.append(Utility::format(ptr->account) + "\n");
		ptr = ptr->next;
	}
	return output;

}
bool AccountList::save() {
	std::ofstream saveFile;
	saveFile.open("accountData.txt", ios::out | ios::trunc);
	if (saveFile.is_open()) {
		sort();
		Node* iterator = first;
		while (iterator != NULL) {
			saveFile << Utility::format(iterator->account) + ",\n";
			iterator = iterator->next;
		}
		saveFile.close();
		return true;
	}
	else {
		return false;
	}
}
std::string AccountList::retrieveFile() {
	std::string line;
	std::string output;
	std::ifstream saveFile("accountData.txt");
	if (saveFile.is_open()) {
		while (std::getline(saveFile, line)) {
			output.append(line + "\n");
		}
		saveFile.close();
	}
	return output;
}

/*
	find() function using BST method

	Node* AccountList::find(std::string username) {
		sort();
		username = Utility::normalizeAscii(username);
		first = Utility::sortedToBST(first);
		Node* iterator = first;
		do {
			std::string currName = iterator->account->getUsername();
			currName = Utility::normalizeAscii(currName);

			if (currName.compare(username) > 0) {
				iterator = iterator->prev;
			}
			else if (currName.compare(username) < 0) {
				iterator = iterator->next;
			}
			else {
				return iterator;
			}
		} while (iterator != NULL);
		return NULL;
	}
*/