
class Solution {
public:
    vector<vector<string>> letters;
    vector<string> letterCombinations(string digits) {
        vector<string> result, result1;
        result1.push_back("");
        if(digits.length() == 0) return result1;
        result1 = letterCombinations(digits.substr(1, digits.length() - 1));
        switch(digits[0]){
            case '2': result = add_letters("abc", result1);break;
            case '3': result = add_letters("def", result1);break;
            case '4': result = add_letters("ghi", result1);break;
            case '5': result = add_letters("jkl", result1);break;
            case '6': result = add_letters("mno", result1);break;
            case '7': result = add_letters("pqrs", result1);break;
            case '8': result = add_letters("tuv", result1);break;
            case '9': result = add_letters("wxyz", result1);break;
        }
        return result;
    }
    vector<string> add_letters(char *s, vector<string> src){
        vector<string> result;
        int len1 = strlen(s);
        int len2 = src.size();
        for(int i = 0 ; i < len1 ;i++){
            for(int j = 0 ; j < len2 ;j ++){
                string temp;
                temp.push_back(s[i]);
                temp.append(src[j]);
                result.push_back(temp);
            }
        }
        return result;
    }
};
