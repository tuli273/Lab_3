/*
#include <iostream>
#include<fstream>
#include<math.h>
using namespace std;

///Variables globales
fstream archivo_lectura,archivo_escritura;
int semilla;

///Prototipos de funciones
void convertir_binario(int a, int b[]);
int contador_0s_1s(string a);

string igual_cantidad_0s_1s(string a, string b);
string mayor_cantidad1s(string a,string b);
string mayor_cantidad0s(string a, string b);

void metodo_codificacion1();
void metodo_codificacion2();



///Cuerpo de la funcion
int main()
{
    cout<<"                     BIENVENIDO AL CODIFICADOR"<<endl;
    int i=0,binario[8],n,opcion;
    string texto,nombre;

    cout<<"Ingrese el nombre del archivo que desea abrir:  ";cin>>nombre;
    archivo_lectura.open(nombre+".txt",ios::in);

    if(archivo_lectura.is_open()){
        cout<<" ->El archivo '"<<nombre<<".txt' ha sido cargado correctamente."<<endl<<endl;
        while (!(archivo_lectura.eof())) {
           texto[i]=archivo_lectura.get();
           i++;
        }
        n=--i;
        cout<<"El contenido del archivo es: '";
        for(int i=0;i<n-1;i++){
            cout<<texto[i];
        }cout<<"'"<<endl<<endl;

        archivo_lectura.close();
        archivo_escritura.open("archivo_binario.txt",ios::out);
        for(int j=0; j<n-1;j++){
            convertir_binario((int)texto[j],binario);
            for(int i=0;i<8;i++){
                archivo_escritura<<binario[i];
            }
        }
        archivo_escritura.close();
        do{cout<<"                          OPCIONES"<<endl<<"1. Metodo de codificacion 1"<<endl<<"2. Metodo de codificacion 2"<<endl
             <<"0. Para finalizar."<<endl<<endl;
            cout<<"Ingrese la opcion deseada: ";cin>>opcion;
            switch (opcion) {
            case 0:
                break;
            case 1:
                system("clear");
                cout<<"->Codificacion 1 seleccionada."<<endl;
                metodo_codificacion1();
                break;
            case 2:
                system("clear");
                cout<<"->Codificacion 2 seleccionada."<<endl;
                metodo_codificacion2();
                break;

            default:
                cout<<"Ingrese una opcion valida."<<endl;
                break;
            }

        }while(opcion);

    }
    else{
        cout<<" ->Lo siento, hubo un error al cargar archivo '"<<nombre<<"'"<<endl;
    }
    return 0;
}

///Cuerpo de las funciones

void convertir_binario(int a, int b[]){  //listo
    int i=0;
    int binario[8]={0,0,0,0,0,0,0,0};
    while(a!=1){
        binario[i]=a%2;
        a=a/2;
        i++;
    }
    binario[i]=a;               // a siempre va a ser igual a 1
    for(int j=7,i=0;j>=0;j--,i++){
        b[i]=binario[j];

    }

}
int contador_0s_1s(string a){ //listo
    int tam,cont1=0,cont0=0;
    tam=a.length();
    for(int i=0;i<tam;i++){
        if(a[i]=='1'){
            cont1++;
        }
        else if(a[i]=='0'){
            cont0++;
        }
    }
    if(cont1>cont0){
        return 1;
    }
    else if(cont0>cont1){
        return 0;
    }
    else {
        return 4;
    }
}

string igual_cantidad_0s_1s(string a, string b){ //listo
    int tam=0;
    tam=a.length();
    for(int i=0;i<tam;i++){
        if(a[i]=='1'){b[i]='0';}
        else if(a[i]=='0'){b[i]='1';}

    }
    return b;
}

string mayor_cantidad1s(string a, string b){ //listo
    int tam=0;
    tam=a.length();
    for(int i=2;i<tam;i+=2){
        if(a[i]=='0'){b[i]='1';}
        else{b[i]='0';}
    }

    return b;
}

string mayor_cantidad0s(string a, string b){ //listo
    int tam=0;
    tam=a.length();
    for(int i=1;i<tam;i+=2){
        if(a[i]=='0'){b[i]='1';}
        else{b[i]='0';}
    }
    return b;


}

string implementar_metodo2(string a, string b){ //listo
    int tam;
    tam=a.length();
    for (int i=0,j=0; i<tam; i++){
        if(i==0){
            b[i]=a[tam-1];
        }
        else{
            b[i]=a[j];
            j++;
        }
    }
    return b;
}



void metodo_codificacion1(){



    string cadena,bin_modificado,bloque1,bloque2,nombre;

    int n;
    cout<<"Ingrese un nombre para el archivo codificado: ";cin>>nombre;
    cout<<"Ingrese el valor de la semilla: ";cin>> semilla;

    archivo_lectura.open("archivo_binario.txt",ios::in);
    if(archivo_lectura.is_open()){
        while (!(archivo_lectura.eof())) {
            archivo_lectura>>cadena;
        }

        archivo_escritura.open(nombre+".txt",ios::out);

        n=cadena.length();
        bloque1=cadena.substr(0,semilla);
        bin_modificado=igual_cantidad_0s_1s(bloque1,bloque1);
        archivo_escritura<<bin_modificado;

        for(int i=0;i<n;i+=semilla){
            if(contador_0s_1s(bloque1)==1){
                bloque2=cadena.substr((i+semilla),semilla);
                bin_modificado=mayor_cantidad1s(bloque2,bloque2);
                archivo_escritura<<bin_modificado;
                bloque1=bloque2;
            }
            else if(contador_0s_1s(bloque1)==0){
                bloque2=cadena.substr((i+semilla),semilla);
                bin_modificado=mayor_cantidad0s(bloque2,bloque2);
                archivo_escritura<<bin_modificado;
                bloque1=bloque2;
            }
            else if(contador_0s_1s(bloque1)==4){
                bloque2=cadena.substr((i+semilla),semilla);
                bin_modificado=igual_cantidad_0s_1s(bloque2,bloque2);
                archivo_escritura<<bin_modificado;
                bloque1=bloque2;
            }

         }
        cout<<" ->El archivo '"<<nombre<<".txt' ha sido codificado correctamente."<<endl<<endl;
    }
    else{
        cout<<"Lo siento,el archivo '"<<nombre<<"' no se pudo codificar."<<endl;
    }
    archivo_escritura.close();
    archivo_lectura.close();
}

void metodo_codificacion2(){ //listo

    string cadena,bin_modificado,bloque1,nombre;

    int tam;
    cout<<"Ingrese el nombre para el archivo codificado: ";cin>>nombre;
    cout<<"Ingrese el valor de la semilla: ";cin>>semilla;

    archivo_lectura.open("archivo_binario.txt",ios::in);
    if(archivo_lectura.is_open()){
        while(!(archivo_lectura.eof())){
            archivo_lectura>>cadena;
        }
        archivo_escritura.open(nombre+".txt",ios::out);
        tam=cadena.length();

        for(int i=0;i<tam;i+=semilla){
            bloque1=cadena.substr(i,semilla);
            bin_modificado=implementar_metodo2(bloque1,bloque1);
            archivo_escritura<<bin_modificado;
        }
    }
    else{
        cout<<"Lo siento,el archivo '"<<nombre<<"' no se pudo codificar."<<endl;
    }
    archivo_escritura.close();
    archivo_lectura.close();
}

*/
