#include <stdio.h>

//validation
//receiving input
char getInput() {
    char input;
    scanf(" %c", &input);
    while (input != 'S' && input != '1' && input != '2' && input != '3' && input != '4' && input != '5' && input != 'B1' && input != 'B2' && input != 'B3' ) {
        printf("Received invd input. Enter valid floor (S, 1, 2, 3, 4, 5, B1, B2, B3): ");
        scanf(" %c", &input);
    }
    return input;
}

//elevator move
void startElev(
char currentFloor, 
char endFloor, 
int *peopleCount) {
    printf("Elevator is going from floor %c to floor %c...\n", currentFloor, endFloor);
    currentFloor = endFloor;
    printf("You arrived at floor %c.\n", currentFloor);
    if(*peopleCount>1) *peopleCount-=1;
}

//starts at S floor
int main() {
    char currentFloor = 'S'; 
    char endFloor;
    int peopleCount;
    printf("You are now on the %c floor.\n", currentFloor);
    printf("Number of passengers : ");
    scanf("%d", &peopleCount);
    printf("Your next floor is? (S, 1, 2, 3, 4, 5, B1, B2, B3): ");
    endFloor = getInput();
    startElev(currentFloor, endFloor, &peopleCount);
    while(peopleCount>0){
        printf("People count : %d\n", peopleCount);
        printf("Your next floor is? (S, 1, 2, 3, 4, 5, B1, B2, B3): ");
        endFloor = getInput();
        startElev(currentFloor, endFloor, &peopleCount);
    }
    printf("Everyone walked out.\n");
    return 0;
}