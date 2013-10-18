

class Solution {
	public:
		vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			unordered_set<string> visited;
			unordered_set<string> level_visit;
			map<string, vector<string>> parent;
			vector<vector<string>> result;
			queue<string> q;
			bool block = false;
			if(start == end){
				vector<string> temp;
				temp.push_back(start);
				temp.push_back(end);
				result.push_back(temp);
				return result;
			}
			int steps = 2;
			visited.insert(start);
			q.push(start);
			q.push(string("\n"));
			while(!q.empty()){
				string a = q.front();
				q.pop();

				if(a == "\n"){
					if(q.empty())
						break;
					q.push(string("\n"));
					steps++;
					for(string s:level_visit){
					    visited.insert(s);
					}
					level_visit.clear();
					continue;
				}

				if(one_step_change(a, end)){
					block = true;
					vector<string> temp;
					temp.push_back(end);
					temp.push_back(a);
					result.push_back(temp);
				}
				string b;
				if(!block){
					for(int i = 0 ; i < 26; i++){
						for(int j = 0 ; j < a.length(); j ++){
							b = a;
							b[j] = 'a' + i;
							if(b == a) continue;
							if(dict.count(b) && !visited.count(b)){
								if(!parent.count(b)){
									vector<string> v;
									v.push_back(a);
									parent[b] = v;
								}
								else{
									vector<string> v = parent[b];
									v.push_back(a);
									parent[b] = v;
								}
								level_visit.insert(b);
								q.push(b);
							}
						}
					}
				}
			}
			for(int i = 0 ; i < result.size(); i ++){
				vector<string> v = result[i];
				string s = v[v.size()-1];
				while(s != start){
					for(int j = 0 ; j < parent[s].size(); j++){
						if(j == parent[s].size()-1){
							vector<string> v = result[i];
							v.push_back(parent[s][j]);
							result[i] = v;
							s = v[v.size()-1];
						}
						else{
							vector<string> v = result[i];
							v.push_back(parent[s][j]);
							result.push_back(v);
						}
					}
				}
			}
			for(int i = 0 ; i < result.size() ; i++){
			    vector<string> v = result[i];
			    int n = v.size();
			    string temps;
			    for(int j = 0 ; j < n - 1 -j; j++){
			        temps = v[j];
			        v[j] = v[n-1-j];
			        v[n-1-j] = temps;
			    }
			    result[i] = v;
			}
			return result;

		}

		bool one_step_change(string a, string b){
			bool change = false;
			for(int i = 0 ; i < a.length() ; i++){
				if(a[i] != b[i] && change)
					return false;
				if(a[i] != b[i] && !change)
					change = true;
			}
			return change;
		}
};
