#include "utils.h"


node_t* rewindList(node_t *node)
{
    // if (node != NULL)
    // {
        // while (node->_id != 0)
        // {
        //     node = node->_previous;
        // }
    // }
    while (node->_previous != NULL)
    {
        printf("SIZE : %ld\n", sizeof node->_previous);
        node = node->_previous;
    }
    printf("VOID * NODE : %p\n", (void*)node);
    printf("prev : %p\n", (void*)node->_previous);
    printf("next : %p\n", (void*)node->_next);

    return (node);
}

void getListElement(node_t *node, int position)
{
    node = rewindList(node);
    for(int i = 0 ; i < position; i++){
        node = node->_next;
        if(node == NULL)
        {
            printf("No list found");
            break;
        }
    }

    if (node != NULL)
    {
        printf("(%d) (%c)\n", node->_id, node->_gen);
    }
}

void displayEntireList(node_t *node, int isStart)
{
    if(isStart == 1)
    {
        node = rewindList(node);
    }

    if (node)
    {
        printf("(%d) : (%c) / (%p) / (%p) / (%p)\n", node->_id, node->_gen, (void*)node, (void*)node->_previous, (void*)node->_next);
        displayEntireList(node->_next, 0);
    }
}

int count(node_t *node)
{
    node = rewindList(node);
    int count = 0;

    while(node != NULL)
    {
        node = node->_next;
        count++;
    }

    return (count);
}

void replaceIds(node_t *node, int startId) //Pars du node donne, puis change l'id de tous les elements suivants (->next)
{
    while(node != NULL)
    {
        node->_id = startId;
        node = node->_next;
        startId++;
    }
}
