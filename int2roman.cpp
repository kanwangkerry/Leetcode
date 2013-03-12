class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        string result = "";
        int len;
        if(num/1000 != 0){
            len = num/1000;            
            for(int i = 0 ; i < len; i++)
                result.append("M");
            
        }
        num = num%1000;
        if(num/100 != 0){
        switch(num/100){
            case 1:result.append("C");break;
            case 2:result.append("CC");break;
            case 3:result.append("CCC");break;
            case 4:result.append("CD");break;
            case 5:result.append("D");break;
            case 6:result.append("DC");break;
            case 7:result.append("DCC");break;
            case 8:result.append("DCCC");break;
            case 9:result.append("CM");break;
        }
        }
        num = num%100;
        if(num/10 !=0){
        switch(num/10){
            case 1:result.append("X");break;
            case 2:result.append("XX");break;
            case 3:result.append("XXX");break;
            case 4:result.append("XL");break;
            case 5:result.append("L");break;
            case 6:result.append("LX");break;
            case 7:result.append("LXX");break;
            case 8:result.append("LXXX");break;
            case 9:result.append("XC");break;
        }
        }
        num = num % 10;
        if(num != 0){
            switch(num){
            case 1:result.append("I");break;
            case 2:result.append("II");break;
            case 3:result.append("III");break;
            case 4:result.append("IV");break;
            case 5:result.append("V");break;
            case 6:result.append("VI");break;
            case 7:result.append("VII");break;
            case 8:result.append("VIII");break;
            case 9:result.append("IX");break;
        }
            
        }
        return result;
        
    }
};
