#include<bits/stdc++.h>

using namespace std;

struct UF{
	vector<int> rank, p;
	UF(int n){
		rank.assign(n,0);
		p.assign(n,0);
		for(int i=0; i<n; i++) p[i] = i;
	}
	int findSet(int i){
		return p[i] == i ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void UnionSet(int i, int j){
		if(!isSameSet(i,j)){
			int px = findSet(i);
			int py = findSet(j);
			if(rank[px] > rank[py]){
				p[py] = px;
			}else{
				if(rank[px] == rank[py]) rank[py]++;
				p[px] = py;
			}
		}	
	}
};


void solve(){
	int N,m;
	cin >> N >> m;
	vector<int> a(N);
	UF perm(N);
	for(auto &it : a ) cin >> it;
	int u,v;
	for(int i=0; i<m; i++){
		cin >> u >> v;
		u--, v--;
		perm.UnionSet(u,v);
	}
	for(int i=0; i<N - 1; i++){
		for(int j= i + 1; j<N; j++){
			if(a[j] < a[i] && perm.isSameSet(i,j)){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for(auto x : a) cout << x << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
