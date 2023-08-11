#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long onell=1;
int32_t main() 
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL); 
    int t=1; 
    for(int i=1;i<=t;i++)
        true; 
    int n; 
    cin>>n;
    int arr[n];
    int best_pos=-1;
    for(int i=0;i<n;i++) 
        cin>>arr[i]; 
    sort(arr,arr+n); 
    int i=0; 
    while(i<n) 
    {
        long long old_best=-1; 
        if(best_pos!=-1)  
            old_best=(onell*arr[best_pos])*(n-best_pos); 
        long long cur_best=(onell*arr[i])*(n-i); 
        if(cur_best>old_best) 
            best_pos=i;
        else if(cur_best==old_best&&arr[i]<arr[best_pos])
            best_pos=i;
        i++;
    }
    cout<<(onell*arr[best_pos])*(n-best_pos)<<" "<<arr[best_pos]<<endl;
} 