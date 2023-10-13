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

int main()
{
    branch *root = NULL;
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        add(a, root);
    }

    for(int i = 0; i < m; i++)
    {
        bool check = true;
        string s; cin >> s;
        branch *buf = root;
        for(int j = 0; j < s.length(); j++)
        {
            if(s[j] == 'L') buf = buf ->  left;
            else buf = buf -> right;
            if(buf == NULL)
            {
                check = false;
                break;
            }
        }
        if(check) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}
