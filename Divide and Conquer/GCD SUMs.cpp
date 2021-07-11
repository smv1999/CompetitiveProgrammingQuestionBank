#include <bits/stdc++.h>
using namespace std;

typedef long long ans_t;
const int C = 6e7;

int p = 1, curr = 1;
int l[C], r[C];

ans_t sub[C], load[C];

struct elem {int val, l, r;};

vector <elem> segs;

int _update(int v, int tl, int tr, int sl, int sr, bool leftSon) {
    if (leftSon) {
        while (sl <= sr && segs[sr].l > tr) sr--;
    } else {
        while (sl <= sr && segs[sl].r < tl) sl++;
    }

    if (sl > sr) return v;

    int nv = curr++;
    assert(curr < C);

    if (segs[sl].l <= tl && segs[sl].r >= tr) {
        l[nv] = l[v];
        r[nv] = r[v];
        load[nv] = load[v] + segs[sl].val;
    } else {
        int mid = (tl + tr) / 2;

        l[nv] = _update(l[v], tl, mid, sl, sr, true);
        r[nv] = _update(r[v], mid + 1, tr, sl, sr, false);
        load[nv] = load[v];
    }

    sub[nv] = sub[l[nv]] + sub[r[nv]] + (load[l[nv]] + load[r[nv]]) * (tr - tl + 1) / 2;
    return nv;
}

ans_t _query(int v, int tl, int tr, int ql, int qr) {
    if (ql > tr || qr < tl) return 0;

    int len = min(tr, qr) - max(tl, ql) + 1;
    ans_t add = len * load[v];

    if (ql <= tl && qr >= tr) {
        return sub[v] + add;
    } else {
        int mid = (tl + tr) / 2;
        return _query(l[v], tl, mid, ql, qr) + _query(r[v], mid + 1, tr, ql, qr) + add;
    }
}

int update(int v) {
    return _update(v, 0, p-1, 0, (int) segs.size() - 1, true);
}

ans_t query(int v, int ql, int qr) {
    return _query(v, 0, p-1, ql, qr);
}
const int MOD = 1000 * 1000 * 1000 + 7;
int readInt() {
  bool minus = false;
  int result = 0;
  char ch;
  ch = getchar();

  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }

  if (ch == '-') minus = true; else result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }

  return minus ? -result : result;
}
void solve(int n, int q, vector <int> &arr) {
    vector <elem> segsNew;

    int currRoot = 0;
    vector <int> roots(n);

    while (p < n) p *= 2;

    for (int l = n - 1; l >= 0; l--) {
        segsNew.push_back({arr[l], l, l});

        for (auto &s : segs) {
            int newVal = __gcd(s.val, arr[l]);

            if (newVal != segsNew.back().val) {
                segsNew.push_back({newVal, s.l, s.r});
            } else {
                segsNew.back().r = s.r;
            }
        }

        segs = segsNew;
        segsNew.clear();

        currRoot = update(currRoot);
        roots[l] = currRoot;
    }

    int lastAns = 0;
    while (q--) {
        int l = readInt();
        int r = readInt();

        l = (l + lastAns) % n;
        r = (r + lastAns) % n;

        long long ans = query(roots[l], l, r) % MOD;
        printf("%lld\n", ans);

        lastAns = ans;
    }
}
int main()
{
    int n = readInt();
    int q = readInt();
    vector <int> arr(n);
    for (int &x : arr) x = readInt();
    solve(n, q, arr);
    return 0;
}
