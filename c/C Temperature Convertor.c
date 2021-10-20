#include <stdio.h>
double F(double F){
    F = (F-32)*5/9;
    return F;
}

double C(double C){
    C = (C*9/5)+32;
    return C;
}

int main() {
    double temp;
    char format;
    printf("What is your temperature reading?\n");
    scanf("%lf", &temp);
        printf("%.1f C = %.1f F\n",temp,C(temp));
        printf("%.1f F = %.1f C",temp,F(temp));
}
