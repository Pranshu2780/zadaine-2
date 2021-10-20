#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int d)
    {
        this->data = d;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = nullptr;
    }

    void insert(int data)
    {
        if (root == nullptr)
        {
            root = new Node(data);
            return;
        }
        Node *temp = root;
        while (true)
        {
            if (temp->data >= data)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new Node(data);
                    return;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = new Node(data);
                    return;
                }
                temp = temp->right;
            }
        }
    }

    bool searchRec(int d , Node* temp)
    {
        if (temp != nullptr)
        {
            inorder(temp->left);
            if(temp->data == d)
                return true;
            inorder(temp->right);
        }
        return false;
    }

    bool search(int data)
    {
        // if(root == nullptr)
        //     return false;
        // Node *temp = root;
        // while(true)
        // {
        //     if(temp == nullptr)
        //         return false;
        //     else if(temp->data == data)
        //         return true;
        //     else if(data <= temp->data)
        //         temp = temp->left;
        //     else
        //         temp = temp->right;
        // }
        // return false;
        return searchRec(data,root);
    }

    void inorder(Node *temp)
    {
        if (temp != nullptr)
        {
            inorder(temp->left);
            cout << temp->data << " ";
            inorder(temp->right);
        }
    }
    void preorder(Node *temp)
    {
        if (temp != nullptr)
        {
            cout << temp->data << " ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }

    void show()
    {
        // inorder(root);
        // preorder(root);
    }
};

int main()
{
    BST bs;
    bs.insert(10);
    bs.insert(8);
    bs.insert(2);
    bs.insert(3);
    bs.insert(5);
    bs.insert(6);
    bs.show();
    bool x = bs.search(10);
    cout<<endl;
    cout<<x;
}