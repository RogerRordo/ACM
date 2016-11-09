/*
	Time: 161109
	Prob: CODEVS3119
	By RogerRo
 */
#include<cstdio>
#include<cstring>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
#define maxn 1200
int l,len,a[maxn];
void init()
{
    int i; char s[maxn];
    scanf("%s",&s); len=strlen(s);
    tr(i,0,len-1) a[i+(len&1)]=s[i]-'0';
    len+=len&1;
}
int deal(int x,int y)
{
    int t=x+a[y]%10-9;
    if (2*y>l) t-=(a[2*y-l])/10;
    if (y>=0&&!(x=deal(t/10,y-1)))
        a[y]+=(t+999)%10-a[y]%10;
    return x;
}
void work()
{
    for(l=0;l<len;l++)
    {
        a[++l]+=10;
        while (!deal(0,l)) a[l]+=20;
        putchar(a[l]/20+'0');
        a[l]-=10;
    }
    putchar('\n');
}
int main()
{
    init();
    work();
    return 0;
}
