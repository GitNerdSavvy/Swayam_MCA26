#include<stdio.h>

int main() {
    int n500=0, n200=0, n100=0, n50=0, n20=0, n10=0, n5=0, n2=0, n1=0;
    int value;
    int Number = 1;

    printf("Enter a value: ");
    scanf("%d", &value);

    switch(Number) {
        case 1:
            n500 = value / 500;
            value = value % 500;
            printf("Number of 500 Notes: %d\n", n500);
        case 2:
            n200 = value / 200;
            value = value % 200;
            printf("Number of 200 Notes: %d\n", n200);
        case 3:
            n100 = value / 100;
            value = value % 100;
            printf("Number of 100 Notes: %d\n", n100);
        case 4:
            n50 = value / 50;
            value = value % 50;
            printf("Number of 50 Notes: %d\n", n50);
        case 5:
            n20 = value / 20;
            value = value % 20;
            printf("Number of 20 Notes: %d\n", n20);
        case 6:
            n10 = value / 10;
            value = value % 10;
            printf("Number of 10 Notes: %d\n", n10);
        case 7:
            n5 = value / 5;
            value = value % 5;
            printf("Number of 5 Notes: %d\n", n5);
        case 8:
            n2 = value / 2;
            value = value % 2;
            printf("Number of 2 Notes: %d\n", n2);
       
        case 9:       
           n1 = value ;
            printf("Number of 1 Notes: %d\n", n1);
            default:
            printf("Completed");
    }

    return 0;
}
