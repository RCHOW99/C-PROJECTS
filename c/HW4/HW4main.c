#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 * COP 3515 – Summer Semester, 2021
 *
 * Homework #4: Securing The Vaccine
 *
 * (Raad Chowdhury)
 *
 */
int main() {
    FILE *cyphertxt1;
    char text1[25];
    cyphertxt1 = fopen("HW #4 Data - Encrypted.txt", "r");
    int h = 0;
    char textarray[820][25];
    while (fgets(text1, 25, cyphertxt1) != NULL) {
        strcpy(textarray[h], text1);
        h++;
    }
    fclose(cyphertxt1);



    int key2 = -3;
    char textdecyp[820][25];
    char *ptextdecyp[820];

    for (int i = 0; i < 820; ++i) {
        for (int j = 0; j < 25; ++j) {
            if (textarray[i][j] != '\0') {
                textdecyp[i][j] = textarray[i][j] + key2;
            }
        }
        ptextdecyp[i] = textdecyp[i];
    }



    char p1_tcell[4];
    int p1_tcells[60];
    int k = 0;
    for (int i = 0; i < 60; i++) {
        for (int j = 5; j < 9; j++) {
            p1_tcell[k] = textdecyp[i][j];
            k++;
        }
        p1_tcells[i] = atoi(p1_tcell);
        k = 0;
    }

    int count1 = 0;
    for (int i = 0; i < 15; i++) {
        if (p1_tcells[i] > 1200) {
            count1++;
        }
    }
    if (count1 <= 10) {
        printf("Astrazeneca passed phase 0\n");
    } else {
        printf("Astrazeneca did not pass phase 0\n");
    }

    count1 = 0;
    for (int i = 15; i < 30; i++) {
        if (p1_tcells[i] > 1200) {
            count1++;
        }
    }
    if (count1 <= 10) {
        printf("Johnson & Johnson passed phase 0\n");
    } else {
        printf("Johnson & Johnson did not pass phase 0\n");
    }

    count1 = 0;
    for (int i = 30; i < 45; i++) {
        if (p1_tcells[i] > 1200) {
            count1++;
        }
    }
    if (count1 <= 10) {
        printf("Moderna passed phase 0\n");
    } else {
        printf("Moderna did not pass phase 0\n");
    }

    count1 = 0;
    for (int i = 45; i < 60; i++) {
        if (p1_tcells[i] > 1200) {
            count1++;
        }
    }
    if (count1 <= 10) {
        printf("Novavax passed phase 0\n");
    } else {
        printf("Novavax did not pass phase 0\n");
    }



    int l = 60;
    char P2[60][25];
    for (int i = 0; i < 60; i++) {
        strcpy(P2[i], textdecyp[l]);
        l++;
    }
    char side_effect_status[6];
    char side_effect_statuses[60][6];
    int p = 0;
    k = 0;
    for (int i = 0; i < 60; i++) {
        for (int j = 5; j < 15; ++j) {
            if (P2[i][j] == '0' || P2[i][j] == '1') {
                side_effect_status[k] = P2[i][j];
                k++;
            }
        }
        strcpy(side_effect_statuses[p], side_effect_status);
        k = 0;
        p++;
    }
    printf("\n");

    int min_side_effects = (20 * 30) / 100;
    int count2 = 0;
    int count3 = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 6; j++) {
            if (side_effect_statuses[i][j] == '1') {
                count2++;
            }
        }
        if (count2 > 0) {
            count3++;
        }
        count2 = 0;
    }
    if (count3 < min_side_effects) {
        printf("Astrazeneca passed phase 1\n");
    } else {
        printf("Astrazeneca did not pass phase 1\n");
    }

    count3 = 0;
    count2 = 0;
    for (int i = 20; i < 40; i++) {
        for (int j = 0; j < 6; j++) {
            if (side_effect_statuses[i][j] == '1') {
                count2++;
            }
        }
        if (count2 > 0) {
            count3++;
        }
        count2 = 0;
    }
    if (count3 < min_side_effects) {
        printf("Johnson & Johnson passed phase 1\n");
    } else {
        printf("Johnson & Johnson did not pass phase 1\n");
    }

    count3 = 0;
    count2 = 0;
    for (int i = 40; i < 60; i++) {
        for (int j = 0; j < 6; j++) {
            if (side_effect_statuses[i][j] == '1') {
                count2++;
            }
        }
        if (count2 > 0) {
            count3++;
        }
        count2 = 0;
    }
    if (count3 < min_side_effects) {
        printf("Novavax passed phase 1\n");
    } else {
        printf("Novavax did not pass phase 1\n");
    }



    int w = 0;
    int q = 0;
    char day[4];
    int days[200];
    for (int i = 120; i < 320; i++) {
        for (int j = 5; j < 8; j++) {
            day[q] = textdecyp[i][j];
            q++;
        }
        days[w] = atoi(day);
        w++;
        q = 0;
    }

    int count4 = 0;
    for (int i = 0; i < 100; i++) {
        if (days[i] < 60) {
            count4++;
        }
    }
    if (count4 > 50) {
        printf("\nAstrazeneca did not pass phase 2");
    } else {
        printf("\nAstrazeneca passed phase 2");
    }

    count4 = 0;
    for (int i = 100; i < 200; i++) {
        if (days[i] < 60) {
            count4++;
        }
    }
    if (count4 > 50) {
        printf("\nNovavax did not pass phase 2");
    } else {
        printf("\nNovavax passed phase 2\n");
    }



    int count5 = 0;
    for (int i = 320; i < 820; i++) {
        if (textdecyp[i][5] == '1') {
            count5++;
        }
    }
    int sick_min = (500 * 20) / 100;
    if (count5 < sick_min) {
        printf("\nNovavax passed phase 3\n\n");
    } else {
        printf("\nNovavax did not pass phase 3\n\n");
    }
    printf("Novavax passed all the testing phases and is now approved for use for the general public");
}
/*
 * COP 3515 – Summer Semester, 2021
 *
 * Homework #4: Securing The Vaccine
 *
 * (Raad Chowdhury)
 *
 */
