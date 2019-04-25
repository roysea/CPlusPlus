#include <iostream>
#include<ctype.h>
#include <string>
#include <list>
#include <set>
#include<map>

using namespace std;



int main()
{
	// friend list
	map<string, set<string> > friends;

	friends["Jack"] = { "James" };
	friends["Jack"].insert("Sara");
	friends["Jack"].insert({ "Sara","Bill","Tom", "Raj", "Hamid" });

	friends["Simon"] = { "James" };
	friends["Simon"].insert("Sara");
	friends["Simon"].insert({ "Jack","Bill","Tommy", "Raj", "Hamid" });


	for (auto buddies : friends)
	{
		int i = 0;
		cout << "  " << buddies.first << " has " << friends[buddies.first].size() << " friends: \n";

		for (auto buddy : buddies.second)
		{
			string name = buddy;
			name[0] = toupper(name[0]);
			cout << string(5, ' ') << ++i << ". " << name << "\n";
		}
		cout << endl;
	}
	return 0;
}
