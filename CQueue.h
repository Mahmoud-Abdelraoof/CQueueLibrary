#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#define QUEUE_MAX 5


#include<stdio.h>
#include "STD_TYPES.h"
typedef struct
{
	s32 queue[QUEUE_MAX];
	s32 Head;
	s32 Tail;
}Queue_t;

typedef enum 
{
	CQUEUE_FULL,
	CQUEUE_NFULL,
	CQUEUE_EMPTY,
	CQUEUE_NEMPTY,
	NULL_POINTER
}Check_t;


void QueueInitialize(Queue_t *Q);
static Check_t QueueFull(Queue_t *Q);
static Check_t QueueEmpty(Queue_t *Q);
static Check_t QueueReset(Queue_t *Q);
void EnqueueData(Queue_t *Q ,s32 value);
void DequeueData(Queue_t *Q,s32 *Data);
void DisPlay(Queue_t *Q);








#endif