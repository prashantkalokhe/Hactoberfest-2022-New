#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 5

int current[MAX_PROCESSES][MAX_RESOURCES];
int maximum_claim[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];
int allocation[MAX_RESOURCES];
int maxres[MAX_RESOURCES];
bool running[MAX_PROCESSES];

void calculateAvailableResources(int processes, int resources) {
    for (int j = 0; j < resources; j++) {
        allocation[j] = 0; // Reset allocation
        for (int i = 0; i < processes; i++) {
            allocation[j] += current[i][j];
        }
        available[j] = maxres[j] - allocation[j];
    }
}

bool isSafeState(int processes, int resources) {
    bool finished[MAX_PROCESSES] = { false };
    int work[MAX_RESOURCES];
    for (int j = 0; j < resources; j++) {
        work[j] = available[j];
    }

    for (int count = 0; count < processes;) {
        bool found = false;
        for (int i = 0; i < processes; i++) {
            if (!finished[i]) {
                bool canAllocate = true;
                for (int j = 0; j < resources; j++) {
                    if (maximum_claim[i][j] - current[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < resources; j++) {
                        work[j] += current[i][j];
                    }
                    finished[i] = true;
                    count++;
                    printf("Process %d is executing\n", i + 1);
                    found = true;
                }
            }
        }
        if (!found) {
            printf("\nThe processes are in an unsafe state.\n");
            return false;
        }
    }
    printf("\nThe processes are in a safe state.\n");
    printf("Available Resources:\n");
    for (int j = 0; j < resources; j++) {
        printf("\t%d", available[j]);
    }
    printf("\n");
    return true;
}

int main() {
    int processes, resources;

    printf("\nEnter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &processes);

    printf("\nEnter number of resources (max %d): ", MAX_RESOURCES);
    scanf("%d", &resources);

    printf("\nEnter Claim Vector:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &maxres[i]);
    }

    printf("\nEnter Allocated Resources Table:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &current[i][j]);
        }
    }

    printf("\nEnter Maximum Claim Table:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &maximum_claim[i][j]);
        }
    }

    calculateAvailableResources(processes, resources);

    printf("\nAllocated Resources:\n");
    for (int i = 0; i < resources; i++) {
        printf("\t%d", allocation[i]);
    }

    printf("\nAvailable Resources:\n");
    for (int i = 0; i < resources; i++) {
        printf("\t%d", available[i]);
    }
    printf("\n");

    isSafeState(processes, resources);

    return 0;
}
