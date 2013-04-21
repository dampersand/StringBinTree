#include <cstddef>
#include <string>
using namespace std;

#ifndef BINNODE_H
#define BINNODE_H

class BinNode {

public:
    /* constructor - which would be great, except I can't construct POINTERS with this*/
    BinNode(string v = "", BinNode* y = NULL, BinNode* n = NULL)
    {
	val = v;
	yes = y;
	no = n;
	count = 0;
    }


    bool isLeaf() //operation
    {
	return no == NULL && yes == NULL; // a node is a leaf if both no and yes are not subtrees (== NULL)
    };

    /* member variables */

    string val;     // the question or category label
    int count;      // can be used to count the number of respondents
    BinNode* no;    // yes and no sub-trees
    BinNode* yes;
};

#endif
