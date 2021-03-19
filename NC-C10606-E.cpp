#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int n, k, a[maxn], cnt, ans[maxn], las[maxn], ins[maxn];
stack<int> s1;
int main(void)
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]), las[a[i]] = i;
    for(int i = 1; i <= n; i++)
    {
        if(s1.empty())    s1.push(a[i]);
        else if(s1.top() < a[i])    s1.push(a[i]);
        else
        {
            while(!s1.empty() && s1.top() > a[i] && las[s1.top()] > i)
            {
                s1.pop();
            }
            s1.push(a[i]);
        }       
    }
    while(!s1.empty())
        ans[++cnt] = s1.top(), s1.pop();
    for(int i = cnt; i >= 1; i--)
        if(!ins[ans[i]])
            printf("%d ", ans[i]), ins[ans[i]] = 1;
    return 0;
}
