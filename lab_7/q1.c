/*
Preemptive SJF algorithm implementation in C using structure / linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
    struct Process *next;
};

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

struct Process *findMinRem(struct Process *head, int current_time)
{
    struct Process *temp = head;
    struct Process *minProcess = NULL;
    int min_remaining = 999999;

    while (temp != NULL)
    {
        if (temp->at <= current_time && temp->rt > 0)
        {
            if (temp->rt < min_remaining)
            {
                min_remaining = temp->rt;
                minProcess = temp;
            }
        }
        temp = temp->next;
    }
    return minProcess;
}

void preemptiveSJF(struct Process *head)
{
    int current_time = 0;
    int completed = 0;
    int total_processes = 0;
    struct Process *temp = head;

    while (temp != NULL)
    {
        total_processes++;
        temp = temp->next;
    }

    while (completed != total_processes)
    {
        struct Process *current = findMinRem(head, current_time);

        if (current == NULL)
        {
            current_time++;
            continue;
        }

        current->rt--;
        current_time++;

        if (current->rt == 0)
        {
            completed++;
            current->ct = current_time;
            current->tat = current->ct - current->at;
            current->wt = current->tat - current->bt;
        }
    }
}

int main()
{
    struct Process *head = NULL;
    struct Process *temp;
    int n, pid, arrival, burst;

    printf("Enter number of processes: ");
    scanf("%d", &n);

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

    preemptiveSJF(head);

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
