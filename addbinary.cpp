class Solution {
public:
    string addBinary(string a, string b) {
        string temp;
        if(a.size() < b.size()){
            temp = a;
            a = b;
            b = temp;   
        }
        string result;
        int len = b.size();
        int len_a = a.size() - b.size();
        int u =0;
        char c;
        while(len-->0){
            c = a[len_a+len]-'0'+b[len]-'0' + u;
            if(c >= 2){
                u = 1;
                c = c-2;
            }
            else u=0;
            result.push_back(c+'0');            
        }
        while(len_a-->0){
            c = a[len_a]-'0' + u;
            if(c>=2){
                u = 1;
                c = c-2;
            }
            else u=0;
            result.push_back(c+'0');
        }
        if(u ==1) result.push_back('1');
        string result1;
        int i = result.size();
        while(i--){
            result1.push_back(result[i]);
        }
        return result1;
        
        
    }
};
