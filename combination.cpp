
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool forward = true;
        int cur = 1;
        int cur_head = 1;
        vector<vector<int>> result;
        vector<int> temp;
        while(true){
            if(forward){
                if(cur <= n){
                    temp.push_back(cur);
                    cur++;
                    if(temp.size() == k){
                        result.push_back(temp);
                        forward = false;
                    }
                }
                else{
                    forward = false;
                }
            }
            else{
                if(cur <= n){
                    temp.erase(temp.end()-1);
                    forward = true;
                }
                else{
                    temp.erase(temp.end()-1);
                    if(temp.size() == 0)
                        break;
                    cur = temp[temp.size()-1]+1;
                    if(cur > n)
                        break;
                    else{
                        forward = true;
                    }
                    temp.erase(temp.end()-1);
                }
            }
        }
        return result;
    }
};
