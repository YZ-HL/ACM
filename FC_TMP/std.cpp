#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 100;
bool notprime[MAXN]; // 值为 false 表示素数，值为 true 表示非素数
vector<int> prime;

void init() {
    memset(notprime, false, sizeof(notprime));
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < MAXN; i++)
        if (!notprime[i]) {
            prime.push_back(i);
            if (i > MAXN / i)
                continue; // 防止后面 i*i 溢出 (或者 i,j 用 long long)
            // 直接从 i*i 开始就可以，小于 i 倍的已经筛选过了, 注意是 j += i
            for (int j = i * i; j < MAXN; j += i)
                notprime[j] = true;
        }
}

int frac(int n) {
    int sum = 0, flag = 0;
    for (auto item : prime) {
        if (n < item) break;
        while (n % item == 0) {
            if (item != 2) sum++;
            else flag = 1;
            n /= item;
        }
    }
    if (n > 1) sum++;
    return sum + flag;
}

void solve() {
    init();
    int _;
    cin >> _;
    for (int ts = 0; ts < _; ++ts) {
        int n;
        cin >> n;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            res ^= frac(tmp);
        }
        cout << (res ? "W" : "L") << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    signed localTestCount = 1, localReadPos = cin.tellg();
    char localTryReadChar;
    do {
        if (localTestCount > 20)
            throw runtime_error("Check the stdin!!!");
        auto startClockForDebug = clock();
        solve();
        auto endClockForDebug = clock();
        cout << "Test " << localTestCount << " successful" << endl;
        cerr << "Test " << localTestCount++ << " Run Time: "
             << double(endClockForDebug - startClockForDebug) / CLOCKS_PER_SEC << "s" << endl;
        cout << "--------------------------------------------------" << endl;
    } while (localReadPos != cin.tellg() && cin >> localTryReadChar && localTryReadChar != '$' &&
             cin.putback(localTryReadChar));
#else
    solve();
#endif
    return 0;
}