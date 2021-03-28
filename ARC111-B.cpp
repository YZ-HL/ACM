#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
map<int, int> mp1, mp2;
int n, a[maxn], b[maxn], vis1[maxn], vis2[maxn], cnt1, cnt2;
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        if(!vis1[a[i]])
        {
            vis1[a[i]] = 1;
            cnt1++;
        }
        mp1[a[i]]++;
        if(!vis2[b[i]])
        {
            vis2[b[i]] = 1;
            cnt2++;
        }
        mp2[b[i]]++;
    }
    /*cout << cnt1 << " " << cnt2 << endl;
    system("pause");*/
    /*for(int i = 1; i <= n; i++)
    {
        cout << vis2[b[i]] << " " << mp2[b[i]] << endl;
        system("pause");
    }*/
    if(cnt1 >= cnt2)
    {
        for(int i = 1; i <= n; i++)
        {
            if(!vis1[b[i]] && mp1[a[i]] > 1)
            {
                /*cout << a[i] << " " << b[i] << endl;
                system("pause");*/
                cnt1++;
                vis1[b[i]] = 1;
                mp1[a[i]]--;
                mp1[b[i]]++;
                if(mp1[a[i]] == 0)
                    vis1[a[i]] = 0;
            }
        }
        printf("%d\n", cnt1);
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(!vis2[a[i]] && mp2[b[i]] > 1)
            {
                cnt2++;
                vis2[a[i]] = 1;
                mp2[a[i]]++;
                mp2[b[i]]--;
                if(mp2[b[i]] == 0)
                    vis2[b[i]] = 0;
            }
        }
        printf("%d\n", cnt2);
    }
    
    return 0;
}
