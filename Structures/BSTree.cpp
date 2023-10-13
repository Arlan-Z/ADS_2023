#include <iostream>

using namespace std;

struct branch
{
  int data;
  branch *left, *right;
};

void add(int data, branch*& root)
{
    if(!root)
    {
        root = new branch;
        root -> data = data;
        root -> left = NULL;
        root -> right = NULL;
    }
    else
    {
        if(root -> data > data)
        {
            add(data, root -> left);
        }
        else
        {
            add(data, root -> right);
        }
    }
}

void print(branch*& aBranch)

{

if (NULL == aBranch) return; //Если дерева нет, выходим

cout << aBranch->data << endl; //Посетили узел

print(aBranch->left); //Обошли левое поддерево

print(aBranch->right); //Обошли правое поддерево

}

int main()
{
    branch *root = NULL;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        add(a, root);
    }
    
    print(root);
    return 0;
}
