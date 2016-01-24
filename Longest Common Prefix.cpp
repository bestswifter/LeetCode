/*
	题解：
	好吧，这个题实在想不到什么好说的，挨个比较吧，遇到不同的就停。。。
*/

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0 || strs[0].size() == 0) {
        return "";
    }
    string result = "";
    int minLength = strs[0].size();
    for (int i = 1; i < strs.size(); ++i) {
        if (strs[i].size() == 0) {
            return "";
        }
        if (minLength > strs[i].size()) {
            minLength = strs[i].size();
        }
    }
    for (int i = 0; i < minLength; ++i) {
        bool isAllEqual = true;
        for (int j = 1; j < strs.size(); ++j) {
            if (!(strs[j][i] == strs[0][i])) {
                isAllEqual = false;
                break;
            }
        }
        if (isAllEqual) {
            result += strs[0][i];
            continue;
        }
        break;
    }
    return result;
}