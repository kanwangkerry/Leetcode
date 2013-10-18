
class Solution {
public:
    string simplifyPath(string path) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<string> path_stack;
        int index = 1, x = 1;
        while(index < path.size()){
            x = path.find("/", index);
            if(x == index){
                index++;
                continue;
            }
            if(x == string::npos)
                x = path.size();
            string temp = path.substr(index, x-index);
            if(temp == "."){
                index = x+1;
            }
            else if(temp == ".."){
                if(!path_stack.empty())
                    path_stack.pop();
                index = x+1;
            }
            else{
                path_stack.push(temp);
                index = x+1;
            }
        }
        string result = "";
        while(!path_stack.empty()){
            result = "/"+ path_stack.top() + result;
            path_stack.pop();
        }
        if(result == "")
            result = "/";
        return result;
    }
};
