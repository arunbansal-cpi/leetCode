#include<iostream>
#include<map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp = head, *prev;
        Node *newHead = NULL;
        map<Node*, Node*> cloneListMap;
        Node* newNode;

        while(temp){
            newNode = new Node(temp->val);
            if(temp == head){
                newHead = newNode;
            }
            else{
                prev->next = newNode;
            }
            cloneListMap.insert({temp, newNode});
            prev = newNode;
            temp = temp->next;
        }
        temp = head;
        while(temp){
            newNode = cloneListMap[temp];
            Node *tempRan = temp->random;
            if (newNode){
                if(tempRan)
                    newNode->random =  cloneListMap[tempRan];
                else
                    newNode->random  = NULL;
            }
            temp = temp->next;
        }
        return newHead;
    }
};


int main(){
    Solution sl; 
    int arr[5] = {7, 13, 11, 10, 1};
    Node *head = NULL, *prev;
    Node* temp;
    for(int i = 0;i<5;i++)
    {
        temp = new Node(arr[i]);
        if(head == NULL)
            head = temp;
        else
            prev->next = temp;
        prev = temp;  
    }
    Node *randArr[5] = {NULL, head, head->next->next->next->next, head->next->next, head};
    temp = head;
    for(int i = 0;i<5;i++)
    {
        temp->random = randArr[i];
        temp = temp->next;
    }
    Node *copyHead = sl.copyRandomList(head);
    temp = copyHead;
    for(int i = 0;i<5;i++)
    {
        cout<<temp<<endl;
        temp = temp->next;
    }
    temp = copyHead;
    for(int i = 0;i<5;i++)
    {
        cout<<temp->random<<endl;
        temp = temp->next;
    }
    
}