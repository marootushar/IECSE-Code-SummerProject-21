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
    void rotate(int k){
        k = k%count;
        if(k==0|| head==NULL){
            return;
        }
        Node *p1 = head, *p2=head;
        while(k--){
            p2 = p2->next;
        }
        while(p2->next){
            p1=p1->next;
            p2=p2->next;
        }
        Node *temp = p1->next;
        p1->next=NULL;
        tail=p1;
        p2->next=head;
        head=temp;
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
            ll.print();
        }
        else{
            cin>>y;
            ll.rotate(y);
        }
    }
}