#include<iostream>
using namespace std;

struct node
{
    int value;
    node* next;
};
struct Queue
{
    node* head;
    node* tail;
    void push();
    void pop();
    void top();
    void duyet();
};
node* makeNode(int x)
{
    node* newNode=new node();
    newNode->next=NULL;
    newNode->value=x;
    return newNode;
}

