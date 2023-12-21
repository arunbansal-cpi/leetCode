#include<iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *current = head, *prev,  *next;
        ListNode *reverseEnd = nullptr, *reverseEndBackup = current;
        int count = 0;
        while(current){
            next = current->next;
            current->next = prev;
            count++;
            if(count == k){
                if(reverseEnd != nullptr)
                    reverseEnd->next = current;
                else{
                    head = current;
                }
                reverseEnd = reverseEndBackup;
                reverseEndBackup = next;
                prev = nullptr;
                count = 0;
            }
            else
                prev = current;
            current = next;     
        }
        if(count != k){
            current = prev;
            prev = nullptr;
            while(current){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            if(reverseEnd)
                reverseEnd->next = prev;
        }
        return head;
    }
};

int main(){
    Solution sl; 
    ListNode *head = nullptr;
    ListNode* temp = nullptr;
    for(int i = 11;i >0;i--)
         temp = temp == nullptr ? new ListNode(i) : new ListNode(i, temp); 
    head = temp;
    head = sl.reverseKGroup(head, 4);
    temp = head;
    for(int i = 11;i >0;i--){
        cout<<temp->val;
        temp = temp->next;
    }
}