#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Data structure.h"
void admin();
void manager_admin();
void create_user_admin();
void delete_user_admin();
void modify_user_admin();
void search_user_admin();
void admin(){
	char usuario[30],contrasenia[30];
	bool salir=false;
		printf("\t\t\t#########################\n");
		printf("\t\t\t#WELCOME TO ADNIN LOGING#\n");
		printf("\t\t\t#########################\n");
		printf("--------------------------------------------------------------------------------");
		printf("\t\tUsername: ");
		scanf("%s",&usuario);
		printf("\t\tPassword: ");
		scanf("%s",&contrasenia);
		if(strcmp(usuario,"admin")==0&&strcmp(contrasenia,"admin")==0){
			printf("\t\t###############\n");
			printf("\t\t#WELCOME ADMIN#\n");
			printf("\t\t###############\n");
			system("pause");
			manager_admin();
		}
		else{
			printf("\t\t############################\n");
			printf("\t\t#WRONG USERNAME OR PASSWORD#\n");
			printf("\t\t############################\n");
			system("pause");
		}	
	return ;
}
void manager_admin(){
	int opcion=0;
	bool salir=false;
	while(salir==0){
		system("cls");
		printf("\t\t##########################\n");
		printf("\t\t#WELCOME TO MANAGER ADMIN#\n");
		printf("\t\t##########################\n");
		printf("--------------------------------------------------------------------------------");
		printf("\t\tSelect your option:\n");
		printf("\t\t1)Create a user\n");
		printf("\t\t2)Delete a user\n");
		printf("\t\t3)Modificate a user\n");
		printf("\t\t4)Search a user\n");
		printf("\t\t5)Exit\n");
		printf("\t\tOPTION:");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 1:{
				create_user_admin();
				break;
			}
			case 2:{
				delete_user_admin();
				break;
			}
			case 3:{
				modify_user_admin();
				break;
			}
			case 4:{
				search_user_admin();
				break;
			}
			case 5:{
				salir=true;
				system("cls");
				printf("\t\t################\n");
				printf("\t\t#Good bye admin#\n");
				printf("\t\t################\n");
				break;
			}
		}
	}
}
void create_user_admin(){
	list users;
	users.final=NULL;
	users.head=NULL;
	struct Node *incoming=(struct Node*)malloc(sizeof(struct Node));
	load_users(&users);	
	printf("\t\t\t#############\n");
	printf("\t\t\t#Create User#\n");
	printf("\t\t\t#############\n");
	printf("--------------------------------------------------------------------------------");
	printf("\t\tEnter the username of the new user: ");
	scanf("%s",&incoming->name);
	printf("\t\tEnter the document of the new user: ");
	scanf("%s",&incoming->document);
	printf("\t\tEnter the password of the new user: ");
	scanf("%s",&incoming->password);
	printf("\t\tEnter the age of the new user: ");
	scanf("%s",&incoming->age);
	printf("\t\tEnter the phone number of the new user: ");
	scanf("%s",&incoming->number_phone);
	printf("\t\tEnter the weight of the new user: ");
	scanf("%s",&incoming->weight);
	system("cls");
	if(repeated_name(&users,incoming->name)==1){
		printf("\t\t###############\n");
		printf("\t\t#User repeated#\n");
		printf("\t\t###############\n");
		system("pause");
		return ;
	}
	if(repeated_document(&users,incoming->document)==1){
		printf("\t\t###################\n");
		printf("\t\t#Document repeated#\n");
		printf("\t\t###################\n");
		system("pause");
		return ;
	}
	new_user_list(&users,incoming);
	download_users(&users);
	printf("\t\t#################################\n");
	printf("\t\t#User created with successful :)#\n");
	printf("\t\t#################################\n");
	system("pause");
	liberate_list(&users);
}
void delete_user_admin(){
	char name_to_delete[100];
	list users;
	users.final=NULL;
	users.head=NULL;
	load_users(&users);
	if(users.head==NULL){
		printf("\t\t############\n");
		printf("\t\t#list empty#\n");
		printf("\t\t############\n");
		system("pause");
		return ;
	}
	printf("\t\t#############\n");
	printf("\t\t#DELETE USER#\n");
	printf("\t\t#############\n");
	printf("--------------------------------------------------------------------------------");
	printf("\t\tEnter the name to delete:");
	scanf("%s",&name_to_delete);
	system("cls");
	if(delete_user(&users,name_to_delete)==0){
		download_users(&users);
	}
	liberate_list(&users);
}
void modify_user_admin(){
	list users;
	users.head=NULL;
	users.final=NULL;
	load_users(&users);
	if(!users.head){
		printf("\t\t############\n");
		printf("\t\t#list empty#\n");
		printf("\t\t############\n");
		system("pause");
		return ;
	}
	bool exit=false;
	char name_to_modify[100];
	struct Node *pointer;
	int option;
	printf("\t\t\t#############\n");
	printf("\t\t\t#MODIFY USER#\n");
	printf("\t\t\t#############\n");
	printf("--------------------------------------------------------------------------------");
	printf("\t\tEnter the user to modify\n");
	scanf("%s",&name_to_modify);
	system("cls");
	if(found_user(&users,name_to_modify,&pointer)==0){
		while(exit==false){
			system("cls");
			printf("\t\t\t#############\n");
			printf("\t\t\t#MODIFY USER#\n");
			printf("\t\t\t#############\n");
			printf("--------------------------------------------------------------------------------");
			printf("\t\tEnter the option to modify\n");
			printf("\t\tName of user to modify:%s\n",pointer->name);
			printf("\t\t1)Password\n");
			printf("\t\t2)Age\n");
			printf("\t\t3)Number phone\n");
			printf("\t\t4)Weight\n");
			printf("\t\t5)Exit\n");
			scanf("%d",&option);
			system("cls");
			switch(option){
				case 1:{
					printf("\t\tActual password:%s\n",pointer->password);
					printf("\t\tEnter the new password of the user: ");
					scanf("%s",&pointer->document);
					break;
				}
				case 2:{
					printf("\t\tActual age:%s\n",pointer->age);
					printf("\t\tEnter the new age of the user: ");
					scanf("%s",&pointer->age);
					break;
				}
				case 3:{
					printf("\t\tActual phone number:%s\n",pointer->number_phone);
					printf("\t\tEnter the new number phone of the user: ");
					scanf("%s",&pointer->number_phone);
					break;
				}
				case 4:{
					printf("\t\tActual weight:%s\n",pointer->weight);
					printf("\t\tEnter the new weight of the user: ");
					scanf("%s",&pointer->weight);
					printf("New weight: %s\n",pointer->weight);
					break;
				}
				case 5:{
					printf("\t\t##########\n");
					printf("\t\t#Good bye#\n");
					printf("\t\t##########\n");
					exit=true;
					break;
				}
			}
			download_users(&users);	
		}
	}
	else{
		printf("\t\t################\n");
		printf("\t\t#User not found#\n");
		printf("\t\t################\n");
	}
	system("pause");
	liberate_list(&users);
}
void search_user_admin(){
	list users;
	users.head=NULL;
	users.final=NULL;
	load_users(&users);
	if(users.head==NULL){
		printf("\t\t############\n");
		printf("\t\t#LIST EMPTY#\n");
		printf("\t\t############\n");
		system("pause");
		return ;
	}
	printf("Name of the head:%s\n",users.head->name);
	struct Node *pointer;
	
	char username[100];
	printf("\t\t###############\n");
	printf("\t\t#SEARCH A USER#\n");
	printf("\t\t###############\n");
	printf("--------------------------------------------------------------------------------");
	printf("\t\tEnter the name of username to search:");
	scanf("%s",&username);
	printf("debugger\n");
	if(found_user(&users,username,&pointer)==0){
		printf("debugger\n");
		system("cls");
		printf("\t\t###############\n");
		printf("\t\t#SEARCH A USER#\n");
		printf("\t\t###############\n");
		printf("--------------------------------------------------------------------------------");
		printf("\t\tName:%s\n",pointer->name);
		printf("\t\tDocument:%s\n",pointer->document);
		printf("\t\tPassword:%s\n",pointer->password);
		printf("\t\tAge:%s\n",pointer->age);
		printf("\t\tPhone number:%s\n",pointer->number_phone);
		printf("\t\tWeight:%s\n",pointer->weight);
		system("pause");
	}
	else{
		printf("\t\t################\n");
		printf("\t\t#User not found#\n");
		printf("\t\t################\n");
		system("pause");
	}
}
