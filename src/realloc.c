/*
** EPITECH PROJECT, 2018
** REALLOC
** File description:
** REALLOC
*/

#include "my_malloc.h"

void *realloc(void *block, size_t size)
{
    meta *node;
    void *ret;
    if (!block || size <= 0)
        return malloc(size);
    node = (meta*)block - 1;
    if (node->_size >= size)
        return block;
    ret = malloc(size);
    if (ret) {
        memcpy(ret, block, node->_size);
        free(block);
    }
    return ret;
}