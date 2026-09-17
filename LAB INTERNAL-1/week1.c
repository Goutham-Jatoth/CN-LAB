// #include <stdio.h>
// #include <string.h>

// int main() {
//     char data[100];
//     int frame_size, current_pos = 0;
//     int k, actual_frame_len;

//     printf("Enter the data string: ");
//     scanf("%s", data);

//     printf("Enter the desired frame size: ");
//     scanf("%d", &frame_size);

//     printf("\nThe Total number of chars are : %d", strlen(data));
//     printf("\nTransmitted Frames:\n");

//     while (current_pos < strlen(data)) {
//         if ((strlen(data) - current_pos) < frame_size)
//             actual_frame_len = strlen(data) - current_pos;
//         else
//             actual_frame_len = frame_size;

//         printf("%d ", actual_frame_len);

//         for (k = 0; k < actual_frame_len; k++)
//             printf("%c", data[current_pos + k]);

//         printf("\n");
//         current_pos += actual_frame_len;
//     }

//     return 0;
// }






// #include <stdio.h>
// #include <string.h>
// #define FLAG 'F'
// #define ESC 'E'
// int main() {
//     char data[100], stuffedData[200];
//     int i, j = 0;

//     printf("Enter the data string: ");
//     scanf("%s", data);

//     stuffedData[j++] = FLAG;

//     for (i = 0; i < strlen(data); i++) {
//         if (data[i] == FLAG || data[i] == ESC)
//             stuffedData[j++] = ESC;

//         stuffedData[j++] = data[i];
//     }

//     stuffedData[j++] = FLAG;
//     stuffedData[j] = '\0';

//     printf("Original Data: %s\n", data);
//     printf("Stuffed Data: %s\n", stuffedData);

//     return 0;
// }


#include <stdio.h>
#include <string.h>

int main() {
    char data[100], stuffedData[200];
    int i, count = 0, j = 0;

    printf("Enter the data: ");
    scanf("%s", data);

    for (i = 0; i < strlen(data); i++) {
        if (data[i] == '1') {
            count++;
            stuffedData[j++] = data[i];
        } else {
            count = 0;
            stuffedData[j++] = data[i];
        }

        if (count == 5) {
            count = 0;
            stuffedData[j++] = '0';
        }
    }

    stuffedData[j] = '\0';

    printf("Data after bit stuffing: %s\n", stuffedData);
    return 0;
}