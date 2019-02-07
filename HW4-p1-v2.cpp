#include <iostream>
#include <bits/stdc++.h>


using namespace std;

struct node{
    int data;
    node* left_ptr = NULL;
    node* right_ptr = NULL;
};

void swap_left(node* A){
    int temp = A->left_ptr->data;
    A->left_ptr->data = A->data;
    A->data = temp;
}

void swap_right(node* A){
    int temp = A->right_ptr->data;
    A->right_ptr->data = A->data;
    A->data = temp;
}

void reorder(node* A, int &count){
    if(A!=NULL){
        if(A->left_ptr!=NULL) {
            if (A->data < A->left_ptr->data) {
                swap_left(A);
                count++;
                reorder(A->left_ptr, count);
            }
            else{
                reorder(A->left_ptr, count);
            }
        }
        if(A->right_ptr!=NULL) {
            if (A->data < A->right_ptr->data) {
                swap_right(A);
                count++;
                reorder(A->right_ptr, count);
            }
            else{
                reorder(A->right_ptr, count);
            }
        }
    }
}

void Tree_to_Heap(node* &A){
    int count = 0;
    reorder(A, count);
    if(count > 0){
        Tree_to_Heap(A);
    }
}

bool isLeaf(node* node)
{
    return (node->left_ptr == NULL && node->right_ptr == NULL);
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printRootToLeafPath(struct node* node, int path[], int path_Length)
{
    if (node==NULL)
        return;

    path[path_Length] = node->data;
    path_Length++;

    if (isLeaf(node))
    {
        printArray(path, path_Length);
    }
    else
    {
        printRootToLeafPath(node->left_ptr, path, path_Length);
        printRootToLeafPath(node->right_ptr, path, path_Length);
    }
}

void printRootToLeafPaths(struct node* node)
{
    int path[100];
    printRootToLeafPath(node, path, 0);
}

int main() {
    node* root = new node;
    root->data = 7;
    root->left_ptr = new node;
    root->left_ptr->data = 3;
    root->right_ptr = new node;
    root->right_ptr->data = 5;
    root->left_ptr->left_ptr = new node;
    root->left_ptr->left_ptr->data = 13;
    root->left_ptr->right_ptr = new node;
    root->left_ptr->right_ptr->data = 15;
    printRootToLeafPaths(root);
    Tree_to_Heap(root);
    printRootToLeafPaths(root);

    return 0;
}

