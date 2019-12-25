#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct employe{
    char ID[20];
    char name[20];
    char add[20];
    char parname[20];
    char pos[20];
    long int phone_no;
};

struct employe emp;

void print_heading(const char st[]){
    printf("\nSRS : %s\n",st);
}

void add_employe(){
    print_heading("Add Record");
    FILE *fp;
    fp = fopen("database.txt","ab+");
    if(fp == NULL){
        printf("NO FILE EXIST\n\n");

    }else{
        fflush(stdin);
        printf("Employe ID: ");gets(emp.ID);
        printf("Name: ");gets(emp.name);
        printf("Address: ");gets(emp.add);
        printf("Parent's name: ");gets(emp.parname);
        printf("Position: ");gets(emp.pos);
        printf("Phone Number: ");scanf("%ld",&emp.phone_no);
        fwrite(&emp, sizeof(emp), 1, fp);
        fprintf(fp,("\n"));
        printf("\nThe record is sucessfully added\n\n");
    }
    fclose(fp);
    return;
}


void search_employe(){
    print_heading("Search Record");
    char e_id[15];
    int isFound = 0;
    printf("Enter ID to Search: ");fflush(stdin);
    gets(e_id);
    FILE *fp;
    fp = fopen("database.txt","a+");
    while(fread(&emp,sizeof(emp),1,fp) == 1){
        if(strcmp(e_id, emp.ID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        printf("The record is Found\n\n");
        printf("\nID: %s\n",emp.ID);
        printf("Name: %s\n",emp.name);
        printf("Address: %s\n",emp.add);
        printf("Parent's Name: %s\n",emp.parname);
        printf("Position: %d\n",emp.pos);
        printf("Phone No: %ld\n\n",emp.phone_no);
    }else{
        printf("Sory, No record found in the database\n\n");
    }
    fclose(fp);
        return;
}

void mod_employe(){
    print_heading("Modify Record");
    char e_id[15];
    int isFound = 0;
    printf("Enter ID to Modify: ");
    fflush(stdin);
    gets(e_id);
    FILE *fp;
    fp = fopen("database.txt","r+");
    while(fread(&emp, sizeof(emp),1,fp) == 1){
        if(strcmp(e_id, emp.ID) == 0){
            fflush(stdin);
            printf("ID: ");gets(emp.ID);
            printf("Name: ");gets(emp.name);
            printf("Address: ");gets(emp.add);
            printf("Parent's name: ");gets(emp.parname);
            printf("Position: ");gets(emp.pos);
            printf("Phone Number: ");scanf("%ld",&emp.phone_no);
            printf("\n");
            fseek(fp,-sizeof(emp), SEEK_CUR);
            fwrite(&emp, sizeof(emp), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        printf("No Record Found\n\n");
    }
    fclose(fp);
    return;
}

 void delete_employe(){
    print_heading("Delete Record");
    char e_id[15];
    int isFound = 0;
    printf("Enter ID to Delete: ");fflush(stdin);
    gets(e_id);
    FILE *fp, *temp;
    fp = fopen("record.txt","r+");
    temp = fopen("temp.txt", "w");
    while(fread(&emp, sizeof(emp),1,fp) == 1){
        if(strcmp(e_id, emp.ID) == 0){
            fwrite(&emp,sizeof(emp),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("database.txt");
    rename("temp.txt","database.txt");
    printf("\n\nThe record is sucessfully deleted\n\n");
    return;
}

void main(){
    int choice;
    int x = 2;

    printf("\t\t\tEMPLOYE INFORMATION COLLECTING SYSTEM\t\t\t\n");
    printf("\t\t\t\tBATA SHOP, Dhaka\t\t\n");
    printf("\t\t\t\t  Estd.: 2002\t\t\t\n");

    while(1){
        printf("1. Add Employe Information\n");
        printf("2. Search Employe\n");
        printf("3. Modify Employe Record\n");
        printf("4. Delete Employe Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_employe();
                break;
            case 2:
                search_employe();
                break;
            case 3:
                mod_employe();
                break;
            case 4:
                delete_employe();
                break;
            case 5:
                exit(0);
                break;
            default:
                break;
        }

    }

}






