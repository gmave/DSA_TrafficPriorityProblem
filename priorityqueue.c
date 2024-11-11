#include "priorityqueue.h"

void initQueue(PriorityQueue *pq)
{
    pq->size = 0;
}
void enqueue(PriorityQueue *pq, TrafficMovement tm)
{
    if (pq->size >= MAX)
    {
        printf("Queue is full!\n");
        return;
    }

    int x = pq->size++;
    while (x > 0 && pq->data[(x - 1) / 2].priority > tm.priority)
    {
        pq->data[x] = pq->data[(x - 1) / 2];
        x = (x - 1) / 2;
    }
    pq->data[x] = tm;
}
TrafficMovement dequeue(PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("Queue is empty!\n");
        exit(1);
    }
    TrafficMovement minItem = pq->data[0];
    TrafficMovement lastItem = pq->data[--pq->size];
    int x = 0;
    while (x * 2 + 1 < pq->size)
    {
        int child = x * 2 + 1;
        if (child + 1 < pq->size && pq->data[child].priority > pq->data[child + 1].priority)
        {
            child++;
        }
        if (lastItem.priority <= pq->data[child].priority)
        {
            break;
        }
        pq->data[x] = pq->data[child];
        x = child;
    }
    pq->data[x] = lastItem;
    return minItem;
}
