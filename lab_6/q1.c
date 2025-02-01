// Implement FCFS algorithm using C language using structure and linked list.

#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid;
    int at;
    int bt;
    int wt;
    int tat;
    struct process *next;
};

void insert(struct process **head, int pid, int at, int bt)
{
    struct process *new_p = (struct process *)malloc(sizeof(struct process));
    new_p->pid = pid;
    new_p->at = at;
    new_p->bt = bt;
    new_p->wt = 0;
    new_p->tat = 0;
    new_p->next = NULL;

    if (*head == NULL)
    {
        *head = new_p;
    }
    else
    {
        struct process *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_p;
    }
}

void display(struct process *head)
{
    struct process *temp = head;
    float sum_wt = 0, sum_tat = 0;
    int count = 0;
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    while (temp != NULL)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", temp->pid, temp->at, temp->bt, temp->wt, temp->tat);
        sum_wt += temp->wt;
        sum_tat += temp->tat;
        count++;
        temp = temp->next;
    }
    printf("Average waiting time - %.2f ", sum_wt / count);
    printf("Average Turnaround time - %.2f ", sum_tat / count);
}

void fcfs(struct process *head)
{
    struct process *temp = head;
    int current_time = 0;
    while (temp != NULL)
    {
        if (current_time < temp->at)
        {
            current_time = temp->at;
        }
        temp->wt = current_time - temp->at;
        temp->tat = temp->wt + temp->bt;
        current_time += temp->bt;
        temp = temp->next;
    }
}

int main()
{
    struct process *head = NULL;
    int n;
    int at, bt;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &at);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &bt);
        insert(&head, i, at, bt);
    }
    fcfs(head);
    display(head);
}