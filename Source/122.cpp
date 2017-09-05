#include<bits/stdc++.h>
#define tr(i,l,r) for(i=(l);i<=(r);i++)
using namespace std;

int d[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
int f[10][10][10];
char st[10][10],s[10][10];

void Copy(){memcpy(s,st,sizeof(s));}
bool Can(int x,int y,int z)
{
//cout<<x<<' '<<y<<' '<<z<<endl;
int	h,t,zz=z,tx,ty,tz;
	memset(f,0,sizeof(f));
	f[x][y][z]=1;
	while (1)
	{
		//cout<<"===="<<a.x<<' '<<a.y<<' '<<a.z<<endl;
		//
		if  (z!=zz&&f[x][y][z]>3)
			if ((z==0&&y==1)||(z==1&&x==1)||(z==2&&y==5)||(z==3&&x==5))
				return 1;
		//	
		tx=x+d[z][0]; ty=y+d[z][1]; tz=z^2;
		if (tx>=1&&tx<=5&&ty>=1&&ty<=5&&!f[tx][ty][tz])
		{
			f[tx][ty][tz]=f[x][y][z]+1;
			x=tx; y=ty; z=tz;
			continue;
		}
		//
		tx=x; ty=y;
		if (s[x][y]=='/') tz=z^1; 
		else if (s[x][y]=='\\') tz=3-z;
		else return 0;
		if (tx>=1&&tx<=5&&ty>=1&&ty<=5&&!f[tx][ty][tz])
		{
			f[tx][ty][tz]=f[x][y][z]+1;
			x=tx; y=ty; z=tz;
			continue;
		}
		return 0;
	}
	return 0;
}

bool Solved()
{
int	i;
	tr(i,1,5)
	if	(Can(1,i,1)||Can(5,i,3)||Can(i,1,0)||Can(i,5,2)) return 1;
	return 0;
}

int main()
{
int	i,j,x,y;

	tr(i,1,5) scanf("%s",st[i]+1);
	tr(i,1,5) tr(j,1,5) if (st[i][j]=='*') {x=i; y=j;}
	Copy();
	if  (Solved())
	{
		printf("WIN\n");
		return 0;
	}
	tr(i,1,x-1)
	{
		Copy();
		for (j=x;j>x-i;j--) s[j][y]=s[j-1][y];
		s[x-i][y]='*';
		if  (Solved())
		{
			printf("D%d\n",i);
			return 0;
		}
	}
	
	tr(i,1,5-x)
	{
		Copy();
		for (j=x;j<x+i;j++) s[j][y]=s[j+1][y];
		s[x+i][y]='*';
		if  (Solved())
		{
			printf("U%d\n",i);
			return 0;
		}
	}
	
	tr(i,1,y-1)
	{
		Copy();
		for (j=y;j>y-i;j--) s[x][j]=s[x][j-1];
		s[x][y-i]='*';
		if  (Solved())
		{
			printf("R%d\n",i);
			return 0;
		}
	}
	
	tr(i,1,5-y)
	{
		Copy();
		for (j=y;j<y+i;j++) s[x][j]=s[x][j+1];
		s[x][y+i]='*';
		if  (Solved())
		{
			printf("L%d\n",i);
			return 0;
		}
	}
	printf("FAIL\n");
	
	return 0;
}
