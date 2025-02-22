/*
Round robin algorithm implementation in C
*/
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
    struct Process* next;
};

struct Process* CreateP(int pid, int arrival, int burst) {
    struct Process* newP = (struct Process*)malloc(sizeof(struct Process));
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

void RoundRobin(struct Process* head, int quantum) {
    int current_time = 0;
    int completed = 0;
    int total_processes = 0;
    struct Process* temp = head;
    
    while (temp != NULL) {
        total_processes++;
        temp = temp->next;
    }
    
    while (completed != total_processes) {
        temp = head;
        while (temp != NULL) {
            if (temp->at <= current_time && temp->rt > 0) {
                if (temp->rt <= quantum) {
                    current_time += temp->rt;
                    temp->rt = 0;
                    temp->ct = current_time;
                    temp->tat = temp->ct - temp->at;
                    temp->wt = temp->tat - temp->bt;
                    completed++;
                } else {
                    current_time += quantum;
                    temp->rt -= quantum;
                }
            }
            temp = temp->next;
        }
        
        int all_greater = 1;
        temp = head;
        while (temp != NULL) {
            if (temp->at <= current_time && temp->rt > 0) {
                all_greater = 0;
                break;
            }
            temp = temp->next;
        }
        if (all_greater) {
            current_time++;
        }
    }
}

int main() {
    struct Process* head = NULL;
    struct Process* temp = NULL;
    int n, quantum, pid, arrival, burst;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    
    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &pid);
        printf("Arrival Time: ");
        scanf("%d", &arrival);
        printf("Burst Time: ");
        scanf("%d", &burst);
        
        struct Process* newP = CreateP(pid, arrival, burst);
        
        if (head == NULL) {
            head = newP;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newP;
        }
    }
    
    RoundRobin(head, quantum);
    
    printf("\nProcess Details:\n");
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    temp = head;
    float avg_turnaround = 0, avg_waiting = 0;
    
    while (temp != NULL) {
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
    
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
