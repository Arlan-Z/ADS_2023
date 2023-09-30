#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int value) : val(value), next(NULL) {}
};

int findMaxSum(Node* head) {
    if (head == NULL)
        return 0;

    int sum = head->val;
    int max_sum = head->val;

    head = head->next;
    while (head != NULL) {
        sum = max(head->val, sum + head->val);
        max_sum = max(max_sum, sum);
        head = head->next;
    }

    return max_sum;
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        Node* cur = new Node(x);

        if (head == NULL) {
            head = tail = cur;
        } else {
            tail->next = cur;
            tail = cur;
        }
    }

    cout << findMaxSum(head) << "\n";

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
