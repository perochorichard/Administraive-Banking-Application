#ifndef USERACCOUNT_H
#define USERACCOUNT_H
#include <string>
using namespace std;
class UserAccount {
private:
	string username;
	string clientName;
	string password;
	double balance;
public:
	UserAccount(string, string, string, double);

	bool setUsername(string);
	string getUsername();

	bool setClientName(string);
	string getClientName();

	bool setPassword(string);
	string getPassword();

	bool deposit(double);
	double getBalance();
};

#endif USERACCOUNT_H
