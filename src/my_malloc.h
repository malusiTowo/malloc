/*
** EPITECH PROJECT, 2018
** MYMALLOC header
** File description:
** header
*/

#ifndef MYMALLOC_H
#define MYMALLOC_H

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<pthread.h>

typedef struct meta_t
{
    size_t _size;
    bool _isFree;
    struct meta_t *next;
    struct meta_t *prev;
} meta;

meta *head;
meta *tail;

pthread_mutex_t global_malloc_lock;

void *malloc(size_t);
void *realloc(void *, size_t);
void free(void *);
void show_alloc_mem(void);
void *get_free_mem(size_t);
void release_mem(void);
void init_node(meta **, void *, size_t);
void add_to_end(meta **);
size_t get_size(size_t );
void destroy_mem(meta **ptr);
size_t destroy_end_nodes(void);

#endif