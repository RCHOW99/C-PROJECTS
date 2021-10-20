#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*
 * COP 3515 – Summer Semester, 2021
 *
 * Homework #3: Go Green, Go Home
 *
 * (Raad Chowdhury)
 *
 */

void print_floors1_10(char g[10][10],char ar[10][10]){
    printf("Floor 1 to 10\n");
    int p =0;
    int o = 1;
    for (int i = 0; i < 10; i++) {
        printf("Floor %d {",o);
        o++;
        for (int j = 0; j < 10; j++) {
            printf("[%c %c], ",g[i][j],ar[i][j]);
            switch (p) {
                case 9: printf("}\n");
                    break;
                case 19: printf("}\n");
                    break;
                case 29: printf("}\n");
                    break;
                case 39: printf("}\n");
                    break;
                case 49: printf("}\n");
                    break;
                case 59: printf("}\n");
                    break;
                case 69: printf("}\n");
                    break;
                case 79: printf("}\n");
                    break;
                case 89: printf("}\n");
                    break;
                case 99: printf("}\n");
            }
            p++;
        }
    }
    printf("\n");
}

void print_patient_color(char Statusmult[10][10],int e, int g1, int y, int r, int p){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(Statusmult[i][j] == 'E'){
                e++;
            }
            if(Statusmult[i][j] == 'G'){
                g1++;
            }
            if(Statusmult[i][j] == 'Y'){
                y++;
            }
            if(Statusmult[i][j] == 'R'){
                r++;
            }
            if(Statusmult[i][j] == 'P'){
                p++;
            }
        }
    }
    printf("Number of empty beds: %d\n",e);
    printf("Number of patients who are in the Green status: %d\n",g1);
    printf("Number of patients who are in the Yellow status: %d\n",y);
    printf("Number of patients who are in the Red status: %d\n",r);
    printf("Number of patients who are in the Purple status: %d\n\n",p);
}


int main() {
    FILE *text;
    char txt[10];
    text = fopen("HW #3 Data.txt", "r");
    int len = 0;
    char Gender[100];
    char Status[100];
    char Age[3];
    int int_Age[100];
    while (fgets(txt, 10, text) != NULL) {
        strcpy(Age, "");
        Gender[len] = txt[0];
        Status[len] = txt[2];
        Age[0] = txt[4];
        Age[1] = txt[5];
        int_Age[len] = atoi(Age);
        len++;
    }



    int counter[10][10];
    int counterw[10][10];
    int counterw2[10][10];
    char Statusmult[10][10];
    int Agemult[10][10];
    char GenderMult[10][10];
    int k = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            Statusmult[i][j] = Status[k];
            Agemult[i][j] = int_Age[k];
            GenderMult[i][j] = Gender[k];
            counter[i][j] =0;
           counterw[i][j]=0;
            counterw2[i][j]=0;
            k++;
        }
    }

    fclose(text);

    int days = 0;
    int z =0;
    int g1 =0;
    int y =0;
    int r =0;
    int p =0;
    int e=0;
    printf("The Default Values\n");
    print_floors1_10(Statusmult,GenderMult);
    print_patient_color(Statusmult,e,g1,y,r,p);
    e=0;
    g1=0;
    y=0;
    r=0;
    p=0;


// Creates a new set of random values each run
srand ( time(NULL));


for (int h = 0; h < 10; h++) {
    for (int g = 0; g < 10; g++) {
            while (Statusmult[h][g] != 'E') { // E represents empty for a empty bed when the patient is finally fully recovered and out of the hospital.


                        for (int i = 0; i < 10; i++) {
                            for (int j = 0; j < 10; j++) {
                                if (Statusmult[i][j] != 'E') {


                                    if (Statusmult[i][j] == 'G') {
                                        int probgw = (rand() % 100);
                                        if (probgw > 50 && probgw < 75 && counter[i][j]==0) {
                                            Statusmult[i][j] = 'Y';
                                            counterw[i][j] +=1;
                                        } else {
                                            int probgb = (rand() % 100);
                                            if (probgb > 75) {
                                                Statusmult[i][j] = 'E';
                                            }
                                        }
                                    }



                                    if (Statusmult[i][j] == 'Y' && counterw[i][j]==0) {
                                        int probyw = (rand() % 100);
                                        if (probyw > 40 && probyw < 60 && counter[i][j]==0) {
                                            Statusmult[i][j] = 'R';
                                            counterw[i][j]+=1;
                                        } else {
                                            int probyb = (rand() % 100);
                                            if (probyb > 60) {
                                                Statusmult[i][j] = 'G';
                                                counter[i][j]+=1;
                                            }
                                        }
                                    }


                                    if(Statusmult[i][j]=='R' && counterw[i][j]==0){ // counterw is a counter that increments if a patient color got worse and the patient needs 3 days to recover. Thus if the counter has a value that means the patient is still recovering and cannot get worse or better
                                        int probrw = (rand() % 100);
                                        if(probrw>20 && probrw<40 && counter[i][j]==0){ // If the correct probability is chosen and the counter for if a color turns positive is zero then the patient can be a worse color.
                                            Statusmult[i][j]='P';
                                            counterw[i][j]++;
                                        }else { // if a patient is not getting worse then a probability is taken and if the probability matches then the patient color will get better.
                                            int probrb = (rand() % 100);
                                            if(probrb>40){
                                                Statusmult[i][j]='Y';
                                                counter[i][j]+=1;
                                            }
                                        }
                                    }



                                    if(Statusmult[i][j]=='P'){// P is the last color so there is no probability of a worse color
                                        int probp = (rand() % 100);
                                        if(probp>30 && probp <40 ){
                                            Statusmult[i][j]='R';
                                            counter[i][j]+=1; // counter variable that corresponds with the index of the color positively changing. The variable is needed so the if a patient its getting better they cannot get worse again
                                        }
                                    }
                    }
                }
            }



                for (int i = 0; i < 10; ++i) {
                        for (int j = 0; j < 10; ++j) {


                            // Here the program will know the patient is in the 3 day recovery based on the counterw. After the if statement launches it will have a new counter called counterw2 that icrements until the 3 days are up. After the 3 days are up both counters reset.
                            if (Statusmult[i][j] == 'Y' && counterw[i][j]>0) {
                                Statusmult[i][j] = 'Y';
                                counterw2[i][j]+=1;
                                if(counterw2[i][j]==3){
                                    counterw2[i][j]=0;
                                    counterw[i][j]=0;
                                }
                            }



                            if (Statusmult[i][j] == 'R' && counterw[i][j]>0) {
                                Statusmult[i][j] = 'R';
                                counterw2[i][j]+=1;
                                if(counterw2[i][j]==3){
                                    counterw2[i][j]=0;
                                    counterw[i][j]=0;
                                }
                            }


                            if (Statusmult[i][j] == 'P' && counterw[i][j]>0) {
                                Statusmult[i][j] = 'P';
                                counterw2[i][j]+=1;
                                if(counterw2[i][j]==3){
                                    counterw2[i][j]=0;
                                    counterw[i][j]=0;
                                }
                            }

                        }
                    }

                    // Represents the Purple patients not changing for 3 days in the start due to getting worse
                    if (z!=3){
                        for (int i = 0; i < 10; ++i) {
                            for (int j = 0; j < 10; ++j) {
                                if(Statusmult[i][j]=='P'){
                                Statusmult[i][j]='P';
                                }
                            }
                        }
                        z++;
                    }

                for (int i = 0; i < 10; ++i) {
                    for (int j = 0; j < 10; ++j) {
                        if(Statusmult[i][j] == 'E'){
                            e++;
                        }
                        if(Statusmult[i][j] == 'G'){
                            g1++;
                        }
                        if(Statusmult[i][j] == 'Y'){
                            y++;
                        }
                        if(Statusmult[i][j] == 'R'){
                            r++;
                        }
                        if(Statusmult[i][j] == 'P'){
                            p++;
                        }
                    }
                }

                days++;
                print_floors1_10(Statusmult,GenderMult);
                printf("Number of empty beds: %d\n",e);
                printf("Number of patients who are in the Green status: %d\n",g1);
                printf("Number of patients who are in the Yellow status: %d\n",y);
                printf("Number of patients who are in the Red status: %d\n",r);
                printf("Number of patients who are in the Purple status: %d\n\n",p);
                e=0;
                g1=0;
                y=0;
                r=0;
                p=0;
                }
            }
        }
    printf("Number of days %d", days);
    }
/*
* COP 3515 – Summer Semester, 2021
*
* Homework #3: Go Green, Go Home
*
* (Raad Chowdhury)
*
*/
