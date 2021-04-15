#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, cnt;
struct Line{
    int A, B;
    Line(){}
    Line(int _A, int _B){
        A = _A;
        B = _B;
    }
}L[maxn];
bool operator < (const Line &A, const Line &B){
    return A.A == B.A ? A.B < B.B : A.A < B.A;
}
set<Line> r;
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(r.count(Line(a, b)))    continue;
        r.insert(Line(a, b));
        L[++cnt] = Line(a, b);        
    }
    //printf("%d\n", cnt);
    int ans = 2;
    for(int i = 1; i <= cnt - 1; i++)
    {
        int cp = 0, na = L[i + 1].A, nb = L[i + 1].B;
        set<pair<long double, long double> > visp;
        for(int j = 1; j <= i; j++)
        {
            int ca = L[j].A, cb = L[j].B;
            if(na == ca)    continue;  
            long double cx = 1.0 * (cb - nb) / (ca - na);
            long double cy = cx * ca + cb;
            if(visp.count(make_pair(cx, cy)))   continue;
            visp.insert(make_pair(cx, cy));
            cp++;
            //printf("%d\n", cp);
        }
        ans += cp + 1;
    }
    printf("%d\n", ans);
    return 0;
}