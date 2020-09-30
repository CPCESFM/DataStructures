#include<bits/stdc++.h>

#define MAXN 200005 

using namespace std;

int n;
string password;
bool carac[26];
struct UF{
	vector<int> p,rank;
	int numero;
	UF(int l){
		numero = l;
		p.assign(l,0);
		rank.assign(l,0);
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
			numero--;
			int pi = findSet(i);
			int pj = findSet(j);
			if(rank[pi] > rank[pj]){
				p[pj] = pi;
			}else{
				p[pi] = pj;
				if(rank[pi] == rank[pj]) rank[pj]++;
			}
		}	
	}
	int conectado(){
		return numero;
	}	

};
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	UF red(n + 26);
	int resta = 0;
	for(int i=0; i<n; i++){
		cin >> password;
		for(char c:password){
			if(!carac[c - 'a']){
				resta++;
				carac[c - 'a'] = true;
			}else{
			
			}
			if(!red.isSameSet(n + c -'a',i)){
				red.UnionSet(n + c -'a',i);
			}
		}
	}
	cout << red.conectado() -26 + resta <<"\n";
	return 0;
}
