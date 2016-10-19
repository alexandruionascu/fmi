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
            this->left = NULL;
            this->right = NULL;
            this->parent = NULL;
            this->height = 0;
        };

        int getValue()
        {
            return this->value;
        };

        int setValue(int x)
        {
            this->value = x;
            return 0;
        }

        int getHeight()
        {
            return this->height;
        }

        int setHeight(int height)
        {
            this->height = height;
            return 0;
        }

        Node* getLeft()
        {
            return this->left;
        }

        Node* getRight()
        {
            return this->right;
        }

        Node* getParent()
        {
            return this->parent;
        }

        Node* setLeft(Node* left)
        {
            this->left = left;
            return 0;
        }

        Node* setRight(Node* right)
        {
            this->right = right;
            return 0;
        }

        Node* setParent(Node* parent)
        {
            this->parent = parent;
            return 0;
        }
    };

    Node* root;
    int size;

    int insert(Node* node, Node* parent, int x, bool direction)
    {
        if(node == NULL)
        {
            node = new Node();
            node->setValue(x);

            //if the node is the root
            if(this->getSize() == 0)
            {
                this->root = node;
            }
            else
            {
                if(direction == 0)
                {
                    parent->setLeft(node);
                }
                else
                {
                    parent->setRight(node);
                }

                node->setParent(parent);
            }

            this->size++;
            balance(node);

        }
        else
        {
            int h1, h2;

            if(node->getRight() != NULL)
            {
                h1 = node->getRight()->getHeight();
            }
            else
            {
                h1 = 0;
            }
            if(node->getLeft() != NULL)
            {
                h2 = node->getLeft()->getHeight();
            }
            else
            {
                h2 = 0;
            }

            if(x <= node->getValue())
            {
                node->setHeight(max(h1, h2 + 1) + 1);
                insert(node->getLeft(), node, x, 0);
            }
            else
            {
                node->setHeight(max(h1 + 1, h2) + 1);
                insert(node->getRight(), node, x, 1);
            }
        }
    }

    bool find(Node* node, int x)
    {
        if(node == NULL)
        {
            return false;
        }
        else
        {
            if(node->getValue() == x)
            {
                return true;
            }
            else if(x <= node->getValue())
            {
                return find(node->getLeft(), x);
            }
            else return find(node->getRight(), x);
        }
    }

    int balance(Node* node)
    {
        Node* parent = node->getParent();
        if(parent != NULL)
        {
            Node* grandParent = parent->getParent();
            if(grandParent != NULL)
            {
                if(grandParent->getHeight() - node->getHeight() > 1)
                {

                    cout << "need to balance " << node->getValue() << "\n";
                    bool Right = false;
                    bool Left = false;

                    //then balance
                    if(parent->getLeft())
                    {
                        if(parent->getLeft()->getValue() == node->getValue())
                        {
                            Left = true;
                        }
                    }
                    else
                    {
                        Right = true;
                    }

                    if(grandParent->getLeft())
                    {
                        if(grandParent->getLeft()->getValue() == parent->getValue())
                            Left = true;
                    }
                    else
                    {
                        Right = true;
                    }


                    if(Left == true && Right == true)
                    {
                        cout << "balance left right ";
                        balanceLeft(node);
                        balanceRight(node);
                    }
                    else
                    {
                        if(Left == true)
                        {
                            cout << "balance left";
                            balanceLeft(node);
                        }
                        else
                        {
                            cout << " balance right";
                            balanceRight(node);
                        }
                    }
                }

            }
        }
    }

    int balanceRight(Node* node)
    {
        Node* parent = node->getParent();
        Node* grandParent = parent->getParent();

        parent->setLeft(grandParent);
        grandParent->setRight(NULL);
        parent->setParent(grandParent->getParent());
        grandParent->setParent(parent);

        grandParent->setHeight(grandParent->getHeight() - 2);

        //if its root
        if(root->getValue() == grandParent->getValue())
        {
            root = parent;
            root->setParent(NULL);
        }

        return 0;

    }

    int balanceLeft(Node* node)
    {
        Node* parent = node->getParent();
        Node* grandParent = parent->getParent();

        parent->setRight(grandParent);
        grandParent->setLeft(NULL);
        parent->setParent(grandParent->getParent());
        grandParent->setParent(parent);

        grandParent->setHeight(grandParent->getHeight() - 2);

        //if its root
        if(root->getValue() == grandParent->getValue())
        {
            root = parent;
        }

        return 0;
    }

    public:
    AVL()
    {
        size = 0;
        root = NULL;
    }


    int getSize()
    {
        return this->size;
    }

    int insert(int x)
    {
        insert(this->root, NULL, x, 0);
    }

    bool find(int x)
    {
        find(this->root, x);
    }

};

int main()
{
    AVL* avl = new AVL();

    avl->insert(20);
    avl->insert(29);
    avl->insert(23);
    avl->insert(41);
    avl->insert(26);

	return 0;
}
