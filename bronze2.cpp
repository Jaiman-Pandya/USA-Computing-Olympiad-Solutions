#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long onell=1;
ll n,k;
void solve(int ng,int g[],vector<int>&ans,int val)
{
    int ind=0;
    for(int ind=0;ind<ng;)
    {
        int cur=g[ind];
        int sel=min(cur+k,n-1);
        if(ans[sel]==0)
            ans[sel]=val;
        else
        {
            ans[sel-1]=val;
            break;
        }
        int cover=sel+k;
        ind=upper_bound(g,g+ng,cover)-g;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k;
        char s[n];
        for(int i=0;i<n;i++)
            cin>>s[i];
        int g[n],h[n];
        int ctrg=0,ctrh=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='H')
                continue;
            g[ctrg++]=i;
        }
        for(int i=ctrg;i<n;i++)
            g[i]=1000000000;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='G')
                continue;
            h[ctrh++]=i;
        }
        for(int i=ctrh;i<n;i++)
            h[i]=1000000000;
        vector<int>ans(n,0);
        solve(ctrg,g,ans,1);
        solve(ctrh,h,ans,2);
        int ctr=0;
        for(auto &el:ans)
        {
            if(el==0)
                continue;
            ctr++;
        }
        cout<<ctr<<endl;
        for(auto &el:ans)
        {
            if(el==0)
                cout<<".";
            else if(el==1)
                cout<<"G";
            else
                cout<<"H";
        }
        cout<<endl;
    }
}
