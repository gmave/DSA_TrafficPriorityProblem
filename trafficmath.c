#include "trafficmath.h"
void saveTrafficData(PriorityQueue *pq, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (!file)
    {
        perror("Unable to open file");
        return;
    }

    fwrite(pq->data, sizeof(TrafficMovement), pq->size, file);
    fclose(file);

    return;
}
int calculateTotalTimeForMainPedestrian(PriorityQueue *pq)
{
    int totalTime = 0;
    while (pq->size > 0)
    {
        TrafficMovement temp = dequeue(pq);

        // Check if the current event is the main lane pedestrian crossing
        if (strcmp(temp.lane, "Main") == 0 && strcmp(temp.direction, "Pedestrian") == 0)
        {
            // Return the accumulated time when the main lane pedestrian is found
            return totalTime;
        }

        // Skip diversion events if there's a higher priority main lane event
        if ((strcmp(temp.lane, "Diversion") == 0) &&
            ((strcmp(temp.direction, "Pedestrian") == 0 && mainLanePedestrianExists(pq)) ||
             (strcmp(temp.direction, "Straight") == 0 && mainLaneVehicleExists(pq, "Straight")) ||
             (strcmp(temp.direction, "Left") == 0 && mainLaneVehicleExists(pq, "Left")) ||
             (strcmp(temp.direction, "Right") == 0 && mainLaneVehicleExists(pq, "Right"))))
        {
            continue; // Skip time for diversion lane event if corresponding main lane event exists
        }

        totalTime += temp.time;
    }
    return -1;
}
int mainLanePedestrianExists(PriorityQueue *pq)
{
    for (int i = 0; i < pq->size; i++)
    {
        if (strcmp(pq->data[i].lane, "Main") == 0 && strcmp(pq->data[i].direction, "Pedestrian") == 0)
        {
            return 1; // Found a main lane pedestrian!
        }
    }
    return 0;
}
int mainLaneVehicleExists(PriorityQueue *pq, const char *direction)
{
    for (int i = 0; i < pq->size; i++)
    {
        if (strcmp(pq->data[i].lane, "Main") == 0 && strcmp(pq->data[i].direction, direction) == 0)
        {
            return 1; // Found a matching main lane vehicle
        }
    }
    return 0;
}