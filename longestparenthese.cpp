int longestValidParentheses(const char* str) {
    assert(str);

    int nMax = 0;
    const char* p = str;
    stack<const char*> stk;
    while (*p != 0)
    {
        if (*p == '(')
            stk.push(p);
        else if (*p == ')')
        {
            if (!stk.empty() && *stk.top() == '(')
            {
                stk.pop();
                nMax = max(p - (stk.empty() ? str-1 : stk.top()), nMax);
            }
            else stk.push(p);
        }

        p++;
    }

    return nMax;
}
