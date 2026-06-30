[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/licenses/MIT)
![GitHub last commit](https://img.shields.io/github/last-commit/cakraawijaya/Conveyor-with-PWM-Speed-and-Item-Counting?logo=Codeforces&logoColor=white&color=%23F7DF1E)
![Project](https://img.shields.io/badge/Project-STM8-light.svg?style=flat&logo=STMicroelectronics&logoColor=white&color=%23F7DF1E)
![Type](https://img.shields.io/badge/Type-Personal%20Experiment-light.svg?style=flat&logo=gitbook&logoColor=white&color=%23F7DF1E)

# Automatic Items Counter on STM8-based Conveyor
Penghitung barang otomatis merupakan alat bantu yang cepat dan tepat bagi manusia untuk mendapatkan hasil penjumlahan barang. Tujuan diadakannya proyek ini adalah untuk memberikan edukasi kepada masyarakat luas tentang bagaimana cara membuat alat penghitung barang otomatis yang sederhana. Proyek ini telah dilaksanakan dan memakan waktu kurang lebih 1 hari. Sistem ini dibuat untuk digunakan sebagai pelengkap pada konveyor. Selain itu, sistem ini juga telah disediakan fitur display dan reset untuk kebutuhan penggunanya. Cara kerja dari sistem ini yaitu apabila barang yang diangkut oleh konveyor itu berada tepat di depan pancaran sinar laser, maka intensitas cahaya yang diterima oleh sensor LDR itu rendah, sehingga dianggap ada barang dan mulai dihitung. Adapun hasil penghitungannya akan ditampilkan pada layar LCD. Proyek ini akan berguna bagi para pelaku bisnis, karena dapat meningkatkan efisiensi dalam produksi. Hasil penelitian menunjukkan bahwa sistem yang dibuat ini dapat berfungsi dengan baik.

<br><br>

## Kebutuhan Proyek
| Bagian | Deskripsi |
| --- | --- |
| Papan Pengembangan | STM8S103F3P6 |
| Editor Kode | Arduino IDE 1.8.19 (Versi Lama yang Stabil) |
| Alat Pemrogram | ST-Link/V2 |
| Alat Komunikasi Serial | USB FTDI |
| Driver | • ST-Link USB Driver<br>• CDM FTDI USB Driver |
| Protokol Komunikasi | Inter Integrated Circuit (I2C) |
| Bahasa Pemrograman | C/C++ |
| Pustaka Arduino | LiquidCrystal_I2C (bawaan) |
| Sensor | • Modul Sensor LDR (x1)<br>• KY-008: Modul Pemancar Laser 5V (x1) |
| Layar | LCD I2C (x1) |
| Komponen Lainnya | • Kabel USB Mikro - USB tipe A (x1)<br>• Kabel USB Mini - USB tipe A (x1)<br>• Kabel jumper (1 set)<br>• Adaptor DC 5V (x1)<br>• Breadboard (x1)<br>• Tombol tekan 12 x 12 mm (x1) |

<br><br>

## Unduh & Instal
1. Arduino IDE

   <table><tr><td width="810">

   ```
   https://bit.ly/ArduinoIDE_Installer
   ```

   </td></tr></table><br>

2. ST-Link USB Driver

   <table><tr><td width="810">
   
   ```
   https://bit.ly/STLink_USBdriver
   ```

   </td></tr></table><br>
   
3. CDM FTDI USB Driver

   <table><tr><td width="810">
   
   ```
   https://bit.ly/CDM_FTDI_USBdriver
   ```

   </td></tr></table>
   
<br><br>

## Rancangan Proyek
<table>
<tr>
<th width="420">Diagram Blok</th>
<th width="420">Diagram Ilustrasi</th>
</tr>
<tr>
<td><img src="Assets/Documentation/Diagram/Block Diagram.jpg" alt="block-diagram"></td>
<td><img src="Assets/Documentation/Diagram/Pictorial Diagram.jpg" alt="pictorial-diagram"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Pengkabelan</th>
</tr>
<tr>
<td><img width="840" src="Assets/Documentation/Table/Device Wiring.jpg" alt="wiring"></td>
</tr>
</table>

<br><br>

## Memindai Alamat I2C Yang Ada Pada LCD
<table><tr><td width="840">

```ino
/*
  =====================================================
  I2C Scanner untuk STM8S103F3P6
  by: Devan Cakra Mudra Wijaya, S.Kom.
  =====================================================

  Fungsi:
  - Mendeteksi seluruh perangkat I2C yang terhubung
  - Menampilkan alamat perangkat dalam format HEX
  - Menampilkan jumlah perangkat yang ditemukan


  =====================================================
  Pin SDA dan SCL untuk STM8S103F3P6
  =====================================================
  SDA -> PB5
  SCL -> PB4
*/

// Memanggil library I2C untuk komunikasi I2C
#include "I2C.h"

// Konstanta untuk menentukan jeda antar scan (5000 ms = 5 detik)
const uint16_t SCAN_INTERVAL = 5000;


// Fungsi setup() dijalankan satu kali saat board pertama kali menyala atau reset
// Digunakan untuk inisialisasi perangkat keras, komunikasi serial, sensor, modul, dan konfigurasi awal program
void setup() {

  // Memulai komunikasi Serial dengan baud rate 9600
  Serial_begin(9600);

  // Menunggu selama 5 detik sebelum program dimulai
  delay(5000);

  // Menampilkan header program
  Serial_println_s("====================================");
  Serial_println_s("         I2C DEVICE SCANNER         ");
  Serial_println_s("by: Devan Cakra Mudra Wijaya, S.Kom.");
  Serial_println_s("====================================");

  // Mencetak baris kosong
  Serial_println_s("");

  // Menginisialisasi komunikasi I2C
  I2C_begin();
}


// Fungsi loop() dijalankan terus-menerus setelah Fungsi setup() selesai
// Seluruh logika utama program biasanya ditempatkan di dalam fungsi ini
void loop() {

  // Variabel untuk menyimpan kode error hasil komunikasi I2C
  uint8_t error;

  // Variabel untuk menyimpan alamat I2C yang sedang diperiksa
  uint8_t address;

  // Variabel penghitung jumlah device yang ditemukan
  uint8_t deviceCount = 0;

  // Menampilkan informasi bahwa proses scan dimulai
  Serial_println_s("------------------------------------");
  Serial_println_s("Scanning I2C bus...");
  Serial_println_s("------------------------------------");

  // Melakukan perulangan dari alamat 1 sampai 126
  // Alamat I2C valid adalah 0x01 sampai 0x7E
  for (address = 1; address < 127; address++) {

    // Melakukan transaksi penulisan I2C (driver I2C STM8)
    // Digunakan untuk menguji respons ACK dari perangkat
    // Kode kesalahan bergantung pada implementasi driver I2C
    error = I2C_write(address, 0x00);

    // Jika tidak ada error, maka:
    if (error == 0) {

      // Menampilkan informasi device ditemukan
      Serial_print_s("[FOUND] Device at address 0x");

      // Jika alamat kurang dari 16, maka:
      // Tambahkan angka 0 di depan agar format HEX rapi
      if (address < 16) {
        Serial_print_s("0");
      }

      // Menampilkan alamat dalam format HEX
      Serial_print_ub(address, HEX);
      Serial_println_s("");

      // Menambah jumlah device yang ditemukan
      deviceCount++;
    }

    // Jika terjadi error tidak dikenal, maka:
    else if (error == 4) {

      // Menampilkan pesan error
      Serial_print_s("[ERROR] Unknown error at address 0x");

      // Jika alamat kurang dari 16, maka:
      // Tambahkan angka 0 di depan agar format HEX rapi
      if (address < 16) {
        Serial_print_s("0");
      }

      // Menampilkan alamat yang bermasalah dalam format HEX
      Serial_print_ub(address, HEX);
      Serial_println_s("");
    }

    // Jika error selain 0 atau 4, maka:
    // Diabaikan, biasanya ini terjadi karena tidak ada perangkat pada alamat tersebut
  }

  // Mencetak baris kosong
  Serial_println_s("");

  // Jika tidak ada device ditemukan, maka:
  if (deviceCount == 0) {

    // Tampilkan pesan tidak ada device
    Serial_println_s("No I2C devices found.");
  }
  else { // Jika setidaknya satu perangkat ditemukan, maka:

    // Menampilkan jumlah device yang ditemukan
    Serial_print_s("Total devices found: ");

    // Menampilkan nilai deviceCount
    Serial_print_ub(deviceCount, DEC);
    Serial_println_s("");
  }

  // Menampilkan informasi waktu scan berikutnya
  Serial_print_s("Next scan in ");

  // Mengubah milidetik menjadi detik
  Serial_print_ub(SCAN_INTERVAL / 1000, DEC);

  // Menampilkan satuan detik
  Serial_println_s(" seconds.");

  // Baris kosong
  Serial_println_s("\n");

  // Menunggu selama 5 detik sebelum scan ulang
  delay(SCAN_INTERVAL);
}
```

</td></tr></table><br><br>

## Pengaturan Arduino IDE
1. Buka ``` Arduino IDE ``` terlebih dahulu, kemudian buka proyek ini dengan cara klik ``` File ``` -> ``` Open ``` :

   <table><tr><td width="810">
   
      ``` auto_counter.ino ```

   </td></tr></table><br>
   
2. Isi ``` Url Pengelola Papan Tambahan ``` di Arduino IDE

   <table><tr><td width="810">
      
   Klik ``` File ``` -> ``` Preferences ``` -> masukkan ``` Boards Manager Url ``` dengan menyalin tautan berikut :
   
   ```
   https://raw.githubusercontent.com/tenbaht/sduino/master/package_sduino_stm8_index.json
   ```

   </td></tr></table><br>
   
3. ``` Pengaturan Board ``` di Arduino IDE

   <table>
      <tr><th width="810">
            
      Cara mengatur board ``` STM8S103F3P6 ```
   
      </th></tr>
      <tr><td width="810">

      • Klik ``` Tools ``` -> ``` Board ``` -> ``` Boards Manager ``` -> Instal ``` Sduino STM8 plain C core (non-C++) ```.

      • Kemudian pilih papan dengan mengklik: ``` Tools ``` -> ``` Board ``` -> ``` STM8S Boards ``` -> ``` STM8S103F3 Breakout Board ```.
              
      </td></tr>
   </table><br>
   
4. ``` Ubah Pemrogram ``` di Arduino IDE

   <table><tr><td width="810">
      
   Klik ``` Tools ``` -> ``` Programmer ``` -> ``` ST-Link/V2 ```

   </td></tr></table><br>
   
5. Sebelum mengunggah program, silakan klik: ``` Verify ```.<br><br>

6. Jika tidak ada kesalahan dalam kode program, langkah selanjutnya yaitu menggunakan alat pemrograman ``` STM8 ``` sesuai dengan prosedur. Kemudian klik: ``` Upload ```.<br><br>

7. Jika masih ada masalah saat unggah program, maka coba periksa pada bagian ``` driver ``` / ``` port ``` / ``` alat pemrogram ``` / ``` yang lainnya ```.

<br><br>

## Pengaturan ST-Link/V2
<img width="840" src="Assets/Documentation/Experiment/ST-Link Configuration.jpg" alt="stlink-configuration"><br><br>

<h3><img src="https://github.com/user-attachments/assets/932b96eb-cbc7-42f1-8938-43cb431889a5" width="16" height="16"> Catatan :</h3>
<blockquote>
   <ul>
   <li>
   
   Modul antarmuka kabel tunggal atau ``` SWIM ``` pada dasarnya digunakan untuk berkomunikasi dengan board ``` STM8 ```.

   </li>
   <li>
   
   Pemasangan kabel antara ``` ST-Link/V2 ``` dengan board ``` STM8 ``` dapat anda lihat selengkapnya pada gambar di atas.
   
   </li>
   <li>
   
   Berdasarkan pengalaman pribadi, ``` STM8 ``` hanya dapat diprogram dengan ``` ST-Link ```.
   
   </li>
   </ul>
</blockquote>

<br><br>

## Pengaturan USB FTDI
<img width="840" src="Assets/Documentation/Experiment/FTDI Configuration.jpg" alt="ftdi-configuration"><br><br>

<h3><img src="https://github.com/user-attachments/assets/932b96eb-cbc7-42f1-8938-43cb431889a5" width="16" height="16"> Catatan :</h3>
<blockquote>
   <ul>
   <li>
   
   Komunikasi serial pada board ``` STM8 ``` ini sangat dimungkinkan terjadi, terutama untuk keperluan ``` Serial Monitor ``` dan ``` Serial Plotter ```. Alat yang dapat dipakai untuk komunikasi serial antara lain: ``` USB CP2102 ```, ``` USB CH340 ```, ``` USB FTDI ```, atau dengan ``` USB PL2303 ```.

   </li>
   <li>
   
   Pemasangan kabel antara ``` USB FTDI ``` dengan board ``` STM8 ``` dapat anda lihat detailnya pada gambar di atas.
   
   </li>
   <li>
   
   Berdasarkan pengalaman, saya akui bahwa penggunaan ``` USB FTDI ``` atau ``` USB CP2102 ``` itu jauh lebih baik daripada ``` USB PL2303 ``` maupun ``` USB CH340 ``` karena diketahui kinerjanya lebih stabil.
   
   </li>
   </ul>
</blockquote>

<br><br>

## Menghilangkan proteksi penulisan pada STM8
Proteksi penulisan pada ``` STM8 ``` dapat dihilangkan melalui beberapa tahapan, antara lain :<br><br>
1. Hubungkan ``` STM8 ``` ke ``` ST-Link/V2 ```, lalu hubungkan ``` ST-Link/V2 ``` ke PC atau laptop.<br><br>

2. Buka ``` CMD (Command Prompt) ```.<br><br>

3. Masuk ke dalam direktori :

   <table><tr><td width="810">

   ``` C:\Users\[Computer Name]\AppData\Local\Arduino15\packages\sduino\tools\STM8Tools\2019.02.05\win ```

   </td></tr></table><br>

4. Masukan perintah :

   <table><tr><td width="810">
   
   ```
   stm8flash -cstlinkv2 -pstm8s103?3 -u
   ```

   </td></tr></table><br>
   
5. Tekan ``` Enter ```, lalu hasilnya dapat anda lihat seperti gambar di bawah ini.
   
   <img width="810" height="250" src="Assets/Documentation/Experiment/Remove Protection STM8.jpg" alt="rmv-protection">

<br><br>

## Memulai
1. Unduh dan ekstrak repositori ini.<br><br>
   
2. Pastikan anda memiliki komponen elektronik yang diperlukan.<br><br>
   
3. Pastikan komponen anda telah dirancang sesuai dengan diagram.<br><br>
    
4. Konfigurasikan perangkat anda menurut pengaturan di atas.<br><br>

5. Selamat menikmati [Selesai].

<br><br>

## Apresiasi
Jika karya ini bermanfaat bagi anda, maka dukunglah karya ini sebagai bentuk apresiasi kepada penulis dengan mengklik tombol ``` ⭐Bintang ``` di bagian atas repositori.

<br><br>

## Penafian
Aplikasi ini merupakan hasil karya saya sendiri dan bukan merupakan hasil plagiat dari penelitian atau karya orang lain, kecuali yang berkaitan dengan layanan pihak ketiga yang meliputi: pustaka, kerangka kerja, dan lain sebagainya.

<br><br>

## LISENSI
LISENSI MIT - Hak Cipta © 2026 - Devan C. M. Wijaya, S.Kom

Dengan ini diberikan izin tanpa biaya kepada siapa pun yang mendapatkan salinan perangkat lunak ini dan file dokumentasi terkait perangkat lunak untuk menggunakannya tanpa batasan, termasuk namun tidak terbatas pada hak untuk menggunakan, menyalin, memodifikasi, menggabungkan, mempublikasikan, mendistribusikan, mensublisensikan, dan/atau menjual salinan Perangkat Lunak ini, dan mengizinkan orang yang menerima Perangkat Lunak ini untuk dilengkapi dengan persyaratan berikut:

Pemberitahuan hak cipta di atas dan pemberitahuan izin ini harus menyertai semua salinan atau bagian penting dari Perangkat Lunak.

DALAM HAL APAPUN, PENULIS ATAU PEMEGANG HAK CIPTA DI SINI TETAP MEMILIKI HAK KEPEMILIKAN PENUH. PERANGKAT LUNAK INI DISEDIAKAN SEBAGAIMANA ADANYA, TANPA JAMINAN APAPUN, BAIK TERSURAT MAUPUN TERSIRAT, OLEH KARENA ITU JIKA TERJADI KERUSAKAN, KEHILANGAN, ATAU LAINNYA YANG TIMBUL DARI PENGGUNAAN ATAU URUSAN LAIN DALAM PERANGKAT LUNAK INI, PENULIS ATAU PEMEGANG HAK CIPTA TIDAK BERTANGGUNG JAWAB, KARENA PENGGUNAAN PERANGKAT LUNAK INI TIDAK DIPAKSAKAN SAMA SEKALI, SEHINGGA RISIKO ADALAH MILIK ANDA SENDIRI.