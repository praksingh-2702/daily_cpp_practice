#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}
Node* insertAtHead(Node* head,int value){
    Node* newNode=new Node(value);
    newNode->next=head;
    return newNode;
}
Node* insertAtTail(Node * head, int value){
    Node* newNode=new Node(value);
    if(head==nullptr){
        return newNode;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
         temp=temp->next;
    }
    temp->next=newNode;
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
    temp->next=newNode;
    return head;
}
Node* insertBeforeValue(Node* head, int value, int newValue){
    if(head==nullptr){
        return head;
    }
    if(head->data==value){
        return insertAtHead(head,newValue);
    }
    Node* newNode=new Node(newValue);
    Node* temp=head;
    while(temp->next!=nullptr && temp->next->data!=value){
        temp=temp->next;
    }
    if(temp->next==nullptr){
        return head;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}
Node* deleteAtHead(Node* head){
    if(head==nullptr){
        return head;
    }
    Node* temp=head;
    head=head->next;
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
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
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
    while(temp!=nullptr && cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp==nullptr || temp->next==nullptr){
        return head;
    }
    Node* nodeToDelete=temp->next;
    temp->next=nodeToDelete->next;
    delete nodeToDelete;
    return head;
}
Node* deleteByValue(Node* head, int value){
    if(head == nullptr){
    return head;
    }
    if(head->data == value){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
    }
    Node* temp=head;
    while(temp->next!=nullptr && temp->next->data!=value){
        temp=temp->next;
    }
    if(temp->next==nullptr){
        return head;
    }
    Node* nodeToDelete=temp->next;
    temp->next=nodeToDelete->next;
    delete nodeToDelete;
    return head;
}
Node *convertarraytoLL(vector<int>& nums,int n){
    Node* head=new Node(nums[0]);
    Node* mover=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(nums[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
int main(){
    vector<int> nums={10,20,30,40};
    int n=nums.size();
    Node* head=convertarraytoLL(nums,n);
    head=insertAtHead(head,5);
    head=insertAtTail(head,50);
    head=insertAtPos(head,2,25);
    head=insertBeforeValue(head,30,28);
    head=deleteAtHead(head);
    head=deleteAtTail(head);
    head=deleteAtPos(head,2);
    head=deleteByValue(head,20);
    printLL(head);
    return 0;
}
