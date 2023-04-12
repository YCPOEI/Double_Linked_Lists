#include "main.h"

int main(void)
{
    node_t *root = malloc(sizeof(node_t));
    initStructure(root, 'S');
    // node_t *root = initStructure('S');
    addListBegin(root, 'E');
    addListEnd(root, '3');
    addListEnd(root, '8');
    addListEnd(root, 'G');
    addListEnd(root, '2');
    addListBegin(root, '7');

    printf("\nNumber of node(s) : %d\n", count(root));
    printf("Here is the list :\n");
    displayEntireList(root, 1);

    printf("\nDelete node 2 : \n");
    deleteFromList(root, 2);
    displayEntireList(root, 1);

    printf("\nAdd a node to the 2nd position :\n");
    addListIndex(root, 'R', 2);
    displayEntireList(root, 1);

    // printf("\nWhat is the 4rd node ?\n");
    // getListElement(root, 3);

    // printf("\nWhat is the 2st node ?\n");
    // getListElement(root, 1);

    // deleteFromList(root, 6);
    // deleteFromList(root, 5);
    // deleteFromList(root, 4);
    // deleteFromList(root, 3);
    // deleteFromList(root, 2);
    // deleteFromList(root, 1);
    // deleteFromList(root, 0);

    return (0);
}