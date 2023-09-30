
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


class SortedUniqueLinkedList{
public:
    Node* head, *tail;
    
public:
    SortedUniqueLinkedList()
    {
        head = tail = NULL;
    }
    
    ~SortedUniqueLinkedList()
    {
        while(head != NULL)
        {
            pop_front();
        }
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
    
    Node* insert(double data)
    {
        if(head == NULL) return push_front(data);
        Node* right = head;
        
        while(right != NULL)
        {
            if(right -> data >= data) break;
            right = right -> next;
        }
        
        if(right == NULL) return push_back(data);
        
        Node* left = right -> prev;
        if(left == NULL) return push_front(data);
        
        Node* ptr = new Node(data);
        ptr -> next = right;
        ptr -> prev = left;
        
        right -> prev = ptr;
        left -> next = ptr;
        
        return ptr;
        
    }
    

private:
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
};

using namespace std;

int main()
{
    SortedUniqueLinkedList List;
    
    List.insert(6);
    List.insert(4);
    List.insert(1);
    List.insert(2);
    List.insert(3);
    List.insert(4);
    List.insert(10);
    List.insert(8);
    List.insert(6);
    List.insert(4);
    List.insert(1);
    List.insert(2);
    List.insert(3);
    List.insert(4);
    List.insert(10);
    List.insert(8);
    List.insert(6);
    List.insert(4);
    List.insert(1);
    List.insert(2);
    List.insert(3);
    List.insert(4);
    List.insert(10);
    List.insert(8);
    
    for(Node* ptr = List.head; ptr != NULL; ptr = ptr -> next)
    {
        cout << ptr -> data << " ";
    }
    cout << endl;
    return 0;
}
