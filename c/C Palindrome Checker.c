#include <stdio.h>
#include <string.h>

int main() {
    char num[9];
    char num2[9];
    printf("Enter a number to check if it is a palindrome.\n");
    scanf("%s",num);
    strcpy( num2,num);
    strrev(num2);
    if(strcmp(num2,num)!=0){
        printf("Not Palindrome");
    }
    else if(strcmp(num2,num)==0){;
        printf("Palindrome");
    }
}
