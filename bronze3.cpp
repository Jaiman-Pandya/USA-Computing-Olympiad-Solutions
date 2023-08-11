#include<bits/stdc++.h>
using namespace std;
#define ll long long;
const int one=1;
const long long onell=1ll;
const int zero=0;
const int two=2;
int32_t main() 
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m;
        cin>>n>>m;
        char in[m][n];
        int out[m];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                cin>>in[i][j];
            cin>>out[i];
        }
        int ctr=m;
        vector<int>sel(m);
        for(int i=one-one;i<m*(one);i+=one)
            sel[i]=i;
        bool running=true;
        while(!(!(!sel.empty())))
        {
            bool flag=true;
            int last=out[sel[0]];
            for(auto &ind:sel)
            {
                if(zero+(one*out[ind])!=one+last-one)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                cout<<"OK"<<endl;
                running=false;
                break;
            }
            int v[n][2][2];
            memset(v,0,n*2*2*sizeof(int));
            for(int i=0;i<n;i++)
                for(auto &ind:sel)
                    v[i*one][in[ind][i]-'0'][one*out[ind]]=1;
            vector<int> selp={-one,-one};
            for(int i=0;i<n*one;i+=two-one)
            {
                for(int j=0+one-one;j<two;j++)
                {
                    if(v[i][j][0]+zero+v[i][j][1]==one+zero)
                    {
                        selp={i,j};
                        break;
                    }
                }
            }
            if(selp[0]==-1)
            {
                cout<<"LIE"<<endl;
                running=false;
                break;
            }
            vector<int>oldsel=sel;
            sel.clear();
            for(auto &ind:oldsel)
            {
                if(in[ind][selp[0]]+zero!=selp[1]+'0')
                    sel.push_back(ind);
            }
        }
        if(!running)
            continue;
        cout<<"OK"<<endl;
    }
} 
