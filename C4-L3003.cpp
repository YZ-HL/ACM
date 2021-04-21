#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int n, ki, hi[maxn];
int uset[maxn], sum[maxn];
vector<int> ans, group[maxn];
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
void unioon(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)    return;
    uset[fx] = fy;
}
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= maxn - 5; i++)    uset[i] = i;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d:", &ki);
        for(int j = 1; j <= ki; j++)
        {
            scanf("%d", &hi[j]);
            group[hi[j]].push_back(i);
        }
    }
    for(int i = 1; i <= 1000; i++)
        for(int j = 1; j < group[i].size(); j++)
            unioon(group[i][j - 1], group[i][j]);
    
    for(int i = 1; i <= n; i++)    sum[find(i)]++;
    for(int i = 1; i <= n; i++)
    {
        if(find(i) == i)
        {
            ans.push_back(sum[i]);
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf(i == ans.size() - 1 ? "%d" : "%d ", ans[i]);
    return 0;
}
