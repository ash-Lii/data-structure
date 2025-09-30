// 问题描述】

// n个人围成一个圈，按顺时针方向一次编号1、2、3、……、n，从第一个人开始顺时针方向依次报数1、2、3、……，报数m的人被淘汰，然后下一个人再从1开始报数，一直重复该过程。由于人数是有限的，因此最后一定只会剩下一个人，求这个人的编号。

// 【输入形式】

// 第一行，一个整数n，表示约瑟夫环的总人数。

// 第二行，一个整数m，表示报到m的人被淘汰。

// 【输出形式】

//  一行，一个整数，约瑟夫环最终剩下的人的编号。

// 【样例输入】

// 5
// 2
// 【样例输出】

// 3


#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

int main() {
    int n, m;
    cin >> n >> m;

    int currNum = n;

    Node* head = new Node{1, nullptr};

    Node* tail = head;
    for (int i = 2; i <= n; ++i) {
        Node* newNode = new Node{i, head};
        tail->next = newNode;
        tail = newNode;
    }

    Node* curr = head;
    while(currNum > 1) {
        for (int i = 2; i <= m - 1; ++i) {
            curr = curr->next;
        }

        Node* toDelete = curr->next;
        curr->next = toDelete->next;

        delete toDelete;
        currNum--;
        curr = curr->next;
    }

    cout << curr->val << endl;

    return 0;
}