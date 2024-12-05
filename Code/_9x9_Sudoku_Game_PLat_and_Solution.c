//2Explain how this code work for solving a Sudoku:

#include<stdio.h>
#include<stdlib.h>
/* We include 2 necessary library for this code*/
int rowcheck();
int colcheck();
int cubecheck();
int mrk(int n,int  x, int y);
int nxt() ;
int  solve (int nw);
/* All function’s  prototype  so that if any function is called then that  can access easily by the compiler*/




int box[9][9];
/*By declaring an integertype 9 by 9 array ,program allocate necessary memory to store all the necessary input for the Sudoku*/

 int mrk(int n, int x, int y)
/*We create a function that will return integer and in this function there is 3 formal parameter if this function is called and in the calling time it send 3 integer value that will be copyed to formal parameter n,x,y */
 {
     for(int i=0; i<9; i++)
     {
         if(box[y][i]==n||box[i][x]==n)
            return 0;
     }
/*In int next(),int solve(int nw) function call the mrk() function and those next(),solve() function send (j,i%9,i/9) & i,nw%9,nw/9) .Here i,j is value from 1 to 9 ,i%9 &nw%9 is column of this value ,i/9&nw/9 is row of that value. This 2 for loop will check along the row is there any value which is equal n or along the column is there any value which is equal to n if any of then occur then this function will terminate and return 0 */
     int tx=3*(x/3),ty=3*(y/3);
     for(int i=ty;i<ty+3;i++)
     {
         for(int j=tx; j<tx+3; j++)
         {
             if(box[i][j]==n)
                return 0;
         }
     }
/* here x is column number and y is row if we devide x by any integer then we will get an integer and if we multiply that with 3 then we will get the the initial column number of the 3*3 cubic sell in the same way if we devide y by 3 and multiply by 3 we will get the initial row number of the 3*3 cubic sell 
In this 2 for loop we are checking , is there any value which is equal to n . If this occur then function will terminate and return 0. */
     return 1;
/*If it dosenot find any number which is equal to n then this function will return 1 where mrk is called*/
 }

int nxt()
 {
     int mn=10, ret=-1, cnt=0;
     for(int i=0; i<81; i++){
        if(box[i/9][i%9])continue;
        cnt=0;
        for(int j=1;j<=9;j++){
            cnt+=mrk(j,i%9,i/9);
/* 
Let i=14 then  the integer value of i/9 is 2 which is row number and modulas (i%9) is 5  which is column number
now if(box[i/9][i%9]){continue}will check is there any value in box[i/9][i%9] .If the box has any value then command will go to continue . And I will increase by 1 and check the 15  .If 15 has no value then command goto for loop where it will call mrk() function and mrk function will check what value(1 to 9) is suitable for the 15. J=1 to 9 means it will send 1 to 9 value to mrk() function so mak() can check which which value can be put in 15 .
*/
        }
        if(mn>cnt){
            mn=cnt;
            ret=i;
        }
/* cnt will copy to mn & i will copy to ret */
     }
     return ret;
/* return ret where nxt() is called*/
 }

 int solve(int nw)
 {
     if(nw==-1)
        return 1;
/* In main function when solve(nxt()) is called nxt() will return ret and ret will copy to int nw. Now nw will check is nw is equal to -1 . If nw==-1 then function will terminate.But it wit doesn’t then check below again whether any value(1 to 9) is already have ret. */
     if(box[nw/9][nw%9]>0)
        return solve(nw+1);
     for(int i=1; i<=9; i++)
     {
         if( mrk(i,nw%9,nw/9) )

         {
             box[nw/9][nw%9]=i;
             if(solve( nxt() ))
                return 1;
         }
     }
/* here in this  2 for loop mrk() function will call again and mrk() function will check which value (1 to 9)is suitable for  this row & colunn. Thus it will put the suitable value in the blank row ,column*/
     box[nw/9][nw%9]=0;
     return 0;
 }
//
// here is main funcction
 int main()
 {
     int game=888;
    while(game==888)
/* How many time the user want to play this will be determined by user by putting the value 888.if he put different value then main function will terminate*/
    {
      int  select;
/* User will select what he want to do either play or want solve of any unsolved Sudoku*/       
printf(" If you want to get the solution of any Sudoku press 1:\n");
      printf(" If you want to play  press 2:\n");

       scanf("%d",&select );
     if(select==1)
     {
         printf("Give your input in this way & don,t repeat any number in any column,row and 3*3 cubic sell: \n");
         printf("1 0 3 0 4 0 5 0 6  \n");
         printf("0 3 0 4 0 8 0 1 9 \n");
         printf("Now Enter Your The  Unsolved Sudoku :\n");
        for(int i=0; i<9; i++)
         {
                for( int j=0; j<9; j++)
               {
                     scanf("%d",&box[i][j]);
                }
          }
/* In this 2 for loop program will take input from user*/
       solve(nxt());
/*  Sudoku will be solved by this function call */
        for(int i=0; i<9; i++)
     {
             if(i%3==0)
               printf("\n");
              for(int j=0; j<9; j++)
               {
                   if(j%3==0){
                    printf(" ");
                  }
                 printf("%d ",box[i][j]);
                 }
                printf("\n");
      }
/* Now this 2 for loop will print the solution of unsolved Sudoku*/
      game=777;
      printf("If you want to play again then press 888 \n");
      printf("If you don't want to play again then press 777 \n");
/*If the user want to play again then he will press 888 if he doesnot then press 777*/
      scanf("%d",&game);

 }
// ****************second part*******************

    if (select==2)
  {
    printf("if you dont want to play put value :999\n");

   int x,y,tt;
   int  a[9][9]={0};
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            printf("%d ",a[i][j]);
            if(j==2 || j==5){printf("  ");}
        }
        printf("\n");
        if(i==2  ||  i==5){printf("\n");}
    }
for(int kk=0;kk<81;kk++)
 {
   printf("enter desired row=");
   scanf("%d",&x);
   if(x>0 && x<10){}
   else if (x<0 || x>9)
     {
         --kk;
         continue;
     }

   printf("enter desired col=");
   scanf("%d",&y);

   if(y>0 && y<10){}
   else if (y<0 || y>9)
     {
         --kk;
         continue;
     }


   printf("enter the value=");
  scanf("%d",&tt);
  if(tt>0 && tt<10){
      a[x-1][y-1]=tt;
  }


  else if(tt==999)
    {
        break;
    }
  else if (tt<0 || tt>9)
       {  --kk;
          continue;
       }
    else if(tt==999)
    {
        break;
    }
    printf("\n");
   for(int i=0;i<9;i++)
      {
         for(int j=0;j<9;j++)
          {
              printf("%d ",a[i][j]);
              if(j==2 || j==5)
                   {
                      printf("  ");
                   }
          }
            printf("\n");
            if(i==2  ||  i==5){printf("\n");}

      }
 }
  printf("Mistakes You Made:");
 if (rowcheck(a)==1 && colcheck(a)==1 && cubecheck(a)==1)
    printf("\n If you don't do any mistake then Congratulation");
    printf("  but if you don't then try again");

    printf("\n");
   for(int i=0;i<9;i++)
      {
         for(int j=0;j<9;j++)
          {
              printf("%d ",a[i][j]);
          }
            printf("\n");

      }
      game=777;
      printf("If you want to solve your unsolved sudoku by  ");
      printf("computer then press 888  if you don't then press 777 \n");
      scanf("%d",&game);


}

}
 }

int rowcheck(int a[9][9])

{

    int c[10]={0};

    for(int i=0;i<9;i++)
     {

         for(int j=0;j<9;j++)

          {
               c[a[i][j]]++;

         }
          for(int k=1;k<=9;k++)


              if(c[k]!=1)
           {
               printf("The value %d came %d times in %d row\n",k,c[k],i+1);
               //return 0;
               }

           for(int k=1;k<=9;k++)

            c[k]=0;

   }
   return 1;
}


//coln
int colcheck(int a[9][9])

{

     int c[10]={0};

     for(int i=0;i<9;i++)

    {

         for(int j=0;j<9;j++)

      {

          c[a[j][i]]++;

        }

    for(int k=1;k<=9;k++)

        if(c[k]!=1)
       {

          printf("the value %d came %d times in %d column\n",k,c[k],i+1);
         // return 0;
}

     for(int k=1;k<=9;k++){
        c[k]=0;
     }

}

return 1;

}
// cube checked

int cubecheck(int a[9][9])

{

   int c[10]={0},count=0;

    for(int m=0;m<9;m+=3)

    {

        for(int b=0;b<9;b+=3)

        {

               for(int i=m;i<m+3;i++)

                  {

                         for(int j= b;j<b+3;j++)

                        {

                          c[a[i][j]]++;

                          }

                          }

                        count++;

              for(int k=1;k<=9;k++)

                 if(c[k]!=1)

           {

              printf("the value %d came% d times in %d box \n",k,c[k],count);
           // return 0;

            }

           for(int k=1;k<=9;k++)

           c[k]=0;

         }

     }

       return 1;

  }
