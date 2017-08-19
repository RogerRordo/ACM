struct node
{
    int x,ch[2],fa,size,cnt;
    int& operator[](int t){return ch[t];}
} a[maxm];
int m,root,err;

void newnode(int x)
{
    a[++m].x=x;
    a[m][0]=a[m][1]=a[m].fa=0;
    a[m].size=a[m].cnt=1;
}
void addnode(int t,int x=1){a[t].size+=x;a[t].cnt+=x;}
void dl(int t){if(!t)return;}    //download
void ul(int t){if(!t)return;a[t].size=a[a[t][0]].size+a[a[t][1]].size+a[t].cnt;}    //upload
void dlk(int p,int q,int&rt){dl(p);if(q)a[p][a[q].x>a[p].x]=a[q].fa=0;}  //del link p->q
void blk(int p,int q,int&rt){if(q)a[(p?a[p][a[q].x>a[p].x]:rt)=q].fa=p;ul(p);}  //build link p->q
//注意从上至下dlk，从下至上blk
void rot(int t,int&rt)     //单旋
{
    int p=a[t].fa,q=a[p].fa,r=a[t][a[p][0]==t];
    dlk(q,p,rt); dlk(p,t,rt); dlk(t,r,rt);
    blk(p,r,rt); blk(t,p,rt); blk(q,t,rt);
}
void splay(int t,int&rt)
{
    for(int p;t!=rt;rot(t,rt))
        if ((p=a[t].fa)!=rt) rot(t==a[p][0]^p==a[a[p].fa][0]?t:p,rt);      //双旋
}
void find(int x,int&rt,int type=0)    //-1:pre(<=)    0:normal(pre/suc)    1:suc(>=)
{
    int s=0,t=rt;
    for(;t;t=(a[t].x!=x)?a[t][x>a[t].x]:0)
        if (type*(a[t].x-x)>=0) s=t;
    if (!s) {err=1; return;}
    splay(s,rt);
}
void kth(int k,int&rt)
{
    if (k<1||k>a[rt].size) {err=1; return;}
    int t=rt;
    for(k-=a[a[rt][0]].size;k<1||k>a[t].cnt;k-=(k>0?a[t].cnt:-a[a[t][0]].size)+a[a[t=a[t][k>0]][0]].size);
    splay(t,rt);
}
void ins(int x,int&rt)
{
    find(x,rt);
    if (a[rt].x==x) return addnode(rt);
    int p=a[rt][x>a[rt].x];
    dlk(rt,p,rt);
    newnode(x); blk(m,p,rt); blk(rt,m,rt);
}
void del(int x,int&rt,int all=0)
{
    find(x,rt);
    if (a[rt].x!=x) {err=1; return;}
    if (!all&&a[rt].cnt>1) return addnode(rt,-1);
    if (!a[rt][0]) return blk(0,a[rt][1],rt);
    find(a[rt].x,a[rt][0]);
    int p=a[rt][0],q=a[rt][1];
    dlk(rt,p,rt); dlk(rt,q,rt);
    blk(p,q,rt); blk(0,p,rt);
}
void work()
{
    newnode(oo); root=1;
    //...
}
