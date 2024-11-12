#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#define WORD "Hello"

int main()
{
    int option;
    printf("Hello there! %s What would you like to calculate\n");
    printf("1. Rectangle\n");
    printf("2. Right Triangle\n");
    printf("3. Circle\n");
    scanf("%d", &option);



    // for
    // while .. do-while
    char go = 'y';
    while (go == 'y') {



    switch (option) {
    case 1:
        {
        int width;
        int height;

        printf("Whats da wit?\n");
        scanf("%d", &width);
        printf("Whats da high?\n");
        scanf("%d", &height);

        while (width < 0) {
            printf("I dont want negative width, enter it again");
            scanf("%d", width);
        }


        int area = width * height;
        printf("Total area: %d\n", area);
        }

        break;
    case 2:
        {
        float base;
        float height;
        printf("Enter base: ");
        scanf("%f", &base);
        printf("Enter height: ");
        scanf("%f", &height);
        float area = 0.5 * height * base;

        printf("Area of triangle: %f", area);
        }

        break;
    case 3:
        {
            float radius;
            scanf("%f", &radius);
            float area = M_PI * radius * radius;
            printf("Area: %f", area);
        }

        break;
    default:
        printf("No no no, choos the correct option\n");
        break;
    }

    printf("Would you like to continue? ");
    scanf(" %c", &go);
    }

    return 0;
}
