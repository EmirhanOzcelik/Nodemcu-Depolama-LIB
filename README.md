# ESP8266/ESP32 LittleFS Dosya Sistemi Kütüphanesi

Bu kütüphane, ESP8266 ve ESP32 kartlarınızda LittleFS dosya sistemini kolayca yönetmenizi sağlar. Dosya ve dizin oluşturmaktan, okumaya, yazmaya, silmeye ve hatta yedeklemeye kadar ihtiyacınız olan tüm temel işlemleri basitleştirir.

## Kurulum

Bu kütüphaneyi projenize dahil etmek oldukça basittir:

1.  `LITTLEFS_LIB.h`, `depo_hesapla.cpp`, `depo_oku.cpp`, `depo_seritest.cpp`, `depo_sil.cpp`, `depo_yaz.cpp` dosyalarını Arduino projenizin ana klasörüne kopyalayın.
2.  Arduino IDE'nin Kütüphane Yöneticisi'nden veya manuel olarak `LittleFS` kütüphanesini yüklediğinizden emin olun. (ESP8266/ESP32 çekirdek kurulumuyla genellikle otomatik olarak gelir, ancak kontrol etmekte fayda var).

## Nasıl Kullanılır?

Kütüphanenin tüm fonksiyonları `dosya_sistemi` sınıfı altında toplanmıştır. Bu sınıfın bir nesnesini oluşturarak dosya sistemi işlemlerini kolayca gerçekleştirebilirsiniz:

```cpp
#include "LITTLEFS_LIB.h" // Projenize eklediğiniz kütüphane başlık dosyası

dosya_sistemi fs; // dosya_sistemi sınıfından bir nesne oluşturma
