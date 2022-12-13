#include <iostream>
#include <string>
template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
template <typename T>
class dRing 
{
    int size_=0;  
    Node<T>* head;
    Node<T>* tail;
public:
    
    class iter;
    dRing() 
    {
        head = nullptr;
        tail = nullptr;
    }
    iter begin() { return head; }
    iter end() { return tail; }  
    class iter
    {  
        friend class dRing;
        Node<T>* n;
    public:
        iter(Node<T>*n_):n(n_){}
        iter operator++(int)
        {
            auto result = *this;
            n = n->next;
            return result;
        }
        iter operator+ (int moveBy) {
            iter temp(n);
            for (int i = 0; i < moveBy; i++) {
                temp.n = temp.n->next;
            }
            return temp;
        }
        iter operator- (int moveBy) {
            iter temp(n);
            for (int i = 0; i < moveBy; i++) {
                temp.n = temp.n->prev;
            }
            return temp;
        }
        iter operator--(int)
        {
            auto result = *this;
            n= n->prev;
            return result;
        }
        T& operator*()
        {
            return n->data;
        }
    };
    void in(T data)
    {
        Node<T>* pl = new Node<T>(data);
        pl->next = this->head;
        pl->prev = this->tail;
        if (size_ > 0) {
            this->head->prev = pl;
        }
        if (size_ > 0) {
            this->tail->next = pl;
        }
        else {
            this->head = pl;
        }
        this->tail = pl;
        size_++;
    }
    void out() 
    {
        Node<T>* current = this->head;
        for (int i = 0; i < this->size_; i++) 
        {

            std::cout << current->data << " ";
            current = current->next;
        }
    };
    void removeElement(int pos) 
    {
        if (this->size_ == 0)
        {
            throw "size=0";
        }
        else if (this->size_ == 1)
        {
            delete head;
            return;
        }
        Node<T>* current = this->head;
        for (int i = 0; i < pos; i++)
        {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        if (pos % this->size_ == 0) 
        {
            head = current->next;
        }
        else if (pos % this->size_== this->size_ - 1) 
        {
            tail = current->prev;
        }
        delete current;
        size_--;
    };
    
};
int main() 
{
    try
    {
        dRing<int> d;
        d.in(5);
        d.in(6);
        d.in(7);
        d.in(16);
        auto it = d.begin();
        for (int i = 0; i < 4; i++)
        {
            std::cout << *it++ << " ";
        }
        std::cout << std::endl;
        d.removeElement(3);
        d.out();
    }
    catch (const char* message)
    {
        std::cout << message << std::endl;
    }
    return 0;
}