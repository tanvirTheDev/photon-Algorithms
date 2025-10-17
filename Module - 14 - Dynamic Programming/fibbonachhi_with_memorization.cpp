#include <iostream>
using namespace std;

long long int dp[2005];

int fibonachhi(long long int n){
    if(n < 2) return n;
    if(dp[n] != -1) return dp[n];
    dp[n] = fibonachhi(n - 1) + fibonachhi(n -2);
    return dp[n];
} 


int main()
{
    memset(dp, -1, sizeof(dp));
    long long int n;
    cin >> n;
    cout << fibonachhi(n);
    return 0;
}