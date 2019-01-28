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
void show_alloc_mem();
void *getFreeMem(size_t);
void releaseMem();
void initNode(meta **, void *, size_t);
void addToEnd(meta **);

#endif