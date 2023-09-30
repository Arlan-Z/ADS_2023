#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node() : value(0), next(nullptr) {}
    Node(int x) : value(x), next(nullptr) {}
    Node(Node* next) : value(0), next(next) {}
    Node(int x, Node* next) : value(x), next(next) {}
};

Node* insert(Node* head, Node* newNode, int position) {
    if (head == nullptr) {
        head = newNode;
        if (position == 0) {
            newNode->next = head;
            head->next = nullptr;
            head = newNode;
            return head;
        }
    } else if (head != nullptr && position == 0) {
        newNode->next = head;
        head = newNode;
        return head;
    } else {
        Node* current = head;
        int index = 1;
        while (current != nullptr) {
            if (index == position) {
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
            current = current->next;
            index++;
        }
        return head;
    }
}

Node* remove(Node* head, int position) {
    if (position == 0) {
        head = head->next;
        return head;
    } else {
        int index = 0;
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr) {
            if (index == position) {
                previous->next = current->next;
            }
            previous = current;
            current = current->next;
            index++;
        }
        return head;
    }
}

Node* replace(Node* head, int position1, int position2) {
    if (position1 == position2) {
        return head;
    } else {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (index == position1) {
                head = remove(head, position1);
                head = insert(head, current, position2);
            }
            current = current->next;
            index++;
        }
        return head;
    }
}

Node* reverse(Node* head) {
    vector<int> values;
    Node* current = head;

    while (current != nullptr) {
        values.push_back(current->value);
        current = current->next;
    }

    current = head;
    int i = values.size() - 1;

    while (current != nullptr) {
        current->value = values[i];
        current = current->next;
        i--;
    }

    return head;
}

void print(Node* head) {
    if (head == nullptr) {
        cout << "-1" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
}

Node* cyclicLeft(Node* head, int x) {
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    while (x != 0) {
        current->next = head;
        head = head->next;
        current = current->next;
        x--;
    }

    current->next = nullptr;

    return head;
}

Node* cyclicRight(Node* head, int x) {
    Node* current = head;
    int length = 0;

    while (current->next != nullptr) {
        current = current->next;
        length++;
    }

    x = (length + 1) - x;

    while (x != 0) {
        current->next = head;
        head = head->next;
        current = current->next;
        x--;
    }

    current->next = nullptr;

    return head;
}

int main() {
    Node* head = nullptr;
    while (true) {
        int command;
        cin >> command;
        if (command == 0) {
            break;
        } else if (command == 1) {
            int value, position;
            cin >> value >> position;
            head = insert(head, new Node(value), position);
        } else if (command == 2) {
            int position;
            cin >> position;
            head = remove(head, position);
        } else if (command == 3) {
            print(head);
            cout << endl;
        } else if (command == 4) {
            int position1, position2;
            cin >> position1 >> position2;
            head = replace(head, position1, position2);
        } else if (command == 5) {
            head = reverse(head);
        } else if (command == 6) {
            int x;
            cin >> x;
            head = cyclicLeft(head, x);
        } else if (command == 7) {
            int x;
            cin >> x;
            head = cyclicRight(head, x);
        }
    }
    return 0;
}
