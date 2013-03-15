#include <stdio.h>
#include <stdlib.h>
int main()
{
		char haystack[1000000];
		char needle[1000000];
		scanf("%s", haystack);
		scanf("%s", needle);
		int n = strlen(haystack);
        int m = strlen(needle);
		

        if(m == 0) return haystack;
        if(n == 0) return NULL;
        if(m > n) return NULL;
        int j;
        int p[1000000];
        
        p[0] = -1;
        j = -1;
		int i;
        for(i = 1; i < m ;i++){
            while(j>=0 && needle[j+1] != needle[i]) j = p[j];
            if(needle[j+1] == needle[i]) j++;
            p[i] = j;
        }
        
        j= -1;
        for(i = 0 ; i < n ;i++){
            while(j >= 0 && haystack[i] != needle[j+1]) j = p[j];
            if(needle[j+1] == haystack[i]) j++;
            if(j == m-1)
			{
				printf("%s\n", haystack+i-m+1);
				break;
			}
		}
	return 0;
}
