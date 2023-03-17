#include<iostream>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<fstream>

using namespace std;

 class KaySif
 {   

    private:
    char metin[100];
    char sifreliMetin[100];
    char desifreliMetin[100];
    string alfabe = "abcdefghijklmnopqrstuvwxyz";

    int anahtar = 3; // anahtar degeri 3 ise sezar sifreleem algoritmasına girer 
    
    int uzunluk;

    public:

    int menu();
    void inputAl();
    void sifrele();
    void desifrele();
    void kaydet();
    void oku();
   

 };

  int KaySif::menu()

  {

    int secim;

    do 
    {

    system("color B");
    cout<<"\nKaydirmali Sifreleme Algoritmasi\n"<<endl;
    cout<<"1. Sifrele"<<endl;
    cout<<"2. Desifrele"<<endl;
    cout<<"3. Sifreli Kaydet"<<endl;
    cout<<"4. Sifreli Oku"<<endl;
    cout<<"5. Cikis"<<endl;
    cout<<"Seciminiz: ";
    secim =getche () - '0';
    system("cls");
    cout<<endl;
    cout<<endl;

    }
    while ( secim < 0 || secim > 4 ); 
    
    return secim;
   

  }
   
  void KaySif:: inputAl()

  {
    char key[5];
    cout<<"Anahtar degeri giriniz: ";
    fgets(key,5,stdin);
    anahtar= atoi(key); // anahtar degeri string olarak girildiği için atoi fonksiyonu ile int e çevirildi

    cout<<"Metin : ";
    fgets(metin,100,stdin);
    uzunluk = strlen(metin);
    metin[uzunluk-1] = '\0';
    strlwr(metin);
    cout<<"Metin : "<<metin<<endl;

  } 

  void KaySif::sifrele()

  {
    
    inputAl();
    
    int i;
    i=0;
    
    while ( i < uzunluk)
    {

        int j;
        
        bool durum = false;
        for ( j = 0; j < 26 ; j++)
        {

            if( metin[i] == alfabe[j] )
            {
                
                durum = true;
                int indis;
                indis = j;
                indis = indis + anahtar;
                if( indis >= 26 )
                indis = indis %26;
                sifreliMetin[i] = alfabe[indis];
                break;

            }
            
        }

        if ( durum == false )
        sifreliMetin[i] = metin[i];


        i++;

    }

    sifreliMetin[i] = '\0';
    system("cls");
    cout<<"Sifreli Metin : "<<sifreliMetin<<endl;

  }
    

    void KaySif::desifrele()

  {
    
    inputAl();
    
    int i;
    i=0;
    
    while ( i < uzunluk)
    {

        int j;
        
        bool durum = false;
        for ( j = 0; j < 26 ; j++)
        {

            if( sifreliMetin[i] == alfabe[j] )
            {
                
                durum = true;
                int indis;
                indis = j;
                indis = indis - anahtar;
                if( indis < 0 )
                indis = indis + 26;
                desifreliMetin[i] = alfabe[indis];
                break;

            }
            
        }

        if ( durum == false )
        desifreliMetin[i] = metin[i];


        i++;

    }

    desifreliMetin[i] = '\0';
    system("cls");
    cout<<"deSifreli Metin : "<<desifreliMetin<<endl;

  }
  
  void KaySif::kaydet()

  {
    
    ofstream ofile("kayit.txt");
    
    if( !ofile )
    {

      cout<<"Dosya olusturulamadi ! ";
      exit(1);

    } 

    sifrele(); 

    ofile.write((char *) &sifreliMetin, sizeof(sifreliMetin));
    ofile.close();
    system("cls");
    cout<<"Kayit basarili !"<<endl;




  }

  void KaySif::oku()

  {
    
    ifstream ifile("kayit.txt");
    
    if( !ifile )
    {

      cout<<"Dosya okuma islemi basarisiz ! ";
      exit(1);

    } 

    sifrele(); 

    ifile.read((char *) &sifreliMetin, sizeof(sifreliMetin));
    ifile.close();
    system("cls");

    desifrele();

    system("cls");

    cout<<desifreliMetin<<endl;

    cout<<"Okuma islemi basarili sekilde tamamlandi !"<<endl;



  }

int main()

{

     KaySif ks;
     int  secim = ks.menu();

     while( secim != 0)

     {
       
       switch(secim)

       {
         
         case 1:
         ks.sifrele();
         break;

         case 2:
         ks.desifrele();
         break;

         case 3:
         ks.kaydet();
         break;

         case 4:
         ks.oku();
         break; 

       }
     
      secim = ks.menu();


     }
      


    return 0;

}