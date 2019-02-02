#include<bits/stdc++.h>
using namespace std;

int f[181];

int main() {
	
	for(int i=3;i<=360;i++) {
		for(int j=1;j<i-1;j++) {
			if((180*j)%i!=0) continue;
			if(!f[180*j/i]) f[180*j/i]=i;
		}
	}
	
	int T;
	scanf("%d",&T);
	while(T--) {
		int x;
		scanf("%d",&x);
		printf("%d\n",f[x]);
	}
	
	return 0;
}
