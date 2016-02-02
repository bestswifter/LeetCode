//
//  main.cpp
//  第二十二题
//
//  Created by 张星宇 on 16/2/2.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//vector<string> generateParenthesis(int n) {
//    if (n < 2) {
//        return n == 1 ? vector<string>({"()"}) : vector<string>({});
//    }
//    
//    vector<string> base = generateParenthesis(n-1);
//    int l = base.size();
//    for (int i = 0; i < l; ++i) {
//        base.push_back(base[i] + "()");
//        
//        if (i != l - 1) {
//            base.push_back("()" + base[i]);
//        }
//        base[i] = '(' + base[i] + ')';
//    }
//    return base;
//}

void helper(vector<string> &v, string s, int l, int r) {
    if (l == 0 && r == 0) {
        v.push_back(s);
    }
    
    if (l > 0) { helper(v, s+'(', l-1, r); }
    if (r > l) { helper(v, s+')', l, r-1); }
}


vector<string> generateParenthesis(int n) {
    vector<string> result;
    helper(result, "", n, n);
    return result;
}

int main(int argc, const char * argv[]) {
    for (int i = 0; i < 5; ++i) {
        vector<string> parentheses = generateParenthesis(i);
        cout << "i = " << i << "nums = " << parentheses.size() << endl;
        for (int j = 0; j < parentheses.size(); ++j) {
            cout << parentheses[j] << " ";
        }
        cout << endl;
        
    }
    return 0;
}
