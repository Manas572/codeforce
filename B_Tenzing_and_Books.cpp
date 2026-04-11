#include <stdio.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

void sort_by_arrival(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void sort_by_id(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].id > p[j + 1].id) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 5;
    struct Process p[5] = {
        {1, 12, 6},
        {2, 2, 3},
        {3, 25, 4},
        {4, 20, 2},
        {5, 7, 4}
    };

    sort_by_arrival(p, n);

    int current_time = 0;
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;
        }
        
        p[i].completion_time = current_time + p[i].burst_time;
        p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
        
        current_time = p[i].completion_time;
        
        total_tat += p[i].turn_around_time;
        total_wt += p[i].waiting_time;
    }

    sort_by_id(p, n);

    printf("P.NO\tAT\tBT\tCT\tTAT\tWT\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[i].id, p[i].arrival_time, p[i].burst_time, 
               p[i].completion_time, p[i].turn_around_time, p[i].waiting_time);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    return 0;
}