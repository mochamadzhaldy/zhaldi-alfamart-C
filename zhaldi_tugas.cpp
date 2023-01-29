#include <iostream>
#include <vector>

using namespace std;

struct Barang{
  string nama;
  vector<string>ukuran;
  vector<string> variant;
  vector<long> harga;
  vector<long> jumlah;
};

struct Keranjang{
  string nama;
  string ukuran;
  string variant;
  long harga;
  long int jumlah;
};

vector<Keranjang> keranjang;

vector<Barang> daftarBarang{
  {
    "Mama Lemon",
    {"400 ml", "760 ml", "800 ml"},
    {"Jeruk nipis", "Habatusauda", "Strawberry"},
    {1000, 26000, 40000},
    {}
  },
  {
    "Sunlight",
    {"400 ml", "700 ml", "900 ml"},
    {"Jeruk nipis", "Habatusauda", "Power white"},
    {1000, 19000, 33000},
    {}
  },
  {
    "Sari Roti",
    {"Tawar", "Bantal", "Jumbo"},
    {"Coklat", "Keju", "Anggur"},
    {1000, 26000, 15000},
    {}
  },
  {
    "Minyak",
    {"400 ml", "760 ml", "1 Liter"},
    {"Sunco", "Bimoli", "Fortune"},
    {1000, 36000, 40000},
    {},
  },
};

void masukkanKeranjang(string nama, string ukuran, string variant, long harga, int jumlah) {
  keranjang.push_back({nama, ukuran, variant, harga, jumlah});
}

void tampilkanDetailBarang(Barang barang) {
  int pilihNomorjenis, pilihNomorvariant,jumlahBarang;

  cout << "==== Barang " << barang.nama << " ====\n\n";

  // jenis barang
  cout << "Daftar Ukuran Barang :\n";
  for (int i = 0; i < barang.ukuran.size(); i++) {
    cout << i + 1 << ". " << barang.ukuran[i] << "\n";
  }

  cout << "\nPilih  : ";
  cin >> pilihNomorjenis;
  // jenis barang


    system("cls");
  // variant barang
  cout << "Daftar variant Barang :\n";
  for (int i = 0; i < barang.variant.size(); i++) {
    cout << i + 1 << ". " << barang.variant[i] << "\n";
  }

  cout << "\nPilih : ";
  cin >> pilihNomorvariant;
  // variant barang

  cout << "\nJumlah Barang : ";
  cin >> jumlahBarang;


  masukkanKeranjang(barang.nama, barang.ukuran[pilihNomorjenis - 1], barang.variant[pilihNomorvariant - 1], barang.harga[pilihNomorjenis - 1],jumlahBarang);
}

int main() {
  int pilihNomornama;
  char ulang;
  int totalHarga1 = 0,tunai;

  do {
    cout << "================ Kasir Alfamaradassat ================\n";
    cout << "Keranjang : " << keranjang.size() << "\n\n";
    
    for (int i = 0; i < daftarBarang.size(); i++) {
      cout << i + 1 << ". " << daftarBarang[i].nama << "\n";
    }

    cout << "\nPilih nomer Barang (1 - " << daftarBarang.size() << ") : ";
    cin >> pilihNomornama;

    system("cls");

    tampilkanDetailBarang(daftarBarang[pilihNomornama - 1]);


    cout << "\n\nApakah ingin membeli yang lain? (y/t) : ";
    cin >> ulang;

    system("cls");
  } while (ulang == 'y');

  cout << "==== Keranjang Belanja Anda ====\n\n";
  for (int i = 0; i < keranjang.size(); i++) {
    cout << i + 1 << ". "<<keranjang[i].nama << " | Jumlah : "<<keranjang[i].jumlah << " | Rp."<<keranjang[i].harga <<" | Total : "<< keranjang[i].harga * keranjang[i].jumlah<<"\n";
  }

  cout << "\nTotal harga : Rp ";
  for (int i = 0; i < keranjang.size(); i++) {
    totalHarga1 = keranjang[i].harga * keranjang[i].jumlah + totalHarga1 ;
  }
// 6474280
  cout << totalHarga1;
  repeatPembayaran:
  cout << "\n\nMasukan Tunai : ";
  cin >> tunai;

    if(tunai > totalHarga1){
        cout <<"Kembalian : Rp." << tunai - totalHarga1<<endl;
        cout <<"Terima Kasih \n";
    }else{
        cout <<"Kurang duitnya";
        goto repeatPembayaran;
    }
}