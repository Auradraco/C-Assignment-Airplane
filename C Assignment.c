	/*edit*/

/*custom header*/
#include <stdio.h>
#include <string.h>
#define SIZE 50
typedef struct
{
    char name[20];
    int ID;
    int status;
} Seat;

void listTakenSeat(Seat *s, int *size);
void assignSeat(Seat *s, int *size);
void removeSeat(Seat *s, int *size);

	/*end_edit*/
	/*edit*/
/* Write your code here */


int main(){
    Seat s[5];
    int k, size, choice;
    int result;
    size=0;
    for (k=0; k<5; k++){
        s[k].status=0;
    }



    printf("NTU AIRLINES SEATING RESERVATION PROGRAM: \n");
    printf("1: listTakenSeat()\n");
    printf("2: assignSeat()\n");
    printf("3: removeSeat()\n");
    printf("4: quit\n");

    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
         case 1:
             listTakenSeat(s, &size);
             break;

         case 2:
             assignSeat(s, &size);
             //sortSeat(s, &size);
             break;
         case 3:
             removeSeat(s, &size);
             //sortSeat(s, &size);
             break;
      }
   } while (choice < 4);

   return 0;
}


void listTakenSeat(Seat *s, int *size){
    int i;
    printf("listTakenSeat():\n");
    //if all seats are empty, display the message
    if (*size==0){
        printf("The seat assignment list is empty\n");
    }
    else if (*size!=0){
        for (i=0; i<5; i++){

            if (s[i].status==1){
                printf("Customer name: %s\n", s[i].name);
                printf("Seat number (ID): %d\n", s[i].ID);
            }

        }
    }
    //else print the list of seat assignments

}
void assignSeat(Seat *s, int *size){
    int i, seatNum, dexter;
    char *p;
    char dummy[80];

    printf("assignSeat():\n");

    //if the plane is full, display the message and break;
    if (*size==5){
        printf("The plane is full\n");
    }

    while (*size!=5){
    //read in selected seat number (ID) and customer name from user
    printf("Enter the seat number:\n");
    scanf("%d", &seatNum);

    if (seatNum<1 || seatNum>5){
       //if selected seat number is not between 1 and 5, display message
       printf("Please enter a seat number between 1 and 5\n");
       scanf("%d", &seatNum);
       //prompt user input again
    }
    for (i=0; i<5; i++){
        if (s[i].ID== seatNum){
            //If selected seat has been assigned to another customer already
            printf("Occupied! Please choose another seat \n");
            scanf("%d", &seatNum);}
    }
    while ((seatNum<1)|| (seatNum>5)){
        printf("Please enter a seat number between 1 and 5\n");
        scanf("%d", &seatNum);
        for (i=0; i<*size; i++){
            if (s[i].ID== seatNum){
                //If selected seat has been assigned to another customer already
                printf("Occupied! Please choose another seat \n");
                scanf("%d", &seatNum);}
        }
        if (seatNum<1 || seatNum>5){
            //if selected seat number is not between 1 and 5, display message
            printf("Please enter a seat number between 1 and 5\n");
            scanf("%d", &seatNum);
            //prompt user input again
            break;
        }

            //prompt user input again

        }
    if ((seatNum>=1) && (seatNum<=5)){
        s[seatNum-1].ID=seatNum;
        printf("Enter customer name:\n");
        fgets(dummy, 80, stdin);
        fgets(s[seatNum-1].name, 80, stdin);
        if (p=strchr(s[seatNum-1].name,'\n')){
            *p = '\0';

        }
        s[seatNum-1].status=1;
        //After assignment, display the message
        printf("The seat has been assigned successfully \n");
        (*size)++;
        break;

    }

    }



}
void removeSeat(Seat *s, int *size){
    int seatNum, i, j, k;
    i=0;
    j=-1;
    char *target;
    printf("removeSeat():\n");
    if (*size==0){
        //if all the seats are empty prior to removal, display message
        printf("All the seats are vacant\n");
        return;
    }
    if (*size!=0){
        //read user input for selected seat number (ID)
        printf("Enter the seat number: \n");
        scanf("%d", &seatNum);
        if (seatNum>=1 && seatNum <=5 && s[seatNum-1].status ==0){
            printf("Empty! Enter another seat number for removal\n");
            scanf("%d", &seatNum);
        }
        while ((seatNum<1) || (seatNum>5)){
            //if selected seat number is not between 1 and 5, display message
            printf("Please enter a seat number between 1 and 5\n");
            //prompt user input again
            scanf("%d", &seatNum);
            if (s[seatNum-1].status!=1){
            //if selected seat is empty, display message
                printf("Empty! Enter another seat number for removal\n");
                scanf("%d", &seatNum);
            }
        }



            while (seatNum>=1 &&seatNum<=5 ){
            //else: remove selected seat and display message
            target=s[seatNum-1].name;
            while((j == -1) && (i < (*size))) {
                if (strcmp(target,s[i].name) == 0){
                    j = i;
                }

                else{
                    i++;
                }
            }

            s[i].status=0;
            --(*size);

            printf("Removal is successful\n");
            return;
        }

    }

}



	/*end_edit*/
