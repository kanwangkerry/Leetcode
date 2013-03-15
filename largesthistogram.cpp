class Solution {
 public:
     int largestRectangleArea(vector<int> &height) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
         int maxArea = 0;
         stack<int> s;
         
         for(int i = 0; i < height.size(); i++)
             if (s.empty())
             {
                 s.push(i);
             }
             else
             {
                 while(!s.empty())
                 {
                     if (height[s.top()] <= height[i])
                     {
                         s.push(i);
                         break;
                     }
                     else
                     {
                         int index = s.top();
                         s.pop();
                         int leftWidth = s.empty() ? index : index - s.top() - 1;
                         int rightWidth = i - index - 1;
                         maxArea = max(maxArea, height[index] * (leftWidth + rightWidth + 1));
                     }
                 }
                 
                 if (s.empty())
                     s.push(i);
             }
         
         int rightIndex = s.empty() ? 0 : s.top() + 1;
         
         while(!s.empty())
         {
             int index = s.top();
             s.pop();
             int leftWidth = s.empty() ? index : index - s.top() - 1;
             int rightWidth = rightIndex - index - 1;
             maxArea = max(maxArea, height[index] * (leftWidth + rightWidth + 1));
         }
         
             
         return maxArea;
     }
 };
