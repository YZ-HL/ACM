#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define maxn 100005
using namespace std;
int n, k, flag;
int cnt, fa1[maxn], fa2[maxn], se[maxn], used[maxn];
map<string, int> mp;
map<int, string> mpr;
void dfs(int now, int dep){
    //cout << mpr[now] <<  " " << dep << endl;
    if(used[now])
    {
        //cout << mpr[now] << endl;
        //printf("de: %d %d\n", now, dep);
        flag = 1;
        return;
    }
    used[now] = 1;
    if(dep == 4)
        return;
    if(~fa1[now])   dfs(fa1[now], dep + 1);
    if(~fa2[now])   dfs(fa2[now], dep + 1);   
}
int main(void)
{
    memset(fa1, -1, sizeof(fa1));
    memset(fa2, -1, sizeof(fa2));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        string id, sex, faid, maid;
        cin >> id >> sex >> faid >> maid;
        if(!mp.count(id))
        {
            mp[id] = ++cnt;
            mpr[cnt] = id;
        }
        if(!mp.count(faid) && faid != "-1")
        {
            mp[faid] = ++cnt;
            mpr[cnt] = faid;
        }
        if(faid != "-1")    fa1[mp[id]] = mp[faid], se[mp[faid]] = 1;
        if(!mp.count(maid) && maid != "-1")
        {
            mp[maid] = ++cnt;
            mpr[cnt] = maid; 
        }
        if(maid != "-1")    fa2[mp[id]] = mp[maid], se[mp[faid]] = 0;
        se[mp[id]] = sex == "M" ? 1 : 0;
    }
    scanf("%d", &k);
    for(int i = 1; i <= k; i++)
    {
        memset(used, 0, sizeof(used));
        string tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        int g1 = mp[tmp1], g2 = mp[tmp2];
        if(se[g1] == se[g2])
        {
            cout << "Never Mind" << endl;
            continue;
        }
        flag = 0;
        dfs(g1, 0);
        dfs(g2, 0);
        if(flag)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
