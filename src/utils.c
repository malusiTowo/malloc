/*
** EPITECH PROJECT, 2018
** UTILS
** File description:
** UTILS
*/

#include"./my_malloc.h"

size_t get_pow_2(size_t size)
{
    size_t i = size;
    for (; (i % 2) != 0; i++);
    return i;
}

size_t get_size(size_t size)
{
    size_t i = size * 4096;
    return i;
}
