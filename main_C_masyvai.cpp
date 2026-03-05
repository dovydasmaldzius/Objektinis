#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <ctime>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::left;
using std::setw;
using std::fixed;
using std::setprecision;
using std::numeric_limits;
using std::streamsize;
using std::sort;


struct Studentas {
    string vardas = "A", pavarde = "B";
    int *pazymiai = nullptr;
    int n = 0;
    int egzaminas = 0;
    double rezultatas = 0;
    double mediana = 0;
};

int main() {
int pasirinkimas;
int m=0;
Studentas* grupe=nullptr;
srand(time(nullptr));

while(true) {
    cout<<"Kaip norite ivesti studentu duomenis?"<<endl;
    cout<<"1 - studentu vardus, pavardes ir pazymius ivesti ranka"<<endl;
    cout<<"2 - tik pazymius generuoti atsitiktinai"<<endl;
    cout<<"3 - generuoti studentu vardus, pavardes ir pazymius"<<endl;
    cin>>pasirinkimas;
if(cin.fail() || pasirinkimas < 1 || pasirinkimas > 3) {
    cout << "Prasome ivesti tik viena is skaiciu 1,2 arba 3!" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
} 
else break;
}

if(pasirinkimas==1) {
    while(true) {
    cout<<"kiek yra studentu? "<<endl;
    cin>>m;
    if(cin.fail() || m <= 0) {
    cout<<"Prasome ivesti sveika skaiciu didesni uz 0! "<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
else break; }
grupe=new Studentas[m];

for(int ii=0; ii<m; ii++) {
    while(true) {
    cout<<"Iveskite varda ir pavarde"<<endl;
    cin>>grupe[ii].vardas>>grupe[ii].pavarde;

    bool hasDigit = std::any_of(grupe[ii].vardas.begin(), grupe[ii].vardas.end(), [](unsigned char c){ return std::isdigit(c); }) ||
std::any_of(grupe[ii].pavarde.begin(), grupe[ii].pavarde.end(), [](unsigned char c){ return std::isdigit(c); });
if(hasDigit) {
    cout<<"Prasome ivesti varda ir pavarde dar karta"<<endl;
    continue; }
    break;
}

int n;
while(true) {
    cout<<"iveskite pazymiu skaiciu:"<<endl;
    cin>>n;
if(cin.fail() || n<=0) {
    cout<<"Prasome ivesti sveika skaiciu didesni uz 0! "<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); } 
    else {
    grupe[ii].n = n;
    grupe[ii].pazymiai = new int[n];
    break; }
}

    int temp;
    int sum=0;
for(int i=0; i<grupe[ii].n; i++) {
    while(true) {
    cout<<"iveskite pazymi: "<<endl;
    cin>>temp;
if(cin.fail() || temp < 1 || temp > 10) {
    cout<<"Prasome ivesti tik skaicius nuo 1 iki 10! "<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else {
grupe[ii].pazymiai[i] = temp;
sum += temp;
break; }
}
}

    while(true) {
    cout<<"iveskite egzamino pazymi"<<endl;
    cin>>grupe[ii].egzaminas;
if(cin.fail() || grupe[ii].egzaminas<1 || grupe[ii].egzaminas>10) {
    cout<<"Prasome ivesti tik skaicius nuo 1 iki 10"<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break;
}

sort(grupe[ii].pazymiai, grupe[ii].pazymiai + grupe[ii].n);
    int kiekis = grupe[ii].n;
if(kiekis == 0) grupe[ii].mediana = 0;
    else if(kiekis % 2 == 0) grupe[ii].mediana = (grupe[ii].pazymiai[kiekis/2 - 1] + grupe[ii].pazymiai[kiekis/2]) / 2.0;
    else grupe[ii].mediana = grupe[ii].pazymiai[kiekis/2];
    grupe[ii].rezultatas = sum * 1.0 / (grupe[ii].n * 1.0) * 0.4 + grupe[ii].egzaminas * 0.6; }
} 

else if(pasirinkimas==2) {
    while(true) {
    cout << "kiek yra studentu? " << endl;
    cin >> m;
    if(cin.fail() || m <= 0) {
        cout<<"Prasome ivesti sveika skaiciu didesni uz 0! "<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
        break;
    }
}
    grupe = new Studentas[m];
for(int ii = 0; ii < m; ii++){
    while(true) {
    cout << "Iveskite varda ir pavarde" << endl;
    cin >> grupe[ii].vardas >> grupe[ii].pavarde;
bool hasDigit = std::any_of(grupe[ii].vardas.begin(), grupe[ii].vardas.end(), [](unsigned char c){ return std::isdigit(c); }) ||
                                std::any_of(grupe[ii].pavarde.begin(), grupe[ii].pavarde.end(), [](unsigned char c){ return std::isdigit(c); });
    if(hasDigit) {
    cout<<"Prasome ivesti varda ir pavarde dar karta"<<endl;
    continue; }
    break;
}

int n;
    while(true) {
    cout<<"iveskite pazymiu skaiciu:"<<endl;
    cin>>n;
if(cin.fail() || n <= 0) {
    cout<<"Prasome ivesti sveika skaiciu didesni uz 0! "<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else {
    grupe[ii].n = n;
    grupe[ii].pazymiai = new int[n];
    break;
}
}

int sum=0;
    cout<<"Atsitiktinai sugeneruoti "<<ii+1<<" - ojo studento pazymiai: ";
for(int i=0; i<grupe[ii].n; i++) {
    int temp=(rand() % 10) + 1;
    grupe[ii].pazymiai[i] = temp;
    sum += temp;
    cout<<temp<<(i + 1 == grupe[ii].n ? "" : " ");
}
    cout << endl;

sort(grupe[ii].pazymiai, grupe[ii].pazymiai + grupe[ii].n);
    int kiekis = grupe[ii].n;

    grupe[ii].egzaminas = (rand() % 10) + 1;
cout << "Atsitiktinai sugeneruotas " << ii+1 << " - ojo studento egzamino pazymys: " << grupe[ii].egzaminas << endl;

if(kiekis == 0) grupe[ii].mediana = 0;
    else if(kiekis % 2 == 0) grupe[ii].mediana = (grupe[ii].pazymiai[kiekis/2 - 1] + grupe[ii].pazymiai[kiekis/2]) / 2.0;
    else grupe[ii].mediana = grupe[ii].pazymiai[kiekis/2];

    grupe[ii].rezultatas = sum * 1.0 / (grupe[ii].n * 1.0) * 0.4 + grupe[ii].egzaminas * 0.6;
}
} 
else if(pasirinkimas == 3) {
    while(true) {
    cout << "kiek yra studentu? " << endl;
    cin >> m;
    if(cin.fail() || m <= 0) {
    cout<<"Prasome ivesti sveika skaiciu didesni uz 0! "<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); } 
else break;
}

grupe = new Studentas[m];
    string firstNames[] = {"Jonas","Petras","Ona","Lina","Mantas","Egle","Darius","Ruta","Tomas","Ieva"};
    string lastNames[]  = {"Petraitis","Kazlauskas","Jankauskas","Stankevicius","Vilkas","Daugela","Miskinis","Jankauskiene","Zalys","Baranauskas"};
for(int ii = 0; ii < m; ii++) {
    grupe[ii].vardas = firstNames[rand() % (sizeof(firstNames)/sizeof(firstNames[0]))];
    grupe[ii].pavarde = lastNames[rand() % (sizeof(lastNames)/sizeof(lastNames[0]))];

int n = (rand() % 10) + 1;
    grupe[ii].n = n;
    grupe[ii].pazymiai = new int[n];

int sum = 0;
    cout << "Atsitiktinai sugeneruoti " << ii+1 << " - ojo studento pazymiai: ";
for(int i = 0; i < n; i++) {
int temp = (rand() % 10) + 1;
    grupe[ii].pazymiai[i] = temp;
    sum += temp;
    cout << temp << (i + 1 == n ? "" : " ");
}
    cout << endl;

grupe[ii].egzaminas = (rand() % 10) + 1;
    cout << "Atsitiktinai sugeneruotas " << ii+1 << " - ojo studento egzamino pazymys: " << grupe[ii].egzaminas << endl;

    sort(grupe[ii].pazymiai, grupe[ii].pazymiai + n);
int kiekis = n;
if(kiekis == 0) grupe[ii].mediana = 0;
    else if(kiekis % 2 == 0) grupe[ii].mediana = (grupe[ii].pazymiai[kiekis/2 - 1] + grupe[ii].pazymiai[kiekis/2]) / 2.0;
    else grupe[ii].mediana = grupe[ii].pazymiai[kiekis/2];

    grupe[ii].rezultatas = sum * 1.0 / (n * 1.0) * 0.4 + grupe[ii].egzaminas * 0.6;
}
} 

    
    cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Rezultatas" << setw(20) << "Mediana" << endl;
    for(int i = 0; i < m; i++){
    cout << left << setw(20) << grupe[i].vardas << setw(20) << grupe[i].pavarde;
    cout << setw(20) << fixed << setprecision(2) << grupe[i].rezultatas;
    cout << setw(20) << grupe[i].mediana << endl;
}

for(int i = 0; i < m; i++) {
    delete[] grupe[i].pazymiai;
}
    delete[] grupe;

    return 0;
}
