#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		long long int n,m,k,l,p,Lnew,ans=9999999999,time=0,fr=9999999999,mx=-1,ldash,left,zero=0; cin>>n>>m>>k>>l;
		long long int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			mx=max(mx,a[i]);
		}
		sort(a,a+n);
	     map<long long int,long long int>mp;
	     mp[0]=(m+1)*l-1; p=0;
	     ans=mp[0];
	     for(int i=0;i<n;i++){
			 if(i==0){
			 	mp[a[i]]=mp[0]-a[i]+1;
			 }
			 else{
			 	mp[a[i]]= mp[a[i-1]]-(a[i]-a[i-1])+l;
			 }
		 }
		 mp[a[n-1]+1]=mp[a[n-1]]+l-1;
		 time=k-a[n-1]-1;
		 
		 mp[k]=max(zero,mp[a[n-1]+1]-time);
		// cout<<mp[k];
		 map<long long int,long long int>:: iterator it;
	/*	 for(it=mp.begin();it!=mp.end();it++){
		 	cout<<it->first<<" "<<it->second<<"\n";
		 } */
		 
		 for(it=mp.begin();it!=mp.end();it++){
		 	ans=min(ans,it->second);
		 }  
		 cout<<ans<<"\n";
	}
}  
