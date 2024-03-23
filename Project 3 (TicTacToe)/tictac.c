#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


 char a[]={'0','1','2','3','4','5','6','7', '8','9'};
 char mark;

int board();
int check();

int main() {

  int u_i;
  printf("\n\n Press 1 to play with a friend:\n Press 2 to play with Computer: \n");
  scanf("%d",&u_i);


//Multi player
  if (u_i == 1){

  int result,player1,player2,input;
  char mark1 ='X',mark2 ='O';

  board();

  while (check()==-1){

printf("Player 1 Choose Your Partition..!\n");
      scanf("%d",&input);

      if(input<1 || 9>input){
      printf("Invalid Input..\n");
      } 

      if(a[input] == 'X' || a[input] == 'O'){

      printf("Already Taken, Player 1 Again Choose Your Partition..!\n");
      scanf("%d",&input); 

      a[input] = mark1; 

      }  else {

      a[input] = mark1;
      
      }      

      board(); 

          result = check();
       if (result == 0){
        printf("Player 1 is the winner..!");
        break;
       } else if (result == 1) {
        printf("Tie..!");
        break;
       } 


printf("Player 2 Choose Your Partition..!\n");
      scanf("%d",&input);

      if(input<1 || 9>input){
      printf("Invalid Input..\n");
      }

      if(a[input] == 'X' || a[input] == 'O'){

      printf("Already Taken, Player 2 Again Choose Your Partition..!\n");
      scanf("%d",&input); 

      a[input] = mark2; 

      }  else {

      a[input] = mark2;
      
      }      

      board(); 


      result = check();
       if (result == 0){
        printf("Player 2 is the winner..!");
        break;
       } else if (result == 1) {
        printf("Tie..!");
        break;
       } 
  }
}


//Single player
   else if (u_i == 2) {

  int result,players;
  

  board();


  printf("\nEnter 1 To Choose 'X': , Enter 2 To Choose 'O': \n");
  scanf("%d",&players);


  while (check()==-1){

      int user;
      mark = (players==1)? 'X':'O';
      printf("Choose Your Partition..!\n");
      scanf("%d",&user);

    if(user<1 || 9>user){
      printf("Invalid Input..\n");
    }

    if(a[user] == 'X' || a[user] == 'O'){

      printf("Already Taken, Plzz Again Choose Your Partition..!\n");
      scanf("%d",&user); 

      a[user] = mark; 

      }  else {

      a[user] = mark;
      
      }  
 
      board();
      result = check();


    if (result == 0){
        printf("\n\nYou are a Winner.....\n");
        break;
    }
  
  //Generating computer's turn 
    int num,number;
    char c_mark;

    c_mark = (mark == 'X')? 'O':'X';
    srand(time(0));
    number = rand();
    num = (number%9)+1;

    a[num] = c_mark;

     while(num == a[user] || num == a[num]){
      srand(time(0));
      number = rand();
      num = (number%9)+1;
    }

      a[num] = c_mark;

    board();
    result = check();



    if (result == 0){
        printf("\n\nComputer is the Winner.....\n");
        break;
    }   else { }
  }

    if (result == 1){
    printf("Tie");
    } else { }

  }
   
   getch();

  return 0;
}


// Board's Func

int board(){

  system("cls");
printf("\n\n      =======  TIC TAC TOE.. ======= \n\n");
printf("\t      |           |\n");
printf("\t  %c   |     %c     |   %c\n",a[1],a[2],a[3]); 
printf("\t______|___________|_______\n");
printf("\t      |           |\n");
printf("\t  %c   |     %c     |   %c\n",a[4],a[5],a[6]); 
printf("\t______|___________|_______\n");
printf("\t      |           |\n");
printf("\t  %c   |     %c     |   %c\n",a[7],a[8],a[9]); 
printf("\t      |           |\n\n");

check (a);

}


// Result Checking

int check(){
  if (a[1]==a[2] && a[1]==a[3]){
    return 0;
  }
  if (a[4]==a[5] && a[4]==a[6]) {
    return 0;
  }
  if (a[7]==a[8] && a[7]==a[9]) {
    return 0;
  }
  if (a[1]==a[4] && a[1]==a[7]) {
    return 0;
  }
  if (a[2]==a[5] && a[2]==a[8]) {
    return 0;
  }
 if (a[3]==a[6] && a[3]==a[9]) {
    return 0;
  }
  if (a[1]==a[5] && a[1]==a[9]) {
    return 0;
  }
  if (a[3]==a[5] && a[3]==a[7]) {
    return 0;
  } 
  else{
    int count=0;
    for(int i=1; i<=9; i++){
      if(a[i]=='X' || a[i]=='O'){
        count++;
      }
    }   

    if(count==9){
      return 1;
    }

  }

  return -1;

}