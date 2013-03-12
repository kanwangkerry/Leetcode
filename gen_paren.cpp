vector<string> generateParenthesis(int n) {
    vector<string> ans;
    if (n>0) generator(ans, "", 0, 0, n);
    return ans;
}

void generator(vector<string> & ans, string s, int l, int r, int n) { // r/l: appearance of ) (
    if (l == n) {
        ans.push_back(s.append(n-r, ')'));
        return;
    }
    generator(ans, s+'(', l+1, r, n);
    if (l>r) generator(ans, s+")", l, r+1, n);
}
