#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int choice;//to choose a random puzzle of the 3
int answer[9][9];//full correct puzzle, hidden from user
int selected[9][9];//puzzle with some blank, shown to user

//fn to display sudoku puzzle
void display(int values[9][9]){
    for(int i=0;i<9;i++){
        if(i%3==0 && i!=0){
            printf("---------------------\n");//to print line after every 3 rows
        }
        for(int j=0;j<9;j++){
            if(j%3==0 && j!=0){
                printf("| ");//to print line after every 3 columns
            }
        printf("%d ",values[i][j]);
        }
        printf("\n");
    }
}

//initializing to poke holes randomly to puzzle,prepare the puzzle
void initialize(int values[9][9]){
    int x,i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            x=rand()%2;
            answer[i][j]=values[i][j];
            if(x==1){
                selected[i][j]=values[i][j];//assign the given values to selected[i][j]
            }else{
                selected[i][j]=0;//assign 0 to selected[i][j] for user input
            }
        }
    }
}

//fn to handle user's guess
int update(int r,int c,int value){
    if(selected[r][c]==0){
        if(answer[r][c]==value){//if value input by user is same to puzzle of answer
            selected[r][c]=value;//assign value to puzzle of selected
            display(selected);
        }
        else{
            printf("Wrong!Try Again\n");//if user enters wrong ans
            display(selected);
        }
    }else{//if selected is 1
        printf("Already filled cell!\n");//if user enter row n colm of already filled no.
        display(selected);
    }
}

//to check if the puzzle is solved
int isComplete(){
    int total=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(answer[i][j]==selected[i][j]){//checking if the value of selected is equal to value of answer
                total=total+1;//while value is correct,add 1 to total until it equals 36
            }
        }
    }
    if(total==81){
        printf("\nCongratulations!You have solved the puzzle.");
        return 0;//means the game has finished
    }
        return 1;//means the game continues
}

int main(){
    srand(time(NULL));
    int r,c,v,opt;
    choice=rand()%3;//0,1,2;sol1,sol2,sol3
    struct Completed{
        int values[9][9];
    };
    struct Completed sol1={
        .values={
            {1,2,3,4,5,6,7,8,9},
            {4,5,6,7,8,9,1,2,3},
            {7,8,9,1,2,3,4,5,6},
            {2,3,4,5,6,7,8,9,1},
            {5,6,7,8,9,1,2,3,4},
            {8,9,1,2,3,4,5,6,7},
            {3,4,5,6,7,8,9,1,2},
            {6,7,8,9,1,2,3,4,5},
            {9,1,2,3,4,5,6,7,8}
            
        }
    };
    struct Completed sol2={
        .values={
            {4,3,1,6,7,9,5,2,8},
			{9,6,7,2,5,8,3,4,1},
            {5,8,2,1,4,3,9,6,7},
            {6,5,9,8,1,7,2,3,4},
            {3,2,8,5,6,4,1,7,9},
            {7,1,4,9,3,2,8,5,6},
            {8,7,3,4,2,1,6,9,5},
            {1,4,5,3,9,6,7,8,2},
            {2,9,6,7,8,5,4,1,3}
        }
    };
    struct Completed sol3={
        .values={
           {4,3,5,2,6,9,7,8,1},
           {6,8,2,5,7,1,4,9,3},
           {1,9,7,8,3,4,5,6,2},
           {8,2,6,1,9,5,3,4,7},
           {3,7,4,6,8,2,9,1,5},
           {9,5,1,7,4,3,6,2,8},
           {5,1,9,3,2,6,8,7,4},
           {2,4,8,9,5,7,1,3,6},
           {7,6,3,4,1,8,2,5,9}
        }
    };

    while(1){//1;continue loop until user wishes to stop playing
        if(choice==0){
            initialize(sol1.values);
        }
        else if(choice==1){
            initialize(sol2.values);
        }
        else{
            initialize(sol3.values);
        }
        display(selected);
        while(isComplete()){
            printf("Enter Row no.,Column no. and it's value: ");
            scanf("%d %d %d",&r,&c,&v);
            update(r-1,c-1,v);
        }
        printf("\nDo you wish to play again? Enter 1(yes) or 0(no): ");
        scanf("%d",&opt);
        if(opt==0){
            break;
        }
    } 
    return 0;
}