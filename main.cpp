//G1A021042

#include <iostream>
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct Mahasiswa{
  string Lagu;

  Mahasiswa *next;
};

Mahasiswa *head, *tail, *newNode, *cur, *del;

// create Circular Single Linked List
void createCircularSingleLinkedList(string laguBaru){

  head = new Mahasiswa();
  head->Lagu = laguBaru;
  tail = head;
  tail->next = head;

}

//Algoritma menambahkan data di awal list 
void addFirst( string data ){
  if( head == NULL ){
    cout << "List Kosong" << endl;
  }else{
    newNode = new Mahasiswa();
    newNode->Lagu = data;
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}

//Algoritma menambahkan data di akhir list
void addLast( string data ){
  if( head == NULL ){
    cout << "List Kosong" << endl;
  }else{
    newNode = new Mahasiswa();
    newNode->Lagu = data;
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}

//Algoritma menambahkan data pada posisi tertentu di dalam list
void addAfter(string data, int posisi)
{
  if( head == NULL ){
    cout << "List Kosong" << endl;
  }else{
    if( posisi == 1 ){
      cout <<"Lakukan addFirst" << endl;
    }else{
      newNode = new Mahasiswa();
      newNode->Lagu = data;

      // tranversing
      int nomor = 1;
      cur = head;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

//Algoritma menghapus data di awal list
void removeFirst(){
  if( head == NULL ){
    cout << "List Kosong" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    delete del;
  }
}

//Algoritma menghapus data di akhir list
void removeLast()
{
  if( head == NULL ){
    cout << "List Kosong" << endl;
  }else{
    del = tail;
    cur = head;
    while( cur->next != tail ){
      cur = cur->next;
    }
    tail = cur;
    tail->next = head;
    delete del;
  }
}

//Algoritma menghapus data pada posisi tertentu di dalam list
void removeAfter(int posisi)
{
  if( head == NULL ){
    cout << "List Kosong" << endl;
  }else{
    // tranversing
    int nomor = 1;
    cur = head;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    del = cur->next;
    cur->next = del->next;
    delete del;
  }
}

//algoritma menampilkan data di dalam list
void printCircular()
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    cout << "Playlist lagu\t\t " << endl;
    cur = head;
    while (cur->next != head)
    {
      // print
      cout << cur->Lagu << endl;
      cur = cur->next;
    }
    cout << cur->Lagu << "\t " << endl;
    cout << "_________________________________________________________________" << endl;
  }
}

int main(){
  string laguBaru = {"UN Village - BAEKHYUN"};
  createCircularSingleLinkedList(laguBaru);
  printCircular();

  string data = {"INVU - TAEYON"};
  addFirst(data);
  printCircular();

  string data2 = {"Hati-hati di jalan - TULUS"};
  addLast(data2);
  printCircular();
  
  string data3 = {"Beautiful goodbye - CHEN"};
  addAfter(data3, 3);
  printCircular();

  string data4 = {"Angel Baby - TROYE SIVAN"};
  addFirst(data4);
  printCircular();

  string data5 = {"Duka - LAST CHILD"};
  addLast(data5);
  printCircular();

  removeFirst();
  printCircular();

  removeLast();
  printCircular();

  removeAfter(4);
  printCircular();
}
