/*
** EPITECH PROJECT, 2018
** FREE
** File description:
** FREE
*/

#include"my_malloc.h"

void free(void * ptr)
{
    size_t rmv = 0;
    if (!ptr)
        return;
    pthread_mutex_lock(&global_malloc_lock);
    meta *tmp = (meta *)ptr - 1;
    meta *iter = NULL;
    if (tail == tmp) {
        if (tail == head) {
            rmv = head->_size + sizeof(meta);
            head = tail = NULL;
            sbrk(0 - rmv);
        } else {
            iter = tail;
            tail->_isFree = true;
            for (; iter->prev != NULL; iter = iter->prev) {
                if (!iter->_isFree)
                    break;
                rmv += iter->_size + sizeof(meta);
            }
            tail = iter;
            tail->next = NULL;
            sbrk(0 - rmv);
        }
    } else
        tmp->_isFree = true;
    pthread_mutex_unlock(&global_malloc_lock);
    return;
}