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
#define oo 0x7F7F7F7F
#define maxl 105
using namespace std;
char s[maxl],t[4];
int T,n,i,j;
void print()
{
	int i,sr=0,sb=0,sy=0,sg=0;
	tr(i,0,n-1) if (s[i]=='!')
	{
		if (t[i%4]=='R') sr++;
		if (t[i%4]=='B') sb++;
		if (t[i%4]=='Y') sy++;
		if (t[i%4]=='G') sg++;
	}
	printf("%d %d %d %d\n",sr,sb,sy,sg);
	//printf("%c%c%c%c",t[0],t[1],t[2],t[3]);
}
int main()
{
    #ifdef DEBUG
    	freopen("in.txt","r",stdin);
    #endif
    srand(time(0));
    T=10000;
    t[0]='R'; t[1]='B'; t[2]='Y'; t[3]='G';
    gets(s); n=strlen(s);
    tr(i,1,T)
    {
    	swap(t[rand()%4],t[rand()%4]);
    	tr(j,0,n-1) if (s[j]!='!'&&s[j]!=t[j%4]) break;
    	if (j!=n) continue;
    	print();
    	break;
    }
    return 0;
}
