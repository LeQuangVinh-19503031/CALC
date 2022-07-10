#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int characterToNumber(int character);

int main() {
	char str[] = "25-11111";
	int number[100];
	float res[100];
	int intt = 0;
	char sign[100];
	int indexNum = 0,indexSign=0;
	int a=0;
	int i = 0;
	
	cout<<"String srouce: "<<str;
//	CHON DAU DAU TIEN
	if(isdigit(str[0])==1) {
		sign[0] = '+';
		indexSign +=1;
	}
//	TACH CHUOI
	for(i; i< strlen(str); i++) {
		if(isdigit(str[i])==0) {
			sign[indexSign] = str[i];
			indexSign += 1;
		} else {
			if(isdigit(str[i-1])==0) {
				a = 0;
				a = a*10+characterToNumber(str[i]);
			} else
				a = a*10+characterToNumber(str[i]);
			if(isdigit(str[i+1])==0) {
				number[indexNum] = a;
				indexNum += 1;
			}

		}
	}
//	DOI DAU
	for(int u = 0; u<indexSign; u++) {
		if(sign[u]=='-') {
			number[u] *= -1;
			sign[u] = '+';
		}
	}
	
	
	
//	NHAN / CHIA / CONG / TRU
	for(int i = 0; i<indexSign; i++) {

		if(sign[i]=='+') {
			if(sign[i+1]=='+') {
				res[intt] = number[i];
				intt +=1;
			}
			else if(sign[i+1]==NULL){
				res[intt] = number[i];
				intt +=1;
			}
			if(sign[i+1]=='*'||sign[i+1]=='/') {
				float s = number[i];
				i += 1;
				for(i; i<indexNum; i++) {
					if(sign[i]=='+'){
						break;
					}
					
					if(sign[i]=='*') {
						s *= number[i];
						continue;
					}
					if(sign[i]=='/'){
							s /= number[i];
						continue;
					}
				}
				res[intt] = s;
				intt++;
				i -= 1;
			}
		}
	}
//	IN KQ:
	float aa = 0;
	for(int i = 0; i<intt; i++) {
		aa += res[i];
	}
	
	cout<<"\nResult: "<<aa;
	
}// MAIN




int characterToNumber(int character) {
	if(character=='1')return 1;
	else if(character=='2')return 2;
	else if(character=='3')return 3;
	else if(character=='4')return 4;
	else if(character=='5')return 5;
	else if(character=='6')return 6;
	else if(character=='7')return 7;
	else if(character=='8')return 8;
	else if(character=='9')return 9;
	else if(character=='0')return 0;
	else return -1;
}

