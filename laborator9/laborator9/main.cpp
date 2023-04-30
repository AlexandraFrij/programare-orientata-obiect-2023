#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <fstream>

using namespace std;

int main()
{
	ifstream f("input.txt");
	if (!f.is_open())
		cout << "Couldn't open file";
	string phrase;
	getline(f, phrase);
	map <string, int> m;
	size_t found = phrase.find_first_of(", .!?");
	int precedent = 0;
	while (found != std::string::npos)
	{
	
		string s = phrase.substr(precedent, found);
		for (unsigned int i = 0; i < s.size(); ++i)
			if (isupper(s[i]))
				s[i] = tolower(s[i]);
		m[s]++;
		precedent = found;
		found = phrase.find_first_of(", .!?", found + 1);
	}
	struct compare {
		bool operator()(pair<string, int>& left, pair<string, int>& right)
		{
			if (left.first > right.first)
				return true;
			else return left.second > right.second ;
		}
	};
	priority_queue<pair<string, int>, vector<pair<string, int>>, compare>per;
	for (auto i = m.begin(); i != m.end(); i++)
	{
		pair<string, int>p;
		p.first = i->first;
		p.second = i->second;
		per.push(p);
	}
	while (!per.empty())
	{
		cout << per.top().first << ' ' << per.top().second  << endl;
		per.pop();
	}

	return 0;
}
