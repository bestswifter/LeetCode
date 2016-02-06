class Solution {
public:
    string longestPalindrome(string s) {
        int longestLength = 1, startPos = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i - 1, tempLength = 1, flag = 0; j > -1; --j){
                if(2 * i - j - flag < s.size()){
                    if(s[j] == s[2 * i - j - flag]){
                        tempLength += 2;
                        if((j == 0 || 2 * i - j - flag == s.size() - 1) && tempLength >= longestLength){
                            // 判断到两端了，强制结束，判断是否需要更新
                            longestLength = tempLength;
                            startPos = j;
                        }
                    }
                    else if(s[j] == s[i] && s.substr(j, i-j+1) == string(i-j+1, s[j])){
                        ++tempLength;
                        ++flag;
                        if(tempLength > longestLength){
                            longestLength = tempLength;
                            startPos = j;
                        }
                    }
                    else{
                        if(tempLength > longestLength){
                            longestLength = tempLength;
                            startPos = j + 1;
                        }
                        break;
                    }
                }
                else if(s[j] == s[i] && tempLength == longestLength){
                    ++longestLength;
                    startPos = j;
                    break;
                }
                else{
                    break;
                }
            }
        }
        return s.substr(startPos, longestLength);
    }
};