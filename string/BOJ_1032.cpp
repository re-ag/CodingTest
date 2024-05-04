#include <iostream>
#include <string>
using namespace std;
/*
	BOJ 1032 "명령 프롬프트"
	https://www.acmicpc.net/problem/1032
*/

int main()
{
	int N;
	cin >> N;
	string input;
	cin >> input;
	for (int i = 0; i < N-1; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < input.length(); j++) {
			if (input[j] != temp[j]) {
				input[j] = '?';
			}
		}
	}
	cout << input << '\n';
}
