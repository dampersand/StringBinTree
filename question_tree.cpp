#ifndef QUESTION_TREE_CPP
#define QUESTION_TREE_CPP
#include "question_tree.h"
#include <iostream>
#include <sstream>
#include <conio.h>


void QuestionTree::make(string file)
{
    int menu =0;
    string str_menu;
    int totalUsers;

        // The root of the full binary tree
    root = buildTree(root, file);

    ClearScreen();
     while(menu != 4)
    {
        cout << "\n\nMain Menu\n" << "[1] Print tree\n" << "[2] Administer test\n" << "[3] Get Statistics\n" << "[4] Quit\n" << ">";
        cin.sync();
        getline(cin, str_menu);
        stringstream (str_menu) >> menu;

        switch (menu)
        {
            case 1:
                menu = 0;
                cout << "\n\nI will now print the tree you've given me.\n\n" << file << endl;
                printTree(root, 0, 0); //Print the tree
                cout << "\nPress enter to continue.";
                getch();
                break;
            case 2:
                menu = 0;
                cout << "\nWhen you are ready to continue to the questioning, please press enter.\n";
                cin.sync();
                getch();
                administer(root);
                cout << "\nPress enter to continue.";
                getch();
                break;
            case 3:
                menu = 0;
                totalUsers = userTotal(root, 0);
                statistics(root, totalUsers);
                cout << "\nPress enter to continue.";
                getch();
                break;
            case 4:
                return;
                break;
            default:
                cout << "Invalid response; please try again.\n" << "Press enter to continue.";
                getch();
                break;
        }
    }
    return;
}

void QuestionTree::removeTree(BinNode* eNode)
{
    if (eNode->yes != NULL)
        QuestionTree::removeTree(eNode->yes);
    if (eNode->no != NULL)
        QuestionTree::removeTree(eNode->no);
    delete eNode;
    return;
}

void QuestionTree::administer(BinNode* question)
{
    int answer;
    string str_answer;
    cout << question->val << endl;
    if (question->isLeaf())
    {
        question->count += 1;
        return;
    }
    cout << "[1] Yes\n" << "[2] No\n" << ">";
    getline(cin, str_answer);
    stringstream(str_answer) >> answer;
    cout << endl;
    while ((answer) != 1 && (answer != 2)) //No more false quits
    {
        cout << "\nInvalid response, try again.\n" << ">";
        cin.sync();
        getline(cin, str_answer);
        stringstream(str_answer) >> answer;
    }
    switch (answer)
    {
    case 1:
        administer(question->yes);
        break;
    case 2:
        administer(question->no);
        break;
    }
return;
}

void QuestionTree::printTree(BinNode* node, int tierCount, int responseType)
{
    tierCount += 1; //this variable will tell us how much margin we need.
    if (node == NULL)
        {
            return;
            tierCount -= 1;
        }
    for (int currentTier = tierCount; currentTier > 0; currentTier--)
    {
        cout << "      "; //print margins, one 'tab' for every tier.
    }
    switch (responseType) //Determine optional prefix to put on entry
    {
    case 0: //No prefix
        break;
    case 1: //Prefix "yes"
        cout << "Yes: ";
        break;
    case 2: //Prefix "no"
        cout << "No:  ";
        break;
    }
    cout << node->val << endl;
    printTree(node->yes, tierCount, 1); //Recursively print the "yes" side of the node
    printTree(node->no, tierCount, 2); //Recursively print the "no" side of the node
}
int QuestionTree::userTotal(BinNode* node, int total)
{
        //Get total number of users
    if(node->isLeaf())
        total += node->count;
    if(node->yes != NULL)
       total = userTotal(node->yes, total);
    if(node->no != NULL)
        total = userTotal(node->no, total);
    return total;
}
void QuestionTree::statistics(BinNode* stat, int totalCount)
{
    cout << endl;
    if (stat->isLeaf())
    {
        float percent = (float(stat->count) / float(totalCount))*100;
        cout << stat->val << ": " << percent << "\%\n";
    }
    if (stat->yes != NULL)
        statistics(stat->yes, totalCount);
    if (stat->no != NULL)
        statistics(stat->no, totalCount);
    return;
}

void QuestionTree::ClearScreen()
{
    cout << string( 100, '\n' );
}

BinNode* QuestionTree::buildTree(BinNode* entry, string data)//Build the entire tree.
{
    string str_userResponse;
    int userResponse; //Simple input variable
    string nextData; //Data to be entered in the node in question
    cout << "\n[1] New Question\n" << "[2] New Category\n" << ">";
    cin.sync(); //cin problems, man.
    getline(cin, str_userResponse);
    stringstream(str_userResponse) >> userResponse; //Catch cin issues when user accidentally inputs string instead of int
    while ((userResponse) != 1 && (userResponse != 2)) //No more false quits in the binary tree!
    {
        cout << "\nInvalid response, try again.\n" << ">";
        cin.sync();
        getline(cin, str_userResponse);
        stringstream(str_userResponse) >> userResponse;
    }
    if (userResponse == 2) //If they've asked for a category...
    {
        cout << "Enter your category.\n" << ">";
        cin.sync();
        getline(cin, nextData); //...get the category's data...
        entry = nodeMaker(entry, nextData); //... and make a new node from it.
    }
    else if (userResponse == 1) //If they've asked for a question...
    {
        cout << "Enter your question. \n" << ">";
        cin.sync();
        getline(cin, nextData); //...get the question's data...
        entry = nodeMaker(entry, nextData); //...and make a new node from it.


        cout << "\n\nAnswer is yes to question \"" << nextData << "\"\n";
        cout << "--------------------------------------";
        entry->yes = buildTree(entry->yes, nextData); //Recursively add a 'yes' answer to the data given.


        cout << "\n\nAnswer is no to question \"" << nextData << "\"\n";
        cout << "--------------------------------------";
        entry->no = buildTree(entry->no, nextData); //Recursively add a 'no' answer to the data given.
    }
    return (entry);
}


BinNode* QuestionTree::nodeMaker(BinNode* nNode, string data)
{
    nNode = new(BinNode);
    nNode->val = data;
    nNode->yes = NULL;
    nNode->no = NULL;
    nNode->count = 0;
    return(nNode);
}

#endif // QUESTION_TREE_CPP
