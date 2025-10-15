#include <iostream>
#include <vector>
using namespace std;

pair<int,int> maxHeight(const vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxH = 0;
    pair<int,int> result = {left, right};

    while(left < right) {
        int h = min(height[left], height[right]);
        if(h > maxH) {
            maxH = h;
            result = {left, right};
        }
        if(height[left] < height[right]) left++;
        else right--;
    }

    return result;
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> height(n);
        for(int i = 0; i < n; i++) cin >> height[i];

        pair<int,int> ans = maxHeight(height);
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}
