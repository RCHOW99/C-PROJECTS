#include <stdio.h>

int main() {
    int j=0;
    int x=0;
    int y=1;
    for (int k = 1; k<13; k++){
        for(int i = 1+j; i<13+x; i+=y){
            printf("%d ",i);
        }
        printf("\n");
        j++;
        x=x+12;
        y++;
    }

    int number =6;
    int guess;

    while (guess!=number) {
        printf("\nEnter your guess 1-10:");
        scanf("%d",&guess);

        if (guess < number) {
            printf("Too low!\n");
        }
        if (guess > number) {
            printf("Too high!\n");
        }
    }
    printf("You guessed it!");
}
