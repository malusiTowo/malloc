/*
** EPITECH PROJECT, 2018
** SHOW_ALLOC_MEM
** File description:
** SHOW_ALLOC_MEM
*/

#include"./my_malloc.h"

void show_alloc_mem(void)
{
    printf("break : %p", sbrk(0));
    meta *iter = head;
    for (; iter->next != NULL; iter = iter->next) {
        if (!iter->_isFree)
            printf("%p - %p : %ld bytes", iter + 1, \
                   iter->next + 1, iter->next->_size - iter->_size);
    }
}