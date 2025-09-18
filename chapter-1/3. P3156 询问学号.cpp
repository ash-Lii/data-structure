// 题目描述
// 有n名同学依次进入教室，已知他们的学号按进入顺序给出。老师需多次查询第i个进入教室的同学的学号。询问次数不超过1e5次。
// 输入格式
// 第一行：两个整数n和m，分别表示学生数和询问次数
// 第二行：n个整数，表示学生的学号
// 第三行：m个整数，表示每次询问的位置i
// 输出格式
// 对于每个询问i，输出对应的学号，每个结果占一行
// 示例输入输出
// 输入：
// 10 3
// 1 9 2 60 8 17 11 4 5 14
// 1 5 9
// 输出：
// 1
// 8
// 5

# include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int students[n];
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }

    for (int i = 0; i < m; i++) {
        int query;
        cin >> query;
        cout << students[query - 1] << endl;
    }
    return 0;
}