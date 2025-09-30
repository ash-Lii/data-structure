// 给定一个含n+1个结点的单链表L：L0→L1→…→Ln-1→Ln，将其重新排列后变为：L0→Ln→L1→Ln-1→L2→Ln-2→…。你不能只是单纯的改变结点内部的值，而是需要实际的进行结点交换。示例1，给定链表为1->2->3->4，重新排列为1->4->2->3。示例2，给定链表为1->2->3->4->5，重新排列为1->5->2->4->3


#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *odd = head, *even = head->next, *evenHead = even, *oddHead=head;
        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;
            if(odd->next){
                evenHead = odd->next;
                evenHead->next = even;
                even = even->next->next;
            }
        }

        odd = oddHead->next;
        even = evenHead;
        ListNode* curr;
        curr = head;
        while(odd && even){
            curr->next = even;
            even = even->next;
            curr = curr->next;

            curr->next = odd;
            odd = odd->next;
            curr = curr->next;
        }
        return;

    }
};

int main(){
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    


    string st;
    while (getline(cin, st) && !st.empty()) {
        int val = stoi(st);
        ListNode* node = new ListNode(val);
        curr->next = node;
        curr = curr->next;
    }

    cout << "The original list is: ";

    head = head->next;
    Solution s;
    s.reorderList(head);

    curr = head;
    while(curr){
        cout << curr->val << " ";
        curr = curr->next;
    }
}