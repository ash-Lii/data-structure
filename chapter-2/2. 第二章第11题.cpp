// 【问题描述】

// 有一个整数单链表L，设计一个算法删除其中所有值为x的结点。例如L=(1,2,2,3,1,),x=2，删除后L=(1,3,1)。


// 【输入形式】

// 第一行输入两个正整数N、x，表示链表的长度，以及x的值

// 第二行输入N个递增有序的整数A[i]，表示链表的元素


// 【输出形式】

// 输出一行整数，表示删除所有值为x的结点后的链表


// 【样例输入】

// 4 5

// 1 3 5 7


// 【样例输出】

// 1 3 7


// 【样例说明】


// 【评分标准】

// N <=100000

// 保证整数在int范围内

 

// 【类库使用要求】

// 不可以使用STL库函数。



// 【说明】

// 需要自行定义链表，完成链表的操作，不能使用STL库。

# include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n, x;
    cin >> n >> x;

    int firstValue;
    cin >> firstValue;
    Node* head = new Node{firstValue, nullptr};

    Node* lastNode = head;
    for (int i = 1; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = new Node{value, nullptr};
        lastNode->next = newNode;
        lastNode = newNode;
    }

    Node* current = head;

    while (current->next != nullptr) {
        if (current->next->data == x) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }

    Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;

    return 0;
}   