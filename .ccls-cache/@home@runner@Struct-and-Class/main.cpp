#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class ktp{
    friend istream& operator >> (istream&, ktp&);
    friend ostream& operator << (ostream&, ktp&); 
private:
char nik[16], nama[20];
int goldar;
int agama;
string berlaku = "Seumur Hidup";
string pekerjaan;
bool kewarga;
bool status;
bool jkel;
 
};

struct{
string tempat;
int tgl,bln,thn;
}tanggal; 

struct{
string jalan,kecamatan,desa;
int rt,rw;
}alamat;

istream& operator >> (istream& in, ktp& input){
	cout << "Input NIK: "; in >> input.nik;
  cout << "Input NAMA: "; in >> input.nama;
  cout << "Input Tempat:"; in >> tanggal.tempat;
  cout << "Masukkan tanggal: "; in >> tanggal.tgl;
  cout << "Masukkan Bulan: "; in >> tanggal.bln;
  cout << "Masukkan Tahun: "; in >> tanggal.thn;
  cout << "Masukkan Jenis Kelamin (0/1) "<<endl;
  cout << "0. Perempuan"<<endl;
  cout << "1. Laki-Laki"<<endl;
  in >> input.jkel;
  cout << "Masukkan Pilihan Goldar : " << endl;
  cout << "1. A " << endl;
  cout << "2. B " << endl;
  cout << "3. O " << endl;
  cout << "4. AB" << endl;
  in >> input.goldar;
  cout << "Masukkan Jalan: "; in >> alamat.jalan;
  cout << "Masukkan RT: "; in >> alamat.rt;
  cout << "Masukkan RW: "; in >> alamat.rw;
  cout << "Masukkan Kel/Desa : "; in >> alamat.desa;
  cout << "Masukkan Kecamatan : "; in >> alamat.kecamatan;
  cout << "Masukkan Agama : " << endl;
  cout << "1. Islam" << endl;
  cout << "2. Katolik" << endl;
  cout << "3. Kristen" << endl;
  cout << "4. Buddha" << endl;
  cout << "5. Hindu" << endl;
  cout << "6. Konghuchu" << endl;
  in >> input.agama;
  cout << "Masukkan Status (0/1) "<<endl;
  cout << "0. Tidak Kawin"<<endl;
  cout << "1. Kawin"<<endl;
  in >> input.status;
  cout << "Masukkan Perkerjaan : "; in >> input.pekerjaan;
  cout << "Masukkan Kewarganegaraan (0/1) "<<endl;
  cout << "0. WNI"<<endl;
  cout << "1. WNA"<<endl;
  
	return in;
}

ostream& operator << (ostream& out, ktp& output){
	out << "\n\n";
	out << "NIK\t\t\t:";
	if(strlen(output.nik)<17)
		out<<"NIK anda kurang dari 16 angka";
	if(strlen(output.nik)>17)
		out<<"NIK anda lebih dari 16 angka";
	else if(strlen(output.nik)==17)
	 out<<output.nik;
  out << "\nNAMA\t\t\t:"<<output.nama;
  out << "\nTempat/Tgl Lahir:"<< tanggal.tempat;
	out << "\nJenis Kelamin\t\t:";
	if(output.jkel==true)
		out<<"Laki-laki";
	else if(output.jkel==false)
		out<<"Perempuan";
	out << "\t\tGol.Darah:";
	switch(output.goldar){
		case 1:
			out<<"A";
		break;
		case 2:
			out<<"B";
		break;
		case 3:	
			out<<"O";
		break;
		case 4:
			out<<"AB";
		break;
	}
	out << "\nAlamat\t\t\t:"<<alamat.jalan;
	out << "\n\tRT/RW\t\t:"<<alamat.rt<<"/"<<alamat.rw;
	out << "\n\tKel/Desa\t:"<<alamat.desa;
	out << "\n\tKecamatan\t:"<<alamat.kecamatan;
	out << "\nAgama\t\t\t:";
  switch(output.agama){
		case 1:
			out<<"Islam";
		break;
		case 2:
			out<<"Protestan";
		break;
		case 3:	
			out<<"Kristen";
		break;
		case 4:
			out<<"Buddha";
		break;
    case 5:
      out << "Hindu";
    break;
    case 6:
      out << "Konghuchu";
    break;
	}
	out << "\nStatus Perkawinan\t:";
  if(output.status==true)
		out<<"KAWIN";
	else if(output.status==false)
		out<<"BELUM KAWIN";
	out << "\nPekerjaan\t\t:"<<output.pekerjaan;
	out << "\nKewarganegaraan\t\t:";
		if(output.kewarga==true)
			out<<"WNA";
		else if(output.kewarga==false)
			out<<"WNI";
	out << "\nBerlaku hingga\t\t:"<<output.berlaku;
	return out;
}

int main() {
  ktp obj;
	cin>>obj;
	cout<<obj;
}