/*
	Time: 161012
	Prob: HDU2222
	By RogerRo
 */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 10005
#define maxp 55
#define maxt 1000005
using namespace std;
struct ac{int s,to[26],fail;} a[maxn*maxp];
int dats,m,n;
char ts[maxp],s[maxt];
queue<int> b;
void clear(int x)
{
    a[x].s=a[x].fail=0;
    memset(a[x].to,0,sizeof(a[x].to));
}
void ins(char *st)
{
    int i,x=0,c,l=strlen(st);
    tr(i,0,l-1)
    {
        if (!a[x].to[c=st[i]-'a']) {a[x].to[c]=++m; clear(m);}
        x=a[x].to[c];
    }
    a[x].s++;
}
void build()
{
    int i,h,t;
    tr(i,0,25) if (t=a[0].to[i]) b.push(t);
    while (b.size())
    {
        h=b.front(); b.pop();
        tr(i,0,25)
        if (t=a[h].to[i])
        {
            a[t].fail=a[a[h].fail].to[i];
            b.push(t);
        } else a[h].to[i]=a[a[h].fail].to[i];
    }
}
int cnt(char *st)
{
    int i,x=0,c,t,cnt=0,l=strlen(st);
    tr(i,0,l-1)
    {
        c=st[i]-'a';
        while (!a[x].to[c]&&x) x=a[x].fail;
        x=a[x].to[c];
        for(t=x;t&&a[t].s>-1;t=a[t].fail) {cnt+=a[t].s; a[t].s=-1;}
    }
    return cnt;
}
int main()
{
    scanf("%d",&dats);
    while (dats--)
    {
        m=0; clear(0);
        scanf("%d",&n);
        while (n--)
        {
            scanf("%s",ts);
            ins(ts);
        }
        build();
        scanf("%s",s);
        printf("%d\n",cnt(s));
    }
    return 0;
}
