#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int particionado=0;

void desenha_coracao_cima(int n){
	int meio=(n/2)/3;
	int a=meio;
	int b=meio*2;
	int c=meio*2;
	int d=meio*2;

	for(int i=meio+1;i>=1;i--){
		for(int k=a;k>=1;k--){
			cout<<" ";
		}
		for(int l=b;l>=1;l--){
			if(i==(meio+1) && (l==b || l==1 ))
				cout<<"  ";
			else
				cout<<"# ";
		}
		for(int m=c;m>=1;m--){
			cout<<" ";
		}
		for(int n=d;n>=1;n--){
			if(i==(meio+1) && (n==d || n==1 ))
				cout<<"  ";
			else
				cout<<"# ";
			if(i==1)
				particionado++;
		}
		cout<<endl;
		a--;
		b++;
		c=c-2;
		d++;
	}
}
void desenha_coracao_meio(int n){
	for(int i=1;i<(n/2)/3;i++){
		for(int k=1;k<=particionado*2;k++){
			cout<<"# ";
		}
		cout<<endl;
	}
}
void desenha_coracao_baixo(int n){
	int aux=particionado*2;
	for(int i=1;i<=particionado*2;i+=2){
		for(int m=1;m<i;m++){
			cout<<" ";
		}
		for(int k=1;k<=aux;k++){
			if((i==1 && k==1) || (i==1 && k==aux+1))
				cout<<" ";
			else
				cout<<"# ";
		}
		cout<<endl;
		aux-=2;
	}
}


void desenha_coracao(int tam){
	desenha_coracao_cima(tam);
	desenha_coracao_meio(tam);
	desenha_coracao_baixo(tam);
}


int main(){
	for(int i=15; ; i++){
		desenha_coracao(i);
		particionado=0;
		usleep(10000);
		system("clear");
		if(i>50){
			i=15;
		}
	}
	return 0;
}
