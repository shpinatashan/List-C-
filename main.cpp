#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>



template <typename T>
class List
{
    public:
        List( T value) { first_node = Node<T>( value); }
        ~List();
        Node* operator[](int n);

    private:
        Node* first_node;
        int size = 1;
};

List::~List()
{
    for ( Node* i = first_node; size != 0; i = next_i) {
        Node *next_i = i->get_next();
        i.remove();
    }
}

template <typename T>
class Node : public List
{
private:
    T data;
    Node* next = this;
    Node* prev = this;

public:
    Node (int value) : data( value) { }
    Node* insert (int value);
    void remove();
    void  print( int direction);
    ~Node();

    void set_next( Node* node_ptr) { next = node; }
    void set_prev( Node* node_ptr) { prev = node; }
    Node* get_next() { return next; }
    Node* get_prev() { return prev; }
};

Node* Node::operator[](int n)
{
    Node* returned_node = this;
    for (int i = 0; i < n; i++)
        returned_node = returned_node.get_next();
    return returned_node;
}

Node* Node::insert( int value)
{
    size++;
    new_n = new Node( value);
    new_n->set_next( next);
    new_n->set_prev( this);
    next = new_n;
    new_n->get_next()->set_prev( new_n);
    return new_n;
}

void Node::print( int direction)
{
    Node* current_node = this;
    for ( int i = 0; i < size; i++)
    {
        std::cout << value << "\n";
        if ( direction == 1)
            next.print( 1);
        else
            prev.print( 0);
    }
}

Node::remove()
{
    prev.set_next( next);
    next.set_prev( prev);
    size--;
    delete this;
}


int main()
{
    List<int> my_list( 7);
    return 0;
}
