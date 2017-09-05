int gfa(int x){return(fa[x]==x?x:fa[x]=gfa(fa[x]));}
