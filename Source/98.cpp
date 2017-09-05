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
#define maxn 200000
using namespace std;
ll a[4];
char ans[maxn],c[4];
void work()
{
    ll n=int(sqrt(2*(a[1]+a[2]+a[3]))),i,x,delta;
    if (n*(n+1)!=2*(a[1]+a[2]+a[3])) {cout<<"Impossible\n"; return;}

    rtr(i,n,1)
    {
        if (a[1]<a[2]){swap(a[1],a[2]);swap(c[1],c[2]);}
        if (a[1]<a[3]){swap(a[1],a[3]);swap(c[1],c[3]);}
        
        if (a[2]>0&&(delta=(2*i+1)*(2*i+1)-8*a[2])>0)
        {
            x=((2*i+1)-sqrt(delta))/2;
            if ((2*i-x+1)*x==2*a[2])
            {
                a[2]-=i; ans[i-1]=c[2];
                continue;
            }
        }
        
        if (a[3]>0&&(delta=(2*i+1)*(2*i+1)-8*a[3])>0)
        {
            x=((2*i+1)-sqrt(delta))/2;
            if ((2*i-x+1)*x==2*a[3])
            {
                a[3]-=i; ans[i-1]=c[3];
                continue;
            }
        }
        
        a[1]-=i;ans[i-1]=c[1];
    }
    if (!(a[1]==0&&a[2]==0&&a[3]==0)) {cout<<"Impossible\n"; return;}
    printf("%s\n",ans);
}
int main()
{
	cin>>a[1]>>a[2]>>a[3];
    c[1]='W'; c[2]='G'; c[3]='B';
    work();
	return 0;
}
