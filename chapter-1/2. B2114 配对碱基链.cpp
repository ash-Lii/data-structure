// 题目描述
// 脱氧核糖核酸（DNA）由两条互补的碱基链以双螺旋的方式结合而成。
// 而构成 DNA 的碱基共有 4 种：
// 腺嘌呤（A）
// 鸟嘌呤（G）
// 胸腺嘧啶（T）
// 胞嘧啶（C）
// 我们知道，在两条互补碱基链的对应位置上，腺嘌呤总是和胸腺嘧啶配对，鸟嘌呤总是和胞嘧啶配对。
// 你的任务就是根据一条单链上的碱基序列，给出对应的互补链上的碱基序列。
// 输入格式
// 一个字符串，表示一条碱基链。
// 这个字符串只含有大写字母 A、T、G、C，分别表示腺嘌呤、胸腺嘧啶、鸟嘌呤和胞嘧啶。
// 字符串长度不超过 255。
// 输出格式
// 一个只含有大写字母 A、T、G、C 的字符串，为与输入的碱基链互补的碱基链。
// 输入输出样例 
// 输入:
// ATATGGATGGTGTTTGGCTCTG
// 输出：
// TATACCTACCACAAACCGAGAC

# include <iostream>
# include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == 'A') {
            str[i] = 'T';
        } else if (str[i] == 'T') {
            str[i] = 'A';
        } else if (str[i] == 'G') {
            str[i] = 'C';
        } else if (str[i] == 'C') {
            str[i] = 'G';
        }
    }
    cout << str << endl;
    return 0;
}