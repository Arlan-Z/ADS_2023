#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    char val;
    Node* next;
    int cnt;

    Node(char x) : val(x), next(nullptr), cnt(0) {}
};

struct LinkedList {
    Node* head;
    Node* tail;
    unordered_map<char, Node*> charMap;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void push(char x) {
        if (charMap.find(x) == charMap.end()) {
            Node* newNode = new Node(x);

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }

            charMap[x] = newNode;
        } else {
            charMap[x]->cnt++;
        }
    }

    char getFirstNonRepeatingChar() {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->cnt == 0) {
                return cur->val;
            }
            cur = cur->next;
        }
        return '-';
    }
};

int main() {
    int n;
    cin >> n;

    while (n != 0) {
        int m;
        cin >> m;
        LinkedList l;

        for (int i = 0; i < m; i++) {
            char x;
            cin >> x;
            l.push(x);
            if(l.getFirstNonRepeatingChar() == '-') 
            {
                cout << "-1" << " ";
                continue;
            }
            cout << l.getFirstNonRepeatingChar() << " ";
        }
        cout << endl;
        n--;
    }

    return 0;
}
