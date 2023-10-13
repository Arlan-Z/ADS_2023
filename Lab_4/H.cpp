#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(NULL), right(NULL) {}
};


Node* insert(Node* root, int data) {
    if (!root) return new Node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}


void reverseInOrderTraversal(Node* node, int &sum) {
    if (node == NULL) return;

 
    reverseInOrderTraversal(node->right, sum);

   
    sum += node->data;
    node->data = sum;

    
    reverseInOrderTraversal(node->left, sum);
}


void collectKeysInOrder(Node* node, vector<int> &keys) {
    if (node == NULL) return;

    
    collectKeysInOrder(node->left, keys);

  
    keys.push_back(node->data);

    
    collectKeysInOrder(node->right, keys);
}

int main() {
    int N, data;
    cin >> N;

    Node* root = NULL;
    for (int i = 0; i < N; ++i) {
        cin >> data;
        root = insert(root, data);
    }

    int sum = 0;
    reverseInOrderTraversal(root, sum); 

    vector<int> keys;
    collectKeysInOrder(root, keys); 
    
    reverse(keys.begin(), keys.end());
    
    for (int key : keys) {
        cout << key << " ";
    }
    cout << endl;

    return 0;
}



