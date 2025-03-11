#include "Twitter.h"
#include "Array.h"
#include <iostream>
using namespace std;

struct Profile
{
	string username;
	int age{};
	string state;

	bool operator==(const Profile& other) const
	{
		return (username == other.username && age == other.age && state == other.state);
	}

};

ostream& operator<<(ostream& os, const Profile& p)
{
	os << "Username: " << p.username << endl << "Age: " << p.age << endl << "State: " << p.state << endl;
	return os;
}

int question() 
{
	int choice;

	cout << "Would you like to 1. View your followers, 2: Add a follower, 3: Remove a follower, or 4: End? \n(Please make sure you type either 1, 2, 3, or 4)" << endl;
	cin >> choice;
	cout << endl;

	return choice;
}

void Menu(TwitterClass<string>&user, int choice)
{
	if (choice == 1)
	{
		user.PrintFollower();
		choice = question();
		Menu(user, choice);

	}
	else if (choice == 2)
	{
		user.AddFollower();
		choice = question();
		Menu(user, choice);

	}
	else if (choice == 3)
	{
		user.RemoveFollower();
		user.PrintFollower();
		choice = question();
		Menu(user, choice);
	}
	else if (choice == 4) 
	{
		return;
	}
	else
	{
		cout << "You entered in the wrong input." << endl;
		choice = question();
		Menu(user, choice);

	}
}

int main() 
{
	int choice;
	string name;
	string username;
	int age;
	string state;
	int followers = 0;

	cout << "Welcome to Twitter!" << endl;
	cout << "What is your name?\n";
	cin >> name;
	TwitterClass<string> user = { name};

	cout << "\nWhat would you like your username to be?\n";
	cin >> username;
	cout << "\nWhat is your age?\n";
	cin >> age;
	cout << "\nWhat state do you live in?\n";
	cin >> state;
	Profile userp = { username, age, state };
	TwitterClass<Profile> user1(userp);

	cout << "\nSo, your name is set to: " << name <<  endl;
	cout << "Your profile is: \n" << userp << endl;

	choice = question();

	Menu(user, choice);

}
