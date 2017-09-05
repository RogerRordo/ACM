//st，s都从1开始！
//      1 2 3 4 5 6 7 8
// st:  a b a
//  s:  0 0 a 0 b 0 a 0
//  a:  0 0 1 2 3 2 1 0
/*
	Time: 161129
	Prob: POJ3974
	By RogerRo
 */
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
#define maxl 1000005
using namespace std;
int a[2*maxl];
char dats,st[maxl],s[2*maxl];
int manacher()
{
    int l=strlen(st+1),i,Mm,Mr=0,ans=0;
    memset(a,0,sizeof(a)); s[1]=0xFF;
    tr(i,2,2*l+2) s[i]=(i&1)*st[i/2];
    tr(i,1,2*l+2)
    {
        if (i<Mr) a[i]=min(a[2*Mm-i],Mr-i);
        while (s[i-a[i]-1]==s[i+a[i]+1]) a[i]++;
        if (i+a[i]>Mr) {Mr=i+a[i]; Mm=i;}
        ans=max(ans,a[i]);
    }
    return ans;
}
int main()
{
    while (strcmp(gets(st+1),"END")!=0)
        printf("Case %d: %d\n",++dats,manacher());
    return 0;
}
