
#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    void displayList(ListNode *head){
        ListNode *node = head;
        while(node){
            cout<<node->val<<endl;
            node = node->next;
        }
    }
    ListNode* rotateRight(ListNode* head, int n) {
        ListNode *temp=head, *pre = nullptr, *curr=head, *next, *last = nullptr;
        int count = 0;
        if (n == 0 || head == nullptr)
            return head;
        while(count < n){
            if(temp == nullptr){
              temp = head;
              n %= count;
              count = -1;
            }
            else
              temp = temp->next;
            count++;
        }

        while(temp){
            next = curr->next;
            pre = curr;
            curr = next;
            last = temp;
            temp = temp->next; 
        }
        if(pre != nullptr){
            pre->next = nullptr;
            last->next = pre == last ? nullptr: head;
        }
        head = curr != nullptr ? curr: head;
        
        return head;
    } 
};

int main(){
    Solution sl;
    ListNode *head = nullptr, *temp=nullptr;

    for(int i = 2;i > 0; i--)
        temp = temp == nullptr ? new ListNode(i) : new ListNode(i, temp); 
    head = temp; 
    head = sl.rotateRight(head, 1);
    sl.displayList(head);
}