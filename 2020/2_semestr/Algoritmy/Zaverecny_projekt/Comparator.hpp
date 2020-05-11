#pragma once
#include <iostream>

#include "FileLoad.hpp"
#include "Tree.hpp"

using namespace std;

struct Print
{
    bool branche;
    int level;
};

class Comparator
{
private:
    Tree *tree_1;
    Tree *tree_2;
    Print *print_1;
    Print *print_2;
    Print *temp_print;
    int iterations;
    
    Print *MakePrint(Tree *tree);
    
public:
    Comparator(Tree *tree_1, Tree *tree_2);
    ~Comparator();

    bool Compare();
};