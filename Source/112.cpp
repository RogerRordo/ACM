#include<bits/stdc++.h>
#define tr(i,l,r) for(i=(l);i<=(r);i++)
#define rtr(i,r,l) for(i=(r);i>=(l);i--)
#define maxn 105
#define maxl 1005
using namespace std;
int n,l[maxn],a[maxn][maxl];
int get(char*s)
{
	int res=(s[0]-'1')*12;
	if (s[1]=='C') res+=1;
	else if (s[1]=='D') res+=3;
	else if (s[1]=='E') res+=5;
	else if (s[1]=='F') res+=6;
	else if (s[1]=='G') res+=8;
	else if (s[1]=='A') res+=10;
	else res+=12;
	res=res-(s[2]=='-')+(s[2]=='+');
	return res;
}
void init()
{
	int i,j;
	char s[5];
	scanf("%d",&l[1]);
	tr(i,1,l[1])
	{
		scanf("%s",s);
		a[1][i]=get(s);
	}
	scanf("%d",&n); n++;
	tr(j,2,n)
	{
		scanf("%d",&l[j]);
		tr(i,1,l[j])
		{
			scanf("%s",s);
			a[j][i]=get(s);
		}
	}
}
void work()
{
	int k,ii,jj,ss,i,j,s;
	tr(k,2,n)
	{
		ss=0;
		tr(jj,2,l[k])
		{
			i=1; j=jj; s=0;
			while (i<=l[1]&&j<=l[k])
			{
				s+=a[1][i]==a[k][j];
				i++; j++;
			}
			ss=max(ss,s);
		}
		tr(ii,1,l[1])
		{
			i=ii; j=1; s=0;
			while (i<=l[1]&&j<=l[k])
			{
				s+=a[1][i]==a[k][j];
				i++; j++;
			}
			ss=max(ss,s);
		}
		printf("%.6lf\n",ss*1.0/l[k]);
	}
}
int main()
{
	init();
	work();
	return 0;
}
