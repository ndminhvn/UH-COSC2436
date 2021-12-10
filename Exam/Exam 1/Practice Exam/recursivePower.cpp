#include <iostream>

using namespace std;

int power(int a, int b) {
   //complete function
   if (b < 0) {
       cout << "Invalid input";
       return -1;
   } else  {
       if (b == 0) {
           return 1;
       } else {
           return (a * power(a, b-1));
       }
   }
   
}

int main() {
   
   return 0; 
}