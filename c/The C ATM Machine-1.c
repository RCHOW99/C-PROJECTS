#include <stdio.h>

int main() {
    float money;
    float users_money;
    printf("Welcome to the ATM, here you can calculate change for your cash.\n");
    scanf("%f",&users_money);

      if(users_money > 100 || users_money==100){
          money = 100;
      }
    else if(users_money >80|| users_money==80){
        money =20*4;
    }
    else if(users_money >60|| users_money==60){
        money =20*3;
    }
    else if(users_money >40|| users_money==40){
        money =20*2;
    }
    else if(users_money >20|| users_money==20){
        money =20*1;
    }
    else if(users_money>10|| users_money==10){
        money=10;
    }
   else if(users_money>5|| users_money==5){
        money=5;
    }
   else if (users_money>1|| users_money==1){
       money =1;
   }
    float change =  users_money - money;
    printf("%.2f",change);
    return 0;
}
