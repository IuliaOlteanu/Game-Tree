# Game Tree

**Structure used for task1 & task2**


typedef struct tree {\
	char **a; *matrix associated to each node*\
	struct tree *fii[9]; *a vector of child pointers*\
	struct tree *tata; *a pointer to the parent of a node*\
	int nr;  *the number of sons*\
  int jucator; *takes only 0 or 1 depending on the initial player (X has the value 1 and O the value 0)*\
	int nivel; *the number of tree levels*\
  int viz; *a label if a node has been visited or not*\
  int N; *a label that takes the value 1 if the node is true and 0 if the node is false*\
};

# **Task1 & Task2**

The creare_rad function builds the root of the tree, initializing all the fields of the Tree structure, associating level 0. The create function builds the game tree starting from the root as long as the matrix is ​​not complete. The ready function checks this aspect, each case is taken separately for verification, on the line, on the column, on the main and the secondary diagonal, returning 1 in case which the matrix associated with the node contains elements on the line/column/main diagonal/secondary diagonal equal to either X or O, otherwise it returns 0. To display the game tree built for the first request, we implemented the display_ad function which prints in depth the tree starting from the root, within the function the display_mat function is called which displays the matrix from a node in the file respecting the indentation required in the statement, the use of \t, and for each node all its subtrees will be displayed. The release function aims to release all allocated memory.

In main, I dynamically allocated space to the matrix associated with a node, I read from the received file as an argument in the command line the player and the initial configuration of the game board in a character string, the player being s[0], and the elements of the matrix are the even indices of the string s, since each character is followed by a space, we created the root and later the game tree by calling the create function, finally the function to display the tree in the output file received as an argument is called and all the memory is freed used.

For the second task, the main is almost identical, except that the tree_si_sau function is also called, which evaluates the game tree and assigns a label to each node. In this function, tree_si_sau, the nodes are labeled according to the level they are on, the nodes or are located on the even level, and those on the odd level, because the player who starts the game wants to maximize his gain. In the case of nodes of type or, it is necessary that at least one son has the label 1 so that the parent is also labeled at kind, and for type nodes all children must be labeled with 1 so that the parent is labeled as well, otherwise the father is labeled with 0. The verif function is called inside the tree_si_sau function, it receives as parameters a node the game tree and a character representing the player who starts the game (X or O), returning 1 if the initial player wins the game and 0 in case of a draw or loss to the opponent, the ac function it is similar to the one used for the first request, ready, it also performs a check on lines, columns, on the main and secondary diagonals. To display the si_or tree, call the display_ad_si_sau function manually, similar to the display_ad function, if the field N of a node has the value 1, it is assigned T, otherwise F, and the display in the file is done respecting the required indentation

# Task3

**Structure used**

typedef struct tree3 {\
    struct tree3 *fii[20]; *a vector of pointers to children*\
    struct tree3 *tata; *a pointer to parent*\
    int nr; *number of sons*\
    int niv; *level of a node*\
    int tip; *0 = internal node, 1 = leaf\
    int val; 
    int viz; *0 if a node was not visited in the ad3 function and 1 if the node was visited*\
    int vizz; *if a node was not visited in the tip_ad3 function and 1 if the node was visited*/\
};

The rad3 function is similar to the one implemented for requirements 1 and 2, all the fields of the structure are initialized. The creation of the tree takes place in the create3 function, similar to the one for requirements 1 and 2. The ad3 function puts in the nodes the value corresponding to the level (if the level is even, the minimum between the values ​​of the nodes is set, otherwise the maximum). The mini and maxi functions calculate the minimum and maximum between the values ​​of the child nodes. By hand, I read from the file in the following way: I read character, number, character, and in the creare3 function, the reading is done as follows: character, number, character, space or new line. For display, I implemented the type_ad3 function that performs a scan in the depth of the created tree.
