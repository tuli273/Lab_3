#include <iostream>
#include <fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;
string Desencriptar(string binario);
string leer(string nombre_archivo);
string encriptar(string x);
string binario(int numero);
string numeros_cadena(string texto);

int main()
{
    int opcion,contador,numero,o,aux,pos,posaux,posinicio=0,_saldo;
    string Acontrasena,contrasena,numeros,usuario,sacado,temp,p="sudo.txt";
    string enteros,cedula,texto_auxiliar,ncontrasena,saldo,ucontrasena,ucedula,contaux,cedaux;
    ofstream Guardar;
    ofstream temp_txt;
    Guardar.open("../practica_tres_aplicacion/BD/usuarios.txt",ios::app);
    temp_txt.open("../practica_tres_aplicacion/BD/temporal.txt",ios::app);
    cout<<"****** BIENBENIDO A SU CAJERO VIRTUAL ******"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*        INGRESE COMO QUIERE ENTRAR        *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"*   1.ADMINISTRADOR                        *"<<endl;
    cout<<"*   2.USUARIO                              *"<<endl;
    cout<<"*   3.SALIR                                *"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"********************************************"<<endl;
    cin>>opcion;
    system("CLS");//borra todo lo que estree en la consola
    switch (opcion) {
    case 1:
        cout<<"********************************************"<<endl;
        cout<<"*           INGRESE SU CONTRASENA          *"<<endl;
        cout<<"********************************************"<<endl;
        cin>>contrasena;

        sacado=leer(p);



        for(unsigned int i=0;i<sacado.length();i++){
            if (sacado.at(i) == ' '){
                Acontrasena+=Desencriptar(temp);
                //cout<<Acontrasena<<endl;
                temp="";
            }else{
                temp+=sacado.at(i);
            }
        }
        Acontrasena+=Desencriptar(temp);
        //cout<<Acontrasena<<endl;
        for(unsigned int i=0;i<=Acontrasena.length();i++){
            if (contador%8==0&&contador!=0){
                numero=std::stoi(enteros, nullptr, 2);
                numeros+=char(numero);
                enteros="";
            }if(i==Acontrasena.length()){
                break;
            }
            enteros+=Acontrasena.at(i);
            contador+=1;
        }
        //cout<<numeros<<endl;
        _sleep(1000);
        system("CLS");//borra todo lo que estree en la consola
        while(opcion!=2){
            if(contrasena==numeros){
                cout<<"********************************************"<<endl;
                cout<<"*             QUE QUIERE HECER             *"<<endl;
                cout<<"********************************************"<<endl;
                cout<<"*                                          *"<<endl;
                cout<<"*   1.CREAR USUARIO                        *"<<endl;
                cout<<"*   2.SALIR                                *"<<endl;
                cout<<"*                                          *"<<endl;
                cout<<"********************************************"<<endl;
                cin>>opcion;
                _sleep(1000);
                system("CLS");
                if(opcion==1){
                    cout<<"********************************************"<<endl;
                    cout<<"*      INGRESE EL NUEVO USUARIO ASI        *"<<endl;
                    cout<<"********************************************"<<endl;
                    cout<<"*                                          *"<<endl;
                    cout<<"*      <CEDULA>,<CONTRASENA>,<SALDO>       *"<<endl;
                    cout<<"*                                          *"<<endl;
                    cout<<"********************************************"<<endl;

                    cin>>usuario;
                    string enc="",binary="";
                    for (unsigned int i=0;i<usuario.length();i++){
                        if(usuario.at(i)==','){
                            binary +=numeros_cadena(enc);
                            binary +=",";
                            enc="";
                        }else{
                            enc+=usuario.at(i);
                        }
                    }
                    binary +=numeros_cadena(enc);
                    binary +=".";
                    Guardar << binary<< endl;
                    opcion=0;
                    usuario="";
                    _sleep(3500);

                    system("CLS");
                }
                system("CLS");//borra todo lo que estree en la consola
            }
            system("CLS");//borra todo lo que estree en la consola

        }
        break;
    case 2:
        cout<<"********************************************"<<endl;
        cout<<"*  INGRESE SU CEDULA Y SU CONTRASENA ASI   *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"*         <CEDULA>,<CONTRASENA>            *"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"********************************************"<<endl;
        cin>>contrasena;

        for(unsigned int i=0;i<contrasena.length();++i){

            if(contrasena.at(i)==','){
                o=1;
            }
            if (o==1 &&contrasena.at(i)!=','){
                ucontrasena+=contrasena.at(i);
            }if (o!=1 &&contrasena.at(i)!=','){
                ucedula+=contrasena.at(i);
            }
        }

        sacado=leer("usuarios.txt");
        pos =sacado.find_first_of('.');
        while(true){
            for( int i=posinicio;i<=pos+1;i++){
                if (sacado.at(i) == ' '){
                    Acontrasena+=Desencriptar(temp);
                    //cout<<Acontrasena<<endl;
                    temp="";

                }else if(sacado.at(i)==','){
                    Acontrasena+=",";
                    Acontrasena+=Desencriptar(temp);
                    //cout<<Acontrasena<<endl;
                    temp="";


                }
                else{
                    temp+=sacado.at(i);
                }

            }
            //cout<<Acontrasena<<endl;
            for(int u=0;u<=3;u++){
                contador=0;
                //Acontrasena+=Desencriptar(temp);;
                switch(u){
                case 1:
                    for(unsigned int i=0;i<=Acontrasena.length();i++){
                        if (contador%8==0&&contador!=0){
                            numero=std::stoi(enteros, nullptr, 2);
                            cedula+=char(numero);
                            enteros="";
                        }if(Acontrasena.at(i)==','){
                            break;
                        }
                        enteros+=Acontrasena.at(i);
                        contador+=1;

                    }
                    aux=contador+1;
                    contador=0;

                    //cout<<cedula<<endl;
                    break;
                case 2:
                    for(unsigned int i=aux;i<=Acontrasena.length();i++){

                        if (contador%8==0&&contador!=0){
                            numero=std::stoi(enteros, nullptr, 2);
                            ncontrasena+=char(numero);
                            enteros="";
                        }if(Acontrasena.at(i)==','){
                            break;
                        }
                        enteros+=Acontrasena.at(i);
                        contador+=1;
                    }
                    aux+=contador+1;
                    contador=0;

                    //cout<<ncontrasena<<endl;
                    break;
                case 3:
                    for(unsigned int i=aux;i<=Acontrasena.length();i++){

                        if (contador%8==0&&contador!=0){
                            numero=std::stoi(enteros, nullptr, 2);
                            saldo+=char(numero);
                            enteros="";
                        }if(Acontrasena.at(i)=='.'){
                            break;
                        }
                        enteros+=Acontrasena.at(i);
                        contador+=1;
                    }
                    //cout<<saldo<<endl;
                    break;
                }

            }
            if(ucedula==cedula&&ucontrasena==ncontrasena ){
                contaux=ncontrasena;
                cedaux=cedula;
                o=6;
                cedula="";
                ncontrasena="";
            }

            else{
                Acontrasena="";
                for(int i=posinicio;i<pos+1;i++){
                    if(sacado.at(i)==' ' && i==posinicio){

                    }else{
                    Acontrasena+=sacado.at(i);}
                }
                //            temp_txt.open("../practica_tres_aplicacion/BD/temporal.txt");
                temp_txt<<Acontrasena<<endl;
            }
            for(unsigned int i=0;i<sacado.length();i++){
                if(i>pos){
                    texto_auxiliar+=sacado.at(i);
                }

            }
            posaux=texto_auxiliar.find_first_of('.');
            if(posaux<10){
                if(o==6){
                    break;
                }else{
                    cout<<"usuario no encontrado"<<endl;
                    break;
                }

                }

                posinicio=pos+1;
                pos+=posaux+1;
                Acontrasena="",saldo="",cedula="",ncontrasena="";
                contador=0;
                texto_auxiliar="";

        }










        system("CLS");//borra todo lo que estree en la consola
        while(opcion!=3){
            if(ucontrasena==contaux && cedaux==ucedula){
                cout<<"********************************************"<<endl;
                cout<<"*             QUE QUIERE HECER             *"<<endl;
                cout<<"********************************************"<<endl;
                cout<<"*                                          *"<<endl;
                cout<<"*   1.CONSULTAR SALDO                      *"<<endl;
                cout<<"*   2.RETIRAR DINERO                       *"<<endl;
                cout<<"*   3.SALIR                                *"<<endl;
                cout<<"*                                          *"<<endl;
                cout<<"********************************************"<<endl;
                cin>>opcion;
            }else{
                opcion=0;
                cout<<"el usuario no corresponde a la contrasena"<<endl;
                system("pause");
                system("CLS");
            }
            system("CLS");//borra todo lo que estree en la consola
            if(opcion==1){
                cout<<"********************************************"<<endl;
                cout<<"*              SU SALDO ES                 *"<<endl;
                cout<<"********************************************"<<endl;
                cout<<"*                                          *"<<endl;
                cout<<"*                "<<"<"<<saldo<<">"<<"                   *"<<endl;
                cout<<"*                                          *"<<endl;
                cout<<"********************************************"<<endl;
                _saldo=atoi(saldo.c_str());
                _saldo-=1000;
                saldo =std::to_string(_saldo);
                saldo=numeros_cadena(saldo);
                cedula=numeros_cadena(cedaux);
                ncontrasena=numeros_cadena(contaux);
                temp_txt<<cedula<<","<<ncontrasena<<","<<saldo<<"."<<endl;
                temp_txt.close();
                Guardar.close();
                remove("../practica_tres_aplicacion/BD/usuarios.txt");
                rename("../practica_tres_aplicacion/BD/temporal.txt","../practica_tres_aplicacion/BD/usuarios.txt");
                _sleep(3500);
                opcion=3;
            }
            system("CLS");//borra todo lo que estree en la consola


            if(opcion==2){
                cout<<"********************************************"<<endl;
                cout<<"*          CUANTO DESEA RETIRAR            *"<<endl;
                cout<<"********************************************"<<endl;
                cin>>_saldo;
                if (_saldo>atoi(saldo.c_str())){
                    cout<<"**********************************************"<<endl;
                    cout<<"*   no puede retirar esa cantidad de dinero  *"<<endl;
                    cout<<"*   ya que no tiene suficiente en el banco   *"<<endl;
                    cout<<"**********************************************"<<endl;
                }else{
                    _saldo=atoi(saldo.c_str())-_saldo;
                    cout<<"saldo actual "<<_saldo;
                }
                _saldo=atoi(saldo.c_str());
                _saldo-=1000;
                saldo =std::to_string(_saldo);
                saldo=numeros_cadena(saldo);
                cedula=numeros_cadena(cedaux);
                ncontrasena=numeros_cadena(contaux);
                temp_txt<<cedula<<","<<ncontrasena<<","<<saldo<<"."<<endl;
                temp_txt.close();
                Guardar.close();
                remove("../practica_tres_aplicacion/BD/usuarios.txt");
                rename("../practica_tres_aplicacion/BD/temporal.txt","../practica_tres_aplicacion/BD/usuarios.txt");
                _sleep(3500);
                opcion=3;
            }
            system("CLS");//borra todo lo que estree en la consola
        }
        system("CLS");//borra todo lo que estree en la consola
        break;
    case 3:
        cout<<"********************************************"<<endl;
        cout<<"* GRACIAS POR CONTAR CON NUESTRO SERVICIO  *"<<endl;
        cout<<"********************************************"<<endl;
        _sleep(3500);
        system("CLS");//borra todo lo que estree en la consola
        break;

    }


    return 0;
}
string encriptar(string x){
    string l;
    int contador=0;
    for (unsigned int i=0;i<x.length();++i){
        if (contador==0){
            l+=x.at(x.length()-1);

        }
        if (i+1<x.length()){
            l+= x.at(i);
        }
        contador+=1;
    }


    return l;
}
string binario(int numero){
    string binario = "";
    if (numero > 0) {
        while (numero > 0) {
            if (numero%2 == 0) {
                binario = "0"+binario;
            } else {
                binario = "1"+binario;
            }
            numero = (int) numero/2;
        }
    } else if (numero == 0) {
        binario = "0";
    } else {
        binario = "No se puede realizar la conversión. Ingrese solo numeros positivos";
    }
    return binario;
}
string numeros_cadena(string texto){
    int l,contador=1;
    string p,pe,x,y;
    for (unsigned int i = 0; i < texto.length(); i++) {
        l = texto.at(i);
        p+="00";
        p +=binario(l);
        //        if(contador%n==0){
        //        p+=" ";
        //        }
        //        contador+=1;


    }

    for (unsigned int i =0;i<p.length();i++){
        x+=p.at(i);
        if (contador%4==0){
            //cout<<y<<","<<x<<endl;
            pe+=encriptar(x);
            pe+=" ";
            y=x;
            x="";
        }

        contador+=1;
    }

    return pe;

}

string Desencriptar(string binario){
    string l;
    unsigned int contador=0;
    for (unsigned int i=0;i<binario.length();++i){
        if (contador==binario.length()-1){
            l+=binario.at(0);

        }
        if (i+1<binario.length()){
            l+= binario.at(i+1);
        }
        contador+=1;
    }
    //cout<<l<<endl;
    return l;
}

string leer(string nombre_archivo){
    string data;
    string texto;
    // Abre el archivo en modo lectura
    ifstream infile;
    string direccion="../practica_tres_aplicacion/BD/";
    direccion+=nombre_archivo;
    // Se pone de manera explicita la ruta relativa donde se encuentra el archivo
    infile.open(direccion);

    // Se comprueba si el archivo fue abierto exitosamente
    if (!infile.is_open())
    {
        cout << "Error abriendo el archivo" << endl;
        exit(1);
    }
    while(!infile.eof()){
        infile>>data;
        if (texto==""){
            texto= data;
        }
        else{
            texto= texto+ " " + data;
        }
        //cout<<texto<<"-"<<endl;
    }
    //cout << "Leyendo el archivo" << endl;
    //cout<<texto<<"#"<<endl;
    //    infile >> data;

    // Se escribe el dato en la pantalla
    //cout << data << endl;
    //cout << "longitud: " << data.length() << endl;

    //cout << "Impresion caracter a caracter" << endl;
    //    for (unsigned int i = 0; i < data.length(); i++) {
    //        cout << data.at(i) << endl;
    //    }

    // Se cierra el archivo abierto
    infile.close();
    //cout << texto << endl;
    return texto;
}

