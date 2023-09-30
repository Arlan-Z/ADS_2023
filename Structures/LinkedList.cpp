
#include <iostream>


class Node{
public:
    double data;
    Node* prev, * next;
    
public:
    Node(double data)
    {
        this -> data = data;
        this -> prev = this -> next = NULL;
    }
};


class LinkedList{
public:
    Node* head, *tail;
    
public:
    LinkedList()
    {
        head = tail = NULL;
    }
    
    ~LinkedList()
    {
        while(head != NULL)
        {
            pop_front();
        }
    }
    
    Node* push_front(double data)
    {
        Node* ptr = new Node(data);
        ptr -> next = head;
        if(head != NULL) head -> prev = ptr;
        if(tail == NULL) tail = ptr; 
        head = ptr;
        
        return ptr;
    }
    
    Node* push_back(double data)
    {
        Node* ptr = new Node(data);
        ptr -> prev = tail;
        if(tail != NULL) tail -> next = ptr;
        if(head == NULL) head = ptr;
        tail = ptr;
        
        return ptr;
    }
    
    void pop_front()
    {
        if(head == NULL) return;
        
        Node* ptr = head -> next;
        if(ptr != NULL) ptr -> prev = NULL;
        else tail = ptr;
        delete head;
        head = ptr;
    }
    
    void pop_back()
    {
        if(tail == NULL) return;
        
        Node* ptr = tail -> prev;
        if(ptr != NULL) ptr -> next = NULL;
        else head = NULL;
        
        delete tail;
        tail = ptr;
    }
    
    Node* getAt(int index)
    {
        Node* ptr = head;
        int n = 0;
        
        while(n != index)
        {
            if(ptr == NULL) return ptr;
            ptr = ptr -> next;
            n++;
        }
        
        return ptr;
    }
    
    Node* operator [] (int index)
    {
        return getAt(index);
    }
    
    Node* insert(int index, double data)
    {
        Node* right = getAt(index);
        if(right == NULL) return push_back(data);
        
        Node* left = right -> prev;
        if(left == NULL) return push_front(data);
        
        Node* ptr = new Node(data);
        
        ptr -> prev = left;
        ptr -> next = right;
        
        left -> next = ptr;
        right -> prev = ptr;
        
        return ptr;
    }
    
    void erase(int index)
    {
        Node* ptr = getAt(index);
        if(ptr == NULL) return;
        
        if(ptr -> prev == NULL) 
        {
            pop_front();
            return;
        }
        
        if(ptr -> next == NULL)
        {
            pop_back();
            return;
        }
        
        Node* left = ptr -> prev;
        Node* right = ptr -> next;
        
        left-> next = right;
        right -> prev = left;
        
        delete ptr;
    }
};

using namespace std;

int main()
{
    LinkedList list;
    
    list.push_back(1);
    list.push_back(3);
    list.push_back(5);
    list.push_back(7);
    
    list.push_front(0);

    cout << list[4] -> data<< endl;
    
    list.insert(2, -5);
    list.insert(100, 10);
    
    list.erase(0);
    
    
    
    for(Node* ptr = list.head; ptr != NULL; ptr = ptr -> next)
    {
        cout << ptr -> data << " ";
    }
    cout << endl;
    return 0;
}
