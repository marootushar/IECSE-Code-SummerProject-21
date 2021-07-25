#include <bits/stdc++.h>
#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

class linkedList
{
private:
    Node *head;
    Node *tail;
    int count=0;
public:
    linkedList()
    {
        head=NULL;
    }
    void addNode(int data)
    {
        Node* node=new Node;
        node->data=data;
        node->next=NULL;
        if(!head)
        {
            head=node;
            tail=node;
        }
        else
        {
            tail->next = node;
            tail=tail->next;
        }
        count++;
    }
    void print()
    {
        Node* temp=head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    Node* reverse(Node *begin){
        Node *prev=begin, *curr=begin->next;
        prev->next=NULL;
        while(curr){
            Node *nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void modify(){
        Node *slow=head, *fast=head->next;
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return;
        }
        while(fast){
            fast=fast->next;
            if(fast){
                slow=slow->next;
                fast=fast->next;
            }
        }
        Node *half = reverse(slow->next);
        Node *t1=head, *t2;
        bool b = 1;
        while(t1){
            if(b){
                t2=t1->next;
                t1->next=half;
                if(half)
                half=half->next;
            }
            else{
                t1->next=t2;
            }
            if(t1->next==NULL){
                tail=t1;
            }
            t1 = t1->next;
            b = !b;
        }
    }
};

int main(){

    int n;
    cin>>n;
    int x, y;
    linkedList ll;
    while(n--){
        cin>>x;
        if(x==1){
            cin>>y;
            ll.addNode(y);
        }
        else if(x==2){
            ll.modify();
        }
        else{
            ll.print();
        }
    }
}