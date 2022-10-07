#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addEmployee(void);
int modifyEmployee(void);
void viewEmployeeData(void);
int removeEmployee(void);
void viewEmployeeScheduleData(void);
void createSchedule(void);

int main(void)
{
    int selectOption = 0;
    while(selectOption == 0 && selectOption != 6){
    printf("Employee Management System\n");
    printf("1.) Add New Employee\n");
    printf("2.) Modify Employee Records and Schedule\n");
    printf("3.) Remove Employee\n");
    printf("4.) View Employee Records\n");
    printf("5.) View Employee Scheduling Data\n");
    printf("6.) Exit System\n");
    scanf("%d",&selectOption);
    switch(selectOption){
    case 1:
        addEmployee();
        break;
    case 2:
        modifyEmployee();
        break;
    case 3:
        removeEmployee();
        break;
    case 4:
         viewEmployeeData();
         break;
    case 5:
        viewEmployeeScheduleData();
        break;
    case 6:
        break;
    default:
        printf("\nERROR: Invalid option. Please select a number between 1 and 6 \n");
        break;
    }
    if(selectOption == 6)
    break;

    selectOption = 0;
    }
    return 0;
}

struct employee
{
    char fName[50];
    char lName[50];
    int id;
    int age;
    char jobTitle[50];
    float hourlyRate;
    int minHours;
    int maxHours;
    //when set to 0 the employees unavailable, 1 means they can only work first shift, 2 means they can only work second shift, 3 means they can work any shift
    int dayOfWeek[7];
};
struct employee e;

void addEmployee(void){
    int i;
    char addEmp = 'y';
    char sRestrictions = '0';
    FILE *fp;

    fp = fopen("employeeData.txt","a+");

    if(fp == NULL)
        perror("Error in opening file. A new file has been created.");
    while(addEmp == 'y'){
sRestrictions = '0';
printf("Please enter the employees first name:\n");
scanf(" %s",e.fName);
printf("Please enter the employees last name:\n");
scanf(" %s",e.lName);
printf("Please enter the employees id:\n");
scanf(" %d",&e.id);
printf("Please enter the employees current age:\n");
scanf(" %d",&e.age);
printf("Please enter the employees current job:\n");
scanf(" %s",e.jobTitle);
printf("Please enter the employees current hourly rate:\n$");
scanf(" %f",&e.hourlyRate);
printf("Please enter the minimum amount of hours the employee wants to work:\n");
scanf(" %d",&e.minHours);
printf("Please enter the max amount of hours the employee wants to work:\n");
scanf(" %d",&e.maxHours);
//asks if there are schedule restrictions
printf("Does %s %s have any schedule restrictions? (Y/N)\n",e.fName, e.lName);
scanf(" %c",&sRestrictions);
if(sRestrictions != 'y' && sRestrictions != 'n'){
printf("Press y or n.\n");
scanf(" %c",&sRestrictions);
}else if(sRestrictions == 'y'){
        printf("\n0 = UNAVAILIABLE\n1 = RESTRICTED TO FIRST SHIFT\n2 = RESTRICTED FOR SECOND SHIFT\n3 = AVAILABLE\n");
    printf("Does %s %s have any schedule restrictions on Monday?:\n",e.fName,e.lName);
scanf(" %d",&e.dayOfWeek[0]);
    printf("Does %s %s have any schedule restrictions on Tuesday?:\n",e.fName,e.lName);
scanf(" %d",&e.dayOfWeek[1]);
    printf("Does %s %s have any schedule restrictions on Wednesday?:\n",e.fName,e.lName);
scanf(" %d",&e.dayOfWeek[2]);
    printf("Does %s %s have any schedule restrictions on Thursday?:\n",e.fName,e.lName);
scanf(" %d",&e.dayOfWeek[3]);
    printf("Does %s %s have any schedule restrictions on Friday?:\n",e.fName,e.lName);
scanf(" %d",&e.dayOfWeek[4]);
    printf("Does %s %s have any schedule restrictions on Saturday?:\n",e.fName,e.lName);
scanf(" %d",&e.dayOfWeek[5]);
    printf("Does %s %s have any schedule restrictions on Sunday?:\n",e.fName,e.lName);
scanf(" %d",&e.dayOfWeek[6]);
} else if(sRestrictions == 'n'){
    for(i = 0; i <= 6; ++i)
    e.dayOfWeek[i] = 3;
}
fprintf(fp,"\n%s %s %d %d %s %f %d %d %d %d %d %d %d %d %d",e.fName,e.lName,e.id,e.age,e.jobTitle,e.hourlyRate,e.minHours,e.maxHours,e.dayOfWeek[0],e.dayOfWeek[1],e.dayOfWeek[2],e.dayOfWeek[3],e.dayOfWeek[4],e.dayOfWeek[5],e.dayOfWeek[6]);

//asks if u want to add a new employee
    printf("\nWould you like to add another employee? (Y/N)");
    scanf(" %c",&addEmp);
    if(addEmp == 'n'){
        break;
    }
    else if(addEmp != 'y' && addEmp != 'n'){
        printf("Invalid input. Please press y to add another employee or press n to exit.");
        scanf(" %c",&addEmp);
    }
    }
    fclose(fp);
    fp = NULL;
}

int modifyEmployee(void){
    char modEmpLoop = 'y';
    while(modEmpLoop == 'y'){
    int modEmp = 0, found = 0, i = 0, j = 0;
    char choice = '0';
    char sRestrictions = '0';
viewEmployeeData();
printf("\n\n\n");
    FILE *fp;
    fp = fopen("employeeData.txt","a+");
    if(fp == NULL)
        perror("Error in opening file. A new file has been created.");
    rewind(fp);

    FILE *fp2;
    fp2 = fopen("temp.txt","w");
    if(fp2 == NULL)
        perror("Error in opening file");
    printf("Which employee would you like to modify: ");
    scanf(" %d",&modEmp);
        while(!feof(fp) && !found){
        ++i;
        fscanf(fp,"\n%s %s %d %d %s %f %d %d %d %d %d %d %d %d %d",e.fName,e.lName,&e.id,&e.age,e.jobTitle,&e.hourlyRate,&e.minHours,&e.maxHours,&e.dayOfWeek[0],&e.dayOfWeek[1],&e.dayOfWeek[2],&e.dayOfWeek[3],&e.dayOfWeek[4],&e.dayOfWeek[5],&e.dayOfWeek[6]);
        if(i == modEmp){
        found = 1;
        printf("\nEMPLOYEE #%d's RECORDS\n",i);
        printf("First Name\tLast Name\t\tID\tAge\tTitle\tHourly Rate   Min Hours   Max Hours\n");
        printf("%s\t\t%s\t\t\t%d\t%d\t%s\t$%g\t      %d\t\t  %d\n",e.fName,e.lName,e.id,e.age,e.jobTitle,e.hourlyRate,e.minHours,e.maxHours);
        printf("\nSCHEDULING DATA FOR EMPLOYEE #%d\n",i);
        printf("Mon Tue Wed Thu Fri Sat Sun\n");
        printf(" %d   %d   %d   %d   %d   %d   %d\n",e.dayOfWeek[0],e.dayOfWeek[1],e.dayOfWeek[2],e.dayOfWeek[3],e.dayOfWeek[4],e.dayOfWeek[5],e.dayOfWeek[6]);
        printf("\n0 = UNAVAILIABLE\n1 = RESTRICTED TO FIRST SHIFT\n2 = RESTRICTED FOR SECOND SHIFT\n3 = AVAILABLE\n");
        printf("\nAre you sure you want to modify employee #%d? (Y/N)",i);
        scanf(" %c", &choice);
        if(choice == 'n'){
            return 0;
        } else if(choice == 'y'){
        rewind(fp);
        //copys all content from old file to new file beside employee to mod
        while(!feof(fp)){
        ++j;
        fscanf(fp,"\n%s %s %d %d %s %f %d %d %d %d %d %d %d %d %d",e.fName,e.lName,&e.id,&e.age,e.jobTitle,&e.hourlyRate,&e.minHours,&e.maxHours,&e.dayOfWeek[0],&e.dayOfWeek[1],&e.dayOfWeek[2],&e.dayOfWeek[3],&e.dayOfWeek[4],&e.dayOfWeek[5],&e.dayOfWeek[6]);
        if(j != modEmp)
        fprintf(fp2,"%s\t%s\t%d\t%d\t%s\t%f\t%d\t%d\n",e.fName,e.lName,e.id,e.age,e.jobTitle,e.hourlyRate,e.minHours,e.maxHours);
        }
        }
        }
    }
        printf("Please enter the employees  new first name:\n");
        scanf(" %s",e.fName);
        printf("Please enter the employees new last name:\n");
        scanf(" %s",e.lName);
        printf("Please enter the employees new id:\n");
        scanf(" %d",&e.id);
        printf("Please enter the employees new age:\n");
        scanf(" %d",&e.age);
        printf("Please enter the employees new job:\n");
        scanf(" %s",e.jobTitle);
        printf("Please enter the employees new hourly rate:\n$");
        scanf(" %f",&e.hourlyRate);
        printf("Please enter the minimum amount of hours the employee wants to work:\n");
        scanf(" %d",&e.minHours);
        printf("Please enter the max amount of hours the employee wants to work:\n");
        scanf(" %d",&e.maxHours);
        printf("Please enter employee #%d's new scheduling data\n",i);
        printf("Does %s %s have any schedule restrictions? (Y/N)\n",e.fName, e.lName);
scanf(" %c",&sRestrictions);
if(sRestrictions != 'y' && sRestrictions != 'n'){
printf("Press y or n.\n");
scanf(" %c",&sRestrictions);
}else if(sRestrictions == 'y'){
    printf("Does %s %s have any schedule restrictions on Monday?:\n",e.fName,e.lName);
scanf(" %d",&e.dayOfWeek[0]);
    printf("Does %s %s have any schedule restrictions on Tuesday?:\n",e.fName,e.lName);
scanf(" %d",&e.dayOfWeek[1]);
    printf("Does %s %s have any schedule restrictions on Wednesday?:\n",e.fName,e.lName);
scanf(" %d",&e.dayOfWeek[2]);
    printf("Does %s %s have any schedule restrictions on Thursday?:\n",e.fName,e.lName);
scanf(" %d",&e.dayOfWeek[3]);
    printf("Does %s %s have any schedule restrictions on Friday?:\n",e.fName,e.lName);
scanf(" %d",&e.dayOfWeek[4]);
    printf("Does %s %s have any schedule restrictions on Saturday?:\n",e.fName,e.lName);
scanf(" %d",&e.dayOfWeek[5]);
    printf("Does %s %s have any schedule restrictions on Sunday?:\n",e.fName,e.lName);
scanf(" %d",&e.dayOfWeek[6]);
} else if(sRestrictions == 'n'){
    for(i = 0; i <= 6; ++i)
    e.dayOfWeek[i] = 3;
}
        fscanf(fp,"\n%s %s %d %d %s %f %d %d %d %d %d %d %d %d %d",e.fName,e.lName,&e.id,&e.age,e.jobTitle,&e.hourlyRate,&e.minHours,&e.maxHours,&e.dayOfWeek[0],&e.dayOfWeek[1],&e.dayOfWeek[2],&e.dayOfWeek[3],&e.dayOfWeek[4],&e.dayOfWeek[5],&e.dayOfWeek[6]);
        fprintf(fp2,"\n%s %s %d %d %s %f %d %d %d %d %d %d %d %d %d",e.fName,e.lName,e.id,e.age,e.jobTitle,e.hourlyRate,e.minHours,e.maxHours,e.dayOfWeek[0],e.dayOfWeek[1],e.dayOfWeek[2],e.dayOfWeek[3],e.dayOfWeek[4],e.dayOfWeek[5],e.dayOfWeek[6]);
        fclose(fp2);
        fp2 = NULL;
    fclose(fp);
    fp = NULL;
    remove("employeeData.txt");
    rename("temp.txt", "employeeData.txt");
    fp = NULL;

    printf("\nEmployee successfully modified.\n");
    viewEmployeeData();
            printf("\nWould you like to modify another employee? (Y/N)");
    scanf(" %c",&modEmpLoop);
    if(modEmpLoop == 'n'){
        return 0;
    }
    else if(modEmpLoop != 'y' && modEmpLoop != 'n'){
        printf("Invalid input. Please press y to modify another employee or press n to exit.");
        scanf(" %c",&modEmpLoop);
    }
}

return 0;
}

void viewEmployeeData(void){
    int i = 0, found = 0;
    FILE *fp;
    fp = fopen("employeeData.txt","r");
    if(fp == NULL)
        perror("Error in opening file. Does it exist?");
    //set pointer to start of file
    rewind(fp);
    printf("\t     First Name\t\tLast Name\t\tID\tAge\tTitle\tHourly Rate   Min Hours   Max Hours\n");
    //loop to print employee data
    while(!feof(fp) && !found){
        ++i;
        fscanf(fp,"\n%s %s %d %d %s %f %d %d %d %d %d %d %d %d %d",e.fName,e.lName,&e.id,&e.age,e.jobTitle,&e.hourlyRate,&e.minHours,&e.maxHours,&e.dayOfWeek[0],&e.dayOfWeek[1],&e.dayOfWeek[2],&e.dayOfWeek[3],&e.dayOfWeek[4],&e.dayOfWeek[5],&e.dayOfWeek[6]);
        if(strlen(e.fName) == 0)
        found = 1;
        printf("\nEmployee %d.) %s\t\t%s\t\t\t%d\t%d\t%s\t$%g\t      %d\t\t  %d\n",i,e.fName,e.lName,e.id,e.age,e.jobTitle,e.hourlyRate,e.minHours,e.maxHours);

    }
    fclose(fp);
    fp = NULL;
}
//removes an employee by copying all employee information besides the employee that will be removed into a new file
int removeEmployee(void){
    char removeEmpLoop = 'y';
    while(removeEmpLoop == 'y'){
    int removeEmp = 0, found = 0, i = 0, j = 0;
    char choice = '0';
viewEmployeeData();
printf("\n\n\n");
    FILE *fp;
    fp = fopen("employeeData.txt","a+");
    if(fp == NULL)
        perror("Error in opening file. A new file has been created.");
    rewind(fp);
    printf("Which employee would you like to remove: ");
    scanf(" %d",&removeEmp);
        while(!feof(fp) && !found){
        ++i;
        fscanf(fp,"\n%s %s %d %d %s %f %d %d %d %d %d %d %d %d %d",e.fName,e.lName,&e.id,&e.age,e.jobTitle,&e.hourlyRate,&e.minHours,&e.maxHours,&e.dayOfWeek[0],&e.dayOfWeek[1],&e.dayOfWeek[2],&e.dayOfWeek[3],&e.dayOfWeek[4],&e.dayOfWeek[5],&e.dayOfWeek[6]);
        if(i == removeEmp){
        found = 1;
        printf("\nEmployee %d.) %s\t  %s\t\t%d\t%d\t%s \t%f\t%d\t\t%d\n",i,e.fName,e.lName,e.id,e.age,e.jobTitle,e.hourlyRate,e.minHours,e.maxHours);
        printf("\nAre you sure you want to remove employee #%d? (Y/N)",i);
        scanf(" %c", &choice);
        if(choice == 'n'){
            return 0;
        } else if(choice == 'y'){
        rewind(fp);
        FILE *fp2;
        fp2 = fopen("temp.txt","w");
        if(fp2 == NULL)
        perror("Error in opening file");
        while(!feof(fp)){
        ++j;
        fscanf(fp,"\n%s %s %d %d %s %f %d %d %d %d %d %d %d %d %d",e.fName,e.lName,&e.id,&e.age,e.jobTitle,&e.hourlyRate,&e.minHours,&e.maxHours,&e.dayOfWeek[0],&e.dayOfWeek[1],&e.dayOfWeek[2],&e.dayOfWeek[3],&e.dayOfWeek[4],&e.dayOfWeek[5],&e.dayOfWeek[6]);
        if(j != removeEmp)
        fprintf(fp2,"%s\t%s\t%d\t%d\t%s\t%f\t%d\t%d\n",e.fName,e.lName,e.id,e.age,e.jobTitle,e.hourlyRate,e.minHours,e.maxHours);
        }
        fclose(fp2);
        fp2 = NULL;
        }
        }
    }
    fclose(fp);
    fp = NULL;
    remove("employeeData.txt");
    rename("temp.txt", "employeeData.txt");

    printf("\nEmployee successfully removed.\n");
    viewEmployeeData();
    printf("\n\n");
        printf("\nWould you like to remove another employee? (Y/N)");
    scanf(" %c",&removeEmpLoop);
    if(removeEmpLoop == 'n'){
        return 0;
    }
    else if(removeEmpLoop != 'y' && removeEmpLoop != 'n'){
        printf("Invalid input. Please press y to remove another employee or press n to exit.");
        scanf(" %c",&removeEmpLoop);
    }
    }
return 0;
}

void viewEmployeeScheduleData(void){
        FILE *fp;
        fp = fopen("employeeData.txt","r");
    if(fp == NULL)
        perror("Error in opening file. Does it exist?");

    printf("EMPLOYEE AVAILABILITY\n");
    printf("\nName:\t\tMon Tue Wed Thu Fri Sat Sun\t   Min Hours\t  Max Hours\n");
    while(!feof(fp)){
    fscanf(fp,"\n%s %s %d %d %s %f %d %d %d %d %d %d %d %d %d",e.fName,e.lName,&e.id,&e.age,e.jobTitle,&e.hourlyRate,&e.minHours,&e.maxHours,&e.dayOfWeek[0],&e.dayOfWeek[1],&e.dayOfWeek[2],&e.dayOfWeek[3],&e.dayOfWeek[4],&e.dayOfWeek[5],&e.dayOfWeek[6]);
    printf("%s %s\t %d   %d   %d   %d   %d   %d   %d\t\t%d\t\t%d\n",e.fName,e.lName,e.dayOfWeek[0],e.dayOfWeek[1],e.dayOfWeek[2],e.dayOfWeek[3],e.dayOfWeek[4],e.dayOfWeek[5],e.dayOfWeek[6],e.minHours,e.maxHours);

}
    printf("\n0 = UNAVAILIABLE\n1 = RESTRICTED TO FIRST SHIFT\n2 = RESTRICTED FOR SECOND SHIFT\n3 = AVAILABLE\n\n");
    fclose(fp);
    fp = NULL;
}

