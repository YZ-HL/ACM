#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
map<int, int> mp;
void inits(){
    mp[0] = 0;
    mp[1] = 1;
    mp[2] = 5;
    mp[5] = 2;
    mp[8] = 8;
}
int t, h, m, tth, ttm;
bool check(int nh, int nm){
    int h1 = nh / 10, h2 = nh % 10;
    int s1 = nm / 10, s2 = nm % 10;
    bool flag1 = mp.count(h1) && mp.count(h2) &&
                 mp.count(s1) && mp.count(s2);
    if(!flag1)
        return flag1;
    int newh = mp[s2] * 10 + mp[s1];
    int newm = mp[h2] * 10 + mp[h1];
    return newh >= 0 && newh < h &&
           newm >= 0 && newm < m; 
}
int main(void)
{
    inits();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &h, &m);
        scanf("%d:%d", &tth, &ttm);
        while(!check(tth, ttm))
        {
            ttm++;
            if(ttm == m)
                ttm = 0, tth++;
            if(tth == h)
                tth = 0;
        }
        printf("%02d:%02d\n", tth, ttm);
    }
    return 0;
}
