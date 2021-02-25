#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, a[maxn], inq[maxn];
int flag, k, pos, fail, now = -1;
deque<int> q1;
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)    scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == i && now == -1)    continue;
        
        if(now == -1)    now = i;
        q1.push_back(a[i]), pos = i;
        
        if(a[i] == now)
        {
            k = i - now + 1;
            flag ^= 1; now++;
            flag ? q1.pop_back() : q1.pop_front();
            if(i + 1 <= n)
                flag ? q1.push_front(a[i + 1]) : q1.push_back(a[i + 1]), pos = i + 1;
            break;
        }
    }
    if(now == -1)
    {
        printf("yes\n1");
        return 0;
    }
    while(now <= n)
    {
        int fr = flag ? q1.back() : q1.front(), fb = flag ? q1.front() : q1.back();
        if(fr == now)
        {
            flag ? q1.pop_back() : q1.pop_front();
            if(pos + 1 <= n)
                flag ? q1.push_front(a[pos + 1]) : q1.push_back(a[pos + 1]), pos++;
            now++;
        }
        else if(fb == now && q1.size() == k)
        {
            flag ^= 1;
            flag ? q1.pop_back() : q1.pop_front();
            if(pos + 1 <= n)
                flag ? q1.push_front(a[pos + 1]) : q1.push_back(a[pos + 1]), pos++;
            now++;
        }
        else
        {
            break;
        }
    }
    if(now <= n)
        printf("no");
    else
        printf("yes\n%d", k);
    return 0;
}