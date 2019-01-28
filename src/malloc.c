/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc
*/

#include"my_malloc.h"


void *getFreeMem(size_t size)
{
    if (!head)
        return NULL;
    meta *tmp = head;
    for(; tmp->next != NULL; tmp = tmp->next) {
        if (tmp->_isFree && tmp->_size <= size)
            return (void *)tmp;
    }
    return NULL;
}

void addToEnd(meta **node)
{
    if (!tail || !node)
        return;
    if (tail->_isFree)
        releaseMem();
    meta *tmp = tail;
    tmp->next = (*node);
    (*node)->prev = tmp;
    tail = (*node);
}

void initNode(meta **node, void *block, size_t size)
{
    (*node) = block;
    (*node)->_size = size;
    (*node)->next = NULL;
    (*node)->_isFree = false;
    (*node)->prev = NULL;

    if (!head)
        head = tail = (*node);
    else
        addToEnd(node);
}

void releaseMem()
{
    size_t size = 0;
    meta *iter = tail;
    for (; iter->prev != NULL; iter = iter->prev) {
        if (!iter->_isFree)
            break;
        size += iter->_size + sizeof(meta);
    }
    tail = iter;
    sbrk(0 - size);
}

void *malloc(size_t size)
{
    size_t total_size = sizeof(meta) + size;
    void *block = NULL;
    if (size <= 0)
        return NULL;
    pthread_mutex_lock(&global_malloc_lock);
    meta *node = (meta *)getFreeMem(size);
    if (node) {
        node->_isFree = false;
        pthread_mutex_unlock(&global_malloc_lock);
        return (void *)(node + 1);
    }
	block = sbrk((total_size ));
	if (block == (void*)-1) {
        pthread_mutex_unlock(&global_malloc_lock);
        return NULL;
    }
    initNode(&node, block, size);
    pthread_mutex_unlock(&global_malloc_lock);
    return (void *)(node + 1);
}
