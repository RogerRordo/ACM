//^是O(n^2.8)的矩阵乘法；一定要用引用传递mat，不然会爆
#define maxn 130
struct mat
{
    int n,m,a[maxn][maxn];
    mat(int nn=0,int mm=0):n(nn),m(mm){}
    int* operator[](int x){return a[x];}
};
const mat nonmat(-1,-1);
mat unit(int n)
{
    mat res(n,n);
    int i,j;
    tr(i,1,res.n) tr(j,1,res.n) if (i==j) res[i][j]=1; else res[i][j]=0;
    return res;
}
mat operator+(mat&a,mat&b)
{
    if (a.n!=b.n||a.m!=b.m) return nonmat;
    mat c(a.n,a.m); int i,j;
    tr(i,1,a.n) tr(j,1,a.m) c[i][j]=a[i][j]+b[i][j];
    return c;
}
mat operator-(mat&a,mat&b)
{
    if (a.n!=b.n||a.m!=b.m) return nonmat;
    mat c(a.n,a.m); int i,j;
    tr(i,1,a.n) tr(j,1,a.m) c[i][j]=a[i][j]-b[i][j];
    return c;
}
mat operator*(mat&a,mat&b)
{
    if (a.m!=b.n) return nonmat;
    mat c(a.n,b.m); int i,j,k;
    tr(i,1,a.n) tr(j,1,b.m)
    {
        c[i][j]=0;
        tr(k,1,a.m) c[i][j]+=a[i][k]*b[k][j];
    }
    return c;
}
mat operator^(mat&a,ll b)
{
	if (a.n!=a.m) return nonmat;
    mat res=unit(a.n);
    while (b)
    {
        if (b&1) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
//===================================================================
void _as(mat&a,int x1,int y1,mat&b,int x2,int y2,int nn,int mm,bool chnm=0) //assign
{
    int i,j; tr(i,1,nn) tr(j,1,mm) a[x1+i-1][y1+j-1]=b[x2+i-1][y2+j-1];
    if (chnm) {a.n=x1+nn-1; a.m=y1+mm-1;}
}
void _st(mat&a,mat&b,mat&c,int n,int m,int k)  //strassen
{
    if (n<=32||m<=32||k<=32){c=a*b;return;}
    c.n=n; c.m=m;
    n>>=1; m>>=1; k>>=1;
    mat a11,a12,a21,a22,b11,b12,b21,b22,m1,m2,m3,m4,m5,m6,m7,t1,t2;
    _as(a11,1,1,a,1,1,n,k,1);       _as(a12,1,1,a,1,k+1,n,k,1);
    _as(a21,1,1,a,n+1,1,n,k,1);     _as(a22,1,1,a,n+1,k+1,n,k,1);
    _as(b11,1,1,b,1,1,k,m,1);       _as(b12,1,1,b,1,m+1,k,m,1);
    _as(b21,1,1,b,k+1,1,k,m,1);     _as(b22,1,1,b,k+1,m+1,k,m,1);
    t1=a11+a22;t2=b11+b22;          _st(t1,t2,m1,n,m,k);
    t1=a21+a22;t2=b11;              _st(t1,t2,m2,n,m,k);
    t1=a11;t2=b12-b22;              _st(t1,t2,m3,n,m,k);
    t1=a22;t2=b21-b11;              _st(t1,t2,m4,n,m,k);
    t1=a11+a12;t2=b22;              _st(t1,t2,m5,n,m,k);
    t1=a21-a11;t2=b11+b12;          _st(t1,t2,m6,n,m,k);
    t1=a12-a22;t2=b21+b22;          _st(t1,t2,m7,n,m,k);
    t1=m1+m4; t1=t1-m5; t1=t1+m7;   _as(c,1,1,t1,1,1,n,m);
    t1=m3+m5;                       _as(c,1,m+1,t1,1,1,n,m);
    t1=m2+m4;                       _as(c,n+1,1,t1,1,1,n,m);
    t1=m1-m2; t1=t1+m3; t1=t1+m6;   _as(c,n+1,m+1,t1,1,1,n,m);
}
int __enlarge(int x){int t=1<<(31-__builtin_clz(x)); return t==x?x:(t<<1);}
mat operator^(mat&a,mat&b)
{
    if (a.m!=b.n) return mat(-1,-1);
    int n=__enlarge(a.n),m=__enlarge(b.m),k=__enlarge(a.m);
    mat c; _st(a,b,c,n,m,k);
    c.n=a.n; c.m=b.m;
    return c;
}
