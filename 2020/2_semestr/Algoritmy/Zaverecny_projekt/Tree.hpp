#pragma once
#include <iostream>
#include <string>


using namespace std;

class Tree
{
private:
    int root_node;
    Tree *left_node;
    Tree *right_node;
    Tree *parent_node;
    bool processed;

public:
    Tree();
    ~Tree();

    int GetRootNode();
    bool GetProcessed();
    Tree *GetLeftNode();
    Tree *GetRightNode();
    Tree *GetParentNode();

    void SetProcessed(bool value);
    void SetRootNode(int node);
    void SetLeftNode(int node, Tree *parent);
    void SetRightNode(int node, Tree *parent);
};