#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,n) for(int i=1;i<=n;++i)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int N, M;
vector<pll> vt;

bool solve(ll d) {
    int cur = INT_MIN;
    int cnt = 0;
    rep(i, M) {
        auto [f, s] = vt[i];
        while (cur <= s - d) {
            cur = max(cur + d, f);
            cnt += 1;
        }
    }
    return cnt >= N;
}

int main() {
    FAST;
    cin >> N >> M;
    vt.resize(M);
    rep(i, M) {
        auto& [f, s] = vt[i];
        cin >> f >> s;
    }
    sort(vt.begin(), vt.end());
    ll lo = 1;
    ll hi = 1e18;
    ll best = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (solve(mid)) {
            best = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    cout << best;

    return 0;
}