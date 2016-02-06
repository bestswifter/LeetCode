/*
	题目分析： 找到数组中唯一一个出现一次的数字(别的都出现了三次)

	解题思路：用00、01和10分别表示出现了0、1、2次。只要找到一种00-01-10-00-01……的转换逻辑即可。
*/

int singleNumber(vector<int> A) {
    int ones = 0, twos = 0;
    for(int i = 0; i < A.size(); i++){
        ones = (ones ^ A[i]) ^ twos;
        twos = (twos ^ A[i]) ^ ones;
        cout << ones << " " << twos << endl;
    }
    return ones;
}