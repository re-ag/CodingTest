#include <iostream>
#include <list>

using namespace std;

int main() {
  list<int> lst;
  int N, K;
  cin >> N >> K;
  for (int i = 1; i <= N; i++)
    lst.push_back(i);

  auto it = lst.begin();

  cout << "<";
  while (!lst.empty()) {
    for (int i = 0; i < K-1; i++) {
      if (it == lst.end())
        it = lst.begin();
      ++it;
      if (it == lst.end())
        it = lst.begin();
    }
    cout << *it;
    if (lst.size() > 1)
      cout << ", ";
    else
      cout << ">\n";
    it = lst.erase(it);
  }
  return 0;
}