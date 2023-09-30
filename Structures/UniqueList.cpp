

#include <iostream>

using namespace std;


class Node
{
    public:
        int data;
        Node* next;
    
    public:
        Node(int data)
        {
            this -> data = data;
            this -> next = NULL;
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
        
        void push_front(int newData)
        {
            Node* buf = head;
            while(true)
            {
                if(buf == NULL) break;
                if(buf -> data == newData) return;
                buf = buf -> next;
            }
            
            Node* node = new Node(newData);
            node -> next = head;
            head = node;
            if(tail == NULL) tail = node;
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
        
};




int main()
{
    UniqueList List;
    List.push_front(1);
    List.push_front(2);
    List.push_front(4);
    List.push_front(1);
    List.push_front(4);
    
    while(!List.isEmpty())
    {
        cout<< List.front();
        List.pop_front();
        
    }
       
    return 0;
}
