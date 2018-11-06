#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<vector>
#include<string>
#include<map>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		long long int n,k,m=1000000007,start=-1,check,not_equal=0,ans=0,p=0,rem,val,end; cin>>n>>k;
		if(k*(k+1)/2>n) cout<<"-1\n";
		else{
			if(n%k==0&&k%2!=0) {start=(n/k)-(k/2); end=(n/k)+(k/2);  }
			else if(n%k==0&&k%2==0) {start=(n/k)-(k/2); not_equal=(n/k); end=(n/k)+(k/2); 	}
			else if(k%2==0){
				rem=n%k; val=n/k;
				if(rem==k/2) { start=(n/k)-(k/2-1); end=(n/k)+(k/2) ; }
				else if(rem>k/2){rem-=k/2; 	start=(n/k)-(k/2-1) ; end=(n/k)+(k/2)+1 ;not_equal=end-rem ; }
				else{start=(n/k)-(k/2); end=(n/k)+(k/2); not_equal=(n/k)-rem;	}
				//cout<<"s";
			}
			else{
				rem=n%k; val=n/k;
				start=(n/k)-(k/2); end=(n/k)+(k/2)+1; not_equal=end-rem;// cout<<"r";
			}
			ans=((start%m)*(start%m)-(start%m))%m;
		//	cout<<start<<" "<<end<<" "<<not_equal;
			for(long long int i=start+1;i<=end;i++){
				if(i!=not_equal){
				p=((i%m)*(i%m)-(i%m))%m;
				ans=((ans%m)*(p%m))%m;
			}
			} 
			cout<<ans<<"\n";
		}
	}
}
