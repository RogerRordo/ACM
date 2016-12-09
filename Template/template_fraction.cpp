int gcd(int x,int y){return y?gcd(y,x%y):x;}
struct frac
{
	int x,y;	//符号放在x
	frac adjust()
	{
		if (!y) {x=0; return *this;}
		if (!x) {y=1; return *this;}
		int sg=(x>0?1:-1)*(y>0?1:-1);
		int t=gcd(x=abs(x),y=abs(y)); x=x/t*sg; y/=t;
		return *this;
	}
	frac(){}
	frac(int a,int b){x=a;y=b;this->adjust();}
	frac(char *a,bool improp=0) //improp假分数
	{
        int t,sg=1;
        if (*a=='-') {sg=-1; a++;}
        if (improp&&strchr(a,' ')) {sscanf(a,"%d %d/%d",&t,&x,&y); x+=t*y;}
        else if (strchr(a,'/')) sscanf(a,"%d/%d",&x,&y);
        else {sscanf(a,"%d",&x); y=1;}
        x*=sg; this->adjust();
	}
	char* c_str(bool improp=0)
	{
		char *res=new char[50](),t[50];
		this->adjust();
		if (x==0) {res[0]='0'; return res;}
		if (x<0) {strcat(res,"-"); x=-x;}
		if (improp&&x/y&&x%y){sprintf(t,"%d ",x/y); strcat(res,t); x%=y;}
		sprintf(t,"%d",x); strcat(res,t);
		if (y!=1) {sprintf(t,"/%d",y); strcat(res,t);}
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
const frac nonfrac=frac(0,0);
const frac zerofrac=frac(0,1);
