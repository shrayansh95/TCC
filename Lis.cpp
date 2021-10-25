#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &it : a) {
        cin >> it;
    }
    vector<int> dp(n, 0);
    dp[0] = 1;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        int maxi = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                if (dp[j] > maxi) {
                    maxi = dp[j];
                }
            }
        }
        dp[i] = maxi + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}