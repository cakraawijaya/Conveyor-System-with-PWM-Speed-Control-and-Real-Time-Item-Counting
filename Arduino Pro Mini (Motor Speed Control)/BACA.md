[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/licenses/MIT)
![GitHub last commit](https://img.shields.io/github/last-commit/cakraawijaya/Conveyor-with-PWM-Speed-and-Item-Counting?logo=Codeforces&logoColor=white&color=%23F7DF1E)
![Project](https://img.shields.io/badge/Project-Arduino-light.svg?style=flat&logo=arduino&logoColor=white&color=%23F7DF1E)
![Type](https://img.shields.io/badge/Type-Personal%20Experiment-light.svg?style=flat&logo=gitbook&logoColor=white&color=%23F7DF1E)

# Arduino Pro Mini-based Conveyor Motor Speed Control System using PWM Method
Konveyor adalah sebuah sistem mekanik yang digunakan untuk memindahkan barang atau material dari satu tempat ke tempat lain yang dilakukan secara terus menerus. Tujuan diadakannya proyek ini adalah untuk memberikan edukasi kepada masyarakat luas tentang bagaimana cara membuat konveyor mini yang sederhana. Proyek ini telah dilaksanakan dan memakan waktu kurang lebih 1 minggu. Untuk mengatur seberapa cepat mesin konveyor dapat bergerak, anda dapat menggunakan potensiometer. Untuk mengganti arah gerakan mesin konveyor sekaligus menghentikannya, anda dapat menggunakan push button. Manfaat dari pembuatan proyek ini tidak lain adalah untuk menambah wawasan. Hasil penelitian menunjukkan bahwa sistem yang dibuat ini dapat berfungsi dengan baik.

<br><br>

## Kebutuhan Proyek
| Bagian | Deskripsi |
| --- | --- |
| Papan Pengembangan | Arduino Pro Mini |
| Editor Kode | Arduino IDE 1.8.19 (Versi Lama yang Stabil) |
| Alat Pemrogram | USB PL2303 |
| Driver | PL2303 USB Driver |
| Bahasa Pemrograman | C/C++ |
| Aktuator | Gear Motor / Motor DC (x1) |
| Komponen Lainnya| • Kabel jumper (1 set)<br>• Adaptor DC 12V 2A (x1)<br>• Motor driver L298N (x1)<br>• Breadboard (x1)<br>• Potensiometer (x1)<br>• Tombol tekan 12 x 12 mm (x2)<br>• PVC Lembaran 3 mm 10 x 50 cm (x5)<br>• Beton Baja Stainless Steel 30 cm (x1)<br>• Bantalan Bearing 6mm (x3)<br>• Pipa 1/2 Inchi 25 cm (x2)<br>• Kain Oscar 50 x 137 cm (x1)<br>• Stiker kayu (1 set)<br>• Baut plus (1 set)<br>• Mur (1 set)<br>• Braket L (1 set)<br>• Isolasi listrik PVC (1 set)<br>• Sandpaper G-180 1 m (x1)<br>• Velg Smart Car (x1)  |

<br><br>

## Unduh & Instal
1. Arduino IDE

   <table><tr><td width="810">
      
   ```
   https://bit.ly/ArduinoIDE_Installer
   ```

   </td></tr></table><br>

2. PL2303 USB Driver

   <table><tr><td width="810">

   ```
   https://bit.ly/PL2303P_USBdriver
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
<td><img src="Assets/Documentation/Table/Device Wiring.jpg" alt="wiring"></td>
</tr>
</table>

<br><br>

## Pengaturan Arduino IDE
1. Buka ``` Arduino IDE ``` terlebih dahulu, kemudian buka proyek ini dengan cara klik ``` File ``` -> ``` Open ``` : 

   <table><tr><td width="810">
   
      ``` pwm_conveyor.ino ```

   </td></tr></table><br>
   
2. ``` Pengaturan Board ``` di Arduino IDE

   <table>
      <tr><th width="810">

      Cara mengatur board ``` Arduino Pro Mini ```
            
      </th></tr>
      <tr><td width="810">
   
      Pilih papan dengan mengklik: ``` Tools ``` -> ``` Board ``` -> ``` Arduino AVR Boards ``` -> ``` Arduino Pro or Pro Mini ```

      </td></tr>
   </table><br>

3. ``` Ubah Processor ``` di Arduino IDE

   <table><tr><td width="810">
   
      Klik ``` Tools ``` -> ``` Processor ``` -> ``` ATmega328P (5V, 16 MHz) ```

   </td></tr></table><br>

4. ``` Pengaturan Port ``` di Arduino IDE

   <table><tr><td width="810">
   
      Klik ``` Port ``` -> Pilih sesuai dengan port perangkat anda ``` (anda dapat melihatnya di Device Manager) ```

   </td></tr></table><br>

5. Sebelum mengunggah program, silakan klik: ``` Verify ```.<br><br>

6. Jika tidak ada kesalahan dalam kode program, silakan klik: ``` Upload ```.<br><br>

7. Beberapa hal yang perlu anda lakukan saat menggunakan ``` board Arduino Pro Mini ``` dengan ``` USB PL2303 ``` :

   <table><tr><td width="810">

      • Informasi ``` Arduino IDE ```: ``` Uploading... ``` -> segera tekan tombol ``` RESET ``` dan lepaskan.
      
      • Tunggu sampai muncul pesan: ``` Done Uploading ``` -> ``` Program langsung dioperasikan ```.

   </td></tr></table><br>

8. Jika masih ada masalah saat unggah program, maka coba periksa pada bagian ``` driver ``` / ``` port ``` / ``` yang lainnya ```.

<br><br>

## Pengaturan USB PL2303
<img width="840" src="Assets/Documentation/Experiment/PL2303 Configuration.jpg" alt="pl2303-configuration"><br><br>

<h3><img src="https://github.com/user-attachments/assets/932b96eb-cbc7-42f1-8938-43cb431889a5" width="16" height="16"> Catatan :</h3>
<blockquote>
   <ul>
   <li>
   
   ``` Arduino Pro Mini ``` ini tidak dilengkapi dengan ``` port USB ```, sehingga anda membutuhkan perangkat tambahan berupa ``` USB to TTL Serial ``` untuk dapat terhubung ke laptop ataupun PC. ``` USB to TTL Serial ``` seperti ``` USB PL2303 ``` ini biasa digunakan untuk media perantara dalam pengunggahan suatu program.
   
   </li>
   <li>
   
   Pemasangan kabel antara ``` USB PL2303 ``` dengan board ``` Arduino Pro Mini ``` dapat anda lihat selengkapnya pada gambar di atas.
   
   </li>
   <li>
   
   Untuk mengunggah program, selain menggunakan ``` USB PL2303 ```, anda juga dapat menggunakan alat pemrogram lainnya seperti: ``` USB CP2102 ```, ``` USB CH340 ```, atau dengan ``` USB FTDI ```. Berdasarkan pengalaman, saya akui bahwa penggunaan ``` USB FTDI ``` atau ``` USB CP2102 ``` itu jauh lebih baik daripada ``` USB PL2303 ``` maupun ``` USB CH340 ``` karena diketahui kinerjanya lebih stabil.
   
   </li>
   </ul>
</blockquote>

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

## LISENSI
LISENSI MIT - Hak Cipta © 2026 - Devan C. M. Wijaya, S.Kom

Dengan ini diberikan izin tanpa biaya kepada siapa pun yang mendapatkan salinan perangkat lunak ini dan file dokumentasi terkait perangkat lunak untuk menggunakannya tanpa batasan, termasuk namun tidak terbatas pada hak untuk menggunakan, menyalin, memodifikasi, menggabungkan, mempublikasikan, mendistribusikan, mensublisensikan, dan/atau menjual salinan Perangkat Lunak ini, dan mengizinkan orang yang menerima Perangkat Lunak ini untuk dilengkapi dengan persyaratan berikut:

Pemberitahuan hak cipta di atas dan pemberitahuan izin ini harus menyertai semua salinan atau bagian penting dari Perangkat Lunak.

DALAM HAL APAPUN, PENULIS ATAU PEMEGANG HAK CIPTA DI SINI TETAP MEMILIKI HAK KEPEMILIKAN PENUH. PERANGKAT LUNAK INI DISEDIAKAN SEBAGAIMANA ADANYA, TANPA JAMINAN APAPUN, BAIK TERSURAT MAUPUN TERSIRAT, OLEH KARENA ITU JIKA TERJADI KERUSAKAN, KEHILANGAN, ATAU LAINNYA YANG TIMBUL DARI PENGGUNAAN ATAU URUSAN LAIN DALAM PERANGKAT LUNAK INI, PENULIS ATAU PEMEGANG HAK CIPTA TIDAK BERTANGGUNG JAWAB, KARENA PENGGUNAAN PERANGKAT LUNAK INI TIDAK DIPAKSAKAN SAMA SEKALI, SEHINGGA RISIKO ADALAH MILIK ANDA SENDIRI.