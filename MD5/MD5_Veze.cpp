//Sandija Veze, P23
#include <iostream>
#include <bits/stdc++.h> // Hedere, lai abstradatu iznemumus.
#include <stdlib.h> //Hedere abs izmantoanai
using namespace std;

class Date{
protected:
    int diena, menesis, gads;
   // int diena2, menesis2, gads2;

public:
    //noklusejuma konstruktors
    Date(){
        diena = 30; menesis = 1; gads = 2020;
    }

    //konstruktors ar parametriem
    Date(int a, int b, int c){
        diena=a; menesis=b, gads=c;
    }


    void setDate(int d, int m, int g){
        diena=d; menesis=m, gads=g;
    }



void getDate (){



   if (diena > 30 || diena <=0 || menesis > 12 || menesis <= 0 || gads <= 0){
   throw Date();
}

        //cout << "Sodienas datums: " << endl;

        if (diena < 10){
            cout << "0" << diena << ".";

        }else
            cout << diena << ".";

        if (menesis < 10) {
            cout << "0" << menesis << ".";
        }else
            cout << menesis << ".";
            cout << gads << '\n' << endl;

    }


    void dateUpdate();

    int dienuStarpiba(Date d1, Date d2);

};

void Date::dateUpdate(){

    if (diena==30) {
        if(menesis==12){
            diena=1;
            menesis=1;
            gads++;

        }else{  // ja menesis ir cits, nevis 12.
            diena=1;
            menesis++;

        } // Ja diena ir cita, nevis 30.
    } else {
        diena++;

    }

    	cout << "Ritdienas datums:\n";
	if (diena < 10){
		cout << "0" << diena << ".";
	} else
		cout << diena << ".";
	if (menesis < 10) {
		cout << "0" << menesis << ".";
	} else
		cout << menesis << ".";
        cout << gads << '\n' << endl;


}

// Funkcija, lai noteiktu dienu skaitu starp abiem ievaditajiem datumiem.
int Date::dienuStarpiba(Date d1, Date d2){

    int dienuSkaits;

    // Tiek aprekinats kopejais dienu skaits, gads un menesis ari tiek parkonvertets dienas.
    int dienuSkaits1= ((d1.gads*12*30) + (d1.menesis*30) + d1.diena);
    int dienuSkaits2 = ((d2.gads*12*30) + (d2.menesis*30) + d2.diena);


        // Tiek aprekinata abu dienu skaita starpiba.
        dienuSkaits = ((d2.gads*12*30) + (d2.menesis*30) + d2.diena) - ((d1.gads*12*30) + (d1.menesis*30) + d1.diena);

    cout << "Dienu skaits starp abiem datumiem: " << abs(dienuSkaits) << '\n'<< endl;

}


class Time : public Date{
    int stundas, minutes;
public:
    Time(){
        stundas = 3; minutes=23;
    }

    //konstruktors ar parametriem
    Time(int s, int mi){
        stundas=s; minutes=mi;
    }

    void setTime(int s, int mi){
        stundas=s; minutes=mi;
    }

    //metode laika izvadisanai uz ekrana
    void getTime(){

        if (stundas < 0 || stundas > 23 || minutes < 0 || minutes > 59)
        throw Time();

        cout << "Ievaditais laiks " << endl;
        	if (stundas<10){	//Parbauda, vai pirms stundas vajadzetu ievietot nulli.
		cout << "0" << stundas << ":";
	}else
		cout << stundas << ":";

	if (minutes<10){	//Parbauda, vai pirms minutem vajag ievietot nulli.
		cout << "0" << minutes << '\n' << endl;
	}else
		cout << minutes << '\n' << endl;
    }


    void timeUpdate();

    void dateAndTime(Time t1, Date d1);

};

//Funkcija laika noteiksanai pec 1 min

void Time::timeUpdate(){

    if (minutes==59) {

    if (stundas==23){ // Ja ievaditais laiks ir 23 stundas un 59 minutes.
        stundas=0;
        minutes=0;

    } else { // Ja stunda ir cita, nevis 23.
        stundas++;
        minutes=0;
        }

    } else {
    minutes++;

}

        cout << "Laiks pec 1 minutes:\n";

	if (stundas<10){	//Parbauda, vai pirms stundas vajadzetu ievietot nulli.
		cout << "0" << stundas << ":";
	}else
		cout << stundas << ":";

	if (minutes<10){	//Parbauda, vai pirms minutem vajag ievietot nulli.
		cout << "0" << minutes << '\n' << endl;
	}else
		cout << minutes << '\n' << endl;

}

//Funkcija laika un datuma noteiksanai pec 1 min.
void Time::dateAndTime(Time t1, Date d1){


    if (stundas < 0 || stundas > 23 || minutes < 0 || minutes > 59 ||
        diena > 30 || diena <=0 || menesis > 12 || menesis <= 0 || gads <= 0){

            throw Time();
        }
       if (minutes==0)

            if (stundas==0){

                if (diena==30){

                    if (menesis==12){
                        gads++;
                        menesis=1;
                        diena=1;
                        stundas=0;
                        minutes=0;

        } else { // ja menesis nav 12
            diena=1;
            menesis++;
            }

        } else { // ja diena nav 30
            diena++;

    }

}

  	cout << "Laiks un datums pec 1 minutes:\n";
	if (diena < 10){
		cout << "0" << diena << ".";
	} else
		cout << diena << ".";
	if (menesis < 10) {
		cout << "0" << menesis << ".";
	} else
		cout << menesis << ".";
        cout << gads << " ";

    	if (stundas<10){	//Parbauda, vai pirms stundas vajadzetu ievietot nulli.
		cout << "0" << stundas << ":";
	}else
		cout << stundas << ":";

	if (minutes<10){	//Parbauda, vai pirms minutem vajag ievietot nulli.
		cout << "0" << minutes << endl;;
	}else
		cout << minutes << endl;


}



int main() {

     Date dat1;

    // try and catch, lai programma izvaditu kludas pazinojumu, ja ievadits nekorekts datums.
    try{


    cout << "Sodienas datums:\n";
    dat1.getDate();
    dat1.dateUpdate();

    Date dat2(4, 12, 2019);
    cout << "Cits datums:\n";
    dat2.getDate();

    dat2.dienuStarpiba(dat1, dat2);

    } catch (Date &e){
        cout << "Ievadits kludains datums.\n" << endl;

}

    Time t(23,59);

    // try and catch, lai programma izvaditu kludas pazinojumu, ja ievadits nekorekts laiks.
    try{

    t.getTime();
    t.timeUpdate();

    } catch (Time &e){
        cout << "Ievadits kludains laiks. \n" << endl;

}

    try{
    t.dateAndTime(t, dat1);

    } catch (Time &e) {
        cout << "Ievadits kludains laiks vai datums. \n" << endl;
}

    return 0;

}
