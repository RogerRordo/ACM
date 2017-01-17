#include<bits/stdc++.h>
#define tr(i,l,r) for(i=(l);i<=(r);i++)
using namespace std;
int a[1005][1005];
int n,i,j,tx,ty,anss;
double x,y,s,ans;
int main()
{
	scanf("%d",&n);
	tr(i,1,n) 
	{
		scanf("%lf%lf",&x,&y);
		tx=int(round((x+100)*1000))%1000;
		ty=int(round((y+100)*1000))%1000;
		//cout<<tx<<' '<<ty<<endl;
		a[tx][ty]++;
	}
	ans=1E100;
	tr(i,0,999) tr(j,0,999) if (a[i][j])
	{
		s=sqrt(pow(i*1.0/1000.0,2)+pow(j*1.0/1000.0,2));
		if (a[i][j]>anss||(a[i][j]==anss&&s<ans))
		{
			anss=a[i][j];
			ans=s;
		}
	}
	printf("%d %.5lf\n",anss,ans);
	return 0;
}
