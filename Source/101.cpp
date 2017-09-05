#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<bitset>
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define rtr(i,r,l) for((i)=(r);(i)>=(l);--i)
#define oo 0x7F7F7F7F
#define maxn 200005
using namespace std;
int n,a[maxn];
char s[maxn];
bool p[maxn];
int read()
{
    int x=0; bool f=0;
    char ch=getchar();
    while (ch<'0'||ch>'9') {f|=ch=='-'; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0'; ch=getchar();}
    return (x^-f)+f;
}
void write(int x)
{
    char a[20],s=0;
    if (x==0){putchar('0'); return ;}
    if (x<0) {putchar('-'); x=-x;}
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(int x){write(x); putchar('\n');}
void writeb(int x){write(x); putchar(' ');}
void init()
{
    scanf("%d\n",&n);
    gets(s);
}
void work()
{
    int k=0,d=0,r=0,i=-1; char ans='\0';
    while (k<n)
    {
        i=(i+1)%n;
        if (p[i]) continue;
        ans=s[i];;
        if (s[i]=='D')
        {
            if (d) {d--; p[i]=1;} else {r++; k++;}
        }
        else
        {
            if (r) {r--; p[i]=1;} else {d++; k++;}
        }
    }
    printf("%c\n",ans);
}
int main()
{
    init();
    work();
    return 0;
}
