#include <iostream>
#include <string>
#include <conio.h>
#include <sstream>
#include "question_tree.h"
#include "question_tree.cpp"

using namespace std;


int main()
{
    string treeName;

    cout << "This tree must be built before it can be used.\n";
    cout << "Type the tree name.\n" << ">";
    getline(cin,treeName);

    QuestionTree Oak(treeName);

    Oak.make(treeName);
    return 0;
}
