#include<bits/stdc++.h>

using namespace std;

struct UF{
	vector<int> p, rank, f;
	UF(int n){
		p.assign(n,0);
		rank.assign(n,0);
		f.assign(n,1);
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
			int pi = findSet(i);
			int pj = findSet(j);
			if(rank[pi] > rank[pj]){
				p[pj] = pi;
				f[pi] += f[pj];
			}else{
				if(rank[pi] == rank[pj]) rank[pj]++;
				p[pi] = pj;
				f[pj] += f[pi];
			}
		}
	}
	int numRed(int i){
		return f[findSet(i)];
	}
};

void solve(){
	int e;
	cin >> e;
	string a,b;
	map<string,int> friends;
	int num_ver = 0;
	int u,v;
	UF red(100002);
	for(int i=0; i<e; i++){
		cin >> a >> b;
		if(friends.find(a) == friends.end()){
			friends[a] = num_ver++;
			u = friends[a];
		}else{
			u = friends[a];
		}
		if(friends.find(b) == friends.end()){
			friends[b] = num_ver++;
			v = friends[b];
		}else{
			v = friends[b];
		}
		red.UnionSet(u,v);
		cout << red.numRed(u) << "\n";
	}
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
