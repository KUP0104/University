#include "Comparator.hpp"

Comparator::Comparator(Tree *tree_1, Tree *tree_2)
{
    this->tree_1 = tree_1;
    this->tree_2 = tree_2;

    //  Makes prints from the trees
    this->print_1 = MakePrint(tree_1);
    this->print_2 = MakePrint(tree_2);
}

Comparator::~Comparator()
{
    free(this->temp_print);
}

Print *Comparator::MakePrint(Tree *tree)
{
    Tree *temp_tree;
    this->temp_print = (Print*)malloc(sizeof(Print)*200);           //  Memory alocation for 200 elements long print - it is the maximum lenght of it

    int level = 0, i = 0;
    temp_tree = tree;
    while (true)
    {
        if (temp_tree->GetLeftNode() != nullptr && temp_tree->GetLeftNode()->GetProcessed() == false)           //  Processes LEFT node when is non-nullptr and is not processed yet
        {
            //cout << "Left" << endl;                               //  #1/7 - Displaying branches in tree
            //cout << temp_tree->GetRootNode() << endl;             //  #2/7 - Displaying values in tree's nodes
            level++;                                                //  Level incrementation with entering a child node
            temp_tree = temp_tree->GetLeftNode();                   //  Re-typing the temp tree with a child node to enter the child object to do with
            temp_print[i].level = level;                            //  Setting level into structure
            temp_print[i].branche = true;                           //  Setting branche direction with bool - TRUE for LEFT directioin and FALSE for RIGHT direction
            temp_tree->SetProcessed(true);                          //  Setting Node as processed
            i++;                                                    //  Finnal incrementation - index grows up with each node
        }
        else
        {
            if (temp_tree->GetRightNode() != nullptr && temp_tree->GetRightNode()->GetProcessed() == false)     //  Processes RIGHT node when is non-nullptr and in not precessed yet
            {
                //cout << "Right" << endl;                          //  #3/7 - Displaying branches in tree
                //cout << temp_tree->GetRootNode() << endl;         //  #4/7 - Displaying values in tree's nodes
                level++;                                            //  Level incrementation with entering the child node
                temp_tree = temp_tree->GetRightNode();              //  Re-typing the temp tree with child node to enter child object to do with
                temp_print[i].level = level;                        //  Setting level into structure
                temp_print[i].branche = false;                      //  Setting branche direction with bool - TRUE for LEFT directioin and FALSE for RIGHT direction
                temp_tree->SetProcessed(true);                      //  Setting Node as processed
                i++;                                                //  Finnal incrementation - index grows up with each node
            }
            else
            {
                if (temp_tree->GetParentNode() == nullptr)                                                      //  Leaves the whole loop and ends print when parent node is nullptr - all Tree objects pointers are defaulty set to nullptr to be able to be equated
                {
                    //cout << "ROOT-END" << endl;                   //  #5/7 - Displaying the ROOT Node in tree
                    break;                                          //  Leaving main while loop from last -> ROOT node
                }
                else                                                                                            //  Processes the step back into PARENT node when the parent is non-nullptr
                {
                    //cout << "ROOT" << endl;                       //  #6/7 - Displaying branches in tree
                    //cout << temp_tree->GetRootNode() << endl;     //  #7/7 - Displaying values in tree's nodes
                    level--;                                        //  Level decrementation with entering the parent node
                    temp_tree = temp_tree->GetParentNode();         //  Re-typing the temp tree with the parent node to enter the parent object to do with
                }
            }
        }
    }

    this->iterations = i;                                           //  Passing the value of iterations that is lenght of generated print

    return temp_print;
}

bool Comparator::Compare()
{
    for (int i = 0; i < this->iterations; i++)
    {
        if (!(this->print_1[i].branche == this->print_2[i].branche && this->print_1[i].level == this->print_2[i].level))
            return false;                                           //  Returns false when the branches or levels are different 
    }
    
    return true;
}