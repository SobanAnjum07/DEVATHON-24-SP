#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
typedef long long ll;
 
int n,k,m,ID[200005],Fa[200005],Siz[200005],p[10],ps[125][10],To[125][125];
ll Ans;
struct Edge{int x,y,z;};
std::vector<Edge> f,g;
 
int Get(const int x){return x==Fa[x]?x:Fa[x]=Get(Fa[x]);}
 
inline void Merge(int x,int y,int z)
{
    if((x=Get(x))==(y=(Get(y))))return;
    int s=Get(1);
    if(x==s)Ans+=(ll)Siz[y]*z;
    if(y==s)Ans+=(ll)Siz[x]*z;
    Fa[x]=y,Siz[y]+=Siz[x],g.push_back((Edge){x,y,z});
}
 
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;++i)p[i]=i;
    do
    {
        ++m;
        int x=0;
        for(int i=0;i<k;++i)x=x*k+p[i],ps[m][i]=p[i];
        ID[x]=m;
    }while(std::next_permutation(p,p+k));
    for(int i=1;i<=m;++i)
        for(int j=1;j<=m;++j)
        {
            int x=0;
            for(int l=0;l<k;++l)x=x*k+ps[i][ps[j][l]];
            To[i][j]=ID[x];
        }
    for(int i=1;i<=n;++i)
    {
        int x=0;
        for(int j=0;j<k;++j)scanf("%d",&p[j]),x=x*k+p[j]-1;
        for(int j=1;j<=m;++j)Fa[j]=j,Siz[j]=1;
        x=ID[x],Ans+=i,f=g,g.clear();
        for(int j=1;j<=m;++j)Merge(j,To[x][j],i);
        for(auto j:f)Merge(j.x,j.y,j.z);
    }
    std::cout<<Ans<<std::endl;
    return 0;
}
