#include <bits/stdc++.h>
using namespace std;
int read()
{
  char cha;
  int x=0,flag=1;
  while(cha=getchar())
     if(cha!=' '&&cha!='\n') break;
   if(cha!='-')
       x=x*10+cha-48;
   else flag=-1;
  while(cha=getchar())
    {
     if(cha==' '||cha=='\n') break;
      x=x*10+cha-48;
    }
    return x*flag;
}
class LeftistNode
{
public:
    int element;
    LeftistNode *left;
    LeftistNode *right;
    int dist;
    LeftistNode(int & element, LeftistNode *lt = NULL,
                LeftistNode *rt = NULL, int np = 0)
    {
        this->element = element;
        right = rt;
        left = lt,
        dist = np;
    }
};

class LeftistHeap
{
public:
    LeftistHeap();
    LeftistHeap(LeftistHeap &rhs);
    ~LeftistHeap();
    bool isEmpty();
    bool isFull();
    int &findMin();
    void Insert(int &x);
    void deleteMin();
    void deleteMin(int &minItem);
    void makeEmpty();
    void Merge(LeftistHeap &rhs);
    LeftistHeap & operator =(LeftistHeap &rhs);
public:
    LeftistNode *root;
    LeftistNode *Merge(LeftistNode *h1,
                       LeftistNode *h2);
    LeftistNode *Merge1(LeftistNode *h1,
                        LeftistNode *h2);
    void swapChildren(LeftistNode * t);
    void reclaimMemory(LeftistNode * t);
    LeftistNode *clone(LeftistNode *t);
};

LeftistHeap::LeftistHeap()
{
    root = NULL;
}

LeftistHeap::LeftistHeap(LeftistHeap &rhs)
{
    root = NULL;
    *this = rhs;
}

LeftistHeap::~LeftistHeap()
{
    makeEmpty( );
}

void LeftistHeap::Merge(LeftistHeap &rhs)
{
    if (this == &rhs)
        return;
    root = Merge(root, rhs.root);
    rhs.root = NULL;
}

LeftistNode *LeftistHeap::Merge(LeftistNode * h1,
                                LeftistNode * h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;
    if (h1->element < h2->element)
        return Merge1(h1, h2);
    else
        return Merge1(h2, h1);
}
LeftistNode *LeftistHeap::Merge1(LeftistNode * h1,
                                 LeftistNode * h2)
{
    if (h1->left == NULL)
        h1->left = h2;
    else
    {
        h1->right = Merge(h1->right, h2);
        if (h1->left->dist < h1->right->dist)
            swapChildren(h1);
        h1->dist = h1->right->dist + 1;
    }
    return h1;
}

void LeftistHeap::swapChildren(LeftistNode * t)
{
    LeftistNode *tmp = t->left;
    t->left = t->right;
    t->right = tmp;
}

void LeftistHeap::Insert(int &x)
{
    root = Merge(new LeftistNode(x), root);
}

/* Find the smallest item in the priority queue.
Return the smallest item, or throw Underflow if empty.*/
int &LeftistHeap::findMin()
{
    return root->element;
}

/* Remove the smallest item from the priority queue.
Throws Underflow if empty.*/
void LeftistHeap::deleteMin()
{
    LeftistNode *oldRoot = root;
    root = Merge(root->left, root->right);
    delete oldRoot;
}

/* Remove the smallest item from the priority queue.
Pass back the smallest item, or throw Underflow if empty.*/
void LeftistHeap::deleteMin(int &minItem)
{
    if (isEmpty())
    {
        cout<<"Heap is Empty"<<endl;
        return;
    }
    minItem = findMin();
    deleteMin();
}

/* Test if the priority queue is logically empty.
 Returns true if empty, false otherwise*/
bool LeftistHeap::isEmpty()
{
    return root == NULL;
}

/* Test if the priority queue is logically full.
 Returns false in this implementation.*/
bool LeftistHeap::isFull()
{
    return false;
}

// Make the priority queue logically empty
void LeftistHeap::makeEmpty()
{
    reclaimMemory(root);
    root = NULL;
}

// Deep copy
LeftistHeap &LeftistHeap::operator =(LeftistHeap & rhs)
{
    if (this != &rhs)
    {
        makeEmpty();
        root = clone(rhs.root);
    }
    return *this;
}

// Internal method to make the tree empty.
void LeftistHeap::reclaimMemory(LeftistNode * t)
{
    if (t != NULL)
    {
        reclaimMemory(t->left);
        reclaimMemory(t->right);
        delete t;
    }
}

// Internal method to clone subtree.
LeftistNode *LeftistHeap::clone(LeftistNode * t)
{
    if (t == NULL)
        return NULL;
    else
        return new LeftistNode(t->element, clone(t->left),
                               clone(t->right), t->dist);
}

//Driver program
int main()
{
    LeftistHeap h[100005];
    LeftistHeap h1;
    LeftistHeap h2;
    int x;
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        char s[10];
        scanf("%s",s);
        if(s[0]=='i')
        {
            int num,add;
            num=read();
            add=read();
            h[num].Insert(add);
        }
        else if(s[0]=='l')
        {
            int num;
            num=read();
            if(h[num].root==NULL)
            {
                puts("NULL");
            }
            else
            printf("%d\n",h[num].findMin());
        }
        else if(s[0]=='j')
        {
            int num1,num2;
            num1=read();
            num2=read();
            h[num1].Merge(h[num2]);
            h[num2].makeEmpty();
        }
        else
        {
            int num;
            num=read();
            if(h[num].root==NULL)
            {
                puts("NULL");
            }
            else
            {
            h[num].deleteMin(x);
            printf("%d\n",x);
            }
        }
    }
    return 0;
}
