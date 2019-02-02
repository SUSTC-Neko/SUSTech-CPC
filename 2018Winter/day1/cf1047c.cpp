#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1.5e7+5;
int a[maxn],num[maxn];
int main(){
    int n,i,j,h;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
        int g,m=0,ans=n;
        for(i=1;i<=n;i++){
            cin>>h;
            if(i==1) g=h;
            else g=__gcd(g,h);
            num[h]++;
            if(h>m) m=h;
        }
        for(i=g+1;i<=m;i++){
            if(a[i]==0){
                int cnt=0;
                for(j=i;j<=m;j+=i)
                a[j]=1,cnt+=num[j];
                ans=min(ans,n-cnt);
            }
        }
        if(ans==n) cout<<-1<<endl;
        else cout<<ans<<endl;
    return 0;
}