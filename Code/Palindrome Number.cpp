/*题解：
    要求：

    给定数字x，判断x是否是回文数

    我的思路：

    1. 对于12321这样的数字，判断它是不是回文数，只要先看最高位和最低位是否相等，如果想等则判断232是不是回文数
    2. 上述思路不适合1000021这样的数字，因此递归调用的方法行不通
    3. 最简单的做法是，不处理原来的数字，依次比较最高位和最低位，次高位和次低位……
    4. getNumberAtIndex函数获取第index位上的数字
    5. isPalindrome函数中先获取数字有几位，再依次比较对应位置上的数字

    大神思路：

    可以减半对比过程。
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
*/

int getNumberAtIndex(int number, int index, int totalBits) {
    return (number / (int)pow(10, totalBits - index - 1)) % 10;
}

bool isPalindrome(int x) {
    if (x < 0) { return false; }
    
    int bits = 0, localValue = x, i = 0;
    while (localValue != 0) {
        bits++;
        localValue /= 10;
    }
    
    while (bits > 1) {
        if (getNumberAtIndex(x, i, bits) != getNumberAtIndex(x, bits - i - 1, bits)) {
            return false;
        }
        ++i;
        bits -= 2;
    }
    return true;
}