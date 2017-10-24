#include <stdio.h>

#include <stdlib.h>

#include <time.h>

int main(){

    const int USER = 5000;
    const int PINADMIN = 9999;
    int arrayPinCash[USER][2];
    int i = 0;
    int pin;
    int money;
    int deustvie;
    int b;


    srand(time(NULL));
    for ( i = 0; i < USER; i++){
        arrayPinCash[i][0] = i + 1000;
        arrayPinCash[i][1] = rand() %10000 + 1;
        printf("%d", arrayPinCash[i][0]);
        printf("    %d \n", arrayPinCash[i][1]);
    }
        for(;;){

             //Proverka na usera
             for (b = 0; b < 3; b++){
                printf("enter your pin: ");
                fflush(stdin);
                scanf("%d", &pin);
                for (i = 0; i < USER; i++){
                    if (pin == arrayPinCash[i][0]){
                        break;
                    }
                    if (pin == PINADMIN){
                        break;
                    }
                }
                    if (pin == arrayPinCash[i][0]){
                        break;
                  }
                  if (pin == PINADMIN){
                        break;
                  }
        }

        //Vhod v adminky
        for (i = 0; i < USER; i++){
            if (pin == arrayPinCash[i][0]){
                break;
            }
        }

            if (pin == arrayPinCash[i][0]){
                for(;;){
                    printf(">>>>>>>>>>Dobro pogalovat v bankomat <<<<<<<<<<<<<\n");
                    printf("1 Proverit schet                                 |\n");
                    printf("2 Pologit dengi                                  |\n");
                    printf("3 Snyat dengi                                    |\n");
                    printf("4 Quit                                           |\n");
                    printf("             Vuberete deustvie - ");
                    fflush(stdin);
                    scanf("%d", &deustvie);

            if (deustvie == 1){
                printf("\n%d", arrayPinCash[i][1]);
            }
            if (deustvie == 2){
                printf("\nvvedite skolko vu hotite pologit\n");
                scanf("%d", &money);
                arrayPinCash[i][1] = arrayPinCash[i][1] + money;
                printf("\nstalo deneg\n");
                printf("\n%d", arrayPinCash[i][1]);
            }
            if (deustvie == 3){
                printf("\nvvedite skolko vu hotite snjt\n");
                scanf("%d", &money);
                arrayPinCash[i][1] = arrayPinCash[i][1] - money;
                printf("\nstalo deneg\n");
                printf("\n%d", arrayPinCash[i][1]);
            }
            if (deustvie == 4){
                break;
            }
            }
            }

            if (pin == PINADMIN){
                for(;;){
                    printf(">>>>>>>>>>    Dobro pogalovat ADMIN  <<<<<<<<<<<<<\n");
                    printf("1 Proverit vse scheta                            |\n");
                    printf("2 Obnylit vse scheta                             |\n");
                    printf("3 Quit                                           |\n");
                    printf("             Vuberete deustvie - ");
                    scanf("%d", &deustvie);

                if (deustvie == 1){
                    for (i = 0; i < USER; i++){
                        printf("\n%d %d  \n", arrayPinCash[i][0], arrayPinCash[i][1]);
                    }
                }

                if (deustvie == 2){
                    for (i = 0; i < USER; i++){
                    arrayPinCash[i][1] =  0;
                    printf("\n%d %d  ", arrayPinCash[i][0], arrayPinCash[i][1]);
                    }
                }
                if (deustvie == 3){
                    break;
                }
            }
            }
        }
            getch(); return 0;
}
