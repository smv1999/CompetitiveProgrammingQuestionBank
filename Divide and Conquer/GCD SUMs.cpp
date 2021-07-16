#include<bits/stdc++.h>
using namespace std;
 
const int nmax=2e5+42,MX=8.7e6+nmax,mod=1e9+7;//8668604 derived empirically
 
int n;
int inp[nmax];
 
int mem_gcd[20][nmax],pointer_left[20][nmax],pointer_right[20][nmax];
 
int mem_sum[20][nmax];
 
pair<int/*gcd*/,int/*count*/> active[nmax],help[nmax];
int pointer_active,pointer_help;
 
int mem[MX],pointer_mem=0;
int start[20][nmax];
int mem_RHS_size[20][nmax];
 
pair<int,int> LHS[nmax],RHS[nmax];
int pointer_LHS=0,pointer_RHS=0;
 
int inv[nmax];
 
int push(int cur)
{
    pointer_active++;
    active[pointer_active]={cur,1};
 
    for(int i=1;i<=pointer_active;i++)
        active[i].first=__gcd(active[i].first,cur);
 
    pointer_help=1;
 
    help[pointer_help]=active[1];
 
    for(int i=2;i<=pointer_active;i++)
        if(active[i].first==help[pointer_help].first)help[pointer_help].second=help[pointer_help].second+active[i].second;
        else
        {
            pointer_help++;
            help[pointer_help]=active[i];
        }
 
    pointer_active=pointer_help;
    for(int i=1;i<=pointer_active;i++)
        active[i]=help[i];
 
    long long ret=0;
    for(int i=1;i<=pointer_active;i++)
        ret=(ret+1LL*active[i].first*active[i].second);
 
    return ret%mod;
}
 
int ask(int id,int l,int size_LHS,int size_RHS)
{
    if(size_LHS==0||size_RHS==0)return 0;
 
    return mem[size_RHS+(size_LHS-1)*mem_RHS_size[id][l]+start[id][l]];
}
 
int mem_pointer[20][nmax];
int cnt_now[20][nmax];
int cnt_original[20][nmax];
 
int MASK[nmax];
 
int mem_border[20][nmax];
 
void build(int id,int l,int r)
{
    if(l>=r)return;
 
    int av=(l+r)/2;
 
    for(int i=av+1;i<=r;i++)
        MASK[i]+=(1<<id);
 
    for(int i=l;i<=av;i++)
        mem_border[id][i]=l;
 
    for(int i=av+1;i<=r;i++)
        mem_border[id][i]=r;
 
    build(id+1,l,av);
    build(id+1,av+1,r);
 
    /*build left*/
    int g=0;
    for(int i=av;i>=l;i--)
    {
        g=__gcd(g,inp[i]);
        mem_gcd[id][i]=g;
    }
 
    pointer_left[id][l]=l;
 
    for(int i=l+1;i<=av;i++)
        if(mem_gcd[id][i-1]==mem_gcd[id][i])pointer_left[id][i]=pointer_left[id][i-1];
        else pointer_left[id][i]=i;
 
    /*build right*/
    g=0;
    for(int i=av+1;i<=r;i++)
    {
        g=__gcd(g,inp[i]);
        mem_gcd[id][i]=g;
    }
 
    pointer_right[id][r]=r;
 
    for(int i=r-1;i>=av+1;i--)
        if(mem_gcd[id][i+1]==mem_gcd[id][i])pointer_right[id][i]=pointer_right[id][i+1];
        else pointer_right[id][i]=i;
 
    /*build the sums*/
    long long sum=0;
    pointer_active=0;
 
    for(int i=av;i>=l;i--)
    {
        sum=(sum+push(inp[i]));
        if(sum>=mod)sum=sum-mod;
 
        mem_sum[id][i]=sum;
    }
 
    sum=0;
    pointer_active=0;
 
    for(int i=av+1;i<=r;i++)
    {
        sum=(sum+push(inp[i]));
        if(sum>=mod)sum=sum-mod;
 
        mem_sum[id][i]=sum;
    }
 
 
    /*precompute*/
    int lq=l,rq=r;
 
    pointer_LHS=0;
 
    int cur=av;
 
    while(pointer_left[id][cur]>lq)
    {
        pointer_LHS++;
 
        LHS[pointer_LHS]={mem_gcd[id][cur],cur+1-pointer_left[id][cur]};
 
        cur=pointer_left[id][cur]-1;
    }
 
    pointer_LHS++;
    LHS[pointer_LHS]={mem_gcd[id][cur],cur+1-lq};
 
    int where_now=av;
    for(int pointer=1;pointer<=pointer_LHS;pointer++)
    {
        for(int j=1;j<=LHS[pointer].second;j++)
        {
            mem_pointer[id][where_now]=pointer;
            cnt_now[id][where_now]=j;
            cnt_original[id][where_now]=LHS[pointer].second;
 
            where_now--;
        }
    }
 
    /*get right gcd*/
    pointer_RHS=0;
 
    cur=av+1;
 
    while(pointer_right[id][cur]<rq)
    {
        pointer_RHS++;
 
        RHS[pointer_RHS]={mem_gcd[id][cur],pointer_right[id][cur]+1-cur};
 
        cur=pointer_right[id][cur]+1;
    }
 
    pointer_RHS++;
    RHS[pointer_RHS]={mem_gcd[id][cur],rq+1-cur};
 
    where_now=av+1;
    for(int pointer=1;pointer<=pointer_RHS;pointer++)
    {
        for(int j=1;j<=RHS[pointer].second;j++)
        {
            mem_pointer[id][where_now]=pointer;
            cnt_now[id][where_now]=j;
            cnt_original[id][where_now]=RHS[pointer].second;
 
            where_now++;
        }
    }
 
    /*precompute merge left(LHS) and right(RHS)*/
    start[id][l]=pointer_mem;
    mem_RHS_size[id][l]=pointer_RHS;
 
    /*
    cout<<"id= "<<id<<" l= "<<l<<" r= "<<r<<endl;
    cout<<"LHS: ";for(int i=1;i<=pointer_LHS;i++)cout<<LHS[i].first<<" "<<LHS[i].second<<"\t";cout<<endl;
    cout<<"RHS: ";for(int i=1;i<=pointer_RHS;i++)cout<<RHS[i].first<<" "<<RHS[i].second<<"\t";cout<<endl;
    cout<<"mem: ";
    */
 
    for(int i=1;i<=pointer_LHS;i++)
    {
        int g=LHS[i].first;
 
        for(int j=1;j<=pointer_RHS;j++)
        {
            g=__gcd(g,RHS[j].first);
 
            pointer_mem++;
 
            //cout<<i<<" "<<j<<" -> "<<pointer_mem<<" : "<<mem[pointer_mem]<<endl;
 
            mem[pointer_mem]=(1LL*g*LHS[i].second*RHS[j].second+ask(id,l,i-1,j)+ask(id,l,i,j-1)-ask(id,l,i-1,j-1)+mod)%mod;
 
            //cout<<"final: "<<mem[pointer_mem]<<endl;
        }
    }
 
}
 
void init(vector<int> a)
{
    n=a.size();
 
    for(int i=1;i<=n;i++)
        inp[i]=a[i-1];
 
    build(0,1,n);
}
 
int was_left_original,was_right_original;
 
int left_now,right_now;
 
int solve(int id,int l,int r,int lq,int rq)
{
    //cout<<"solve "<<id<<" "<<l<<" "<<r<<" "<<lq<<" "<<rq<<endl;
 
    //return -1;
 
    //merge
 
    /*get left gcd*/
    pointer_LHS=mem_pointer[id][lq];
 
    left_now=cnt_now[id][lq];
 
    was_left_original=cnt_original[id][lq];
 
    //return -1;
 
    /*get right gcd*/
    pointer_RHS=mem_pointer[id][rq];
 
    right_now=cnt_now[id][rq];
 
    was_right_original=cnt_original[id][rq];
 
    //return -1;
 
    int with_l_r=ask(id,l,pointer_LHS,pointer_RHS);
    int with_l=ask(id,l,pointer_LHS,pointer_RHS-1);
    int with_r=ask(id,l,pointer_LHS-1,pointer_RHS);
    int with=ask(id,l,pointer_LHS-1,pointer_RHS-1);
 
    //return -1;
 
    /*merge left(LHS) and right(RHS)*/
 
    long long ret=with;
 
    //return -1;
 
    ret+=(with_l_r-with_l-with_r+with+2LL*mod)*inv[was_left_original]%mod*inv[was_right_original]%mod*left_now%mod*right_now%mod;
 
    ret+=1LL*(with_l-with+mod)*inv[was_left_original]%mod*left_now%mod;
 
    //pointer_LHS--;
 
    //ret+=(ask(id,l,pointer_LHS,pointer_RHS)-ask(id,l,pointer_LHS,pointer_RHS-1))/was_right_original*RHS[pointer_RHS].second;
    ret+=1LL*(with_r-with+mod)*inv[was_right_original]%mod*right_now%mod;
 
    //ret+=(with_l-with)/was_right_original*RHS[pointer_RHS].second;
 
    //cout<<"ret -> "<<ret<<endl;
 
    ret=ret%mod;
 
    return ret;
}
long long query(int lq,int rq)
{
    if(lq==rq)return inp[lq];
 
    //return -1;
 
    //return solve(0,1,n,lq,rq);
 
    int id = __builtin_ctz(MASK[lq]^MASK[rq]);
 
    return (1LL*mem_sum[id][lq]+mem_sum[id][rq]+solve(id,mem_border[id][lq],mem_border[id][rq],lq,rq))%mod;
}
 
int main()
{
    inv[1]=1;
    for(int i=2;i<nmax;i++)
        inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
 
    int n;
    scanf("%i",&n);
 
    int q;
    scanf("%i",&q);
 
    vector<int> a(n,0);
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
 
    init(a);
 
    int ans=0;
 
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%i%i",&l,&r);
 
        l=(l+ans)%n+1;
        r=(r+ans)%n+1;
 
        ans=query(l,r);
 
        printf("%i\n",ans);
    }
 
    return 0;
}

// Time complexity: O(N∗log(N)∗logphi(C)+q)
