
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.size();
        int max = 0;
        int i =0;
        bool exists[256];
        memset(exists, 0, 256*sizeof(bool));
        int l = 0;
        while(i < len){
            while(i< len){
                if(exists[s[i]])
                    break;
                else{
                    l++;
                    exists[s[i]] = true;
                    i++;
                }
            }
            if(l > max)
                max = l;
            int j = i - l;
            while(j < i){
                l--;
                if(s[j] == s[i]){
                    l++;
                    i++;
                    break;
                }
                else{
                    exists[s[j]] = false;
                    j++;
                }
            }
        }
        return max;
    }
};
