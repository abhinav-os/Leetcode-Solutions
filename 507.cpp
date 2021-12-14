// #easy #math
/*
    Time Complexity: O(SQRT(N))
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

bool checkPerfectNumber(int num) {
    int sum = 0;
    for(int i = 1; i * i <= num; i++) 
    {
        if(num % i == 0) 
        {
            if(i == num/i)
                sum += i;
            else
                sum += (i + num/i);
        }
    }
    return (sum - num == num);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    cout << checkPerfectNumber(n);
}

/*
28
true
*/