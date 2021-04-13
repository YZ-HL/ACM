#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long lld;
lld pow_mod(lld a, lld b, const int &pr)
{
	lld ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % pr;
		b >>= 1;
		a = a * a % pr;
	}
	return ans;
}
lld C_small(lld n, lld m, const int &pr)
{
	lld ans = 1;
	for (int i = 1; i <= m; i++)
	{
		lld a = (n - m + i) % pr;
		lld b = i % pr;
		ans = ans * (a * pow_mod(b, pr - 2, pr) % pr) % pr; //Fermat Theory
	}
	return ans;
}
lld C(lld n, lld m, const int &pr) // Lucas's theorem
{
	if (m == 0 || m == n) return 1;
	return C_small(n % pr, m % pr, pr) * C(n / pr, m / pr, pr) % pr;
}
int main(void)
{
    lld n;
    scanf("%lld", &n);
    printf("%lld\n", C(n + 8, 8, 100019));
    return 0;
}
