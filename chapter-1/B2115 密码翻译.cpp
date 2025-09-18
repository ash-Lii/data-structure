// 在情报传递过程中，为了防止情报被截获，往往需要对情报用一定的方式加密。我们给出一种最简单的加密方法，对给定的一个字符串，把其中从 a~y，A~Y 的字母用其后继字母替代，把 z 和 Z 用 a 和 A 替代，其他非字母字符不变。请根据该加密规则将输入的密码进行解密。

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'y') {
            str[i] = str[i] + 1;
        } else if (str[i] == 'z') {
            str[i] = 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Y') {
            str[i] = str[i] + 1;
        } else if (str[i] == 'Z') {
            str[i] = 'A';
        }
    }
    cout << str << endl;
    return 0;
}