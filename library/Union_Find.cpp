class Union_Find{
private:
    int* par;                       //親
    int* rank;                      //木の深さ
public:
    Union_Find(int n);
    ~Union_Find();
    int find(int x);                //木の根を求める
    void unite(int x,int y);        //xとyの属する集合を併合
    bool same(int x,int y);         //xとyが同じ集合に属するか否か
};

Union_Find::Union_Find(int n){
    par=new int[n];
    rank=new int[n];
    for(int i=0;i<n;i++){
        par[i]=i;
        rank[i]=0;
    }
}

Union_Find::~Union_Find(){
    delete[] par;
    delete[] rank;
}

int Union_Find::find(int x){
    if(par[x]==x) return x;
    return par[x]=this->find[par[x]];
}

void Union_Find::unite(int x,int y){
    x=find(x);
    y=find(y);
    
    if(x==y) return;

    if(rank[x]<rank[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
}

bool Union_Find::same(int x,int y){
    return find(x)==find(y);
}