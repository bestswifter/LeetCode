//
//  main.cpp
//  第137题
//
//  Created by 张星宇 on 16/2/6.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> A) {
    int ones = 0, twos = 0;
    for(int i = 0; i < A.size(); i++){
        ones = (ones ^ A[i]) ^ twos;
        twos = (twos ^ A[i]) ^ ones;
        cout << ones << " " << twos << endl;
    }
    return ones;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,2,2,1};
    std::cout << singleNumber(nums) << endl;
    
    cout << (0 ^ 2) << endl;
    cout << (2 & 1) << endl;
    return 0;
}
