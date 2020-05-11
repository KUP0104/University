#include "Tree.hpp"

Tree::Tree()
{
    this->root_node = 0;
    this->left_node = nullptr;
    this->right_node = nullptr;
    this->parent_node = nullptr;
    this->processed = false;
}

Tree::~Tree()
{
    //
}

int Tree::GetRootNode()
{
    return this->root_node;
}

bool Tree::GetProcessed()
{
    return this->processed;
}

Tree *Tree::GetLeftNode()
{
    return this->left_node;
}

Tree *Tree::GetRightNode()
{
    return this->right_node;
}

Tree *Tree::GetParentNode()
{
    return this->parent_node;
}

void Tree::SetProcessed(bool value)
{
    this->processed = value;
}

void Tree::SetRootNode(int node)
{
    this->root_node = node;
}

void Tree::SetLeftNode(int node, Tree *parent)
{
    this->left_node = new Tree();                   //  Creates a new object on a hold address for a LEFT node 
    this->left_node->SetRootNode(node);             //  Sets the int value of ROOT node in LEFT child node
    this->left_node->parent_node = parent;          //  Passing address into parent pointer in LEFT node's parent node
}

void Tree::SetRightNode(int node, Tree *parent)
{
    this->right_node = new Tree();                  //  Creates a new object on a hold address for a RIGHT node
    this->right_node->SetRootNode(node);            //  Sets the int value of ROOT node in RIGHT child node
    this->right_node->parent_node = parent;         //  Passing address into parent pointer in RIGHT node's parent node
}
