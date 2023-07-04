#include <iostream>
using namespace std;
// cú pháp tạo cau trúc
struct node
{
    int data;
    node* next;
};
// Mỗi node là 1 con trỏ kiểu
// Cú pháp tạo node mới
node* makenode(int x)
{
    node* newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
// Hàm duyệt dslk

void Duyet(node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
// Hàm Đếm số node
int count(node* head)
{
    int dem = 0;
    while (head != NULL)
    {
        dem++;
        head = head->next;
    }
    return dem;
}
// Hàm thêm 1 node mới vào đầu ds
void pushFront(node*& head, int x)
{
    node* newNode = makenode(x);
    newNode->next = head;
    head = newNode;
}
// Ham them 1 node moi vao cuoi ds
void pushback(node*& head, int x)
{
    node* tmp = head;
    node* newNode = makenode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->next = NULL;
}
// Xoa Nut o Dau ds
void popFront(node*& head)
{
    if (head == NULL)
        return;
    node* tmp = head;
    head = tmp->next;
    delete tmp;
}
// Xoa Phan tu cuoi mang
void popBack(node*& head)
{
    if (head == NULL) // th khong co phan tu nao trong ds
    {
        return;
    }
    node* tmp = head;
    // truong hop co 1 phan tu
    if (tmp->next == NULL)
    {
        head = NULL;
        delete tmp;
        return;
    }
    // truong hop co nhieu pt

    while (tmp->next->next != NULL) //
    {
        tmp = tmp->next;
    }
    node* last = new node();
    last = tmp->next;
    tmp->next = NULL;

    delete last;
}

// Xoa node o giua ds
void erase(node*& head, int k) // k la vi tri can xoa
{
    int n = count(head);
    if (k <= 0 || k > n)
        return;
    node* tmp = head;
    if (k == 1)
    {
        tmp->next = NULL;
        head = NULL;
        delete tmp;
    }
    if (k == n)
    {
        while (tmp->next->next != 0)
        {
            tmp = tmp->next;
        }
        node* last = tmp->next;
        tmp->next = NULL;
        delete last;
    }
    if (k > 1 && k < n)
    {
        for (int i = 0; i < k - 2; i++)
        {
            tmp = tmp->next;
        }
        node* popNode = tmp->next;
        tmp->next = popNode->next;
        delete popNode;
    }
}
//Them 1 not o giua ds

void push(node*& head, int x, int k)
{
    if (k <= 0 || k > count(head))
    {
        return;
    }
    if (k == 1)
    {
        pushFront(head, x);
    }
    if (k == count(head))
    {
        pushback(head, x);
    }
    if (k > 1 && k < count(head))
    {
        node* newNode = makenode(x);
        node* tmp = head;
        for (int i = 0; i < k - 1; i++)
        {
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }

}

//Tao Stack

void PUSH(node *&top,int x)
{   
    node *newNode=makenode(x);
    newNode->next=top;
    top=newNode;

}
int main()
{
    node* head = NULL;
    int lc = 0;
    while (1)
    {
        cout << "----------------------------------------------------------\n";
        cout << "-------------------MENU DIEU KHIEN-----------------------\n";
        cout << "1:PushFrontn\n";
        cout << "2:PushBack\n";
        cout << "3:Push\n";
        cout << "4:PopFront\n";
        cout << "5:PopBack\n";
        cout << "6:Erase\n";
        cout << "7:Duyet!\n";
        cout << "8:Thoat!\n";
        cout << "-------------------------------------------------------------\n";
        cout << "Nhap Lua Chon ";
        cin >> lc;
        if (lc == 1)
        {
            int x;
            cout << "\n Nhap Gia Tri Can them ";
            cin >> x;
            pushFront(head, x);
        }
        else if (lc == 2)
        {
            int x;
            cout << "\n Nhap Gia Tri Can them ";
            cin >> x;
            pushback(head, x);
        }
        else if (lc == 3)
        {
            int x;
            cout << "\n Nhap Gia Tri Can them ";
            cin >> x;
            int k;
            cout << "\n Vi tri can chen "; cin >> k;
            push(head, x, k);
        }
        else if (lc == 4)
        {
            popFront(head);
        }
        else if (lc == 5)
        {
            popBack(head);
        }
        else if (lc == 6)
        {
            int k;
            cout << "\nNhap vi tri can xoa "; cin >> k;
            erase(head, k);
        }
        else if (lc == 7)
        {
            cout << endl;
            Duyet(head);
        }
        else
        {
            break;
        }
    }
}
