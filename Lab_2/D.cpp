
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

class UniqueList
{
     public:
        Node* head, * tail;
    
    public:
        UniqueList()
        {
            this -> head = this -> tail = NULL;
        }
        
        ~UniqueList()
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
        
        void push_back(double newData)
        {
            Node* buf = head;
            while(true)
            {
                if(buf == NULL) break;
                if(buf -> data == newData) return;
                buf = buf -> next;
            }
            
            Node* node = new Node(newData);
            if(head == NULL) head = node;
            if(tail != NULL) tail -> next = node;
            tail = node;
        }
        
        bool isEmpty()
        {
            if(head == NULL && tail == NULL) return true;
            return false;
        }
        
        int front()
        {
            return head -> data;
        }
        
        int size()
        {
            int count = 0;
            for(Node* ptr = head; ptr != NULL; ptr = ptr -> next)
            {
                count ++;
            }
            
            return count;
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
        
        int operator [] (int index)
        {
            return getAt(index) -> data;
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
    
    int count(int n)
    {
        int cnt = 0;
        
        for(Node* ptr = head; ptr != NULL; ptr = ptr -> next)
        {
            if(n == ptr -> data) cnt ++;
            else continue;
        }
        
        return cnt;
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
    SortedUniqueLinkedList Answer;
    UniqueList Set;
    
    int n; cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        List.insert(a);
        Set.push_back(a);
    }
    
    int max = 0;
    
    for(int i = 0; i < Set.size(); i++)
    {
        int cnt = List.count(Set[i]);
        if(cnt > max) max = cnt;
    }
    
    for(int i = Set.size() - 1; i >= 0; i--)
    {
        int cnt = List.count(Set[i]);
        if(cnt == max) Answer.insert(Set[i]);
    }
    
    for(Node* ptr = Answer.tail; ptr != NULL; ptr = ptr -> prev)
    {
        cout << ptr -> data << " ";
    }
    
    
    return 0;
}
