#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
using namespace std;
int main(){
	int t;cin>>t;
    while(t--){
        int n,m,sumA=0,sumB=0;cin>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;i++){
            cin>>a[i];  sumA+=a[i];
        }
        sort(a,a+n);
        for(int j=0;j<m;j++){
            cin>>b[j];
            sumB+=b[j];
        }
        sort(b,b+m);
        int error=1,I=0,J=0;
        while(I<n && a[I]==0) I++;
        while(J<m && b[J]==0) J++;
        if(sumA==sumB){
            error=0;
            for(;I<n&&J<m;J++,I++){
                if(a[I]!=b[J]){
                    error=1; break;
                }
            }
        }
        if(I==n && J==m &&error==0)  cout<<"Bob\n";
        else cout<<"Alice\n";
    }
}  
