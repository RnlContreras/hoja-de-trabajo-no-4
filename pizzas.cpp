#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct ventas{
	int tipoprod;
	float descuento;
	float precio;
	int unidades;
	float totalvta;
};
void venta();
void reporte();
int main(){
	venta();
	reporte();
}
	
void venta(){
	int tipoprod;
	float precio;
	int unidades;
	float descuento;
	float totalvta;
	string s;
	
	cout<<"*********************"<<endl;
	cout<<"*PIZZAS BONIFACIA SA*"<<endl;
	cout<<"*********************"<<endl;
	
	cout<<" Que tipo de pizza desea: "<<endl;
	cout<<" Pizza Grande    (Q80.00) = 1  - Descuento 10%"<<endl;
	cout<<" Pizza Familiar (Q115.00) = 2  - Descuento 15%"<<endl;
	cout<<" Pizza Fiesta   (Q100.00) = 3  - Descuento 20%"<<endl;
	cin>>tipoprod;
	cout<<"Total unidades a comprar: "<<endl;
	cin>>unidades;	
	if (tipoprod ==1){
		descuento = 0.10;
		precio = 80.00;
		totalvta = (precio - (descuento * precio) )* unidades; 	
	}
	else if (tipoprod ==2){
		descuento = 0.20;
		precio = 100.00;
		totalvta = (precio - (descuento * precio) )* unidades; 	
	} else if (tipoprod ==3){
		descuento = 0.10;
		precio = 100.00;
		totalvta = (precio - (descuento * precio) )* unidades; 
	}
	cout<<"Tipo Prod: "<<tipoprod<<"Descuento: "<<descuento<<"Precio: "<<precio<<"Unidades: "<<unidades<<"Total de la venta: "<<totalvta;
	ofstream grabararchivo;
	try {
		grabararchivo.open("pizza.txt",ios::app);
		grabararchivo<<tipoprod<<"\t"<<descuento<<"\t"<<precio<<"\t"<<unidades<<"\t"<<totalvta<<endl;
		grabararchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
	cout<<"\n"<<"Ventas Actuales"<<endl;
	cout<<"Tipo Prod  Descuento  Precio  Unidades  TotalVenta"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("pizza.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
}

void reporte(){

	ifstream db;
	float tp,d,p,u,tv=0;
	float sumatotal=0;
	float tp1=0;
	float tp2=0;
	float tp3=0;	
	try{	
		db.open("pizza.txt",ios::in);
		
		while (db >>tp >> d >>p>> u>>tv){
			sumatotal = tv + sumatotal;	
			if (tp==1)
				tp1+=tv;
			else if (tp==2)
				tp2+=tv;
			else if (tp==3)
				tp3+=tv;
		}	
		db.close();
		
		cout<<setprecision(5)<<"Total de Ventas:          "<<sumatotal<<endl;
		cout<<"Desgloce por producto:  "<<endl;
		cout<<setprecision(5)<<" Pizza Grande   "<<tp1<<" - % sobre el total: "<<setprecision(3)<<tp1*100/sumatotal<<endl;
		cout<<setprecision(5)<<" Pizza Familiar "<<tp2<<" - % sobre el total: "<<setprecision(3)<<tp2*100/sumatotal<<endl;
		cout<<setprecision(5)<<" Pizza Fiesta   "<<tp3<<" - % sobre el total: "<<setprecision(3)<<tp3*100/sumatotal<<endl;
		
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
	}		
	
	
}

