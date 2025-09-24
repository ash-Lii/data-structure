// 【问题描述】

// 设计高效的算法，使用顺序表存储数据，将顺序表中所有元素逆置，要求算法的空间复杂度为O（1）
// 【输入形式】

// 先输入一个整数N（N<30)，换行后间隔输入一行个数为N的整数。

// 【输出形式】

// 第一行间隔输出N个整数，要求与输入的数据顺序一致；第二行间隔输出N个整数，要求与输入的数据顺序逆置。
// 【样例输入】

// 5

// 5 6 7 8 9
// 【样例输出】

// 5 6 7 8 9

// 9 8 7 6 5

# include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* A = new int[30];

    int i = 0;
    while (i < n) {
        cin >> A[i];
        cout << A[i] << " ";
        i++;
    }
    cout << endl;
    i--;
    
    while (i >= 0) {
        cout << A[i] << " ";
        i--;
    }
    cout << endl;


    return 0;
}