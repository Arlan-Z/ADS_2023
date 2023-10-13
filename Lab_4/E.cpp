#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void addNode(int parentData, int childData, int position, Node* &root) {
    if (!root) {
        root = new Node(parentData); 
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->data == parentData) {
            if (position == 0) {
                current->left = new Node(childData);
            } else {
                current->right = new Node(childData);
            }
            return; 
        } else {
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
}

int maxWidth(Node* root) {
    if (!root) return 0;

    queue<Node*> q;
    q.push(root);

    int max_width = 0;

    while (!q.empty()) {
        int count = q.size(); 
        max_width = max(max_width, count);

        for (int i = 0; i < count; ++i) { 
            Node* current = q.front();
            q.pop();

            if (current->left) q.push(current->left); 
            if (current->right) q.push(current->right); 
        }
    }

    return max_width;
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        addNode(x, y, z, root);
    }

    cout << maxWidth(root) << endl;

    return 0;
}

