#include <iostream>
#include <string>

#include "FileLoad.hpp"
#include "Comparator.hpp"


using namespace std;

int main()
{
    FileLoad *load = new FileLoad("input.txt");                                 //  The First input file load
    FileLoad *load_2 = new FileLoad("input_2.txt");                             //  The Second input file load

    Comparator *comp = new Comparator(load->GetTree(), load_2->GetTree());      //  Initialization of Comparator that creates prints of both of inputed trees

    if (comp->Compare())                                                        //  Finnal call of Compare method returning bool value
        cout << "Given trees are SAME!" << endl;
    else
        cout << "Given trees are NOT SAME!" << endl;

    return 0;
}