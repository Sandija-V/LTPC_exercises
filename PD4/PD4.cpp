#include <iostream>
#include <fstream>//Hedere, lai varetu izmantot ifstream un ofstream, kas nepieciesamas failu nolasisanai
//un informacijas ierakstisanai faila.
#include <string> //Hedere, lai izmantotu string.

//Funkcija, kas string parvers par integer tipa masivu.
//Klat vel visam ari ieraksta masivu faila apgriezta seciba un izrekina masiva elementu summu.
void convertStrtoArr(std::string str){

    //Tiek noteikts string izmers.
    int str_length = str.length();

    //Tiek deklarets integer tipa masivs, kura glabasies integer tipa vertibas, kas nemtas no string.
    int masivs[str_length]={};

    //Tiek noteikts masiva izmers.
    int masivaIzmers = sizeof(masivs)/sizeof(masivs[0]);

    int j = 0, i, summa = 0;

    //For cikls iteres lidz string pasam beigam.
    for (i = 0; str[i] != '\0'; i++) {

        //Ja string elements bus komats, programma turpinas savu darbibu, parlecot uz nakamo iteraciju.
        if (str[i] == ',')
            continue;

        //Ja iteracijas laika programma saskarsies ar atstarpi, tad j tiks palielinats.
        //Tas liks programmai saprast, kur sakas un beidzas integer masiva elementi.
        if (str[i] == ' '){
            j++;
        }else {
            // String elements tiek paveidots par integer tipa elementu un saglabats integer tipa masiva.
            masivs[j] = masivs[j] * 10 + (str[i] - 48);

        }
    }

    //Tiek izveidots klases ofstream objekts un tas tiek savienots ar failu data_out.txt
    std::ofstream fileout ("data_out.txt");

    //for cikls ietere cauri visam masivam, sakot ar masiva pedejo elementu, lidz masiva elementam ar indeksu nulle.
    for(int i = j; i >= 0; i--){
        //Elements tiek ieraksits faila data_out.txt, pec katra elementa seko komats un atstarpe.
        fileout << masivs[i] << ", ";
        //Katras iteracijas laika elementa vertiba tiek pieskaitita mainiga summa vertibai.
        summa += masivs[i];
    }

    fileout << std::endl;
    //Faila tiek ierakstita masiva skaitlu summa.
    fileout << "Masiva skaitlu summa: ";
    fileout << summa;
    //Fails tiek aizverts.
    fileout.close();
}

int main(){

    //Tiek deklareta un inicieta tuksa string, kura galabasies faila esosa infomacija.
    std::string data = "";

    //Fails tiek atverts lasisanai
    std::ifstream file("data_in.txt");

    //Tiek parbaudits, vai fails ir atverts.
    if(!file.is_open()){
        //Ja fails netiek atverts, uz ekrana paradas kludas pazinojums.
        std::cout << "Kluda. Failu nevar atvert.\n";
    }else {
        /*
        Ja fails tiek atverts, tad while cikls ies lidz pat faila esosas informacijas beigam (pedejai rakszimei, simbolam)
        un ar getline palidzibu visa informacija no faila tiek ierakstita string.
        */
        while(getline(file, data)){
            //String tiek izvadita uz ekrana.
            std::cout << data << std::endl;
            //Tiek izsaukta funkcija, kas konverte string par integer tipa masivu.
            convertStrtoArr(data);
        }
        //Aizver failu.
        file.close();
    }
    return 0;
}
