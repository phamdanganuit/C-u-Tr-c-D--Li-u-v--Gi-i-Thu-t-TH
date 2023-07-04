#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct root
{
	int data;
	root* Left;
	root* Right;
	int Height;
};
int getHeight(root* r)
{
	if (r == NULL) return 0;	
	return r->Height;
}
int max(int a, int b)
{
	if (a < b) return a;
	else return b;
	
}
root* makeRoot(int x)
{
	root* newRoot = new root();
	newRoot->data = x;
	newRoot->Left = NULL;
	newRoot->Right = NULL;
	newRoot->Height = 1;
	return newRoot;
}

void rightRotate(Node*& y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Thực hiện xoay
    x->right = y;
    y->left = T2;

    // Cập nhật chiều cao
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    y = x;
}

// Xoay sang trái tại nút x
void leftRotate(Node*& x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Thực hiện xoay
    y->left = x;
    x->right = T2;

    // Cập nhật chiều cao
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    x = y;
}
int GetBalance(root* r)
{
	if (r == NULL) return 0;
	return getHeight(r->Left) - getHeight(r->Right);
}

void addRoot(root*& root, int x)
{
	if (root == NULL) {
		root = makeRoot(x); return;
	}
	
	if (x < root->data)
			addRoot(root->Left, x);
		else if (x > root->data)
			addRoot(root->Right, x);
		else return;

	
	root->Height = max(getHeight(root->Left), getHeight(root->Right))+1;
	int balance = GetBalance(root);
	if (balance > 1 && x < root->Left->data) {
		XoayPhai(root);
		return;
	}

	if (balance > 1 && x > root->Left->data)//LR
	{
		XoayTrai(root->Left);
		XoayPhai(root); return;
	}
	if (balance<-1 && x>root->Right->data)//RR
	{
		XoayTrai(root); return;
	}
	if (balance < -1 && x < root->Right->data)//RL
	{
		XoayPhai(root->Right);
		XoayTrai(root); return;
	}


}

void DuyetNRL(root* root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		DuyetNRL(root->Right);
		DuyetNRL(root->Left);
	}
}

void DuyetNLR(root* root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		DuyetNLR(root->Left);
		DuyetNLR(root->Right);
	}
}

void duyetLNR(root* r)
{
	if (r != NULL)
	{
		duyetLNR(r->Left);
		cout << r->data << " ";
		duyetLNR(r->Right);
	}
}

void duyetRNL(root* r)
{
	if (r != NULL)
	{
		duyetRNL(r->Right);
		cout << r->data << " ";
		duyetRNL(r->Left);
	}
}

void TimMAX(root* r)
{
	if (r != NULL)
	{
		if (r->Right == NULL)
			cout << "\n Phan tu lon nhat " << r->data;
		TimMAX(r->Right);
	}
}

void ReadFile(root*& r, ifstream& input)
{
	while (true)
	{
		int x;
		input >> x;
		addRoot(r, x);
		char c;
		input >> c;
		if (input.eof())
		{
			break;
		}
	}
}

void XuatNodeLa(root* r)
{
	if (r != NULL)
	{
		if (r->Left == NULL && r->Right == NULL)
			cout << r->data << " ";

		XuatNodeLa(r->Left);
		XuatNodeLa(r->Right);
	}
}

void XuatNutCo1Node(root* r)
{
	if (r != NULL)
	{
		if ((r->Left == NULL && r->Right != NULL) || (r->Left != NULL && r->Right == NULL))
		{
			cout << r->data << " ";
		}
		XuatNutCo1Node(r->Left);
		XuatNutCo1Node(r->Right);
	}
}

void CapNhatNutTheMang(root*& X, root*& Y)//Y=r->Right
{
	if (Y->Left != NULL)
	{
		CapNhatNutTheMang(X, Y->Left);
	}
	else//Y->Left==NULL
	{
		X->data = Y->data;//Gan data X= data Y
		X = Y;//Tro X->Y
		Y = Y->Left;
	}
}



void DemSoNodeLa(root* r, int& count)
{
	if (r != NULL)
	{
		if (r->Left == NULL && r->Right == NULL)
			count++;
		DemSoNodeLa(r->Left, count);
		DemSoNodeLa(r->Right, count);
	}
}
void XoaNodeBatKi(root*& r, int x)
{
	if (r == NULL)
		return;

	if (x < r->data)
		XoaNodeBatKi(r->Left, x);
	else if (x > r->data)
		XoaNodeBatKi(r->Right, x);
	else
	{
		root* X = r;

		// Xoa 1 node 0 co la
		if (r->Left == NULL && r->Right != NULL)
		{
			r = r->Right;
		}
		else if (r->Right == NULL && r->Left != NULL)
		{
			r = r->Left;
		}
		else if (r->Right != NULL && r->Left != NULL)
		{
			CapNhatNutTheMang(X, r->Right);
		}
		delete X;
	}
}

int main()
{
	root* root = NULL;
	addRoot(root, 7);
	addRoot(root, 1);
	addRoot(root, 3);
	addRoot(root, 8);
	addRoot(root, 2);
	addRoot(root, 6);
	DuyetNLR(root);

	return 0;
}
