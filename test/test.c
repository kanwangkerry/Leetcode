#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <tr1/unordered_set>
#include <set>
#include <vector>
#include <map>
#include <queue>
using namespace std;

    bool ableToDecode2(string s, int begin){
        if(begin == s.size() -1 || begin < 0)
            return false;
        char a[2];
        a[0] = s[begin+0];
        a[1] = s[begin+1];
        int x = atoi(a);
        if(x>=10 && x <= 26)
            return true;
        else return false;
    }

    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if(n ==0)
            return 0;
        int *result = new int[n];
            
        if(s[n-1] == '0'){
            result[n-1] = 0;
        }
        else{
            result[n-1] = 1;
        }
        if(s.size() >= 2 && ableToDecode2(s, s.size()-2)){
            result[s.size()-2] = 1 + result[s.size()-1];
        }
        else if(s.size() >= 2 && !ableToDecode2(s, s.size()-2)){
            if(s[s.size()-2] == '0')
                result[s.size()-2] = 0;
            else
                result[s.size()-2] = result[s.size()-1];
        }
        for(int i = s.size() - 3; i >= 0 ; i--){
            if(s[i] == '0'){
                result[i] = 0;
                continue;
            }
            if(ableToDecode2(s, i)){
                result[i] = result[i+1] + result[i+2];
            }
            else
                result[i] = result[i+1];
        }
        return result[0];
        
    }
    
    
int main(){
	string s("abc");
	s.push_back('\0');
	s += "def";
	int index = s.find('\0');

	printf("%s\n", s.substr(index+1, s.size()-index - 1).c_str());
	return 1;
}
