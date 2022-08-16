#include "sort.h"

void swap_node(listint_t **head, listint_t *node1, listint_t *node2);

void insertion_sort_list(listint_t **list)
{
    listint_t *new, *temp;
   
    if(*list == NULL || (*list)->next == NULL)
        return;

    for(new = (*list)->next; new; new = new->next)
    {
        for(; new && new->prev && new->prev->n > new->n; new = new->prev)
        {
            temp = new->prev;
            swap_node(list, temp, new);
            print_list(*list);
           
        }
    }          
}

void swap_node(listint_t **head, listint_t *node1, listint_t *node2)
{
    listint_t *prev, *next;

    prev = node1->prev;
    next = node2->next;

    if(prev != NULL)
        prev->next = node2;
    else
        *head = node2;

    node1->prev = node2;
    node1->next = next;
    node2->prev = prev;
    node2->next = node1;
    if(next)
        next->prev = node1;

}

