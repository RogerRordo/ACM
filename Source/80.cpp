/*
	Time: 161109
	Prob: HDU5973
	By RogerRo
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define rtr(i,r,l) for((i)=(r);(i)>=(l);--i)
using namespace std;
#define maxn 400
#define p 150
int len,l,a[maxn+2],b[maxn+2],c[maxn+2],d[maxn+2],dp,i,j,k,t;
char s[maxn+2];
int deal(int x,int y)
{
    int t=x+c[y]%10-9;
    if (2*y>l) t-=(c[2*y-l])/10;
    if (y>=0&&!(x=deal(t/10,y-1)))
        c[y]+=(t+999)%10-c[y]%10;
    return x;
}
int main()
{
    //d=0.5+sqrt(1.25)
    c[p]=1; c[p+1]=2; c[p+2]=5;
    dp=p-1;
    for(l=p-1;l<=maxn;l++)
    {
        c[++l]+=10;
        while (!deal(0,l)) c[l]+=20;
        d[++dp]=c[l]/20;
        c[l]-=10;
    }
    d[p+1]+=5;

    while (~scanf("%s",&s))
    {
        //init
        memset(a,0,sizeof(a)); memset(b,0,sizeof(b)); memset(c,0,sizeof(c));
        len=strlen(s); tr(i,0,len-1) a[p-len+i+1]=s[i]-'0';
        scanf("%s",&s);
        len=strlen(s); tr(i,0,len-1) b[p-len+i+1]=s[i]-'0';
        tr(i,1,maxn) if (a[i]!=b[i]) break;
        if (i<=maxn&&a[i]>b[i]) swap(a,b);
        //b=b-a
        rtr(i,maxn,1) if ((b[i]=b[i]-t-a[i])<0) {b[i]+=10;t=1;} else t=0;
        //c=b*d
        rtr(i,maxn,1) rtr(j,maxn,1)
            if ((k=i+j-p)>=1&&k<=maxn)
            {
                c[k]+=t+b[i]*d[j];
                t=c[k]/10;
                c[k]=c[k]%10;
            }
        //a==floor(c)?
        tr(i,1,p) if (a[i]!=c[i]) break;
        if (i>p) printf("0\n"); else printf("1\n");
    }
    return 0;
}
