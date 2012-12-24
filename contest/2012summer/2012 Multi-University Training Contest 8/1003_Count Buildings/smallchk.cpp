#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}
template<class T>void show(T a, int h, int r, int l){for(int i=0; i<h; ++i)show(a[i],r,l);cout<<endl;}
const long long mod = 1e9+7;
const int N = 101;
long long dp[N][N][N];
long long cansee[N][N];
long long C[N][N];
int main(){
	for(int i=1; i<=12; i++){
		vector<int>v;
		for(int j=1; j<=i; j++)
			v.push_back(j);
		do{
			vector<int> l(i),r(i);
			int ansl = 1, ansr = 1;
			l[0] = 1, r[v.size()-1] = 1;
			for(int j=1; j<v.size(); j++){
				l[j] = 0;
				for(int k=j-1; k>-1; k--)
					if(v[j] > v[k] && l[k]>0 && l[j]<l[k]+1) l[j] = l[k]+1;
					else if(v[j] < v[k]){ l[j] = 0; break; }
				if(l[j]>ansl) ansl = l[j];
			}
			for(int j=(int)v.size()-2; j>-1; j--){
				r[j] = 1;
				for(int k=j+1; k<v.size(); k++)
					if(v[j] > v[k] && r[k]>0 && r[j]<r[k]+1) r[j] = r[k]+1;
					else if(v[j] < v[k]){
						r[j] = 0; break;
					}
				if(r[j]>ansr) ansr = r[j];
			}
			dp[i][ansl][ansr]++;

		}
		while(next_permutation(v.begin(), v.end()));
	}
	show(dp,9,9,9);
	return 0;
}

