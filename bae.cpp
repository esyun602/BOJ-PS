#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
class Date{
    public:
		int year;
        int month;
        int day;
        Date(int y, int m, int d){
        	year = y;
        	month = m;
        	day = d;
		}
		void printDate(){
			printf("%d년%d월%d일", year,month,day);
		}
};

int main(){
	time_t ct;
	time(&ct);
	struct tm* t;
	t = (struct tm*)localtime(&ct);	
    char d[30], name[10];
    int stnum;
    int birth[3];
    char birthc[15];
    int age;
    cin>>d>>stnum;
    getchar();
	cin>>name>>birthc;
	name[strlen(name)-1] = d[strlen(d)-1]=0;
	birthc[4] = birthc[7] = 0;
	birth[0] = atoi(birthc);
	birth[1] = atoi(birthc+5);
	birth[2] = atoi(birthc+8);
	Date b(birth[0],birth[1],birth[2]);
	Date n(t->tm_year+1900, t->tm_mon+1, t->tm_mday);
	age = n.year-b.year;
	if(n.month<b.month || (n.month == b.month && n.day < b.day)) age--;
	cout<<d<<' '<<stnum<<' '<<name<<"님 ";
	b.printDate();
	cout<<"생 ";
	n.printDate();
	cout<<" 현재 "<<age<<"세입니다.";
}
