#include <cassert>
#include <iostream>

class Fibonacci {
 public:
  static int get(int n) {
    assert(n >= 0);
    n--;
    int a1=0,a2=1,temp;
    while(n--)
    {
        temp=a1+a2;
        a1=a2;
        a2=temp;
    }
    return a2;
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get(n) << std::endl;
  return 0;
}
