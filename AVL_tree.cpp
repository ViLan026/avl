#include "AVL_tree.h"
#include <iostream>
#include "Node.h"
using namespace std;
AVL_tree::AVL_tree()
{
    // ctor
    this->root = nullptr;
}

AVL_tree::~AVL_tree()
{
    // dtor
}

bool AVL_tree::InsertNode(Node *n)
{
    Node *p = this->root;
    Node *T = nullptr;
    if (root == nullptr)
    {
        this->root = n;

        return true;
    }
    while (p != nullptr)
    {
        T = p;

        if (p->Getkey() > n->Getkey())
            p = p->Getleft();
        else if (p->Getkey() < n->Getkey())
            p = p->Getright();
        else if (p->Getkey() == n->Getkey())
            return false;
    }

    if (T->Getkey() > n->Getkey())
        T->Setleft(n);
    else
        T->Setright(n);
    n->Setparent(T);
    /////////////////////////////////////////
    Node *x = n;
    Node *parentX = x->Getparent();
    while (x != nullptr)
    {
        int bal = this->CheckBal(x);
        switch (bal)
        {
        case 0:
            break; // Can bang
        case 1:
            break; //
        case -1:
            break; //

        case 2:
            if (x->Getleft()->Getleft() != nullptr) // LEFT-LEFT
            {
                parentX = x->Getparent();
                this->RightRotate(x);
                cout << x->Getheight() << endl;
                x->Setparent(parentX);
                if (parentX != nullptr)
                    if (x->Getkey() > parentX->Getkey())
                        parentX->Setright(x);
                    else
                        parentX->Setleft(x);
            }
            else
            {
                Node *tmp = x->Getleft();
                this->LeftRotate(tmp);
                tmp->Setparent(x);
                x->Setleft(tmp);

                parentX = x->Getparent();
                this->RightRotate(x);
                x->Setparent(parentX);
                if (parentX != nullptr)
                    if (x->Getkey() > parentX->Getkey())
                        parentX->Setright(x);
                    else
                        parentX->Setleft(x);
            }
            break;
        case -2:
            Node *left = x->Getright();
            if (left->Getright()->Getheight() < left->Getleft()->Getheight()) // RIGHT-RIGHT
            {
                parentX = x->Getparent();
                this->LeftRotate(x);
                x->Setparent(parentX);
                if (parentX != nullptr)
                    if (x->Getkey() > parentX->Getkey())
                        parentX->Setright(x);
                    else
                        parentX->Setleft(x);
            }
            else // Right-left
            {
                Node *tmp = x->Getright();
                this->RightRotate(tmp);
                tmp->Setparent(x);
                x->Setright(tmp);
                cout << x->Getkey() << " " << tmp->Getkey() << endl;

                parentX = x->Getparent();
                this->LeftRotate(x);
                x->Setparent(parentX);
                if (parentX != nullptr)
                    if (x->Getkey() > parentX->Getkey())
                        parentX->Setright(x);
                    else
                        parentX->Setleft(x);
            }
            break; //
        }
        if (x->Getparent() == nullptr)
            this->root = x;
        x = x->Getparent();
    }

    return true;
}
Node *AVL_tree::InsertNode(Node *r, Node *p)
{
    if (r == nullptr)
    {
        r = p;
        return r;
    }
    if (r->Getkey() == p->Getkey())
        return nullptr;
    else if (r->Getkey() > p->Getkey())
    {
        r->Setleft(InsertNode(r->Getleft(), p));
        return r->Getleft();
    }
    else
    {
        r->Setright(InsertNode(r->Getright(), p));
        return r->Getright();
    };
    //
    /*   r->Setheight ( 1 + max(r->Getleft()->Getheight(),r->Getright()->Getheight()));


       int valBalance = r->Getleft()->Getheight() - r->Getright()->Getheight();


       if(valBalance>1&&r->Getleft()->Getkey()>p->Getkey())
           this->RightRotate(r);*/
}

void AVL_tree::InsertNodeRe(Node *p)
{
    this->root = InsertNode(this->root, p);
}
void AVL_tree::NLR(Node *r)
{
    if (r != nullptr)
    {
        cout << r->Getkey() << " ";
        NLR(r->Getleft());
        NLR(r->Getright());
    }
}

void AVL_tree::LNR(Node *r)
{
    if (r != nullptr)
    {
        LNR(r->Getleft());
        cout << r->Getkey() << " ";
        LNR(r->Getright());
    }
}

void AVL_tree::LRN(Node *r)
{
    if (r != nullptr)
    {
        LRN(r->Getleft());
        LRN(r->Getright());
        cout << r->Getkey() << " ";
    }
}

void AVL_tree::TravelNLR()
{
    NLR(this->root);
}
void AVL_tree::TravelLNR()
{
    LNR(this->root);
}
void AVL_tree::TravelLRN()
{
    LRN(this->root);
}
Node *AVL_tree::search_x(int k)
{
    Node *tmp = this->root;
    while (tmp != nullptr)
    {
        if (k == tmp->Getkey())
            return tmp;
        if (k > tmp->Getkey())
        {
            tmp = tmp->Getright();
        }
        else
            tmp = tmp->Getleft();
    }
    return nullptr;
}
void AVL_tree::deleteNode(Node *n)
{
    Node *p = n;
    if (n->Getleft() == nullptr && n->Getright() == nullptr)
    {

        if (p->Getparent()->Getleft() == p)
            p->Getparent()->Setleft(nullptr);
        else
            p->Getparent()->Setright(nullptr);
        delete n;
    }
    else
    {
        if (p->Getright() != nullptr)
        {
            p = p->Getright();
            while (p->Getleft() != nullptr) // tim so nho nhat ben phai
                p = p->Getleft();

            n->Setkey(p->Getkey());
            deleteNode(p);
        }
        else
        {
            p = p->Getleft();
            while (p->Getright() != nullptr) // tim so lon nhat ben trai
                p = p->Getright();

            n->Setkey(p->Getkey());
            deleteNode(p);
        }
    }
}
void AVL_tree::LeftRotate(Node *&P)
{
    Node *Q = P->Getright();
    Node *T = Q->Getleft();

    Q->Setleft(P);
    P->Setright(T);

    if (T != nullptr)
        T->Setparent(P);

    Q->Setparent(P->Getparent());
    P->Setparent(Q);

    P = Q;
}

void AVL_tree::RightRotate(Node *&P)
{
    Node *Q = P->Getleft();
    Node *T = Q->Getright();

    Q->Setright(P);
    P->Setleft(T);

    if (T != nullptr)
        T->Setparent(P);

    Q->Setparent(P->Getparent());
    P->Setparent(Q);

    P = Q;
}

int AVL_tree::CheckBal(Node *p)
{
    int bal = this->GetHeight(p->Getleft()) - this->GetHeight(p->Getright());
    return bal;
}
int AVL_tree::GetHeight(Node *p)
{
    if (p == nullptr)
        return 0;
    else
        return 1 + max(GetHeight(p->Getleft()), GetHeight(p->Getright()));
}
