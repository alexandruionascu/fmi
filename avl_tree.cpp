#include<iostream>
#include<fstream>
using namespace std;

class AVL
{
    private:
    class Node
    {
        private:
        int height;
        int value;

        Node* left;
        Node* right;
        Node* parent;

        public:
        Node()
        {
            //this->parent = NULL;
            //this->value = NULL;
            //this->left = NULL;
        };

        int getValue()
        {

        };

        int setValue(int x)
        {
            this->value = x;
        }

        Node* getLeft()
        {

        }

        Node* getRight()
        {

        }

        Node* getParent()
        {

        }
    };

    Node* root;
    int height;
    int size;

    public:
    AVL()
    {
        height = 0;
        size = 0;
    }

    int insert(int x)
    {

    }

    int insert(Node* root, int x)
    {
        if(root  == NULL)
        {
            root = new Node();
            root->setValue(x);
        }
        else
        {
            if(x <= root.getValue())
            {
                insert(root->getLeft(), x);
            }
            else
            {
                insert(root->getRight(), x);
            }
        }
    }

};

int main()
{
    AVL* avl = new AVL();

}
