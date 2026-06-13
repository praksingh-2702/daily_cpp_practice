#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyNode = new ListNode(-1);
    ListNode* current = dummyNode;

    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry) {
        int sum = carry;

        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    return dummyNode->next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        head = head->next;
    }
    cout << endl;
}

int main() {
    // 342
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // 465
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}


//Result: 708