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

const int mod = 20011;

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

int dp[305][305][305][2];
int a[305][305];
int r, c, d;

const int down = 0, rigt = 1;

// solve(i, j, s, m) = number of ways to get from (i, j) to (r, c) if the last s steps were in direction m
int solve(int i, int j, int s, int m) {

	if(!a[i][j])
		return 0;
	if(i == r and j == c)
		return 1;

	if(dp[i][j][s][m] == -1) {
		int res = 0;

		if(m == down) {
			res += solve(i, j+1, 1, rigt);
			if(s < d)
				res += solve(i+1, j, s+1, down);
		}
		else {
			res += solve(i+1, j, 1, down);
			if(s < d)
				res += solve(i, j+1, s+1, rigt);
		}

		dp[i][j][s][m] = res % mod;
	}

	return dp[i][j][s][m];
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt",  "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> r >> c >> d;

	memset(a, 0, sizeof(a));
	memset(dp, -1, sizeof(dp));

	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			cin >> a[i][j];

	cout << solve(1, 1, 0, 0) << '\n';

	return 0;
}