#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace std;
const int N=4e5+5,inf=2e9+1e8;
int n,m,s,t,u,v,ans=inf,tot,s1,s2,dfn[N],low[N],flow[N],vis[N],w[N];
vector<pair<int,int> >a[N];
template<typename T>inline void readmain(T &n){T sum=0,x=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-')x=-1;ch=getchar();}while (ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}n=sum*x;}
template<typename T>inline T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>inline void read(T &x,Tr&... r){readmain(x);read(r...);}
template<typename T>inline void write(T x){if (x<0){putchar('-');x=-x;}if (x>9)write(x/10);putchar(x%10+'0');return;}
template<typename T>inline void writesc(T x){write(x);putchar(' ');}
template<typename T>inline void writeln(T x){write(x);putchar('\n');}
inline void tarjan(int u,int fa,int k)
{
dfn[u]=low[u]=++tot;
for (auto [v,id]:a[u])
{
if (id==fa||vis[id])continue;
if (dfn[v])low[u]=min(low[u],dfn[v]);else
{
tarjan(v,id,k);low[u]=min(low[u],low[v]);
if (low[v]>dfn[u]&&dfn[t]&&dfn[t]>=dfn[v]&&w[k]+w[id]<ans)
ans=w[k]+w[id],s1=k,s2=id;
}
}
}
inline bool dfs(int u)
{
flow[u]=1;bool f=(u==t);
for (auto [v,id]:a[u])
{
if (flow[v]||!dfs(v))continue;
f=1;vis[id]=1;F(i,1,n)dfn[i]=0;tot=0;
tarjan(s,0,id);if (!dfn[t]&&w[id]<ans)ans=w[id],s1=id,s2=0;
vis[id]=0;
}
return f;
}
int main()
{
read(n,m,s,t);F(i,1,m)
{
read(u,v,w[i]);
a[u].push_back({v,i});
a[v].push_back({u,i});
}
if (!dfs(s))return !printf("0\n0");
if (ans==inf)return 0*puts("-1");
writeln(ans);writeln(1+(s2>0));
writesc(s1);if (s2)writeln(s2);
return 0;
}
