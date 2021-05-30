#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n;
multiset<int> fac;
void divv(int x){
    for(int i = 2; i * i <= x; i++)
    {
        while(x % i == 0)
        {
            x /= i;
            fac.insert(i);
        }
    }
    if(x > 1)
        fac.insert(x);
}
void divv2(int x){
    for(int i = 2; i * i <= x; i++)
    {
        while(x % i == 0)
        {
            x /= i;
            if(fac.count(i))
                fac.erase(fac.find(i));
        }
        if(fac.empty())
            return;
    }
    if(x > 1)
        if(fac.count(x))
            fac.erase(fac.find(x));
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n == 1)
        {
            printf("1\n");
            continue;
        }
        divv(n);
        set<int> s1;
        while(!fac.empty())
        {
            int r = *fac.begin();
            int pos = r;
            while(s1.count(pos))
                pos += r;
            s1.insert(pos);
            divv2(pos);
        }            
        printf("%d\n", *(--s1.end()));  
    }
    return 0;
}