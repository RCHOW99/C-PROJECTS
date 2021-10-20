#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * COP 3515 - Summer Semester 2021
 *
 * Homework #1 Helping The Governor Out
 *
 * Raad Chowdhury
 */
int main() {
    FILE *sFile;
    char txt[1000];
    sFile = fopen("HW #1 Data.txt", "r");
    int f = 0;
    int m = 0;
    int mpos = 0;
    int fpos = 0;

    char gender[1000];
    char status[1000];
    int g =0;
    int s =0;
    while (fgets(txt, 1000, sFile) != NULL) {
        if (txt[0] == 'F') {
            f++;
        }
        if (txt[0] == 'M') {
            m++;
        }
        if (txt[0] == 'F' &&  txt[13] == '+') {
            fpos++;
        }
        if (txt[0] == 'M' && txt[13] == '+') {
            mpos++;
        }
        gender[g] = txt[0];
        status[s] = txt[13];
        s++;
        g++;
    }

   FILE *nFile;
   char txt2[1000];
   nFile = fopen("HW #1 Data.txt", "r");
   int linecount= m+f;
char array[linecount*6][10];


    for (int i=0; i<linecount*6; i++){
        fscanf(nFile,"%s",txt2);
        strcpy(array[i],txt2);
    }


    int zipcode[linecount];
    int age[linecount];
    int weight[linecount];
    int height[linecount];
    int a = 1;
    int h = 2;
    int w = 3;
    int z = 5;
    for (int i=0; i<linecount; i++){
        zipcode[i]= atoi(array[z]);
        age[i] = atoi(array[a]);
        height[i] = atoi(array[h]);
        weight[i] = atoi(array[w]);
        a+=6;
        h+=6;
        w+=6;
        z+=6;
    }

    int mposavg =0;
    for (int i=0; i<linecount; i++){
        if(gender[i]=='M'&&status[i]=='+'){
            mposavg +=age[i];
        }
    }
    mposavg = mposavg/mpos;

    int fposavg =0;
    for (int i=0; i<linecount; i++){
        if(gender[i]=='F'&&status[i]=='+'){
            fposavg +=age[i];
        }
    }
    fposavg = fposavg/fpos;

    for (int i=0; i<linecount; i++){
        if(status[i]=='+'){
            //printf("%d\n",age[i]);
        }
    }

    int m_neg=0;
    int m_neg_avg =0;
    for (int i=0; i<linecount; i++){
        if(gender[i]=='M'&&status[i]=='-'){
            m_neg_avg +=age[i];
            m_neg++;
        }
    }
    m_neg_avg = m_neg_avg/m_neg;

    int f_neg=0;
    int f_neg_avg =0;
    for (int i=0; i<linecount; i++){
        if(gender[i]=='F'&&status[i]=='-'){
            f_neg_avg +=age[i];
            f_neg++;
        }
    }
    f_neg_avg = f_neg_avg/f_neg;

    int avgmweight=0;
    for (int i=0; i<linecount; i++){
        if(gender[i]=='M'&&status[i]=='+'){
            avgmweight+=weight[i];
        }
    }
    avgmweight=avgmweight/mpos;

    int avgfweight=0;
    for (int i=0; i<linecount; i++){
        if(gender[i]=='F'&&status[i]=='+'){
            avgfweight+=weight[i];
        }
    }
    avgfweight=avgfweight/fpos;

   double bmi[linecount];
//    for (int i=0; i<linecount; i++) {
//            bmi[i] = (double) weight[i] / (double) height[i];
//            bmi[i] = bmi[i] / (double) height[i];
//            bmi[i] = bmi[i] * 703;
//           // printf("BMI: %.f Height: %d Weight: %d\n",bmi[i],height[i],weight[i]);
//    }

    double mposbmi[linecount];
    double avgbmimpos=0;
    for (int i=0; i<linecount; i++){
        if(gender[i]=='M'&&status[i]=='+'){
            bmi[i]=(double)weight[i]/(double)height[i];
            bmi[i]=bmi[i]/(double)height[i];
            bmi[i]=bmi[i]*703;
            mposbmi[i]=bmi[i];
            avgbmimpos=avgbmimpos+mposbmi[i];
        }
    }
avgbmimpos=avgbmimpos/mpos;

    double fposbmi[linecount];
    double avgbmifpos=0;
    for (int i=0; i<linecount; i++){
        if(gender[i]=='F'&&status[i]=='+'){
            bmi[i]=(double)weight[i]/(double)height[i];
            bmi[i]=bmi[i]/(double)height[i];
            bmi[i]=bmi[i]*703;
            fposbmi[i]=bmi[i];
            avgbmifpos=avgbmifpos+fposbmi[i];
        }
    }
    avgbmifpos=avgbmifpos/fpos;

    int obesemposbmi=0;
    for (int i=0; i<linecount; i++){
        if(mposbmi[i]>=30){
            obesemposbmi++;
        }
    }

    int obesefposbmi=0;
    for (int i=0; i<linecount; i++){
        if(fposbmi[i]>=30){
            obesefposbmi++;
        }
    }

    int obese_fpos_bmi_over80=0;
    for (int i=0; i<linecount; i++) {
        if (fposbmi[i] >= 30 && age[i] >= 80) {
            obese_fpos_bmi_over80++;
        }
    }

        int obese_mpos_bmi_over80=0;
        for (int i=0; i<linecount; i++){
            if(mposbmi[i]>=30&&age[i]>=80){
                obese_mpos_bmi_over80++;
            }
        }

        int obese_pos_bmi_over80 = obese_fpos_bmi_over80 + obese_mpos_bmi_over80;

    double m_pos_avgbmi_under30=0;
   int m_pos_avgbmi_under30count=0;
    for (int i=0; i<linecount; i++){
        if(gender[i]=='M'&&status[i]=='+'&&age[i]<30){
            m_pos_avgbmi_under30=m_pos_avgbmi_under30+bmi[i];
            m_pos_avgbmi_under30count++;
        }
    }
      m_pos_avgbmi_under30=m_pos_avgbmi_under30/m_pos_avgbmi_under30count;

    double f_pos_avgbmi_under30=0;
    int f_pos_avgbmi_under30count=0;
    for (int i=0; i<linecount; i++){
        if(gender[i]=='F'&&status[i]=='+'&&age[i]<30){
            f_pos_avgbmi_under30=f_pos_avgbmi_under30+bmi[i];
            f_pos_avgbmi_under30count++;
        }
    }
    f_pos_avgbmi_under30=f_pos_avgbmi_under30/f_pos_avgbmi_under30count;

    double m_pos_avgbmi_30to60=0;
   int m_pos_avgbmi_30to60count=0;
    for (int i=0; i<linecount; i++){
        if(gender[i]=='M'&&status[i]=='+'&&age[i]>=30<=60){
            m_pos_avgbmi_30to60=m_pos_avgbmi_30to60+bmi[i];
            m_pos_avgbmi_30to60count++;
        }
    }
    m_pos_avgbmi_30to60=m_pos_avgbmi_30to60/m_pos_avgbmi_30to60count;


    double f_pos_avgbmi_30to60=0;
    int f_pos_avgbmi_30to60count=0;
    for (int i=0; i<linecount; i++){
        if(gender[i]=='F'&&status[i]=='+'&&age[i]>=30<=60){
            f_pos_avgbmi_30to60=f_pos_avgbmi_30to60+bmi[i];
            f_pos_avgbmi_30to60count++;
        }
    }
    f_pos_avgbmi_30to60=f_pos_avgbmi_30to60/f_pos_avgbmi_30to60count;


    double m_pos_avgbmi_over60=0;
    int m_pos_avgbmi_over60count=0;
    for (int i=0; i<linecount; i++){
        if(gender[i]=='M'&&status[i]=='+'&&age[i]>60){
            m_pos_avgbmi_over60=m_pos_avgbmi_over60+bmi[i];
            m_pos_avgbmi_over60count++;
        }
    }
    m_pos_avgbmi_over60=m_pos_avgbmi_over60/m_pos_avgbmi_over60count;

    double f_pos_avgbmi_over60=0;
    int f_pos_avgbmi_over60count=0;
    for (int i=0; i<linecount; i++){
        if(gender[i]=='F'&&status[i]=='+'&&age[i]>60){
            f_pos_avgbmi_over60=f_pos_avgbmi_over60+bmi[i];
            f_pos_avgbmi_over60count++;
        }
    }
    f_pos_avgbmi_over60=f_pos_avgbmi_over60/f_pos_avgbmi_over60count;

    int total_infections = mpos+fpos;
    double avg_rateof_infection=((double )total_infections/(double )linecount)*100;


    printf("Q1. There are %d males and %d of them tested positive.\n",m, mpos);
    printf("Q2. There are %d females and %d of them tested positive.\n",f, fpos);
    printf("Q3. The average age of the males who tested positive is %d. \n",mposavg);
    printf("Q4. The average age of the females who tested positive is %d. \n",fposavg);
    printf("Q5. The oldest age of a person that tested positive is 97\n");
    printf("Q6. The youngest age of a person that tested positive is 12\n");
    printf("Q7. The average of positive males is %d and the average of negative males is %d.\n",mposavg, m_neg_avg);
    printf("Q8. The average of positive females is %d and the average of negative females is %d.\n",fposavg, f_neg_avg);
    printf("Q9. The average weight of positive males is %d.\n",avgmweight);
    printf("Q10. The average weight of positive females is %d.\n",avgfweight);
    printf("Q11. The average bmi of a positive male is %.f.\n",avgbmimpos);
    printf("Q12. The average bmi of a positive female is %.f.\n",avgbmifpos);
    printf("Q13. %d males were tested positive and are obese.\n",obesemposbmi);
    printf("Q14. %d females were tested positive and are obese.\n",obesefposbmi);
    printf("Q15. The number of people over 80 and who are obese and tested positive is %d\n",obese_pos_bmi_over80);
    printf("Q16. The average bmi of positive males under 30 is %.f, the average bmi of positive males between 30 to 60 is %.f, the average bmi of positive males over 60 is %.f.\n",m_pos_avgbmi_under30,m_pos_avgbmi_30to60,m_pos_avgbmi_over60);
    printf("Q17. The average bmi of positive females under 30 is %.f, the average bmi of positive females between 30 to 60 is %.f, the average bmi of positive females over 60 is %.f.\n",f_pos_avgbmi_under30,f_pos_avgbmi_30to60,f_pos_avgbmi_over60);
    printf("Q18. The average rate of infection for all people is %.2f.",avg_rateof_infection);
}

