// Problem: D. Extra Element
// Contest: Codeforces - Codeforces Round 568 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1185/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <cassert>
#include <cctype>
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <chrono>
#include <random>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#endif

#define FAST ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15)
#define Tsolve() int T; cin >> T; while (T --) solve()
#define endl '\n'
#define em(x) (x.empty())
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mem(a,b) memset(a,b,sizeof(a))
#define Fill(x,a) memset(x,a,sizeof(x))
#define cpy(a,b) memcpy(a,b,sizeof(a))
#define pbk push_back
#define mpr make_pair
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,n) for(int i=a;i<=n;++i)
#define fi first
#define se second
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
//-----------------------precompiler--------------------
using ll = long long;
using i64 = long long;
using pii = std::pair<int,int>;
using VI = std::vector<int>;
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
//-----------------------debug-----------------------
#ifndef ONLINE_JUDGE
#include "D:/OneDrive-Personal/OneDrive/my-acm-template/my_header/debug.h"
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) {}
#endif
//-----------------------constant-----------------------
const int maxn = 2e5+10;
const int inf = 0x3f3f3f3f;
const ll inf2 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9+7;
const int mod2 = 998244353;
ll gcd(ll a,ll b) { return b?gcd(b, a%b):a;}
//-----------------------variable-----------------------
int n;

//-----------------------function-----------------------

void solve() {
    cin >> n;
    vector<pii> a;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        a.emplace_back(x, i);
    }
    if (n == 2) {
        cout << 1 << endl;
        return;
    }
    sort(all(a));
    
    auto check = [&](int l, int r, int d) {
        for (int i = l + 1; i <= r; i ++) {
            if (a[i].fi - a[i-1].fi != d) return false;
        }
        return true;
    };
    
    // 删除最小元素
    if (check(2, n - 1, a[2].fi - a[1].fi)) {
        cout << a[0].se << endl;
        return;
    }
    // 删除次小元素
    if (check(2, n - 1, a[2].fi - a[0].fi)) {
        cout << a[1].se << endl;
        return;
    }
    
    // 都不删
    int d = a[1].fi - a[0].fi;
    int del = -1;
    int last = a[1].fi;
    for (int i = 2; i < n; i ++) {
        if (a[i].fi - last != d) {
            if (del >= 0) {
                cout << -1 << endl;
                return;
            }
            del = a[i].se;
        }
        else {
            last = a[i].fi;
        }
    }
    if (del >= 0) cout << del << endl;
    else cout << a.back().se << endl;
}
int main() {
    FAST;
    // Tsolve();
    solve();

    return 0;
}
