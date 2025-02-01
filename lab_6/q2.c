// Implement non premptive SJF using c language using structure and linked list .

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

struct process *find_next_process(struct process *head, int current_time)
{
    struct process *selected = NULL;
    struct process *temp = head;

    while (temp != NULL)
    {
        if (temp->at <= current_time)
        {
            if (selected == NULL || temp->bt < selected->bt ||
                (temp->bt == selected->bt && temp->at < selected->at))
            {
                selected = temp;
            }
        }
        temp = temp->next;
    }
    return selected;
}

void delete_process(struct process **head, struct process *target)
{
    if (*head == target)
    {
        *head = target->next;
        return;
    }
    struct process *temp = *head;
    while (temp->next != target)
    {
        temp = temp->next;
    }
    temp->next = target->next;
}

void calculate_times(struct process **head)
{
    struct process *completed = NULL;
    int current_time = 0;

    while (*head != NULL)
    {
        struct process *selected = find_next_process(*head, current_time);

        if (selected == NULL)
        {
            current_time++;
            continue;
        }

        if (current_time < selected->at)
        {
            current_time = selected->at;
        }

        selected->wt = current_time - selected->at;
        selected->tat = selected->wt + selected->bt;
        current_time += selected->bt;

        delete_process(head, selected);
        selected->next = completed;
        completed = selected;
    }

    *head = completed;
}

void display(struct process *head)
{
    struct process *temp = head;
    float sum_wt = 0, sum_tat = 0;
    int count = 0;

    printf("\nPID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    while (temp != NULL)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", temp->pid, temp->at, temp->bt, temp->wt, temp->tat);
        sum_wt += temp->wt;
        sum_tat += temp->tat;
        count++;
        temp = temp->next;
    }

    printf("\nAverage Waiting Time: %.2f", sum_wt / count);
    printf("\nAverage Turnaround Time: %.2f\n", sum_tat / count);
}

int main()
{
    struct process *head = NULL;
    int n, at, bt;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter Arrival Time of Process %d: ", i);
        scanf("%d", &at);
        printf("Enter Burst Time of Process %d: ", i);
        scanf("%d", &bt);
        insert(&head, i, at, bt);
    }

    calculate_times(&head);
    display(head);

    return 0;
}
