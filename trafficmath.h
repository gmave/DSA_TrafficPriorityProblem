#ifndef TRAFFICMATH_H
#define TRAFFICMATH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priorityqueue.h"

int mainLanePedestrianExists(PriorityQueue *pq);
int mainLaneVehicleExists(PriorityQueue *pq, const char *direction);
int calculateTotalTimeForMainPedestrian(PriorityQueue *pq);
void saveTrafficData(PriorityQueue *pq, const char *filename);

#endif