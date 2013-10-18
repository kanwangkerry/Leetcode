
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int carry = 0;
        digits[digits.size()-1] += 1;
        if(digits[digits.size()-1] >= 10){
            digits[digits.size() -1] = digits[digits.size()-1] - 10;
            carry = 1;
        }
        if(carry == 0)
            return digits;
        int i;
        for(i = digits.size() - 2 ; i >=0 && carry == 1;i--){
            digits[i] = digits[i] + carry;
            carry = digits[i] >= 10 ? 1 : 0;
            digits[i] = digits[i] == 10 ? 0 : digits[i];
        }
        if(carry == 1 && i < 0){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
