#include "tree.h"

tree_t *init_tree(int data){
    tree_t *t = (tree_t*)calloc(1, sizeof(tree_t));
    t->data = data;
    t->size = 0;
    t->capacity = INITIAL_CAPACITY;
    t->children = (tree_t**) calloc(t->capacity, sizeof(tree_t*));
    for (int i = 0; i < t->capacity; i++)
        t->children[i] = NULL;
    return t;
}

void delete_tree(tree_t **tp){
    if (*tp == NULL)
        return;
    tree_t *t = *tp;
    if (t->children != NULL){
        tree_t *node = t->children[0];
        for (int i =0; i < t->size; i++)
            delete_tree(&t->children[i]);
    }
    free(t);
}


int get(const tree_t *t){
    if (t == NULL)
        return -1;
    return t->data;
}


int set(tree_t *t, int data){
    int old = t->data;
    t->data = data;
    return old;
}

void addChild(tree_t *t, tree_t *c){
    if (t == NULL)
        return;
    if (t->size == t->capacity)
        reallocateChildren(t);
    t->children[t->size++] = c;
}

tree_t *removeChild(tree_t *t, int index){
    if (t == NULL)
        return NULL;
    if (index < 0 || index >= t->size){
        fprintf(stderr, "%d is out of bounds!!!\n", index);
        exit(EXIT_FAILURE);
    }
    tree_t *removalChild = t->children[index];
    for (int i = index; i < t->size-1; i++)
        t->children[i] = t->children[i+1];
    t->size--;
    return removalChild;
}


int indexOfChild(tree_t* t, tree_t *c){
    if (t == NULL)
        return -1;
    for (int i = 0; i < t->size; i++)
        if (t->children[i] == c)
            return i;
    return -1;
}

tree_t *getChild(tree_t *t, int index){
    if (t == NULL)
        return NULL;
    if (index < 0 || index >= t->size){
        fprintf(stderr, "Index is out of bound!!!\n");
        exit(EXIT_FAILURE);
    }
    return t->children[index];
}

void reallocateChildren(tree_t *t){
    int oldCapacity = t->capacity;
    int size = t->size;

    tree_t **oldChilren = t->children;
    t->capacity = 2 * t->capacity;
    t->children = (tree_t**)calloc(t->capacity, sizeof(tree_t*));
    for (int i = 0; i < size; i++)
        t->children[i] = oldChilren[i];
    free(oldChilren);
}



void printTree(tree_t *t){
    _printTree(t, 0);
}


void _printTree(tree_t *t, int lvl){
    if (t == NULL)
        return;
    for (int i = 0; i < lvl; i++)
        printf("    ");
    printf("%d\n", t->data);
    for (int i = 0; i < t->size; i++)
        _printTree(t->children[i], lvl+1);
}



