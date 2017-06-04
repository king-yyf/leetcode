#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PAIR;
//int fa[100002];
struct mfSet{
    int fa[8];
    int find(int x){
        if(fa[x] == -1) return x;
        return fa[x] = find(fa[x]);
    }
    mfSet(){}
    void init(){
        memset(fa, -1,sizeof(fa));
    }
};
int main(){
    int n,m;
  //  int fa[8];
    scanf("%d%d",&n,&m);
    priority_queue<PAIR, vector<PAIR>, greater<PAIR> > que;
    while(m--){
        int from, to, cost;
        scanf("%d%d%d",&from, &to, &cost);
        que.push(PAIR(cost, P(from,to)));
    }
    int ans = 0;
    mfSet a;
    a.init();
    while(a.find(1) != a.find(n)){
        PAIR pa = que.top();
        ans = pa.first;
        que.pop();
        P p = pa.second;
        a.fa[a.find(p.second)] = a.find(p.first);
    }
    printf("%d\n",ans);
    return 0;
}