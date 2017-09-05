/*
	Time: 161020
	Prob: HDU1556
	By RogerRo
 */
#include<cstdio>
#include<cstring>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 100005
using namespace std;
int n,i,f[maxn];
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
void modify(int x,int y){while (x) {f[x]+=y; x-=x&-x;}}
int sum(int x){int res=0;while (x<=n) {res+=f[x]; x+=x&-x;} return res;}
int main()
{
    while (n=read())
    {
        memset(f,0,sizeof(f));
        tr(i,1,n) {modify(read()-1,-1); modify(read(),1);}
        tr(i,1,n-1) {write(sum(i)); putchar(' ');}
        writeln(sum(n));
    }
    return 0;
}
