#include<bits/stdc++.h>

using namespace std;
const int MaxN = 2 * 1e5;
vector<string> palabras(MaxN);
map<string, int> pb;

struct UF{
	vector<int> p;
	UF(){
		p.assign(MaxN, 0);
		for(int i=0; i<MaxN; i++) p[i] = i;
	}
	int FindSet(int i){
		return (p[i] == i) ? i : (p[i] = FindSet(p[i]));
	}
	bool isSameSet(int i, int j){
		return FindSet(i) == FindSet(j);
	}
	void UnionSet(int i, int j){
		if(!isSameSet(i, j)){
			int pi = FindSet(i);
			int pj = FindSet(j);
			string padre_i = palabras[pi];
			string padre_j = palabras[pj];
			if(padre_i.size() == padre_j.size()){
				if(padre_i < padre_j){
					p[pj] = pi;
				}else{
					p[pi] = pj;
				}
			}else{
				if(padre_i.size() < padre_j.size()){
					p[pj] = pi;
				}else{
					p[pi] = pj;
				}
			}
		}
	}

};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string a, b;
	cin >> n;
	int index = 0;
	queue<pair<string,string>> peticiones;
	for(int i=0; i<n; i++){
		cin >> a >> b;
		if(pb.find(a) == pb.end()){
			pb[a] = index++;
		}
		if(pb.find(b) == pb.end()){
			pb[b] = index++;
		}
		peticiones.push(make_pair(a, b));
	}
	for(auto x : pb){
		palabras[x.second] = x.first;
	}
	UF crypto = UF();
	while(!peticiones.empty()){
		pair<string,string> pe = peticiones.front();
		peticiones.pop();
		crypto.UnionSet(pb[pe.first], pb[pe.second]);	
	}

	string msg ;
	while(cin >> msg){
		if(pb.find(msg) == pb.end()){
			cout << msg << " ";
		}else{
			int ix = crypto.FindSet(pb[msg]);
			cout << palabras[ix] << " ";
		}
	}
	cout << "\n";
	return 0;
}
