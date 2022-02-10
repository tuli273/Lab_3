/*
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
void convertir (int numero,string &numeroS, string aux);
string palabras (string binario);

int main()
{


    // VARIABLES PARA CODIFICAR POR EL PRIMER METODO
    //-------------------------------
    int k=0;
    int j=0;
    bool ban;
    int a=0;
    int uno=0;
    int cero=0;
    int longitud1;
    string copia;
    //-------------------------------

    //VARIABLES PARA CODIFICAR POR EL SEGUNDO METODO
    //-------------------------------

    int seed;
    int inicio=0;
    int longitud2;
    string copia2;

    //-------------------------------
    //VARIABLES PARA DECODIFICAR POR MÉTODO 1
    string stri="";
    int met;
    int finn;
    int q=0;
    int l=0;
    bool bandera;
    int b=0;
    int semillaa;
    int u=0;
    int c=0;
    int longi;
    //-------------------------------
    //VARIABLES PARA DECODIFICAR POR METODO 2
    int semilla0;
    int seed0;
    int inicio0=0;
    int longitud0;
    string str0=" ";
    string copia0;


    //-----------------------------
    int cantidad;
    //
    string binario="";
    int longitud;
    string aux;
    string imprimir;
    //imprimir dos es para guardar el numero con un cero adelante
    string imprimir2;
    string numeroS="";
    int conv;
    int metodo;
    int semilla;
    ifstream fileread;
    ofstream filewrite;
    char cadena1[15];
    cout<<"Ingrese una palabra: "<<endl;

    cin.getline(cadena1,15);
    try {
        filewrite.open("archivo.txt" );
        if (!filewrite.is_open())
            throw"1";
        filewrite<<cadena1;
        filewrite.close();
        fileread.open("archivo.txt");
        if (!fileread.is_open())
            throw"2";
    // leer archivo caracter por caracter
    fileread.seekg(0);
    int i=0;
    //leyendo el archivo
    while (fileread.good())
    {
        char temp= fileread.get();
        //sacando caracter por caracter
        if (fileread.good())
        {
            cadena1[i]=temp;
            //convertir el char a entero para poder convertirlo a binario
            conv=temp; // conv esta definido como entero, valor ascii


           //convertiendo a binario

            convertir (conv,numeroS,aux);
            longitud=numeroS.size();

            if (longitud<8)
            {   cantidad=8-longitud;
                for (int w=0;w<cantidad;w++)
                {
                binario+='0';

                }
                binario+=numeroS;
            }

            else{
            binario+=numeroS;
            }
            numeroS="";


        i++;
        }
    }
    cout<<"La palabra o frase en binario: "<<binario<<endl;




    }

//para saber si el archivo tiene un error en lectura o escritura
    catch (char c)
    {
      if (c==1)
      cout<<"Error al abrir el archivo de escritura"<<endl;
      if (c==2)
      cout<<"Error al abrir el archivo de lectura"<<endl;
    }
    fileread.close();

    cout<<endl;
    cout<<"Escriba un numero entero para la semilla de codificacion "<<endl;
    cout<<endl;
    cin>>semilla;
    finn=semilla;
    cout<<endl;
    cout<<"Escriba un numero entero para el metodo de codificacion (1) (2)"<<endl;
    cout<<endl;
    cin>>metodo;
    filewrite.open("codificado.txt" );


    //METODO 1

    if (metodo==1)
    {
        copia=binario;
        if (semilla%2==0)
                {
                    ban=true;
                }
                else
                {
                    ban=false;
                }
                longitud1=binario.size();
                //cambiar el primer bloque , los 1 por ceros
                //primer bloque de n bits
                for (int j=0;j<semilla;j++)
                {
                    if (binario[j]==49)
                    {


                        binario[j]=48;

                    }
                    else
                    {
                        binario[j]=49;
                    }
                }


                //para los grupos siguientes


            //----------------------------------------------------------------------------

            while (semilla<=longitud1)
            {
            //{
                //este for revisa el bloque anterior
                for (int i=a;i<(semilla+semilla)/2;i++)
                {
                    if (copia[i]==48)
                    {
                    cero+=+1;
                    }
                    else
                    {
                      uno+=1;
                    }

                }

                //esta parte revisa cada bloque
                if (uno==cero)
                {    for (int j=semilla;j<semilla+4;j++)
                    {

                        if (binario[j]==49)
                        {
                            binario[j]=48;


                        }
                        else
                        {
                            binario[j]=49;

                        }

                    }
                }


                    if (cero>uno)
                    {

                        j=semilla+1;
                        if (ban==true)
                        {



                            while  (j<=semilla+4 and j<=longitud1)
                            {



                                if (j%2==0)
                                {
                                    if (copia[j-1]==48)
                                    {

                                        binario[j-1]=49;

                                    }
                                    else
                                    {
                                        binario[j-1]=48;

                                    }


                                }
                           j=j+1;

                            }
                        }


                    }
                        if (uno>cero)
                        {   k=semilla+2;
                            while (k<semilla+4)
                            {
                                if (copia[k]==48)
                                {

                                    binario[k]=49;

                                }
                                else
                                {
                                    binario[k]=48;

                                }
                                k=k+2;
                            }
                        }




            a=a+finn;
            cero=0;
            uno=0;
            semilla=semilla+finn;

            }

        filewrite<<binario;
        cout<<endl;
        cout<<"LA FRASE CON EL METODO 1 ES : "<<binario<<endl;
        cout<<endl;
    }

    //METODO 2
    else if (metodo==2)
    {

        copia2=binario;
       longitud2=binario.size();
        seed=semilla;
        while (semilla<=longitud2)
            {
                for (int i=inicio;i<semilla;i++)
                {
                    if (i==inicio)
                    {
                        binario [i]=copia2 [semilla-1];
                    }
                    else
                    {
                    binario[i]=copia2[i-1];
                    }
                }

            inicio=semilla;
            semilla=semilla+seed;

            }



        filewrite<<binario;
        cout<<endl;
        cout<<"LA FRASE CON EL METODO 2 ES : "<<binario<<endl;
        cout<<endl;
    }

    else{
    cout<<"El numero ingresado es erroneo"<<endl;
    exit(EXIT_FAILURE);
    }


cout<<endl;
filewrite.close();
fileread.open("codificado.txt");
fileread.seekg(0);

//leyendo el archivo

while (fileread.good())
{
    char temp= fileread.get();
    //sacando caracter por caracter
    if (fileread.good())
    {
        stri.push_back(temp);
    }

}

cout<<endl;
cout<<"DECODIFICACION"<<endl;
cout<<endl;
cout<<"Ingrese la semilla para decodificar el archivo: "<<endl;
cin>>semillaa;
cout<<endl;
int final=semillaa;
cout<<endl;
cout<<"Ingrese el metodo para decodificar el archivo: (1)(2): "<<endl;
cin>>met;
cout<<endl;
//MÉTODO 1 DE DECODIFICACION
if (met==1)
{
    finn=semillaa+semillaa;

    if (semillaa%2==0)
    {
        bandera=true;
    }
    else
    {
        bandera=false;
    }
    longi=stri.size();

    for (int j=0;j<semillaa;j++)
    {

        if (stri[j]==49)
        {

            stri[j]=48;

        }
        else
        {
            stri[j]=49;
        }
    }

while (semillaa<=longi)
{

    for (int i=b;i<(semillaa+semillaa)/2;i++)
    {
        if (stri[i]==48)
        {
        c+=+1;
        }
        else
        {
          u+=1;
        }

    }
    if (u==c)
    {    for (int j=semillaa;j<semillaa+4;j++)
        {

            if (stri[j]==49)
            {
                stri[j]=48;


            }
            else
            {
                stri[j]=49;

            }

        }
    }
        if (c>u)
        {

            l=semillaa+1;
            if (bandera==true)
            {



                while  (l<=semillaa+4 and l<=longi)
                {
                    if (l%2==0)
                    {
                        if (stri[l-1]==48)
                        {

                            stri[l-1]=49;

                        }
                        else
                        {
                            stri[l-1]=48;

                        }
                    }
               l=l+1;

                }
            }


        }
            if (u>c)
            {   q=semillaa+2;
                while (q<semillaa+4)
                {
                    if (stri[q]==48)
                    {

                        stri[q]=49;

                    }
                    else
                    {
                        stri[q]=48;

                    }
                    q=q+2;
                }
            }

b=b+final;
c=0;
u=0;
semillaa=semillaa+final;

}
cout<<"LA DECODIFICACION DEL METODO 1 ES:  "<<stri<<endl;
string pall;
for (int k=0;stri[k]!='\0';k++)
{
    pall+=stri[k];
}
string h;
h=palabras ( pall);
cout<<"LA DECODIFICACION COMPLETA ES: "<<h<<endl;
}

if (met==2)
{
        str0=stri;
        copia0=str0;
        longitud0=str0.size();
        semilla0=semillaa;
        seed0=semilla0;
        while (semilla0<=longitud0)
            {
                for (int i=inicio0;i<semilla0;i++)
                {
                    if (i==semilla0-1)
                    {
                        str0 [semilla0-1]=copia0 [inicio0];

                    }
                    else
                    {
                    str0[i]=copia0[i+1];
                    }
                }

            inicio0=semilla0;
            semilla0=semilla0+seed0;
            }


cout<<"LA DECODIFICACION POR EL METODO 2 ES: "<<str0<<endl;
string pal;
for (int k=0;str0[k]!='\0';k++)
{
    pal+=str0[k];
}
string t;
t=palabras ( pal);
cout<<"LA DECODIFICACION COMPLETA ES: "<<t<<endl;
}

}

//funcion de convertir en binario

void convertir (int numero,string &numeroS, string aux)
{
    while (numero>0)
    {
        if (numero%2==0)
        {
            numeroS=numeroS+"0";
        }
        else
        {
            numeroS=numeroS+"1";
        }
        numero=numero/2;
    }
    for (int i=numeroS.length()-1;i>=0;i--)
    {
        aux=aux+numeroS.at(i);
    }
    numeroS=aux;
}


//CONVERTIR BINARIO A NUMERO


    string palabras (string original)
    {
        char letra;
        int longitud=original.size();
        string str;
        int digito2;
        int posicion=0;
        int resultado=0;
        string palabra;
        int contador=0;
        int vector []={1,2,4,8,16,32,64,128,256};
            while (contador<longitud)
            {
                for (int j=0;j<=7;j++)
                {
                    str[j]=original[contador];

                    contador=contador+1;

                }

            for (int i=8-1;i>=0;i--)
            {
                digito2=str[i];

                if (digito2==49)
                {
                    resultado=resultado+vector[posicion];

                }
                posicion++;


            }


            letra=resultado;
            posicion=0;
            palabra+=letra;

            resultado=0;


            }
            return palabra;
    }

*/
