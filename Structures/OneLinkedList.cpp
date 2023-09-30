

#include <iostream>

using namespace std;


class Node
{
    public:
        double data;
        Node* next;
    
    public:
        Node(double data)
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
        
        void push_back(double data)
        {
            Node* node = new Node(data);
            if(head == NULL) head = node;
            if(tail != NULL) tail -> next = node;
            tail = node;
        }
        
        void push_front(double data)
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
        
        void insert(int k, double data)
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
};

int main()
{
    // Testing
    
    /*OneLinkedList list;
    list.push_front(1);
    list.push_back(2);
    
    list.erase(1);
    list.insert(0, 5);
    list.insert(0, 2);
    
    Node* n = list.getAt(0);
    double d = (n != NULL) ? n -> data : 0;
    cout << d << endl;
    
    for(Node* node = list.head; node!=NULL; node = node -> next)
        cout << node -> data << " ";*/

    return 0;
}
