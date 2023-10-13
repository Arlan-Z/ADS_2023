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

if (NULL == aBranch) return; 

cout << aBranch->data << endl; 

print(aBranch->left); 

print(aBranch->right);

}

int count(branch*& root)
{
    if(!root) return 0;
    return 1 + count(root -> right) + count(root -> left);
}

int main()
{
    int n; cin >> n;
    branch *root = NULL;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        add(a, root);
    }
    int f; cin >> f;
    branch *buf = root;
    //print(root);
    while(buf != NULL && buf -> data != f)
    {
        if(buf -> data > f) buf = buf -> left;
        else buf = buf -> right;
    }
    cout << count(buf) << endl; 
    return 0;
}
