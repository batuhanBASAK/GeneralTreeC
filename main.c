#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    tree_t *root = init_tree(100);

    tree_t *trees[15];

    for (int i = 0; i < 15; i++)
        trees[i] = init_tree(i);

    addChild(trees[1], trees[2]);
    addChild(trees[1], trees[3]);
    addChild(trees[1], trees[4]);
       

    addChild(root, trees[1]);
    
    for (int i = 5; i < 15; i++)
        addChild(root, trees[i]);


    set(root, 40);
    printTree(root);
    
    int index = indexOfChild(root, trees[1]);
    tree_t *childNode = getChild(root, index);
    printf("\n\n-------------------------\n\n");
    printTree(childNode);
    printf("\n\n-------------------------\n\n");

    for(int i = 2; i < 6; i++) {
        tree_t *removal = removeChild(root, i);
        delete_tree(&removal);
    }

    
    printTree(root);

    delete_tree(&root);
    return 0;
}
