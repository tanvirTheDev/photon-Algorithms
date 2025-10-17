#include <iostream>
using namespace std;



int fibonachhi(int n){
    if(n < 2) return n;
    return fibonachhi(n - 1) + fibonachhi(n -2);
} 


int main()
{
    cout << fibonachhi(6);
    return 0;
}