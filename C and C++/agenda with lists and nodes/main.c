#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libs/admin.h"
#include "libs/user.h"

int main(){
	int opcion;
	bool salir=false;
	while(salir==false){
		system("cls");
		printf("\t\t\t###########################\n");
		printf("\t\t\t#Welcome to N3 Corporation#\n");
		printf("\t\t\t###########################\n");
		printf("--------------------------------------------------------------------------------");
		printf("\t\tSelect the login\n");
		printf("\t\t1)Admin\n");
		printf("\t\t2)User\n");
		printf("\t\t3)Exit\n");
		printf("\t\tOption:");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 1:{
				admin();
				break;
			}
			case 2:{
				login_user();
				break;
			}
			case 3:{
				salir=true;
				printf("\t\t############\n");
				printf("\t\t#Good bye:)#\n");
				printf("\t\t############\n");
				break;
			}
		}
	}
	return 0;
}
