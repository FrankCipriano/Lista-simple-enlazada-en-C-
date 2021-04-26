#include <stdlib.h>
#include <iostream>
using namespace std;

struct nodo{
    string pnombren;
    string snombren;
    string papellidon;
    string sapellidon;
    int carnetn,n1n,n2n,n3n;
    struct nodo *sgte;
};

typedef struct nodo *Tlista;


void insertaInicio(Tlista &lista, string pnombre,string snombre,string papellido,string sapellido,int carnet,int n1,int n2,int n3){
    Tlista q;
    q = new(struct nodo);
    q->pnombren = pnombre;
    q->snombren = snombre;
    q->papellidon = papellido;
    q->sapellidon = sapellido;
    q->carnetn = carnet;
    q->n1n = n1;
    q->n2n = n2;
    q->n3n = n3;
    q->sgte = lista;
    lista = q;
}
void insertarFinal(Tlista &lista, string pnombre,string snombre,string papellido, string sapellido,int carnet,int n1, int n2, int n3){
    Tlista t, q = new(struct nodo);
    q->pnombren = pnombre;
    q->snombren = snombre;
    q->papellidon = papellido;
    q->sapellidon = sapellido;
    q->carnetn = carnet;
    q->n1n = n1;
    q->n2n = n2;
    q->n3n = n3;
    q->sgte = NULL;

    if(lista==NULL){
        lista = q;
    }else{
        t = lista;
        while(t->sgte!=NULL){
            t = t->sgte;
        }
        t->sgte = q;
    }
}
int insertarAntesDespues(){
    int _op,band;
    cout<<endl;
    cout<<"1. Antes de la posicion\n";
    cout<<"2. Despues de la posicion\n";
    cout<<"Elija.!!"; cin>>_op;

    if(_op==1){
        band = -1;
    }else{
        band = 0;
    }
    return band;
}
void insertarElemento(Tlista &lista, int pos,string pnombre,string snombre,string papellido,string sapellido,int carnet,int n1,int n2,int n3){
    Tlista q,t;
    int i;
    q = new(struct nodo);
    q->pnombren = pnombre;
    q->snombren = snombre;
    q->papellidon = papellido;
    q->sapellidon = sapellido;
    q->carnetn = carnet;
    q->n1n = n1;
    q->n2n = n2;
    q->n3n = n3;

    if(pos==1){
        q->sgte = lista;
        lista = q;
    }else{
        int x = insertarAntesDespues();
        t = lista;

        for(i=1;t!=NULL;i++){
            if(i==pos+x){
                q->sgte = t->sgte;
                t->sgte = q;
                return;
            }
            t = t->sgte;
        }
    }
    cout<<"Posicion no encontrada\n";
}
void buscarElemento(Tlista lista,string pnombre,string snombre,string papellido,string sapellido,int carnet,int n1, int n2,int n3){
    Tlista q = lista;
    int i=1;
    int band=0;

    while(q!=NULL){
        if(q->pnombren==pnombre){
            cout<<"\nEncontrada en la posicion"<<i<<endl;
            band=1;
        }
        q=q->sgte;
        i++;
    }
    if(band==0){
        cout<<"\nNumero no encontrado!"<<endl;
    }
}
void reportarLista(Tlista lista){
    int i=0;
    while(lista!=NULL){
        cout<<' '<<i+1<<")"<<endl;
        cout<<lista->pnombren<<endl;
        cout<<lista->snombren<<endl;
        cout<<lista->papellidon<<endl;
        cout<<lista->sapellidon<<endl;
        cout<<lista->carnetn<<endl;
        cout<<lista->n1n<<endl;
        cout<<lista->n2n<<endl;
        cout<<lista->n3n<<endl;
        lista = lista->sgte;
        i++;
    }
}
void eliminarElemento(Tlista &lista,string pnombre,string snombre,string papellido,string sapellido,int carnet,int n1,int n2,int n3){
    Tlista p,ant;
    p=lista;
    if(lista!=NULL){
        while(p!=NULL){
            if(p->pnombren==pnombre){
                if(p==lista){
                    lista=lista->sgte;
                }else{
                    ant->sgte=p->sgte;
                }
                delete(p);
                return;
            }
            ant=p;
            p=p->sgte;
        }
    }else{
            cout<<"Lista vacia!";
        }
}
void eliminarRepetidos(Tlista &lista,string pnombre,string snombre,string papellido,string sapellido,int carnet,int n1,int n2,int n3){
    Tlista q,ant;
    q=lista;
    ant=lista;
    while(q!=NULL){
        if(q->pnombren==pnombre){
            if(q==lista){
                lista=lista->sgte;
                delete(q);
                q=lista;
            }else{
                ant->sgte=q->sgte;
                delete(q);
                q=ant->sgte;
            }
        }else{
            ant=q;
            q=q->sgte;
        }
    }
    cout<<"\nValores eliminados!";
}
void menu(){
    cout<<"LISTAS ENLAZADAS SIMPLES\n\n";
    cout<<"1. INSERTAR AL INICIO\n";
    cout<<"2. INSERTAR AL FINAL\n";
    cout<<"3. INSERTAR EN UNA POSICION\n";
    cout<<"4. REPORTAR LISTA\n";
    cout<<"5. BUSCAR ELEMENTO\n";
    cout<<"6. ELIMINAR ELEMENTO\n";
    cout<<"7. ELIMINAR ELEMENTOS CON VALOR\n";
    cout<<"8. SALIR\n";
    cout<<"INGRESE UNA OPCION\n";
}
int main(){
    Tlista lista = NULL;
    int op;
    string pnombre;
    string snombre;
    string papellido;
    string sapellido;
    int carnet,n1,n2,n3;
    int pos;
    do{
        menu();
        cin>>op;
        switch(op){
            case 1:cout<<"\nDatos a insertar:\n";
                    cin>>pnombre;cin>>snombre;cin>>papellido;cin>>sapellido;cin>>carnet;cin>>n1;cin>>n2;cin>>n3;
                    insertaInicio(lista,pnombre,snombre,papellido,sapellido,carnet,n1,n2,n3);
                    break;
            case 2:cout<<"\nDatos a insertar:\n";
                    cin>>pnombre;cin>>snombre;cin>>papellido;cin>>sapellido;cin>>carnet;cin>>n1;cin>>n2;cin>>n3;
                    insertarFinal(lista,pnombre,snombre,papellido,sapellido,carnet,n1,n2,n3);
                    break;
            case 3:cout<<"\nDatos a inserta:\n";
                     cin>>pnombre;cin>>snombre;cin>>papellido;cin>>sapellido;cin>>carnet;cin>>n1;cin>>n2;cin>>n3;
                     cout<<"Posicion: ";cin>>pos;
                     insertarElemento(lista,pos,pnombre,snombre,papellido,sapellido,carnet,n1,n2,n3);
                     break;
            case 4:cout<<"\nMostrar Lista\n";
                    reportarLista(lista);
                    break;
            case 5:cout<<"\nDato a buscar";
                    cin>>pnombre;
                    buscarElemento(lista,pnombre,snombre,papellido,sapellido,carnet,n1,n2,n3);
                    break;
            case 6:cout<<"\nDato a eliminar";cin>>pnombre;
                    eliminarElemento(lista,pnombre,snombre,papellido,sapellido,carnet,n1,n2,n3);
                    break;
            case 7:cout<<"\nDato repetido a eliminar";cin>>pnombre;
                    eliminarRepetidos(lista,pnombre,snombre,papellido,sapellido,carnet,n1,n2,n3);
                    break;
        }
        cout<<endl<<endl;
        system("pause");system("cls");
    }while(op!=8);
    system("pause");
    return 0;
}