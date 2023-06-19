#include <cassert>
#include <iostream>

class Fibonacci {
 public:
  static int get_last_digit(int n) {
    assert(n >= 1);
    n--;
    int a1=0,a2=1,temp;
    while(n--)
    {
        temp=(a1+a2)%10;
        a1=a2;
        a2=temp;
    }
    return a2;
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get_last_digit(n) << std::endl;
  return 0;
}
