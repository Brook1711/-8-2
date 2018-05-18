#include<iostream>

using namespace std;
template<class T> class BiNode
{
public:
	T data;
	BiNode<T> * lch;
	BiNode<T> * rch;
	BiNode() :lch(NULL), rch(NULL) {};
};
template<class T> class BST
{
public:
	BST(T r[], int n);
	~BST();
	BiNode<T>* Search(BiNode<T>* R, T key, int &count);
	void InsertBST(BiNode<T> *&R, BiNode<T> * s);
	void Delete(BiNode<T> *& R);
	bool DeleteBST(BiNode<T> *&r, T key);
	BiNode<T> * Root;
};

template<class T>
BST<T>::BST(T r[], int n)
{
	Root = NULL;
	for (int i = 0; i < n; i++)
	{
		BiNode<T> * s = new BiNode<T>;
		s->data = r[i];
		s->lch = s->rch = NULL;
		InsertBST(Root, s);
	}
}

template<class T>
BST<T>::~BST()
{
	while (Root->lch != NULL || Root->rch != NULL)
	{
		Delete(Root);
	}
	delete Root;
}

template<class T>
BiNode<T>* BST<T>::Search(BiNode<T>* R, T key, int &count)
{
	if (R == NULL)
	{
		return NULL;
	}
	if (key == R->data)
	{
		count++;
		return R;
	}
	else if (key < R->data)
	{
		count++;
		return Search(R->lch, key, count);
	}
	else
	{
		count++;
		return Search(R->rch, key, count);
	}
}

template<class T>
void BST<T>::InsertBST(BiNode<T>*& R, BiNode<T>* s)
{
	if (R == NULL)
		R = s;
	else if (s->data < R->data)
		InsertBST(R->lch, s);
	else
		InsertBST(R->rch, s);
}

template<class T>
void BST<T>::Delete(BiNode<T>*& R)
{
	BiNode<T> *q, *s;
	if (R->lch == NULL)
	{
		q = R;
		R = R->rch;
		delete q;
	}
	else if (R->rch == NULL)
	{
		q = R;
		R = R->lch;
		delete q;
	}
	else
	{
		q = R;
		s = R->lch;
		while (s->rch != NULL)
		{
			q = s;
			s = s->rch;
		}
		R->data = s->data;
		if (q != R)
			q->rch = s->lch;
		else
			R->lch = s->lch;
		delete s;
	}
}

template<class T>
bool BST<T>::DeleteBST(BiNode<T>*& R, T key)
{
	if(R=NULL)
		return false;
	else
	{
		if (key == R->data)
		{
			Delete(R);
			return true;
		}
		else if (key<R ->data)
			return DeleteBST(R->lch, key);
		else
			return DeleteBST(R->rch, key);
	}
}

int main()
{
	int n, waiting, count(0);
	cin >> n;
	int arr[100] = { -1 };
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> waiting;
	BST<int> MyBst(arr, n);
	MyBst.Search(MyBst.Root, waiting, count);
	cout << count;
//	system("pause");
	return 0;
}