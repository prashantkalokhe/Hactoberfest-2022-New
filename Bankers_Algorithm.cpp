//
// Created by Sumit on 17/10/22.
//

#include<stdio.h>
#define rep(i,a,b) for(int i=a; i<b; i++)
int current[5][5], maximum_claim[5][5], available[5];
int allocation[5] = {0, 0, 0, 0, 0};
int maxres[5], running[5], safe = 0;
int counter = 0, i , j, exec, resources, processes, k = 1;

int main()
{
    printf("\nEnter number of processes: ");
    scanf("%d", &processes);

    rep(i,0,processes){
        running[i] = 1;
        counter++;
    }
    printf("\nEnter number of resources: ");
    scanf("%d", &resources);
    printf("\nEnter Claim Vector:");
    rep(i,0,resources){
        scanf("%d", &maxres[i]);
    }

    printf("\nEnter Allocated Resources Table:\n");
    rep(i,0,processes){
        rep(i,0,resources){
            scanf("%d", &current[i][j]);
        }
    }

    printf("\nEnter Maximum Claim Table:\n");
    rep(i,0,processes){
        rep(j,0,resources){
            scanf("%d", &maximum_claim[i][j]);
        }
    }

    printf("\nThe Claim Vector is: ");
    rep(i,0,resources){
        printf("\t%d", maxres[i]);
    }

    printf("\nThe Allocated Resources Table:\n");
    rep(i,0,processes){
        rep(j,0,resources){
            printf("\t%d", current[i][j]);
        }
        printf("\n");
    }

    printf("\nThe Maximum Claim Table:\n");
    rep(i,0,processes){
        rep(j,0,resources){
            printf("\t%d", maximum_claim[i][j]);
        }
        printf("\n");
    }

    rep(i,0,processes){
        rep(j,0,resources){
            allocation[j] += current[i][j];
        }
    }

    printf("\nAllocated Resources:");
    rep(i,0,resources){
        printf("\t%d", allocation[i]);
    }
    rep(i,0,resources){
        available[i] = maxres[i] - allocation[i];
    }

    printf("\nAvailable Resources:");
    rep(i,0,resources){
        printf("\t%d", available[i]);
    }
    printf("\n");


    while(counter != 0){
        safe = 0;
        rep(i,0,processes){
            if(running[i]){
                exec = 1;
                rep(j,0,resources){
                    if(maximum_claim[i][j] - current[i][j] > available[j]){
                        exec = 0;
                        break;
                    }
                }
            }

            if(exec){
                printf("\nProcess%d is executing\n", i + 1);
                counter--;
                safe = 1;
                rep(j,0,resources){
                    available[j] += current[i][j];
                }
                break;
            }
        }
    }

    if(!safe){
        printf("\nThe processes are in unsafe state.\n");
        //break;
    }
    else{
        printf("\nThe process is in safe state");
        printf("\nAvailable Vector:");
        rep(i,0,resources){
            printf("\t%d", available[i]);
        }
        printf("\n");
    }
}
