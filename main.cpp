#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <time.h>

using namespace std;


//Globale Variablen
bool play;
bool path;
bool ingame;
int namensSpeicher[100];
int speicher[250];//Speichergröße
int spielfeld[100][100];//Spielfeldgröße
string squadName1="shinji";
string squadName2="lili";
string squadName3="ralfson";
string squadName4="zehnzeiche";
string squadName5="ricemang";
string charName="hans";
string displayName;

void loadmenu();
void load1();
void load2();
void load3();
void quit();
void mapmaker();
void savemenu();
void save1();
void save2();
void save3();
void gameround();
void ClearScreen();
void settings();
void colorSetting();
void expedition();
void squadManagerMenu();
void frameworkTop();
void frameworkBottom();
void squadManager(int, int);
void survivorCreator();
void squadAssignment(int,int,int);
void squadAssignmentMenu(int,int,int);
void displaySurvivorStatus(int);
void displayFemaleName(int);
void displayMaleName(int);
void displaySurname(int);
void squadAssMenuDisplay(int&,int&,int,int);

int main()
{
    speicher[51]=10999900;

    srand(time(NULL));
    survivorCreator();
    survivorCreator();
    survivorCreator();
    survivorCreator();
    survivorCreator();
    speicher[167]=0;
    play = true;
    ingame = false;
    do
    {
        cout << "\{======================================\}\n";
        cout << "1 - Start game\n";
        cout << "2 - Load game\n";
        cout << "3 - Quit game\n";
        cout << "4 - Settings\n";
        cout << "\{======================================\}\n";
        char menu;
        cin >> menu;
        switch(menu)
        {
            case '1': ClearScreen();
            break;
            case '2': ClearScreen(),loadmenu();
            break;
            case '3': ClearScreen(),quit();
            break;
            case '4': ClearScreen(),settings();
            break;
            default: ClearScreen();
        }
    }while(play);
    cout << "Game quit.\n";
    return 0;
}

void loadmenu()
{
    cout << "<------------------------------------------->\n";
    cout << "Which file do you want to load?\n";
    cout << "1 - Savefile 1\n";
    cout << "2 - Savefile 2\n";
    cout << "3 - Savefile 3\n";
    cout << "<------------------------------------------->\n";
    cout << "Press any other key to get back.\n";
    cout << "<------------------------------------------->\n";
    char menu;
    cin >> menu;
    switch(menu)
    {
        case '1': system("cls"),load1(),gameround();
        return;
        case '2': system("cls"),load2();
        return;
        case '3': system("cls"),load3();
        return;
        default: system("cls");
    }
}

void load1()
{
    char* save="save1.txt";
    int wert;
    ifstream loadfile(save);
    int checknumber;
    loadfile >> checknumber;
    if(checknumber)
        {
            for(int i=1;i<100;i++)//Speichergröße
            {
                loadfile >> wert;
                speicher[i]=wert;
            }
            cout << "Loading succesful.\n";
            save="saveworld1.txt";
            ifstream saveworld(save);
            if(saveworld)
            {
                for(int i=0;i<100;i++)//Spielfeldgröße
                    for(int j=0;j<100;j++)//Spielfeldgröße
                    {
                        saveworld >> wert;
                        spielfeld[i][j]=wert;
                    }
            }
            else
                cout << "Unable to load world.\n";
        }
    else
        cout << "Empty file.\n";
}

void load2()
{
    char* save="save2.txt";
    int wert;
    ifstream loadfile(save);
    int checknumber;
    loadfile >> checknumber;
    if(checknumber)
        {
            for(int i=1;i<100;i++)//Speichergröße
            {
                loadfile >> wert;
                speicher[i]=wert;
            }
            cout << "Loading succesful.\n";
            save="saveworld2.txt";
            ifstream saveworld(save);
            if(saveworld)
            {
                for(int i=0;i<100;i++)//Spielfeldgröße
                    for(int j=0;j<100;j++)//Spielfeldgröße
                    {
                        saveworld >> wert;
                        spielfeld[i][j]=wert;
                    }
            }
            else
                cout << "Unable to load world.\n";
        }
    else
        cout << "Empty file.\n";
}

void load3()
{
    char* save="save3.txt";
    int wert;
    ifstream loadfile(save);
    int checknumber;
    loadfile >> checknumber;
    if(checknumber)
        {
            for(int i=1;i<100;i++)//Speichergröße
            {
                loadfile >> wert;
                speicher[i]=wert;
            }
            cout << "Loading succesful.\n";
            save="saveworld3.txt";
            ifstream saveworld(save);
            if(saveworld)
            {
                for(int i=0;i<100;i++)//Spielfeldgröße
                    for(int j=0;j<100;j++)//Spielfeldgröße
                    {
                        saveworld >> wert;
                        spielfeld[i][j]=wert;
                    }
            }
            else
                cout << "Unable to load world.\n";
        }
    else
        cout << "Empty file.\n";
}

void quit()
{
    cout << "---------------------------------\n";
    cout << "Do you really want to quit?\n";
    cout << "1 - Yes\n";
    cout << "2 - No\n";
    cout << "---------------------------------\n";
    char menu;
    cin >> menu;
    switch(menu)
    {
        case '1': play=false,system("cls");
        return;
        case '2': play=true,system("cls");
        return;
        default: play=true,system("cls");
    }
}

void mapmaker()
{
    int randomizer;
    for(int i=0;i<100;i++)//Spielfeldgröße
        for(int j=0;j<100;j++)//Spielfeldgröße
            spielfeld[i][j]=0;
    spielfeld[50][50]=1;//Startposition
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
        {
            if(spielfeld[i][j]!=1)
            {
                randomizer=rand()%100;
                if(randomizer<40)//Wahrscheinlichkeit Parks
                {
                    randomizer=rand()%99;
                    if(randomizer<33)//Wahrscheinlichkeit kleiner Park
                    {
                        randomizer=rand()%10+20;
                        spielfeld[i][j]=randomizer;//Kleiner Park
                    }
                    else
                        if(randomizer<66)//Wahrscheinlichkeit mittlerer Park
                        {
                            randomizer=rand()%10+30;
                            spielfeld[i][j]=randomizer;//Mittlerer Park
                        }
                        else
                        {
                            randomizer=rand()%10+40;
                            spielfeld[i][j]=randomizer;//Großer Park
                        }
                }
                else
                    if(randomizer<80)//Wahrscheinlichkeit Gebäude
                    {
                        randomizer=rand()%99;
                        if(randomizer<33)//Wahrscheinlichkeit kleines Gebäude
                        {
                            randomizer=rand()%10+50;
                            spielfeld[i][j]=randomizer;//Kleines Gebäude
                        }
                        else
                            if(randomizer<66)//Wahrscheinlichkeit mittleres Gebäude
                            {
                                randomizer=rand()%10+60;
                                spielfeld[i][j]=randomizer;//Mittleres Gebäude
                            }
                            else
                            {
                                randomizer=rand()%10+70;
                                spielfeld[i][j]=randomizer;//Großes Gebäude
                            }
                    }
                    else
                    {
                        randomizer=rand()%120;
                        if(randomizer<20)
                        {
                            randomizer=rand()%10+80;
                            spielfeld[i][j]=randomizer;//Krankenhaus
                        }
                        else
                            if(randomizer<40)
                            {
                                randomizer=rand()%10+90;
                                spielfeld[i][j]=randomizer;//Labor
                            }
                            else
                                if(randomizer<60)
                                {
                                    randomizer=rand()%10+100;
                                    spielfeld[i][j]=randomizer;//Supermarkt
                                }
                                else
                                    if(randomizer<80)
                                    {
                                        randomizer=rand()%10+110;
                                        spielfeld[i][j]=randomizer;//Waffengeschäft
                                    }
                                    else
                                        if(randomizer<100)
                                        {
                                            randomizer=rand()%10+120;
                                            spielfeld[i][j]=randomizer;//Baumarkt
                                        }
                                        else
                                        {
                                            randomizer=rand()%10+130;
                                            spielfeld[i][j]=randomizer;//Fachgeschäft
                                        }
                    }
            }
        }
}

void savemenu()
{
    cout << "---------------------------------\n";
    cout << "Which savefile do you want to use?\n";
    cout << "1 - Savefile 1\n";
    cout << "2 - Savefile 2\n";
    cout << "3 - Savefile 3\n";
    cout << "---------------------------------\n";
    cout << "Press any other key to get back.\n";
    cout << "---------------------------------\n";
    char menu;
    cin >> menu;
    switch(menu)
    {
        case '1':
        {
            cout << "---------------------------------\n";
            cout << "Do you really want to use savefile 1?\n";
            cout << "1 - Yes\n";
            cout << "2 - No\n";
            cout << "---------------------------------\n";
            cin >> menu;
            switch(menu)
            {
                case '1': system("cls"),save1();
                return;
                case '2': system("cls");
                return;
                default: system("cls");
            }
        }
        return;
        case '2':
        {
            cout << "---------------------------------\n";
            cout << "Do you really want to use savefile 2?\n";
            cout << "1 - Yes\n";
            cout << "2 - No\n";
            cout << "---------------------------------\n";
            cin >> menu;
            switch(menu)
            {
                case '1': system("cls"),save2();
                return;
                case '2': system("cls");
                return;
                default: system("cls");
            }
        }
        return;
        case '3':
        {
            cout << "---------------------------------\n";
            cout << "Do you really want to use savefile 3?\n";
            cout << "1 - Yes\n";
            cout << "2 - No\n";
            cout << "---------------------------------\n";
            cin >> menu;
            switch(menu)
            {
                case '1': system("cls"),save3();
                return;
                case '2': system("cls");
                return;
                default: system("cls");
            }
        }
        return;
        default: system("cls");
    }
}

void save1()
{
    char* save="saveworld1.txt";
    ofstream saveworld(save);
    for(int i=0;i<100;i++)//Spielfeldgröße
        for(int j=0;j<100;j++)//Spielfeldgröße
            saveworld << spielfeld[i][j] << " ";
    save="save1.txt";
    ofstream savefile(save);
    for(int i=0;i<100;i++)//Speichergröße
        savefile << speicher[i] << " ";
}

void save2()
{
    char* save="saveworld2.txt";
    ofstream saveworld(save);
    for(int i=0;i<100;i++)//Spielfeldgröße
        for(int j=0;j<100;j++)//Spielfeldgröße
            saveworld << spielfeld[i][j] << " ";
    save="save2.txt";
    ofstream savefile(save);
    for(int i=0;i<100;i++)//Speichergröße
        savefile << speicher[i] << " ";
}

void save3()
{
    char* save="saveworld3.txt";
    ofstream saveworld(save);
    for(int i=0;i<100;i++)//Spielfeldgröße
        for(int j=0;j<100;j++)//Spielfeldgröße
            saveworld << spielfeld[i][j] << " ";
    save="save3.txt";
    ofstream savefile(save);
    for(int i=0;i<100;i++)//Speichergröße
        savefile << speicher[i] << " ";
}

void roundweather()
{
    int randomizer=rand()%6;//Wetter
    speicher[166]=randomizer;
    randomizer=rand()%5;//Regenwahrscheinlichkeit
    if(randomizer==0)//Regenwahrscheinlichkeit
        speicher[163]=true;
    else
        speicher[163]=false;
    speicher[165]=rand()%71;//Grundsatz von EZA
        if(speicher[163])
            speicher[165]+=25;//Erhöhung durch Regen
        else
            if(speicher[164]<-4)
                speicher[165]-=25;//Senkung durch Temperaturen unter -4
            else
                if(speicher[164]<1)
                    speicher[165]-=15;//Senkung durch Temperaturen unter 1
                else
                    if(speicher[164]<6)
                        speicher[165]-=5;//Senkung durch Temperaturen unter 6
                    else
                        if(speicher[164]<16)
                            speicher[165]+=5;//Erhöhung durch Temperaturen unter 16
                        else
                            if(speicher[164]<26)
                                speicher[165]+=25;//Erhöhung durch Temperaturen unter 26
                            else
                                if(speicher[164]<31)
                                    speicher[165]+=15;//Erhöhung durch Temperaturen unter 31
                                else;
    if(speicher[3]<32)
    {
        speicher[162]=1;
        speicher[164]=rand()%22-8;
    }
    else
        if(speicher[3]<60)
        {
            speicher[162]=2;
            speicher[164]=rand()%28-10;
        }
        else
            if(speicher[3]<91)
            {
                speicher[162]=3;
                speicher[164]=rand()%28-7;
            }
            else
                if(speicher[3]<121)
                {
                    speicher[162]=4;
                    speicher[164]=rand()%29-2;
                }
                else
                    if(speicher[3]<152)
                    {
                        speicher[162]=5;
                        speicher[164]=rand()%32-2;
                    }
                    else
                        if(speicher[3]<182)
                        {
                            speicher[162]=6;
                            speicher[164]=rand()%42-11;
                        }
                        else
                            if(speicher[3]<213)
                            {
                                speicher[162]=7;
                                speicher[164]=rand()%44-11;
                            }
                            else
                                if(speicher[3]<244)
                                {
                                    speicher[162]=8;
                                    speicher[164]=rand()%45-9;
                                }
                                else
                                    if(speicher[3]<274)
                                    {
                                        speicher[162]=9;
                                        speicher[164]=rand()%41-9;
                                    }
                                    else
                                        if(speicher[3]<305)
                                        {
                                            speicher[162]=10;
                                            speicher[164]=rand()%26;
                                        }
                                        else
                                            if(speicher[3]<335)
                                            {
                                                speicher[162]=11;
                                                speicher[164]=rand()%19-3;
                                            }
                                            else
                                                {
                                                    speicher[162]=12;
                                                    speicher[164]=rand()%17-4;
                                                }
}

void gameround()
{
    roundweather();
    frameworkTop();
    cout << "<Survivors:      ";
    if(speicher[14]<10)//Speicher[14]=Überlebende
        cout << "            " << speicher[14];
        else
            if(speicher[14]<100)
                cout << "           " << speicher[14];
            else
                if(speicher[14]<1000)
                    cout << "          " << speicher[14];
                else
                    if(speicher[14]<10000)
                        cout << "         " << speicher[14];
                    else
                        if(speicher[14]<100000)
                            cout << "        " << speicher[14];
                        else
                            if(speicher[14]<1000000)
                                cout << "       " << speicher[14];
                            else
                                cout << "      +999999";
    if(speicher[30])//Speicher[30]=Gebäude Labor
    {
        cout << " | Lab          - Remaining time:   ";
        if(speicher[19]<10)//Speicher[19]=Verbleibende Forschungszeit
            cout << " " << speicher[19];
        else
            cout << speicher[19];
        cout << " Rounds >\n";
    }
    else
        cout << " --------------------------------------------------->\n";
    cout << "<Camp morale:          ";
    if(speicher[161])
        if(double(speicher[16])/speicher[151]<0.25)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        else
            if(double(speicher[16])/speicher[151]<0.75)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            else
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    else;
    if(speicher[16]<10)//Speicher[16]=Moral im Camp
        cout << "  " << speicher[16];
    else
        if(speicher[16]<100)
            cout << " " << speicher[16];
        else
            cout << speicher[16];
    cout << "/";
    if(speicher[151]<10)//Speicher[151]=Maximale Moral im Camp
        cout << speicher[151] << "  ";
    else
        if(speicher[151]<100)
            cout << speicher[151] << " ";
        else
            cout << speicher[151];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    if(speicher[31])//Speicher[31]=Gebäude Werkstatt
    {
        cout << " | Workshop     - Remaining time:   ";
        if(speicher[20]<10)//Speicher[20]=Verbleibende Arbeitszeit
            cout << " " << speicher[20];
        else
            cout << speicher[20];
        cout << " Rounds >\n";
    }
    else
        cout << " --------------------------------------------------->\n";
    cout << "<Fortifications:       ";
    if(speicher[161])
        if(double(speicher[17])/speicher[18]<0.25)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        else
            if(double(speicher[17])/speicher[18]<0.75)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            else
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    else;
    if(speicher[17]<10)//Speicher[17]=Barrikaden HP
        cout << "  " << speicher[17];
    else
        if(speicher[17]<100)
            cout << " " << speicher[17];
        else
            cout << speicher[17];
    cout << "/";
    if(speicher[18]<10)//Speicher[18]=Maximale Barrikaden HP
        cout << speicher[18] << "  ";
    else
        if(speicher[18]<100)
            cout << speicher[18] << " ";
        else
            cout << speicher[18];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    if(speicher[32])//Speicher[32]=Derzeitig errichtetes Gebäude
    {
        cout << " | Construction - Remaining time:   ";
        if(speicher[21]<10)//Speicher[21]=Verbleibende Bauzeit
            cout << " " << speicher[21];
        else
            cout << speicher[21];
        cout << " Rounds >\n";
    }
    else
        cout << " --------------------------------------------------->\n";
    cout << "<--------------------------------------------------------------------------->\n";
    cout << "<Food:         ";
    if(speicher[4]<10)//Speicher[4]=Nahrungsvorräte
        cout << "      " << speicher[4];
    else
        if(speicher[4]<100)
            cout << "     " << speicher[4];
        else
            if(speicher[4]<1000)
                cout << "    " << speicher[4];
            else
                if(speicher[4]<10000)
                    cout << "   " << speicher[4];
                else
                    if(speicher[4]<100000)
                        cout << "  " << speicher[4];
                    else
                        if(speicher[4]<1000000)
                            cout << " " << speicher[4];
                        else
                            cout << "+999999";
    cout << "/";
    if(speicher[5]<10)//Speicher[5]=Maximale Nahrungsvorräte
        cout << speicher[5] << "      ";
    else
        if(speicher[5]<100)
            cout << speicher[5] << "     ";
        else
            if(speicher[5]<1000)
                cout << speicher[5] << "    ";
            else
                if(speicher[5]<10000)
                    cout << speicher[5] << "   ";
                else
                    if(speicher[5]<100000)
                        cout << speicher[5] << "  ";
                    else
                        if(speicher[5]<1000000)
                            cout << speicher[5] << " ";
                        else
                            cout << "+999999";
    cout << " | What do you want to do? ";
    if(speicher[161])
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    else;
    cout << speicher[152];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << " AP remaining.    >\n"; //Speicher[152]=Aktionspunkte
    cout << "<Food consumption:     ";
    int verbrauch=(speicher[14]/2)*speicher[155];//Speicher[14]=Überlebende,Speicher[155]=Nahrungsverbrauch
    if(verbrauch==0)
        verbrauch=1;
    else;
    if(speicher[161])
        if(verbrauch>speicher[4])
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    else;
    if(verbrauch<10)
        cout << "      " << verbrauch;
    else
        if(verbrauch<100)
            cout << "     " << verbrauch;
        else
            if(verbrauch<1000)
                cout << "    " << verbrauch;
            else
                if(verbrauch<10000)
                    cout << "   " << verbrauch;
                else
                    if(verbrauch<100000)
                        cout << "  " << verbrauch;
                    else
                        if(verbrauch<1000000)
                            cout << " " << verbrauch;
                        else
                            cout << "+999999";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    if(speicher[161]&&speicher[152])//Einstellung ob Farben dargestellt werden oder nicht
    {
        cout << " |";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "      1 - Head out into the city.     -1 AP ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << ">\n";
    }
    else
        cout << " |      1 - Head out into the city.           >\n";
    cout << "<Water:        ";
    if(speicher[6]<10)//Speicher[6]=Wasservorräte
        cout << "      " << speicher[6];
    else
        if(speicher[6]<100)
            cout << "     " << speicher[6];
        else
            if(speicher[6]<1000)
                cout << "    " << speicher[6];
            else
                if(speicher[6]<10000)
                    cout << "   " << speicher[6];
                else
                    if(speicher[6]<100000)
                        cout << "  " << speicher[6];
                    else
                        if(speicher[6]<1000000)
                            cout << " " << speicher[6];
                        else
                            cout << "+999999";
    cout << "/";
    if(speicher[7]<10)//Speicher[7]=Maximale Wasservorräte
        cout << speicher[7] << "      ";
    else
        if(speicher[7]<100)
            cout << speicher[7] << "     ";
        else
            if(speicher[7]<1000)
                cout << speicher[7] << "    ";
            else
                if(speicher[7]<10000)
                    cout << speicher[7] << "   ";
                else
                    if(speicher[7]<100000)
                        cout << speicher[7] << "  ";
                    else
                        if(speicher[7]<1000000)
                            cout << speicher[7] << " ";
                        else
                            cout << "+999999";
    if(speicher[161]&&speicher[152])//Einstellung ob Farben dargestellt werden oder nicht
    {
        cout << " |";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "      2 - Rest for a while.           -1 AP ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << ">\n";
    }
    else
        cout << " |      2 - Rest for a while.                 >\n";
    cout << "<Water consumption:    ";
    int wasserverbrauch=speicher[14]/2;//Speicher[14]=Überlebende
    if(wasserverbrauch==0)
        wasserverbrauch=1;
    else;
    if(speicher[161])
        if(wasserverbrauch>speicher[6])
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    else;
    if(speicher[164]>25)
        wasserverbrauch=wasserverbrauch*2;
    else
        if(speicher[164]>35)
        wasserverbrauch=wasserverbrauch*4;
    if(wasserverbrauch<10)
        cout << "      " << wasserverbrauch;
    else
        if(wasserverbrauch<100)
            cout << "     " << wasserverbrauch;
        else
            if(wasserverbrauch<1000)
                cout << "    " << wasserverbrauch;
            else
                if(wasserverbrauch<10000)
                    cout << "   " << wasserverbrauch;
                else
                    if(wasserverbrauch<100000)
                        cout << "  " << wasserverbrauch;
                    else
                        if(wasserverbrauch<1000000)
                            cout << " " << wasserverbrauch;
                        else
                            cout << "+999999";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    if(speicher[161]&&speicher[152])//Einstellung ob Farben dargestellt werden oder nicht
    {
        cout << " |";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        if(speicher[17]<21)
            cout << "   !  3 - Inspect the fortifications. -1 AP ";
        else
            cout << "      3 - Inspect the fortifications. -1 AP ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << ">\n";
    }
    else
        if(speicher[17]<21)
            cout << " |   !  3 - Inspect the fortifications.       >\n";
        else
            cout << " |      3 - Inspect the fortifications.       >\n";
    cout << "<Medical supplies:     ";
    if(speicher[8]<10)//Speicher[8]=Medikamente
        cout << "      " << speicher[8];
    else
        if(speicher[8]<100)
            cout << "     " << speicher[8];
        else
            if(speicher[8]<1000)
                cout << "    " << speicher[8];
            else
                if(speicher[8]<10000)
                    cout << "   " << speicher[8];
                else
                    if(speicher[8]<100000)
                        cout << "  " << speicher[8];
                    else
                        if(speicher[8]<1000000)
                            cout << " " << speicher[8];
                        else
                            cout << "+999999";
    if(speicher[161])//Einstellung ob Farben dargestellt werden oder nicht
    {
        cout << " |";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        if(speicher[158])
            cout << "   !  4 - Visit the lab.                    ";
        else
            cout << "      4 - Visit the lab.                    ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << ">\n";
    }
    else
        if(speicher[158])//Prüfung ob neue Forschung verfügbar ist
            cout << " |   !  4 - Visit the lab.                    >\n";
        else
            cout << " |      4 - Visit the lab.                    >\n";
    cout << "<Equipment:            ";
    if(speicher[9]<10)//Speicher[9]=Ausrüstung
        cout << "      " << speicher[9];
    else
        if(speicher[9]<100)
            cout << "     " << speicher[9];
        else
            if(speicher[9]<1000)
                cout << "    " << speicher[9];
            else
                if(speicher[9]<10000)
                    cout << "   " << speicher[9];
                else
                    if(speicher[9]<100000)
                        cout << "  " << speicher[9];
                    else
                        if(speicher[9]<1000000)
                            cout << " " << speicher[9];
                        else
                            cout << "+999999";
    if(speicher[161])//Einstellung ob Farben dargestellt werden oder nicht
    {
        cout << " |";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        if(speicher[159])
            cout << "   !  5 - Visit the workshop.               ";
        else
            cout << "      5 - Visit the workshop.               ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << ">\n";
    }
    else
        if(speicher[159])
            cout << " |   !  5 - Visit the workshop.               >\n";
        else
            cout << " |      5 - Visit the workshop.               >\n";
    cout << "<Building materials:   ";
    if(speicher[10]<10)//Speicher[10]=Baumaterialien
        cout << "      " << speicher[10];
    else
        if(speicher[10]<100)
            cout << "     " << speicher[10];
        else
            if(speicher[10]<1000)
                cout << "    " << speicher[10];
            else
                if(speicher[10]<10000)
                    cout << "   " << speicher[10];
                else
                    if(speicher[10]<100000)
                        cout << "  " << speicher[10];
                    else
                        if(speicher[10]<1000000)
                            cout << " " << speicher[10];
                        else
                            cout << "+999999";
    if(speicher[161])//Einstellung ob Farben dargestellt werden oder nicht
    {
        cout << " |";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        if(speicher[160])
            cout << "   !  6 - Visit the construction site.      ";
        else
            cout << "      6 - Visit the construction site.      ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << ">\n";
    }
    else
        if(speicher[160])
            cout << " |   !  6 - Visit the construction site.      >\n";
        else
            cout << " |      6 - Visit the construction site.      >\n";
    cout << "<Lab equipment:        ";
    if(speicher[11]<10)//Speicher[11]=Labormaterialien
        cout << "      " << speicher[11];
    else
        if(speicher[11]<100)
            cout << "     " << speicher[11];
        else
            if(speicher[11]<1000)
                cout << "    " << speicher[11];
            else
                if(speicher[11]<10000)
                    cout << "   " << speicher[11];
                else
                    if(speicher[11]<100000)
                        cout << "  " << speicher[11];
                    else
                        if(speicher[11]<1000000)
                            cout << " " << speicher[11];
                        else
                            cout << "+999999";
    if(speicher[161])//Einstellung ob Farben dargestellt werden oder nicht
    {
        cout << " |";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "      7 - Manage the camp.                  ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << ">\n";
    }
    else
        cout << " |      7 - Manage the camp.                  >\n";
    cout << "<Fuel:                 ";
    if(speicher[12]<10)//Speicher[12]=Treibstoff
        cout << "      " << speicher[12];
    else
        if(speicher[12]<100)
            cout << "     " << speicher[12];
        else
            if(speicher[12]<1000)
                cout << "    " << speicher[12];
            else
                if(speicher[12]<10000)
                    cout << "   " << speicher[12];
                else
                    if(speicher[12]<100000)
                        cout << "  " << speicher[12];
                    else
                        if(speicher[12]<1000000)
                            cout << " " << speicher[12];
                        else
                            cout << "+999999";
    if(speicher[161])//Einstellung ob Farben dargestellt werden oder nicht
    {
        cout << " |";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "      8 - End the round.                    ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << ">\n";
    }
    else
        cout << " |      8 - End the round.                    >\n";
    cout << "<Ammunition:           ";
    if(speicher[13]<10)//Speicher[13]=Munition
        cout << "      " << speicher[13];
    else
        if(speicher[13]<100)
            cout << "     " << speicher[13];
        else
            if(speicher[13]<1000)
                cout << "    " << speicher[13];
            else
                if(speicher[13]<10000)
                    cout << "   " << speicher[13];
                else
                    if(speicher[13]<100000)
                        cout << "  " << speicher[13];
                    else
                        if(speicher[13]<1000000)
                            cout << " " << speicher[13];
                        else
                            cout << "+999999";
    if(speicher[161])//Einstellung ob Farben dargestellt werden oder nicht
    {
        cout << " |";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "      9 - Menu                              ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << ">\n";
    }
    else
        cout << " |      9 - Menu                              >\n";
    frameworkBottom();
    ingame=true;
    char menu;
    cin >> menu;
    switch(menu)
    {
        case '1':
            if(speicher[152])
                ClearScreen(),expedition();
            else
                ClearScreen(),gameround();
        return;
        case '9': ClearScreen(),settings();
        return;
        default: ClearScreen(),gameround();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FInitializer()
{
    for(int i=0;i<250;i++)
        speicher[i]=0;
    speicher[1]=1;
    speicher[3]=rand()%365+1;
    speicher[4]=6/schwierigkeit;
    speicher[6]=6/schwierigkeit;
    speicher[8]=2/schwierigkeit;
    speicher[9]=2/schwierigkeit;
    speicher[10]=2/schwierigkeit;
    speicher[11]=2/schwierigkeit;
    speicher[12]=2/schwierigkeit;
    speicher[13]=2/schwierigkeit;
    speicher[22]=100;
    speicher[23]=100;
    speicher[24]=1;
    speicher[26]=1;
    speicher[151]=100;
    speicher[152]=3;
    speicher[153]=3;
    speicher[156]=100;
    speicher[157]=100;
    speicher[161]=1;
}

void settings()
{
    cout << "<--------------------------------------------------------------------------->\n";
    cout << "<                                 Settings                                  >\n";
    cout << "<--------------------------------------------------------------------------->\n";
    cout << "<-----> 1 - Colors                                                          >\n";
    cout << "<--------------------------------------------------------------------------->\n";
    char menu;
    cin >> menu;
    switch(menu)
    {
        case '1': ClearScreen(),colorSetting();
        return;
        default:
            if(ingame)
                ClearScreen(),gameround();
            else
                ClearScreen();
    }
}

void colorSetting()
{
    cout << "<--------------------------------------------------------------------------->\n";
    cout << "<                              Color Settings                               >\n";
    cout << "<--------------------------------------------------------------------------->\n";
    cout << "<-----> 1 - Activate colors                                                 >\n";
    cout << "<-----> 2 - Deactivate colors                                               >\n";
    cout << "<--------------------------------------------------------------------------->\n";
    char menu;
    cin >> menu;
    switch(menu)
    {
        case '1':
            if(ingame)
                speicher[161]=1,ClearScreen(),gameround();
            else
                speicher[161]=1,ClearScreen();
        return;
        case '2':
            if(ingame)
                speicher[161]=0,ClearScreen(),gameround();
            else
                speicher[161]=0,ClearScreen();
        return;
        default:
            if(ingame)
                ClearScreen(),gameround();
            else
                ClearScreen();
    }
}

void UIExpedition()
{
    frameworkTop();
    cout << "<--- ";
    if(speicher[167])
    {
        cout << "Which squad do you want to join or send out into the city?             >\n";
        cout << "<                                                                           >\n";
        if(speicher[167])
        {
            cout << "<    1 - ";
            cout << squadName1;
        int spaces = squadName1.length();
        spaces = 10-spaces;
        for(;spaces;spaces--)
                cout << " ";
            cout << "                                                         >\n";
        }
        else
            cout << "<                                                                           >\n";
        if(speicher[173])
        {
            cout << "<    2 - ";
            cout << squadName2;
            int spaces = squadName2.length();
            spaces = 10-spaces;
            for(;spaces;spaces--)
                cout << " ";
            cout << "                                                         >\n";
        }
        else
            cout << "<                                                                           >\n";
        if(speicher[179])
        {
            cout << "<    3 - ";
            cout << squadName3;
            int spaces = squadName3.length();
            spaces = 10-spaces;
            for(;spaces;spaces--)
                cout << " ";
            cout << "                                                         >\n";
        }
        else
            cout << "<                                                                           >\n";
        if(speicher[185])
        {
            cout << "<    4 - ";
            cout << squadName4;
            int spaces = squadName4.length();
            spaces = 10-spaces;
            for(;spaces;spaces--)
                cout << " ";
            cout << "                                                         >\n";
        }
        else
            cout << "<                                                                           >\n";
        if(speicher[191])
        {
            cout << "<    5 - ";
            cout << squadName5;
            int spaces = squadName5.length();
            spaces = 10-spaces;
            for(;spaces;spaces--)
                cout << " ";
            cout << "                                                         >\n";
        }
        else
            cout << "<                                                                           >\n";
        cout << "<                                                                           >\n";
        cout << "<    6 - I don't need a squad.                                              >\n";
        cout << "<                                                                           >\n";
        cout << "<    7 - Manage squads.                                                     >\n";
        cout << "<                                                                           >\n";
        cout << "<    Press any other key to get back                                        >\n";
        cout << "<                                                                           >\n";
        frameworkBottom();
        char menu;
        cin >> menu;
        switch(menu)
        {
            case '1':;
            return;
            case '2':;
            return;
            case '3':;
            return;
            case '4':;
            return;
            case '5':;
            return;
            case '6':;
            return;
            case '7':;
            return;
            default: ClearScreen(),gameround();
        }
    }
    else
    {
        cout << "There are no existiting squads.                                        >\n";
        cout << "<                                                                           >\n";
        cout << "<    1 - I don't need a squad.                                              >\n";
        cout << "<                                                                           >\n";
        cout << "<    2 - Manage squads.                                                     >\n";
        cout << "<                                                                           >\n";
        cout << "<                                                                           >\n";
        cout << "<                                                                           >\n";
        cout << "<                                                                           >\n";
        cout << "<                                                                           >\n";
        cout << "<                                                                           >\n";
        cout << "<                                                                           >\n";
        cout << "<    Press any other key to get back                                        >\n";
        cout << "<                                                                           >\n";
        frameworkBottom();
        char menu;
        cin >> menu;
        switch(menu)
        {
            case '1':;
            return;
            case '2':;
            return;
            default: ClearScreen(), gameround();
        }
    }
}















void squadManagerMenu()
{
    frameworkTop();
    cout << "<--- ";
        cout << "Which squad do you want to edit?                                       >\n";
        cout << "<                                                                           >\n";
        if(speicher[167])
        {
            cout << "<    1 - ";
            cout << squadName1;
            int spaces = squadName1.length();
            spaces = 10-spaces;
            for(;spaces;spaces--)
                cout << " ";
            cout << "                                                         >\n";
        }
        else
            cout << "<    1 - Create new squad                                                   >\n";
        if(speicher[167] && speicher[173])
        {
            cout << "<    2 - ";
            cout << squadName2;
            int spaces = squadName2.length();
            spaces = 10-spaces;
            for(;spaces;spaces--)
                cout << " ";
            cout << "                                                         >\n";
        }
        else
        if(speicher[167])
            cout << "<    2 - Create new squad                                                   >\n";
        else
            cout << "<                                                                           >\n";
        if(speicher[167] && speicher[173] && speicher[179])
        {
            cout << "<    3 - ";
            cout << squadName3;
            int spaces = squadName3.length();
            spaces = 10-spaces;
            for(;spaces;spaces--)
                cout << " ";
            cout << "                                                         >\n";
        }
        else
        if(speicher[167] && speicher[173])
            cout << "<    3 - Create new squad                                                   >\n";
        else
            cout << "<                                                                           >\n";
        if(speicher[167] && speicher[173] && speicher[179] && speicher[185])
        {
            cout << "<    4 - ";
            cout << squadName4;
            int spaces = squadName4.length();
            spaces = 10-spaces;
            for(;spaces;spaces--)
                cout << " ";
            cout << "                                                         >\n";
        }
        else
        if(speicher[167] && speicher[173] && speicher[179])
            cout << "<    4 - Create new squad                                                   >\n";
        else
            cout << "<                                                                           >\n";
        if(speicher[167] && speicher[173] && speicher[179] && speicher[185] && speicher[191])
        {
            cout << "<    5 - ";
            cout << squadName5;
            int spaces = squadName5.length();
            spaces = 10-spaces;
            for(;spaces;spaces--)
                cout << " ";
            cout << "                                                         >\n";
        }
        else
        if(speicher[167] && speicher[173] && speicher[179] && speicher[185])
            cout << "<    5 - Create new squad                                                   >\n";
        else
            cout << "<                                                                           >\n";
        cout << "<                                                                           >\n";
        cout << "<                                                                           >\n";
        cout << "<                                                                           >\n";
        cout << "<                                                                           >\n";
        cout << "<                                                                           >\n";
        cout << "<    Press any other key to get back                                        >\n";
        cout << "<                                                                           >\n";
        frameworkBottom();
        char menu;
        cin >> menu;
        switch(menu)
        {
            case '1': squadManager(1,1);
            return;
            case '2':;
            return;
            case '3':;
            return;
            case '4':;
            return;
            case '5':;
            return;
            default:
                if(path)
                    ClearScreen(),path=false,expedition();
                else
                    ClearScreen(),gameround();
        }
}

void squadManager(int existing, int squadnumber)
{
    int vehicle;
    int member1,member2,member3,member4,member5;
    string squadname;
    frameworkTop();
    if(existing)
    {
        switch(squadnumber)
        {
        case 1:
            {
                member1=speicher[167];
                member2=speicher[168];
                member3=speicher[169];
                member4=speicher[170];
                member5=speicher[171];
                vehicle=speicher[172];
                squadname=squadName1;
            }
        break;
        case 2:
            {
                member1=speicher[173];
                member2=speicher[174];
                member3=speicher[175];
                member4=speicher[176];
                member5=speicher[177];
                vehicle=speicher[178];
                squadname=squadName2;
            }
        break;
        case 3:
            {
                member1=speicher[179];
                member2=speicher[180];
                member3=speicher[181];
                member4=speicher[182];
                member5=speicher[183];
                vehicle=speicher[184];
                squadname=squadName3;
            }
        break;
        case 4:
            {
                member1=speicher[185];
                member2=speicher[186];
                member3=speicher[187];
                member4=speicher[188];
                member5=speicher[189];
                vehicle=speicher[190];
                squadname=squadName4;
            }
        break;
        case 5:
            {
                member1=speicher[191];
                member2=speicher[192];
                member3=speicher[193];
                member4=speicher[194];
                member5=speicher[195];
                vehicle=speicher[196];
                squadname=squadName5;
            }
        break;
        default: cout << "ERROR: UNABLE TO LOAD SQUAD-MEMBERS!\n";
        }
        cout << "<--- ";
        switch(vehicle)
        {
            case 0: cout << "No vehicle assigned to this squad.                                     >\n";
            break;
            case 1: cout << "Assigned vehicles: Bicycles                                            >\n";
            break;
            case 2: cout << "Assigned vehicles: Small cars                                          >\n";
            break;
            case 3: cout << "Assigned vehicles: Cars                                                >\n";
            break;
            case 4: cout << "Assigned vehicles: Big cars                                            >\n";
            break;
            case 5: cout << "Assigned vehicle:  Helicopter                                          >\n";
            break;
            default: cout << "ERROR: UNABLE TO LOAD SQUAD-VEHICLE!\n";
        }
        cout << "<                                                                           >\n";
        cout << "<    1 - Assign new vehicle to squad.                                       >\n";
        cout << "<                                                                           >\n";
        cout << "<    2 - ";
        if(member1)
        {

        }
        else
        {
            cout << "Assign survivor to squad.                                               >\n";
        }
    }
        cout << "<--------------------------------------------------------------------------->\n";
        cout << "<--- ";
    frameworkBottom();
}

void squadAssignmentMenu(int squadnumber, int membernumber, int existing)
{
    frameworkTop();
    int soldiers=0, farmers=0, doctors=0, engineers=0, priests=0, constructors=0, scientists=0, survivors=0;
    int zwischenspeicher;
    for(int i=51;i<149 && speicher[i];i++)
    {
        zwischenspeicher=speicher[i];
        zwischenspeicher=zwischenspeicher/10000000;
        switch(zwischenspeicher)
        {
            case 1: soldiers++;
            break;
            case 2: farmers++;
            break;
            case 3: doctors++;
            break;
            case 4: engineers++;
            break;
            case 5: priests++;
            break;
            case 6: constructors++;
            break;
            case 7: scientists++;
            break;
            case 8: survivors++;
            break;
            default:;
        }
    }
    cout << "<--- Which kind of survivor do you want to assign to the squad?             >\n";
    if(soldiers)
        cout << "<    1 - Militant                                                           >\n";
    else
        cout << "<    No militants in the camp.                                              >\n";
    if(farmers)
        cout << "<    2 - Farmer                                                             >\n";
    else
        cout << "<    No farmers in the camp.                                                >\n";
    if(doctors)
        cout << "<    3 - Doctor                                                             >\n";
    else
        cout << "<    No doctors in the camp.                                                >\n";
    if(engineers)
        cout << "<    4 - Engineer                                                           >\n";
    else
        cout << "<    No engineers in the camp.                                              >\n";
    if(priests)
        cout << "<    5 - Therapist/Cleric                                                   >\n";
    else
        cout << "<    No therapists or clerics in the camp.                                  >\n";
    if(constructors)
        cout << "<    6 - Construction worker                                                >\n";
    else
        cout << "<    No construction workers in the camp.                                   >\n";
    if(scientists)
        cout << "<    7 - Scientist                                                          >\n";
    else
        cout << "<    No scientists in the camp.                                             >\n";
    if(survivors)
        cout << "<    8 - Regular survivor                                                   >\n";
    else
        cout << "<    No regular survivors in the camp.                                      >\n";
    cout << "<                                                                           >\n";
    cout << "<                                                                           >\n";
    cout << "<    Press any other key to get back                                        >\n";
    cout << "<                                                                           >\n";
    frameworkBottom();
    char menu;
    cin >> menu;
    switch(menu)
    {
        case '1': ClearScreen(),squadAssignment(squadnumber,membernumber,1);
        return;
        case '2': ClearScreen(),squadAssignment(squadnumber,membernumber,2);
        return;
        case '3': ClearScreen(),squadAssignment(squadnumber,membernumber,3);
        return;
        case '4': ClearScreen(),squadAssignment(squadnumber,membernumber,4);
        return;
        case '5': ClearScreen(),squadAssignment(squadnumber,membernumber,5);
        return;
        case '6': ClearScreen(),squadAssignment(squadnumber,membernumber,6);
        return;
        case '7': ClearScreen(),squadAssignment(squadnumber,membernumber,7);
        return;
        case '8': ClearScreen(),squadAssignment(squadnumber,membernumber,8);
        return;
        default: ClearScreen(),squadManager(existing, squadnumber);
    }
}

void squadAssignment(int squadnumber, int membernumber, int survivorClass)
{
    frameworkTop();
    int classmember[100];
    int k=0;
    int zwischenspeicher,levelspeicher;
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==0)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==9)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==8)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==7)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==6)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==5)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==4)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==3)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==2)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==1)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    switch(survivorClass)
    {
        case 1: cout << "<--- Militants in the camp:                                                 >\n";
        break;
        case 2: cout << "<--- Farmers in the camp:                                                   >\n";
        break;
        case 3: cout << "<--- Doctors in the camp:                                                   >\n";
        break;
        case 4: cout << "<--- Engineers in the camp:                                                 >\n";
        break;
        case 5: cout << "<--- Therapists/Clerics in the camp:                                        >\n";
        break;
        case 6: cout << "<--- Construction workers in the camp:                                      >\n";
        break;
        case 7: cout << "<--- Scientists in the camp:                                                >\n";
        break;
        case 8: cout << "<--- Regular survivors in the camp:                                         >\n";
        break;
        default:;
    }
    int page=0;
    int a=0,b=0;
    squadAssMenuDisplay(a,b,survivorClass,page);
    frameworkBottom();
    char menu;
    cin >> menu;
    switch(menu)
    {
        case '1':
        switch(squadnumber)
        {
            case 1:
            switch(membernumber)
            {
                case 1: speicher[167]=classmember[b];
            }
        }
        case '9':
        {
            page++;
            b+=8;
            if(b>99)
                b=99;
            else;
            a=0;
        }
        case '10':
        {
            page--;
            b-=8;
            if(b<0)
                b=0;
            else;
            a=0;
        }
        break;
        default:;
    }
}

void squadAssMenuDisplay(int& a, int& b, int survivorClass,int page)
{
    int classmember[100];
    int k=0;
    int zwischenspeicher,levelspeicher;
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==0)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==9)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==8)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==7)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==6)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==5)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==4)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==3)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==2)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(int i=51;i<149 && speicher[i];i++)
    {
        speicher[i]=zwischenspeicher;
        levelspeicher=zwischenspeicher/1000000;
        zwischenspeicher=zwischenspeicher/10000000;
        if(survivorClass==zwischenspeicher && levelspeicher==1)
        {
            classmember[k]=speicher[i];
            k++;
        }
    }
    for(;classmember[b]||a<9;b++,a++)
    {
        cout << "<    " << a << " - " << "Assign ";
        displaySurvivorStatus(classmember[b]);
    }
    for(;a<9;a++)
        cout << "<                                                                           >\n";
    cout << "<    9 - Next page                                                          >\n";
    if(page)
        cout << "<    10 - Previous page                                                     >\n";
    else;
    cout << "<    Press any other key to get back                                        >\n";
    cout << "<                                                                           >\n";
}

void survivorCreator()
{
    int randomizer;
    int i=51;
    int k=0;
    for(;speicher[i]||i==149;i++,k++);
    randomizer=rand()%100+1;
    if(randomizer<16)
        speicher[i]+=10;
    else
        if(randomizer<6)
            speicher[i]+=11;
        else;
    randomizer=rand()%50+50;
    speicher[i]+=randomizer*100;
    randomizer=rand()%50+50;
    speicher[i]+=randomizer*10000;
    randomizer=rand()%40+1;
    if(randomizer<11)
        speicher[i]+=1000000;
    else
        if(randomizer<21)
            speicher[i]+=2000000;
        else
            if(randomizer<31)
                speicher[i]+=3000000;
            else
                speicher[i]+=4000000;
    randomizer=rand()%100+1;
    if(randomizer<47)
        speicher[i]+=80000000;
    else
        if(randomizer<59)
            speicher[i]+=10000000;
        else
            if(randomizer<71)
                speicher[i]+=20000000;
            else
                if(randomizer<77)
                    speicher[i]+=30000000;
                else
                    if(randomizer<83)
                        speicher[i]+=40000000;
                    else
                        if(randomizer<89)
                            speicher[i]+=50000000;
                        else
                            if(randomizer<95)
                                speicher[i]+=60000000;
                            else
                                speicher[i]+=70000000;
    speicher[i]+=k*100000000;
    randomizer=rand()%2+1;
    if(randomizer==1)
        namensSpeicher[k]=1;
    else
        namensSpeicher[k]=2;
    if(randomizer==1)
    {
        randomizer=rand()%1000;
        namensSpeicher[k]+=randomizer*10;
    }
    else
    {
        randomizer=rand()%1000;
        namensSpeicher[k]+=randomizer*10;
    }
    randomizer=rand()%1000;
    namensSpeicher[k]+=randomizer*10000;
}

void displaySurvivorStatus(int survivorID)
{
    int ID,namensID,lange,zwischenspeicher;
    zwischenspeicher=survivorID;
    ID=survivorID/100000000;
    namensID=namensSpeicher[ID];
    if(namensID%10==1)
    {
        namensID=namensID/10;
        displayMaleName(namensID%1000);
    }
    else
    {
        namensID=namensID/10;
        displayFemaleName(namensID%1000);
    }
    lange=displayName.length();
    lange=11-lange;
    for(;lange;lange--)
        cout << " ";
    cout << displayName;
    cout << " ";
    namensID=namensID/1000;
    displaySurname(namensID);
    cout << displayName;
    lange=displayName.length();
    lange=11-lange;
    for(;lange;lange--)
        cout << " ";
    cout << "   LVL:";
    zwischenspeicher=survivorID;
    zwischenspeicher=zwischenspeicher/1000000;
    if(zwischenspeicher%10)
    {
        cout << zwischenspeicher%10;
        cout << " ";
    }
    else
        cout << "10";
    cout << " - HP:";
    zwischenspeicher=survivorID;
    zwischenspeicher=zwischenspeicher/100;
    cout << zwischenspeicher%100;
    if((zwischenspeicher%100)<10)
        cout << " ";
    else;
    cout << " - Morale:";
    zwischenspeicher=survivorID;
    zwischenspeicher=zwischenspeicher/10000;
    cout << zwischenspeicher%100;
    if((zwischenspeicher%100)<10)
        cout << " ";
    cout << "     >\n";
}


void displaySurname(int randomizer)
{
    switch(randomizer)
    {
    case 0: displayName="SMITH";
    break;
    case 1: displayName="JOHNSON";
    break;
    case 2: displayName="WILLIAMS";
    break;
    case 3: displayName="BROWN";
    break;
    case 4: displayName="JONES";
    break;
    case 5: displayName="MILLER";
    break;
    case 6: displayName="DAVIS";
    break;
    case 7: displayName="GARCIA";
    break;
    case 8: displayName="RODRIGUEZ";
    break;
    case 9: displayName="WILSON";
    break;
    case 10: displayName="MARTINEZ";
    break;
    case 11: displayName="ANDERSON";
    break;
    case 12: displayName="TAYLOR";
    break;
    case 13: displayName="THOMAS";
    break;
    case 14: displayName="HERNANDEZ";
    break;
    case 15: displayName="MOORE";
    break;
    case 16: displayName="MARTIN";
    break;
    case 17: displayName="JACKSON";
    break;
    case 18: displayName="THOMPSON";
    break;
    case 19: displayName="WHITE";
    break;
    case 20: displayName="LOPEZ";
    break;
    case 21: displayName="LEE";
    break;
    case 22: displayName="GONZALEZ";
    break;
    case 23: displayName="HARRIS";
    break;
    case 24: displayName="CLARK";
    break;
    case 25: displayName="LEWIS";
    break;
    case 26: displayName="ROBINSON";
    break;
    case 27: displayName="WALKER";
    break;
    case 28: displayName="PEREZ";
    break;
    case 29: displayName="HALL";
    break;
    case 30: displayName="YOUNG";
    break;
    case 31: displayName="ALLEN";
    break;
    case 32: displayName="SANCHEZ";
    break;
    case 33: displayName="WRIGHT";
    break;
    case 34: displayName="KING";
    break;
    case 35: displayName="SCOTT";
    break;
    case 36: displayName="GREEN";
    break;
    case 37: displayName="BAKER";
    break;
    case 38: displayName="ADAMS";
    break;
    case 39: displayName="NELSON";
    break;
    case 40: displayName="HILL";
    break;
    case 41: displayName="RAMIREZ";
    break;
    case 42: displayName="CAMPBELL";
    break;
    case 43: displayName="MITCHELL";
    break;
    case 44: displayName="ROBERTS";
    break;
    case 45: displayName="CARTER";
    break;
    case 46: displayName="PHILLIPS";
    break;
    case 47: displayName="EVANS";
    break;
    case 48: displayName="TURNER";
    break;
    case 49: displayName="TORRES";
    break;
    case 50: displayName="PARKER";
    break;
    case 51: displayName="COLLINS";
    break;
    case 52: displayName="EDWARDS";
    break;
    case 53: displayName="STEWART";
    break;
    case 54: displayName="FLORES";
    break;
    case 55: displayName="MORRIS";
    break;
    case 56: displayName="NGUYEN";
    break;
    case 57: displayName="MURPHY";
    break;
    case 58: displayName="RIVERA";
    break;
    case 59: displayName="COOK";
    break;
    case 60: displayName="ROGERS";
    break;
    case 61: displayName="MORGAN";
    break;
    case 62: displayName="PETERSON";
    break;
    case 63: displayName="COOPER";
    break;
    case 64: displayName="REED";
    break;
    case 65: displayName="BAILEY";
    break;
    case 66: displayName="BELL";
    break;
    case 67: displayName="GOMEZ";
    break;
    case 68: displayName="KELLY";
    break;
    case 69: displayName="HOWARD";
    break;
    case 70: displayName="WARD";
    break;
    case 71: displayName="COX";
    break;
    case 72: displayName="DIAZ";
    break;
    case 73: displayName="RICHARDSON";
    break;
    case 74: displayName="WOOD";
    break;
    case 75: displayName="WATSON";
    break;
    case 76: displayName="BROOKS";
    break;
    case 77: displayName="BENNETT";
    break;
    case 78: displayName="GRAY";
    break;
    case 79: displayName="JAMES";
    break;
    case 80: displayName="REYES";
    break;
    case 81: displayName="CRUZ";
    break;
    case 82: displayName="HUGHES";
    break;
    case 83: displayName="PRICE";
    break;
    case 84: displayName="MYERS";
    break;
    case 85: displayName="LONG";
    break;
    case 86: displayName="FOSTER";
    break;
    case 87: displayName="SANDERS";
    break;
    case 88: displayName="ROSS";
    break;
    case 89: displayName="MORALES";
    break;
    case 90: displayName="POWELL";
    break;
    case 91: displayName="SULLIVAN";
    break;
    case 92: displayName="RUSSELL";
    break;
    case 93: displayName="ORTIZ";
    break;
    case 94: displayName="JENKINS";
    break;
    case 95: displayName="GUTIERREZ";
    break;
    case 96: displayName="PERRY";
    break;
    case 97: displayName="BUTLER";
    break;
    case 98: displayName="BARNES";
    break;
    case 99: displayName="FISHER";
    break;
    case 100: displayName="HENDERSON";
    break;
    case 101: displayName="COLEMAN";
    break;
    case 102: displayName="SIMMONS";
    break;
    case 103: displayName="PATTERSON";
    break;
    case 104: displayName="JORDAN";
    break;
    case 105: displayName="REYNOLDS";
    break;
    case 106: displayName="HAMILTON";
    break;
    case 107: displayName="GRAHAM";
    break;
    case 108: displayName="KIM";
    break;
    case 109: displayName="GONZALES";
    break;
    case 110: displayName="ALEXANDER";
    break;
    case 111: displayName="RAMOS";
    break;
    case 112: displayName="WALLACE";
    break;
    case 113: displayName="GRIFFIN";
    break;
    case 114: displayName="WEST";
    break;
    case 115: displayName="COLE";
    break;
    case 116: displayName="HAYES";
    break;
    case 117: displayName="CHAVEZ";
    break;
    case 118: displayName="GIBSON";
    break;
    case 119: displayName="BRYANT";
    break;
    case 120: displayName="ELLIS";
    break;
    case 121: displayName="STEVENS";
    break;
    case 122: displayName="MURRAY";
    break;
    case 123: displayName="FORD";
    break;
    case 124: displayName="MARSHALL";
    break;
    case 125: displayName="OWENS";
    break;
    case 126: displayName="MCDONALD";
    break;
    case 127: displayName="HARRISON";
    break;
    case 128: displayName="RUIZ";
    break;
    case 129: displayName="KENNEDY";
    break;
    case 130: displayName="WELLS";
    break;
    case 131: displayName="ALVAREZ";
    break;
    case 132: displayName="WOODS";
    break;
    case 133: displayName="MENDOZA";
    break;
    case 134: displayName="CASTILLO";
    break;
    case 135: displayName="OLSON";
    break;
    case 136: displayName="WEBB";
    break;
    case 137: displayName="WASHINGTON";
    break;
    case 138: displayName="TUCKER";
    break;
    case 139: displayName="FREEMAN";
    break;
    case 140: displayName="BURNS";
    break;
    case 141: displayName="HENRY";
    break;
    case 142: displayName="VASQUEZ";
    break;
    case 143: displayName="SNYDER";
    break;
    case 144: displayName="SIMPSON";
    break;
    case 145: displayName="CRAWFORD";
    break;
    case 146: displayName="JIMENEZ";
    break;
    case 147: displayName="PORTER";
    break;
    case 148: displayName="MASON";
    break;
    case 149: displayName="SHAW";
    break;
    case 150: displayName="GORDON";
    break;
    case 151: displayName="WAGNER";
    break;
    case 152: displayName="HUNTER";
    break;
    case 153: displayName="ROMERO";
    break;
    case 154: displayName="HICKS";
    break;
    case 155: displayName="DIXON";
    break;
    case 156: displayName="HUNT";
    break;
    case 157: displayName="PALMER";
    break;
    case 158: displayName="ROBERTSON";
    break;
    case 159: displayName="BLACK";
    break;
    case 160: displayName="HOLMES";
    break;
    case 161: displayName="STONE";
    break;
    case 162: displayName="MEYER";
    break;
    case 163: displayName="BOYD";
    break;
    case 164: displayName="MILLS";
    break;
    case 165: displayName="WARREN";
    break;
    case 166: displayName="FOX";
    break;
    case 167: displayName="ROSE";
    break;
    case 168: displayName="RICE";
    break;
    case 169: displayName="MORENO";
    break;
    case 170: displayName="SCHMIDT";
    break;
    case 171: displayName="PATEL";
    break;
    case 172: displayName="FERGUSON";
    break;
    case 173: displayName="NICHOLS";
    break;
    case 174: displayName="HERRERA";
    break;
    case 175: displayName="MEDINA";
    break;
    case 176: displayName="RYAN";
    break;
    case 177: displayName="FERNANDEZ";
    break;
    case 178: displayName="WEAVER";
    break;
    case 179: displayName="DANIELS";
    break;
    case 180: displayName="STEPHENS";
    break;
    case 181: displayName="GARDNER";
    break;
    case 182: displayName="PAYNE";
    break;
    case 183: displayName="KELLEY";
    break;
    case 184: displayName="DUNN";
    break;
    case 185: displayName="PIERCE";
    break;
    case 186: displayName="ARNOLD";
    break;
    case 187: displayName="TRAN";
    break;
    case 188: displayName="SPENCER";
    break;
    case 189: displayName="PETERS";
    break;
    case 190: displayName="HAWKINS";
    break;
    case 191: displayName="GRANT";
    break;
    case 192: displayName="HANSEN";
    break;
    case 193: displayName="CASTRO";
    break;
    case 194: displayName="HOFFMAN";
    break;
    case 195: displayName="HART";
    break;
    case 196: displayName="ELLIOTT";
    break;
    case 197: displayName="CUNNINGHAM";
    break;
    case 198: displayName="KNIGHT";
    break;
    case 199: displayName="BRADLEY";
    break;
    case 200: displayName="CARROLL";
    break;
    case 201: displayName="HUDSON";
    break;
    case 202: displayName="DUNCAN";
    break;
    case 203: displayName="ARMSTRONG";
    break;
    case 204: displayName="BERRY";
    break;
    case 205: displayName="ANDREWS";
    break;
    case 206: displayName="JOHNSTON";
    break;
    case 207: displayName="RAY";
    break;
    case 208: displayName="LANE";
    break;
    case 209: displayName="RILEY";
    break;
    case 210: displayName="CARPENTER";
    break;
    case 211: displayName="PERKINS";
    break;
    case 212: displayName="AGUILAR";
    break;
    case 213: displayName="SILVA";
    break;
    case 214: displayName="RICHARDS";
    break;
    case 215: displayName="WILLIS";
    break;
    case 216: displayName="MATTHEWS";
    break;
    case 217: displayName="CHAPMAN";
    break;
    case 218: displayName="LAWRENCE";
    break;
    case 219: displayName="GARZA";
    break;
    case 220: displayName="VARGAS";
    break;
    case 221: displayName="WATKINS";
    break;
    case 222: displayName="WHEELER";
    break;
    case 223: displayName="LARSON";
    break;
    case 224: displayName="CARLSON";
    break;
    case 225: displayName="HARPER";
    break;
    case 226: displayName="GEORGE";
    break;
    case 227: displayName="GREENE";
    break;
    case 228: displayName="BURKE";
    break;
    case 229: displayName="GUZMAN";
    break;
    case 230: displayName="MORRISON";
    break;
    case 231: displayName="MUNOZ";
    break;
    case 232: displayName="JACOBS";
    break;
    case 233: displayName="OBRIEN";
    break;
    case 234: displayName="LAWSON";
    break;
    case 235: displayName="FRANKLIN";
    break;
    case 236: displayName="LYNCH";
    break;
    case 237: displayName="BISHOP";
    break;
    case 238: displayName="CARR";
    break;
    case 239: displayName="SALAZAR";
    break;
    case 240: displayName="AUSTIN";
    break;
    case 241: displayName="MENDEZ";
    break;
    case 242: displayName="GILBERT";
    break;
    case 243: displayName="JENSEN";
    break;
    case 244: displayName="WILLIAMSON";
    break;
    case 245: displayName="MONTGOMERY";
    break;
    case 246: displayName="HARVEY";
    break;
    case 247: displayName="OLIVER";
    break;
    case 248: displayName="HOWELL";
    break;
    case 249: displayName="DEAN";
    break;
    case 250: displayName="HANSON";
    break;
    case 251: displayName="WEBER";
    break;
    case 252: displayName="GARRETT";
    break;
    case 253: displayName="SIMS";
    break;
    case 254: displayName="BURTON";
    break;
    case 255: displayName="FULLER";
    break;
    case 256: displayName="SOTO";
    break;
    case 257: displayName="MCCOY";
    break;
    case 258: displayName="WELCH";
    break;
    case 259: displayName="CHEN";
    break;
    case 260: displayName="SCHULTZ";
    break;
    case 261: displayName="WALTERS";
    break;
    case 262: displayName="REID";
    break;
    case 263: displayName="FIELDS";
    break;
    case 264: displayName="WALSH";
    break;
    case 265: displayName="LITTLE";
    break;
    case 266: displayName="FOWLER";
    break;
    case 267: displayName="BOWMAN";
    break;
    case 268: displayName="DAVIDSON";
    break;
    case 269: displayName="MAY";
    break;
    case 270: displayName="DAY";
    break;
    case 271: displayName="SCHNEIDER";
    break;
    case 272: displayName="NEWMAN";
    break;
    case 273: displayName="BREWER";
    break;
    case 274: displayName="LUCAS";
    break;
    case 275: displayName="HOLLAND";
    break;
    case 276: displayName="WONG";
    break;
    case 277: displayName="BANKS";
    break;
    case 278: displayName="SANTOS";
    break;
    case 279: displayName="CURTIS";
    break;
    case 280: displayName="PEARSON";
    break;
    case 281: displayName="DELGADO";
    break;
    case 282: displayName="VALDEZ";
    break;
    case 283: displayName="PENA";
    break;
    case 284: displayName="RIOS";
    break;
    case 285: displayName="DOUGLAS";
    break;
    case 286: displayName="SANDOVAL";
    break;
    case 287: displayName="BARRETT";
    break;
    case 288: displayName="HOPKINS";
    break;
    case 289: displayName="KELLER";
    break;
    case 290: displayName="GUERRERO";
    break;
    case 291: displayName="STANLEY";
    break;
    case 292: displayName="BATES";
    break;
    case 293: displayName="ALVARADO";
    break;
    case 294: displayName="BECK";
    break;
    case 295: displayName="ORTEGA";
    break;
    case 296: displayName="WADE";
    break;
    case 297: displayName="ESTRADA";
    break;
    case 298: displayName="CONTRERAS";
    break;
    case 299: displayName="BARNETT";
    break;
    case 300: displayName="CALDWELL";
    break;
    case 301: displayName="SANTIAGO";
    break;
    case 302: displayName="LAMBERT";
    break;
    case 303: displayName="POWERS";
    break;
    case 304: displayName="CHAMBERS";
    break;
    case 305: displayName="NUNEZ";
    break;
    case 306: displayName="CRAIG";
    break;
    case 307: displayName="LEONARD";
    break;
    case 308: displayName="LOWE";
    break;
    case 309: displayName="RHODES";
    break;
    case 310: displayName="BYRD";
    break;
    case 311: displayName="GREGORY";
    break;
    case 312: displayName="SHELTON";
    break;
    case 313: displayName="FRAZIER";
    break;
    case 314: displayName="BECKER";
    break;
    case 315: displayName="MALDONADO";
    break;
    case 316: displayName="FLEMING";
    break;
    case 317: displayName="VEGA";
    break;
    case 318: displayName="SUTTON";
    break;
    case 319: displayName="COHEN";
    break;
    case 320: displayName="JENNINGS";
    break;
    case 321: displayName="PARKS";
    break;
    case 322: displayName="MCDANIEL";
    break;
    case 323: displayName="WATTS";
    break;
    case 324: displayName="BARKER";
    break;
    case 325: displayName="NORRIS";
    break;
    case 326: displayName="VAUGHN";
    break;
    case 327: displayName="VAZQUEZ";
    break;
    case 328: displayName="HOLT";
    break;
    case 329: displayName="SCHWARTZ";
    break;
    case 330: displayName="STEELE";
    break;
    case 331: displayName="BENSON";
    break;
    case 332: displayName="NEAL";
    break;
    case 333: displayName="DOMINGUEZ";
    break;
    case 334: displayName="HORTON";
    break;
    case 335: displayName="TERRY";
    break;
    case 336: displayName="WOLFE";
    break;
    case 337: displayName="HALE";
    break;
    case 338: displayName="LYONS";
    break;
    case 339: displayName="GRAVES";
    break;
    case 340: displayName="HAYNES";
    break;
    case 341: displayName="MILES";
    break;
    case 342: displayName="PARK";
    break;
    case 343: displayName="WARNER";
    break;
    case 344: displayName="PADILLA";
    break;
    case 345: displayName="BUSH";
    break;
    case 346: displayName="THORNTON";
    break;
    case 347: displayName="MCCARTHY";
    break;
    case 348: displayName="MANN";
    break;
    case 349: displayName="ZIMMERMAN";
    break;
    case 350: displayName="ERICKSON";
    break;
    case 351: displayName="FLETCHER";
    break;
    case 352: displayName="MCKINNEY";
    break;
    case 353: displayName="PAGE";
    break;
    case 354: displayName="DAWSON";
    break;
    case 355: displayName="JOSEPH";
    break;
    case 356: displayName="MARQUEZ";
    break;
    case 357: displayName="REEVES";
    break;
    case 358: displayName="KLEIN";
    break;
    case 359: displayName="ESPINOZA";
    break;
    case 360: displayName="BALDWIN";
    break;
    case 361: displayName="MORAN";
    break;
    case 362: displayName="LOVE";
    break;
    case 363: displayName="ROBBINS";
    break;
    case 364: displayName="HIGGINS";
    break;
    case 365: displayName="BALL";
    break;
    case 366: displayName="CORTEZ";
    break;
    case 367: displayName="LE";
    break;
    case 368: displayName="GRIFFITH";
    break;
    case 369: displayName="BOWEN";
    break;
    case 370: displayName="SHARP";
    break;
    case 371: displayName="CUMMINGS";
    break;
    case 372: displayName="RAMSEY";
    break;
    case 373: displayName="HARDY";
    break;
    case 374: displayName="SWANSON";
    break;
    case 375: displayName="BARBER";
    break;
    case 376: displayName="ACOSTA";
    break;
    case 377: displayName="LUNA";
    break;
    case 378: displayName="CHANDLER";
    break;
    case 379: displayName="BLAIR";
    break;
    case 380: displayName="DANIEL";
    break;
    case 381: displayName="CROSS";
    break;
    case 382: displayName="SIMON";
    break;
    case 383: displayName="DENNIS";
    break;
    case 384: displayName="OCONNOR";
    break;
    case 385: displayName="QUINN";
    break;
    case 386: displayName="GROSS";
    break;
    case 387: displayName="NAVARRO";
    break;
    case 388: displayName="MOSS";
    break;
    case 389: displayName="FITZGERALD";
    break;
    case 390: displayName="DOYLE";
    break;
    case 391: displayName="MCLAUGHLIN";
    break;
    case 392: displayName="ROJAS";
    break;
    case 393: displayName="RODGERS";
    break;
    case 394: displayName="STEVENSON";
    break;
    case 395: displayName="SINGH";
    break;
    case 396: displayName="YANG";
    break;
    case 397: displayName="FIGUEROA";
    break;
    case 398: displayName="HARMON";
    break;
    case 399: displayName="NEWTON";
    break;
    case 400: displayName="PAUL";
    break;
    case 401: displayName="MANNING";
    break;
    case 402: displayName="GARNER";
    break;
    case 403: displayName="MCGEE";
    break;
    case 404: displayName="REESE";
    break;
    case 405: displayName="FRANCIS";
    break;
    case 406: displayName="BURGESS";
    break;
    case 407: displayName="ADKINS";
    break;
    case 408: displayName="GOODMAN";
    break;
    case 409: displayName="CURRY";
    break;
    case 410: displayName="BRADY";
    break;
    case 411: displayName="CHRISTENSEN";
    break;
    case 412: displayName="POTTER";
    break;
    case 413: displayName="WALTON";
    break;
    case 414: displayName="GOODWIN";
    break;
    case 415: displayName="MULLINS";
    break;
    case 416: displayName="MOLINA";
    break;
    case 417: displayName="WEBSTER";
    break;
    case 418: displayName="FISCHER";
    break;
    case 419: displayName="CAMPOS";
    break;
    case 420: displayName="AVILA";
    break;
    case 421: displayName="SHERMAN";
    break;
    case 422: displayName="TODD";
    break;
    case 423: displayName="CHANG";
    break;
    case 424: displayName="BLAKE";
    break;
    case 425: displayName="MALONE";
    break;
    case 426: displayName="WOLF";
    break;
    case 427: displayName="HODGES";
    break;
    case 428: displayName="JUAREZ";
    break;
    case 429: displayName="GILL";
    break;
    case 430: displayName="FARMER";
    break;
    case 431: displayName="HINES";
    break;
    case 432: displayName="GALLAGHER";
    break;
    case 433: displayName="DURAN";
    break;
    case 434: displayName="HUBBARD";
    break;
    case 435: displayName="CANNON";
    break;
    case 436: displayName="MIRANDA";
    break;
    case 437: displayName="WANG";
    break;
    case 438: displayName="SAUNDERS";
    break;
    case 439: displayName="TATE";
    break;
    case 440: displayName="MACK";
    break;
    case 441: displayName="HAMMOND";
    break;
    case 442: displayName="CARRILLO";
    break;
    case 443: displayName="TOWNSEND";
    break;
    case 444: displayName="WISE";
    break;
    case 445: displayName="INGRAM";
    break;
    case 446: displayName="BARTON";
    break;
    case 447: displayName="MEJIA";
    break;
    case 448: displayName="AYALA";
    break;
    case 449: displayName="SCHROEDER";
    break;
    case 450: displayName="HAMPTON";
    break;
    case 451: displayName="ROWE";
    break;
    case 452: displayName="PARSONS";
    break;
    case 453: displayName="FRANK";
    break;
    case 454: displayName="WATERS";
    break;
    case 455: displayName="STRICKLAND";
    break;
    case 456: displayName="OSBORNE";
    break;
    case 457: displayName="MAXWELL";
    break;
    case 458: displayName="CHAN";
    break;
    case 459: displayName="DELEON";
    break;
    case 460: displayName="NORMAN";
    break;
    case 461: displayName="HARRINGTON";
    break;
    case 462: displayName="CASEY";
    break;
    case 463: displayName="PATTON";
    break;
    case 464: displayName="LOGAN";
    break;
    case 465: displayName="BOWERS";
    break;
    case 466: displayName="MUELLER";
    break;
    case 467: displayName="GLOVER";
    break;
    case 468: displayName="FLOYD";
    break;
    case 469: displayName="HARTMAN";
    break;
    case 470: displayName="BUCHANAN";
    break;
    case 471: displayName="COBB";
    break;
    case 472: displayName="FRENCH";
    break;
    case 473: displayName="KRAMER";
    break;
    case 474: displayName="MCCORMICK";
    break;
    case 475: displayName="CLARKE";
    break;
    case 476: displayName="TYLER";
    break;
    case 477: displayName="GIBBS";
    break;
    case 478: displayName="MOODY";
    break;
    case 479: displayName="CONNER";
    break;
    case 480: displayName="SPARKS";
    break;
    case 481: displayName="MCGUIRE";
    break;
    case 482: displayName="LEON";
    break;
    case 483: displayName="BAUER";
    break;
    case 484: displayName="NORTON";
    break;
    case 485: displayName="POPE";
    break;
    case 486: displayName="FLYNN";
    break;
    case 487: displayName="HOGAN";
    break;
    case 488: displayName="ROBLES";
    break;
    case 489: displayName="SALINAS";
    break;
    case 490: displayName="YATES";
    break;
    case 491: displayName="LINDSEY";
    break;
    case 492: displayName="LLOYD";
    break;
    case 493: displayName="MARSH";
    break;
    case 494: displayName="MCBRIDE";
    break;
    case 495: displayName="OWEN";
    break;
    case 496: displayName="SOLIS";
    break;
    case 497: displayName="PHAM";
    break;
    case 498: displayName="LANG";
    break;
    case 499: displayName="PRATT";
    break;
    case 500: displayName="LARA";
    break;
    case 501: displayName="BROCK";
    break;
    case 502: displayName="BALLARD";
    break;
    case 503: displayName="TRUJILLO";
    break;
    case 504: displayName="SHAFFER";
    break;
    case 505: displayName="DRAKE";
    break;
    case 506: displayName="ROMAN";
    break;
    case 507: displayName="AGUIRRE";
    break;
    case 508: displayName="MORTON";
    break;
    case 509: displayName="STOKES";
    break;
    case 510: displayName="LAMB";
    break;
    case 511: displayName="PACHECO";
    break;
    case 512: displayName="PATRICK";
    break;
    case 513: displayName="COCHRAN";
    break;
    case 514: displayName="SHEPHERD";
    break;
    case 515: displayName="CAIN";
    break;
    case 516: displayName="BURNETT";
    break;
    case 517: displayName="HESS";
    break;
    case 518: displayName="LI";
    break;
    case 519: displayName="CERVANTES";
    break;
    case 520: displayName="OLSEN";
    break;
    case 521: displayName="BRIGGS";
    break;
    case 522: displayName="OCHOA";
    break;
    case 523: displayName="CABRERA";
    break;
    case 524: displayName="VELASQUEZ";
    break;
    case 525: displayName="MONTOYA";
    break;
    case 526: displayName="ROTH";
    break;
    case 527: displayName="MEYERS";
    break;
    case 528: displayName="CARDENAS";
    break;
    case 529: displayName="FUENTES";
    break;
    case 530: displayName="WEISS";
    break;
    case 531: displayName="HOOVER";
    break;
    case 532: displayName="WILKINS";
    break;
    case 533: displayName="NICHOLSON";
    break;
    case 534: displayName="UNDERWOOD";
    break;
    case 535: displayName="SHORT";
    break;
    case 536: displayName="CARSON";
    break;
    case 537: displayName="MORROW";
    break;
    case 538: displayName="COLON";
    break;
    case 539: displayName="HOLLOWAY";
    break;
    case 540: displayName="SUMMERS";
    break;
    case 541: displayName="BRYAN";
    break;
    case 542: displayName="PETERSEN";
    break;
    case 543: displayName="MCKENZIE";
    break;
    case 544: displayName="SERRANO";
    break;
    case 545: displayName="WILCOX";
    break;
    case 546: displayName="CAREY";
    break;
    case 547: displayName="CLAYTON";
    break;
    case 548: displayName="POOLE";
    break;
    case 549: displayName="CALDERON";
    break;
    case 550: displayName="GALLEGOS";
    break;
    case 551: displayName="GREER";
    break;
    case 552: displayName="RIVAS";
    break;
    case 553: displayName="GUERRA";
    break;
    case 554: displayName="DECKER";
    break;
    case 555: displayName="COLLIER";
    break;
    case 556: displayName="WALL";
    break;
    case 557: displayName="WHITAKER";
    break;
    case 558: displayName="BASS";
    break;
    case 559: displayName="FLOWERS";
    break;
    case 560: displayName="DAVENPORT";
    break;
    case 561: displayName="CONLEY";
    break;
    case 562: displayName="HOUSTON";
    break;
    case 563: displayName="HUFF";
    break;
    case 564: displayName="COPELAND";
    break;
    case 565: displayName="HOOD";
    break;
    case 566: displayName="MONROE";
    break;
    case 567: displayName="MASSEY";
    break;
    case 568: displayName="ROBERSON";
    break;
    case 569: displayName="COMBS";
    break;
    case 570: displayName="FRANCO";
    break;
    case 571: displayName="LARSEN";
    break;
    case 572: displayName="PITTMAN";
    break;
    case 573: displayName="RANDALL";
    break;
    case 574: displayName="SKINNER";
    break;
    case 575: displayName="WILKINSON";
    break;
    case 576: displayName="KIRBY";
    break;
    case 577: displayName="CAMERON";
    break;
    case 578: displayName="BRIDGES";
    break;
    case 579: displayName="ANTHONY";
    break;
    case 580: displayName="RICHARD";
    break;
    case 581: displayName="KIRK";
    break;
    case 582: displayName="BRUCE";
    break;
    case 583: displayName="SINGLETON";
    break;
    case 584: displayName="MATHIS";
    break;
    case 585: displayName="BRADFORD";
    break;
    case 586: displayName="BOONE";
    break;
    case 587: displayName="ABBOTT";
    break;
    case 588: displayName="CHARLES";
    break;
    case 589: displayName="ALLISON";
    break;
    case 590: displayName="SWEENEY";
    break;
    case 591: displayName="ATKINSON";
    break;
    case 592: displayName="HORN";
    break;
    case 593: displayName="JEFFERSON";
    break;
    case 594: displayName="ROSALES";
    break;
    case 595: displayName="YORK";
    break;
    case 596: displayName="CHRISTIAN";
    break;
    case 597: displayName="PHELPS";
    break;
    case 598: displayName="FARRELL";
    break;
    case 599: displayName="CASTANEDA";
    break;
    case 600: displayName="NASH";
    break;
    case 601: displayName="DICKERSON";
    break;
    case 602: displayName="BOND";
    break;
    case 603: displayName="WYATT";
    break;
    case 604: displayName="FOLEY";
    break;
    case 605: displayName="CHASE";
    break;
    case 606: displayName="GATES";
    break;
    case 607: displayName="VINCENT";
    break;
    case 608: displayName="MATHEWS";
    break;
    case 609: displayName="HODGE";
    break;
    case 610: displayName="GARRISON";
    break;
    case 611: displayName="TREVINO";
    break;
    case 612: displayName="VILLARREAL";
    break;
    case 613: displayName="HEATH";
    break;
    case 614: displayName="DALTON";
    break;
    case 615: displayName="VALENCIA";
    break;
    case 616: displayName="CALLAHAN";
    break;
    case 617: displayName="HENSLEY";
    break;
    case 618: displayName="ATKINS";
    break;
    case 619: displayName="HUFFMAN";
    break;
    case 620: displayName="ROY";
    break;
    case 621: displayName="BOYER";
    break;
    case 622: displayName="SHIELDS";
    break;
    case 623: displayName="LIN";
    break;
    case 624: displayName="HANCOCK";
    break;
    case 625: displayName="GRIMES";
    break;
    case 626: displayName="GLENN";
    break;
    case 627: displayName="CLINE";
    break;
    case 628: displayName="DELACRUZ";
    break;
    case 629: displayName="CAMACHO";
    break;
    case 630: displayName="DILLON";
    break;
    case 631: displayName="PARRISH";
    break;
    case 632: displayName="ONEILL";
    break;
    case 633: displayName="MELTON";
    break;
    case 634: displayName="BOOTH";
    break;
    case 635: displayName="KANE";
    break;
    case 636: displayName="BERG";
    break;
    case 637: displayName="HARRELL";
    break;
    case 638: displayName="PITTS";
    break;
    case 639: displayName="SAVAGE";
    break;
    case 640: displayName="WIGGINS";
    break;
    case 641: displayName="BRENNAN";
    break;
    case 642: displayName="SALAS";
    break;
    case 643: displayName="MARKS";
    break;
    case 644: displayName="RUSSO";
    break;
    case 645: displayName="SAWYER";
    break;
    case 646: displayName="BAXTER";
    break;
    case 647: displayName="GOLDEN";
    break;
    case 648: displayName="HUTCHINSON";
    break;
    case 649: displayName="LIU";
    break;
    case 650: displayName="WALTER";
    break;
    case 651: displayName="MCDOWELL";
    break;
    case 652: displayName="WILEY";
    break;
    case 653: displayName="RICH";
    break;
    case 654: displayName="HUMPHREY";
    break;
    case 655: displayName="JOHNS";
    break;
    case 656: displayName="KOCH";
    break;
    case 657: displayName="SUAREZ";
    break;
    case 658: displayName="HOBBS";
    break;
    case 659: displayName="BEARD";
    break;
    case 660: displayName="GILMORE";
    break;
    case 661: displayName="IBARRA";
    break;
    case 662: displayName="KEITH";
    break;
    case 663: displayName="MACIAS";
    break;
    case 664: displayName="KHAN";
    break;
    case 665: displayName="ANDRADE";
    break;
    case 666: displayName="WARE";
    break;
    case 667: displayName="STEPHENSON";
    break;
    case 668: displayName="HENSON";
    break;
    case 669: displayName="WILKERSON";
    break;
    case 670: displayName="DYER";
    break;
    case 671: displayName="MCCLURE";
    break;
    case 672: displayName="BLACKWELL";
    break;
    case 673: displayName="MERCADO";
    break;
    case 674: displayName="TANNER";
    break;
    case 675: displayName="EATON";
    break;
    case 676: displayName="CLAY";
    break;
    case 677: displayName="BARRON";
    break;
    case 678: displayName="BEASLEY";
    break;
    case 679: displayName="ONEAL";
    break;
    case 680: displayName="PRESTON";
    break;
    case 681: displayName="SMALL";
    break;
    case 682: displayName="WU";
    break;
    case 683: displayName="ZAMORA";
    break;
    case 684: displayName="MACDONALD";
    break;
    case 685: displayName="VANCE";
    break;
    case 686: displayName="SNOW";
    break;
    case 687: displayName="MCCLAIN";
    break;
    case 688: displayName="STAFFORD";
    break;
    case 689: displayName="OROZCO";
    break;
    case 690: displayName="BARRY";
    break;
    case 691: displayName="ENGLISH";
    break;
    case 692: displayName="SHANNON";
    break;
    case 693: displayName="KLINE";
    break;
    case 694: displayName="JACOBSON";
    break;
    case 695: displayName="WOODARD";
    break;
    case 696: displayName="HUANG";
    break;
    case 697: displayName="KEMP";
    break;
    case 698: displayName="MOSLEY";
    break;
    case 699: displayName="PRINCE";
    break;
    case 700: displayName="MERRITT";
    break;
    case 701: displayName="HURST";
    break;
    case 702: displayName="VILLANUEVA";
    break;
    case 703: displayName="ROACH";
    break;
    case 704: displayName="NOLAN";
    break;
    case 705: displayName="LAM";
    break;
    case 706: displayName="YODER";
    break;
    case 707: displayName="MCCULLOUGH";
    break;
    case 708: displayName="LESTER";
    break;
    case 709: displayName="SANTANA";
    break;
    case 710: displayName="VALENZUELA";
    break;
    case 711: displayName="WINTERS";
    break;
    case 712: displayName="BARRERA";
    break;
    case 713: displayName="LEACH";
    break;
    case 714: displayName="ORR";
    break;
    case 715: displayName="BERGER";
    break;
    case 716: displayName="MCKEE";
    break;
    case 717: displayName="STRONG";
    break;
    case 718: displayName="CONWAY";
    break;
    case 719: displayName="STEIN";
    break;
    case 720: displayName="WHITEHEAD";
    break;
    case 721: displayName="BULLOCK";
    break;
    case 722: displayName="ESCOBAR";
    break;
    case 723: displayName="KNOX";
    break;
    case 724: displayName="MEADOWS";
    break;
    case 725: displayName="SOLOMON";
    break;
    case 726: displayName="VELEZ";
    break;
    case 727: displayName="ODONNELL";
    break;
    case 728: displayName="KERR";
    break;
    case 729: displayName="STOUT";
    break;
    case 730: displayName="BLANKENSHIP";
    break;
    case 731: displayName="BROWNING";
    break;
    case 732: displayName="KENT";
    break;
    case 733: displayName="LOZANO";
    break;
    case 734: displayName="BARTLETT";
    break;
    case 735: displayName="PRUITT";
    break;
    case 736: displayName="BUCK";
    break;
    case 737: displayName="BARR";
    break;
    case 738: displayName="GAINES";
    break;
    case 739: displayName="DURHAM";
    break;
    case 740: displayName="GENTRY";
    break;
    case 741: displayName="MCINTYRE";
    break;
    case 742: displayName="SLOAN";
    break;
    case 743: displayName="MELENDEZ";
    break;
    case 744: displayName="ROCHA";
    break;
    case 745: displayName="HERMAN";
    break;
    case 746: displayName="SEXTON";
    break;
    case 747: displayName="MOON";
    break;
    case 748: displayName="HENDRICKS";
    break;
    case 749: displayName="RANGEL";
    break;
    case 750: displayName="STARK";
    break;
    case 751: displayName="LOWERY";
    break;
    case 752: displayName="HARDIN";
    break;
    case 753: displayName="HULL";
    break;
    case 754: displayName="SELLERS";
    break;
    case 755: displayName="ELLISON";
    break;
    case 756: displayName="CALHOUN";
    break;
    case 757: displayName="GILLESPIE";
    break;
    case 758: displayName="MORA";
    break;
    case 759: displayName="KNAPP";
    break;
    case 760: displayName="MCCALL";
    break;
    case 761: displayName="MORSE";
    break;
    case 762: displayName="DORSEY";
    break;
    case 763: displayName="WEEKS";
    break;
    case 764: displayName="NIELSEN";
    break;
    case 765: displayName="LIVINGSTON";
    break;
    case 766: displayName="LEBLANC";
    break;
    case 767: displayName="MCLEAN";
    break;
    case 768: displayName="BRADSHAW";
    break;
    case 769: displayName="GLASS";
    break;
    case 770: displayName="MIDDLETON";
    break;
    case 771: displayName="BUCKLEY";
    break;
    case 772: displayName="SCHAEFER";
    break;
    case 773: displayName="FROST";
    break;
    case 774: displayName="HOWE";
    break;
    case 775: displayName="HOUSE";
    break;
    case 776: displayName="MCINTOSH";
    break;
    case 777: displayName="HO";
    break;
    case 778: displayName="PENNINGTON";
    break;
    case 779: displayName="REILLY";
    break;
    case 780: displayName="HEBERT";
    break;
    case 781: displayName="MCFARLAND";
    break;
    case 782: displayName="HICKMAN";
    break;
    case 783: displayName="NOBLE";
    break;
    case 784: displayName="SPEARS";
    break;
    case 785: displayName="CONRAD";
    break;
    case 786: displayName="ARIAS";
    break;
    case 787: displayName="GALVAN";
    break;
    case 788: displayName="VELAZQUEZ";
    break;
    case 789: displayName="HUYNH";
    break;
    case 790: displayName="FREDERICK";
    break;
    case 791: displayName="RANDOLPH";
    break;
    case 792: displayName="CANTU";
    break;
    case 793: displayName="FITZPATRICK";
    break;
    case 794: displayName="MAHONEY";
    break;
    case 795: displayName="PECK";
    break;
    case 796: displayName="VILLA";
    break;
    case 797: displayName="MICHAEL";
    break;
    case 798: displayName="DONOVAN";
    break;
    case 799: displayName="MCCONNELL";
    break;
    case 800: displayName="WALLS";
    break;
    case 801: displayName="BOYLE";
    break;
    case 802: displayName="MAYER";
    break;
    case 803: displayName="ZUNIGA";
    break;
    case 804: displayName="GILES";
    break;
    case 805: displayName="PINEDA";
    break;
    case 806: displayName="PACE";
    break;
    case 807: displayName="HURLEY";
    break;
    case 808: displayName="MAYS";
    break;
    case 809: displayName="MCMILLAN";
    break;
    case 810: displayName="CROSBY";
    break;
    case 811: displayName="AYERS";
    break;
    case 812: displayName="CASE";
    break;
    case 813: displayName="BENTLEY";
    break;
    case 814: displayName="SHEPARD";
    break;
    case 815: displayName="EVERETT";
    break;
    case 816: displayName="PUGH";
    break;
    case 817: displayName="DAVID";
    break;
    case 818: displayName="MCMAHON";
    break;
    case 819: displayName="DUNLAP";
    break;
    case 820: displayName="BENDER";
    break;
    case 821: displayName="HAHN";
    break;
    case 822: displayName="HARDING";
    break;
    case 823: displayName="ACEVEDO";
    break;
    case 824: displayName="RAYMOND";
    break;
    case 825: displayName="BLACKBURN";
    break;
    case 826: displayName="DUFFY";
    break;
    case 827: displayName="LANDRY";
    break;
    case 828: displayName="DOUGHERTY";
    break;
    case 829: displayName="BAUTISTA";
    break;
    case 830: displayName="SHAH";
    break;
    case 831: displayName="POTTS";
    break;
    case 832: displayName="ARROYO";
    break;
    case 833: displayName="VALENTINE";
    break;
    case 834: displayName="MEZA";
    break;
    case 835: displayName="GOULD";
    break;
    case 836: displayName="VAUGHAN";
    break;
    case 837: displayName="FRY";
    break;
    case 838: displayName="RUSH";
    break;
    case 839: displayName="AVERY";
    break;
    case 840: displayName="HERRING";
    break;
    case 841: displayName="DODSON";
    break;
    case 842: displayName="CLEMENTS";
    break;
    case 843: displayName="SAMPSON";
    break;
    case 844: displayName="TAPIA";
    break;
    case 845: displayName="BEAN";
    break;
    case 846: displayName="LYNN";
    break;
    case 847: displayName="CRANE";
    break;
    case 848: displayName="FARLEY";
    break;
    case 849: displayName="CISNEROS";
    break;
    case 850: displayName="BENTON";
    break;
    case 851: displayName="ASHLEY";
    break;
    case 852: displayName="MCKAY";
    break;
    case 853: displayName="FINLEY";
    break;
    case 854: displayName="BEST";
    break;
    case 855: displayName="BLEVINS";
    break;
    case 856: displayName="FRIEDMAN";
    break;
    case 857: displayName="MOSES";
    break;
    case 858: displayName="SOSA";
    break;
    case 859: displayName="BLANCHARD";
    break;
    case 860: displayName="HUBER";
    break;
    case 861: displayName="FRYE";
    break;
    case 862: displayName="KRUEGER";
    break;
    case 863: displayName="BERNARD";
    break;
    case 864: displayName="ROSARIO";
    break;
    case 865: displayName="RUBIO";
    break;
    case 866: displayName="MULLEN";
    break;
    case 867: displayName="BENJAMIN";
    break;
    case 868: displayName="HALEY";
    break;
    case 869: displayName="CHUNG";
    break;
    case 870: displayName="MOYER";
    break;
    case 871: displayName="CHOI";
    break;
    case 872: displayName="HORNE";
    break;
    case 873: displayName="YU";
    break;
    case 874: displayName="WOODWARD";
    break;
    case 875: displayName="ALI";
    break;
    case 876: displayName="NIXON";
    break;
    case 877: displayName="HAYDEN";
    break;
    case 878: displayName="RIVERS";
    break;
    case 879: displayName="ESTES";
    break;
    case 880: displayName="MCCARTY";
    break;
    case 881: displayName="RICHMOND";
    break;
    case 882: displayName="STUART";
    break;
    case 883: displayName="MAYNARD";
    break;
    case 884: displayName="BRANDT";
    break;
    case 885: displayName="OCONNELL";
    break;
    case 886: displayName="HANNA";
    break;
    case 887: displayName="SANFORD";
    break;
    case 888: displayName="SHEPPARD";
    break;
    case 889: displayName="CHURCH";
    break;
    case 890: displayName="BURCH";
    break;
    case 891: displayName="LEVY";
    break;
    case 892: displayName="RASMUSSEN";
    break;
    case 893: displayName="COFFEY";
    break;
    case 894: displayName="PONCE";
    break;
    case 895: displayName="FAULKNER";
    break;
    case 896: displayName="DONALDSON";
    break;
    case 897: displayName="SCHMITT";
    break;
    case 898: displayName="NOVAK";
    break;
    case 899: displayName="COSTA";
    break;
    case 900: displayName="MONTES";
    break;
    case 901: displayName="BOOKER";
    break;
    case 902: displayName="CORDOVA";
    break;
    case 903: displayName="WALLER";
    break;
    case 904: displayName="ARELLANO";
    break;
    case 905: displayName="MADDOX";
    break;
    case 906: displayName="MATA";
    break;
    case 907: displayName="BONILLA";
    break;
    case 908: displayName="STANTON";
    break;
    case 909: displayName="COMPTON";
    break;
    case 910: displayName="KAUFMAN";
    break;
    case 911: displayName="DUDLEY";
    break;
    case 912: displayName="MCPHERSON";
    break;
    case 913: displayName="BELTRAN";
    break;
    case 914: displayName="DICKSON";
    break;
    case 915: displayName="MCCANN";
    break;
    case 916: displayName="VILLEGAS";
    break;
    case 917: displayName="PROCTOR";
    break;
    case 918: displayName="HESTER";
    break;
    case 919: displayName="CANTRELL";
    break;
    case 920: displayName="DAUGHERTY";
    break;
    case 921: displayName="CHERRY";
    break;
    case 922: displayName="BRAY";
    break;
    case 923: displayName="DAVILA";
    break;
    case 924: displayName="ROWLAND";
    break;
    case 925: displayName="LEVINE";
    break;
    case 926: displayName="MADDEN";
    break;
    case 927: displayName="SPENCE";
    break;
    case 928: displayName="GOOD";
    break;
    case 929: displayName="IRWIN";
    break;
    case 930: displayName="WERNER";
    break;
    case 931: displayName="KRAUSE";
    break;
    case 932: displayName="PETTY";
    break;
    case 933: displayName="WHITNEY";
    break;
    case 934: displayName="BAIRD";
    break;
    case 935: displayName="HOOPER";
    break;
    case 936: displayName="POLLARD";
    break;
    case 937: displayName="ZAVALA";
    break;
    case 938: displayName="JARVIS";
    break;
    case 939: displayName="HOLDEN";
    break;
    case 940: displayName="HAAS";
    break;
    case 941: displayName="HENDRIX";
    break;
    case 942: displayName="MCGRATH";
    break;
    case 943: displayName="BIRD";
    break;
    case 944: displayName="LUCERO";
    break;
    case 945: displayName="TERRELL";
    break;
    case 946: displayName="RIGGS";
    break;
    case 947: displayName="JOYCE";
    break;
    case 948: displayName="MERCER";
    break;
    case 949: displayName="ROLLINS";
    break;
    case 950: displayName="GALLOWAY";
    break;
    case 951: displayName="DUKE";
    break;
    case 952: displayName="ODOM";
    break;
    case 953: displayName="ANDERSEN";
    break;
    case 954: displayName="DOWNS";
    break;
    case 955: displayName="HATFIELD";
    break;
    case 956: displayName="BENITEZ";
    break;
    case 957: displayName="ARCHER";
    break;
    case 958: displayName="HUERTA";
    break;
    case 959: displayName="TRAVIS";
    break;
    case 960: displayName="MCNEIL";
    break;
    case 961: displayName="HINTON";
    break;
    case 962: displayName="ZHANG";
    break;
    case 963: displayName="HAYS";
    break;
    case 964: displayName="MAYO";
    break;
    case 965: displayName="FRITZ";
    break;
    case 966: displayName="BRANCH";
    break;
    case 967: displayName="MOONEY";
    break;
    case 968: displayName="EWING";
    break;
    case 969: displayName="RITTER";
    break;
    case 970: displayName="ESPARZA";
    break;
    case 971: displayName="FREY";
    break;
    case 972: displayName="BRAUN";
    break;
    case 973: displayName="GAY";
    break;
    case 974: displayName="RIDDLE";
    break;
    case 975: displayName="HANEY";
    break;
    case 976: displayName="KAISER";
    break;
    case 977: displayName="HOLDER";
    break;
    case 978: displayName="CHANEY";
    break;
    case 979: displayName="MCKNIGHT";
    break;
    case 980: displayName="GAMBLE";
    break;
    case 981: displayName="VANG";
    break;
    case 982: displayName="COOLEY";
    break;
    case 983: displayName="CARNEY";
    break;
    case 984: displayName="COWAN";
    break;
    case 985: displayName="FORBES";
    break;
    case 986: displayName="FERRELL";
    break;
    case 987: displayName="DAVIES";
    break;
    case 988: displayName="BARAJAS";
    break;
    case 989: displayName="SHEA";
    break;
    case 990: displayName="OSBORN";
    break;
    case 991: displayName="BRIGHT";
    break;
    case 992: displayName="CUEVAS";
    break;
    case 993: displayName="BOLTON";
    break;
    case 994: displayName="MURILLO";
    break;
    case 995: displayName="LUTZ";
    break;
    case 996: displayName="DUARTE";
    break;
    case 997: displayName="KIDD";
    break;
    case 998: displayName="KEY";
    break;
    case 999: displayName="COOKE";
    break;
    }
}

void displayMaleName(int randomizer)
{
    switch(randomizer)
    {
    case 0: displayName="JAMES";
    break;
    case 1: displayName="JOHN";
    break;
    case 2: displayName="ROBERT";
    break;
    case 3: displayName="MICHAEL";
    break;
    case 4: displayName="WILLIAM";
    break;
    case 5: displayName="DAVID";
    break;
    case 6: displayName="RICHARD";
    break;
    case 7: displayName="CHARLES";
    break;
    case 8: displayName="JOSEPH";
    break;
    case 9: displayName="THOMAS";
    break;
    case 10: displayName="CHRISTOPHER";
    break;
    case 11: displayName="DANIEL";
    break;
    case 12: displayName="PAUL";
    break;
    case 13: displayName="MARK";
    break;
    case 14: displayName="DONALD";
    break;
    case 15: displayName="GEORGE";
    break;
    case 16: displayName="KENNETH";
    break;
    case 17: displayName="STEVEN";
    break;
    case 18: displayName="EDWARD";
    break;
    case 19: displayName="BRIAN";
    break;
    case 20: displayName="RONALD";
    break;
    case 21: displayName="ANTHONY";
    break;
    case 22: displayName="KEVIN";
    break;
    case 23: displayName="JASON";
    break;
    case 24: displayName="MATTHEW";
    break;
    case 25: displayName="GARY";
    break;
    case 26: displayName="TIMOTHY";
    break;
    case 27: displayName="JOSE";
    break;
    case 28: displayName="LARRY";
    break;
    case 29: displayName="JEFFREY";
    break;
    case 30: displayName="FRANK";
    break;
    case 31: displayName="SCOTT";
    break;
    case 32: displayName="ERIC";
    break;
    case 33: displayName="STEPHEN";
    break;
    case 34: displayName="ANDREW";
    break;
    case 35: displayName="RAYMOND";
    break;
    case 36: displayName="GREGORY";
    break;
    case 37: displayName="JOSHUA";
    break;
    case 38: displayName="JERRY";
    break;
    case 39: displayName="DENNIS";
    break;
    case 40: displayName="WALTER";
    break;
    case 41: displayName="PATRICK";
    break;
    case 42: displayName="PETER";
    break;
    case 43: displayName="HAROLD";
    break;
    case 44: displayName="DOUGLAS";
    break;
    case 45: displayName="HENRY";
    break;
    case 46: displayName="CARL";
    break;
    case 47: displayName="ARTHUR";
    break;
    case 48: displayName="RYAN";
    break;
    case 49: displayName="ROGER";
    break;
    case 50: displayName="JOE";
    break;
    case 51: displayName="JUAN";
    break;
    case 52: displayName="JACK";
    break;
    case 53: displayName="ALBERT";
    break;
    case 54: displayName="JONATHAN";
    break;
    case 55: displayName="JUSTIN";
    break;
    case 56: displayName="TERRY";
    break;
    case 57: displayName="GERALD";
    break;
    case 58: displayName="KEITH";
    break;
    case 59: displayName="SAMUEL";
    break;
    case 60: displayName="WILLIE";
    break;
    case 61: displayName="RALPH";
    break;
    case 62: displayName="LAWRENCE";
    break;
    case 63: displayName="NICHOLAS";
    break;
    case 64: displayName="ROY";
    break;
    case 65: displayName="BENJAMIN";
    break;
    case 66: displayName="BRUCE";
    break;
    case 67: displayName="BRANDON";
    break;
    case 68: displayName="ADAM";
    break;
    case 69: displayName="HARRY";
    break;
    case 70: displayName="FRED";
    break;
    case 71: displayName="WAYNE";
    break;
    case 72: displayName="BILLY";
    break;
    case 73: displayName="STEVE";
    break;
    case 74: displayName="LOUIS";
    break;
    case 75: displayName="JEREMY";
    break;
    case 76: displayName="AARON";
    break;
    case 77: displayName="RANDY";
    break;
    case 78: displayName="HOWARD";
    break;
    case 79: displayName="EUGENE";
    break;
    case 80: displayName="CARLOS";
    break;
    case 81: displayName="RUSSELL";
    break;
    case 82: displayName="BOBBY";
    break;
    case 83: displayName="VICTOR";
    break;
    case 84: displayName="MARTIN";
    break;
    case 85: displayName="ERNEST";
    break;
    case 86: displayName="PHILLIP";
    break;
    case 87: displayName="TODD";
    break;
    case 88: displayName="JESSE";
    break;
    case 89: displayName="CRAIG";
    break;
    case 90: displayName="ALAN";
    break;
    case 91: displayName="SHAWN";
    break;
    case 92: displayName="CLARENCE";
    break;
    case 93: displayName="SEAN";
    break;
    case 94: displayName="PHILIP";
    break;
    case 95: displayName="CHRIS";
    break;
    case 96: displayName="JOHNNY";
    break;
    case 97: displayName="EARL";
    break;
    case 98: displayName="JIMMY";
    break;
    case 99: displayName="ANTONIO";
    break;
    case 100: displayName="DANNY";
    break;
    case 101: displayName="BRYAN";
    break;
    case 102: displayName="TONY";
    break;
    case 103: displayName="LUIS";
    break;
    case 104: displayName="MIKE";
    break;
    case 105: displayName="STANLEY";
    break;
    case 106: displayName="LEONARD";
    break;
    case 107: displayName="NATHAN";
    break;
    case 108: displayName="DALE";
    break;
    case 109: displayName="MANUEL";
    break;
    case 110: displayName="RODNEY";
    break;
    case 111: displayName="CURTIS";
    break;
    case 112: displayName="NORMAN";
    break;
    case 113: displayName="ALLEN";
    break;
    case 114: displayName="MARVIN";
    break;
    case 115: displayName="VINCENT";
    break;
    case 116: displayName="GLENN";
    break;
    case 117: displayName="JEFFERY";
    break;
    case 118: displayName="TRAVIS";
    break;
    case 119: displayName="JEFF";
    break;
    case 120: displayName="CHAD";
    break;
    case 121: displayName="JACOB";
    break;
    case 122: displayName="LEE";
    break;
    case 123: displayName="MELVIN";
    break;
    case 124: displayName="ALFRED";
    break;
    case 125: displayName="KYLE";
    break;
    case 126: displayName="FRANCIS";
    break;
    case 127: displayName="BRADLEY";
    break;
    case 128: displayName="JESUS";
    break;
    case 129: displayName="HERBERT";
    break;
    case 130: displayName="FREDERICK";
    break;
    case 131: displayName="RAY";
    break;
    case 132: displayName="JOEL";
    break;
    case 133: displayName="EDWIN";
    break;
    case 134: displayName="DON";
    break;
    case 135: displayName="EDDIE";
    break;
    case 136: displayName="RICKY";
    break;
    case 137: displayName="TROY";
    break;
    case 138: displayName="RANDALL";
    break;
    case 139: displayName="BARRY";
    break;
    case 140: displayName="ALEXANDER";
    break;
    case 141: displayName="BERNARD";
    break;
    case 142: displayName="MARIO";
    break;
    case 143: displayName="LEROY";
    break;
    case 144: displayName="FRANCISCO";
    break;
    case 145: displayName="MARCUS";
    break;
    case 146: displayName="MICHEAL";
    break;
    case 147: displayName="THEODORE";
    break;
    case 148: displayName="CLIFFORD";
    break;
    case 149: displayName="MIGUEL";
    break;
    case 150: displayName="OSCAR";
    break;
    case 151: displayName="JAY";
    break;
    case 152: displayName="JIM";
    break;
    case 153: displayName="TOM";
    break;
    case 154: displayName="CALVIN";
    break;
    case 155: displayName="ALEX";
    break;
    case 156: displayName="JON";
    break;
    case 157: displayName="RONNIE";
    break;
    case 158: displayName="BILL";
    break;
    case 159: displayName="LLOYD";
    break;
    case 160: displayName="TOMMY";
    break;
    case 161: displayName="LEON";
    break;
    case 162: displayName="DEREK";
    break;
    case 163: displayName="WARREN";
    break;
    case 164: displayName="DARRELL";
    break;
    case 165: displayName="JEROME";
    break;
    case 166: displayName="FLOYD";
    break;
    case 167: displayName="LEO";
    break;
    case 168: displayName="ALVIN";
    break;
    case 169: displayName="TIM";
    break;
    case 170: displayName="WESLEY";
    break;
    case 171: displayName="GORDON";
    break;
    case 172: displayName="DEAN";
    break;
    case 173: displayName="GREG";
    break;
    case 174: displayName="JORGE";
    break;
    case 175: displayName="DUSTIN";
    break;
    case 176: displayName="PEDRO";
    break;
    case 177: displayName="DERRICK";
    break;
    case 178: displayName="DAN";
    break;
    case 179: displayName="LEWIS";
    break;
    case 180: displayName="ZACHARY";
    break;
    case 181: displayName="COREY";
    break;
    case 182: displayName="HERMAN";
    break;
    case 183: displayName="MAURICE";
    break;
    case 184: displayName="VERNON";
    break;
    case 185: displayName="ROBERTO";
    break;
    case 186: displayName="CLYDE";
    break;
    case 187: displayName="GLEN";
    break;
    case 188: displayName="HECTOR";
    break;
    case 189: displayName="SHANE";
    break;
    case 190: displayName="RICARDO";
    break;
    case 191: displayName="SAM";
    break;
    case 192: displayName="RICK";
    break;
    case 193: displayName="LESTER";
    break;
    case 194: displayName="BRENT";
    break;
    case 195: displayName="RAMON";
    break;
    case 196: displayName="CHARLIE";
    break;
    case 197: displayName="TYLER";
    break;
    case 198: displayName="GILBERT";
    break;
    case 199: displayName="GENE";
    break;
    case 200: displayName="MARC";
    break;
    case 201: displayName="REGINALD";
    break;
    case 202: displayName="RUBEN";
    break;
    case 203: displayName="BRETT";
    break;
    case 204: displayName="ANGEL";
    break;
    case 205: displayName="NATHANIEL";
    break;
    case 206: displayName="RAFAEL";
    break;
    case 207: displayName="LESLIE";
    break;
    case 208: displayName="EDGAR";
    break;
    case 209: displayName="MILTON";
    break;
    case 210: displayName="RAUL";
    break;
    case 211: displayName="BEN";
    break;
    case 212: displayName="CHESTER";
    break;
    case 213: displayName="CECIL";
    break;
    case 214: displayName="DUANE";
    break;
    case 215: displayName="FRANKLIN";
    break;
    case 216: displayName="ANDRE";
    break;
    case 217: displayName="ELMER";
    break;
    case 218: displayName="BRAD";
    break;
    case 219: displayName="GABRIEL";
    break;
    case 220: displayName="RON";
    break;
    case 221: displayName="MITCHELL";
    break;
    case 222: displayName="ROLAND";
    break;
    case 223: displayName="ARNOLD";
    break;
    case 224: displayName="HARVEY";
    break;
    case 225: displayName="JARED";
    break;
    case 226: displayName="ADRIAN";
    break;
    case 227: displayName="KARL";
    break;
    case 228: displayName="CORY";
    break;
    case 229: displayName="CLAUDE";
    break;
    case 230: displayName="ERIK";
    break;
    case 231: displayName="DARRYL";
    break;
    case 232: displayName="JAMIE";
    break;
    case 233: displayName="NEIL";
    break;
    case 234: displayName="JESSIE";
    break;
    case 235: displayName="CHRISTIAN";
    break;
    case 236: displayName="JAVIER";
    break;
    case 237: displayName="FERNANDO";
    break;
    case 238: displayName="CLINTON";
    break;
    case 239: displayName="TED";
    break;
    case 240: displayName="MATHEW";
    break;
    case 241: displayName="TYRONE";
    break;
    case 242: displayName="DARREN";
    break;
    case 243: displayName="LONNIE";
    break;
    case 244: displayName="LANCE";
    break;
    case 245: displayName="CODY";
    break;
    case 246: displayName="JULIO";
    break;
    case 247: displayName="KELLY";
    break;
    case 248: displayName="KURT";
    break;
    case 249: displayName="ALLAN";
    break;
    case 250: displayName="NELSON";
    break;
    case 251: displayName="GUY";
    break;
    case 252: displayName="CLAYTON";
    break;
    case 253: displayName="HUGH";
    break;
    case 254: displayName="MAX";
    break;
    case 255: displayName="DWAYNE";
    break;
    case 256: displayName="DWIGHT";
    break;
    case 257: displayName="ARMANDO";
    break;
    case 258: displayName="FELIX";
    break;
    case 259: displayName="JIMMIE";
    break;
    case 260: displayName="EVERETT";
    break;
    case 261: displayName="JORDAN";
    break;
    case 262: displayName="IAN";
    break;
    case 263: displayName="WALLACE";
    break;
    case 264: displayName="KEN";
    break;
    case 265: displayName="BOB";
    break;
    case 266: displayName="JAIME";
    break;
    case 267: displayName="CASEY";
    break;
    case 268: displayName="ALFREDO";
    break;
    case 269: displayName="ALBERTO";
    break;
    case 270: displayName="DAVE";
    break;
    case 271: displayName="IVAN";
    break;
    case 272: displayName="JOHNNIE";
    break;
    case 273: displayName="SIDNEY";
    break;
    case 274: displayName="BYRON";
    break;
    case 275: displayName="JULIAN";
    break;
    case 276: displayName="ISAAC";
    break;
    case 277: displayName="MORRIS";
    break;
    case 278: displayName="CLIFTON";
    break;
    case 279: displayName="WILLARD";
    break;
    case 280: displayName="DARYL";
    break;
    case 281: displayName="ROSS";
    break;
    case 282: displayName="VIRGIL";
    break;
    case 283: displayName="ANDY";
    break;
    case 284: displayName="MARSHALL";
    break;
    case 285: displayName="SALVADOR";
    break;
    case 286: displayName="PERRY";
    break;
    case 287: displayName="KIRK";
    break;
    case 288: displayName="SERGIO";
    break;
    case 289: displayName="MARION";
    break;
    case 290: displayName="TRACY";
    break;
    case 291: displayName="SETH";
    break;
    case 292: displayName="KENT";
    break;
    case 293: displayName="TERRANCE";
    break;
    case 294: displayName="RENE";
    break;
    case 295: displayName="EDUARDO";
    break;
    case 296: displayName="TERRENCE";
    break;
    case 297: displayName="ENRIQUE";
    break;
    case 298: displayName="FREDDIE";
    break;
    case 299: displayName="WADE";
    break;
    case 300: displayName="AUSTIN";
    break;
    case 301: displayName="STUART";
    break;
    case 302: displayName="FREDRICK";
    break;
    case 303: displayName="ARTURO";
    break;
    case 304: displayName="ALEJANDRO";
    break;
    case 305: displayName="JACKIE";
    break;
    case 306: displayName="JOEY";
    break;
    case 307: displayName="NICK";
    break;
    case 308: displayName="LUTHER";
    break;
    case 309: displayName="WENDELL";
    break;
    case 310: displayName="JEREMIAH";
    break;
    case 311: displayName="EVAN";
    break;
    case 312: displayName="JULIUS";
    break;
    case 313: displayName="DANA";
    break;
    case 314: displayName="DONNIE";
    break;
    case 315: displayName="OTIS";
    break;
    case 316: displayName="SHANNON";
    break;
    case 317: displayName="TREVOR";
    break;
    case 318: displayName="OLIVER";
    break;
    case 319: displayName="LUKE";
    break;
    case 320: displayName="HOMER";
    break;
    case 321: displayName="GERARD";
    break;
    case 322: displayName="DOUG";
    break;
    case 323: displayName="KENNY";
    break;
    case 324: displayName="HUBERT";
    break;
    case 325: displayName="ANGELO";
    break;
    case 326: displayName="SHAUN";
    break;
    case 327: displayName="LYLE";
    break;
    case 328: displayName="MATT";
    break;
    case 329: displayName="LYNN";
    break;
    case 330: displayName="ALFONSO";
    break;
    case 331: displayName="ORLANDO";
    break;
    case 332: displayName="REX";
    break;
    case 333: displayName="CARLTON";
    break;
    case 334: displayName="ERNESTO";
    break;
    case 335: displayName="CAMERON";
    break;
    case 336: displayName="NEAL";
    break;
    case 337: displayName="PABLO";
    break;
    case 338: displayName="LORENZO";
    break;
    case 339: displayName="OMAR";
    break;
    case 340: displayName="WILBUR";
    break;
    case 341: displayName="BLAKE";
    break;
    case 342: displayName="GRANT";
    break;
    case 343: displayName="HORACE";
    break;
    case 344: displayName="RODERICK";
    break;
    case 345: displayName="KERRY";
    break;
    case 346: displayName="ABRAHAM";
    break;
    case 347: displayName="WILLIS";
    break;
    case 348: displayName="RICKEY";
    break;
    case 349: displayName="JEAN";
    break;
    case 350: displayName="IRA";
    break;
    case 351: displayName="ANDRES";
    break;
    case 352: displayName="CESAR";
    break;
    case 353: displayName="JOHNATHAN";
    break;
    case 354: displayName="MALCOLM";
    break;
    case 355: displayName="RUDOLPH";
    break;
    case 356: displayName="DAMON";
    break;
    case 357: displayName="KELVIN";
    break;
    case 358: displayName="RUDY";
    break;
    case 359: displayName="PRESTON";
    break;
    case 360: displayName="ALTON";
    break;
    case 361: displayName="ARCHIE";
    break;
    case 362: displayName="MARCO";
    break;
    case 363: displayName="WM";
    break;
    case 364: displayName="PETE";
    break;
    case 365: displayName="RANDOLPH";
    break;
    case 366: displayName="GARRY";
    break;
    case 367: displayName="GEOFFREY";
    break;
    case 368: displayName="JONATHON";
    break;
    case 369: displayName="FELIPE";
    break;
    case 370: displayName="BENNIE";
    break;
    case 371: displayName="GERARDO";
    break;
    case 372: displayName="ED";
    break;
    case 373: displayName="DOMINIC";
    break;
    case 374: displayName="ROBIN";
    break;
    case 375: displayName="LOREN";
    break;
    case 376: displayName="DELBERT";
    break;
    case 377: displayName="COLIN";
    break;
    case 378: displayName="GUILLERMO";
    break;
    case 379: displayName="EARNEST";
    break;
    case 380: displayName="LUCAS";
    break;
    case 381: displayName="BENNY";
    break;
    case 382: displayName="NOEL";
    break;
    case 383: displayName="SPENCER";
    break;
    case 384: displayName="RODOLFO";
    break;
    case 385: displayName="MYRON";
    break;
    case 386: displayName="EDMUND";
    break;
    case 387: displayName="GARRETT";
    break;
    case 388: displayName="SALVATORE";
    break;
    case 389: displayName="CEDRIC";
    break;
    case 390: displayName="LOWELL";
    break;
    case 391: displayName="GREGG";
    break;
    case 392: displayName="SHERMAN";
    break;
    case 393: displayName="WILSON";
    break;
    case 394: displayName="DEVIN";
    break;
    case 395: displayName="SYLVESTER";
    break;
    case 396: displayName="KIM";
    break;
    case 397: displayName="ROOSEVELT";
    break;
    case 398: displayName="ISRAEL";
    break;
    case 399: displayName="JERMAINE";
    break;
    case 400: displayName="FORREST";
    break;
    case 401: displayName="WILBERT";
    break;
    case 402: displayName="LELAND";
    break;
    case 403: displayName="SIMON";
    break;
    case 404: displayName="GUADALUPE";
    break;
    case 405: displayName="CLARK";
    break;
    case 406: displayName="IRVING";
    break;
    case 407: displayName="CARROLL";
    break;
    case 408: displayName="BRYANT";
    break;
    case 409: displayName="OWEN";
    break;
    case 410: displayName="RUFUS";
    break;
    case 411: displayName="WOODROW";
    break;
    case 412: displayName="SAMMY";
    break;
    case 413: displayName="KRISTOPHER";
    break;
    case 414: displayName="MACK";
    break;
    case 415: displayName="LEVI";
    break;
    case 416: displayName="MARCOS";
    break;
    case 417: displayName="GUSTAVO";
    break;
    case 418: displayName="JAKE";
    break;
    case 419: displayName="LIONEL";
    break;
    case 420: displayName="MARTY";
    break;
    case 421: displayName="TAYLOR";
    break;
    case 422: displayName="ELLIS";
    break;
    case 423: displayName="DALLAS";
    break;
    case 424: displayName="GILBERTO";
    break;
    case 425: displayName="CLINT";
    break;
    case 426: displayName="NICOLAS";
    break;
    case 427: displayName="LAURENCE";
    break;
    case 428: displayName="ISMAEL";
    break;
    case 429: displayName="ORVILLE";
    break;
    case 430: displayName="DREW";
    break;
    case 431: displayName="JODY";
    break;
    case 432: displayName="ERVIN";
    break;
    case 433: displayName="DEWEY";
    break;
    case 434: displayName="AL";
    break;
    case 435: displayName="WILFRED";
    break;
    case 436: displayName="JOSH";
    break;
    case 437: displayName="HUGO";
    break;
    case 438: displayName="IGNACIO";
    break;
    case 439: displayName="CALEB";
    break;
    case 440: displayName="TOMAS";
    break;
    case 441: displayName="SHELDON";
    break;
    case 442: displayName="ERICK";
    break;
    case 443: displayName="FRANKIE";
    break;
    case 444: displayName="STEWART";
    break;
    case 445: displayName="DOYLE";
    break;
    case 446: displayName="DARREL";
    break;
    case 447: displayName="ROGELIO";
    break;
    case 448: displayName="TERENCE";
    break;
    case 449: displayName="SANTIAGO";
    break;
    case 450: displayName="ALONZO";
    break;
    case 451: displayName="ELIAS";
    break;
    case 452: displayName="BERT";
    break;
    case 453: displayName="ELBERT";
    break;
    case 454: displayName="RAMIRO";
    break;
    case 455: displayName="CONRAD";
    break;
    case 456: displayName="PAT";
    break;
    case 457: displayName="NOAH";
    break;
    case 458: displayName="GRADY";
    break;
    case 459: displayName="PHIL";
    break;
    case 460: displayName="CORNELIUS";
    break;
    case 461: displayName="LAMAR";
    break;
    case 462: displayName="ROLANDO";
    break;
    case 463: displayName="CLAY";
    break;
    case 464: displayName="PERCY";
    break;
    case 465: displayName="DEXTER";
    break;
    case 466: displayName="BRADFORD";
    break;
    case 467: displayName="MERLE";
    break;
    case 468: displayName="DARIN";
    break;
    case 469: displayName="AMOS";
    break;
    case 470: displayName="TERRELL";
    break;
    case 471: displayName="MOSES";
    break;
    case 472: displayName="IRVIN";
    break;
    case 473: displayName="SAUL";
    break;
    case 474: displayName="ROMAN";
    break;
    case 475: displayName="DARNELL";
    break;
    case 476: displayName="RANDAL";
    break;
    case 477: displayName="TOMMIE";
    break;
    case 478: displayName="TIMMY";
    break;
    case 479: displayName="DARRIN";
    break;
    case 480: displayName="WINSTON";
    break;
    case 481: displayName="BRENDAN";
    break;
    case 482: displayName="TOBY";
    break;
    case 483: displayName="VAN";
    break;
    case 484: displayName="ABEL";
    break;
    case 485: displayName="DOMINICK";
    break;
    case 486: displayName="BOYD";
    break;
    case 487: displayName="COURTNEY";
    break;
    case 488: displayName="JAN";
    break;
    case 489: displayName="EMILIO";
    break;
    case 490: displayName="ELIJAH";
    break;
    case 491: displayName="CARY";
    break;
    case 492: displayName="DOMINGO";
    break;
    case 493: displayName="SANTOS";
    break;
    case 494: displayName="AUBREY";
    break;
    case 495: displayName="EMMETT";
    break;
    case 496: displayName="MARLON";
    break;
    case 497: displayName="EMANUEL";
    break;
    case 498: displayName="JERALD";
    break;
    case 499: displayName="EDMOND";
    break;
    case 500: displayName="EMIL";
    break;
    case 501: displayName="DEWAYNE";
    break;
    case 502: displayName="WILL";
    break;
    case 503: displayName="OTTO";
    break;
    case 504: displayName="TEDDY";
    break;
    case 505: displayName="REYNALDO";
    break;
    case 506: displayName="BRET";
    break;
    case 507: displayName="MORGAN";
    break;
    case 508: displayName="JESS";
    break;
    case 509: displayName="TRENT";
    break;
    case 510: displayName="HUMBERTO";
    break;
    case 511: displayName="EMMANUEL";
    break;
    case 512: displayName="STEPHAN";
    break;
    case 513: displayName="LOUIE";
    break;
    case 514: displayName="VICENTE";
    break;
    case 515: displayName="LAMONT";
    break;
    case 516: displayName="STACY";
    break;
    case 517: displayName="GARLAND";
    break;
    case 518: displayName="MILES";
    break;
    case 519: displayName="MICAH";
    break;
    case 520: displayName="EFRAIN";
    break;
    case 521: displayName="BILLIE";
    break;
    case 522: displayName="LOGAN";
    break;
    case 523: displayName="HEATH";
    break;
    case 524: displayName="RODGER";
    break;
    case 525: displayName="HARLEY";
    break;
    case 526: displayName="DEMETRIUS";
    break;
    case 527: displayName="ETHAN";
    break;
    case 528: displayName="ELDON";
    break;
    case 529: displayName="ROCKY";
    break;
    case 530: displayName="PIERRE";
    break;
    case 531: displayName="JUNIOR";
    break;
    case 532: displayName="FREDDY";
    break;
    case 533: displayName="ELI";
    break;
    case 534: displayName="BRYCE";
    break;
    case 535: displayName="ANTOINE";
    break;
    case 536: displayName="ROBBIE";
    break;
    case 537: displayName="KENDALL";
    break;
    case 538: displayName="ROYCE";
    break;
    case 539: displayName="STERLING";
    break;
    case 540: displayName="MICKEY";
    break;
    case 541: displayName="CHASE";
    break;
    case 542: displayName="GROVER";
    break;
    case 543: displayName="ELTON";
    break;
    case 544: displayName="CLEVELAND";
    break;
    case 545: displayName="DYLAN";
    break;
    case 546: displayName="CHUCK";
    break;
    case 547: displayName="DAMIAN";
    break;
    case 548: displayName="REUBEN";
    break;
    case 549: displayName="STAN";
    break;
    case 550: displayName="AUGUST";
    break;
    case 551: displayName="LEONARDO";
    break;
    case 552: displayName="JASPER";
    break;
    case 553: displayName="RUSSEL";
    break;
    case 554: displayName="ERWIN";
    break;
    case 555: displayName="BENITO";
    break;
    case 556: displayName="HANS";
    break;
    case 557: displayName="MONTE";
    break;
    case 558: displayName="BLAINE";
    break;
    case 559: displayName="ERNIE";
    break;
    case 560: displayName="CURT";
    break;
    case 561: displayName="QUENTIN";
    break;
    case 562: displayName="AGUSTIN";
    break;
    case 563: displayName="MURRAY";
    break;
    case 564: displayName="JAMAL";
    break;
    case 565: displayName="DEVON";
    break;
    case 566: displayName="ADOLFO";
    break;
    case 567: displayName="HARRISON";
    break;
    case 568: displayName="TYSON";
    break;
    case 569: displayName="BURTON";
    break;
    case 570: displayName="BRADY";
    break;
    case 571: displayName="ELLIOTT";
    break;
    case 572: displayName="WILFREDO";
    break;
    case 573: displayName="BART";
    break;
    case 574: displayName="JARROD";
    break;
    case 575: displayName="VANCE";
    break;
    case 576: displayName="DENIS";
    break;
    case 577: displayName="DAMIEN";
    break;
    case 578: displayName="JOAQUIN";
    break;
    case 579: displayName="HARLAN";
    break;
    case 580: displayName="DESMOND";
    break;
    case 581: displayName="ELLIOT";
    break;
    case 582: displayName="DARWIN";
    break;
    case 583: displayName="ASHLEY";
    break;
    case 584: displayName="GREGORIO";
    break;
    case 585: displayName="BUDDY";
    break;
    case 586: displayName="XAVIER";
    break;
    case 587: displayName="KERMIT";
    break;
    case 588: displayName="ROSCOE";
    break;
    case 589: displayName="ESTEBAN";
    break;
    case 590: displayName="ANTON";
    break;
    case 591: displayName="SOLOMON";
    break;
    case 592: displayName="SCOTTY";
    break;
    case 593: displayName="NORBERT";
    break;
    case 594: displayName="ELVIN";
    break;
    case 595: displayName="WILLIAMS";
    break;
    case 596: displayName="NOLAN";
    break;
    case 597: displayName="CAREY";
    break;
    case 598: displayName="ROD";
    break;
    case 599: displayName="QUINTON";
    break;
    case 600: displayName="HAL";
    break;
    case 601: displayName="BRAIN";
    break;
    case 602: displayName="ROB";
    break;
    case 603: displayName="ELWOOD";
    break;
    case 604: displayName="KENDRICK";
    break;
    case 605: displayName="DARIUS";
    break;
    case 606: displayName="MOISES";
    break;
    case 607: displayName="SON";
    break;
    case 608: displayName="MARLIN";
    break;
    case 609: displayName="FIDEL";
    break;
    case 610: displayName="THADDEUS";
    break;
    case 611: displayName="CLIFF";
    break;
    case 612: displayName="MARCEL";
    break;
    case 613: displayName="ALI";
    break;
    case 614: displayName="JACKSON";
    break;
    case 615: displayName="RAPHAEL";
    break;
    case 616: displayName="BRYON";
    break;
    case 617: displayName="ARMAND";
    break;
    case 618: displayName="ALVARO";
    break;
    case 619: displayName="JEFFRY";
    break;
    case 620: displayName="DANE";
    break;
    case 621: displayName="JOESPH";
    break;
    case 622: displayName="THURMAN";
    break;
    case 623: displayName="NED";
    break;
    case 624: displayName="SAMMIE";
    break;
    case 625: displayName="RUSTY";
    break;
    case 626: displayName="MICHEL";
    break;
    case 627: displayName="MONTY";
    break;
    case 628: displayName="RORY";
    break;
    case 629: displayName="FABIAN";
    break;
    case 630: displayName="REGGIE";
    break;
    case 631: displayName="MASON";
    break;
    case 632: displayName="GRAHAM";
    break;
    case 633: displayName="KRIS";
    break;
    case 634: displayName="ISAIAH";
    break;
    case 635: displayName="VAUGHN";
    break;
    case 636: displayName="GUS";
    break;
    case 637: displayName="AVERY";
    break;
    case 638: displayName="LOYD";
    break;
    case 639: displayName="DIEGO";
    break;
    case 640: displayName="ALEXIS";
    break;
    case 641: displayName="ADOLPH";
    break;
    case 642: displayName="NORRIS";
    break;
    case 643: displayName="MILLARD";
    break;
    case 644: displayName="ROCCO";
    break;
    case 645: displayName="GONZALO";
    break;
    case 646: displayName="DERICK";
    break;
    case 647: displayName="RODRIGO";
    break;
    case 648: displayName="GERRY";
    break;
    case 649: displayName="STACEY";
    break;
    case 650: displayName="CARMEN";
    break;
    case 651: displayName="WILEY";
    break;
    case 652: displayName="RIGOBERTO";
    break;
    case 653: displayName="ALPHONSO";
    break;
    case 654: displayName="TY";
    break;
    case 655: displayName="SHELBY";
    break;
    case 656: displayName="RICKIE";
    break;
    case 657: displayName="NOE";
    break;
    case 658: displayName="VERN";
    break;
    case 659: displayName="BOBBIE";
    break;
    case 660: displayName="REED";
    break;
    case 661: displayName="JEFFERSON";
    break;
    case 662: displayName="ELVIS";
    break;
    case 663: displayName="BERNARDO";
    break;
    case 664: displayName="MAURICIO";
    break;
    case 665: displayName="HIRAM";
    break;
    case 666: displayName="DONOVAN";
    break;
    case 667: displayName="BASIL";
    break;
    case 668: displayName="RILEY";
    break;
    case 669: displayName="OLLIE";
    break;
    case 670: displayName="NICKOLAS";
    break;
    case 671: displayName="MAYNARD";
    break;
    case 672: displayName="SCOT";
    break;
    case 673: displayName="VINCE";
    break;
    case 674: displayName="QUINCY";
    break;
    case 675: displayName="EDDY";
    break;
    case 676: displayName="SEBASTIAN";
    break;
    case 677: displayName="FEDERICO";
    break;
    case 678: displayName="ULYSSES";
    break;
    case 679: displayName="HERIBERTO";
    break;
    case 680: displayName="DONNELL";
    break;
    case 681: displayName="COLE";
    break;
    case 682: displayName="DENNY";
    break;
    case 683: displayName="DAVIS";
    break;
    case 684: displayName="GAVIN";
    break;
    case 685: displayName="EMERY";
    break;
    case 686: displayName="WARD";
    break;
    case 687: displayName="ROMEO";
    break;
    case 688: displayName="JAYSON";
    break;
    case 689: displayName="DION";
    break;
    case 690: displayName="DANTE";
    break;
    case 691: displayName="CLEMENT";
    break;
    case 692: displayName="COY";
    break;
    case 693: displayName="ODELL";
    break;
    case 694: displayName="MAXWELL";
    break;
    case 695: displayName="JARVIS";
    break;
    case 696: displayName="BRUNO";
    break;
    case 697: displayName="ISSAC";
    break;
    case 698: displayName="MARY";
    break;
    case 699: displayName="DUDLEY";
    break;
    case 700: displayName="BROCK";
    break;
    case 701: displayName="SANFORD";
    break;
    case 702: displayName="COLBY";
    break;
    case 703: displayName="CARMELO";
    break;
    case 704: displayName="BARNEY";
    break;
    case 705: displayName="NESTOR";
    break;
    case 706: displayName="HOLLIS";
    break;
    case 707: displayName="STEFAN";
    break;
    case 708: displayName="DONNY";
    break;
    case 709: displayName="ART";
    break;
    case 710: displayName="LINWOOD";
    break;
    case 711: displayName="BEAU";
    break;
    case 712: displayName="WELDON";
    break;
    case 713: displayName="GALEN";
    break;
    case 714: displayName="ISIDRO";
    break;
    case 715: displayName="TRUMAN";
    break;
    case 716: displayName="DELMAR";
    break;
    case 717: displayName="JOHNATHON";
    break;
    case 718: displayName="SILAS";
    break;
    case 719: displayName="FREDERIC";
    break;
    case 720: displayName="DICK";
    break;
    case 721: displayName="KIRBY";
    break;
    case 722: displayName="IRWIN";
    break;
    case 723: displayName="CRUZ";
    break;
    case 724: displayName="MERLIN";
    break;
    case 725: displayName="MERRILL";
    break;
    case 726: displayName="CHARLEY";
    break;
    case 727: displayName="MARCELINO";
    break;
    case 728: displayName="LANE";
    break;
    case 729: displayName="HARRIS";
    break;
    case 730: displayName="CLEO";
    break;
    case 731: displayName="CARLO";
    break;
    case 732: displayName="TRENTON";
    break;
    case 733: displayName="KURTIS";
    break;
    case 734: displayName="HUNTER";
    break;
    case 735: displayName="AURELIO";
    break;
    case 736: displayName="WINFRED";
    break;
    case 737: displayName="VITO";
    break;
    case 738: displayName="COLLIN";
    break;
    case 739: displayName="DENVER";
    break;
    case 740: displayName="CARTER";
    break;
    case 741: displayName="LEONEL";
    break;
    case 742: displayName="EMORY";
    break;
    case 743: displayName="PASQUALE";
    break;
    case 744: displayName="MOHAMMAD";
    break;
    case 745: displayName="MARIANO";
    break;
    case 746: displayName="DANIAL";
    break;
    case 747: displayName="BLAIR";
    break;
    case 748: displayName="LANDON";
    break;
    case 749: displayName="DIRK";
    break;
    case 750: displayName="BRANDEN";
    break;
    case 751: displayName="ADAN";
    break;
    case 752: displayName="NUMBERS";
    break;
    case 753: displayName="CLAIR";
    break;
    case 754: displayName="BUFORD";
    break;
    case 755: displayName="GERMAN";
    break;
    case 756: displayName="BERNIE";
    break;
    case 757: displayName="WILMER";
    break;
    case 758: displayName="JOAN";
    break;
    case 759: displayName="EMERSON";
    break;
    case 760: displayName="ZACHERY";
    break;
    case 761: displayName="FLETCHER";
    break;
    case 762: displayName="JACQUES";
    break;
    case 763: displayName="ERROL";
    break;
    case 764: displayName="DALTON";
    break;
    case 765: displayName="MONROE";
    break;
    case 766: displayName="JOSUE";
    break;
    case 767: displayName="DOMINIQUE";
    break;
    case 768: displayName="EDWARDO";
    break;
    case 769: displayName="BOOKER";
    break;
    case 770: displayName="WILFORD";
    break;
    case 771: displayName="SONNY";
    break;
    case 772: displayName="SHELTON";
    break;
    case 773: displayName="CARSON";
    break;
    case 774: displayName="THERON";
    break;
    case 775: displayName="RAYMUNDO";
    break;
    case 776: displayName="DAREN";
    break;
    case 777: displayName="TRISTAN";
    break;
    case 778: displayName="HOUSTON";
    break;
    case 779: displayName="ROBBY";
    break;
    case 780: displayName="LINCOLN";
    break;
    case 781: displayName="JAME";
    break;
    case 782: displayName="GENARO";
    break;
    case 783: displayName="GALE";
    break;
    case 784: displayName="BENNETT";
    break;
    case 785: displayName="OCTAVIO";
    break;
    case 786: displayName="CORNELL";
    break;
    case 787: displayName="LAVERNE";
    break;
    case 788: displayName="HUNG";
    break;
    case 789: displayName="ARRON";
    break;
    case 790: displayName="ANTONY";
    break;
    case 791: displayName="HERSCHEL";
    break;
    case 792: displayName="ALVA";
    break;
    case 793: displayName="GIOVANNI";
    break;
    case 794: displayName="GARTH";
    break;
    case 795: displayName="CYRUS";
    break;
    case 796: displayName="CYRIL";
    break;
    case 797: displayName="RONNY";
    break;
    case 798: displayName="STEVIE";
    break;
    case 799: displayName="LON";
    break;
    case 800: displayName="FREEMAN";
    break;
    case 801: displayName="ERIN";
    break;
    case 802: displayName="DUNCAN";
    break;
    case 803: displayName="KENNITH";
    break;
    case 804: displayName="CARMINE";
    break;
    case 805: displayName="AUGUSTINE";
    break;
    case 806: displayName="YOUNG";
    break;
    case 807: displayName="ERICH";
    break;
    case 808: displayName="CHADWICK";
    break;
    case 809: displayName="WILBURN";
    break;
    case 810: displayName="RUSS";
    break;
    case 811: displayName="REID";
    break;
    case 812: displayName="MYLES";
    break;
    case 813: displayName="ANDERSON";
    break;
    case 814: displayName="MORTON";
    break;
    case 815: displayName="JONAS";
    break;
    case 816: displayName="FOREST";
    break;
    case 817: displayName="MITCHEL";
    break;
    case 818: displayName="MERVIN";
    break;
    case 819: displayName="ZANE";
    break;
    case 820: displayName="RICH";
    break;
    case 821: displayName="JAMEL";
    break;
    case 822: displayName="LAZARO";
    break;
    case 823: displayName="ALPHONSE";
    break;
    case 824: displayName="RANDELL";
    break;
    case 825: displayName="MAJOR";
    break;
    case 826: displayName="JOHNIE";
    break;
    case 827: displayName="JARRETT";
    break;
    case 828: displayName="BROOKS";
    break;
    case 829: displayName="ARIEL";
    break;
    case 830: displayName="ABDUL";
    break;
    case 831: displayName="DUSTY";
    break;
    case 832: displayName="LUCIANO";
    break;
    case 833: displayName="LINDSEY";
    break;
    case 834: displayName="TRACEY";
    break;
    case 835: displayName="SEYMOUR";
    break;
    case 836: displayName="SCOTTIE";
    break;
    case 837: displayName="EUGENIO";
    break;
    case 838: displayName="MOHAMMED";
    break;
    case 839: displayName="SANDY";
    break;
    case 840: displayName="VALENTIN";
    break;
    case 841: displayName="CHANCE";
    break;
    case 842: displayName="ARNULFO";
    break;
    case 843: displayName="LUCIEN";
    break;
    case 844: displayName="FERDINAND";
    break;
    case 845: displayName="THAD";
    break;
    case 846: displayName="EZRA";
    break;
    case 847: displayName="SYDNEY";
    break;
    case 848: displayName="ALDO";
    break;
    case 849: displayName="RUBIN";
    break;
    case 850: displayName="ROYAL";
    break;
    case 851: displayName="MITCH";
    break;
    case 852: displayName="EARLE";
    break;
    case 853: displayName="ABE";
    break;
    case 854: displayName="WYATT";
    break;
    case 855: displayName="MARQUIS";
    break;
    case 856: displayName="LANNY";
    break;
    case 857: displayName="KAREEM";
    break;
    case 858: displayName="JAMAR";
    break;
    case 859: displayName="BORIS";
    break;
    case 860: displayName="ISIAH";
    break;
    case 861: displayName="EMILE";
    break;
    case 862: displayName="ELMO";
    break;
    case 863: displayName="ARON";
    break;
    case 864: displayName="LEOPOLDO";
    break;
    case 865: displayName="EVERETTE";
    break;
    case 866: displayName="JOSEF";
    break;
    case 867: displayName="GAIL";
    break;
    case 868: displayName="ELOY";
    break;
    case 869: displayName="DORIAN";
    break;
    case 870: displayName="RODRICK";
    break;
    case 871: displayName="REINALDO";
    break;
    case 872: displayName="LUCIO";
    break;
    case 873: displayName="JERROD";
    break;
    case 874: displayName="WESTON";
    break;
    case 875: displayName="HERSHEL";
    break;
    case 876: displayName="BARTON";
    break;
    case 877: displayName="PARKER";
    break;
    case 878: displayName="LEMUEL";
    break;
    case 879: displayName="LAVERN";
    break;
    case 880: displayName="BURT";
    break;
    case 881: displayName="JULES";
    break;
    case 882: displayName="GIL";
    break;
    case 883: displayName="ELISEO";
    break;
    case 884: displayName="AHMAD";
    break;
    case 885: displayName="NIGEL";
    break;
    case 886: displayName="EFREN";
    break;
    case 887: displayName="ANTWAN";
    break;
    case 888: displayName="ALDEN";
    break;
    case 889: displayName="MARGARITO";
    break;
    case 890: displayName="COLEMAN";
    break;
    case 891: displayName="REFUGIO";
    break;
    case 892: displayName="DINO";
    break;
    case 893: displayName="OSVALDO";
    break;
    case 894: displayName="LES";
    break;
    case 895: displayName="DEANDRE";
    break;
    case 896: displayName="NORMAND";
    break;
    case 897: displayName="KIETH";
    break;
    case 898: displayName="IVORY";
    break;
    case 899: displayName="ANDREA";
    break;
    case 900: displayName="TREY";
    break;
    case 901: displayName="NORBERTO";
    break;
    case 902: displayName="NAPOLEON";
    break;
    case 903: displayName="JEROLD";
    break;
    case 904: displayName="FRITZ";
    break;
    case 905: displayName="ROSENDO";
    break;
    case 906: displayName="MILFORD";
    break;
    case 907: displayName="SANG";
    break;
    case 908: displayName="DEON";
    break;
    case 909: displayName="CHRISTOPER";
    break;
    case 910: displayName="ALFONZO";
    break;
    case 911: displayName="LYMAN";
    break;
    case 912: displayName="JOSIAH";
    break;
    case 913: displayName="BRANT";
    break;
    case 914: displayName="WILTON";
    break;
    case 915: displayName="RICO";
    break;
    case 916: displayName="JAMAAL";
    break;
    case 917: displayName="DEWITT";
    break;
    case 918: displayName="CAROL";
    break;
    case 919: displayName="BRENTON";
    break;
    case 920: displayName="YONG";
    break;
    case 921: displayName="OLIN";
    break;
    case 922: displayName="FOSTER";
    break;
    case 923: displayName="FAUSTINO";
    break;
    case 924: displayName="CLAUDIO";
    break;
    case 925: displayName="JUDSON";
    break;
    case 926: displayName="GINO";
    break;
    case 927: displayName="EDGARDO";
    break;
    case 928: displayName="BERRY";
    break;
    case 929: displayName="ALEC";
    break;
    case 930: displayName="TANNER";
    break;
    case 931: displayName="JARRED";
    break;
    case 932: displayName="DONN";
    break;
    case 933: displayName="TRINIDAD";
    break;
    case 934: displayName="TAD";
    break;
    case 935: displayName="SHIRLEY";
    break;
    case 936: displayName="PRINCE";
    break;
    case 937: displayName="PORFIRIO";
    break;
    case 938: displayName="ODIS";
    break;
    case 939: displayName="MARIA";
    break;
    case 940: displayName="LENARD";
    break;
    case 941: displayName="CHAUNCEY";
    break;
    case 942: displayName="CHANG";
    break;
    case 943: displayName="TOD";
    break;
    case 944: displayName="MEL";
    break;
    case 945: displayName="MARCELO";
    break;
    case 946: displayName="KORY";
    break;
    case 947: displayName="AUGUSTUS";
    break;
    case 948: displayName="KEVEN";
    break;
    case 949: displayName="HILARIO";
    break;
    case 950: displayName="BUD";
    break;
    case 951: displayName="SAL";
    break;
    case 952: displayName="ROSARIO";
    break;
    case 953: displayName="ORVAL";
    break;
    case 954: displayName="MAURO";
    break;
    case 955: displayName="DANNIE";
    break;
    case 956: displayName="ZACHARIAH";
    break;
    case 957: displayName="OLEN";
    break;
    case 958: displayName="ANIBAL";
    break;
    case 959: displayName="MILO";
    break;
    case 960: displayName="JED";
    break;
    case 961: displayName="FRANCES";
    break;
    case 962: displayName="THANH";
    break;
    case 963: displayName="DILLON";
    break;
    case 964: displayName="AMADO";
    break;
    case 965: displayName="NEWTON";
    break;
    case 966: displayName="CONNIE";
    break;
    case 967: displayName="LENNY";
    break;
    case 968: displayName="TORY";
    break;
    case 969: displayName="RICHIE";
    break;
    case 970: displayName="LUPE";
    break;
    case 971: displayName="HORACIO";
    break;
    case 972: displayName="BRICE";
    break;
    case 973: displayName="MOHAMED";
    break;
    case 974: displayName="DELMER";
    break;
    case 975: displayName="DARIO";
    break;
    case 976: displayName="REYES";
    break;
    case 977: displayName="DEE";
    break;
    case 978: displayName="MAC";
    break;
    case 979: displayName="JONAH";
    break;
    case 980: displayName="JERROLD";
    break;
    case 981: displayName="ROBT";
    break;
    case 982: displayName="HANK";
    break;
    case 983: displayName="SUNG";
    break;
    case 984: displayName="RUPERT";
    break;
    case 985: displayName="ROLLAND";
    break;
    case 986: displayName="KENTON";
    break;
    case 987: displayName="DAMION";
    break;
    case 988: displayName="CHI";
    break;
    case 989: displayName="ANTONE";
    break;
    case 990: displayName="WALDO";
    break;
    case 991: displayName="FREDRIC";
    break;
    case 992: displayName="BRADLY";
    break;
    case 993: displayName="QUINN";
    break;
    case 994: displayName="KIP";
    break;
    case 995: displayName="BURL";
    break;
    case 996: displayName="WALKER";
    break;
    case 997: displayName="TYREE";
    break;
    case 998: displayName="JEFFEREY";
    break;
    case 999: displayName="AHMED";
    break;
    }
}

void displayFemaleName(int randomizer)
{
    switch(randomizer)
    {
    case 0: displayName="MARY";
    break;
    case 1: displayName="PATRICIA";
    break;
    case 2: displayName="LINDA";
    break;
    case 3: displayName="BARBARA";
    break;
    case 4: displayName="ELIZABETH";
    break;
    case 5: displayName="JENNIFER";
    break;
    case 6: displayName="MARIA";
    break;
    case 7: displayName="SUSAN";
    break;
    case 8: displayName="MARGARET";
    break;
    case 9: displayName="DOROTHY";
    break;
    case 10: displayName="LISA";
    break;
    case 11: displayName="NANCY";
    break;
    case 12: displayName="KAREN";
    break;
    case 13: displayName="BETTY";
    break;
    case 14: displayName="HELEN";
    break;
    case 15: displayName="SANDRA";
    break;
    case 16: displayName="DONNA";
    break;
    case 17: displayName="CAROL";
    break;
    case 18: displayName="RUTH";
    break;
    case 19: displayName="SHARON";
    break;
    case 20: displayName="MICHELLE";
    break;
    case 21: displayName="LAURA";
    break;
    case 22: displayName="SARAH";
    break;
    case 23: displayName="KIMBERLY";
    break;
    case 24: displayName="DEBORAH";
    break;
    case 25: displayName="JESSICA";
    break;
    case 26: displayName="SHIRLEY";
    break;
    case 27: displayName="CYNTHIA";
    break;
    case 28: displayName="ANGELA";
    break;
    case 29: displayName="MELISSA";
    break;
    case 30: displayName="BRENDA";
    break;
    case 31: displayName="AMY";
    break;
    case 32: displayName="ANNA";
    break;
    case 33: displayName="REBECCA";
    break;
    case 34: displayName="VIRGINIA";
    break;
    case 35: displayName="KATHLEEN";
    break;
    case 36: displayName="PAMELA";
    break;
    case 37: displayName="MARTHA";
    break;
    case 38: displayName="DEBRA";
    break;
    case 39: displayName="AMANDA";
    break;
    case 40: displayName="STEPHANIE";
    break;
    case 41: displayName="CAROLYN";
    break;
    case 42: displayName="CHRISTINE";
    break;
    case 43: displayName="MARIE";
    break;
    case 44: displayName="JANET";
    break;
    case 45: displayName="CATHERINE";
    break;
    case 46: displayName="FRANCES";
    break;
    case 47: displayName="ANN";
    break;
    case 48: displayName="JOYCE";
    break;
    case 49: displayName="DIANE";
    break;
    case 50: displayName="ALICE";
    break;
    case 51: displayName="JULIE";
    break;
    case 52: displayName="HEATHER";
    break;
    case 53: displayName="TERESA";
    break;
    case 54: displayName="DORIS";
    break;
    case 55: displayName="GLORIA";
    break;
    case 56: displayName="EVELYN";
    break;
    case 57: displayName="JEAN";
    break;
    case 58: displayName="CHERYL";
    break;
    case 59: displayName="MILDRED";
    break;
    case 60: displayName="KATHERINE";
    break;
    case 61: displayName="JOAN";
    break;
    case 62: displayName="ASHLEY";
    break;
    case 63: displayName="JUDITH";
    break;
    case 64: displayName="ROSE";
    break;
    case 65: displayName="JANICE";
    break;
    case 66: displayName="KELLY";
    break;
    case 67: displayName="NICOLE";
    break;
    case 68: displayName="JUDY";
    break;
    case 69: displayName="CHRISTINA";
    break;
    case 70: displayName="KATHY";
    break;
    case 71: displayName="THERESA";
    break;
    case 72: displayName="BEVERLY";
    break;
    case 73: displayName="DENISE";
    break;
    case 74: displayName="TAMMY";
    break;
    case 75: displayName="IRENE";
    break;
    case 76: displayName="JANE";
    break;
    case 77: displayName="LORI";
    break;
    case 78: displayName="RACHEL";
    break;
    case 79: displayName="MARILYN";
    break;
    case 80: displayName="ANDREA";
    break;
    case 81: displayName="KATHRYN";
    break;
    case 82: displayName="LOUISE";
    break;
    case 83: displayName="SARA";
    break;
    case 84: displayName="ANNE";
    break;
    case 85: displayName="JACQUELINE";
    break;
    case 86: displayName="WANDA";
    break;
    case 87: displayName="BONNIE";
    break;
    case 88: displayName="JULIA";
    break;
    case 89: displayName="RUBY";
    break;
    case 90: displayName="LOIS";
    break;
    case 91: displayName="TINA";
    break;
    case 92: displayName="PHYLLIS";
    break;
    case 93: displayName="NORMA";
    break;
    case 94: displayName="PAULA";
    break;
    case 95: displayName="DIANA";
    break;
    case 96: displayName="ANNIE";
    break;
    case 97: displayName="LILLIAN";
    break;
    case 98: displayName="EMILY";
    break;
    case 99: displayName="ROBIN";
    break;
    case 100: displayName="PEGGY";
    break;
    case 101: displayName="CRYSTAL";
    break;
    case 102: displayName="GLADYS";
    break;
    case 103: displayName="RITA";
    break;
    case 104: displayName="DAWN";
    break;
    case 105: displayName="CONNIE";
    break;
    case 106: displayName="FLORENCE";
    break;
    case 107: displayName="TRACY";
    break;
    case 108: displayName="EDNA";
    break;
    case 109: displayName="TIFFANY";
    break;
    case 110: displayName="CARMEN";
    break;
    case 111: displayName="ROSA";
    break;
    case 112: displayName="CINDY";
    break;
    case 113: displayName="GRACE";
    break;
    case 114: displayName="WENDY";
    break;
    case 115: displayName="VICTORIA";
    break;
    case 116: displayName="EDITH";
    break;
    case 117: displayName="KIM";
    break;
    case 118: displayName="SHERRY";
    break;
    case 119: displayName="SYLVIA";
    break;
    case 120: displayName="JOSEPHINE";
    break;
    case 121: displayName="THELMA";
    break;
    case 122: displayName="SHANNON";
    break;
    case 123: displayName="SHEILA";
    break;
    case 124: displayName="ETHEL";
    break;
    case 125: displayName="ELLEN";
    break;
    case 126: displayName="ELAINE";
    break;
    case 127: displayName="MARJORIE";
    break;
    case 128: displayName="CARRIE";
    break;
    case 129: displayName="CHARLOTTE";
    break;
    case 130: displayName="MONICA";
    break;
    case 131: displayName="ESTHER";
    break;
    case 132: displayName="PAULINE";
    break;
    case 133: displayName="EMMA";
    break;
    case 134: displayName="JUANITA";
    break;
    case 135: displayName="ANITA";
    break;
    case 136: displayName="RHONDA";
    break;
    case 137: displayName="HAZEL";
    break;
    case 138: displayName="AMBER";
    break;
    case 139: displayName="EVA";
    break;
    case 140: displayName="DEBBIE";
    break;
    case 141: displayName="APRIL";
    break;
    case 142: displayName="LESLIE";
    break;
    case 143: displayName="CLARA";
    break;
    case 144: displayName="LUCILLE";
    break;
    case 145: displayName="JAMIE";
    break;
    case 146: displayName="JOANNE";
    break;
    case 147: displayName="ELEANOR";
    break;
    case 148: displayName="VALERIE";
    break;
    case 149: displayName="DANIELLE";
    break;
    case 150: displayName="MEGAN";
    break;
    case 151: displayName="ALICIA";
    break;
    case 152: displayName="SUZANNE";
    break;
    case 153: displayName="MICHELE";
    break;
    case 154: displayName="GAIL";
    break;
    case 155: displayName="BERTHA";
    break;
    case 156: displayName="DARLENE";
    break;
    case 157: displayName="VERONICA";
    break;
    case 158: displayName="JILL";
    break;
    case 159: displayName="ERIN";
    break;
    case 160: displayName="GERALDINE";
    break;
    case 161: displayName="LAUREN";
    break;
    case 162: displayName="CATHY";
    break;
    case 163: displayName="JOANN";
    break;
    case 164: displayName="LORRAINE";
    break;
    case 165: displayName="LYNN";
    break;
    case 166: displayName="SALLY";
    break;
    case 167: displayName="REGINA";
    break;
    case 168: displayName="ERICA";
    break;
    case 169: displayName="BEATRICE";
    break;
    case 170: displayName="DOLORES";
    break;
    case 171: displayName="BERNICE";
    break;
    case 172: displayName="AUDREY";
    break;
    case 173: displayName="YVONNE";
    break;
    case 174: displayName="ANNETTE";
    break;
    case 175: displayName="JUNE";
    break;
    case 176: displayName="SAMANTHA";
    break;
    case 177: displayName="MARION";
    break;
    case 178: displayName="DANA";
    break;
    case 179: displayName="STACY";
    break;
    case 180: displayName="ANA";
    break;
    case 181: displayName="RENEE";
    break;
    case 182: displayName="IDA";
    break;
    case 183: displayName="VIVIAN";
    break;
    case 184: displayName="ROBERTA";
    break;
    case 185: displayName="HOLLY";
    break;
    case 186: displayName="BRITTANY";
    break;
    case 187: displayName="MELANIE";
    break;
    case 188: displayName="LORETTA";
    break;
    case 189: displayName="YOLANDA";
    break;
    case 190: displayName="JEANETTE";
    break;
    case 191: displayName="LAURIE";
    break;
    case 192: displayName="KATIE";
    break;
    case 193: displayName="KRISTEN";
    break;
    case 194: displayName="VANESSA";
    break;
    case 195: displayName="ALMA";
    break;
    case 196: displayName="SUE";
    break;
    case 197: displayName="ELSIE";
    break;
    case 198: displayName="BETH";
    break;
    case 199: displayName="JEANNE";
    break;
    case 200: displayName="VICKI";
    break;
    case 201: displayName="CARLA";
    break;
    case 202: displayName="TARA";
    break;
    case 203: displayName="ROSEMARY";
    break;
    case 204: displayName="EILEEN";
    break;
    case 205: displayName="TERRI";
    break;
    case 206: displayName="GERTRUDE";
    break;
    case 207: displayName="LUCY";
    break;
    case 208: displayName="TONYA";
    break;
    case 209: displayName="ELLA";
    break;
    case 210: displayName="STACEY";
    break;
    case 211: displayName="WILMA";
    break;
    case 212: displayName="GINA";
    break;
    case 213: displayName="KRISTIN";
    break;
    case 214: displayName="JESSIE";
    break;
    case 215: displayName="NATALIE";
    break;
    case 216: displayName="AGNES";
    break;
    case 217: displayName="VERA";
    break;
    case 218: displayName="WILLIE";
    break;
    case 219: displayName="CHARLENE";
    break;
    case 220: displayName="BESSIE";
    break;
    case 221: displayName="DELORES";
    break;
    case 222: displayName="MELINDA";
    break;
    case 223: displayName="PEARL";
    break;
    case 224: displayName="ARLENE";
    break;
    case 225: displayName="MAUREEN";
    break;
    case 226: displayName="COLLEEN";
    break;
    case 227: displayName="ALLISON";
    break;
    case 228: displayName="TAMARA";
    break;
    case 229: displayName="JOY";
    break;
    case 230: displayName="GEORGIA";
    break;
    case 231: displayName="CONSTANCE";
    break;
    case 232: displayName="LILLIE";
    break;
    case 233: displayName="CLAUDIA";
    break;
    case 234: displayName="JACKIE";
    break;
    case 235: displayName="MARCIA";
    break;
    case 236: displayName="TANYA";
    break;
    case 237: displayName="NELLIE";
    break;
    case 238: displayName="MINNIE";
    break;
    case 239: displayName="MARLENE";
    break;
    case 240: displayName="HEIDI";
    break;
    case 241: displayName="GLENDA";
    break;
    case 242: displayName="LYDIA";
    break;
    case 243: displayName="VIOLA";
    break;
    case 244: displayName="COURTNEY";
    break;
    case 245: displayName="MARIAN";
    break;
    case 246: displayName="STELLA";
    break;
    case 247: displayName="CAROLINE";
    break;
    case 248: displayName="DORA";
    break;
    case 249: displayName="JO";
    break;
    case 250: displayName="VICKIE";
    break;
    case 251: displayName="MATTIE";
    break;
    case 252: displayName="TERRY";
    break;
    case 253: displayName="MAXINE";
    break;
    case 254: displayName="IRMA";
    break;
    case 255: displayName="MABEL";
    break;
    case 256: displayName="MARSHA";
    break;
    case 257: displayName="MYRTLE";
    break;
    case 258: displayName="LENA";
    break;
    case 259: displayName="CHRISTY";
    break;
    case 260: displayName="DEANNA";
    break;
    case 261: displayName="PATSY";
    break;
    case 262: displayName="HILDA";
    break;
    case 263: displayName="GWENDOLYN";
    break;
    case 264: displayName="JENNIE";
    break;
    case 265: displayName="NORA";
    break;
    case 266: displayName="MARGIE";
    break;
    case 267: displayName="NINA";
    break;
    case 268: displayName="CASSANDRA";
    break;
    case 269: displayName="LEAH";
    break;
    case 270: displayName="PENNY";
    break;
    case 271: displayName="KAY";
    break;
    case 272: displayName="PRISCILLA";
    break;
    case 273: displayName="NAOMI";
    break;
    case 274: displayName="CAROLE";
    break;
    case 275: displayName="BRANDY";
    break;
    case 276: displayName="OLGA";
    break;
    case 277: displayName="BILLIE";
    break;
    case 278: displayName="DIANNE";
    break;
    case 279: displayName="TRACEY";
    break;
    case 280: displayName="LEONA";
    break;
    case 281: displayName="JENNY";
    break;
    case 282: displayName="FELICIA";
    break;
    case 283: displayName="SONIA";
    break;
    case 284: displayName="MIRIAM";
    break;
    case 285: displayName="VELMA";
    break;
    case 286: displayName="BECKY";
    break;
    case 287: displayName="BOBBIE";
    break;
    case 288: displayName="VIOLET";
    break;
    case 289: displayName="KRISTINA";
    break;
    case 290: displayName="TONI";
    break;
    case 291: displayName="MISTY";
    break;
    case 292: displayName="MAE";
    break;
    case 293: displayName="SHELLY";
    break;
    case 294: displayName="DAISY";
    break;
    case 295: displayName="RAMONA";
    break;
    case 296: displayName="SHERRI";
    break;
    case 297: displayName="ERIKA";
    break;
    case 298: displayName="KATRINA";
    break;
    case 299: displayName="CLAIRE";
    break;
    case 300: displayName="LINDSEY";
    break;
    case 301: displayName="LINDSAY";
    break;
    case 302: displayName="GENEVA";
    break;
    case 303: displayName="GUADALUPE";
    break;
    case 304: displayName="BELINDA";
    break;
    case 305: displayName="MARGARITA";
    break;
    case 306: displayName="SHERYL";
    break;
    case 307: displayName="CORA";
    break;
    case 308: displayName="FAYE";
    break;
    case 309: displayName="ADA";
    break;
    case 310: displayName="NATASHA";
    break;
    case 311: displayName="SABRINA";
    break;
    case 312: displayName="ISABEL";
    break;
    case 313: displayName="MARGUERITE";
    break;
    case 314: displayName="HATTIE";
    break;
    case 315: displayName="HARRIET";
    break;
    case 316: displayName="MOLLY";
    break;
    case 317: displayName="CECILIA";
    break;
    case 318: displayName="KRISTI";
    break;
    case 319: displayName="BRANDI";
    break;
    case 320: displayName="BLANCHE";
    break;
    case 321: displayName="SANDY";
    break;
    case 322: displayName="ROSIE";
    break;
    case 323: displayName="JOANNA";
    break;
    case 324: displayName="IRIS";
    break;
    case 325: displayName="EUNICE";
    break;
    case 326: displayName="ANGIE";
    break;
    case 327: displayName="INEZ";
    break;
    case 328: displayName="LYNDA";
    break;
    case 329: displayName="MADELINE";
    break;
    case 330: displayName="AMELIA";
    break;
    case 331: displayName="ALBERTA";
    break;
    case 332: displayName="GENEVIEVE";
    break;
    case 333: displayName="MONIQUE";
    break;
    case 334: displayName="JODI";
    break;
    case 335: displayName="JANIE";
    break;
    case 336: displayName="MAGGIE";
    break;
    case 337: displayName="KAYLA";
    break;
    case 338: displayName="SONYA";
    break;
    case 339: displayName="JAN";
    break;
    case 340: displayName="LEE";
    break;
    case 341: displayName="KRISTINE";
    break;
    case 342: displayName="CANDACE";
    break;
    case 343: displayName="FANNIE";
    break;
    case 344: displayName="MARYANN";
    break;
    case 345: displayName="OPAL";
    break;
    case 346: displayName="ALISON";
    break;
    case 347: displayName="YVETTE";
    break;
    case 348: displayName="MELODY";
    break;
    case 349: displayName="LUZ";
    break;
    case 350: displayName="SUSIE";
    break;
    case 351: displayName="OLIVIA";
    break;
    case 352: displayName="FLORA";
    break;
    case 353: displayName="SHELLEY";
    break;
    case 354: displayName="KRISTY";
    break;
    case 355: displayName="MAMIE";
    break;
    case 356: displayName="LULA";
    break;
    case 357: displayName="LOLA";
    break;
    case 358: displayName="VERNA";
    break;
    case 359: displayName="BEULAH";
    break;
    case 360: displayName="ANTOINETTE";
    break;
    case 361: displayName="CANDICE";
    break;
    case 362: displayName="JUANA";
    break;
    case 363: displayName="JEANNETTE";
    break;
    case 364: displayName="PAM";
    break;
    case 365: displayName="KELLI";
    break;
    case 366: displayName="HANNAH";
    break;
    case 367: displayName="WHITNEY";
    break;
    case 368: displayName="BRIDGET";
    break;
    case 369: displayName="KARLA";
    break;
    case 370: displayName="CELIA";
    break;
    case 371: displayName="LATOYA";
    break;
    case 372: displayName="PATTY";
    break;
    case 373: displayName="SHELIA";
    break;
    case 374: displayName="GAYLE";
    break;
    case 375: displayName="DELLA";
    break;
    case 376: displayName="VICKY";
    break;
    case 377: displayName="LYNNE";
    break;
    case 378: displayName="SHERI";
    break;
    case 379: displayName="MARIANNE";
    break;
    case 380: displayName="KARA";
    break;
    case 381: displayName="JACQUELYN";
    break;
    case 382: displayName="ERMA";
    break;
    case 383: displayName="BLANCA";
    break;
    case 384: displayName="MYRA";
    break;
    case 385: displayName="LETICIA";
    break;
    case 386: displayName="PAT";
    break;
    case 387: displayName="KRISTA";
    break;
    case 388: displayName="ROXANNE";
    break;
    case 389: displayName="ANGELICA";
    break;
    case 390: displayName="JOHNNIE";
    break;
    case 391: displayName="ROBYN";
    break;
    case 392: displayName="FRANCIS";
    break;
    case 393: displayName="ADRIENNE";
    break;
    case 394: displayName="ROSALIE";
    break;
    case 395: displayName="ALEXANDRA";
    break;
    case 396: displayName="BROOKE";
    break;
    case 397: displayName="BETHANY";
    break;
    case 398: displayName="SADIE";
    break;
    case 399: displayName="BERNADETTE";
    break;
    case 400: displayName="TRACI";
    break;
    case 401: displayName="JODY";
    break;
    case 402: displayName="KENDRA";
    break;
    case 403: displayName="JASMINE";
    break;
    case 404: displayName="NICHOLE";
    break;
    case 405: displayName="RACHAEL";
    break;
    case 406: displayName="CHELSEA";
    break;
    case 407: displayName="MABLE";
    break;
    case 408: displayName="ERNESTINE";
    break;
    case 409: displayName="MURIEL";
    break;
    case 410: displayName="MARCELLA";
    break;
    case 411: displayName="ELENA";
    break;
    case 412: displayName="KRYSTAL";
    break;
    case 413: displayName="ANGELINA";
    break;
    case 414: displayName="NADINE";
    break;
    case 415: displayName="KARI";
    break;
    case 416: displayName="ESTELLE";
    break;
    case 417: displayName="DIANNA";
    break;
    case 418: displayName="PAULETTE";
    break;
    case 419: displayName="LORA";
    break;
    case 420: displayName="MONA";
    break;
    case 421: displayName="DOREEN";
    break;
    case 422: displayName="ROSEMARIE";
    break;
    case 423: displayName="ANGEL";
    break;
    case 424: displayName="DESIREE";
    break;
    case 425: displayName="ANTONIA";
    break;
    case 426: displayName="HOPE";
    break;
    case 427: displayName="GINGER";
    break;
    case 428: displayName="JANIS";
    break;
    case 429: displayName="BETSY";
    break;
    case 430: displayName="CHRISTIE";
    break;
    case 431: displayName="FREDA";
    break;
    case 432: displayName="MERCEDES";
    break;
    case 433: displayName="MEREDITH";
    break;
    case 434: displayName="LYNETTE";
    break;
    case 435: displayName="TERI";
    break;
    case 436: displayName="CRISTINA";
    break;
    case 437: displayName="EULA";
    break;
    case 438: displayName="LEIGH";
    break;
    case 439: displayName="MEGHAN";
    break;
    case 440: displayName="SOPHIA";
    break;
    case 441: displayName="ELOISE";
    break;
    case 442: displayName="ROCHELLE";
    break;
    case 443: displayName="GRETCHEN";
    break;
    case 444: displayName="CECELIA";
    break;
    case 445: displayName="RAQUEL";
    break;
    case 446: displayName="HENRIETTA";
    break;
    case 447: displayName="ALYSSA";
    break;
    case 448: displayName="JANA";
    break;
    case 449: displayName="KELLEY";
    break;
    case 450: displayName="GWEN";
    break;
    case 451: displayName="KERRY";
    break;
    case 452: displayName="JENNA";
    break;
    case 453: displayName="TRICIA";
    break;
    case 454: displayName="LAVERNE";
    break;
    case 455: displayName="OLIVE";
    break;
    case 456: displayName="ALEXIS";
    break;
    case 457: displayName="TASHA";
    break;
    case 458: displayName="SILVIA";
    break;
    case 459: displayName="ELVIRA";
    break;
    case 460: displayName="CASEY";
    break;
    case 461: displayName="DELIA";
    break;
    case 462: displayName="SOPHIE";
    break;
    case 463: displayName="KATE";
    break;
    case 464: displayName="PATTI";
    break;
    case 465: displayName="LORENA";
    break;
    case 466: displayName="KELLIE";
    break;
    case 467: displayName="SONJA";
    break;
    case 468: displayName="LILA";
    break;
    case 469: displayName="LANA";
    break;
    case 470: displayName="DARLA";
    break;
    case 471: displayName="MAY";
    break;
    case 472: displayName="MINDY";
    break;
    case 473: displayName="ESSIE";
    break;
    case 474: displayName="MANDY";
    break;
    case 475: displayName="LORENE";
    break;
    case 476: displayName="ELSA";
    break;
    case 477: displayName="JOSEFINA";
    break;
    case 478: displayName="JEANNIE";
    break;
    case 479: displayName="MIRANDA";
    break;
    case 480: displayName="DIXIE";
    break;
    case 481: displayName="LUCIA";
    break;
    case 482: displayName="MARTA";
    break;
    case 483: displayName="FAITH";
    break;
    case 484: displayName="LELA";
    break;
    case 485: displayName="JOHANNA";
    break;
    case 486: displayName="SHARI";
    break;
    case 487: displayName="CAMILLE";
    break;
    case 488: displayName="TAMI";
    break;
    case 489: displayName="SHAWNA";
    break;
    case 490: displayName="ELISA";
    break;
    case 491: displayName="EBONY";
    break;
    case 492: displayName="MELBA";
    break;
    case 493: displayName="ORA";
    break;
    case 494: displayName="NETTIE";
    break;
    case 495: displayName="TABITHA";
    break;
    case 496: displayName="OLLIE";
    break;
    case 497: displayName="JAIME";
    break;
    case 498: displayName="WINIFRED";
    break;
    case 499: displayName="KRISTIE";
    break;
    case 500: displayName="MARINA";
    break;
    case 501: displayName="ALISHA";
    break;
    case 502: displayName="AIMEE";
    break;
    case 503: displayName="RENA";
    break;
    case 504: displayName="MYRNA";
    break;
    case 505: displayName="MARLA";
    break;
    case 506: displayName="TAMMIE";
    break;
    case 507: displayName="LATASHA";
    break;
    case 508: displayName="BONITA";
    break;
    case 509: displayName="PATRICE";
    break;
    case 510: displayName="RONDA";
    break;
    case 511: displayName="SHERRIE";
    break;
    case 512: displayName="ADDIE";
    break;
    case 513: displayName="FRANCINE";
    break;
    case 514: displayName="DELORIS";
    break;
    case 515: displayName="STACIE";
    break;
    case 516: displayName="ADRIANA";
    break;
    case 517: displayName="CHERI";
    break;
    case 518: displayName="SHELBY";
    break;
    case 519: displayName="ABIGAIL";
    break;
    case 520: displayName="CELESTE";
    break;
    case 521: displayName="JEWEL";
    break;
    case 522: displayName="CARA";
    break;
    case 523: displayName="ADELE";
    break;
    case 524: displayName="REBEKAH";
    break;
    case 525: displayName="LUCINDA";
    break;
    case 526: displayName="DORTHY";
    break;
    case 527: displayName="CHRIS";
    break;
    case 528: displayName="EFFIE";
    break;
    case 529: displayName="TRINA";
    break;
    case 530: displayName="REBA";
    break;
    case 531: displayName="SHAWN";
    break;
    case 532: displayName="SALLIE";
    break;
    case 533: displayName="AURORA";
    break;
    case 534: displayName="LENORA";
    break;
    case 535: displayName="ETTA";
    break;
    case 536: displayName="LOTTIE";
    break;
    case 537: displayName="KERRI";
    break;
    case 538: displayName="TRISHA";
    break;
    case 539: displayName="NIKKI";
    break;
    case 540: displayName="ESTELLA";
    break;
    case 541: displayName="FRANCISCA";
    break;
    case 542: displayName="JOSIE";
    break;
    case 543: displayName="TRACIE";
    break;
    case 544: displayName="MARISSA";
    break;
    case 545: displayName="KARIN";
    break;
    case 546: displayName="BRITTNEY";
    break;
    case 547: displayName="JANELLE";
    break;
    case 548: displayName="LOURDES";
    break;
    case 549: displayName="LAUREL";
    break;
    case 550: displayName="HELENE";
    break;
    case 551: displayName="FERN";
    break;
    case 552: displayName="ELVA";
    break;
    case 553: displayName="CORINNE";
    break;
    case 554: displayName="KELSEY";
    break;
    case 555: displayName="INA";
    break;
    case 556: displayName="BETTIE";
    break;
    case 557: displayName="ELISABETH";
    break;
    case 558: displayName="AIDA";
    break;
    case 559: displayName="CAITLIN";
    break;
    case 560: displayName="INGRID";
    break;
    case 561: displayName="IVA";
    break;
    case 562: displayName="EUGENIA";
    break;
    case 563: displayName="CHRISTA";
    break;
    case 564: displayName="GOLDIE";
    break;
    case 565: displayName="CASSIE";
    break;
    case 566: displayName="MAUDE";
    break;
    case 567: displayName="JENIFER";
    break;
    case 568: displayName="THERESE";
    break;
    case 569: displayName="FRANKIE";
    break;
    case 570: displayName="DENA";
    break;
    case 571: displayName="LORNA";
    break;
    case 572: displayName="JANETTE";
    break;
    case 573: displayName="LATONYA";
    break;
    case 574: displayName="CANDY";
    break;
    case 575: displayName="MORGAN";
    break;
    case 576: displayName="CONSUELO";
    break;
    case 577: displayName="TAMIKA";
    break;
    case 578: displayName="ROSETTA";
    break;
    case 579: displayName="DEBORA";
    break;
    case 580: displayName="CHERIE";
    break;
    case 581: displayName="POLLY";
    break;
    case 582: displayName="DINA";
    break;
    case 583: displayName="JEWELL";
    break;
    case 584: displayName="FAY";
    break;
    case 585: displayName="JILLIAN";
    break;
    case 586: displayName="DOROTHEA";
    break;
    case 587: displayName="NELL";
    break;
    case 588: displayName="TRUDY";
    break;
    case 589: displayName="ESPERANZA";
    break;
    case 590: displayName="PATRICA";
    break;
    case 591: displayName="KIMBERLEY";
    break;
    case 592: displayName="SHANNA";
    break;
    case 593: displayName="HELENA";
    break;
    case 594: displayName="CAROLINA";
    break;
    case 595: displayName="CLEO";
    break;
    case 596: displayName="STEFANIE";
    break;
    case 597: displayName="ROSARIO";
    break;
    case 598: displayName="OLA";
    break;
    case 599: displayName="JANINE";
    break;
    case 600: displayName="MOLLIE";
    break;
    case 601: displayName="LUPE";
    break;
    case 602: displayName="ALISA";
    break;
    case 603: displayName="LOU";
    break;
    case 604: displayName="MARIBEL";
    break;
    case 605: displayName="SUSANNE";
    break;
    case 606: displayName="BETTE";
    break;
    case 607: displayName="SUSANA";
    break;
    case 608: displayName="ELISE";
    break;
    case 609: displayName="CECILE";
    break;
    case 610: displayName="ISABELLE";
    break;
    case 611: displayName="LESLEY";
    break;
    case 612: displayName="JOCELYN";
    break;
    case 613: displayName="PAIGE";
    break;
    case 614: displayName="JONI";
    break;
    case 615: displayName="RACHELLE";
    break;
    case 616: displayName="LEOLA";
    break;
    case 617: displayName="DAPHNE";
    break;
    case 618: displayName="ALTA";
    break;
    case 619: displayName="ESTER";
    break;
    case 620: displayName="PETRA";
    break;
    case 621: displayName="GRACIELA";
    break;
    case 622: displayName="IMOGENE";
    break;
    case 623: displayName="JOLENE";
    break;
    case 624: displayName="KEISHA";
    break;
    case 625: displayName="LACEY";
    break;
    case 626: displayName="GLENNA";
    break;
    case 627: displayName="GABRIELA";
    break;
    case 628: displayName="KERI";
    break;
    case 629: displayName="URSULA";
    break;
    case 630: displayName="LIZZIE";
    break;
    case 631: displayName="KIRSTEN";
    break;
    case 632: displayName="SHANA";
    break;
    case 633: displayName="ADELINE";
    break;
    case 634: displayName="MAYRA";
    break;
    case 635: displayName="JAYNE";
    break;
    case 636: displayName="JACLYN";
    break;
    case 637: displayName="GRACIE";
    break;
    case 638: displayName="SONDRA";
    break;
    case 639: displayName="CARMELA";
    break;
    case 640: displayName="MARISA";
    break;
    case 641: displayName="ROSALIND";
    break;
    case 642: displayName="CHARITY";
    break;
    case 643: displayName="TONIA";
    break;
    case 644: displayName="BEATRIZ";
    break;
    case 645: displayName="MARISOL";
    break;
    case 646: displayName="CLARICE";
    break;
    case 647: displayName="JEANINE";
    break;
    case 648: displayName="SHEENA";
    break;
    case 649: displayName="ANGELINE";
    break;
    case 650: displayName="FRIEDA";
    break;
    case 651: displayName="LILY";
    break;
    case 652: displayName="ROBBIE";
    break;
    case 653: displayName="SHAUNA";
    break;
    case 654: displayName="MILLIE";
    break;
    case 655: displayName="CLAUDETTE";
    break;
    case 656: displayName="CATHLEEN";
    break;
    case 657: displayName="ANGELIA";
    break;
    case 658: displayName="GABRIELLE";
    break;
    case 659: displayName="AUTUMN";
    break;
    case 660: displayName="KATHARINE";
    break;
    case 661: displayName="SUMMER";
    break;
    case 662: displayName="JODIE";
    break;
    case 663: displayName="STACI";
    break;
    case 664: displayName="LEA";
    break;
    case 665: displayName="CHRISTI";
    break;
    case 666: displayName="JIMMIE";
    break;
    case 667: displayName="JUSTINE";
    break;
    case 668: displayName="ELMA";
    break;
    case 669: displayName="LUELLA";
    break;
    case 670: displayName="MARGRET";
    break;
    case 671: displayName="DOMINIQUE";
    break;
    case 672: displayName="SOCORRO";
    break;
    case 673: displayName="RENE";
    break;
    case 674: displayName="MARTINA";
    break;
    case 675: displayName="MARGO";
    break;
    case 676: displayName="MAVIS";
    break;
    case 677: displayName="CALLIE";
    break;
    case 678: displayName="BOBBI";
    break;
    case 679: displayName="MARITZA";
    break;
    case 680: displayName="LUCILE";
    break;
    case 681: displayName="LEANNE";
    break;
    case 682: displayName="JEANNINE";
    break;
    case 683: displayName="DEANA";
    break;
    case 684: displayName="AILEEN";
    break;
    case 685: displayName="LORIE";
    break;
    case 686: displayName="LADONNA";
    break;
    case 687: displayName="WILLA";
    break;
    case 688: displayName="MANUELA";
    break;
    case 689: displayName="GALE";
    break;
    case 690: displayName="SELMA";
    break;
    case 691: displayName="DOLLY";
    break;
    case 692: displayName="SYBIL";
    break;
    case 693: displayName="ABBY";
    break;
    case 694: displayName="LARA";
    break;
    case 695: displayName="DALE";
    break;
    case 696: displayName="IVY";
    break;
    case 697: displayName="DEE";
    break;
    case 698: displayName="WINNIE";
    break;
    case 699: displayName="MARCY";
    break;
    case 700: displayName="LUISA";
    break;
    case 701: displayName="JERI";
    break;
    case 702: displayName="MAGDALENA";
    break;
    case 703: displayName="OFELIA";
    break;
    case 704: displayName="MEAGAN";
    break;
    case 705: displayName="AUDRA";
    break;
    case 706: displayName="MATILDA";
    break;
    case 707: displayName="LEILA";
    break;
    case 708: displayName="CORNELIA";
    break;
    case 709: displayName="BIANCA";
    break;
    case 710: displayName="SIMONE";
    break;
    case 711: displayName="BETTYE";
    break;
    case 712: displayName="RANDI";
    break;
    case 713: displayName="VIRGIE";
    break;
    case 714: displayName="LATISHA";
    break;
    case 715: displayName="BARBRA";
    break;
    case 716: displayName="GEORGINA";
    break;
    case 717: displayName="ELIZA";
    break;
    case 718: displayName="LEANN";
    break;
    case 719: displayName="BRIDGETTE";
    break;
    case 720: displayName="RHODA";
    break;
    case 721: displayName="HALEY";
    break;
    case 722: displayName="ADELA";
    break;
    case 723: displayName="NOLA";
    break;
    case 724: displayName="BERNADINE";
    break;
    case 725: displayName="FLOSSIE";
    break;
    case 726: displayName="ILA";
    break;
    case 727: displayName="GRETA";
    break;
    case 728: displayName="RUTHIE";
    break;
    case 729: displayName="NELDA";
    break;
    case 730: displayName="MINERVA";
    break;
    case 731: displayName="LILLY";
    break;
    case 732: displayName="TERRIE";
    break;
    case 733: displayName="LETHA";
    break;
    case 734: displayName="HILARY";
    break;
    case 735: displayName="ESTELA";
    break;
    case 736: displayName="VALARIE";
    break;
    case 737: displayName="BRIANNA";
    break;
    case 738: displayName="ROSALYN";
    break;
    case 739: displayName="EARLINE";
    break;
    case 740: displayName="CATALINA";
    break;
    case 741: displayName="AVA";
    break;
    case 742: displayName="MIA";
    break;
    case 743: displayName="CLARISSA";
    break;
    case 744: displayName="LIDIA";
    break;
    case 745: displayName="CORRINE";
    break;
    case 746: displayName="ALEXANDRIA";
    break;
    case 747: displayName="CONCEPCION";
    break;
    case 748: displayName="TIA";
    break;
    case 749: displayName="SHARRON";
    break;
    case 750: displayName="RAE";
    break;
    case 751: displayName="DONA";
    break;
    case 752: displayName="ERICKA";
    break;
    case 753: displayName="JAMI";
    break;
    case 754: displayName="ELNORA";
    break;
    case 755: displayName="CHANDRA";
    break;
    case 756: displayName="LENORE";
    break;
    case 757: displayName="NEVA";
    break;
    case 758: displayName="MARYLOU";
    break;
    case 759: displayName="MELISA";
    break;
    case 760: displayName="TABATHA";
    break;
    case 761: displayName="SERENA";
    break;
    case 762: displayName="AVIS";
    break;
    case 763: displayName="ALLIE";
    break;
    case 764: displayName="SOFIA";
    break;
    case 765: displayName="JEANIE";
    break;
    case 766: displayName="ODESSA";
    break;
    case 767: displayName="NANNIE";
    break;
    case 768: displayName="HARRIETT";
    break;
    case 769: displayName="LORAINE";
    break;
    case 770: displayName="PENELOPE";
    break;
    case 771: displayName="MILAGROS";
    break;
    case 772: displayName="EMILIA";
    break;
    case 773: displayName="BENITA";
    break;
    case 774: displayName="ALLYSON";
    break;
    case 775: displayName="ASHLEE";
    break;
    case 776: displayName="TANIA";
    break;
    case 777: displayName="TOMMIE";
    break;
    case 778: displayName="ESMERALDA";
    break;
    case 779: displayName="KARINA";
    break;
    case 780: displayName="EVE";
    break;
    case 781: displayName="PEARLIE";
    break;
    case 782: displayName="ZELMA";
    break;
    case 783: displayName="MALINDA";
    break;
    case 784: displayName="NOREEN";
    break;
    case 785: displayName="TAMEKA";
    break;
    case 786: displayName="SAUNDRA";
    break;
    case 787: displayName="HILLARY";
    break;
    case 788: displayName="AMIE";
    break;
    case 789: displayName="ALTHEA";
    break;
    case 790: displayName="ROSALINDA";
    break;
    case 791: displayName="JORDAN";
    break;
    case 792: displayName="LILIA";
    break;
    case 793: displayName="ALANA";
    break;
    case 794: displayName="GAY";
    break;
    case 795: displayName="CLARE";
    break;
    case 796: displayName="ALEJANDRA";
    break;
    case 797: displayName="ELINOR";
    break;
    case 798: displayName="MICHAEL";
    break;
    case 799: displayName="LORRIE";
    break;
    case 800: displayName="JERRI";
    break;
    case 801: displayName="DARCY";
    break;
    case 802: displayName="EARNESTINE";
    break;
    case 803: displayName="CARMELLA";
    break;
    case 804: displayName="TAYLOR";
    break;
    case 805: displayName="NOEMI";
    break;
    case 806: displayName="MARCIE";
    break;
    case 807: displayName="LIZA";
    break;
    case 808: displayName="ANNABELLE";
    break;
    case 809: displayName="LOUISA";
    break;
    case 810: displayName="EARLENE";
    break;
    case 811: displayName="MALLORY";
    break;
    case 812: displayName="CARLENE";
    break;
    case 813: displayName="NITA";
    break;
    case 814: displayName="SELENA";
    break;
    case 815: displayName="TANISHA";
    break;
    case 816: displayName="KATY";
    break;
    case 817: displayName="JULIANNE";
    break;
    case 818: displayName="JOHN";
    break;
    case 819: displayName="LAKISHA";
    break;
    case 820: displayName="EDWINA";
    break;
    case 821: displayName="MARICELA";
    break;
    case 822: displayName="MARGERY";
    break;
    case 823: displayName="KENYA";
    break;
    case 824: displayName="DOLLIE";
    break;
    case 825: displayName="ROXIE";
    break;
    case 826: displayName="ROSLYN";
    break;
    case 827: displayName="KATHRINE";
    break;
    case 828: displayName="NANETTE";
    break;
    case 829: displayName="CHARMAINE";
    break;
    case 830: displayName="LAVONNE";
    break;
    case 831: displayName="ILENE";
    break;
    case 832: displayName="KRIS";
    break;
    case 833: displayName="TAMMI";
    break;
    case 834: displayName="SUZETTE";
    break;
    case 835: displayName="CORINE";
    break;
    case 836: displayName="KAYE";
    break;
    case 837: displayName="JERRY";
    break;
    case 838: displayName="MERLE";
    break;
    case 839: displayName="CHRYSTAL";
    break;
    case 840: displayName="LINA";
    break;
    case 841: displayName="DEANNE";
    break;
    case 842: displayName="LILIAN";
    break;
    case 843: displayName="JULIANA";
    break;
    case 844: displayName="ALINE";
    break;
    case 845: displayName="LUANN";
    break;
    case 846: displayName="KASEY";
    break;
    case 847: displayName="MARYANNE";
    break;
    case 848: displayName="EVANGELINE";
    break;
    case 849: displayName="COLETTE";
    break;
    case 850: displayName="MELVA";
    break;
    case 851: displayName="LAWANDA";
    break;
    case 852: displayName="YESENIA";
    break;
    case 853: displayName="NADIA";
    break;
    case 854: displayName="MADGE";
    break;
    case 855: displayName="KATHIE";
    break;
    case 856: displayName="EDDIE";
    break;
    case 857: displayName="OPHELIA";
    break;
    case 858: displayName="VALERIA";
    break;
    case 859: displayName="NONA";
    break;
    case 860: displayName="MITZI";
    break;
    case 861: displayName="MARI";
    break;
    case 862: displayName="GEORGETTE";
    break;
    case 863: displayName="CLAUDINE";
    break;
    case 864: displayName="FRAN";
    break;
    case 865: displayName="ALISSA";
    break;
    case 866: displayName="ROSEANN";
    break;
    case 867: displayName="LAKEISHA";
    break;
    case 868: displayName="SUSANNA";
    break;
    case 869: displayName="REVA";
    break;
    case 870: displayName="DEIDRE";
    break;
    case 871: displayName="CHASITY";
    break;
    case 872: displayName="SHEREE";
    break;
    case 873: displayName="CARLY";
    break;
    case 874: displayName="JAMES";
    break;
    case 875: displayName="ELVIA";
    break;
    case 876: displayName="ALYCE";
    break;
    case 877: displayName="DEIRDRE";
    break;
    case 878: displayName="GENA";
    break;
    case 879: displayName="BRIANA";
    break;
    case 880: displayName="ARACELI";
    break;
    case 881: displayName="KATELYN";
    break;
    case 882: displayName="ROSANNE";
    break;
    case 883: displayName="WENDI";
    break;
    case 884: displayName="TESSA";
    break;
    case 885: displayName="BERTA";
    break;
    case 886: displayName="MARVA";
    break;
    case 887: displayName="IMELDA";
    break;
    case 888: displayName="MARIETTA";
    break;
    case 889: displayName="MARCI";
    break;
    case 890: displayName="LEONOR";
    break;
    case 891: displayName="ARLINE";
    break;
    case 892: displayName="SASHA";
    break;
    case 893: displayName="MADELYN";
    break;
    case 894: displayName="JANNA";
    break;
    case 895: displayName="JULIETTE";
    break;
    case 896: displayName="DEENA";
    break;
    case 897: displayName="AURELIA";
    break;
    case 898: displayName="JOSEFA";
    break;
    case 899: displayName="AUGUSTA";
    break;
    case 900: displayName="LILIANA";
    break;
    case 901: displayName="YOUNG";
    break;
    case 902: displayName="CHRISTIAN";
    break;
    case 903: displayName="LESSIE";
    break;
    case 904: displayName="AMALIA";
    break;
    case 905: displayName="SAVANNAH";
    break;
    case 906: displayName="ANASTASIA";
    break;
    case 907: displayName="VILMA";
    break;
    case 908: displayName="NATALIA";
    break;
    case 909: displayName="ROSELLA";
    break;
    case 910: displayName="LYNNETTE";
    break;
    case 911: displayName="CORINA";
    break;
    case 912: displayName="ALFREDA";
    break;
    case 913: displayName="LEANNA";
    break;
    case 914: displayName="CAREY";
    break;
    case 915: displayName="AMPARO";
    break;
    case 916: displayName="COLEEN";
    break;
    case 917: displayName="TAMRA";
    break;
    case 918: displayName="AISHA";
    break;
    case 919: displayName="WILDA";
    break;
    case 920: displayName="KARYN";
    break;
    case 921: displayName="CHERRY";
    break;
    case 922: displayName="QUEEN";
    break;
    case 923: displayName="MAURA";
    break;
    case 924: displayName="MAI";
    break;
    case 925: displayName="EVANGELINA";
    break;
    case 926: displayName="ROSANNA";
    break;
    case 927: displayName="HALLIE";
    break;
    case 928: displayName="ERNA";
    break;
    case 929: displayName="ENID";
    break;
    case 930: displayName="MARIANA";
    break;
    case 931: displayName="LACY";
    break;
    case 932: displayName="JULIET";
    break;
    case 933: displayName="JACKLYN";
    break;
    case 934: displayName="FREIDA";
    break;
    case 935: displayName="MADELEINE";
    break;
    case 936: displayName="MARA";
    break;
    case 937: displayName="HESTER";
    break;
    case 938: displayName="CATHRYN";
    break;
    case 939: displayName="LELIA";
    break;
    case 940: displayName="CASANDRA";
    break;
    case 941: displayName="BRIDGETT";
    break;
    case 942: displayName="ANGELITA";
    break;
    case 943: displayName="JANNIE";
    break;
    case 944: displayName="DIONNE";
    break;
    case 945: displayName="ANNMARIE";
    break;
    case 946: displayName="KATINA";
    break;
    case 947: displayName="BERYL";
    break;
    case 948: displayName="PHOEBE";
    break;
    case 949: displayName="MILLICENT";
    break;
    case 950: displayName="KATHERYN";
    break;
    case 951: displayName="DIANN";
    break;
    case 952: displayName="CARISSA";
    break;
    case 953: displayName="MARYELLEN";
    break;
    case 954: displayName="LIZ";
    break;
    case 955: displayName="LAURI";
    break;
    case 956: displayName="HELGA";
    break;
    case 957: displayName="GILDA";
    break;
    case 958: displayName="ADRIAN";
    break;
    case 959: displayName="RHEA";
    break;
    case 960: displayName="MARQUITA";
    break;
    case 961: displayName="HOLLIE";
    break;
    case 962: displayName="TISHA";
    break;
    case 963: displayName="TAMERA";
    break;
    case 964: displayName="ANGELIQUE";
    break;
    case 965: displayName="FRANCESCA";
    break;
    case 966: displayName="BRITNEY";
    break;
    case 967: displayName="KAITLIN";
    break;
    case 968: displayName="LOLITA";
    break;
    case 969: displayName="FLORINE";
    break;
    case 970: displayName="ROWENA";
    break;
    case 971: displayName="REYNA";
    break;
    case 972: displayName="TWILA";
    break;
    case 973: displayName="FANNY";
    break;
    case 974: displayName="JANELL";
    break;
    case 975: displayName="INES";
    break;
    case 976: displayName="CONCETTA";
    break;
    case 977: displayName="BERTIE";
    break;
    case 978: displayName="ALBA";
    break;
    case 979: displayName="BRIGITTE";
    break;
    case 980: displayName="ALYSON";
    break;
    case 981: displayName="VONDA";
    break;
    case 982: displayName="PANSY";
    break;
    case 983: displayName="ELBA";
    break;
    case 984: displayName="NOELLE";
    break;
    case 985: displayName="LETITIA";
    break;
    case 986: displayName="KITTY";
    break;
    case 987: displayName="DEANN";
    break;
    case 988: displayName="BRANDIE";
    break;
    case 989: displayName="LOUELLA";
    break;
    case 990: displayName="LETA";
    break;
    case 991: displayName="FELECIA";
    break;
    case 992: displayName="SHARLENE";
    break;
    case 993: displayName="LESA";
    break;
    case 994: displayName="BEVERLEY";
    break;
    case 995: displayName="ROBERT";
    break;
    case 996: displayName="ISABELLA";
    break;
    case 997: displayName="HERMINIA";
    break;
    case 998: displayName="TERRA";
    break;
    case 999: displayName="CELINA";
    break;
    }
}

void frameworkTop()
{
    string displayMonth,weather,displaySeason;
    switch(speicher[162])
    {
        case 1: displayMonth="January  ";
        break;
        case 2: displayMonth="February ";
        break;
        case 3: displayMonth="March    ";
        break;
        case 4: displayMonth="April    ";
        break;
        case 5: displayMonth="May      ";
        break;
        case 6: displayMonth="June     ";
        break;
        case 7: displayMonth="July     ";
        break;
        case 8: displayMonth="August   ";
        break;
        case 9: displayMonth="September";
        break;
        case 10: displayMonth="October ";
        break;
        case 11: displayMonth="November";
        break;
        case 12: displayMonth="December";
        break;
        default:;
    }
    if(speicher[163] && speicher[164]>10)
        weather="Rainy        ";//Bennenung für Regen bei über 10 Grad
    else
        if(speicher[163] && speicher[164]>0)
            weather="Stormy       ";//Bennenung für Regen bei 1 bis 10 Grad
        else
            if(speicher[163] && speicher[164]>-5)
                weather="Snowy        ";//Bennenung für Regen bei -4 bis 0 Grad
            else
                if(speicher[163])
                    weather="Snowstorm    ";//Bennenung für Regen bei weniger als -4 Grad
                else
                {
                    switch(speicher[166])
                    {
                        case 0: weather="Clear Sky    ";
                        break;
                        case 1: weather="Clear Sky    ";
                        break;
                        case 2: weather="Clear Sky    ";
                        break;
                        case 3: weather="Partly Cloudy";
                        break;
                        case 4: weather="Cloudy       ";
                        break;
                        case 5: weather="Darkened     ";
                        default:;
                    }
                }
    switch(speicher[2])//Speicher[2]=Jahreszeit
    {
        case 1: displaySeason="Spring";
        break;
        case 2: displaySeason="Summer";
        break;
        case 3: displaySeason="Fall  ";
        break;
        case 4: displaySeason="Winter";
        break;
        default: displaySeason="ERROR ";
    }
    cout << "<--------------------------------------------------------------------------->\n";
    cout << "<-----Round: ";
    if(speicher[1]<10)//Speicher[1]=Runde
        cout << "         " << speicher[1];
    else
        if(speicher[1]<100)
            cout << "        " << speicher[1];
        else
            if(speicher[1]<1000)
                cout << "       " << speicher[1];
            else
                if(speicher[1]<10000)
                    cout << "      " << speicher[1];
                else
                    if(speicher[1]<100000)
                        cout << "     " << speicher[1];
                    else
                        if(speicher[1]<1000000)
                            cout << "    " << speicher[1];
                        else
                            cout << "   " << speicher[1];
    cout << " -----Season: " << displaySeason;
    cout << " -----Month: Maybe " << displayMonth << "----->\n";
    cout << "<--------------------------------------------------------------------------->\n";
    cout << "<---Weather: " << weather;
    if(speicher[50])//Speicher[50]=Forschung Meteorologie
    {
        cout << "---Temperature: ";
        if(speicher[164]<-9)
            cout << speicher[164];
        else
            if(speicher[164]<0)
                cout << " " << speicher[164];
            else
                if(speicher[164]<10)
                    cout << "  " << speicher[164];
                else
                    cout << " " << speicher[164];
        cout << " ---Z-Activity: ";
        if(speicher[161])
            if(speicher[165]<21)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cout << "Very Low";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cout << "    --->\n";
            }
            else
                if(speicher[165]<41)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    cout << "Low";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    cout << "         --->\n";
                }
                else
                    if(speicher[165]<61)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        cout << "Normal";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        cout << "      --->\n";
                    }
                    else
                        if(speicher[165]<81)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                            cout << "High";
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                            cout << "        --->\n";
                        }
                        else
                            if(speicher[165]<101)
                            {
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                                cout << "Very High";
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                                cout << "   --->\n";
                            }
                            else
                            {
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                                cout << "Extreme";
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                                cout << "      --->\n";
                            }
        else
            if(speicher[165]<21)
                cout << "Very Low    --->\n";
            else
                if(speicher[165]<41)
                    cout << "Low         --->\n";
                else
                    if(speicher[165]<61)
                        cout << "Normal      --->\n";
                    else
                        if(speicher[165]<81)
                            cout << "High        --->\n";
                        else
                            if(speicher[165]<101)
                                cout << "Very High   --->\n";
                            else
                                cout << "Extreme     ---->\n";
    }
    else//Ausgabe ohne Meteorologie
    {
        cout << "---Temperature: ";
        if(speicher[164]<-4)
            cout << "Damn Cold";
        else
            if(speicher[164]<1)
                cout << "Very Cold";
            else
                if(speicher[164]<6)
                    cout << "Cold     ";
                else
                    if(speicher[164]<16)
                        cout << "Fresh    ";
                    else
                        if(speicher[164]<26)
                            cout << "Warm     ";
                        else
                            if(speicher[164]<31)
                                cout << "Hot      ";
                            else
                                if(speicher[164]<39)
                                    cout << "Very Hot ";
                                else
                                    cout << "Damn Hot ";
        cout << " ------------------------>\n";
    }
    cout << "<--------------------------------------------------------------------------->\n";
}

void frameworkBottom()
{
    cout << "<--------------------------------------------------------------------------->\n";
        cout << "<Character info ";
        cout << charName;
        int spaces = charName.length();
        spaces = 10-spaces;
        for(;spaces;spaces--)
            cout << "-";
        cout << "-------------------------------------------------->\n";
        cout << "<----- HP:     ";
        if(speicher[161])//Einstellung ob Farben dargestellt werden oder nicht
            if(speicher[22]<34)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            else
                if(speicher[22]<67)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                else
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        else;
        if(speicher[22]<10)//Speicher[22]=HP Charakter
            cout << "  " << speicher[22];
        else
            if(speicher[22]<100)
                cout << " " << speicher[22];
            else
                cout << speicher[22];
        cout << "/";
        if(speicher[156<10])//Speicher[156]=Maximale HP Charakter
            cout << speicher[156] << "  ";
        else
            if(speicher[156]<100)
                cout << speicher[156] << " ";
            else
                cout << speicher[156];
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << " ----- Level: ";
        if(speicher[24]<10)//Speicher[24]=Level Charakter
            cout << " " << speicher[24];
        else
            cout << speicher[24];
        cout << "      ----- Status: ";
        if(speicher[26]==1 && speicher[22]==speicher[156])//Speicher[26]=Status Speicher[22]=HP Speicher[156] Max HP
            cout << "Healthy            >\n";
        else
            if(speicher[26]==2)
            cout << "Weary              >\n";
            else
                if(speicher[26]==3)
                    cout << "Feverish           >\n";
                else
                    if(speicher[26]==4)
                        cout << "Really sick        >\n";
                    else
                        if(speicher[26]==5)
                            cout << "Probably infected  >\n";
                        else
                            cout << "Wounded            >\n";
        cout << "<----- Morale: ";
        if(speicher[161])//Einstellung ob Farben dargestellt werden oder nicht
            if(speicher[23]<34)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            else
                if(speicher[23]<67)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                else
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        else;
        if(speicher[23]<10)//Speicher[23]=Moral Charakter
            cout << "  " << speicher[23];
        else
            if(speicher[23]<100)
                cout << " " << speicher[23];
            else
                cout << speicher[23];
        cout << "/";
        if(speicher[157]<10)//Maximale Moral
            cout << speicher[157] << "  ";
        else
            if(speicher[157]<100)
                cout << speicher[157] << " ";
            else
                cout << speicher[157];
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "----- EP:   ";
        if(speicher[25]<10)//EP Charakter
            cout << "  " << speicher[25];
        else
            if(speicher[25]<100)
                cout << " " << speicher[25];
            else
                cout << speicher[25];
        cout << "/";
        if((speicher[24]*10)<100)//Level des Charakters
            cout << speicher[24]*10+10 << " ";
        else
            cout << speicher[24]*10+10;
        cout << "  -----         ";
        if(speicher[22]==speicher[156])
            cout << "                    >\n";
        else
            if(speicher[22]>90)
                cout << "Just a scratch     >\n";
            else
                if(speicher[22]>80)
                    cout << "Bruised            >\n";
                else
                    if(speicher[22]>60)
                        cout << "Just a flesh wound >\n";
                    else
                        if(speicher[22]>40)
                            cout << "Injured            >\n";
                        else
                            if(speicher[22]>20)
                                cout << "Looks pretty bad   >\n";
                            else
                                cout << "Almost dead        >\n";
        cout << "<--------------------------------------------------------------------------->\n";
}

void ClearScreen()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }
