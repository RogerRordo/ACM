#include<bits/stdc++.h>
#define tr(i,l,r) for(i=(l);i<=(r);i++)
#define rtr(i,r,l) for(i=(r);i>=(l);i--)
using namespace std;
char a[205][205];
int n,x,y,i,j,mnx,mny,mxx,mxy;
int main()
{
	scanf("%d",&n);
	tr(i,0,200) tr(j,0,200) a[i][j]='.';
	tr(i,0,200) a[100][i]='|';
	tr(i,0,200) a[i][100]='-';
	a[100][100]='+';
	mxx=mxy=-205; mnx=mny=205;
	tr(i,1,n)
	{
		scanf("%d%d",&x,&y); x+=100; y+=100;
		mnx=min(mnx,x); mxx=max(mxx,x);
		mny=min(mny,y); mxy=max(mxy,y);
		a[x][y]='*';
	}
	//cout<<mnx<<' '<<mxx<<' '<<mny<<' '<<mxy<<endl;
	if (mxx<100) mxx=100;
	if (mxy<100) mxy=100;
	if (mnx>100) mnx=100;
	if (mny>100) mny=100;
	rtr(i,mxy,mny)
	{
		tr(j,mnx,mxx) putchar(a[j][i]);
		puts("");
	}
	return 0;
}
