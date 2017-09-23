/*
注意很多字符集，特别是"-'a'"
=BASIC
    fa--------------suffix link
    to--------------trans
    mxl-------------max length
    clone-----------cloned from/0
=OPTIONAL
    ac--------------accept state 是否为后缀态
    mnl-------------min length
    fep-------------first endpos 首次出现的末端
    tp--------------可供拓扑排序DP/树上DP的顺序
    sep-------------size of endpos 出现次数
    invfa-----------inverse of fa(suffix-link)
=PROBLEMS
    KthSub----------第k小子串,分不同位置是否算多个两种模式(BZOJ3998)
    AllOccur--------P[]在T中所有出现的位置
    LCS-------------最长公共子串
     *待补* LCS2------------多串最长公共子串
==其它
    判断P是否为T子串:T建直接跑P
    子串种数:sum{mxl[i]-mnl[i]+1}
    不同子串总长:sum{mnl[i]+..+mxl[i]}
    环串最小表示:S+S后,走最小后继一直走n次，必能走到
    P在T中首次出现位置:fep
    P在T中出现次数（可重叠）:sep
    最短非子串:DP,d[u]=1+min{d[v]},v含0
    最长重复不重叠子串:DP找出lastendpos,贪心地用fep,lep,mnl,mxl更新答案
==未想
    BZOJ3238 BZOJ2806 BZOJ2555 BZOJ3926 BZOJ3879
    BZOJ2780 BZOJ3756 BZOJ1396 HDU4622 SPOJ8222
    BZOJ4566
*/

struct sam
{
    int fa,to[chs],mxl,clone;
    int& operator[](int x){return to[x];}
    sam(int _fa=0,int _mxl=0,int _clone=0)
    {
        fa=_fa; mxl=_mxl; clone=_clone;
        memset(to,0,sizeof(to));
    }
} a[maxn<<1];
bool ac[maxn<<1];
int m,last,mnl[maxn<<1],fep[maxn<<1],sep[maxn<<1],tp[maxn<<1];
vector<int> invfa[maxn<<1];

void extend(int ch)
{
    int p=last,q,r;
    a[last=++m]=sam(p,a[p].mxl+1,0);
    for(;p&&!a[p][ch];p=a[p].fa) a[p][ch]=m;
    if (!p) {a[m].fa=1; return;}
    if (a[q=a[p][ch]].mxl==a[p].mxl+1) {a[m].fa=q; return;}
    a[r=++m]=a[q];
    a[r].clone=q;
    a[r].mxl=a[p].mxl+1;
    a[q].fa=a[last].fa=r;
    for(;p&&a[p][ch]==q;p=a[p].fa) a[p][ch]=r;
}
void getac()
{
    memset(ac,0,sizeof(ac));
    for(int x=last;x;x=a[x].fa) ac[x]=1;
}
void getmnl()
{
    int i;
    tr(i,2,m) mnl[i]=a[a[i].fa].mxl+1;
}
void getfep()
{
    int i;
    tr(i,2,m) fep[i]=a[i].clone?fep[a[i].clone]:a[i].mxl;
}
void gettp()
{
    static int ls[maxn];
    int i,mx=0;
    memset(ls,0,sizeof(ls));
    tr(i,1,m) {mx=max(mx,a[i].mxl); ls[a[i].mxl]++;}
    rtr(i,mx-1,0) ls[i]+=ls[i+1];
    tr(i,1,m) tp[ls[a[i].mxl]--]=i;
}
void getsep()
{
    gettp();
    int i;
    tr(i,1,m) sep[i]=a[i].clone?0:1;
    tr(i,1,m-1) sep[a[tp[i]].fa]+=sep[tp[i]];
}
void getinvfa()
{
    int i;
    tr(i,2,m) invfa[i].clear();
    tr(i,2,m) invfa[a[i].fa].push_back(i);
}
//=======================================================
void KthSub(char *s,int k,bool diffpos)  //diffpos为1算多个
{
    static int ll d[maxn<<1];
    int n=strlen(s+1),i,j,x;
    a[m=last=1]=sam();
    tr(i,1,n) extend(s[i]-'a');
    if (diffpos) getsep();
    else gettp();
    tr(i,1,m)
    {
        x=tp[i];
        if (x!=1)
        {
            if (diffpos) d[x]=sep[x]; else d[x]=1;
        }
        tr(j,0,25) if (a[x][j]) d[x]+=d[a[x][j]];
    }
    x=1;
    if (d[1]<k) {puts("-1"); return;}
    for(;;)
    {
        ll t;
        if (x!=1)
        {
            if (diffpos) t=sep[x]; else t=1;
        } else t=0;
        if (t>=k) break;
        tr(j,0,25) if (a[x][j])
        {
            t+=d[a[x][j]];
            if (t>=k) break;
        }
        putchar('a'+j);
        t-=d[x=a[x][j]];
        k-=t;
    }
    puts("");
}
void OutputAllOccur(int x,int np)
{
    if (!a[x].clone) printf("%d ",fep[x]-np+1);
    int i,l=int(invfa[x].size())-1;
    tr(i,0,l) OutputAllOccur(invfa[x][i],np);
}
void AllOccur(char *T,int q)    //待测
{
    static char P[maxn];
    int n=strlen(T+1),np,i,j,x;
    a[m=last=1]=sam();
    tr(i,1,n) extend(T[i]-'a');
    getfep();
    getinvfa();
    tr(i,1,q)
    {
        gets(P+1);
        np=strlen(P+1);
        for(x=1,j=1;j<=np&&a[x][P[j]-'a'];j++) x=a[x][P[j]-'a'];
        if (j>np) OutputAllOccur(x,np);
        puts("");
    }
}
void LCS(char *s1,char *s2)
{
    int n1=strlen(s1+1),n2=strlen(s2+1),i,x,l,bestl,besti;
    a[m=last=1]=sam();
    tr(i,1,n1) extend(s1[i]-'a');
    x=1; l=bestl=besti=0;
    tr(i,1,n2)
    {
        while(x&&a[x][s2[i]-'a']==0) l=a[x=a[x].fa].mxl;
        if (x)
        {
            x=a[x][s2[i]-'a']; l++;
        } else x=1;
        if (l>bestl)
        {
            bestl=l; besti=i;
        }
    }
    tr(i,besti-bestl+1,besti) putchar(s2[i]);
    puts("");
}

int main()
{
    //gets(s+1); n=strlen(s+1);
    //a[m=last=1]=sam();
    //tr(i,1,n) extend(s[i]-'a');

    return 0;
}
