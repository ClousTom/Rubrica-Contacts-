#include <iostream>
#include <stdio.h>
#include <list>
#include <string>
using namespace std;

struct node {
    string nome;
    string cognome;
    string number;
    node *next = NULL;
    node *backNode = NULL;
};

node *start = new node;

void insertNum(string nome, string cognome, string number);
void printList();
void cerca(string cercando);
void cancella(string cancellando);
void sortby(char b);

void menu(){ //ricorsione multipla
    printf("Cosa vuoi fare?\n");
    char a=0,b;
    printf(" 1.Visualizza numeri\n 2.Inserisci numero\n 3.Cerca\n 4.Elimina\n 5.Ordina\n\n");
    cin>>a;
    string nome;
    string cognome;
    string number;
    string cercando;
    string cancellando;
  switch (a) {
  case '1':
      printList();
    break;
  case '2':
      printf("Scrivi il nome: ");
      cin>> nome;
      printf("Scrivi il cognome: ");
      cin>> cognome;
      printf("Scrivi il numero : ");
      cin>> number;
      insertNum(nome,cognome,number);
    break;
  case '3':
      printf("\nCerca: ");
      cin>>cercando;
      cerca(cercando);
    break;
  case '4':
      printf("Che contatto vuoi cancellare? ");
      cin>>cancellando;
      cancella(cancellando);
    break;
  case '5':
      printf("\nVuoi ordinare per:\n 1.nome\n 2.cognome\n 3.numero\n");
      cin>>b;
      cout<<endl;
      sortby(b);
    break;
  default:
    printf("Errore.\n\n");
    menu();
    break;
    }
}

void printList (){
    node *select = start;
    cout<<endl;
    if (select->next == NULL){
        printf("La lista e' vuota.\n\n");
        menu();
        }
    while (select->next != NULL){
        cout<<select->nome<<" "<<select->cognome<<" "<<select->number<<endl;
        select=select->next;
         }
    cout<<endl;
    menu();
}

void insertNum(string nome, string cognome, string number){
  node *select = start;
  while (select->next != NULL){
    select=select->next;
  }
  select->nome = nome;

  select->cognome = cognome;
  select->number = number;
  select->next = new node;
  cout<<endl;
 menu();
}

void cerca(string cercando){
   node *select = start;
   int cont=0;
   cout<<endl;
    if (select->next == NULL){
    printf("La lista e' vuota. Inserire dei contatti prima di selezionare altre azioni.\n\n");
    menu();}
   while (select->next != NULL){
    bool fatto=false;
    if (select->nome == cercando && fatto == false){
    fatto=true;
    cout<<select->nome<<" "<<select->cognome<<" "<<select->number<<endl;
    cont++;}
       if (select->cognome == cercando && fatto==false){
       fatto=true;
       cout<<select->nome<<" "<<select->cognome<<" "<<select->number<<endl;
       cont++;}
           if (select->number == cercando && fatto==false){
           fatto=true;
           cout<<select->nome<<" "<<select->cognome<<" "<<select->number<<endl;
           cont++;}
    select=select->next;}
   if (cont==0){
    printf("Non ho trovato nulla.\n");}
   cout<<endl;
   menu();
}

void cancella(string dele){
        bool first= true;
        bool trovato= false;
       node *select = start;
       node *oldSelect= start;
   while (select != NULL){
    if (select->nome == dele || select->cognome == dele || select->number == dele ){
            trovato=true;
            cout<<"\nElemento cancellato.\n";
        if(first == true){
            start = start->next;
            delete select;
            break;
        }else{
            oldSelect->next=select->next;
            delete select;
            break;
        }
    }
    oldSelect=select;
    select=select->next;
    first=false;
   }
    if (trovato=false){
    cout<<"Elemento non trovato.";
    }
   cout<<endl;
   menu();
}

void swapdata(node *scorri, node *select){
    string tempn;
    string tempc;
    string tempnum;

    tempn=scorri->nome;
    scorri->nome=select->nome;
    select->nome=tempn;

        tempc=scorri->cognome;
        scorri->cognome=select->cognome;
        select->cognome=tempc;

           tempnum=scorri->number;
           scorri->number=select->number;
           select->number=tempnum;
}

void SelectionSort (char b){
    node *scorri = start;
    node *select = start;
    switch (b) {
   case '1':
           for (select; select->next != NULL; select= select->next){
             scorri=select->next;
                for (scorri; scorri->next != NULL; scorri=scorri->next){
                  if (scorri->nome < select->nome){
                    swapdata(scorri,select);
                  }
                }
            }
    menu();
       break;
   case '2':
       for (select; select->next != NULL; select= select->next){
             scorri=select->next;
                for (scorri; scorri->next != NULL; scorri=scorri->next){
                  if (scorri->cognome < select->cognome){
                    swapdata(scorri,select);
                  }
                }
            }
    menu();
       break;
   case '3':
       for (select; select->next != NULL; select= select->next){
             scorri=select->next;
                for (scorri; scorri->next != NULL; scorri=scorri->next){
                  if (scorri->number < select->number){
                    swapdata(scorri,select);
                  }
                }
            }
    menu();
       break;
   default:
       printf("\nErrore.\n");
       menu();
       break;
   }
}

void sortby(char b){
    node *head = start;
    if (head->next == NULL || head->next->next == NULL){
        printf("\nLa lista e' vuota o e' gia' ordinata perche' e' presente un solo elemento.\n\n");
        menu();
}
     SelectionSort(b);
     cout<<endl;
}

int main()
{
 printf("__________Contacts Book__________\n\n\n");
 menu();

    return 0;
}
