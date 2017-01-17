#include<bits/stdc++.h>
#define tr(i,l,r) for(i=(l);i<=(r);i++)
using namespace std;
map<int,int> a;
int l1,l2,n,ans,tt;
char ch;
string t;
deque<int> q;
int get(string t)
{
	return (t[0]-33)*10000+(t[1]-33)*100+(t[2]-33);
}
int main()
{
	while((ch=getchar())!='\n')
	{
		if (ch==' ')
		{
			int& at = a[get(t)];
			if (at == 0) n++;
			at++;
			t="";
			l1++;
		} else
		{
			t+=ch;
		}	
	}
	{
			int& at = a[get(t)];
			if (at == 0) n++;
			at++;
			t="";
			l1++;
	}
	
	while((ch=getchar())!='\n'&&ch!=EOF)
	{
		if (ch==' ')
		{
			int& at = a[get(t)];
			if (at==0) n++;
			at--;
			if (at==0) n--;
			l2++;
			q.push_back(get(t));
			t="";
			if (l2>l1)
			{
				tt=q.front(); q.pop_front();
				int& att = a[tt];
				if (att==0) n++;
				att++;
				if (att==0) n--;
			}
			if (n==0) ans++;
		} else
		{
			t+=ch;
		}	
		
	}
	
	{
			int& at = a[get(t)];
			if (at==0) n++;
			at--;
			if (at==0) n--;
			l2++;
			q.push_back(get(t));
			t="";
			if (l2>l1)
			{
				tt=q.front(); q.pop_front();
				int& att = a[tt];
				if (att==0) n++;
				att++;
				if (att==0) n--;
			}
			if (n==0) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
