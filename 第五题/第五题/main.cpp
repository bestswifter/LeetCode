//
//  main.cpp
//  第五题
//
//  Created by 张星宇 on 15/9/20.
//  Copyright © 2015年 张星宇. All rights reserved.
//

#include <iostream>

using namespace std;

string convert(string s, int numRows);
int main(int argc, const char * argv[]) {

    std::cout << convert("PAYPALISHIRING", 3) << endl;
    return 0;
}

string convert(string s, int numRows) {
    if(numRows == 1) return s;
    string returnString(s);
    int t = 2 * numRows - 2;
    
    for(int i = 1; i <= s.size(); i++){
        if(i % t == 0){
            returnString[(int)(s.size() / t + 0.5) + 2 * i / t] = s[i - 1];
            std::cout << "对应下标 = " << (int)(s.size() / t + 0.5) + 2 * i / t << endl;
        }
        else{
            // std::cout << "i = " << i << "   ";
            int root = i % t <= numRows ? i % t : numRows - i % numRows;
            int offset = i % t <= numRows ? ((root % numRows <= 1) ? 1 : 2) * (i / t) : 2 * (i / t) + 1;
            
            // std::cout << "offset = " << offset << " root = " << root << endl;
            int pos = ((2 * root - 3) < 0 ? 0 : (2 * root - 3))  * (s.size() / t) + (i % t <= root -1 ? : root - 1 + std::max(i % t, 2 * numRows - root + 1) % (2 * numRows - root + 1));
            // std::cout << "real pos = " << pos + offset << " 整数 = " << ((2 * root - 3) < 0 ? 0 : (2 * root - 3))  * (i / t) << " else = " << (i % t <= root -1 ? : root - 1 + max(i % t, 2 * numRows - root + 1) % (2 * numRows - root + 1)) << endl;
            returnString[pos + offset] = s[i - 1];
            std::cout << "pos + offset = " << pos + offset << endl;
        }
        
    }
    return returnString;
}