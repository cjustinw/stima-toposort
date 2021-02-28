# Tugas Kecil II IF2211 Strategi Algoritma Semester 2 Tahun 2020/2021

## Penjelasan singkat algoritma Decrease and Conquer yang diimplementasikan
Pada  permasalahan  penyusunan  rencana  kuliah  dengan  topological  sort,  vertex  di  dalam himpunan  vertex  graf  G  akan  terus  dikurangi  hingga  graf  G  kosong.  Vertex  yang dikeluarkan/dikurangi  dari  graf  G  menandakan  bahwa  vertex  mata  kuliah  tersebut  sudah disusun pada suatu semester tertentu. Sisa vertex graf G merupakan mata kuliah yang akan disusun pada semester yang lebih tinggi dari vertex yang telah dikeluarkan (karena adanya prasyarat). Hal ini mengakibatkan ukuran himpunan vertex graf G menjadi lebih kecil dari sebelumnya sehingga permasalahan ini dapat diselesaikan dengan pendekatan Decrease and Conquer. Karena untuk setiap perulangan jumlah vertex yang mempunyai derajat masuk = 0 dapat bervariasi yang menandakan jumlah mata kuliah yang dapat diambil pada satu semester maka permasalahan ini termasuk dalam decrease by variable size. 

### Algoritma Topological Sort (Decrease and Conquer)
1.  Buatlah Directed Acyclic Graph (DAG) G yang setiap vertex nya terdiri dari kode mata kuliah. Setiap vertex juga menyimpan nilai dari derajat masuk dan derajat keluar. 
2.  Untuk setiap vertex yang mempunyai derajat masuk = 0, masukkan ke dalam array hasil L. 
3.  Kumpulan  vertex  yang  terdapat  di  dalam  array  L  merupakan  mata  kuliah  yang  dapat diambil pada suatu semester tertentu. Cetak ke layar untuk mendapakan daftar mata kuliah yang dapat diambil pada suatu semester tertentu. 
4.  Hapus untuk setiap vertex di dalam array L dari graf G. Hal ini akan mengakibatkan derajat masuk dari vertex successornya dikurangi satu. 
5.  Ulangi langkah 2 – 4 hingga graf G kosong. Setiap langkah perulangan merepresentasikan satu semester.

## Cara menggunakan program
- Buka directory src pada terminal
- Jalankan g++ -o TopoSort.exe 13519006-TopoSort.cpp 13519006-Graph.cpp 13519006-ListNode.cpp 13519006-Node.cpp
- Jalankan ./TopoSort.exe

## Tentang
Nama  : Christopher Justine William
NIM   : 13519006
Kelas : K-01
