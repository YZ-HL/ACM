#include <bits/stdc++.h>
#define int long long
using namespace std;
int B, C;
pair<int, int> calc(int C){
    if(C & 1){
        return make_pair(- B - C / 2, - B + C / 2);
    }
    else{
        if(C == 0)
            return make_pair(B, B);
        return make_pair(B - C / 2, B + C / 2 - 1);
    }
}
signed main(void)
{
    scanf("%lld %lld", &B, &C);
    int l1, r1, l2, r2, n;
    pair<int, int> res;
    res = calc(C);
    l1 = res.first, r1 = res.second;
    res = calc(C - 1);
    l2 = res.first, r2 = res.second;    
    printf("%lld\n", r1 - l1 + 1 + r2 - l2 + 1 - max(0LL, min(r1, r2) - max(l1, l2) + 1));
    return 0;
}
