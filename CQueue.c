#include "CQueue.h"

static Check_t QueueFull(Queue_t *Q)
{
	if(NULL != Q)
	{
		if((0==Q->Head&&QUEUE_MAX-1==Q->Tail)||(Q->Head == Q->Tail+1))
		{
			return CQUEUE_FULL;
		}
		else
		{
			return CQUEUE_NFULL;
		}
	}
	else
	{
		return NULL_POINTER;
	}
}


static Check_t QueueEmpty(Queue_t *Q)
{
	if(NULL != Q)
	{
		if(Q->Head==-1&&Q->Tail==-1)
		{
			return CQUEUE_EMPTY;
		}
		else
		{
			return CQUEUE_NEMPTY;
		}
	}
	else
	{
		return NULL_POINTER;
	}
}


static Check_t QueueReset(Queue_t *Q)
{
	if(NULL != Q)
	{
		if(Q->Head==Q->Tail)
		{
			Q->Head = -1;
			Q->Tail = -1;
			return CQUEUE_EMPTY;
		}else{}
	}
	else
	{
		return NULL_POINTER;
	}
		
}

void QueueInitialize(Queue_t *Q)
{
	if(NULL != Q)
	{
		Q->Head = -1;
		Q->Tail = -1;
	}
	else
	{
		printf("Error!! You Path a NULL_POINTER\n");
	}
	
}

void EnqueueData(Queue_t *Q ,s32 value)
{
	if(NULL!=Q)
	{
		if(QueueFull(Q)==CQUEUE_FULL)
		{
			printf("Sorry!! The Queue is FULL\n");
		}
		else if(QueueEmpty(Q)==CQUEUE_EMPTY)
		{
			Q->Head = 0;
			Q->Tail = 0;
			Q->queue[Q->Tail]=value;
		}
		else
		{
			Q->Tail = (Q->Tail+1)%QUEUE_MAX;
			Q->queue[Q->Tail]=value;
		}	
	}
	else
	{
		printf("Error!! You Path a NULL_POINTER\n");
	}
}


void DequeueData(Queue_t *Q,s32 *Data)
{
	if(NULL != Q)
	{
		if(QueueEmpty(Q)==CQUEUE_EMPTY)
		{
			printf("Sorry!! The Queue is EMPTY\n");
		}
		else
		{
			*Data = Q->queue[Q->Head];
			if(Q->Head==Q->Tail)
			{
				QueueReset(Q);
			}
			else
			{
				Q->Head = (Q->Head + 1)%QUEUE_MAX;  
			}
		}
	}
	else
	{
		printf("Error!! You Path a NULL_POINTER\n");
	}
}


void DisPlay(Queue_t *Q)
{
	if(NULL != Q)
	{
		if(QueueEmpty(Q)==CQUEUE_EMPTY)
		{
		printf("Sorry!! The Queue is EMPTY\n");
		}
		else
		{
			u8 counter = 0;
			for(counter =Q->Head;counter!=Q->Tail;counter = (counter+1)%QUEUE_MAX)
			{
				printf("%d\t",Q->queue[counter]);
			}
			printf("%d",Q->queue[counter]);
		}
	}
	else
	{
		printf("Error!! You Path a NULL_POINTER\n");
	}
	
}