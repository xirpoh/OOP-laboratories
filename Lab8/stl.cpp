#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

ifstream fin("sentence.txt");

size_t findDelim(string s, vector<string> delims) 
{
    size_t min_pos = string::npos;
    for (auto d : delims) {
        size_t pos = s.find(d);
        if (pos != string::npos && pos < min_pos)
            min_pos = pos;
    }
    return min_pos;
}

struct cmp 
{
	bool operator()(pair<string, int> a, pair<string, int> b) {
		if (a.second == b.second)
			return a.first > b.first;
		return a.second < b.second;
	}
};

int main()
{
    string s;
    vector<string> delims = {" ", ",", "?", "!", "."};

    getline(fin, s);
    transform(s.begin(), s.end(), s.begin(),
    [](unsigned char c){ return tolower(c); });

	vector<string> v;
    size_t pos = 0;
    while ((pos = findDelim(s, delims)) != string::npos) {
        string w = s.substr(0, pos);
        if (w.size()) v.push_back(w);
        s.erase(0, pos + 1); 
    }

	vector<string> uniq;
	map<string, int> mp;
	for (auto word : v) {
		if (mp[word] == 0)
			uniq.push_back(word);
		mp[word]++;
	}

	vector<pair<string, int>> frq;
	for (auto str : uniq)
		frq.push_back(make_pair(str, mp[str]));

	priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
	for (auto it : frq) pq.push(it);

	while (!pq.empty()) {
		cout << pq.top().first << " => " << pq.top().second << "\n";
		pq.pop();
	}

    return 0;
}
