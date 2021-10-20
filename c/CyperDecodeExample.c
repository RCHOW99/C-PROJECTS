#include <stdio.h>

int main() {
   char cypher[] = ")& ! 7//$#(5#+ #/5,$ #(5#+ 7//$, (/7 -5#( 7//$ 7/5,$ ! 7//$#(5#+ #(5#+?";

    int arrsize;

    arrsize = (sizeof cypher/ sizeof *cypher)-1;

    int cyphernum[arrsize];

    for (int i = 0; i < arrsize; i++) {
        cyphernum[i] = (int)cypher[i];
        //printf("%d %c\n",cyphernum[i],cypher[i]);
    }

    int key[75];
    for (int i = 0; i < 75; i++) {
        key[i]= i;
        //printf("%d\n",key[i]);
    }


    int i =0;
    int j =0;

    int index = -1;
   while(key[i]!=74){
    //printf("%c",cyphernum[j]+key[i]);
    j++;
    if(cyphernum[j]==63){
        j=0;
        i++;
        index++;
        //printf(" %d\n\n",index);
    }
   }

    printf("The decoded cypher is\n");
    for (int k = 0; k < arrsize-1; k++) {
        printf("%c",cyphernum[k]+key[64]);
    }
    printf("\nThe key is a a shift of %d",key[64]);






}
