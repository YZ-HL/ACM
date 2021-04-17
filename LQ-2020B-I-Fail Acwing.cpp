#include <bits/stdc++.h>
#define maxn 100005
#define mp(a, b) make_pair(a, b)
#define int __int128
#define abs(x) (x >= 0 ? x : -x)
using namespace std;

inline __int128 read()
{
   int X=0,w=0; char ch=0;
   while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
   while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
   return w?-X:X;
}

//输出：
inline void print(__int128 x)
{    
   if(x<0){putchar('-');x=-x;}
   if(x>9) print(x/10);
   putchar(x%10+'0');
}

int n, cnt, ans = 1;

struct Line{
    int A, B;
    Line(){}
    Line(int _A, int _B){
        A = _A;
        B = _B;
    }
}L[maxn];
bool operator < (const Line &L1, const Line &L2){
    return L1.A == L2.A ? L1.B < L2.B : L1.A < L2.A;
}
set<Line> r;

struct Point{
    int ntor;
    int dtor;
    int f;
    Point(){}
    Point(int _n, int _d, int _f){
        ntor = _n;
        dtor = _d;
        f = _f;
    }
};
bool operator < (const Point &P1, const Point &P2){
    if(P1.ntor == P2.ntor && P1.dtor == P2.dtor)
        return P1.f < P2.f;
    return P1.ntor != P2.ntor ? P1.ntor < P2.ntor : P1.dtor < P2.dtor;
}

int sgn(int x){
    if(x == 0)  return x;
    return (x > 0 ? 1 : -1);
}

signed main(void)
{
    //scanf("%lld", &n);
    n = read();
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        //scanf("%lld %lld", &a, &b);
        a = read();
        b = read();
        if(r.count(Line(a, b)))    continue;
        int cp = 0;
        set<pair<Point, Point> > s;
        for(set<Line>::iterator iter = r.begin(); iter != r.end(); iter++)
        {
            if((*iter).A != a)
            {
                int na = (*iter).A, nb = (*iter).B;
                
                int cx_n = nb - b;
                int cx_d = a - na;
                int bas1 = __gcd(abs(cx_n), abs(cx_d));
                cx_n /= bas1; cx_d /= bas1;
                
                int f1 = (sgn(cx_n) * sgn(cx_d) >= 0); 
                
                if(sgn(cx_n) == 0 || sgn(cx_d) == 0)    f1 = -2;
                //f1 = cx_n * cx_d >= 0;
                //printf("%lld %lld %lld\n", cx_n, cx_d, f1);
                
                int cy_n = cx_n * na + cx_d * nb;
                int cy_d = cx_d;
                int bas2 = __gcd(abs(cy_n), abs(cy_d));
                cy_n /= bas2; cy_d /= bas2;
                
                int f2 = (sgn(cy_n) * sgn(cy_d) >= 0); 

                if(sgn(cy_n) == 0 || sgn(cy_d) == 0)    f2 = -2;
                
                //printf("%lld %lld %lld\n", cy_n, cy_d, f2);
                
                if(s.count(mp(Point(abs(cx_n), abs(cx_d), f1), Point(abs(cy_n), abs(cy_d), f2))))    continue;
                s.insert(mp(Point(abs(cx_n), abs(cx_d), f1), Point(abs(cy_n), abs(cy_d), f2)));
                cp++;
            }
        }
        ans += cp + 1;
        r.insert(Line(a, b));
    }
    print(ans);
    //printf("%lld\n", ans);
    return 0;
}