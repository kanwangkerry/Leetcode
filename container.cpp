class Solution {
public:
    int maxArea(vector<int> &height) {
        int len = height.size();
        int max= 0;
        int h, temp;
        int i= 0, j = len-1;
        while(i < j){
            if(height[i] < height[j] ){
                temp = height[i]*(j-i);
                if(temp > max) max =temp;
                i++;
            }
            else{
                temp = height[j]*(j-i);
                if(temp > max) max = temp;
                j--;
            }
            
        }
        
        return max;
        
    }
};
