HW 1 Additions:

Write a Twitter class that sets the Twitter user first (who’s to be followed) and lets the
client add up to 5 followers. These users/followers could be in form of string or Profile1
At any time your main program should be able to remove any given user from the
follower list, which will be stored in an array with a capacity of 5. You need to have a
function which can print all followers at any time and calling this function after a
removal is a requirement. You are free to design your program with your own will as
long as you fulfill the followings:
1. Main program should use the Twitter class template, which you should write in a
separate .h file. (10 points)
2. In the main program two types objects need to be created, i.e.,
a. Twitter<string> (10 points)
b. Twitter<Profile> (10 points)
where Profile is a struct that contains three fiels (username, age, state)
3. A constructor which does initialization for the followed user and number of
followers. (5 points)
4. AddFollower function (10 points)
5. RemoveFollower function (10 points)
(Hint: you may need to check whether the given user and the array member are
equal to each other. Profile struct may require an overloaded operator ==)
6. PrintFollower function. (10 points) (This should be called after removal of a user)
(Hint: cout<< works with string, but you should add the overloaded operator
below in your code to be able to print a Profile object)
7. Submitting a main program with a header file, even if it doesn’t work (35 points)


HW 2 Additions:

Modify your HW1 in a way that your followers should be stored in an Array object (a dynamic array created by Array class). That means you should use the Array class we discussed in the class.  (See the Chapter 5 slides.)
Do your initializations with the constructor. I recommend you to start with an Array object of size 2.

Instead of working with a fixed size array, your program should change the size of the array when it is full or only a small portion of the current capacity is used. Therefore, you should use changeSize() function inside addFollower() and removeFollower() functions.
You should call changeSize() to double the size when the array is full.
You should call changeSize() to cut the array into half if less than 25% of the array is being utilized.
