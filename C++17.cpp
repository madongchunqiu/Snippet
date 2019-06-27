#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
  vector<pair<int, string>> v = {{1, "a"}, {2, "b"}, {3, "c"}, {4, "d"}, {5, "e"}};
  
  for(auto& m: v) {
    for_each(begin(v), find(v.begin(), v.end(), m)+1, [&m](auto n) {
      if (auto &[p, q] = m; p == n.first) q = q + to_string(p); // [C++17]structured binding, [C++17]Init statements for if/switch
      cout << "(" << m.first << "," << m.second << ")-(" << n.first << "," << n.second << ") "; 
    });
    
    cout << endl;
  }

  return 0;
}
