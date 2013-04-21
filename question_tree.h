#ifndef QUESTION_TREE_H
#define QUESTION_TREE_H

#include "node.h"

class QuestionTree {
public:
    QuestionTree(string name)
    {
        root = nodeMaker(name);
    }
    void make(string file);

private:

        /* method to ask a series of questions (Task #3)
     */
    void administer(BinNode* question);
    /* Method to perform task #2; prettyprint included.
     */
    void printTree(BinNode* node, int tierCount, int responseType);
    void statistics(BinNode* stat, int totalCount);
    void ClearScreen();
    int userTotal(BinNode* node, int total);
    /* Method called to build the binary tree (Task #1).
        - relies on recursive function makeQuestionTreeHelper()
    */

    // private recursive functions called by the above

    BinNode* buildTree(BinNode* entry, string data);//Build the entire tree.
    //a function to construct an ENTIRE BinNode pointer
    BinNode* nodeMaker(string data);
    BinNode *root;
};

#endif
