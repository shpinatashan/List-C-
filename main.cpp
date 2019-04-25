#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
#include <string>

template <typename T>
class Node;

template <typename T>
class List
{
public:
    List( T value) { first_node = new Node<T>( value); }
    Node<T>* operator[](int n);
    void remove( int position);
    void insert_after( int position, T value);
    void insert_back( T value) { insert_after( size - 1, value); }
    void print_node( int position);
    void Ssort();
    void print( int direction);
    int get_size() { return size; }
private:
    Node<T>* first_node;
    int size = 1;
};

template <typename T>
void List<T>::remove( int position)
{
    (*this)[position]->remove();
    size--;
}

template <typename T>
void List<T>::insert_after( int position, T value)
{
    (*this)[position]->insert( value);
    size++;
}


template <typename T>
void List<T>::Ssort()
{
    Node<T>* temp = first_node;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if ((*this)[j] -> get_data() > (*this)[j + 1]-> get_data())
            {
                temp -> set_data((*this)[j]-> get_data());
                (*this)[j]-> set_data((*this)[j + 1]-> get_data()) ;
                (*this)[j + 1]-> set_data(temp-> get_data()) ;
            }
        }
    }
}


template <typename T>
void List<T>::print( int direction)
{
    Node<T>* current_node = first_node;
    for ( int i = 0; i < size; i++) {
        current_node->print();
        if ( direction == 1)
            current_node = current_node->get_next();
        else
            current_node = current_node->get_prev();
    }
}

template <typename T>
class Node
{
private:
    T data;
    Node* next = this;
    Node* prev = this;

public:
    Node (T value) : data( value) {}
    Node* insert (T value);
    void remove();
    void print() { std::cout << data << "\n"; }
    void set_next( Node* node_ptr) { next = node_ptr; }
    void set_prev( Node* node_ptr) { prev = node_ptr; }
    Node* get_next() { return next; }
    Node* get_prev() { return prev; }
    T get_data() { return data; }
    void set_data(int val) { data = val; }
};

template <typename T>
Node<T>* List<T>::operator[](int n)
{
    Node<T>* returned_node = first_node;
    for (int i = 0; i < n; i++)
        returned_node = returned_node->get_next();
    return returned_node;
}

template <typename T>
Node<T>* Node<T>::insert( T value)
{
    Node<T>* new_n = new Node( value);
    new_n->set_next( next);
    new_n->set_prev( this);
    next = new_n;
    new_n->get_next()->set_prev( new_n);
    return new_n;
}



template <typename T>
void Node<T>::remove()
{
    prev->set_next( next);
    next->set_prev( prev);
    delete this;
}

int main()
{
   /* List<int> int_list( head);
    int_list[0]->print();
    int_list[1]->print();
    std::cout << "Size: " << int_list.get_size() << "\n\n";
   */


    //creating a list
    int number = 0, head = 0;
    printf("Number of nodes ");
    scanf("%d", &number);
    if (number <= 0)
    {
        printf("invalid input");
        return -1;
    }

    printf("Head ");
    if (scanf("%d", &head) != 1)
    {
        printf("invalid input");
        return -1;
    }

    List<int> int_list( head);

    for (int i = 1; i < number; i++)
    {
        int num = 0;
        printf("a = ");
        if (scanf("%d", &num) != 1) {
            printf("invalid input");
            return -1;
        }
        int_list.insert_after( i, num);
    }


    int_list.print( 0);
    std::cout << "Size: " << int_list.get_size() << "\n\n";
    int_list.print( 1);
    std::cout << "Size: " << int_list.get_size() << "\n\n";


    ////delete single node.Find node by index
    printf("enter the index for the node to be removed\n");
    int index;
    scanf("%d", &index);
    int_list.remove( index);
    int_list.print( 0);
    std::cout << "Size: " << int_list.get_size() << "\n\n";



    int_list.Ssort();
    int_list.print( 0);
    std::cout << "Size: " << int_list.get_size() << "\n\n";

    List<std::string> string_list( "Cherez chas otsuda v chisty pereulok");
    string_list.insert_back( "Vytechet po cheloveku vash obruzgshiy zhir");
    string_list.insert_back( "A ya vam otkrul stolko stihow shkatulok");
    string_list.insert_back( "Ya - besscennyh slov mod i tranzhir");
    string_list.print( 1);
    printf("\n\n");
    string_list.print( 0);
    return 0;
}
