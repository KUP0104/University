#include "FileLoad.hpp"

FileLoad::FileLoad(string filename)
{
    this->tree = new Tree();

    this->load_values = (int*)malloc(sizeof(int) * 100);    //  Limited for 100 values loaded from file
    
    ifstream file;
    file.open(filename);
    if (!file.is_open())
        exit(1);

    int j = 0;
    while (file >> this->temp)
        this->load_values[j++] = this->temp;

    file.close();   //  Closing file

    this->tree->SetRootNode(load_values[0]);                //  Setting the root element
    int k = 1;
    while (k < j)
    {
        //  cout << endl;                                   //  #1/5 - Displaying values in tree
        bool getting_node = true;

        this->temp_tree = this->tree;
        while (getting_node)
        {
            if (this->load_values[k] <= this->temp_tree->GetRootNode()) //  When the value is lower or equal then current node -> continues for left childnode, otherwise for right childnode
            {
                //cout << this->temp_tree->GetRootNode() << "- ";           //  #2/5 - Displaying values in tree
                if (this->temp_tree->GetLeftNode() == nullptr)              //  If there is not left childnode, it creates the new one and puts the equated value into
                {
                    this->temp_tree->SetLeftNode(this->load_values[k], this->temp_tree);
                    getting_node = false;                                   //  It ends the nesting loop
                    k++;                                                    //  Itteration when the current value is stored in the left node to continue to the other one
                    //  cout << this->temp_tree->GetLeftNode()->GetRootNode() << "L ";  //  #3/5 - Displaying values in tree
                }
                else
                {
                    this->temp_tree = this->temp_tree->GetLeftNode();       //  Nesting to child node
                }
            }
            else
            {
                //cout << this->temp_tree->GetRootNode() << "* ";           //  #4/5 - Displaying values in tree
                if (this->temp_tree->GetRightNode() == nullptr)             //  If there is not right childnode, it creates the new one and puts the equated value into
                {
                    this->temp_tree->SetRightNode(this->load_values[k], this->temp_tree);
                    getting_node = false;                                   //  It ends the nesting loop
                    k++;                                                    //  Itteration when the current value is stored in the right node to continue to the other one
                    //  cout << this->temp_tree->GetRightNode()->GetRootNode() << "P "; //  #5/5 - Displaying values in tree
                }
                else
                {
                    this->temp_tree = this->temp_tree->GetRightNode();      //  Nesting to child node
                }
            }
        }
    }
}

FileLoad::~FileLoad()
{
    free(load_values);
}

Tree *FileLoad::GetTree()
{
    return this->tree;
}