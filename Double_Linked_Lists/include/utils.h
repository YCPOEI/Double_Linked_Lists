#ifndef utils_H_
#define utils_H_

// SYSTEME INCLUDE(S)
#include <stdio.h>

// STRUCTURE(S)

// LOCAL INCLUDE(S)
#include "structure.h"

// PROTOTYPE(S)
node_t *rewindList(node_t *node);
void getListElement(node_t *node, int position);
void displayEntireList(node_t *node, int isStart);
int count(node_t *node);
void replaceIds(node_t *node, int startId);

#endif /* !utils_H_ */