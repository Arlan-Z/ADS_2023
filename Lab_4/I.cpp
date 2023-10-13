#include <iostream>
using namespace std;

struct Node {
    int key, count;
    Node *left, *right;

    Node(int key) : key(key), count(1), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        root->count++;

    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (--root->count > 0) return root;

        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->count = temp->count;
        temp->count = 1;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

int getCount(Node* root, int key) {
    if (root == NULL) return 0;

    if (key < root->key) 
        return getCount(root->left, key); 
    else if (key > root->key)
        return getCount(root->right, key);

    return root->count;
}

int main() {
    int Q, value;
    string query;
    Node* root = NULL;

    cin >> Q;
    while (Q--) {
        cin >> query;
        if (query == "insert") {
            cin >> value;
            root = insert(root, value);
        }
        else if (query == "delete") {
            cin >> value;
            root = deleteNode(root, value);
        }
        else if (query == "cnt") {
            cin >> value;
            cout << getCount(root, value) << endl;
        }
    }

    return 0;
}



