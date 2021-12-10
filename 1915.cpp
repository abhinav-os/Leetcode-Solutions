// #medium #bitmasking #string
/*
    Time Complexity: O(APLPHABET SIZE * N)
    Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

long long wonderfulSubstrings(string word) {
    ll cnt = 0, n = word.length();
    unordered_map<int, int> mp;

    ll mask = 0;
    mp[mask] = 1;

    for(int i = 0; i < n; i++) {
        mask = mask xor (1 << (word[i] - 'a'));
        if(mp[mask] != 0)
            cnt += mp[mask];
        
        for(int j = 0; j < 10; j++) {
            ll tempMask = mask xor (1 << j);
            if(mp[tempMask] != 0) 
                cnt += mp[tempMask];
        }

        mp[mask] += 1;
    }

    return cnt;
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string str;
    cin >> str;

    cout << wonderfulSubstrings(str);
}

/*

*/