#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include "linkedList.h"
using namespace std;


Node::Node(int value) {
    data = value;
    next = NULL;
    prev = NULL;

}

Node::~Node() {
}

List::List() {
    head = NULL;
    tail = NULL;
    node_count = 0;
}

//destructor
List::~List() {
    Node *p = head;
    while (head != NULL) {
        head = head->next;
        delete p;
        p = head;
    }
}


void List::push_back(int d) {
    Node *tmp = new Node(d);
    // list empty?
    if (! head) {
        head = tmp;
        tail = tmp;
        node_count ++;
    } else {
        tail->next = tmp;
        tail = tmp;
        node_count ++;
    }
}


void List::push_front(int d) {
    Node *tmp = new Node(d);
    // list empty?
    if (! head) {
        head = tmp;
        tail = tmp;
        node_count ++;
    } else {
        tmp->next = head;
        head = tmp;
        node_count ++;
    }
}


void List::to_string() {
    Node *p = head;
    // traverse the list
    while (p != NULL) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << "\n";
}


void List::delete_last() {
    if (head == NULL) {
        return;
    } else if (head->next == NULL) {
        delete head;
        head = NULL;
        tail = NULL;
        node_count--;
    } else {
        Node *p = head;
        // list has at least two elements
        while (p->next->next != NULL) {
            p = p->next;
        }
        p->next = NULL;
        delete tail;
        tail = p;
        node_count--;
    }
}


void List::delete_first() {
    if (head == NULL) {
        return;
    } else if (head->next == NULL) {
        delete head;
        head = NULL;
        tail = NULL;
        node_count--;
    } else {
        Node *p = head;
        head = head->next;
        delete p;
        node_count--;
    }
}


bool List::contains( int x)  {
    Node *current = head;
    while (current->next != NULL){
        current = current->next;
        if (current->data == x){
            return true;
        }
    }
    return false;
}


void List::deleteNode( int x){
    Node *current = head;
    Node *prev = NULL;
        if(x == tail->data){
            List::delete_last();
            node_count -1;
        }
        else if(x == head->data){
            List::delete_first();
            node_count -1;
        }
        else{
            while(current != NULL && current->data != x){
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            node_count--;
            delete current;
        }
}


void List::insert(int index, int data){
    Node *temp = new Node(data);
    temp->data = data;
    temp->next = NULL;
    if(index == 0){
        List::push_front(data);
    }
    else{
        Node *head_ref = head;
        for(int i = 0; i < index-1; i++){ // stops before the index pos to be inserted
            head_ref = head_ref->next;
        }
        temp->next = head_ref->next;
        head_ref->next = temp;//pointer to new node
        node_count ++;
    }

}


int List::size(){
   return node_count;

}


int List::middle_node(){
    Node *tmp = head;
    int mid_count;
    if(node_count%2 != 0){
    //    node_count++;
         mid_count =  node_count / 2;
         //return mid_count;
        int i = 0;
        while(i != mid_count){
            tmp = tmp -> next;
            i++;
        }
        char info = tmp->data;
        return info;
    }
    else{
        node_count --;
        mid_count= node_count/2;
        int i = 0;
        while(i != mid_count){
            tmp = tmp -> next;
            i++;
        }
        char info = tmp->data;
        return info;
    }
    return mid_count;
}






int main() {
    List sequence;
    sequence.push_back(10);
    sequence.push_back(20);
    sequence.push_back(30);
    sequence.push_back(35);
    sequence.to_string();

    sequence.delete_first();
   // sequence.deleteNode(30);
//    sequence.deleteNode(20);

    // sequence.insert(3,50);
    // sequence.insert(3,50);
    // sequence.insert(4,60);
    // sequence.insert(4,100);
    sequence.to_string();
    sequence.delete_first();
  //  sequence.insert(0,60);


    sequence.to_string();

 //   cout << sequence.size()<<endl;
 //   cout << sequence.middle_node()<<endl;//O(n)
    return 0;

}