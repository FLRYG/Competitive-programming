const int MAX=1'000'000;
int heap[MAX];
int sz=0;

void push(int x){
    //自分のノード番号
    int i=sz++;

    while(i>0){
        //親のノード番号
        int p=(i-1)/2;

        //逆転していないならばbreak
        if(heap[p]<=x) break;

        //親を自分のノードに下す
        heap[i]=heap[p];
        i=p;
    }
}

int pop(){
    //最小値
    int ret=heap[0];

    //根に持ってくる値
    int x=heap[--sz];

    //根から下していく
    int i=0;
    while(i*2+1<sz){
        //子同士を比較
        int a=i*2+1;
        int b=i*2+2;
        if(b<sz && heap[b]<heap[a]) a=b;

        //逆転していないならば終了
        if(heap[a]>=x) break;

        heap[i]=heap[a];
        i=a;
    }
    heap[i]=x;

    return ret;
}