#include "bits/stdc++.h"
using namespace std;


int main() {
	string input;
	int M;
	list<char> lst;
	char command, ch;
	cin >> input;
	for (auto c : input) {
		lst.push_back(c);
	}
	list<char>::iterator it = lst.end();

	cin >> M;
	while (M--) {
		cin >> command;
		switch (command) {
		case 'L': // left (if first, ignore)
			if (it != lst.begin()) it--;
			break;
		case 'D': // right (if last, ignore)
			if (it != lst.end()) it++;
			break;
		case 'B': // remove character 
			if(it != lst.begin())
				lst.erase(next(it, -1));
			break;
		case 'P':
			cin >> ch;
			lst.insert(it, ch);
			break;
		}
	}
	for (auto c : lst)
		cout << c;
}

