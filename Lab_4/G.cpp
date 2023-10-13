#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int data) {
    if (!root) return new Node(data);

    if (data == root->data) 
        return root;

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

int height(Node* node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int diameter(Node* root, int& res) {
    if (!root) return 0;

    int left_height = diameter(root->left, res);
    int right_height = diameter(root->right, res);

    res = max(res, left_height + right_height + 1);

    return 1 + max(left_height, right_height);
}

int main() {
    int N;
    cin >> N;

    Node* root = NULL;
    for (int i = 0; i < N; ++i) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    int res = 0;
    diameter(root, res);
    cout << res << endl;
    return 0;
}



