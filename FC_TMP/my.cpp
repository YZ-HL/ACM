#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 5000005
#define int long long
#define BLOCK_LENGTH 5000000
using namespace std;
bool isp_s[maxn], isp_l[maxn];
int t, n, k;
int table[] = {0, 838596693108,2364728301248,3823097653715,5246155169981,6643178394102,8027049707812,9388226084984,10757376545189,12090729942028,13440410138110,14755104304286,16094247428837,17401803981195,18731223854764,20026736125708,21317781912884,22632874242681,23906303820299,25233207382477,26490958703868,27802000335535,29091051334023,30300518132207,31606727206204,32890617377828,34175431266959,35413715855104,36676553613240,37961213897248,39205525289667,40436501824379,41722190422309,42984991779000,44237164624767,45485788090635,46791192534993,47925497972627,49216153199757,50455743121030,51618831732546,52960990849498,54189519013285,55386727412672,56608857143864,57924651992377,59081508484896,60320440111766,61637252051789,62835665189558,64017959658854,65271086020049,66445887695063,67704686021411,68907121434101,70158903049226,71379301888909,72548845804560,73825301263594,75038045864951,76196821347705,77469890655251,78749937215637,79850673089246,81014003648421,82280010445434,83557228521433,84678977639740,85879510232380,87246743784406,88329735183791,89539118085727,90715812272693,91901931611882,93195554935021,94373244548667,95740977474843,96805247568071,97940738312290,99135927597609,100385468050143,101536479029900,102739815411419,103996084944012,105064821055590,106482464732063,107534073088026,108726929986141,109862403065096,111279455731446,112324029504549,113490342913401,114696151067225,115913058971691,117130183421589,118177352757998,119658978471360,120633231686709,121839592811651,122996511010923,124255024703640,125201006481038,126483797974539,127549909040152,129145694366357,130060484786803,131396096671020,132457203914022,133803121800957,134685202583080,136167077923029,137371846107848,138346755954632,139614663301592,140701266803520,141989220176296,143146843208371,144273355553544,145517640076189,146748822127536,147868893424923,149284936191800,150031424436501,151426623923835,152347997300663,153724731687557,154926025645540,155961181184243,157233962467634,158251442815755,159697656926328,160772941867416,161994272626133,163076363401678,164201195111815,165454218988871,166543118729111,167605839279187,169128322827135,170163076973099,171208721763383,172458592225563,173677789221887,174658637627907,175793478458888,177348383466513,177987747693773,179307045235984,180709088792387,181796897017235,182651200351383,183916320530477,185307262782123,186259809199624,187642072473270,188777065874656,189807297950587,191260250841948,192429822271719,193264095362415,194636180524245,195819712328472,197026580775694,197914529347699,199247280250582,200186269171766,201507588519260,202774663160391,203875404366431,204984362252633,206155708785785,207241528040416,208180014232236,209574911845945,210857203553443,212001300854433,212787542274646,214004616484930,215265805818499,216479449337510,217418404556099,218666852753071,220568725990439,221381613203236,222416914431794,223302838191513,224256815488667,225884023502033,226645423923202,228110217203153,229313810734714,230352096252165,231720987934262,232777334416143,233781990447907,234901405584044,235810296318988,237528569607573,238352716599656,239595190871224,240814910985589};
void inits(int lim){
    memset(isp_s, true, sizeof(isp_s));
    for(int i = 2; i <= lim; i++)
    {
        if(isp_s[i])
        {
            for(int j = i*2; j <= lim; j += i)
            {
                isp_s[j] = false;
            }
        }
    }
}
int Prime_Cnt(int s, int lim){
    memset(isp_l, true, sizeof(isp_l));
    for(int i = 2; i * i <= lim; i++)
    {
        if(isp_s[i])
        {
            int nows = max(2*i, i * (s % i ? s / i + 1 : s / i));
            for(int j = nows; j <= lim; j += i)
                isp_l[j - s] = false;
        }
    }
    int sum = 0;
    for(int i = s; i <= lim; i++)
        if(isp_l[i - s])    sum += i;
    return s == 1 ? sum - 1 : sum;
}
int solve(int lim){
    int s = 1, sum = 0, cnt = 0;
    while(s + BLOCK_LENGTH - 1 <= lim)  sum = (sum + table[++cnt]) % k, s += BLOCK_LENGTH;
    if(s != lim + 1)    
        sum += Prime_Cnt(s, lim), sum %= k;
    return sum;
}
signed main(void)
{
    scanf("%lld", &t);
    inits(100000);
    while(t--)
    {
        scanf("%lld %lld", &n, &k);
        int inv = ((k - k / 2) % k);
        int sum = ((((((n + 3) % k) * (n % k)) % k) * (inv % k)) % k);
        int ans = (sum + (solve(n + 1) % k)) % k;
        printf("%lld\n", (ans + k - 4) % k);
    }
    //system("pause");
    return 0;
}
