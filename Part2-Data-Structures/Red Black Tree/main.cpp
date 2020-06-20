//
//  main.cpp
//  Red Black Tree
//
//  Created by 爱学习的兔子 on 2020/6/11.
//  Copyright © 2020 Yang Shan. All rights reserved.
//

#include <vector>
#include <assert.h>
#include <stdio.h>
using namespace std;

enum E_COLOR {
    BLACK,
    RED
};

struct RBNode {
    RBNode(int k, E_COLOR c) :
        key(k), color(c), p(nullptr), left(nullptr), right(nullptr)
    { }
    RBNode(int k, E_COLOR c, RBNode * ptr1, RBNode * ptr2, RBNode * ptr3) :
        key(k), color(c), p(ptr1), left(ptr2), right(ptr3)
    { }

    int key;
    E_COLOR color;
    RBNode * p;
    RBNode * left;
    RBNode * right;
};

class RBTree {
public:
    RBTree() {
        NIL = new RBNode(0, BLACK);
        NIL->left = NIL;
        NIL->right = NIL;
        NIL->p = NIL;

        root = NIL;
    }
    ~RBTree() {
        Clear();
        delete NIL;
    }

    RBNode * FindKey(int key) {
        RBNode * pNode = root;

        while (pNode != NIL) {
            if (pNode->key < key) {
                pNode = pNode->right;
            }
            else if (pNode->key > key) {
                pNode = pNode->left;
            }
            else {
                return pNode;
            }
        }

        return nullptr;
    }

    RBNode * FindInsertPos(int key) {
        RBNode * pNode = root;
        while (pNode != NIL) {
            if (pNode->key < key) {
                if (pNode->right == NIL) {
                    return pNode;
                }
                else {
                    pNode = pNode->right;
                }
            }
            else if (pNode->key > key) {
                if (pNode->left == NIL) {
                    return pNode;
                }
                else {
                    pNode = pNode->left;
                }
            }
            else {
                return NIL;
            }
        }

        return NIL;
    }

    RBNode * FindDeletePos(int key) {
        RBNode * pNode = root;

        while (pNode != NIL) {
            if (pNode->key < key) {
                pNode = pNode->right;
            }
            else if (pNode->key > key) {
                pNode = pNode->left;
            }
            else {
                return pNode;
            }
        }

        return NIL;
    }

    void InsertKey(int key) {

        RBNode * pNode = FindInsertPos(key);
        if (root != NIL && pNode == NIL) {
            return;
        }
        RBNode * new_node = new RBNode(key, RED, NIL, NIL, NIL);

        if (pNode == NIL) {
            root = new_node;
        }
        else if (pNode->key < key) {
            pNode->right = new_node;
            new_node->p = pNode;
        }
        else {
            pNode->left = new_node;
            new_node->p = pNode;
        }

        InsertAdjust(new_node);
    }

    void InsertAdjust(RBNode * cur_node) {
        if (root == cur_node) {
            cur_node->color = BLACK;
            NIL->left = cur_node;
            cur_node->p = NIL;
        }
        else if (cur_node->p->color == RED) {
            RBNode * grandpa = cur_node->p->p;
            RBNode * pa = cur_node->p;
            RBNode * uncle = NIL;
            if (grandpa->left == cur_node->p) {
                uncle = grandpa->right;
                if (uncle->color == RED) {
                    pa->color = BLACK;
                    uncle->color = BLACK;
                    grandpa->color = RED;
                    InsertAdjust(grandpa);
                }
                else {
                    if (pa->right == cur_node) {
                        left_rotate(pa);
                        pa = cur_node;
                    }
                    right_rotate(grandpa);
                    grandpa->color = RED;
                    pa->color = BLACK;
                }
            }
            else {
                uncle = grandpa->left;
                if (uncle->color == RED) {
                    pa->color = BLACK;
                    uncle->color = BLACK;
                    grandpa->color = RED;
                    InsertAdjust(grandpa);
                }
                else {
                    if (pa->left == cur_node) {
                        right_rotate(pa);
                        pa = cur_node;
                    }
                    left_rotate(grandpa);
                    grandpa->color = RED;
                    pa->color = BLACK;
                }
            }
        }
    }



    RBNode * FindSuccessor(RBNode * z) {  // assume z have right tree
        assert(z->right != NIL);

        RBNode * p = z->right;
        while (p->left != NIL) {
            p = p->left;
        }
        return p;
    }

    void DeleteKey(int key) {
        RBNode * z = FindDeletePos(key);
        if (z == NIL) return ;

        RBNode * y = NIL;
        if (z->left == NIL || z->right == NIL) {
            y = z;
        }
        else {
            y = FindSuccessor(z);
            swap(y->key, z->key);
        }

        RBNode * yp = y->p;
        RBNode * ychild = y->left != NIL ? y->left : y->right;

        ychild->p = yp;
        if (yp->left == y) {
            yp->left = ychild;
        }
        else {
            yp->right = ychild;
        }

        if (yp == NIL) {
            root = ychild;
        }

        if (y->color == BLACK)
            DeleteAdjust(ychild);

        delete y;
    }

    void DeleteAdjust(RBNode *cur_node) {
        if (cur_node == root
            || cur_node->color == RED) {
            cur_node->color = BLACK;
        }
        else {
            RBNode * x = cur_node;
            RBNode * y = x->p;
            if (y->left == x) {
                RBNode * z = y->right;
                RBNode * zleft = z->left;
                RBNode * zright = z->right;

                if (z->color == RED) {
                    left_rotate(y);
                    y->color = RED;
                    z->color = BLACK;
                    DeleteAdjust(x);
                }
                else if (zleft->color == BLACK && zright->color == BLACK) {
                    z->color = RED;
                    DeleteAdjust(y);
                }
                else if (zleft->color == RED && zright->color == BLACK) {
                    right_rotate(z);
                    zleft->color = BLACK;
                    z->color = RED;
                    DeleteAdjust(x);
                }
                else {
                    left_rotate(y);
                    y->color = BLACK;
                    z->color = RED;
                    zright->color = BLACK;
                }

            }
            else {
                RBNode * z = y->left;
                RBNode * zleft = z->left;
                RBNode * zright = z->right;

                if (z->color == RED) {
                    right_rotate(y);
                    y->color = RED;
                    z->color = BLACK;
                    DeleteAdjust(x);
                }
                else if (zleft->color == BLACK && zright->color == BLACK) {
                    z->color = RED;
                    DeleteAdjust(y);
                }
                else if (zleft->color == BLACK && zright->color == RED) {
                    left_rotate(z);
                    zright->color = BLACK;
                    z->color = RED;
                    DeleteAdjust(x);
                }
                else {
                    right_rotate(y);
                    y->color = BLACK;
                    z->color = RED;
                    zleft->color = BLACK;
                }
            }
        }
    }

    void left_rotate(RBNode * x) { // y 是 x 的右孩子
        RBNode * y = x->right;
        RBNode * xp = x->p;
        RBNode * yleft = y->left;

        y->p = xp;
        if (xp->left == x) {
            xp->left = y;
        }
        else {
            xp->right = y;
        }

        y->left = x;
        x->p = y;

        x->right = yleft;
        yleft->p = x;

        if (root == x) {
            root = y;
        }
    }

    void right_rotate(RBNode * x) { // y是 x的左孩子
        RBNode * y = x->left;
        RBNode * xp = x->p;
        RBNode * yright = y->right;

        y->p = xp;
        if (xp->left == x) {
            xp->left = y;
        }
        else {
            xp->right = y;
        }

        y->right = x;
        x->p = y;
        x->left = yright;
        yright->p = x;

        if (root == x) {
            root = y;
        }
    }

    void Output(RBNode * pNode) {
        if (pNode == NIL) return;

        Output(pNode->left);
        printf("%d ", pNode->key);
        Output(pNode->right);
    }

    void Output() {
        Output(root);
    }

    void Clear(RBNode * pNode) {
        if (pNode == NIL) {
            return;
        }

        Clear(pNode->left);
        Clear(pNode->right);
        delete pNode;
    }

    void Clear() {
        Clear(root);
        root = NIL;
    }

private:
    RBNode * root;
private:
    RBNode * NIL;
};

int main(int argc, char ** argv) {
    RBTree tree;
    vector<int> vecNum = { 1, 3, 2, 4, 5, 6, 10, 2, 19, -1, 20, 50, 22 };

    
    for (int i = 0; i < vecNum.size(); ++i) {
        tree.InsertKey(vecNum[i]);
    }

    tree.Output();
    puts("");

    for (int i = 0; i < vecNum.size(); ++i) {
        tree.DeleteKey(vecNum[i]);
    }


    tree.Output();
    puts("");
    tree.DeleteKey(50);

    tree.Output();
    puts("");

    tree.InsertKey(1000);
    tree.Output();
    puts("");

    return 0;
}
