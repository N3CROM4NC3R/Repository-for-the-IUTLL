#ifndef DATA_STRUCTURE_H_
#define DATA_STRUCTURE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
	char name[100];
	char document[100];
	char password[100];
	char age[100];
	char number_phone[100];
	char weight[100];
	struct Node* next;
	struct Node* previous;
};
typedef struct {
	struct Node* head;
	struct Node* final;
}list;
void liberate_list(list*);
void show_list(list*);
void load_users(list*);
void download_users(list*);
int delete_user(list*,char[]);
int found_user(list *,char [],struct Node**);
void load_users(list *users){
	struct Node *incoming=NULL;	
	FILE *fichero;
	char name_new[100];
	char document_new[100];
	char password_new[100];
	char age_new[100];
	char phone_new[100];
	char weight_new[100];
	fichero=fopen("registroUsuario.txt","r");
	if(fichero==NULL){
		return ;
	}
	else{
		while(feof(fichero)==0){
			incoming=(struct Node*)malloc(sizeof(struct Node));
			fscanf(fichero,"%s %s %s %s %s %s\n",name_new,document_new,password_new,age_new,phone_new,weight_new);
			strcpy(incoming->name,name_new);
			strcpy(incoming->document,document_new);
			strcpy(incoming->password,password_new);
			strcpy(incoming->age,age_new);
			strcpy(incoming->number_phone,phone_new);
			strcpy(incoming->weight,weight_new);
			if(users->head==NULL){
				users->head=incoming;
				users->final=incoming;
				incoming->next=NULL;
				incoming->previous=NULL;
			}
			else{
				users->final->next=incoming;
				incoming->previous=users->final;
				users->final=incoming;
				incoming->next=NULL;	
			}
		}
	}
	fclose(fichero);
}
void download_users(list *users){
	FILE *file;
	char name_new[100];
	char document_new[100];
	char password_new[100];
	char age_new[100];
	char phone_new[100];
	char weight_new[100];
	if(!users->head){
		remove("registroUsuario.txt");
		return ;
	}
	struct Node *pointer=users->head;
	file=fopen("registroUsuario.txt","w");
	while(pointer){
		fflush(file);
		strcpy(name_new,pointer->name);
		strcpy(document_new,pointer->document);
		strcpy(password_new,pointer->password);
		strcpy(age_new,pointer->age);
		strcpy(phone_new,pointer->number_phone);
		strcpy(weight_new,pointer->weight);
		fprintf(file,"%s %s %s %s %s %s\n",name_new,document_new,password_new,age_new,phone_new,weight_new);
		pointer=pointer->next;	
	}
	fclose(file);
}
int delete_user(list *users,char user_to_delete[]){
	struct Node *pointer=users->head;
	bool found=false;
	printf("before list\n");
	show_list(users);
	while(found==false&&pointer!=NULL){
		if(strcmp(pointer->name,user_to_delete)==0){
			found=true;
		}
		else{
			pointer=pointer->next;
		}
	}
	printf("middle list\n");
	show_list(users);
	if(found==true){
		if(pointer->previous==NULL){
			
			users->head=users->head->next;
			printf("debug\n");
			if(users->head){
				users->head->previous=NULL;
			}
			printf("debug\n");
			free(pointer);
		}
		else if(pointer->next==NULL){
			users->final=users->final->previous;
			if(users->final){
				users->final->next=NULL;
			}
			free(pointer);
		}
		else{
			pointer->previous->next=pointer->next;
			pointer->next->previous=pointer->previous;
			free(pointer);
		}
	}
	else{
		printf("User not found\n");
		system("pause");
		return -1;
	}
	printf("\nafter list:\n\n");
	show_list(users);
	printf("User eliminate with successful\n");
	system("pause");
	return 0;
}
int repeated_name(list *users,char user_repeated[]){
	struct Node *pointer=users->head;
	while(pointer){
		if(strcmp(pointer->name,user_repeated)==0){
			return 1;
		}
		else{
			pointer=pointer->next;
		}
	}
	return 0;
}
int repeated_document(list *users,char document_repeated[]){
	struct Node *pointer=users->head;
	while(pointer){
		if(strcmp(pointer->document,document_repeated)==0){
			return 1;
		}
		else{
			pointer=pointer->next;
		}
	}
	return 0;
}
void new_user_list(list *users,struct Node *incoming){
	if(users->head==NULL){
		users->head=incoming;
		users->final=incoming;
		incoming->previous=NULL;
		incoming->next=NULL;
	}
	else{
		users->final->next=incoming;
		incoming->previous=users->final;
		users->final=incoming;
		incoming->next=NULL;
	}
}
int found_user(list *users,char name_to_found[],struct Node**pointer){
	pointer[0]=users->head;
	while(pointer[0]){
		if(strcmp(pointer[0]->name,name_to_found)==0){
			return 0;
		}
		else{
			pointer[0]=pointer[0]->next;
		}
	}
	return -1;
}
void show_list(list *users){
	struct Node *pointer=users->head;
	int i=1;
	while(pointer){
		printf("Name %d=%s\n",i,pointer->name);
		printf("Document %d=%s\n",i,pointer->document);
		printf("Password %d=%s\n",i,pointer->password);
		printf("Age %d=%s\n",i,pointer->age);
		printf("Phone %d=%s\n",i,pointer->number_phone);
		printf("Weight %d=%s\n",i,pointer->weight);
		pointer=pointer->next;
		i++;
	}
	system("pause");
}
void liberate_list(list *users){
	struct Node *pointer=users->head;
	while(pointer){
		users->head=users->head->next;
		free(pointer);
		pointer=users->head;	
	}
}
#endif
