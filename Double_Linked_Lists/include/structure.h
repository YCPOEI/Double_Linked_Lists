#ifndef structure_H_
#define structure_H_

// SYSTEME INCLUDE(S)
#include <stdlib.h>
#include <stddef.h>

// STRUCTURE(S)
typedef struct node_t {
    int _id;
    char _gen;
    struct node_t *_next;
    struct node_t *_previous;
} node_t;

// LOCAL INCLUDE(S)
#include "utils.h"

// PROTOTYPE(S)
void initStructure(node_t *node, char gen);
// node_t *initStructure(char gen);
void addListBegin(node_t *node, char gen);
void addListEnd(node_t *node, char gen);
void addListIndex(node_t *node, char gen, int position);
void deleteFromList(node_t *node, int position);

#endif /* !structure_H_ */