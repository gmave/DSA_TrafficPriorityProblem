#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priorityqueue.h"
#include "trafficmath.h"
void populateQueue(PriorityQueue *pq)
{
    TrafficMovement movements[] = {
        {4, "Main", "Pedestrian", 15},
        {8, "Main", "Right", 30},
        {1, "Diversion", "Left", 17},
        {2, "Diversion", "Pedestrian", 15},
        {3, "Main", "Straight", 10},
        {7, "Diversion", "Straight", 10},
        {5, "Main", "Left", 21},
        {6, "Diversion", "Left", 17},
    };
    int numMovements = sizeof(movements) / sizeof(movements[0]);
    for (int i = 0; i < numMovements; i++)
    {
        enqueue(pq, movements[i]);
    }
}
int main()
{
    PriorityQueue store;
    initQueue(&store);
    populateQueue(&store);

    saveTrafficData(&store, "traffic.dat");

    int timeUntilPedestrian = calculateTotalTimeForMainPedestrian(&store);
    if (timeUntilPedestrian != -1)
    {
        printf("Total time until main lane pedestrian can cross: %d seconds\n", timeUntilPedestrian);
    }
    else
    {
        printf("Main lane pedestrian crossing not found.\n");
    }

    return 0;
}
