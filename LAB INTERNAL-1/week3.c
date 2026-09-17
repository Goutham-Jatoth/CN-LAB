#include <stdio.h>

int main()
{
    int frames, win, ack = 0, i;

    printf("enter no.of frames\n");
    scanf("%d", &frames);

    printf("enter window size\n");
    scanf("%d", &win);

    while (ack < frames)
    {
        for (i = ack; i < ack + win && i < frames; i++)
            printf("Frame %d has been transmitted.\n", i);

        printf("\nPlease enter the Acknowledgement number: ");
        scanf("%d", &ack);

        if (ack > i)
        {
            if (ack == frames)
                printf("Total frames were sent");
            else
            {
                printf("invalid and resending the frame\n");
                ack = i - win;
            }
        }
    }

    return 0;
}