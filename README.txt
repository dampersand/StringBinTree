String Binary Tree
dampersand

In an effort to play around with GitHub and repositories, I've added this particular repository.

StringBinTree is a simple binary tree based on a project description I found on the web; that I've recreated in C++ (mostly to prove I could).

For anyone looking at the project, the compiled program will initially build the tree based on user input:

1. The user will be prompted for the tree's name
2. The user will be prompted to create a node (one of two types; a "question" is a regular node and a "category" is a leaf node).
3. If the node is a question, the program will then create two more nodes - a "yes to that question" node and a "no to that question node," then prompt the user to input a question/category for each of those nodes, ad infinitum.

Upon completion of the binary tree (by terminating all tree paths in leaves), the program will allow the user to print out the tree, administer a yes/no test based on the tree, or calculate  the percentage of users that fell into each leaf during administration of the test.

As an example:
The program can be used to build a tree to determine what to eat:

///////////////////////////////////////////
Tree name: Hunger Flowchart

Question 1: Are you hungry?

if answer is yes to question 1:
Question 2: Is it morning?

if answer is yes to question 2:
Have a bagel.

if answer is no to question 2:
Have a hamburger.

if answer is no to question 1:
Then why would you look at this flowchart?
////////////////////////////////////////////


In the example above, the user would input the tree name, all questions, and all answers to the questions.  The program would then store all that information until termination, so that it can be played with.

The program was compiled using gcc 4.7.1... so your results on compilation may vary.