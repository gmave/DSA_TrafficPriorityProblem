#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct TrafficMovement
{
    int priority;       // Priority of the movement
    char lane[20];      // "Main" or "Diversion"
    char direction[10]; // "Straight", "Left", "Right", or "Pedestrian"
    int time;           // Time in seconds needed for the movement
} TrafficMovement;

typedef struct PriorityQueue
{
    TrafficMovement data[MAX];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue *pq);
void enqueue(PriorityQueue *pq, TrafficMovement tm);
TrafficMovement dequeue(PriorityQueue *pq);
void populateQueue(PriorityQueue *pq);

#endif