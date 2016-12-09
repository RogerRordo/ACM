//^是O(n^2.8)的矩阵乘法
#define maxn 105
struct mat
{
    int n,m,a[maxn][maxn];
    mat(int nn=0,int mm=0):n(nn),m(mm){memset(a,0,sizeof(a));}
    void assign(int x1,int y1,mat b,int x2,int y2,int nn,int mm,bool chnm=0)
    {
        int i,j; tr(i,1,nn) tr(j,1,mm) a[x1+i-1][y1+j-1]=b[x2+i-1][y2+j-1];
        if (chnm) {n=x1+nn-1; m=y1+mm-1;}
    }
    int* operator[](int x){return a[x];}
};
const mat nonmat(-1,-1);
mat operator+(mat a,mat b)
{
    if (a.n!=b.n||a.m!=b.m) return nonmat;
    mat c(a.n,a.m); int i,j;
    tr(i,1,a.n) tr(j,1,a.m) c[i][j]=a[i][j]+b[i][j];
    return c;
}
mat operator-(mat a,mat b)
{
    if (a.n!=b.n||a.m!=b.m) return nonmat;
    mat c(a.n,a.m); int i,j;
    tr(i,1,a.n) tr(j,1,a.m) c[i][j]=a[i][j]-b[i][j];
    return c;
}
mat operator*(mat a,mat b)
{
    if (a.m!=b.n) return nonmat;
    mat c(a.n,b.m); int i,j,k;
    tr(i,1,a.n) tr(j,1,b.m) tr(k,1,a.m) c[i][j]+=a[i][k]*b[k][j];
    return c;
}
void __strassen(mat a,mat b,mat&c,int n,int m,int k)
{
    if (n==1||m==1||k==1){c=a*b;return;}
    mat a11,a12,a21,a22,b11,b12,b21,b22,m1,m2,m3,m4,m5,m6,m7;
    a11.assign(1,1,a,1,1,n>>1,k>>1,1);          a12.assign(1,1,a,1,(k>>1)+1,n>>1,k>>1,1);
    a21.assign(1,1,a,(n>>1)+1,1,n>>1,k>>1,1);   a22.assign(1,1,a,(n>>1)+1,(k>>1)+1,n>>1,k>>1,1);
    b11.assign(1,1,b,1,1,k>>1,m>>1,1);          b12.assign(1,1,b,1,(m>>1)+1,k>>1,m>>1,1);
    b21.assign(1,1,b,(k>>1)+1,1,k>>1,m>>1,1);   b22.assign(1,1,b,(k>>1)+1,(m>>1)+1,k>>1,m>>1,1);
    __strassen(a11+a22,b11+b22,m1,n>>1,m>>1,k>>1);
    __strassen(a21+a22,b11,m2,n>>1,m>>1,k>>1);
    __strassen(a11,b12-b22,m3,n>>1,m>>1,k>>1);
    __strassen(a22,b21-b11,m4,n>>1,m>>1,k>>1);
    __strassen(a11+a12,b22,m5,n>>1,m>>1,k>>1);
    __strassen(a21-a11,b11+b12,m6,n>>1,m>>1,k>>1);
    __strassen(a12-a22,b21+b22,m7,n>>1,m>>1,k>>1);
    c.n=n; c.m=m;
    c.assign(1,1,m1+m4-m5+m7,1,1,n>>1,m>>1);    c.assign(1,(m>>1)+1,m3+m5,1,1,n>>1,m>>1);
    c.assign((n>>1)+1,1,m2+m4,1,1,n>>1,m>>1);   c.assign((n>>1)+1,(m>>1)+1,m1-m2+m3+m6,1,1,n>>1,m>>1);
}
int __enlarge(int x){int t=1<<(31-__builtin_clz(x)); return t==x?x:(t<<1);}
mat operator^(mat&a,mat&b)
{
    if (a.m!=b.n) return mat(-1,-1);
    int n=__enlarge(a.n),m=__enlarge(b.m),k=__enlarge(a.m);
    mat c; __strassen(a,b,c,n,m,k);
    c.n=a.n; c.m=b.m;
    return c;
}
