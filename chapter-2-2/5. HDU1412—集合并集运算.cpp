// 【问题描述】

// 给你两个集合A和B，要求{A}+{B}。注意同一个集合中不会有两个相同的元素。

// 【输入形式】

//       每组输入数据分为三行，第一行有两个数字n，m（0<n，m≤10000），分别表示集合A和集合B的元素个数。后两行分别表示集合A和集合B，每个元素为不超出int范围的整数，两个元素之间有一个空格隔开。

// 【输出形式】

//       针对每组数据输出一行数据，表示合并后的集合，要求从小到大输出，两个元素之间有一个空格隔开。

// 【样例输入】

// 1 2

// 1

// 2 3

// 【样例输出】

//        1 2 3


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n, m;
    cin >> n >> m;

    Node* first = new Node();
    cin >> first->data;
    first->next = nullptr;

    for(int i = 1; i < n + m; i++) {
        Node* newNode = new Node();
        cin >> newNode->data;

        if(first->next == nullptr){
            if(first->data == newNode->data){
                continue;
            } else if(first->data < newNode->data){
                first->next = newNode;
                newNode->next = nullptr;
                continue;
            } else {
                newNode->next = first;
                first = newNode;
                continue;
            }
        }

        Node* curr = first;
        while(curr != nullptr){
            if(curr->data == newNode->data){
                break;
            } else if(curr->data < newNode->data ){
                if(curr->next == nullptr){
                    curr->next = newNode;
                    newNode->next = nullptr;
                    break;
                } else if(curr->next->data > newNode->data){
                    newNode->next = curr->next;
                    curr->next = newNode;
                    break;
                } else {
                    curr = curr->next;
                }
            } else {
                newNode->next = curr;
                first = newNode;
                break;
            }
        }

    }


    Node* curr = first;
    while(curr != nullptr){
        if(curr != first)  cout << " ";
        cout << curr->data;
        curr = curr->next;
    }

    cout << endl;




    return 0;
}