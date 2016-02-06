class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int currentMaxLength = 0;
        int maxLength = 0;
        int searchRangeBegin = 0;
        unordered_map<char, int> letters;
        
        for (int i = 0; i < s.size(); ++i){
            unordered_map<char, int>::iterator indexIterator = letters.find(s[i]);
            
            if(indexIterator == letters.end() || (indexIterator != letters.end() && indexIterator->second < searchRangeBegin)){
                ++currentMaxLength;
                //更新一下最大不重复子串的长度
                if (maxLength < currentMaxLength){
                    maxLength = currentMaxLength;
                }
                letters[s[i]] = i;
            }
            else{
                int index = indexIterator->second;
                //找到了重复字符
                searchRangeBegin = index + 1;
                currentMaxLength = i - index;
            }
        }
        
        return maxLength;
    }
};