#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

struct queue{
    node *head;
    node *tail;
};

void createEmpQ(queue &q) {
    q.head = NULL;
    q.tail = NULL;
}

node* createNode(int x) {
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void Push(queue &q, int x) {
    if(q.head == NULL) {
        q.head = createNode(x);
        q.tail = createNode(x);
    }
    else {
        node *p = createNode(x);
        q.tail->next = p;
        q.tail = p;
    }
}

void Pop(queue &q) {
    if (q.head == NULL)
        return;
    node* tmp = q.head;
    q.head = tmp->next;
    delete tmp;
}

int top(queue q) {
    return q.head->data;
}

void Duyet(queue q) {
    while(q.head != NULL) {
        cout << q.head->data << " ";
        q.head = q.head->next;
    }
    cout << endl;
}

int main() {
    queue q;
    createEmpQ(q);
    for (int i = 1; i < 6; i++) {
        Push(q, i);
    }
    // cout << top(q) << endl;
    Duyet(q);
    // Pop(q);
    // Duyet(q);
}