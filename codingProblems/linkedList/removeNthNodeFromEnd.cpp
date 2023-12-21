
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head, *pre = nullptr, *curr=head, *next;
        int count = 0;
        if (n == 0)
            return head;
        while(temp){
            temp = temp->next;
            count++;
            if(count == n)
                break;
        }
        if(count < n){
            //cout<<"Can not delete the "<<n<<" node from end, since there are only "<<count<<" nodes in list"<<endl;
            return head;
        }
        while(temp){
            next = curr->next;
            pre = curr;
            curr = next;
            temp = temp->next; 
        }
        
        if(pre == nullptr)
           head = curr->next;
        else
            pre->next = curr->next;
        delete curr;
        return head;
    } 
};

int main(){
    Solution sl;
    ListNode *head = nullptr, *temp=nullptr;

    for(int i = 10;i > 0; i--)
        temp = temp == nullptr ? new ListNode(i) : new ListNode(i, temp);  
    head = temp;
    sl.displayList(head);
    head = sl.removeNthFromEnd(head, 0);
    sl.displayList(head);
    head = sl.removeNthFromEnd(head, 12);
    sl.displayList(head);
    head = sl.removeNthFromEnd(head, 10);
    sl.displayList(head);
    head = sl.removeNthFromEnd(head, 1);
    sl.displayList(head);
    head = sl.removeNthFromEnd(head, 4);
    sl.displayList(head);
}