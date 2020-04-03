# SoalShiftSISOP20_modul3_C03
Kelompok C03:
* _Irsyadhani Dwi Shubhi (0511184000022)_
* _Reihan Nanda Ramadhan (05111840000132)_

----------------------------------------------------------------
## Soal
* [Soal 1](#Soal-1-Poke-ZONE)
  * [Soal 1 pokezone](#Soal-1-pokezone)
  * [Soal 1 traizone](#Soal-1-traizone)
* [Soal 2](#Soal-2-Tap-Tap-Game)
* [Soal 3](#Soal-3-Pengkategorian-File)
* [Soal 4](#Soal-4-Norland-Pecahkan-Matriks)
  * [Soal 4.a.](#soal-4a)
  * [Soal 4.b.](#soal-4b)
  * [Soal 4.c.](#soal-4c)
----------------------------------------------------------------

# Soal 1 Poke ZONE
   _**Soal:**_

> Source Code: [Soal 1 pokezone](https://github.com/irsyadhani22/SoalShiftSISOP20_modul3_C03/blob/master/soal1/soal1_pokezone.c)

> Source Code: [Soal 1 traizone](https://github.com/irsyadhani22/SoalShiftSISOP20_modul3_C03/blob/master/soal1/soal1_traizone.c)

#

#### Soal 1 pokezone:

_**Penyelesaian:**_

```c

```
Hasil eksekusi program:
![alt text](https://github.com/irsyadhani22/SoalShiftSISOP20_modul3_C03/blob/master/soal1/gambar/soal1_pokezone.png "Hasil Soal 1 pokezone")

#

#### Soal 1 traizone:

_**Penyelesaian:**_

```c

```
Hasil eksekusi program:
![alt text](https://github.com/irsyadhani22/SoalShiftSISOP20_modul3_C03/blob/master/soal1/gambar/soal1_traizone.png "Hasil Soal 1 traizone")

#

_**Kendala:**_

# 

# Soal 2 Tap Tap Game
  
_**Soal 2:**_


> Source Code: [Soal 2](https://github.com/irsyadhani22/SoalShiftSISOP20_modul3_C03/blob/master/soal2/soal2.c)

#

_**Penyelesaian:**_

```c

```
Hasil eksekusi program:
![alt text](https://github.com/irsyadhani22/SoalShiftSISOP20_modul3_C03/blob/master/soal2/gambar/soal2.png "Hasil Soal 2")

#

_**Kendala:**_


#

# Soal 3 Pengkategorian File

_**Soal 3:**_
Buatlah sebuah program dari C untuk mengkategorikan file. Program ini akan
memindahkan file sesuai ekstensinya (tidak case sensitive. JPG dan jpg adalah
sama) ke dalam folder sesuai ekstensinya yang folder hasilnya terdapat di working
directory ketika program kategori tersebut dijalankan.

● Semisal program dijalankan:
#### File kategori terletak di /home/izone/kategori

> $ ./kategori -f path/to/file1.jpg path/to/file2.c path/to/file3.zip

#### Hasilnya adalah sebagai berikut
```
/home/izone
 -jpg
 --file1.jpg
 -c
 --file2.c
 -zip
 --file3.zip
 
```
● Pada opsi -f tersebut, user bisa menambahkan argumen file yang bisa
dikategorikan sebanyak yang user inginkan seperti contoh di atas.

● Pada program kategori tersebut, folder jpg,c,zip tidak dibuat secara manual,
melainkan melalui program c. Semisal ada file yang tidak memiliki ekstensi,
maka dia akan disimpan dalam folder “Unknown”.

● Program kategori ini juga menerima perintah (*) seperti di bawah;

> $ ./kategori \*

● Artinya mengkategori seluruh file yang ada di working directory ketika
menjalankan program C tersebut.

● Selain hal itu program C ini juga menerima opsi -d untuk melakukan kategori
pada suatu directory. Untuk opsi -d ini, user hanya bisa menginput 1 directory
saja, tidak seperti file yang bebas menginput file sebanyak mungkin.
> $ ./kategori -d /path/to/directory/

● Hasilnya perintah di atas adalah mengkategorikan file di /path/to/directory dan
hasilnya akan disimpan di working directory di mana program C tersebut
berjalan (hasil kategori filenya bukan di /path/to/directory).

● Program ini tidak rekursif. Semisal di directory yang mau dikategorikan, atau
menggunakan (*) terdapat folder yang berisi file, maka file dalam folder
tersebut tidak dihiraukan, cukup file pada 1 level saja.

● Setiap 1 file yang dikategorikan dioperasikan oleh 1 thread agar bisa berjalan
secara paralel sehingga proses kategori bisa berjalan lebih cepat. Dilarang
juga menggunakan fork-exec dan system.

● Silahkan download soal3.zip sebagai percobaan. Namun silahkan
dicoba-coba sendiri untuk kemungkinan test case lainnya yang mungkin
belum ada di soal3.zip.

> Source Code: [Soal 3](https://github.com/irsyadhani22/SoalShiftSISOP20_modul3_C03/blob/master/Soal%203/3.c)

#

_**Penyelesaian:**_


```c

```
Hasil eksekusi program:
![alt text](https://github.com/irsyadhani22/SoalShiftSISOP20_modul3_C03/blob/master/soal3/gambar/soal3.png "Hasil Soal 3")

#

_**Kendala:**_

#

# Soal 4 Norland Pecahkan Matriks
   _**Soal:**_
Norland adalah seorang penjelajah terkenal. Pada suatu malam Norland menyusuri
jalan setapak menuju ke sebuah gua dan mendapati tiga pilar yang pada setiap
pilarnya ada sebuah batu berkilau yang tertancap. Batu itu berkilau di kegelapan dan
setiap batunya memiliki warna yang berbeda.
Norland mendapati ada sebuah teka-teki yang tertulis di setiap pilar. Untuk dapat
mengambil batu mulia di suatu pilar, Ia harus memecahkan teka-teki yang ada di
pilar tersebut. Norland menghampiri setiap pilar secara bergantian.

> Source Code: [Soal 4.a.](https://github.com/irsyadhani22/SoalShiftSISOP20_modul3_C03/blob/master/soal4/soal4a.c)

> Source Code: [Soal 4.b.](https://github.com/irsyadhani22/SoalShiftSISOP20_modul3_C03/blob/master/soal4/soal4b.c)

> Source Code: [Soal 4.c.](https://github.com/irsyadhani22/SoalShiftSISOP20_modul3_C03/blob/master/soal4/soal4c.c)

#

#### Soal 4.a.:
Buatlah program C dengan nama "4a.c", yang berisi program untuk
melakukan perkalian matriks. Ukuran matriks pertama adalah 4x2, dan
matriks kedua 2x5. Isi dari matriks didefinisikan di dalam kodingan. Matriks
nantinya akan berisi angka 1-20 (tidak perlu dibuat filter angka).

_**Penyelesaian:**_

```c

```
Hasil eksekusi program:
![alt text](https://github.com/irsyadhani22/SoalShiftSISOP20_modul3_C03/blob/master/soal4/gambar/soal4a.png "Hasil Soal 4a")

#

#### Soal 4.b.:
Buatlah program C kedua dengan nama "4b.c". Program ini akan
mengambil variabel hasil perkalian matriks dari program "4a.c". Setelah ditampilkan, berikutnya untuk setiap angka dari matriks
tersebut, carilah nilai faktorialnya.

_**Penyelesaian:**_

```c

```
Hasil eksekusi program:
![alt text](https://github.com/irsyadhani22/SoalShiftSISOP20_modul3_C03/blob/master/soal4/gambar/soal4b.png "Hasil Soal 4b")

#

#### Soal 4.c.:
Norland diminta mengetahui jumlah file dan
folder di direktori saat ini dengan command "ls | wc -l". Karena sudah belajar
IPC, Norland mengerjakannya dengan semangat.

_**Penyelesaian:**_

```c

```
Hasil eksekusi program:
![alt text](https://github.com/irsyadhani22/SoalShiftSISOP20_modul3_C03/blob/master/soal4/gambar/soal4c.png "Hasil Soal 4c")
#

_**Kendala:**_
