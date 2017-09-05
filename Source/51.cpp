/*
	Time: 161020
	Prob: UVA12086
	By RogerRo
 */
#include<cstdio>
#include<cstring>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 200005
using namespace std;
int dats,n,i,tx,ty,a[maxn],f[maxn];
char tc;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void write(int x)
{
    char a[20],s=0;
    if (x==0){putchar('0'); return ;}
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(int x){write(x); putchar('\n');}
void modify(int x,int y){while (x<=n) {f[x]+=y; x+=x&-x;}}
int sum(int x){int res=0;while (x) {res+=f[x]; x-=x&-x;} return res;}
int main()
{
    while ((n=read())>0)
    {
        if (dats) puts("");
        printf("Case %d:\n",++dats);
        memset(f,0,sizeof(f));
        tr(i,1,n) {a[i]=read(); modify(i,a[i]);}
        while (~scanf("%c",&tc)&&tc!='E')
        {
            tx=read(); ty=read();
            if (tc=='S') {modify(tx,ty-a[tx]); a[tx]=ty;}
            else writeln(sum(ty)-sum(tx-1));
        }
    }
    return 0;
}
