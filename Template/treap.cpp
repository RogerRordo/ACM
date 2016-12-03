struct node
{
    node* ch[2];
    int x,y,size;
    int chsize(int d){return ch[d]?ch[d]->size:0;}
} ;
node *root;
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
        int d=t->x<x; ins(t->ch[d],x); ++t->size;
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
        } else
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
    srand(time(0)); newnode(root,oo);
    //...
}
