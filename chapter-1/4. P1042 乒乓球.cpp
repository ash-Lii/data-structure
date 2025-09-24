// 题目描述
// 华华通过以下方式进行分析，首先将比赛每个球的胜负列成一张表，然后分别计算在 11 分制和 21 分制下，双方的比赛结果（截至记录末尾）。

// 比如现在有这么一份记录，（其中 W 表示华华获得一分，L 表示华华对手获得一分）：
// WWWWWWWWWWWWWWWWWWWWWWLW
// 在 11 分制下，此时比赛的结果是华华第一局 11 比 0 获胜，第二局 11 比 0 获胜，正在进行第三局，当前比分 1 比 1。而在 21 分制下，此时比赛结果是华华第一局 21 比 0 获胜，正在进行第二局，比分 2 比 1。如果一局比赛刚开始，则此时比分为 0 比 0。直到分差大于或者等于 2，才一局结束。

// 注意：当一局比赛结束后，下一局立刻开始。

// 输入格式
// 每个输入文件包含若干行字符串，字符串由大写的 W、 L 和 E 组成。其中 E 表示比赛信息结束，程序应该忽略 E 之后的所有内容。

// 输出格式
// 输出由两部分组成，每部分有若干行，每一行对-应一局比赛的比分（按比赛信息输入顺序）。其中第一部分是 11 分制下的结果，第二部分是 21 分制下的结果，两部分之间由一个空行分隔。

// 输入 #1

// WWWWWWWWWWWWWWWWWWWW 
// WWLWE
// 输出 #1

// 11:0 
// 11:0 
// 1:1 

// 21:0 
// 2:1


// 输入 #2

// WWWWWWWWWW
// LLLLLLLLLL
// WLWLWLWWWW
// LWWWWLWE
// 输出 #2

// 15:13
// 7:2

// 21:14
// 1:1

#include <iostream>
#include <vector>
#include <string>
using namespace std;


void printScore(const vector<int>& score11, const vector<int>& score21) {
    for (size_t i = 0; i < score11.size(); i += 2) {
        cout << score11[i] << ":" << score11[i + 1] << endl;
    }
    cout << endl;
    for (size_t i = 0; i < score21.size(); i += 2) {
        cout << score21[i] << ":" << score21[i + 1] << endl;
    }
}

int main() {
    string input;
    vector<int> score11, score21;
    int w11 = 0, l11 = 0, w21 = 0, l21 = 0;

    while (cin >> input) {
        for (char ch : input) {
            if (ch == 'E') {
                score11.push_back(w11);
                score11.push_back(l11);
                score21.push_back(w21);
                score21.push_back(l21);
                printScore(score11, score21);
                return 0;
            } else if (ch == 'W') {
                w11++;
                w21++;
            } else if (ch == 'L') {
                l11++;
                l21++;
            }

            if (((w11 >= 11) || (l11 >= 11)) && (abs(w11 - l11) >= 2)) {
                score11.push_back(w11);
                score11.push_back(l11);
                w11 = 0;
                l11 = 0;
            }

            if (((w21 >= 21) || (l21 >= 21)) && (abs(w21 - l21) >= 2)) {
                score21.push_back(w21);
                score21.push_back(l21);
                w21 = 0;
                l21 = 0;
            }
        }

    }
}