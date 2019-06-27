#include <iostream>
#include <vector>
#include <algorithm> // std::find
#include <memory> // std::shared_ptr

using namespace std;

int main(void)
{
  using T = pair<int, string>; // for clearer code demo
  vector<T> v = {{1, "a"}, {2, "b"}, {3, "c"}, {4, "d"}, {5, "e"}}; // [C++11]Bracketed copy-list-initialization   // NO-Range-Operator

  auto p(make_shared<T>(6, "f")); // [C++11]shared_ptr: use 'make_shared' instead of 'new'
  v.push_back(move(*p)); // only demo, don't do like this. [C++11]Move semantic, check the effect in the last line // Note: std containers already impleted move sematics
    
  for(auto& m: v) { // [C++11]Type Deduction (auto), [C++11]Range Based For-Loop   // NO-(index, value)-pair-iteration
    for_each(begin(v), find(v.begin(), v.end(), m)+1, [&m](auto n) { // generic begin(), [C++11]Lamda
      if (m.first == n.first) m.second = m.second + to_string(m.first); // verify m is a reference
      cout << "(" << m.first << "," << m.second << ")-(" << n.first << "," << n.second << ") "; // NO-String-Interpolation...
    });
    cout << endl;
  }

  cout << p->first << "-" << p->second << endl; // check the move effect. results based on compiler & flags
  p = nullptr; // use nullptr instead of NULL
  return 0;
}
