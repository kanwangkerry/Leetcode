
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int index = 0;
        vector<string> result;
        while(true){
            int sum = 0;
            int end, spaces, slot_space, num_large_index;
            int k;
            for(k = index ; k < words.size(); k ++){
                sum += words[k].size();
                if(k != index)
                    sum += 1;
                if(sum > L)
                    break;
            }
            if(sum <= L){ // here is the last line
                string temp = "";
                for(int i = index ; i < words.size() -1; i ++){
                    temp += words[i];
                    temp += " ";
                }
                temp += words[words.size() -1];
                while(temp.size() < L){
                    temp += " ";
                }
                result.push_back(temp);
                break;
            }
            else if(sum > L){
                end = k -1;
                sum = 0;
                for(int i = index ; i <= end ; i++){
                    sum += words[i].size();
                }
                spaces = L - sum;
                if(end - index == 0){
                    string temp = "";
                    temp += words[index];
                    for(int i = 0 ; i < spaces ; i ++){
                        temp += " ";
                    }
                    result.push_back(temp);
                    index += 1;
                    continue;
                }
                if(spaces %(end -index) == 0){
                    slot_space = spaces / (end - index);
                    num_large_index = 0;
                }
                else{
                    slot_space = spaces / (end - index);
                    num_large_index = spaces - slot_space*(end-index);
                }
                string temp = "";
                for(int i = index ; i < index+num_large_index ; i++){
                    temp += words[i];
                    for(int j = 0 ; j <= slot_space ; j++){
                        temp += " ";
                    }
                }
                for(int i = index + num_large_index ; i < end; i++){
                    temp += words[i];
                    for(int j = 0 ; j < slot_space ; j++){
                        temp += " ";
                    }
                }
                temp += words[end];
                result.push_back(temp);
                index =end +1;
            }
        }
        return result;
    }
};
