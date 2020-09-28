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


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, p, u, ini;
	while(cin >> n >> m && (n!=0 || m!=0)){
		UF amigos(n);
		for(int i=0; i<m; i++){
			cin >> p;
			for(int j=0; j<p; j++){
				cin >> u;
				if( j == 0){
					ini = u;
				}else{
					amigos.UnionSet(ini, u);
				}
			}
		}
		
		cout << amigos.numRed(0) << "\n";
		
	}
	return 0;
}
