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

const int mxN = 150001;

int dp[mxN];
int n, m;

int solve(int i) {

	if(dp[i] == -1) {
		int res = 0;

		for(int j = 1; j < i; j++)
			if(i % j == 0)
				res = (res + solve(j)) % m;

		dp[i] = (fastPow(2, i, m) - res + m) % m;
	}

	return dp[i];
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt",  "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));
	dp[1] = 2;

	cin >> n >> m;
	cout << solve(n) << '\n';

	return 0;
}