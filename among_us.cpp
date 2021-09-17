// Krishnaya vaasudevaya
// Devaki nandanayacha
// Nanda gopakumaraya
// Govindaya namoh namaha
// Jay ganeshji, Jay Guruji, Jay Ram-bhakt Hanumanji

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ff first
#define ss second

#define pb emplace_back
#define eb emplace

// Competion only
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ull = unsigned ll;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;

const int inf = 1e9 + 7;
const ll llinf = 1e18 + 7;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll fastPow(ll a, ll b)
{
	ll res = 1;
	while(b) {
		if(b & 1)
			res *= a;
		a *= a, b >>= 1;
	}
	return res;
}

ll fastPow(ll a, ll b, ll m)
{
	ll res = 1;
	a %= m;
	while(b) {
		if(b & 1)
			(res *= a) %= m;
		(a *= a) %= m, b >>= 1;
	}
	return res;
}

ll modinv(ll x, ll m)
{
	return fastPow(x, m - 2, m);
}

ll moddiv(ll numerator, ll denominator, ll m) {
	return numerator * modinv(denominator, m);
}

template<typename T>
constexpr ostream &operator<<(ostream &stream, const vector<T> &other) {
	stream << '[';
	size_t n = other.size();

	if(n > 0) {
		for(size_t i = 0; i < n - 1; i++)
			stream << other[i] << ", ";
		stream << other[n - 1];
	}

	return stream << ']';
}

template<typename T>
constexpr ostream &operator<<(ostream &stream, const set<T> &other) {
	stream << '{';

	size_t n = other.size();

	if(n > 0) {
		auto it = other.begin();
		for(size_t i = 0; i < n-1; i++)
			stream << *it << ", ", ++it;
		stream << *it;
	}

	return stream << '}';
}

template<typename T>
constexpr ostream &operator<<(ostream &stream, const multiset<T> &other) {
	stream << '{';

	size_t n = other.size();

	if(n > 0) {
		auto it = other.begin();
		for(size_t i = 0; i < n-1; i++)
			stream << *it << ", ", ++it;
		stream << *it;
	}

	return stream << '}';
}

template<typename T>
constexpr ostream &operator<<(ostream &stream, const ordered_set<T> &other) {
	stream << '{';

	size_t n = other.size();

	if(n > 0) {
		auto it = other.begin();
		for(size_t i = 0; i < n-1; i++)
			stream << *it << ", ", ++it;
		stream << *it;
	}

	return stream << '}';
}

template<typename T1, typename T2>
constexpr ostream &operator<<(ostream &stream, const map<T1, T2> &other) {
	stream << '{';

	size_t n = other.size();

	if(n > 0) {
		auto it = other.begin();
		for(size_t i = 0; i < n-1; i++)
			stream << (*it).first << ':' << (*it).second << ", ", ++it;
		stream << (*it).first << ':' << (*it).second;
	}

	return stream << '}';
}

template<typename T1, typename T2>
constexpr ostream &operator<<(ostream &stream, const multimap<T1, T2> &other) {
	stream << '{';

	size_t n = other.size();

	if(n > 0) {
		auto it = other.begin();
		for(size_t i = 0; i < n-1; i++)
			stream << (*it).first << ':' << (*it).second << ", ", ++it;
		stream << (*it).first << ':' << (*it).second;
	}

	return stream << '}';
}

template<typename T1, typename T2>
constexpr ostream &operator<<(ostream &stream, const unordered_map<T1, T2> &other) {
	stream << '{';

	size_t n = other.size();

	if(n > 0) {
		auto it = other.begin();
		for(size_t i = 0; i < n-1; i++)
			stream << (*it).first << ':' << (*it).second << ", ", ++it;
		stream << (*it).first << ':' << (*it).second;
	}

	return stream << '}';
}

template<typename T1, typename T2>
constexpr ostream &operator<<(ostream &stream, const pair<T1, T2> &other) {
	return stream << '(' << other.first << ", " << other.second << ')';
}

template<typename T>
istream &operator>>(istream &stream, vector<T> &other) {
	for(auto &e : other)
		stream >> e;

	return stream;
}

template<typename T1, typename T2>
istream &operator>>(istream &stream, pair<T1, T2> &other) {
	stream >> other.first >> other.second;
	return stream;
}

const int MAX = 500005;

int n, q, vis[MAX], who[MAX], sz[MAX];

inline void solve() {

	cin >> n >> q;
	memset(vis, -1, n * sizeof(int));
	memset(who, -1, n * sizeof(int));
	memset(sz, 0, n * sizeof(int));

	vector<vi> adj1[2];
	adj1[0].resize(n),
	adj1[1].resize(n);

	stack<int> st;
	int cntr = -1, res = 0;

	// input
	while(q--) {
		int i, j, t; cin >> t >> i >> j, --t, --i, --j;
		adj1[t][i].pb(j), adj1[t][j].pb(i);
	}

	// make components where each component contains nodes that vouch for each other (of the same type)
	for(int i = 0, h; i < n; i++) {
		if(who[i] != -1)
			continue;

		who[i] = ++cntr, st.eb(i);
		while(!st.empty()) {
			h = st.top(), st.pop();
			sz[cntr]++;
			for(auto &e : adj1[1][h])
				if(who[e] == -1)
					who[e] = cntr, st.eb(e);
		}
	}

	// construct graph of components where an edge indicates accusation
	vector<vi> adj2(++cntr);
	for(int i = 0; i < n; i++) {
		for(auto &e : adj1[0][i]) {
			if(who[e] == who[i]) {
				// if accused in the same component as accuser, inconsistency found
				cout << -1 << '\n';
				return;
			}
			adj2[who[i]].pb(who[e]), adj2[who[e]].pb(who[i]);
		}
	}

	// color the graph and for each mega component, find the max number of parasites possible
	for(int i = 0; i < cntr; i++) {
		if(vis[i] != -1)
			continue;

		int cnt[2]{0, 0}, h;
		vis[i] = 0, st.eb(i);

		while(!st.empty()) {
			h = st.top(), st.pop();
			cnt[vis[h]] += sz[h];
			for(auto &e : adj2[h]) {
				if(vis[e] == -1)
					vis[e] = 1 - vis[h], st.eb(e);
				else if(vis[e] == vis[h]) {
					cout << -1 << '\n';
					return;
				}
			}
		}

		res += max(cnt[0], cnt[1]);
	}

	cout << res << '\n';
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt",  "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while(t--)
		solve();

	return 0;
}