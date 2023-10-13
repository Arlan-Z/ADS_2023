#include <iostream>
#include <vector>
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

cout << aBranch->data << " "; 

print(aBranch->left); 

print(aBranch->right);

}

int count(branch*& root)
{
    if(!root) return 0;
    return 1 + count(root -> right) + count(root -> left);
}

void lvlsum(branch*& root, vector<int> &cnt, int lvl = 0)
{
    if(!root) return;
    if(cnt.size() <= lvl ) cnt.push_back(0);
    cnt[lvl] += root -> data;
    lvlsum(root -> right, cnt, lvl + 1);
    lvlsum(root -> left, cnt, lvl + 1);
}


int main()
{
    int n; cin >> n;
    branch *root = NULL;
    vector <int> cnt;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        add(a, root);
    }
    
    lvlsum(root, cnt);
    cout << cnt.size() << endl;
    for(int i = 0; i < cnt.size(); i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
