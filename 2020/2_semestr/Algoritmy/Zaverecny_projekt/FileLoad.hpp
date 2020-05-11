#pragma once
#include <iostream>
#include <fstream>

#include "Tree.hpp"


using namespace std;

class FileLoad
{
private:
    ifstream *file;
    Tree *tree;
    Tree *temp_tree;
    int temp;
    int *load_values;

public:
    FileLoad(string filename);
    ~FileLoad();

    Tree *GetTree();
};