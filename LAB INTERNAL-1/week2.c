#include <stdio.h>
#include <string.h>

void crc(char d[], char p[], int n, int k)
{
    for(int i=0;i<n;i++)
        if(d[i]=='1')
            for(int j=0;j<k;j++)
                d[i+j]=(d[i+j]==p[j])?'0':'1';

    printf("%s",&d[n]);
}

int main()
{
    char data[100], p[100], code[100];
    int n,k;

    printf("Enter data: ");
    scanf("%s",data);

    printf("Enter Polynomial: ");
    scanf("%s",p);

    n=strlen(data);
    k=strlen(p);

    for(int i=0;i<k-1;i++)
        data[n+i]='0';

    printf("Data with zeros: %s\n\n",data);

    printf("CRC at sender side: ");
    crc(data,p,n,k);

    printf("\n\nEnter codeword (Data + CRC): ");
    scanf("%s",code);

    printf("CRC at receiver side: ");
    crc(code,p,n,k);

    return 0;
}