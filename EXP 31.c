#include <stdio.h>

int main() {
    int pages[] = {1, 2, 3, 4, 1, 2, 5};
    int frames[3];
    int i, j, k = 0, faults = 0, found;

    for(i = 0; i < 3; i++)
        frames[i] = -1;

    for(i = 0; i < 7; i++) {
        found = 0;
        for(j = 0; j < 3; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frames[k] = pages[i];
            k = (k + 1) % 3;
            faults++;
        }
    }

    printf("Total Page Faults (FIFO): %d\n", faults);
    return 0;
}
