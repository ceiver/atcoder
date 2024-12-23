#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    long long to; //行き先
    long long cost; //辺の長さ
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, ll>;
const long long INF = 1LL << 60;

/* dijkstra(G,s,d)
    入力：グラフ G, 開始点 s, 距離を格納する d
    計算量: O(|E|log|V|)
    副作用: d が書き換えられる
*/
void dijkstra(const Graph &G, ll s, vector<ll> &d) {
    ll N = G.size();
    d.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    d[s] = 0;
    pq.emplace(d[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        ll v = p.second;
        if (d[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            if (d[e.to] > d[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                d[e.to] = d[v] + e.cost;
                pq.emplace(d[e.to], e.to);
            }
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    ll A, B, C;
    cin >> A >> B >> C;

    Graph G1(N), G2(N);
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            ll d;
            cin >> d;
            G1[i].push_back({j, d * A});
            G2[i].push_back({j, d * B + C});
        }
    }

    vector<ll> d1, d2;
    dijkstra(G1, 0, d1);
    dijkstra(G2, N - 1, d2);

    ll ans = INF;
    for (ll i = 0; i < N; i++) {
        ans = min(ans, d1[i] + d2[i]);
    }
    cout << ans << endl;
}
