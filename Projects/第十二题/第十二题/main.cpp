//
//  main.cpp
//  第十二题
//
//  Created by 张星宇 on 16/1/23.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>

using namespace std;

string intToRoman(int num);

string getInteger(int num) {
    // 可以确信num小于10且大于等于0
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

string getTen(int num) {    // 负责处理10-99
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

string getHundred(int num) {    // 负责处理100-999
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

int main(int argc, const char * argv[]) {
    for (int i = 1; i < 100; ++i) {
        std::cout << i << " = " << intToRoman(i) << endl;
    }
    std::cout << 51 << " = " << intToRoman(51) << endl;
    return 0;
}

string intToRoman(int num) { //负责处理1000-3999
    string result = "", THOUSAND = "M";
    while (num >= 1000) {
        result += THOUSAND;
        num -= 1000;
    }
    return result + getHundred(num);
}


//string intToRoman(int num) {
//    string ret = "";
//    string roman[4][10] = {{"0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
//        {"0", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
//        {"0", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
//        {"0", "M", "MM", "MMM"}};
//    for (int i = 3, k = 1000; i >= 0; --i, num %= k, k /= 10)
//        ret += (num / k == 0 ? "" : roman[i][num/k]);
//    return ret;
//}