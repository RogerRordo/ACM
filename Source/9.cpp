#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<queue>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long
#define oo 2147483647
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
int dats,r,xa,ya,xb,yb,i,j;
double ans1[10],ans2[10];
bool p;
double solve1(int aa,int bb,int cc)
{
	double a=double(aa);
	double b=double(bb);
	double c=double(cc);
	if (b*b-4*a*c<0) return(1e+100);
	if (a==0)
	{
		if (sqrt(b*b-4*a*c)-b>0) return(1e+50);
		return(-1e+50);
	}
	return((sqrt(b*b-4*a*c)-b)/(2*a)); 
}
double solve2(int aa,int bb,int cc)
{
	double a=double(aa);
	double b=double(bb);
	double c=double(cc);
	if (b*b-4*a*c<0) return(1e+100);
	if (a==0)
	{
		if (-sqrt(b*b-4*a*c)-b>0) return(1e+50);
		return(-1e+50);
	}
	return((-sqrt(b*b-4*a*c)-b)/(2*a));
}
int main()
{
    cin>>dats;
	while (dats)
	{
		scanf("%d%d%d%d%d",&r,&xa,&ya,&xb,&yb);
		
		ans1[1]=solve1(xa+ya+r,2*ya-2*xa,r-xa-ya);
		ans1[2]=solve2(xa+ya+r,2*ya-2*xa,r-xa-ya);
		ans2[1]=solve1(xb+yb+r,2*yb-2*xb,r-xb-yb);
		ans2[2]=solve2(xb+yb+r,2*yb-2*xb,r-xb-yb);

		ans1[3]=solve1(xa+ya-r,2*ya-2*xa,-r-xa-ya);
		ans1[4]=solve2(xa+ya-r,2*ya-2*xa,-r-xa-ya);
		ans2[3]=solve1(xb+yb-r,2*yb-2*xb,-r-xb-yb);
		ans2[4]=solve2(xb+yb-r,2*yb-2*xb,-r-xb-yb);
		
		ans1[5]=solve1(xa-ya+r,2*ya+2*xa,r-xa+ya);
		ans1[6]=solve2(xa-ya+r,2*ya+2*xa,r-xa+ya);
		ans2[5]=solve1(xb-yb+r,2*yb+2*xb,r-xb+yb);
		ans2[6]=solve2(xb-yb+r,2*yb+2*xb,r-xb+yb);
		
		ans1[7]=solve1(xa-ya-r,2*ya+2*xa,-r-xa+ya);
		ans1[8]=solve2(xa-ya-r,2*ya+2*xa,-r-xa+ya);
		ans2[7]=solve1(xb-yb-r,2*yb+2*xb,-r-xb+yb);
		ans2[8]=solve2(xb-yb-r,2*yb+2*xb,-r-xb+yb);
		
		//tr(i,1,8) cout<<ans1[i]<<' ';cout<<endl;
		//tr(i,1,8) cout<<ans2[i]<<' ';cout<<endl;

		p=0;
		tr(i,1,8)
		{
			tr(j,1,8)
				if (abs(ans1[i]-ans2[j])<1e-10 && ans1[i]!=1e+100){p=1;break;}
			if (p) break;
		}
		if (p) printf("YES\n"); else printf("NO\n");
	
		dats--;
	}
	return 0;
}