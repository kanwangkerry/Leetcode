class Solution {
public:
    string multiply(string num1, string num2) {
        int len = num2.length();
        string temp = "";
        string result = "";
        int l = num1.length();
        for(int i = len-1 ;i >= 0; i--){
            temp = "";
            int x = num2[i] - '0';
            int c = 0;
            for(int j = l-1; j >= 0;j--){
                int y = x*(num1[j]-'0') + c;
                c = y/10;
                y = y%10;
                temp.insert(temp.begin(), y+'0');                
            }
            if(c > 0)
                temp.insert(temp.begin(), c+'0');
            for(int j = 0 ; j < len - i -1; j++)
                temp.push_back('0');
            result = add(result, temp);            
        }
        while(result.length() > 1){
            if(result[0] != '0') break;
            else result.erase(result.begin());
        }
        return result;

        
    }
    
    string add(string num1, string num2){
        string result = "";
        int l1 = num1.length() -1;
        int l2 = num2.length() -1;
        int c = 0;
        while(l1 >= 0 && l2 >= 0){
            int x= num1[l1] + num2[l2] - '0' - '0' + c;
            c = x/10;
            x = x%10;
            result.insert(result.begin(), (x+'0'));
            l1--;
            l2--;          
        }
        while(l1 >= 0){
            int x= num1[l1] - '0' + c;
            c = x/10;
            x = x%10;
            result.insert(result.begin(), x+'0');
            l1--;            
        }
        while(l2 >= 0){
            int x= num2[l2] - '0' + c;
            c = x/10;
            x = x%10;
            result.insert(result.begin(), x+'0');
            l2--;            
        }
        if(c == 1)
            result.insert(result.begin(), '1');
        return result;

    }
};
