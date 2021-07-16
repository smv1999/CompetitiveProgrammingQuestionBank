#include <bits/stdc++.h>
using namespace std;

#define N 1010
#define K 22

int cnt[N][N], dp[N][N][K], C[K][K];
const int mod = 1e9 + 7;

int main() {
    for (int i = 0; i < K; i ++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j ++) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
    }
	cnt[0][0] = 1;
	for (int i = 1; i < N; i ++) for (int j = 0; j < N; j ++) {
		if (i == 1) {
			cnt[i][j] = 1; continue;
		}
		cnt[i][j] = 2 * cnt[i-1][j] - cnt[i-2][j];
		if (cnt[i][j] >= mod) cnt[i][j] -= mod;
		if (cnt[i][j] < 0) cnt[i][j] += mod;
		if (j >= i && (cnt[i][j] += cnt[i][j-i]) >= mod) cnt[i][j] -= mod;
	}
    auto expmod = [&](int x, int n) {
		int rlt = 1;
		while (n) {
			if (n & 1) rlt = 1ll * x * rlt % mod;
			x = 1ll * x * x % mod, n >>= 1;
		}
		return rlt;
    };
	for (int k = 0; k < K; k ++) for (int i = 1; i < N; i ++) for (int j = 0; j < N; j ++) {
		if (k == 0) {
			dp[i][j][k] = 1ll * i * cnt[i][j] % mod; continue;
		}
		if (i == 1) {
			dp[i][j][k] = expmod(j, k); continue;
		}
		dp[i][j][k] = 2 * dp[i-1][j][k] - dp[i-2][j][k];
		if (dp[i][j][k] >= mod) dp[i][j][k] -= mod;
		if (dp[i][j][k] < 0) dp[i][j][k] += mod;
		if (j < i) continue;
		for (int t = 0; t <= k; t ++) dp[i][j][k] = (dp[i][j][k] + 1ll * C[k][t] * dp[i][j-i][t]) % mod;
	}
    for (int i = 1; i < N; i ++) for (int j = 0; j < N; j ++) cnt[i][j] = expmod(cnt[i][j], mod - 2);
	int T;
	scanf("%d", &T);
	while (T --) {
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		printf("%d\n", 1ll * dp[n][m][k] * cnt[n][m] % mod);
	}

    return 0;
}
