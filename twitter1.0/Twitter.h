#ifndef TWITTERCLASS_H
#define TWITTERCLASS_H

#include <iostream>
#include <string>
#include "Array.h"
using namespace std;

template <typename T>
class TwitterClass
{

public:
	T twitterUser;
	int numoffollowers;
	Array<string> nums;

	TwitterClass(T user) : twitterUser(user), nums(2)
	{
		numoffollowers = 0;
	}

	void AddFollower();
	void PrintFollower() const;
	void RemoveFollower();

};

template <typename T>
void TwitterClass<T> :: AddFollower()
{
	string follower;
	int size = nums.length();
	int i = 0;

	cout << "What is the username of the follower you would like to add?\n";
	cin >> follower;

	if (nums.length() == numoffollowers)
	{
		nums.changeSize(size * 2);
		cout << "\nFollower list was full. Doubling the size! \n";
		AddFollower();
	}
	else
	{
		for (i = 0; i < nums.length(); i++)
		{

			if (!nums[i].empty())
			{
				continue;
			}
			else
			{
				nums[i] = follower;
				numoffollowers++;
				break;
			}
		}
	}

	cout << "\n";

}

template <typename T>
void TwitterClass<T> :: PrintFollower() const
{
	cout << "You have " << numoffollowers << " followers.\n";
	cout << "Your followers are: " << endl;

	for (int i = 0; i < nums.length(); i++)
	{
		if (nums[i].empty())
		{
			continue;
		}
		else
		{
			cout << i + 1 << ": " << nums[i] << endl;
		}

	}

	cout << "\n";
}

template <typename T>
void TwitterClass<T> :: RemoveFollower()
{
	string follower;
	int i = 0;
	int used = 0;
	int newSizeT = 0;
	int oldSize = nums.length();

	cout << "What is the username of the follower you would like to remove?" << endl;
	cin >> follower;
	cout << endl;


	for (i = 0; i < nums.length(); i++)
	{

		if (nums[i] == follower)
		{
			nums[i] = "";
			numoffollowers--;
			cout << follower << " removed! \n";
			break;
		}
		else
		{
			continue;
		}

	}

	if (i == nums.length())
	{
		cout << "Follower not found.\n" << endl;
	}

	for (i = 0; i < nums.length(); i++)
	{

		if (!nums[i].empty())
		{
			used++;
		}

	}

	if (used < (nums.length() * 0.25))
	{
		newSizeT = oldSize / 2;
		nums.changeSize(newSizeT);
		cout << "Since followers list had less than 25% of the list being utilized the size was cut in half.\n";
	}

}
#endif


