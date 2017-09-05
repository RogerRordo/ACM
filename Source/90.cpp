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
using namespace std;
int dats,l,i,a[40],n=36,ans;
int b[40]={0,12,11,11,10,10,10,9,9,9,9,8,8,8,8,8,7,7,7,7,7,7,6,6,6,6,6,5,5,5,5,4,4,4,3,3,2};
char s[105];
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
int main()
{
    dats=read();
    while (dats--)
    {
        gets(s); l=strlen(s);
        memset(a,0,sizeof(a));
        tr(i,0,l-1)
            if (s[i]>='A'&&s[i]<='Z') a[s[i]-'A'+1]++;
            else if(s[i]>='0'&&s[i]<='9') a[s[i]-'0'+27]++;
        sort(a+1,a+n+1); ans=0;
        tr(i,1,n) ans+=a[i]*b[i];
        printf("%d\n",ans);
    }
    return 0;
}