// Implement Round Robin Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid; // Process id
    int at;  // Arrival Time
    int bt;  // Burst Time
    int rt;  // Response Time
    int ct;  // Completion Time
    int tat;
    int wt;
    struct Process *next;
};

// Creating new process here
struct Process *CreateP(int pid, int arrival, int burst)
{
    struct Process *newP = (struct Process *)malloc(sizeof(struct Process));
    newP->pid = pid;
    newP->at = arrival;
    newP->bt = burst;
    newP->rt = burst;
    newP->ct = 0;
    newP->tat = 0;
    newP->wt = 0;
    newP->next = NULL;
    return newP;
}

// Simulating Round Robin Scheduling Algorithm
void RoundRobin(struct Process *head, int timeQuantum)
{
    int currentTime = 0;
    int done;
    struct Process *p;

    while (1)
    {
        int flag = 0;
        p = head;
        while (p != NULL)
        {

            if (p->rt > 0 && p->at <= currentTime)
            {
                flag = 1;
                if (p->rt > timeQuantum)
                {
                    currentTime += timeQuantum;
                    p->rt -= timeQuantum;
                }
                else
                {
                    currentTime += p->rt;
                    p->rt = 0;
                    p->ct = currentTime;
                    p->tat = p->ct - p->at;
                    p->wt = p->tat - p->bt;
                }
            }
            p = p->next;
        }

        if (flag == 0)
        {
            int minArrival = -1;
            p = head;
            while (p != NULL)
            {
                if (p->rt > 0)
                {
                    if (minArrival == -1 || p->at < minArrival)
                    {
                        minArrival = p->at;
                    }
                }
                p = p->next;
            }

            if (minArrival == -1)
            {
                break;
            }

            currentTime = minArrival;
        }

        done = 1;
        p = head;
        while (p != NULL)
        {
            if (p->rt > 0)
            {
                done = 0;
                break;
            }
            p = p->next;
        }
        if (done == 1)
            break;
    }
}

int main()
{
    struct Process *head = NULL;
    struct Process *temp;
    int n, pid, arrival, burst;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    int timeQuantum;
    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for process %d:\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &pid);
        printf("Arrival Time: ");
        scanf("%d", &arrival);
        printf("Burst Time: ");
        scanf("%d", &burst);

        struct Process *newP = CreateP(pid, arrival, burst);

        if (head == NULL)
        {
            head = newP;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newP;
        }
    }

    RoundRobin(head, timeQuantum);

    printf("\nProcess Details:\n");
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    temp = head;
    float avg_turnaround = 0, avg_waiting = 0;

    while (temp != NULL)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               temp->pid, temp->at, temp->bt,
               temp->ct, temp->tat, temp->wt);
        avg_turnaround += temp->tat;
        avg_waiting += temp->wt;
        temp = temp->next;
    }

    avg_turnaround /= n;
    avg_waiting /= n;
    printf("\nAverage Turnaround Time: %.2f", avg_turnaround);
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting);

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
