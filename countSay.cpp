class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        string tempResult;
        int len;
        int index;
        while(--n){
            index = 0;
            int i = 1;
            len = result.length();
            tempResult = "";
            while(index < len){
                i = 1;
                while(i < len && result[index] == result[index + i])
                    i++;
                tempResult.push_back('0'+i);
                tempResult.push_back(result[index]);
                index += i;
            }
            result = tempResult;
            
        }
        return result;
        
    }
};
