class Solution {
public:
    int romanToInt(string s) {
        if(s[0] == 0) return 0;
        if(s[0] == 'M')
            return 1000+romanToInt(s.substr(1, s.length()-1));
        else if(s[0] == 'C' && s[1] == 'M')
            return 900+romanToInt(s.substr(2, s.length()-2));
        else if(s[0] == 'D')
            return 500+romanToInt(s.substr(1, s.length()-1));
        else if(s[0] == 'C' && s[1] == 'D')
            return 400+romanToInt(s.substr(2, s.length()-2));
        else if(s[0] == 'C')
            return 100+romanToInt(s.substr(1, s.length()-1));
        else if(s[0] == 'X' && s[1] == 'C')
            return 90 +romanToInt(s.substr(2, s.length()-2));
        else if(s[0] == 'L')
            return 50 + romanToInt(s.substr(1, s.length()-1));
        else if(s[0] == 'X' && s[1] == 'L')
            return 40 + romanToInt(s.substr(2, s.length()-2));
        else if(s[0] == 'X')
            return 10 + romanToInt(s.substr(1, s.length()-1));
        else if(s[0] == 'I' && s[1] == 'X')
            return 9 + romanToInt(s.substr(2, s.length()-2));
        else if(s[0] == 'V')
            return 5 + romanToInt(s.substr(1, s.length()-1));
        else if(s[0] == 'I' && s[1] == 'V')
            return 4 + romanToInt(s.substr(2, s.length()-2));
        else if(s[0] == 'I')
            return 1+ romanToInt(s.substr(1, s.length()-1));
    }
};
