//要sqrt就一定要len和dcm是偶数
//不可以出现如big x=y;的东西，必须分开成big x;x=y;
/*
	Time:
	Prob:
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
#define len 500//3000
#define dcm 200//3000
using namespace std;
void carry(int*x,int y){*(x-1)+=((*x+=y)+10000)/10-1000;*x=(*x+10000)%10;}
struct big
{
    int _[len+2];
    
    int& operator[](int x){return _[x];}
    big(){memset(_,0,sizeof(int)*(len+2));}
    big(char*x)
    {
        memset(_,0,sizeof(int)*(len+2));
        char *y=x+strlen(x)-1,*z=strchr(x,'.'),*i;
        if (!z) z=y+1;
        int t=dcm-(z-x);
        tr(i,x,y) if(i!=z&&t>=1&&t<=len) _[++t]=*i-'0';
    }
    
    big& operator=(const big&x){memcpy(_,x._,sizeof(int)*(len+2));return *this;}
    char* c_str()
    {
        char *s=new char[len]; int l,r,i=0,k;
        tr(l,1,len) if(_[l]>0||l==dcm) break;
        rtr(r,len,1) if(_[r]>0||r==dcm) break;
        tr(k,l,r){if(k==dcm+1)s[i++]='.';s[i++]=_[k]+'0';}
        s[i]=0; return s;
    }
    
    friend int comp(big x,big y) //O(len)
    {
        int i;
        tr(i,1,len) if (x[i]!=y[i]) break;
        return i>len?0:(x[i]>y[i]?1:-1);
    }
    friend big operator+(big x,big y) //O(len)
    {
        big z; int i;
        rtr(i,len,1) carry(&z[i],x[i]+y[i]);
        return z;
    }
    friend big operator-(big x,big y) //O(len)
    {
        big z; int i;
        rtr(i,len,1) carry(&z[i],x[i]-y[i]);
        return z;
    }
    friend big operator*(big x,big y) //O(len^2)
    {
        big z; int i,j;
        rtr(i,len,1) rtr(j,min(dcm+len-i,len),max(dcm+1-i,1))
            carry(&z[i+j-dcm],x[i]*y[j]);
        return z;
    }
    friend big operator/(big x,big y) //O(len^2)
    {
        big z,t,tmp[10]; int i,j,k;
        tr(k,1,9) tmp[k]=tmp[k-1]+y;
        tr(j,1,len-dcm) t[j+dcm]=x[j];
        j--;
        tr(i,1,len)
        {
            tr(k,1,len-1) t[k]=t[k+1];
            t[len]=++j<=len?x[j]:0;
            tr(k,1,9) if (comp(tmp[k],t)>0) break;
            z[i]=--k;
            t=t-tmp[k];
        }
        return z;
    }
    friend int sqrt_deal(big&y,int a,int b,int l)
    {
        int t=a+y[b]%10-9;
        if(2*b>l)t-=(y[2*b-l])/10;
        if (b>=0&&!(a=sqrt_deal(y,t/10,b-1,l))) y[b]+=(t+999)%10-y[b]%10;
        return a;
    }
    friend big sqrt(big x) //O(len^2)
    {
        int l,t=dcm/2; big y,z; y=x;
        for(l=1;l<=len;l++)
        {
            y[++l]+=10;
            while (!sqrt_deal(y,0,l,l)) y[l]+=20;
            z[++t]=y[l]/20; y[l]-=10;
        }
        return z;
    }
    friend big floor(big x)
    {
        big z; z=x; int i;
        tr(i,dcm+1,len) z[i]=0;
        return z;
    }
    friend big ceil(big x){return comp(x,floor(x))==0?x:floor(x+big("1"));}
};
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void write(int x)
{
    char a[20],s=0;
    if (x==0){putchar('0'); return ;}
    if (x<0) {putchar('-'); x=-x;}
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(int x){write(x); putchar('\n');}
int main()
{

    return 0;
}

