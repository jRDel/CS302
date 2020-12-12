#define V 5
#include<iostream>
#include <vector>
#include <climits>
#include  <algorithm>
using namespace std;

void RBTree::fixViolation(Node * & root, Node * &pt)
{
    Node *parent_pt = NULL;
    Node * grand_parent_pt= NULL;

    while ((pt != root) && (pt->color != BLACK) && 
           (pt->parent->color == RED)) 
    { 
  
        parent_pt = pt->parent; 
        grand_parent_pt = pt->parent->parent; 
  
        /*  Case : A 
            Parent of pt is left child  
            of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left) 
        { 
  
            Node *uncle_pt = grand_parent_pt->right; 
  
            /* Case : 1 
               The uncle of pt is also red 
               Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color ==  
                                                   RED) 
            { 
                grand_parent_pt->color = RED; 
                parent_pt->color = BLACK; 
                uncle_pt->color = BLACK; 
                pt = grand_parent_pt; 
            } 
  
            else
            { 
                /* Case : 2 
                   pt is right child of its parent 
                   Left-rotation required */
                if (pt == parent_pt->right) 
                { 
                    rotateLeft(root, parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
  
                /* Case : 3 
                   pt is left child of its parent 
                   Right-rotation required */
                rotateRight(root, grand_parent_pt); 
                swap(parent_pt->color,  
                           grand_parent_pt->color); 
                pt = parent_pt; 
            } 
        } 
  
        /* Case : B 
           Parent of pt is right child  
           of Grand-parent of pt */
        else
        { 
            Node *uncle_pt = grand_parent_pt->left; 
  
            /*  Case : 1 
                The uncle of pt is also red 
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color ==  
                                                    RED)) 
            { 
                grand_parent_pt->color = RED; 
                parent_pt->color = BLACK; 
                uncle_pt->color = BLACK; 
                pt = grand_parent_pt; 
            } 
            else
            { 
                /* Case : 2 
                   pt is left child of its parent 
                   Right-rotation required */
                if (pt == parent_pt->left) 
                { 
                    rotateRight(root, parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
  
                /* Case : 3 
                   pt is right child of its parent 
                   Left-rotation required */
                rotateLeft(root, grand_parent_pt); 
                swap(parent_pt->color,  
                         grand_parent_pt->color); 
                pt = parent_pt; 
            } 
        } 
    } 
  
    root->color = BLACK; 
} 

/*The role of fixViolation is to consider many of the violations that may occur when you insert new nodes into a rb tree. Some examples are no two red nodes in a row, and the fixviolation
method considers this and will apply rotations and color flips depending on the type of violation and the placement of parent, grandparent, and uncle nodes.*/