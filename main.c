#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    const int MAX_NUMBER_OF_PIN = 5000;
    const int PINADMIN = 9999;
    const int CELL_PINS = 0;
    const int CELL_CASH = 1;
    const int VERIFY_ACCOUNT = 1;
    const int PUT_MONEY = 2;
    const int WITHDRAW_MONEY = 3;
    const int QUIT = 0;
    const int CHECK_ALL_ACCOUNT = 1;
    const int ZERO_ALL_ACCOUNT = 2;
    const int NUMBER_OF_ATTEMPTS = 3;
    int arrayPinCash[MAX_NUMBER_OF_PIN][2];
    int i = 0;
    int pin;
    int money;
    int deustvie;
    int b;

    srand(time(NULL));
    for ( i = 0; i < MAX_NUMBER_OF_PIN; i++){
        arrayPinCash[i][CELL_PINS] = i + 1000;
        arrayPinCash[i][CELL_CASH] = rand() %10000 + 1;
        printf("%d", arrayPinCash[i][CELL_PINS]);
        printf("    %d \n", arrayPinCash[i][CELL_CASH]);
    }

    for(;;){
        //user verification
        for (b = 0; b < NUMBER_OF_ATTEMPTS; b++){
            printf("enter your pin: ");
            fflush(stdin);
            scanf("%d", &pin);
            for (i = 0; i < MAX_NUMBER_OF_PIN; i++){
                if (pin == arrayPinCash[i][CELL_PINS]){
                    break;
                }
                if (pin == PINADMIN){
                    break;
                }
            }
            if (pin == arrayPinCash[i][CELL_PINS]){
                break;
            }
            if (pin == PINADMIN){
                break;
            }
        }

        //admin login
        if (pin == arrayPinCash[i][CELL_PINS]){
            for(;;){
                printf(">>>>>>>>>>  Welcome to cash machine  <<<<<<<<<<<<<\n");
                printf("1 Verify account                                 |\n");
                printf("2 Put money                                      |\n");
                printf("3 Withdraw money                                 |\n");
                printf("0 Quit                                           |\n");
                printf("             Select an action - ");
                fflush(stdin);
                scanf("%d", &action);

                if (action == VERIFY_ACCOUNT){
                    printf("\n%d", arrayPinCash[i][CELL_CASH]);
                }
                if (action == PUT_MONEY){
                    printf("\nenter how much money you want to put\n");
                    scanf("%d", &money);
                    arrayPinCash[i][CELL_CASH] = arrayPinCash[i][CELL_CASH] + money;
                    printf("\nbecame money in the account\n");
                    printf("\n%d", arrayPinCash[i][CELL_CASH]);
                }
                if (action == WITHDRAW_MONEY){
                    printf("\nenter how much money you want to withdraw\n");
                    scanf("%d", &money);
                    arrayPinCash[i][CELL_CASH] = arrayPinCash[i][CELL_CASH] - money;
                    printf("\nbecame money in the account\n");
                    printf("\n%d", arrayPinCash[i][CELL_CASH]);
                }
                if (action == QUIT){
                    break;
                }
            }
        }

        if (pin == PINADMIN){
            for(;;){
                printf(">>>>>>>>>>       Welcome ADMIN       <<<<<<<<<<<<<\n");
                printf("1 Check all accounts                             |\n");
                printf("2 Zero all accounts                              |\n");
                printf("0 Quit                                           |\n");
                printf("             Select an action - ");
                scanf("%d", &action);

                if (action == CHECK_ALL_ACCOUNT){
                    for (i = 0; i < MAX_NUMBER_OF_PIN; i++){
                        printf("\n%d %d  \n", arrayPinCash[i][CELL_PINS], arrayPinCash[i][CELL_CASH]);
                    }
                }

                if (action == ZERO_ALL_ACCOUNT){
                    for (i = 0; i < MAX_NUMBER_OF_PIN; i++){
                        arrayPinCash[i][CELL_CASH] =  0;
                        printf("\n%d %d  ", arrayPinCash[i][CELL_PINS], arrayPinCash[i][CELL_CASH]);
                    }
                }
                if (action == QUIT){
                    break;
                }
            }
        }
    }
    getch();    return 0;
}
