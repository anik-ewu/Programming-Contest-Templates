#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define fi first
#define se second

typedef long long lli;
typedef pair<int, int> ii;
typedef pair<lli, lli> ll;

int n, memo[205][205][205];
char s[205], t[5];

int dp(int p, int a, int k) {
	int ret = 0;
	if (p == n)
		return 0;
	if (memo[p][a][k] != -1)
		return memo[p][a][k];
	if ((s[p] == t[0]) && (s[p] == t[1]))
		ret = max(ret, dp(p + 1, a + 1, k) + a);
	else if (s[p] == t[0])
		ret = max(ret, dp(p + 1, a + 1, k));
	else if (s[p] == t[1])
		ret = max(ret, dp(p + 1, a, k) + a);
	else
		ret = max(ret, dp(p + 1, a, k));
	if (k > 0) {
		if (t[0] == t[1])
			ret = max(ret, dp(p + 1, a + 1, k - 1) + a);
		else {
			ret = max(ret, dp(p + 1, a + 1, k - 1));
			ret = max(ret, dp(p + 1, a, k - 1) + a);
		}
	}
	memo[p][a][k] = ret;
	return ret;
}

int main() {
	int k;
	scanf("%d %d %s %s", &n, &k, s, t);
	memset(memo, -1, sizeof memo);
	printf("%d\n", dp(0, 0, k));
	return 0;
}
