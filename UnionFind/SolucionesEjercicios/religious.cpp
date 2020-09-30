#include<bits/stdc++.h>

using namespace std;


struct UF{
	vector<int> rank,p;
	int religiones;
	UF(int l){
		religiones = l;
		rank.assign(l,0);
		p.assign(l,0);
		for(int i=0; i<l; i++) p[i] = i;
	}
	int findSet(int i){
		return p[i] == i ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void UnionSet(int i, int j){
		if(!isSameSet(i,j)){
			religiones--;
			int x = findSet(i);
			int y = findSet(j);
			if(rank[x] > rank[y]){
				p[y] = x;
			}else{
				if(rank[x] == rank[y]) rank[y]++;
				p[x] = y;
			}
		}
	}
	int Religiones(){
		return religiones;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,u,v;
	int casos = 0;
	while(cin >> n >> m && !(n==0&& m==0)){
		UF diferentes(n);
		for(int i=0; i<m; i++){
			cin >> u >> v;
			u--, v--;
			diferentes.UnionSet(u,v);
		}
		printf("Case %d: %d\n",++casos, diferentes.Religiones());
	}

	return 0;
}
