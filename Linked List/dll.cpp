#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node (int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
    Node (int data2,Node* next1, Node* prev1){
        data=data2;
        next=next1;
        prev=prev1;
    }
};
void print(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}
Node* convertarraytoDLL(const vector<int>& nums,int n){
    if(n==0) return nullptr;
    Node* head = new Node(nums[0]);
    Node* prev = head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(nums[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
Node* insertAtHead(Node* head, int value){
    Node* newNode=new Node(value);
    if(head!=nullptr){
        newNode->next=head;
        head->prev=newNode;
    }
    return newNode;
}
Node* insertAtTail(Node* head, int value){
    Node* newNode=new Node(value);
    if(head==nullptr){
        return newNode;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    return head;
}
Node* insertAtPos(Node* head, int pos, int value){
    if(pos==1){
        return insertAtHead(head,value);
    }
    Node* newNode=new Node(value);
    Node* temp=head;
    int cnt=1;
    while(temp!=nullptr && cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp==nullptr){
        return head;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next!=nullptr){
        temp->next->prev=newNode;
    }
    temp->next=newNode;
    return head;
}
Node* deleteAtHead(Node* head){
    if(head==nullptr){
        return head;
    }
    Node* temp=head;
    head=head->next;
    if(head!=nullptr){
        head->prev=nullptr;
    }
    delete temp;
    return head;
}
Node* deleteAtTail(Node* head){
    if(head==nullptr){
        return nullptr;
    }
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->prev->next=nullptr;
    delete temp;
    return head;
}
Node* deleteAtPos(Node* head, int pos){
    if(head==nullptr){
        return head;
    }
    if(pos==1){
        return deleteAtHead(head);
    }
    Node* temp=head;
    int cnt=1;
    while(temp!=nullptr && cnt<pos){
        temp=temp->next;
        cnt++;
    }
    if(temp==nullptr){
        return head;
    }
    if(temp->prev!=nullptr){
        temp->prev->next=temp->next;
    }
    if(temp->next!=nullptr){
        temp->next->prev=temp->prev;
    }
    delete temp;
    return head;
}
Node* deleteByValue(Node* head, int value){
    if(head == nullptr){
        return head;
    }
    Node* temp=head;
    while(temp!=nullptr && temp->data!=value){
        temp=temp->next;
    }
    if(temp==nullptr){
        return head;
    }
    if(temp->prev!=nullptr){
        temp->prev->next=temp->next;
    } else {
        head=temp->next;
    }
    if(temp->next!=nullptr){
        temp->next->prev=temp->prev;
    }
    delete temp;
    return head;
}
int main(){
    vector<int> nums={10,20,30,40};
    int n=nums.size();
    Node* head=convertarraytoDLL(nums,n);
    head = insertAtHead(head,5);
    head = insertAtTail(head,50);
    head = insertAtPos(head,3,15);
    head = insertAtPos(head,1,1);
    head = insertAtPos(head,7,60);
    head = deleteAtHead(head);
    head = deleteAtTail(head);
    head = deleteAtPos(head,3);
    head = deleteByValue(head,20);
    print(head);
}