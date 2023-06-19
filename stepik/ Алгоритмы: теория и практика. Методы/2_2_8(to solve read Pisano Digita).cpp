#include <cassert>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Fibonacci {
 public:
  static int get_remainder(long long n, int mod) {
    assert(n >= 1);
    assert(mod >= 2);
    vector<int> pisano;
    pisano.push_back(0);
    pisano.push_back(1);
    pisano.push_back(1);
    int a1=pisano[1],a2=pisano[2],temp;
    while(pisano[0]!=pisano[pisano.size()-2]||pisano[1]!=pisano[pisano.size()-1])
    {
        temp=(a1+a2)%mod;
        a2=a1;
        a1=temp;
        pisano.push_back(a1);
    }
    pisano.pop_back();
    pisano.pop_back();
    return pisano[n%pisano.size()];
  }
};

int main(void) {
  long long n;
  int m;
  std::cin >> n >> m;
  std::cout << Fibonacci::get_remainder(n, m) << std::endl;
  return 0;
}
