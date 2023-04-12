#include "structure.h"

void initStructure(node_t *init_node, char gen)
{
    // init_node = malloc(sizeof(node_t));
    //node_t* tmp = realloc(init_node, sizeof(node_t));
    //init_node = tmp;
    //free(tmp);

    if (init_node != NULL)
    {
        init_node->_id = 0;
        init_node->_gen = gen;
        init_node->_next = NULL;
        init_node->_previous = NULL;
    }
}


// node_t* initStructure(char gen)
// {
//     node_t* init_node = malloc(sizeof(node_t));

//     if (init_node != NULL)
//     {
//         init_node->_id = 0;
//         init_node->_gen = gen;
//         init_node->_next = NULL;
//         init_node->_previous = NULL;
//     }

//     return (init_node);
// }


void addListBegin(node_t *node, char gen)
{
    if (node != NULL)
    {
        node_t *s_node = malloc(sizeof(node_t));
        initStructure(s_node, gen);
        // node_t *s_node = initStructure(gen);

        if (s_node != NULL)
        {
            /*while (node->_previous != NULL)
            {
                node = node->_previous;
            }*/
            node = rewindList(node);

            if (node->_previous == NULL)
            {
                s_node->_next = node;
                s_node->_previous = NULL;
                node->_previous = s_node;
            }
            replaceIds(s_node, 0);
       }
    }
}

void addListEnd(node_t *node, char gen)
{
    if (node != NULL)
    {
        node_t *e_node = malloc(sizeof(node_t));
        initStructure(e_node, gen);
        // node_t *e_node = initStructure(gen);;

        if (e_node != NULL)
        {
            while(node->_next != NULL)
            {
                node = node->_next;
            }

            if (node->_next == NULL)
            {
                e_node->_next = NULL;
                e_node->_previous = node;
                node->_next = e_node;
            }
            e_node->_id = node->_id + 1;
       }
    }
}

void addListIndex(node_t *node, char gen, int position)
{
    node = rewindList(node);
    if (node != NULL)
    {
        if (position == 0) addListBegin(node, gen); //Si position est 0, on utilise la fonction d'ajout au debut
        else if (position == count(node)) addListEnd(node, gen);  //Si position est a la fin de la liste, on utilise la fonction d'ajout a la fin
        else if (position <= count(node) && position > 0)
        {
            node_t *i_node = malloc(sizeof(node_t));
            initStructure(i_node, gen);
            // node_t *i_node = initStructure(gen);

            if (i_node != NULL)
            {
                for (int i = 0; i < position; i++) //Trouve l'element etant actuellement a la position
                {
                    node = node->_next; //se déplace sur le node précédent
                }

                i_node->_id = node->_id;
                i_node->_previous = node->_previous;
                i_node->_next = node;
                node->_previous->_next = i_node;
                node->_previous = i_node;

                replaceIds(i_node, i_node->_id);
            }
        }
    }
}

void deleteFromList(node_t *node, int position)
{
    node = rewindList(node);
    node_t *tmp = node;
    while (node->_id != position)
    {
        if(node->_next == NULL)
        {
            printf("No element found at this position.");
            return;
        }
        node = node->_next;
    }

    printf("node_del : %p\n", (void*)node);
    printf("prev_del : %p\n", (void*)node->_previous);
    printf("next_del : %p\n", (void*)node->_next);

    // nodeSupper = node;
    // apres = node->_next;
    // avant = node->_previous;
    // apres->_previous = avant;
    // avant->_next = apres;

    if (node->_previous != NULL)
    {
        //n-1 a son next qui passe a n+1
        node->_previous->_next = node->_next;
    }

    if (node->_next != NULL)
    {
        //n+1 a son prev qui passe a n-1, le decalant en arriere et changeant son id
        node->_next->_previous = node->_previous;
        replaceIds(node->_next, node->_id);
    }

    printf("liste lors du del");
    displayEntireList(node->_previous, 1);

    free(tmp);
    printf("HAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

    printf("node_rew : %p\n", (void*)node);
    printf("prev_rew : %p\n", (void*)node->_previous);
    printf("next_rew : %p\n", (void*)node->_next);

    node = rewindList(node);

    printf("node_rew2 : %p\n", (void*)node);
    printf("prev_rew2 : %p\n", (void*)node->_previous);
    printf("next_rew2 : %p\n", (void*)node->_next);

    printf("HAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA2");
}