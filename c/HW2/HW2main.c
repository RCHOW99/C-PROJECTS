#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 * COP 3515 – Summer Semester, 2021
 *
 * Homework #2: The Hospital Bed Problem
 *
 * (Raad Chowdhury)
 *
 */
void print_floors10_1(int ar[10][10],char g[10][10]){
    printf("Floor 10 to 1\n");
    int p =0;
    int o = 10;
    for (int i = 9; i > -1; i--) {
        printf("Floor %d {",o);
        o--;
        for (int j = 0; j < 10; j++) {
            printf("[%c %d], ",g[i][j], ar[i][j]);
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

struct towera {
    int Floorn[10][10];
    char gender[10][10];
};

void Scenario1(struct towera floors){
    printf("Default Values\n");
    print_floors10_1(floors.Floorn,floors.gender);

    int emptfl = 0;
    int emptbeds =0;

  //Loop that takes away 1 from each element of the 2d array in each run to represent a day being passed.
    for (int h = 0; h < 10; h++) {
        for (int g = 0; g < 10; g++) {
            while (floors.Floorn[h][g] != 0) {

                for (int i = 0; i < 10; ++i) {
                    for (int j = 0; j < 10; ++j) {
                        if (floors.Floorn[i][j] != 0) {
                            floors.Floorn[i][j] -= 1;
                        }
                        if(floors.Floorn[i][j]==0){
                            // if the days left is zero then their is no patient left in the bed so the gender variable turns into . to represent a empty bed
                            floors.gender[i][j]='.';
                            emptbeds++;
                        }
                    }
                }
                // If the patient with the most amount of days(highest element) in each floor(Floorn[i]) has zero days left then the floor is empty.
                if(floors.Floorn[9][0]==0){
                    emptfl++;
                }
                if(floors.Floorn[8][3]==0){
                    emptfl++;
                }
                if(floors.Floorn[7][1]==0){
                    emptfl++;
                }
                if(floors.Floorn[6][3]==0){
                    emptfl++;
                }
                if(floors.Floorn[5][5]==0){
                    emptfl++;
                }
                if(floors.Floorn[4][2]==0){
                    emptfl++;
                }
                if(floors.Floorn[3][3]==0){
                    emptfl++;
                }
                if(floors.Floorn[2][7]==0){
                    emptfl++;
                }
                if(floors.Floorn[1][3]==0){
                    emptfl++;
                }
                if(floors.Floorn[0][0]==0){
                    emptfl++;
                }
                printf("RUNNING SCENARIO 1: DO NOT MOVE PATIENTS\n");
                print_floors10_1(floors.Floorn,floors.gender);
                printf("Number of Covid beds: %d\n",100-emptbeds);
                printf("Number of empty beds: %d\n",emptbeds);
                printf("Number of Covid floors: %d\n",10-emptfl);
                printf("Number of empty floors: %d\n\n",emptfl);

                emptfl=0;
                emptbeds=0;
            }
        }
    }
}


    void Scenario2(struct towera floors){
        printf("Default Values\n");
        print_floors10_1(floors.Floorn,floors.gender);
    int emptfl = 0;
    int emptbeds =0;
        // Loop that takes away 1 from each element of the 2d array in each run to represent a day being passed.
        for (int h = 0; h < 10; h++) {
            for (int g = 0; g < 10; g++) {
                while (floors.Floorn[h][g] != 0) {

                    // A loop that brings a patient down a floor if the bottom patient has zero days left.
                    for (int i = 0; i < 9; ++i) {
                        for (int j = 0; j < 10; ++j) {
                            if (floors.Floorn[i][j] == 0) {
                                if (floors.Floorn[i + 1][j] != 0) {
                                    floors.Floorn[i][j] = floors.Floorn[i + 1][j];
                                    floors.gender[i][j] = floors.gender[i + 1][j];
                                    floors.Floorn[i + 1][j] = 0;
                                }
                            }
                        }
                    }


                    for (int i = 0; i < 10; ++i) {
                        for (int j = 0; j < 10; ++j) {
                            if (floors.Floorn[i][j] != 0) {
                                floors.Floorn[i][j] -= 1;
                            }
                            if (floors.Floorn[i][j] == 0) {
                                // if the days left is zero then their is no patient left in the bed so the gender variable turns into . to represent a empty bed
                                floors.gender[i][j]='.';
                                emptbeds++;
                            }
                        }
                    }


                    // If the patient with the most amount of days(highest element) in each floor(Floorn[i]) has zero days left then the floor is empty.
                    if(floors.Floorn[9][0]==0){
                        emptfl++;
                    }
                    if(floors.Floorn[8][3]==0){
                        emptfl++;
                    }
                    if(floors.Floorn[7][1]==0){
                        emptfl++;
                    }
                    if(floors.Floorn[6][3]==0){
                        emptfl++;
                    }
                    if(floors.Floorn[5][5]==0){
                        emptfl++;
                    }
                    if(floors.Floorn[4][2]==0){
                        emptfl++;
                    }
                    if(floors.Floorn[3][3]==0){
                        emptfl++;
                    }
                    if(floors.Floorn[2][7]==0){
                        emptfl++;
                    }
                    if(floors.Floorn[1][3]==0){
                        emptfl++;
                    }
                    if(floors.Floorn[0][0]==0){
                        emptfl++;
                    }
                    printf("RUNNING SCENARIO 2: MOVE PATIENTS\n");
                    print_floors10_1(floors.Floorn,floors.gender);
                    printf("Number of Covid beds: %d\n",100-emptbeds);
                    printf("Number of empty beds: %d\n",emptbeds);
                    printf("Number of Covid floors: %d\n",10-emptfl);
                    printf("Number of empty floors: %d\n\n",emptfl);
                    emptfl=0;
                    emptbeds=0;
                }
            }
        }
};

int main() {
    FILE *textlen;
    char txt[10];
    textlen = fopen("HW #2 Data.txt", "r");

    int len = 0;
    char gender[100];
    char days[3];
    int intdays[100];
    while (fgets(txt, 10, textlen) != NULL) {
        strcpy(days, "");
        gender[len] = txt[0];
        days[0] = txt[2];
        days[1] = txt[3];
        intdays[len] = atoi(days);
        len++;
    }


    struct towera floors;

    int k = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            floors.Floorn[i][j] = intdays[k];
            floors.gender[i][j] = gender[k];
            k++;
        }
    }

    fclose(textlen);

    int mode;
    printf("What Scenario Do You Want To Run\n");
    printf("Type 1 To Run Scenario 1: Do Not Move Patients\n");
    printf("Type 2 To Run Scenario 2: Move Patients\n");
    scanf("%d", &mode);
    if (mode == 1) {
        Scenario1(floors);
    }
    if (mode == 2) {
        Scenario2(floors);
    }
}
/*
 * COP 3515 – Summer Semester, 2021
 *
 * Homework #2: The Hospital Bed Problem
 *
 * (Raad Chowdhury)
 *
 */
