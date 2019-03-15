// PRESSSSIIOOOOONNNN
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    time_t t;
    srand((unsigned ) &t);   // Initialization, should only be called once.
    char chars[] = {'a', 'b', 'c'};
    int nums[] = {1, 5, 2};
    int sizeofcharre = 0;
    char    newcharre[] = {};
    while (chars[sizeofcharre])
        sizeofcharre++;
    int total = 0;
    int r = 0;
    while (r < sizeofcharre)
        total += nums[r++];
    int pick = rand() % total;
    printf("pick == %d\n", pick);
    printf("total == %d\n", total);
    int topick = 0;
    while (pick > 0)
    {
        pick -= nums[topick];
        topick++;
    }
    topick != 0 ? topick-- : 0;
    printf("to pick == %c\n", chars[topick]);
    printf("to pick nb == %d\n", topick);
    return (0);
}
