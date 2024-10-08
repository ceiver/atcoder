#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    vector<vector<ll>> dist(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
        }
    }
    vector<ll> cost(1 << N);
    for (int i = 0; i < 1 << N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < j; k++) {
                if (i >> j & 1 && i >> k & 1) {
                    cost[i] = max(cost[i], dist[j][k]);
                }
            }
        }
    }
    
    vector<vector<ll>> dp(K + 1, vector<ll>(1 << N, 1ll << 62));
    dp[0][0] = 0;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < 1 << N; j++) {
            for (int k = j; k != 0; k = (k - 1) & j) {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][j - k], cost[k]));
            }
        }
    }
    cout << dp[K][(1 << N) - 1] << endl;
}
