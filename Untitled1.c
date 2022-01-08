#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

int ish(){
    struct node{

    char food[100];
    int serv;
    int weight;
    int credits;
    struct node *next;
}*head[8]={0,0,0,0,0,0,0},*temp[8],*newnode[8];

int insertinto(){
    int pp=0;
    while(pp==0){
        reenter:
        system("cls");
        char day[10];
        printf("\t\t\t\t\t==================================================================================================================================\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t   FOOD DATA ENTRY\n\n\n");
        printf("\t\t\t\t\t==================================================================================================================================\n\n\n");
        printf("Enter the Day of the week: ");
        gets(day);
        strlwr(day);


        int d;
        if (strcmp(day,"sunday")==0){
           d=1;
        }
        else if (strcmp(day,"monday")==0){
            d=2;}
        else if (strcmp(day,"tuesday")==0){
            d=3;}
        else if (strcmp(day,"wednesday")==0){
            d=4;}
        else if (strcmp(day,"thursday")==0){
            d=5;}
        else if (strcmp(day,"friday")==0){
            d=6;}
        else if (strcmp(day,"saturday")==0){
            d=7;}
        else{
            goto reenter;
        }

        int ch=0;
        while(ch==0){

            newnode[d]=(struct node *)malloc(sizeof(struct node));

            printf("\n\nEnter food: ");
            gets(newnode[d]->food);
            printf("Enter Servings: ");
            scanf("%d",&newnode[d]->serv);
            printf("Enter wt per Servings in gram: ");
            scanf("%d",&newnode[d]->weight);
            printf("Enter Credits required for the food to be consumed: ");
            scanf("%d",&newnode[d]->credits);
            newnode[d]->next=0;

            if(head[d]==0){
                head[d]=temp[d]=newnode[d];
            }
            else{
                temp[d]->next=newnode[d];
                temp[d]=newnode[d];
            }

            printf("\n\nDo you want to enter the data of more Food?(0=Yes): ");
            scanf("%d",&ch);
            getchar();
        }
        printf("\n\nDo you want to enter data of food for other days?(0=Yes): ");
        scanf("%d",&pp);
        getchar();

    }


};

void display(){

    printf("\t\t\t\t\t==================================================================================================================================\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t   MESS ROUTINE\n\n\n");
        printf("\t\t\t\t\t==================================================================================================================================\n\n\n");
    int d=1;


    for(d=1;d<8;d++){
        if (d==1){
           printf("\n\n\t\t\t\t\tDAY: SUNDAY\n\n");
        }
        else if (d==2){
            printf("\t\t\t\t\t-----------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\n\n\t\t\t\t\tDAY: MONDAY\n\n");}
        else if (d==3){
            printf("\t\t\t\t\t-----------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\n\n\t\t\t\t\tDAY: TUESDAY\n\n");}
        else if (d==4){
            printf("\t\t\t\t\t-----------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\n\n\t\t\t\t\tDAY: WEDNESDAY\n\n");}
        else if (d==5){
            printf("\t\t\t\t\t-----------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\n\n\t\t\t\t\tDAY: THURSDAY\n\n");}
        else if (d==6){
            printf("\t\t\t\t\t-----------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\n\n\t\t\t\t\tDAY: FRIDAY\n\n");}
        else if (d==7){
            printf("\t\t\t\t\t-----------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\n\n\t\t\t\t\tDAY: SATURDAY\n\n");}
        else{
            printf("Invalid Entry!");
        }
        temp[d]=head[d];
        int co=1;
        while(temp[d]!=0){
            printf("\t\t\t\t\t%d.Food: %s\n",co,temp[d]->food);
            printf("\t\t\t\t\t  Servings per person: %d\n",temp[d]->serv);
            printf("\t\t\t\t\t  Weight: %d\n",temp[d]->weight);
            printf("\t\t\t\t\t  Credits: %d\n\n",temp[d]->credits);
            co++;
            temp[d]=temp[d]->next;
        }
    }
    getch();

}


int search(char data[100],struct node *head){
     struct node *current = head;
     int i = 1;
     bool flag = false;
     if(head == 0) {
        printf("List is empty \n");
     }
     else {
         while(current != 0) {
             if(strcmp(current->food,data)==0) {
             flag = true;
             break;
             }
             i++;
             current = current->next;
         }
     }
     if(flag)
        return(i);
     else
        return(0);
}




int deletepos()
{
            printf("\t\t\t\t\t==================================================================================================================================\n");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t   DELETE FOOD DATA\n\n\n");
            printf("\t\t\t\t\t==================================================================================================================================\n\n\n");
            int d,error=0;
            do{
                    char day[100];
                    printf("\nEnter Day of the Week: ");
                    scanf("%s",&day);
                    strlwr(day);
                    if (strcmp(day,"sunday")==0){
                       d=1;
                       error=1;
                    }
                    else if (strcmp(day,"monday")==0){
                        d=2;
                        error=1;}
                    else if (strcmp(day,"tuesday")==0){
                        d=3;
                        error=1;}
                    else if (strcmp(day,"wednesday")==0){
                        d=4;
                        error=1;}
                    else if (strcmp(day,"thursday")==0){
                        d=5;
                        error=1;}
                    else if (strcmp(day,"friday")==0){
                        d=6;
                        error=1;}
                    else if (strcmp(day,"saturday")==0){
                        d=7;
                        error=1;}
                    else{
                        printf("Invalid Entry!");
                        error=0;
                    }

            }while(error==0);


            char name[100];
            printf("\nEnter the name of the food to be deleted: ");
            getchar();
            gets(name);
            int pos=search(name,head[d]);
            printf("Position of the food in Mess routine is %d\n",pos);
    if (d==0){
        printf("Invalid Entry!");
        getch();
        return 1;
    }
    int i;
    struct node * t;
    if(head[d]==0)
    {
        printf("List is empty!!\n");
        return 0;
    }

    temp[d]=head[d];
    for(i=1;i<pos-1;i++)
    {
        if(temp[d]->next==0)
        {
            printf("There are less elements!!\n");
            return 0;
        }
        temp[d]=temp[d]->next;
    }
    t=temp[d]->next;
    temp[d]->next=t->next;
    printf("\n\n\nFOOD INFORMATION SUCCESSFULLY DELETED!\n");
    free(t);

}



int dayvalue(){
        char day[10];
        printf("\n\n");
        printf("Enter the Day of the week: ");
        scanf("%s",&day);
        strlwr(day);
        int d=0;
        while (d==0){

            if (strcmp(day,"sunday")==0){
               d=1;
            }
            else if (strcmp(day,"monday")==0){
                d=2;}
            else if (strcmp(day,"tuesday")==0){
                d=3;}
            else if (strcmp(day,"wednesday")==0){
                d=4;}
            else if (strcmp(day,"thursday")==0){
                d=5;}
            else if (strcmp(day,"friday")==0){
                d=6;}
            else if (strcmp(day,"saturday")==0){
                d=7;}
            else{
                printf("Invalid Entry!");
                d=0;
                getch();
            }
        }
        return (d);
}




int count(int d){
        temp[d]=head[d];
        int co=0;
        while(temp[d]!=0){
            co++;
            temp[d]=temp[d]->next;
        }
        return (co);

}





int max(int a, int b) { return (a > b)? a : b; }

int knapSack()
{
            printf("\t\t\t\t\t==================================================================================================================================\n");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t   CALCULATE SUITABLE AMOUNT OF FOOD FOR GIVEN CREDITS\n\n\n");
            printf("\t\t\t\t\t==================================================================================================================================\n\n\n");
            int n;
            int d;
            d=dayvalue();
            n=count(d);
            int val[n],wt[n];

            int x=0;
            temp[d]=head[d];
            while(temp[d]!=0){
                val[x]=temp[d]->weight;
                wt[x]=temp[d]->credits;
                x++;
                temp[d]=temp[d]->next;
            }

            int W;
            printf("\nEnter the credits contained by the student: ");
            scanf("%d", &W);

   int i, w;
   int K[n+1][W+1];

   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

    int res= K[n][W];
    w=W;
    printf("Maximum amount of Weight of food consumable by %d credits: %dgm\n\n",W,res);
    printf("The foods included are: \n");
    for (int i=n; i>0 && res>0;i--){
        if (res==K[i-1][w])
            continue;

    else{

        temp[d]=head[d];
        int co=1;
        while(temp[d]!=0){
                if (val[i-1]==temp[d]->weight){
                    printf("%s\n",temp[d]->food);
                }
                co++;
                temp[d]=temp[d]->next;

        }

        res = res - val[i - 1];
        w = w - wt[i - 1];
    }
    }
    return 0;
}

int update(){
    system("cls");
    printf("\t\t\t\t\t==================================================================================================================================\n");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t   UPDATE FOOD DATA\n\n\n");
    printf("\t\t\t\t\t==================================================================================================================================\n\n\n");
    int d=dayvalue();
    temp[d]=head[d];
    int co=0;
    char upfood[100];
    while(co==0){
        printf("Enter the name of the food that you want to update it's data: ");
        getchar();
        gets(upfood);

        while(temp[d]!=0){
            if (strcmp(upfood,temp[d]->food)==0){
                printf("\n\n\nEnter new Servings per person: ");
                scanf("%d",&temp[d]->serv);
                printf("Enter new Weight: ");
                scanf("%d",&temp[d]->weight);
                printf("Enter new Credits: ");
                scanf("%d",&temp[d]->credits);

                printf("\n FOOD DATA SUCESSFULLY UPDATED!");
                return 0;

            }
            temp[d]=temp[d]->next;

        }
        printf("\n\nFOOD NOT FOUND!!!\n\n");
        printf("Do you want to continue (0=Yes): ");
        scanf("%d",&co);

    }


}




    int lo=1;

    while(lo==1){
        int ch;
        system("cls");
        printf("\t\t\t\t\t==================================================================================================================================\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tMESS INFORMATION\n\n\n");
        printf("\t\t\t\t\t==================================================================================================================================\n");
        printf("\t\t\t\t\t1.Enter Food data\n\t\t\t\t\t2.Display Food data\n\t\t\t\t\t3.Delete\n\t\t\t\t\t4.Update Food Data\n\t\t\t\t\t5.Worth it Food\n\t\t\t\t\t6.Exit\n\n\n");
        printf("Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            system("cls");
            insertinto();
            break;
        case 2:
            system("cls");
            display();
            break;

        case 3:
            getchar();
            system("cls");

            deletepos();
            getch();
            break;

        case 4:
            update();
            getch();
            break;


        case 5:
            system("cls");

            knapSack();
            getch();
            break;

        case 6:
            lo=2;
            break;
        default:
            printf("Invalid Entry!!!");
            getch();
        }

    }

}


