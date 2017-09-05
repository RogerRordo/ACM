#include<bits/stdc++.h>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define rtr(i,r,l) for((i)=(r);(i)>=(l);--i)
#define ll long long
using namespace std;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
struct frac
{
	ll x,y;
	frac adjust()
	{
		if (!y) {x=0; return *this;}
		if (!x) {y=1; return *this;}
		ll sg=(x>0?1:-1)*(y>0?1:-1);
		ll t=gcd(x=abs(x),y=abs(y)); x=x/t*sg; y/=t;
		return *this;
	}
	frac(){}
	frac(ll a,ll b){x=a;y=b;this->adjust();}
	frac(char *a,bool improp=0)
	{
        ll t,sg=1;
        if (*a=='-') {sg=-1; a++;}
        if (improp&&strchr(a,' ')) {sscanf(a,"%lld %lld/%lld",&t,&x,&y); x+=t*y;}
        else if (strchr(a,'/')) sscanf(a,"%lld/%lld",&x,&y);
        else {sscanf(a,"%lld",&x); y=1;}
        x*=sg; this->adjust();
	}
	char* c_str(bool improp=0)
	{
		char *res=new char[50](),t[50];
		this->adjust();
		if (x==0) {res[0]='0'; return res;}
		if (x<0) {strcat(res,"-"); x=-x;}
		if (improp&&x/y&&x%y){sprintf(t,"%lld ",x/y); strcat(res,t); x%=y;}
		sprintf(t,"%lld",x); strcat(res,t);
		if (y!=1) {sprintf(t,"/%lld",y); strcat(res,t);}
		return res;
	}
};
bool operator==(frac a,frac b){a.adjust();b.adjust();return a.x==b.x&&a.y==b.y;}
bool operator!=(frac a,frac b){a.adjust();b.adjust();return !(a.x==b.x&&a.y==b.y);}
bool operator>(frac a,frac b){if(a.x*b.x<=0)return a.x>b.x;return a.x*b.y>b.x*a.y;}
bool operator<(frac a,frac b){if(a.x*b.x<=0)return a.x<b.x;return a.x*b.y<b.x*a.y;}
frac operator+(frac a,frac b){return frac(a.x*b.y+a.y*b.x,a.y*b.y).adjust();}
frac operator-(frac a,frac b){return frac(a.x*b.y-a.y*b.x,a.y*b.y).adjust();}
frac operator*(frac a,frac b){return frac(a.x*b.x,a.y*b.y).adjust();}
frac operator/(frac a,frac b){return frac(a.x*b.y,a.y*b.x).adjust();}
const frac nonfrac=frac(0LL,0LL);
const frac zerofrac=frac(0LL,1LL);

struct T
{
	ll type;	//0:num 1:var 2:n 3:lag 4:ext
	ll x;
	vector<ll> to;
};

ll m,n=7,v[30];
T b[30];
frac a[10][10],ans[10];

void init()
{
	ll dep[10],ly;
	static ll var[30];
	static char fr[130];
	dep[0]=1;
	b[m=1].type=4;
	while (gets(fr)!=NULL)
	{
		m++;
		ly=1;
		while(fr[(ly-1)*4]==' ') ly++;
		dep[ly]=m;
		if (fr[(ly-1)*4]=='f') 
		{
			char s1[4],s2[2],s3[3],s4[10];
			sscanf(fr,"%s%s%s%s",s1,s2,s3,s4);
			var[s2[0]-'a']=m;
			if (s4[6]=='n') b[m].type=2;
			else if (s4[6]>='0'&&s4[6]<='9')
			{
				b[m].type=0;
				b[m].x=s4[6]-'0';
			} else
			{
				b[m].type=1;
				b[m].x=var[s4[6]-'a'];
			}
		} else b[m].type=3;
		b[dep[ly-1]].to.push_back(m);
	}
}
void gauss()
{
	ll j,k,x,y;
	frac t;
	tr(j,1,n)
	{
		tr(k,j,n) if (a[k][j]!=zerofrac) break;
		if (k>n) continue;
		if (k!=j) tr(y,j,n+1) swap(a[j][y],a[k][y]);
		tr(x,1,n) if (x!=j)
		{
			t=a[x][j]/a[j][j];
			tr(y,j,n+1) a[x][y]=a[x][y]-a[j][y]*t;
		}
	}
	rtr(k,n,1)
	{
		ans[k]=a[k][n+1];
		rtr(j,n,k+1) ans[k]=ans[k]-ans[j]*a[k][j];
		ans[k]=ans[k]/a[k][k];
	}
}
ll get(ll t,ll nn)
{
	if (b[t].type==3) return 1;
	ll res=0,r;
	if (b[t].type==4) r=0;
	else if (b[t].type==2) r=nn-1;
	else if (b[t].type==1) r=v[b[t].x]-1;
	else if (b[t].type==0) r=b[t].x-1;
	tr(v[t],0,r)
	{
		vector<ll>::iterator it;
		for(it=b[t].to.begin();it!=b[t].to.end();it++)
			res+=get(*it,nn);
		
	}
	return res;
}
void __print()
{
	int i,j;
	tr(i,1,n)
	{
		tr(j,1,n+1) printf("%s ",a[i][j].c_str());
		puts("");
	}
}
void work()
{
	ll i,j;
	tr(i,1,n) 
	{
		a[i][1]=frac(1,1);
		tr(j,2,n) a[i][j]=a[i][j-1]*frac(i,1);
		memset(v,0,sizeof(v));
		a[i][n+1]=frac(get(1,i),1);
	}
	//__print();
	gauss();
	printf("(%s)",ans[1].c_str());
	tr(i,2,n)
	{
		printf("+(%s",ans[i].c_str());
		tr(j,1,i-1) printf("*n");
		printf(")");
	}
	printf("\n");
}
int main()
{
	freopen("fygon.in","r",stdin);
	freopen("fygon.out","w",stdout);
    init();
    work();
    return 0;
}
