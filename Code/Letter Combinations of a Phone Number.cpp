/*
    解题思路：

    数组中的元素呈指数级增长，首先排除0和1的情况，这种情况下返回空数组。
    否则只要把原来数组中的每个元素，分别加上若干个后缀即可。注意原数组为空的情况
*/

vector<string> letterCombinations(string digits) {
    vector<vector<string>> map = {{"a","b","c"}, {"d","e","f"}, {"g","h","i"},
        {"j","k","l"}, {"m","n","o"}, {"p","q","r","s"}, {"t","u","v"}, {"w","x","y","z"}};
    vector<string> result;
    for (int i = 0; i <digits.length(); ++i) {
        if (digits[i] == '0' || digits[i] == '1') {
            return result;
        }
    }
    if (digits.size() > 0) {
        for (int i = 0; i < map[digits[0] - 50].size(); ++i) {
            result.push_back(map[digits[0] - 50][i]);
        }
    }
    
    for (int i = 1; i < digits.length(); ++i) {
        int currentSize = result.size();
        for (int j = 0; j < currentSize; ++j) {
            for (int k = 1; k < map[digits[i]-50].size(); ++k) {
                result.push_back(result[j] + map[digits[i] - 50][k]);
            }
        }
        for (int j = 0; j < currentSize; ++j) {
            result[j] += map[digits[i] - 50][0];
        }
    }
    return result;
}