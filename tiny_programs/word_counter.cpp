#include <iostream>
#include<fstream>
#include<ctype.h>
#include <string>
#include <set>
#include<map>
#include <algorithm>

using namespace std;

void wordCounter(string filename);

int main()
{
	wordCounter("text/mobydick.txt");

	return 0;
}

void wordCounter(string filename)
{
	ifstream input(filename);
	if (!input) cerr << "Failed to open. ";

	map<string, int>wordsTally;

	string word;
	while (input >> word)
	{
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		++wordsTally[word];
	}

	while (true)
	{
		cout << "Enter a word to count? ";
		string word;
		getline(cin, word);
		transform(word.begin(), word.end(), word.begin(), ::tolower);

		if (word == "") break;
		else if (wordsTally[word])
			cout << "Word is repeated:   " << wordsTally[word] << endl;
		else
			cout << "Word is not found!\n";
	}
	for (auto i : wordsTally)
		cout << "(" << i.first << ", " << i.second << ") ";

	input.close();
}
