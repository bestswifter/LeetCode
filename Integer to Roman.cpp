/*
	要求：把整数(1~3999)转换成罗马数字，罗马数字和阿拉伯数字对应如下：
	I:1, V:5, X:10, L:50, C:100, D:500, M:1000
	之所以不超过4000，是因为只有I、X、C这三个数字可以放在大数字之前

	我的思路：
		方案很容易想到，以1-9为例，除了4、9特殊外，其他都有迹可循。可以对不同的位进行类似的处理

		缺点是代码比较复杂，还可以优化

	大神的思路：

		考虑getInteger的实现，它类似于分成4段的switch……case……
		这种情况下可以考虑用数组保存，避免不必要的if判断。
		不过好像这种实现更慢一些。。。。。。。。。

		string intToRoman(int num) {
	        string ret = "";
    	    string roman[4][10] = {{"0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        		                   {"0", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            		               {"0", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                		           {"0", "M", "MM", "MMM"}};
		    for (int i = 3, k = 1000; i >= 0; --i, num %= k, k /= 10)
    		    ret += (num / k == 0 ? "" : roman[i][num/k]);
    		return ret;
    	}
*/

class Solution {
public:

    string getInteger(int num) {
        string ONE = "I", FIVE = "V", TEN = "X", result = "";
        if (num == 9) {
            result = ONE + TEN;
        }
        else if (num < 9 && num >= 5) {
            result = FIVE;
            while (num > 5) {
                result += ONE;
                --num;
            }
        }
        else if (num == 4) {
            result = ONE + FIVE;
        }
        else {
            while (num >= 1) {
                result += ONE;
                --num;
            }
        }
        return result;
    }

    string getTen(int num) {
        string TEN = "X", FIFTY = "L",HUNDRED = "C", result = "";
        if (num >= 90) {
            result = TEN + HUNDRED;
        }
        else if (num < 90 && num >= 50) {
            result = FIFTY;
            while (num >= 60) {
                result += TEN;
                num -= 10;
            }
        }
        else if (num >= 40) {
            result = TEN + FIFTY;
        }   
        else if (num >= 10){
            while (num >= 10) {
                result += TEN;
                num -= 10;
            }
        }
        return result + getInteger(num % 10);
    }

    string getHundred(int num) {
        string HUNDRED = "C", FIVEHUNDRED = "D", THOUSAND = "M", result = "";
        if (num >= 900) {
            result = HUNDRED + THOUSAND;
        }
        else if ( num < 900 && num >= 500) {
            result = FIVEHUNDRED;
            while (num >= 600) {
                result += HUNDRED;
                num -= 100;
            }
        }
        else if (num >= 400) {
            result = HUNDRED + FIVEHUNDRED;
        }
        else if (num >= 100) {
            while (num >= 100) {
                result += HUNDRED;
                num -= 100;
            }
        }
        return result + getTen(num % 100);
    }
    
    string intToRoman(int num) {
        string result = "", THOUSAND = "M";
        while (num >= 1000) {
            result += THOUSAND;
            num -= 1000;
        }
        return result + getHundred(num);
    }
};