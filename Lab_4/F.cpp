#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (!root) return new Node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

int countMiniTriangles(Node* root) {
    if (!root) return 0;

    int count = 0;
    // Если у узла есть оба дочерних узла, это мини-треугольник
    if (root->left && root->right) 
        count = 1;

    // Подсчитываем мини-треугольники для левого и правого поддеревьев
    return count + countMiniTriangles(root->left) + countMiniTriangles(root->right);
}

int main() {
    int N;
    cin >> N;

    Node* root = nullptr;
    for (int i = 0; i < N; ++i) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    cout << countMiniTriangles(root) << endl;
    return 0;
}




