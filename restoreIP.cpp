
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return getIp(s, 0, 4);
    }
    
    vector<string> getIp(string s, int begin, int field){
        int x;
        vector<string> result, temp;
        if(field == 1){
            x = getInt(s, begin, s.size() - begin);
            if(x <= 255){
                result.push_back(s.substr(begin, s.size()-begin));
                return result;
            }
            else{
                return result;
            }
        }
        for(int i = 0 ; i < s.size() - begin && i < 3; i++){
            x= getInt(s, begin, i+1);
            if(x <= 255){
                temp = getIp(s, begin + i + 1, field - 1);
                for(string t:temp){
                    t = s.substr(begin, i+1) + "." + t;
                    result.push_back(t);
                }
            }
        }
        return result;
    }
    
    int getInt(string s, int begin, int size){
        if(size <= 0)
            return 256;
        string sub = s.substr(begin, size);
        int x =  atoi(sub.c_str());
        if(x == 0 && size > 1)
            return 256;
        if(x != 0 && log10((double)x) < size - 1)
            return 256;
        return x;
    }
};
