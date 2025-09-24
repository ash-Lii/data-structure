// 【问题描述】

// 有两个集合采用递增有序的整数顺序表A、B存储，设计一个在时间上尽可能高效的算法求两个集合的差集C，C仍然用顺序表存储（其中C中的元素是存在于A中但不在B中的所有元素，并且保持C的递增有序）。

// 【输入形式】

// 第一行分别输入数组A和数组B的元素个数，第二行递增输入序列A中的元素，以空格分隔；第三行递增输入序列B中的元素，以空格分隔。

// 【输出形式】

// 按照递增有序的方式一行输出差集C的所有元素，每个元素间隔一个空格，最后一个元素也带有空格。

// 【输入样例】

// 4 5
// 1 3 5 7
// 1 2 4 5 9
// 【输出样例】

// 3 7
// 【样例说明】

// A={1,3,5,7}，B={1,2,4,5,9}。差集C为{3,7}。



// 【类库使用要求】

// 不可以使用STL库函数。


# include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int* A = new int[n];
    int* B = new int[m];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> B[j];
    }
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] < B[j]) {
            cout << A[i] << " ";
            i++;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    while (i < n) {
        cout << A[i] << " ";
        i++;
    }
    cout << endl;
    delete[] A;
    delete[] B;
    return 0;
}