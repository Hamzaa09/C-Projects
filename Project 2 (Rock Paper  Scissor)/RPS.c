#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int Result(int comp, int input){
  if (comp==1 && input==1){
    return 0;
  } else if (comp==1 && input==2){
    return 1;
  } else if (comp==1 && input==3){
    return 2;
  }

  else if (comp==2 && input==1){
    return 2;
  } else if (comp==2 && input==2){
    return 0;
  } else if (comp==2 && input==3){
    return 1;
  }

  else if (comp==3 && input==1){
    return 1;
  } else if (comp==3 && input==2){
    return 2;
  } else if (comp==3 && input==3){
    return 0;
  }
  return -1;
}

int main(void) {

  int i=0, j=0;
  char stop;
  
  do {
  srand(time(0));
  int num = (rand()%3)+1;
  // printf("%d",num);

  int input;
  printf("\n\n\n===== Rock , Paper & Scissor =====");
  printf("\n\n\n1.Rock\t\t2.Paper\t\t3.Scissor");
printf("\n\nEnter Respective Numbers Of Your Choice");
  scanf("%d",&input);

    if (input<1 || 3<input){
      printf("Invalid Input :(");
      break;
    }

  int result = Result(num,input);

    switch(result){
      case 1:
    printf("Congratulations..! , You are a Winner");
      i++;
      break;
    case 2:
    printf("Computer is the Winner");
      j++;
      break;
    default:
      printf("Draw..");
      
    }
    
    printf("\n\nYour Wins = %d\t",i);
    printf("Computer's Wins = %d",j);


    printf("\n\n\nPlay Again..?  If yes Enter 'y' Other wise Enter 'n' ");
    scanf("%s", &stop);

    if (stop=='y'){
      system("cls");
    } else if (stop=='n'){
      break;
    } else {
      printf("Invalid Input");
    }
  } while(stop != 'n');
  
  return 0;
}