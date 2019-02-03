/*
** EPITECH PROJECT, 2018
** FREE
** File description:
** FREE
*/

#include"my_malloc.h"

void free(void *ptr)
{
    if (!ptr)
        return;
    pthread_mutex_lock(&global_malloc_lock);
    meta *tmp = (meta *)ptr - 1;
    destroy_mem(&tmp);
    pthread_mutex_unlock(&global_malloc_lock);
}

void destroy_mem(meta **ptr)
{
    size_t rmv = 0;

    if (tail == (*ptr)) {
        if (tail == head) {
            rmv = head->_size + sizeof(meta);
            head = tail = NULL;
            sbrk(0 - rmv);
        } else {
            tail->_isFree = true;
            rmv = destroy_end_nodes();
            sbrk(0 - rmv);
        }
    } else
        (*ptr)->_isFree = true;
}

size_t destroy_end_nodes(void)
{
    size_t rmv = 0;
    meta *iter = tail;

    for (; iter->prev != NULL; iter = iter->prev) {
        if (!iter->_isFree)
            break;
        rmv += iter->_size + sizeof(meta);
    }
    tail = iter;
    tail->next = NULL;
    return rmv;
}