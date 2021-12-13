// #medium #string #sliding-window
/*
    Time Complexity: O(N)
    Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

int equalSubstring(string s, string t, int maxCost) {
    int n = s.length();
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        a[i] = abs(s[i] - t[i]);

    int cnt = 0, sum = 0;
    for(int i = 0; i < n; i++) 
    {
        if(sum + a[i] <= maxCost)
        {
            sum += a[i];
            cnt += 1;
        }
        else
            sum = sum - a[i-cnt] + a[i];
    }
    return cnt;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s, t;
    int maxCost;
    cin >> s >> t >> maxCost;
    cout << equalSubstring(s, t, maxCost);
}

/*
abcd bcdf 3
*/