
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         unordered_set<string> visited;
         queue<string> q;
         if(start == end)
            return 1;
        int steps = 2;
        visited.insert(start);
        q.push(start);
        q.push(string("\n"));
        std::unordered_set<string>::iterator it;
        while(!q.empty()){
            string a = q.front();
            q.pop();
            
            if(a == "\n"){
                if(q.empty())
                    return 0;
                q.push(string("\n"));
                steps++;
                continue;
            }
            
            if(one_step_change(a, end))
                return steps;
           string b;
           for(int i = 0 ; i < 26; i++){
               for(int j = 0 ; j < a.length(); j ++){
                   b = a;
                   b[j] = 'a' + i;
                   if(b == a) continue;
                   if(dict.count(b) && !visited.count(b)){
                        visited.insert(b);
                        q.push(b);
                   }
               }
           }
        }
        return 0;
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
