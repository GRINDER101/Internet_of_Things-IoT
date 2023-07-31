#include <stdio.h>
#include <stdlib.h>



char location[100];
void readdatafile1(char *);
void calculation();
typedef struct RoomData
{
char time[24][8];
float intemp[24];
float outtemp[24];
float humidity[24];
float motion[24][6];
int inttempcontrolstate[24];
int outtempcontrolstate[24];
int humiditycontrolstate[24];
int motioncontrolstate[24][6];
int energyconsumption[24];
}RD;

int heatingcount=0;
int ventilationcount=0;
int lightscount=0;
int t,k;
int hourlyconsumption=0;
float inttempthreshold=0;;
float outtempthreshold=0;
float humiditythreshold=0;
float motionthreshold=0;

int main()
{
 printf("enter your livingroom file location to read\n");
//  gets(location);
 scanf("%s",location);
 readdatafile1(location);
 calculation();
}

 void readdatafile1(char *location)
 {
  RD RDL[200];
  RD RDB[200];
  RD RDK[200];
  FILE *fptr1, *fptr2, *fptr3, *fptr4, *fptr5, *fptr6;
  fptr1= fopen(location,"r");
  if(fptr1==NULL)
  {
      printf("Error!\n");
      exit(1);
  }
  printf("\nenter your file location where you will store control state of devices for livingroom\n");
  scanf("%s",location);
  fptr2= fopen(location,"w");
  if(fptr2==NULL)
  {
      printf("Error!\n");
      exit(1);
  }

  printf("\nenter your bedroom file location to read\n");
  scanf("%s",location);
  fptr3= fopen(location,"r");
  if(fptr3==NULL)
  {
      printf("Error!\n");
      exit(1);
  }

  printf("\nenter your file location where you will store control state of devices for bedroom\n");
  scanf("%s",location);
  fptr4= fopen(location,"w");
  if(fptr4==NULL)
  {
      printf("Error!\n");
      exit(1);
  }

  printf("\nenter your kitchen file location to read\n");
  scanf("%s",location);
  fptr5= fopen(location,"r");
  if(fptr5==NULL)
  {
      printf("Error!\n");
      exit(1);
  }

  printf("\nenter your file location where you will store control state of devices for kitchen\n");
  scanf("%s",location);
  fptr6= fopen(location,"w");
  if(fptr6==NULL)
  {
      printf("Error!\n");
      exit(1);
  }

     printf("enter the threshold for internal temperature");
     scanf("%f",&inttempthreshold);
     printf("enter the threshold for outer temperature");
     scanf("%f",&outtempthreshold);
     printf("enter the threshold for humidity");
     scanf("%f",&humiditythreshold);
     printf("enter the threshold for motion");
     scanf("%f",&motionthreshold);

  for(t=0; (t<24 && !feof(fptr1)&& !feof(fptr2) && !feof(fptr3) && !feof(fptr4) && !feof(fptr5) && !feof(fptr6)); t++)
    {
         fscanf(fptr1, "%s", &RDL->time[t][8]);
         fprintf(fptr2, "\n%s\t", RDL->time[t][8]);
         fscanf(fptr3, "%s", &RDB->time[t][8]);
         fprintf(fptr4, "\n%s\t", RDB->time[t][8]);
         fscanf(fptr5, "%s", &RDK->time[t][8]);
         fprintf(fptr6, "\n%s\t", RDK->time[t][8]);
         fscanf(fptr1, "%f", &RDL->intemp[t]);
         if(inttempthreshold>RDL->intemp[t])
            {
              fprintf(fptr2,"\t1\t",RDL->inttempcontrolstate[t]);
            }
          else
          {
              fprintf(fptr2,"\t0\t",RDL->inttempcontrolstate[t]);
          }
         fscanf(fptr3, "%f", &RDB->intemp[t]);
         if(inttempthreshold>RDB->intemp[t])
            {
              fprintf(fptr4,"\t1\t",RDB->inttempcontrolstate[t]);
            }
          else
          {
              fprintf(fptr4,"\t0\t",RDB->inttempcontrolstate[t]);
          }
         fscanf(fptr5, "%f", &RDK->intemp[t]);
         if(inttempthreshold>RDK->intemp[t])
            {
              fprintf(fptr6,"\t1\t",RDK->inttempcontrolstate[t]);
            }
          else
          {
              fprintf(fptr6,"\t0\t",RDK->inttempcontrolstate[t]);
          }


         fscanf(fptr1,"%f",&RDL->outtemp[t]);
         if(outtempthreshold>RDL->outtemp[t])
         {
             fprintf(fptr2,"\t1\t",RDL->outtempcontrolstate[t]);
         }
         else
         {
             fprintf(fptr2,"\t0\t",RDL->outtempcontrolstate[t]);
         }
         fscanf(fptr3,"%f",&RDB->outtemp[t]);
         if(outtempthreshold>RDB->outtemp[t])
         {
             fprintf(fptr4,"\t1\t",RDB->outtempcontrolstate[t]);
         }
         else
         {
             fprintf(fptr4,"\t0\t",RDB->outtempcontrolstate[t]);
         }
         fscanf(fptr5,"%f",&RDK->outtemp[t]);
         if(outtempthreshold>RDK->outtemp[t])
         {
             fprintf(fptr6,"\t1\t",RDK->outtempcontrolstate[t]);
         }
         else
         {
             fprintf(fptr6,"\t0\t",RDK->outtempcontrolstate[t]);
         }

         fscanf(fptr1, "%f", &RDL->humidity[t]);
         if(humiditythreshold>RDL->humidity[t])
         {
             fprintf(fptr2,"\t1\t",RDL->humiditycontrolstate[t]);
         }
         else
         {
             fprintf(fptr2,"\t0\t",RDL->humiditycontrolstate[t]);
         }
         fscanf(fptr3, "%f", &RDB->humidity[t]);
         if(humiditythreshold>RDB->humidity[t])
         {
             fprintf(fptr4,"\t1\t",RDB->humiditycontrolstate[t]);
         }
         else
         {
             fprintf(fptr4,"\t0\t",RDB->humiditycontrolstate[t]);
         }
         fscanf(fptr5, "%f", &RDK->humidity[t]);
         if(humiditythreshold>RDK->humidity[t])
         {
             fprintf(fptr6,"\t1\t",RDK->humiditycontrolstate[t]);
         }
         else
         {
             fprintf(fptr6,"\t0\t",RDK->humiditycontrolstate[t]);
         }


       for ( k=0; k<6; k++)
       {
       fscanf(fptr1,"%f", &RDL->motion[t][k]);
       if(motionthreshold<RDL->motion[t][k])
       {
           fprintf(fptr2,"\ton\t",RDL->motioncontrolstate[t][k]);
       }
       else
       {
           fprintf(fptr2,"\toff\t",RDL->motioncontrolstate[t][k]);
       }
       fscanf(fptr3,"%f", &RDB->motion[t][k]);
       if(motionthreshold<RDB->motion[t][k])
       {
           fprintf(fptr4,"\ton\t",RDB->motioncontrolstate[t][k]);
       }
       else
       {
           fprintf(fptr4,"\toff\t",RDB->motioncontrolstate[t][k]);
       }
       fscanf(fptr5,"%f", &RDK->motion[t][k]);
       if(motionthreshold<RDK->motion[t][k])
       {
           fprintf(fptr6,"\ton\t",RDK->motioncontrolstate[t][k]);
       }
       else
       {
           fprintf(fptr6,"\toff\t",RDK->motioncontrolstate[t][k]);
       }

    }
    }
   fclose(fptr1);
   fclose(fptr2);
   fclose(fptr3);
   fclose(fptr4);
   fclose(fptr5);
   fclose(fptr6);

 }

 void calculation()
 {
     RD RDL[200];
     RD RDB[200];
     RD RDK[200];

     FILE *fptr7, *fptr8, *fptr9, *fptr10, *fptr11, *fptr12;

     printf("enter the file location where you stored control state of devices for livingroom to read");
     scanf("%s",location);
     fptr7= fopen(location,"r");
     if(fptr7==NULL)
    {
      printf("Error!\n");
      exit(1);
    }
     printf("enter the file location where you want to store total energy consumption for livingroom");
     scanf("%s",location);
     fptr8= fopen(location,"w");
     if(fptr8==NULL)
    {
      printf("Error!\n");
      exit(1);
    }
    printf("enter the file location where you stored control state of devices for bedroom to read");
     scanf("%s",location);
     fptr9= fopen(location,"r");
     if(fptr9==NULL)
    {
      printf("Error!\n");
      exit(1);
    }
    printf("enter the file location where you want to store total energy consumption for bedroom");
     scanf("%s",location);
     fptr10= fopen(location,"w");
     if(fptr10==NULL)
    {
      printf("Error!\n");
      exit(1);
    }
    printf("enter the file location where you stored control state of devices for kitchen to read");
     scanf("%s",location);
     fptr11= fopen(location,"r");
     if(fptr11==NULL)
    {
      printf("Error!\n");
      exit(1);
    }
    printf("enter the file location where you want to store total energy consumption for kitchen");
     scanf("%s",location);
     fptr12= fopen(location,"w");
     if(fptr12==NULL)
    {
      printf("Error!\n");
      exit(1);
    }

    for(t=0; (t<24 && !feof(fptr7)&& !feof(fptr8) && !feof(fptr9) && !feof(fptr10) && !feof(fptr11) && !feof(fptr12)); t++)
    {
         heatingcount=0;
         ventilationcount=0;
         lightscount=0;
         hourlyconsumption=0;

         fscanf(fptr7, "%s", &RDL->time[t][8]);
         fprintf(fptr8, "\n%s\t", RDL->time[t][8]);
         fscanf(fptr9, "%s", &RDB->time[t][8]);
         fprintf(fptr10, "\n%s\t", RDB->time[t][8]);
         fscanf(fptr11, "%s", &RDK->time[t][8]);
         fprintf(fptr12, "\n%s\t", RDK->time[t][8]);
         fscanf(fptr7, "%d", &RDL->inttempcontrolstate[t]);
         if(RDL->inttempcontrolstate[t]==1)
         {
             heatingcount=heatingcount+1;
         }
         else
         {
             heatingcount=0;
         }
         fscanf(fptr7, "%d", &RDL->outtempcontrolstate[t]);
         if(RDL->outtempcontrolstate[t]==1)
         {
             heatingcount= heatingcount+1;
         }
         else
         {
             heatingcount=heatingcount+0;
         }
         fscanf(fptr7, "%d", &RDL->humiditycontrolstate[t]);
         if(RDL->humiditycontrolstate[t]==1)
         {
             ventilationcount= ventilationcount+1;
         }
         else
         {
             ventilationcount=0;
         }
         for ( k=0; k<6; k++)
         {
         fscanf(fptr7, "%d", &RDL->motioncontrolstate[t][k]);
         if(RDL->motioncontrolstate[t][k]==1)
         {
             lightscount= lightscount+1;
         }
         else
         {
             lightscount=0;
         }
         }
         hourlyconsumption=heatingcount*300+ventilationcount*250+lightscount*100;
         fprintf(fptr8, "\t%d\t", hourlyconsumption,RDL->energyconsumption[t]);

         heatingcount=0;
         ventilationcount=0;
         lightscount=0;
         hourlyconsumption=0;

         fscanf(fptr9, "%d", &RDB->inttempcontrolstate[t]);
         if(RDB->inttempcontrolstate[t]==1)
         {
             heatingcount=heatingcount+1;
         }
         else
         {
             heatingcount=0;
         }
         fscanf(fptr9, "%d", &RDB->outtempcontrolstate[t]);
         if(RDB->outtempcontrolstate[t]==1)//IF
         {
             heatingcount= heatingcount+1;
         }
         else
         {
             heatingcount=heatingcount+0;
         }
         fscanf(fptr9, "%d", &RDB->humiditycontrolstate[t]);
         if(RDB->humiditycontrolstate[t]==1)
         {
             ventilationcount= ventilationcount+1;
         }
         else
         {
             ventilationcount=0;
         }
         for ( k=0; k<6; k++)
         {
         fscanf(fptr9, "%d", &RDB->motioncontrolstate[t][k]);
         if(RDB->motioncontrolstate[t][k]==1)
         {
             lightscount= lightscount+1;
         }
         else
         {
             lightscount=0;
         }
         }
         hourlyconsumption=heatingcount*300+ventilationcount*250+lightscount*100;
         fprintf(fptr10, "\t%d\t", hourlyconsumption,RDB->energyconsumption[t]);

         heatingcount=0;
         ventilationcount=0;
         lightscount=0;
         hourlyconsumption=0;

         fscanf(fptr11, "%d", &RDK->inttempcontrolstate[t]);
         if(RDK->inttempcontrolstate[t]==1)
         {
             heatingcount=heatingcount+1;
         }
         else
         {
             heatingcount=0;
         }
         fscanf(fptr11, "%d", &RDK->outtempcontrolstate[t]);
         if(RDK->outtempcontrolstate[t]==1)
         {
             heatingcount= heatingcount+1;
         }
         else
         {
             heatingcount=heatingcount+0;
         }
         fscanf(fptr11, "%d", &RDK->humiditycontrolstate[t]);
         if(RDK->humiditycontrolstate[t]==1)
         {
             ventilationcount= ventilationcount+1;
         }
         else
         {
             ventilationcount=0;
         }
         for ( k=0; k<6; k++)
         {
         fscanf(fptr11, "%d", &RDK->motioncontrolstate[t][k]);
         if(RDK->motioncontrolstate[t][k]==1)
         {
             lightscount= lightscount+1;
         }
         else
         {
             lightscount=0;
         }
         }
         hourlyconsumption=heatingcount*300+ventilationcount*250+lightscount*100;
         fprintf(fptr12, "\t%d\t", hourlyconsumption,RDK->energyconsumption[t]);


 }
   fclose(fptr7);
   fclose(fptr8);
   fclose(fptr9);
   fclose(fptr10);
   fclose(fptr11);
   fclose(fptr12);
 }
