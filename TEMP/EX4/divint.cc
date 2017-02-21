#include <iostream>
using namespace std;

// Shout out to www.tutorialspoint.com

int divint(int, int);
int main() {
   int x = 5, y = 2;
   cout << divint(x, y) << endl;
   // (gdb) break 10
   x = 3; y = 1; // not a division by ZERO
   cout << divint(x, y) << endl;
   //(gdb) break 13
   return 0;
}

int divint(int a, int b) {
   return a / b;
}
