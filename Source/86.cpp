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
using namespace std;
struct node
{
    node* ch[2];
    int x,y,size;
    int chsize(int d){return ch[d]?ch[d]->size:0;}
} ;
node *root;
int n,m;
int read()
{
    int x=0; bool f=0;
    char ch=getchar();
    while (ch<'0'||ch>'9') {f|=ch=='-'; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0'; ch=getchar();}
    return (x^-f)+f;
}
void write(int x)
{
    char a[20],s=0;
    if (x==0){putchar('0'); return ;}
    if (x<0) {putchar('-'); x=-x;}
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeb(int x){write(x); putchar(' ');}
void newnode(node *&t,int x)
{
    t=new node;
    t->ch[0]=t->ch[1]=0;
    t->x=x; t->y=rand(); t->size=1;
}
void rot(node *&t,int d)
{
    node *tt=t->ch[!d];
    t->ch[!d]=tt->ch[d];
    tt->ch[d]=t;
    tt->size=t->size;
    t->size=t->chsize(0)+t->chsize(1)+1;
    t=tt;
}
void ins(node *&t,int x)
{
    if (!t) newnode(t,x);
    else {
        int d=t->x<x;
        ins(t->ch[d],x);
        ++t->size;
        if (t->ch[d]->y<t->y) rot(t,!d);
    }
}
void del(node *&t,int x)
{
    if (x==t->x)
    {
        if (!t->ch[0]||!t->ch[1])
        {
            node *tt=t; t=t->ch[t->ch[0]==0]; delete(tt);
            return;
        }
        else
        {
            int d=t->ch[0]->y<t->ch[1]->y;
            rot(t,d); del(t->ch[d],x);
        }
    } else del(t->ch[t->x<x],x);
    --t->size;
}
node* kth(node *&t,int k)
{
    if (k<=t->chsize(0)) return kth(t->ch[0],k);
    else if(k>t->chsize(0)+1) return kth(t->ch[1],k-(t->chsize(0)+1));
    else return t;
}
void work()
{
    int i,t=1,tt;
    newnode(root,oo);
    tr(i,1,n) ins(root,i);
    tr(i,1,n)
    {
        t=(t+m-2)%(root->size-1)+1;
        writeb(tt=kth(root,t)->x);
        del(root,tt);
    }
    printf("\n");
}
int main()
{
    srand(time(0));
    n=read(); m=read();
    work();
    return 0;
}