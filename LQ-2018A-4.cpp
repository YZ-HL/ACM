#include <bits/stdc++.h>
#define ll long long
using namespace std;
set<ll> s1;
void dfs(ll now){
    if(now > 59084709587505)    return;
    if(!s1.count(now))
    {
        s1.insert(now);
        dfs(now * 3LL);
        dfs(now * 5LL);
        dfs(now * 7LL);
    }
}
int main(void)
{
    dfs(1LL);
    printf("%lld\n", s1.size());
    for(set<ll>::iterator iter = s1.begin(); iter != s1.end(); iter++)
        printf("%lld ", *iter);
    return 0;
}