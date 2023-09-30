

#include <iostream>

using namespace std;


class Node
{
    public:
        string data;
        Node* next;
    
    public:
        Node(string data)
        {
            this -> data = data;
            this -> next = NULL;
        }
        
       
};

class OneLinkedList
{
    public:
        Node* head, * tail;
    
    public:
        OneLinkedList()
        {
            this -> head = this -> tail = NULL;
        }
        
        ~OneLinkedList()
        {
            while(head != NULL) pop_front();
        }
        
        void pop_front()
        {
            if(head == NULL) return;
            
            if(head == tail) {
                delete tail;
                head = tail = NULL;
                return;
            }
            
            Node* node = head;
            head = node -> next;
            delete node;
        }
        
        void push_back(string data)
        {
            Node* node = new Node(data);
            if(head == NULL) head = node;
            if(tail != NULL) tail -> next = node;
            tail = node;
        }
        
        void push_front(string data)
        {
            Node* node = new Node(data);
            node -> next = head;
            head = node;
            if(tail == NULL) tail = node;
        }
        
        void pop_back()
        {
            if(tail == NULL) return;
            if(head == tail) 
            {
                delete tail;
                head = tail = NULL;
                return;
            }
            
            Node* node = head;
            for(; node -> next != tail; node = node -> next);
            node -> next = NULL;
            delete tail;
            tail = node;
        }
        
        Node* getAt(int k)
        {
            if(k < 0) return NULL;
            
            Node* node = head;
            int n = 0;
            while(node && n != k && node -> next)
            {
                node = node -> next;
                n++;
            }
            return(n == k) ? node : NULL;
        }
        
        void insert(int k, string data)
        {
            Node* left = getAt(k);
            if (left == NULL) return;
            
            Node* right = left -> next;
            Node* node = new Node(data);
            
            left -> next = node;
            node -> next = right;
            if(right == NULL) tail = node;
        }
    
        void erase(int k)
        {
            if(k < 0) return;
            if(k == 0) 
            {
                pop_front();
                return;
            }
            
            Node* left = getAt(k - 1);
            Node* node = left -> next;
            if(node == NULL) return;
            Node* right = node -> next;
            
            left -> next = right;
            if(node == tail) tail = left;
            delete node;
        }
        
        bool isEmpty()
        {
            if(head == NULL && tail == NULL) return true;
            return false;
        }
        
        string front()
        {
            return head -> data;
        }
        
        string back()
        {
            return tail -> data;
        }
};



int main()
{
    string s;
    string name;
    OneLinkedList List;
    while(s != "exit")
    {
        cin >> s;
        
            if(s ==  "add_front")
            {
                cin >> name;
                List.push_front(name);
                cout << "ok" << endl;
            }
            
            if(s == "add_back")
            {
                cin >> name;
                List.push_back(name);
                cout << "ok" << endl;
            }
            
            if(s == "erase_front")
            {
                if(List.isEmpty())
                {
                    cout << "error" << endl;
                    continue;
                }
                name = List.front();
                List.pop_front();
                cout << name << endl;
            }
            
            if(s ==  "erase_back")
            {
                if(List.isEmpty())
                {
                    cout << "error" << endl;
                    continue;
                }
                name = List.back();
                List.pop_back();
                cout << name << endl;
                
            }
            
            if(s ==  "front")
            {
                if(List.isEmpty())
                {
                    cout << "error" << endl;
                    continue;
                }
                cout << List.front() << endl;
                
            }
            
            if(s ==  "back")
            {
                if(List.isEmpty())
                {
                    cout << "error" << endl;
                    continue;
                }
                cout << List.back() << endl;
                
            }
            
            if(s ==  "clear")
            {
                while(!List.isEmpty())
                {
                    List.pop_front();
                }
                cout << "ok" << endl;
            }
        
    }
    cout << "goodbye" << endl;
    return 0;
}
