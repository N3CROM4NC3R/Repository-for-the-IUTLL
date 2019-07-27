#ifndef USER_H_
#define USER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data structure.h"
void login_user();
void manager_user(char []);
void show_information_user(char[]);
void modify_information_user(char[]);
void login_user(){
	char username[30],password_enter[30];
	list users;
	struct Node *pointer;
	users.head=NULL;
	users.final=NULL;
	load_users(&users);
	if(!users.head){
		printf("\t\tThe file dont have users\n");
		system("pause");
		return ;
	}
	printf("\t\t#######################\n");
	printf("\t\t#Welcome to user login#\n");
	printf("\t\t#######################\n");
	printf("--------------------------------------------------------------------------------");
	printf("\t\tUsername:");
	scanf("%s",&username);
	printf("\t\tPassword: ");
	scanf("%s",&password_enter);
	if(found_user(&users,username,&pointer)==0&&strcmp(pointer->password,password_enter)==0){
		printf("\t\tWelcome,%s",pointer->name);
		manager_user(pointer->name);
	}
	else{
		printf("\t\t############################\n");
		printf("\t\t#Wrong username or password#\n");
		printf("\t\t############################\n");
	}
}
void manager_user(char username[]){
	bool exit=false;
	int option;
	while(exit==false){
		system("cls");
		printf("\t\t#########################\n");
		printf("\t\t#Welcome to manager user#\n");
		printf("\t\t#########################\n");
		printf("\t\tUsername:%s\n",username);
		printf("\t\tSelect your option\n");
		printf("\t\t1)Show information\n");
		printf("\t\t2)Modify information\n");
		printf("\t\t3)Exit\n");
		scanf("%d",&option);
		system("cls");
		switch(option){
			case 1:{
				show_information_user(username);
				break;
			}
			case 2:{
				modify_information_user(username);
				break;
			}
			case 3:{
				exit=true;
				printf("\t\t###############\n");
				printf("\t\t#Good bye user#\n");
				printf("\t\t###############\n");
				system("pause");
				break;
			}
		}
	}
}
void show_information_user(char username[]){
	struct Node *pointer=NULL;
	list users;
	users.head=NULL;
	users.final=NULL;
	load_users(&users);
	found_user(&users,username,&pointer);
	printf("\t\t#############\n");
	printf("\t\t#INFORMATION#\n");
	printf("\t\t#############\n");
	printf("--------------------------------------------------------------------------------");
	printf("\t\tName: %s\n",pointer->name);
	printf("\t\tDocument: %s\n",pointer->document);
	printf("\t\tPassword: %s\n",pointer->password);
	printf("\t\tAge:%s\n",pointer->age);
	printf("\t\tNumber of phone:%s\n",pointer->number_phone);
	printf("\t\tWeight in kg:%s\n",pointer->weight);
	liberate_list(&users);
	system("pause");
}
void modify_information_user(char username[]){
	struct Node *pointer;
	list users;
	users.head=NULL;
	users.final=NULL;
	load_users(&users);
	found_user(&users,username,&pointer);
	bool exit=false;
	int option;
	while(exit==false){
		system("cls");
		printf("\t\t#############\n");
		printf("\t\t#MODIFY USER#\n");
		printf("\t\t#############\n");
		printf("--------------------------------------------------------------------------------");
		printf("\t\tSelect a data to modify\n");
		printf("\t\t1)Password\n");
		printf("\t\t2)Age\n");
		printf("\t\t3)Number phone\n");
		printf("\t\t4)Weight\n");
		printf("\t\t5)Exit\n");
		scanf("%d",&option);
		system("cls");
		switch(option){
			case 1:{
				printf("\t\t########################\n");
				printf("\t\t#Enter the new password#\n");
				printf("\t\t########################\n");
				printf("--------------------------------------------------------------------------------");
				printf("\t\tNew Password: ");
				scanf("%s",pointer->password);
				break;
			}
			case 2:{
				printf("\t\t###################\n");
				printf("\t\t#Enter the new age#\n");
				printf("\t\t###################\n");
				printf("--------------------------------------------------------------------------------");
				printf("\t\tNew age");
				scanf("%s",pointer->age);
				break;
			}
			case 3:{
				printf("\t\t#####################\n");
				printf("\t\t#Enter the new phone#\n");
				printf("\t\t#####################\n");
				printf("--------------------------------------------------------------------------------");
				printf("\t\tNew phone");
				scanf("%s",pointer->number_phone);
				break;
			}
			case 4:{
				printf("\t\t######################\n");
				printf("\t\t#Enter the new weight#\n");
				printf("\t\t######################\n");
				printf("--------------------------------------------------------------------------------");
				printf("\t\tNew weight");
				scanf("%s",pointer->weight);
				break;
			}
			case 5:{
				exit=true;
				break;
			}
		}
		download_users(&users);
	}
	liberate_list(&users);
}
#endif
