#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;
class Hesap
{
	private:
		int hesapNO;
		string AD;
		double bakiye;
	public:
		Hesap(int no, string ad, double ilkbakiye)
		{
			hesapNO = no;
			AD = ad;
			bakiye = ilkbakiye;
		}
		void bilgiyazdir()
		{
			cout << left
				<< setw(12) << hesapNO
				<< setw(20) << AD
				<< setw(12) << bakiye << endl;
		}
		void paraYatir(double miktar)
		{
			if (miktar > 0)
			{
				bakiye += miktar;
				cout << "Yeni bakiye: " << bakiye << endl;
			}
			else
			{
				cout << "Gecersiz miktar!" << endl;
			}
		}
		void paraCek(double miktar)
		{
			if (miktar > 0 && miktar <= bakiye)
			{
				bakiye -= miktar;
				cout << "Yeni bakiye: " << bakiye << endl;
			}
			else if (miktar <= 0)
			{
				cout << "Gecersiz miktar!\n";
			}
			else if (miktar > bakiye)
			{
				cout << "Yetersiz bakiye!\n";
			}
		}
		int getHesapNo() const
		{
			return hesapNO;
		}
		string getAd() const { return AD; }
		double getBakiye() const { return bakiye; }

};
int main()
{
	vector <Hesap> hesaplar;
	ifstream oku("hesaplar.txt");
	if (oku.is_open())
	{
		string noStr, isim, bakiyeStr;
		while (getline(oku, noStr, ',') && getline(oku, isim, ',') && getline(oku, bakiyeStr))
		{
			if (!bakiyeStr.empty() && bakiyeStr.back() == '\r')
			{
				bakiyeStr.pop_back();
			}

			if (noStr.empty() || bakiyeStr.empty()) continue;

			try
			{
				int no = stoi(noStr);
				double bakiye = stod(bakiyeStr);
				hesaplar.push_back(Hesap(no, isim, bakiye));
			}
			catch (...)
			{
				continue;
			}
		}
		oku.close();
		cout << "[Bilgi] Onceki veriler basariyla yuklendi.\n";
	}
	else
	{
		cout << "[Bilgi] Kayit dosyasi bulunamadi, sifir veritabani ile baslatiliyor.\n";
	}
	int secim = 0;
	while (secim != 5)
	{
		cout << "=== BANKA SISTEMI ===" << endl;
		cout << "1. Yeni Hesap Ac" << endl;
		cout << "2. Hesaplari Listele" << endl;
		cout << "3. Para Yatir" << endl;
		cout << "4. Para Cek" << endl;
		cout << "5. Cikis" << endl;
		cout << "Seciminiz: ";
		cin >> secim;
		switch(secim)
		{
		case 1:
		{
			int no; string isim; double bakiye;
			cout << "Hesap numaranizi girin: ";
			cin >> no;
			bool zatenVar = false;
			for (int i = 0; i < hesaplar.size(); i++)
			{
				if (hesaplar[i].getHesapNo() == no)
				{
					zatenVar = true;
					break;
				}
			}

			if (zatenVar)
			{
				cout << "Hata: Bu hesap numarasi zaten kullanimda!\n";
				break; 
			}
			cin.ignore();
			cout << "Adinizi ve soyadinizi girin: ";
			getline(cin, isim);
			cout << "Bakiyenizi girin: ";
			cin >> bakiye;
			hesaplar.push_back(Hesap(no, isim, bakiye));
			cout << "Hesap basariyla acildi.\n";
			break;
		}
		case 2:
		{
			if (hesaplar.empty())
			{
				cout << "\nSistemde kayitli hesap bulunmamaktadir.\n";
				break;
			}
			cout << "\n--------------------------------------------\n";
			cout << left
				<< setw(12) << "Hesap No"
				<< setw(20) << "Musteri Adi"
				<< setw(12) << "Bakiye (TL)" << endl;
			cout << "--------------------------------------------\n";

			for (int i = 0; i < hesaplar.size(); i++)
			{
				hesaplar[i].bilgiyazdir();
			}
			cout << "--------------------------------------------\n";
			break;
		}
		case 3:
		{
			int arananNO;
			cout << "Islem yapilacak hesap numarasini girin: ";
			cin >> arananNO;
			bool bulundu = false;
			for (int i = 0; i < hesaplar.size(); i++)
			{
				if (hesaplar[i].getHesapNo() == arananNO)
				{
					bulundu = true;
					double miktar;
					cout << "Yatirmak istediginiz miktari girin: ";
					cin >> miktar;
					hesaplar[i].paraYatir(miktar);
					break;
				}
			}
			if (!bulundu)
			{
				cout << "Bu numaraya ait hesap bulunamadi!\n";
			}

			break;
		}
		case 4:
		{
			int arananNO;
			cout << "Islem yapilacak hesap numarasini girin: ";
			cin >> arananNO;
			bool bulundu = false;
			for (int i = 0; i < hesaplar.size(); i++)
			{
				if (hesaplar[i].getHesapNo() == arananNO)
				{
					bulundu = true;
					double miktar;
					cout << "Cekmek istediginiz miktari girin: ";
					cin >> miktar;
					hesaplar[i].paraCek(miktar);
					break;
				}
			}
			if (!bulundu)
			{
				cout << "Bu numaraya ait hesap bulunamadi!\n";
			}

			break;
		}
		case 5:
		{
			ofstream dosya("hesaplar.txt");
			if (!dosya)
			{	cout << "Dosya acilamadi, kayit yapilamiyor.\n";
				break;}
			else
			{
				for (int i = 0; i < hesaplar.size(); i++)
				{
					dosya << hesaplar[i].getHesapNo() << ","
						<< hesaplar[i].getAd() << ","
						<< hesaplar[i].getBakiye() << "\n";
				}
			}
			dosya.close();
			cout << "Tum veriler dosyaya kaydedildi. Cikis yapiliyor...\n";
			break;
		}
		default:
		{
			cout << "Hatali secim, tekrar deneyin." << endl;
			break;
		}
		}
	}

}