#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	long int info;
	struct node *next;
} nodeptr;


typedef struct {
	nodeptr *inicio;
	nodeptr *fim;
} lista;


int inicializaLista (lista *no) {
	nodeptr *novo = (nodeptr *) malloc (sizeof(nodeptr));
	no->inicio=novo;
	no->fim=novo;
	novo->info=-1;
	novo->next=NULL;
}

int insereElemento (lista *no, int elemento) {
	nodeptr *novo = (nodeptr *) malloc (sizeof(nodeptr));
	novo->info=elemento;
	novo->next=NULL;
	
	if (no->inicio==NULL) {
		no->inicio=novo;
		no->fim=novo;
		novo->info=-1;
	} else {
		no->fim->next=novo;
		no->fim=novo;
	}
}

int contaAlgarismos(char* numero) {
	int i=0;
	char caractere;
	caractere='0';
	while (caractere!='\0') {
		caractere=numero[i];
		i++;
	}
	return i-1;
}

int divideString(char* numero, int tam, lista *no) {
	int i=0, j=0, k=0;
	long int num=0;
	char string[5];
	
	for (i=tam; i>0; i=i-5) {
		k=0;
		if (i>=5) {
			for (j=i-5; j<i; j++) {
				string[k]=numero[j];
				k++;
			}
		} else {
			for (j=0; j<(contaAlgarismos(numero)%5); j++) {
				string[k]=numero[j];
				string[k+1]='\0';
				k++;
			}
		}
		num=atoi(string);
		insereElemento(no, num);
	}
}

int addin (lista *no1, lista *no2, lista *no3) {
	long int soma;
	soma=0;
	nodeptr *aux1;
	nodeptr *aux2;
	int tamAux1=0, i=0;
	int tamAux2=0;
	
	aux1=no1->inicio->next;
	aux2=no2->inicio->next;
	


	while (aux1 != NULL) {
		if (aux1->info!=-1) {
			i++;
		}
		aux1=aux1->next;
	}
	tamAux1=i;
	i=0;
	while (aux2 != NULL) {
		if (aux2->info!=-1) {
			i++;
		}
		aux2=aux2->next;
	}
	tamAux2=i;


	aux1=no1->inicio->next;
	aux2=no2->inicio->next;
	
	if (tamAux1>tamAux2) {
		while (aux2!=NULL) {
			if  (aux1!=NULL ) {
				soma=soma+(aux1->info+aux2->info);
				insereElemento(no3, (soma%100000));
				if (soma/100000!=0) {
					soma=soma/100000;
				} else {
					soma=0;
				}
		
				aux1=aux1->next;
	
				aux2=aux2->next;
			}
		}
		
		
	} else {
		while (aux1!=NULL) {
			if  ( aux2!=NULL ) {
				soma=soma+(aux1->info+aux2->info);
				insereElemento(no3, (soma%100000));
			
				if (soma/100000!=0) {
					soma=soma/100000;
				} else {
					soma=0;
				}
		
				aux1=aux1->next;
	
				aux2=aux2->next;
			}
		}
	}

		
	if (tamAux1==tamAux2) {
		if (soma!=0) {
			insereElemento(no3, (soma));
		}
	}
	
	
	if (aux1 == NULL && aux2 != NULL) {
		while (aux2 != NULL) {
			
		soma=soma+aux2->info; 	
		insereElemento(no3, (soma%100000));
			if (soma/100000!=0) {
				soma=soma/100000;
			}
		aux2=aux2->next;
		}
		
	} else if (aux1!= NULL && aux2 == NULL) {
		while (aux1 != NULL) {
		soma=soma+aux1->info;
		insereElemento(no3, (soma%100000));
			if (soma/100000!=0) {
				soma=soma/100000;
			} else {
					soma=0;
				}
			aux1=aux1->next;
		}
		
	}
	

	return 1;
}

int imprimeLista (lista *no) {

	nodeptr *aux = (nodeptr *) malloc (sizeof(nodeptr));
	aux=no->inicio;
	
	int i=0, j=0, *vet;
	
	while (aux != NULL) {
		if (aux->info!=-1) {
			i++;
		}
		aux=aux->next;
	}

	aux=no->inicio;
	vet= ((int *)malloc (sizeof(int)*i));

	while (aux != NULL) {
		if (aux->info!=-1) {
			vet[j]=aux->info;
			j++;
		}
		aux=aux->next;
	}


	printf ("%d", vet[i-1]);
	for (j=i-2; j>=0; j--) {
		printf ("%05d", vet[j]);
	}

}




main () {
	lista no1;
	lista no2;
	lista no3;
	char numero1[70], numero2[70];
	
	inicializaLista(&no1);
	inicializaLista(&no2);
	inicializaLista(&no3);

	printf ("Insira o primeiro numero a ser somado: ");
	scanf ("%s", &numero1);
	
	printf ("Insira o segundo numero a ser somado: ");
	scanf ("%s", &numero2);
	

	divideString(numero1, contaAlgarismos(numero1), &no1);
	divideString(numero2, contaAlgarismos(numero2), &no2);
	
	addin(&no1, &no2, &no3);
	printf("A soma dos dois numeros resulta no numero: \n");
	imprimeLista(&no3);
	 
}
