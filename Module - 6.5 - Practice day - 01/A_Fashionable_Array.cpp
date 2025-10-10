#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);

        int mn = a[0];
        int mx = a[n - 1];

        if(mn % 2 == mx % 2) cout << 0 << endl;
        

    }
    
    return 0;
}