#include "LITTLEFS_LIB.h"

#define __TEST 0

/**
 * @brief Dosya sistemi sınıfı için etkileşimli test konsolu
 * 
 * Bu fonksiyon, tüm temel fonksiyonların örnek kullanımını test etmek amacıyla
 * seri monitörden gelen karakter girdisine göre ilgili işlemleri yapar.
 * Yardım menüsü 'H' tuşuyla tekrar gösterilebilir.
 */
void dosya_sistemi::test()
{
#if __TEST == 1
    static bool ilk_calistirildi = false;

    if (!ilk_calistirildi)
    {
        Serial.println(F("\n==== LittleFS Test Konsolu Başlatıldı ===="));
        Serial.println(F("H - Yardım menüsünü göster"));
        Serial.println(F("1 - /test dizini var mı?"));
        Serial.println(F("2 - /test dizini oluştur"));
        Serial.println(F("3 - /test dizinini tamamen sil"));
        Serial.println(F("4 - Tüm dosya ve klasörleri listele"));
        Serial.println(F("5 - /test.txt dosyasına birkaç satır yaz"));
        Serial.println(F("6 - /test.txt içeriğini oku"));
        Serial.println(F("7 - /test.txt satır sayısını göster"));
        Serial.println(F("8 - /test.txt 2. satırı oku"));
        Serial.println(F("9 - /test.txt 2. satırı değiştir"));
        Serial.println(F("0 - /test.txt içinde 'const' ara"));
        Serial.println(F("B - Genel dosya sistemi boyut bilgilerini göster"));
        Serial.println(F("b - /test.txt dosya boyutunu ve kullanılan alanı yazdır"));
        Serial.println(F("s - /test.txt içeriğini temizle"));
        Serial.println(F("S - /test.txt dosyasını sil"));
        Serial.println(F("Y - /test.txt dosyasını yedekle"));
        Serial.println(F("G - /test.txt yedeğini geri yükle"));
        Serial.println(F("K - /test.txt dosyasını /kopya.txt olarak kopyala"));
        Serial.println(F("R - /kopya.txt dosyasını /yenisim.txt olarak yeniden adlandır"));
        Serial.println(F("Q - /yenisim.txt dosyasını sil"));
        Serial.println(F("==== Bir komut girin (H yardımı tekrar gösterir) ===="));
        ilk_calistirildi = true;
    }

    if (Serial.available())
    {
        char komut = Serial.read();
        switch (komut)
        {
        case 'H':
        case 'h':
            ilk_calistirildi = false; // yardım ekranını tekrar göster
            break;

        case '1':
            Serial.println(F("/test dizini var mı?"));
            Serial.println(!bos_mu("/test") ? F("Boş veya yok") : F("Var ve içerik mevcut"));
            break;

        case '2':
            Serial.println(F("/test dizini oluşturuluyor..."));
            Serial.println(dizin_olustur("/test") ? F("Başarılı") : F("Başarısız"));
            break;

        case '3':
            Serial.println(F("/test dizini tamamen siliniyor..."));
            sil_full_dizin("/test");
            break;

        case '4':
            listele_tumicerik();
            break;

        case '5':
            Serial.println(F("Dosyaya test verileri yazılıyor..."));
            ekle("/test.txt", "satir1: Merhaba\nsatir2: Bu bir test\nsatir3: const uint8_t veri\n");
            break;

        case '6':
            Serial.println(F("Dosya içeriği:\n"));
            Serial.println(oku("/test.txt"));
            break;

        case '7':
            Serial.print(F("Satır sayısı: "));
            Serial.println(satir_hesap("/test.txt"));
            break;

        case '8':
            Serial.println(F("2. satır:"));
            Serial.println(satir_oku("/test.txt", 1));
            break;

        case '9':
            Serial.println(F("2. satır değiştiriliyor..."));
            Serial.println(satir_degistir("/test.txt", 1, "satir2: Bu satır değiştirildi"));
            break;

        case '0':
            Serial.print(F("const kelimesi geçen satır no: "));
            Serial.println(ara("/test.txt", "const"));
            break;

        case 'B':
            boyut_genel_ayrintili();
            break;

        case 'b':
            Serial.print(F("Kullanım yüzdesi: "));
            boyut();
            Serial.print(F("/test.txt boyutu: "));
            Serial.println(boyut("/test.txt"));
            break;

        case 's':
            Serial.println(F("Dosya içeriği temizleniyor..."));
            temizle("/test.txt");
            break;

        case 'S':
            Serial.println(F("/test.txt siliniyor..."));
            sil("/test.txt");
            break;

        case 'Y':
            Serial.println(F("Dosya yedekleniyor (test.txt -> test.yedek)..."));
            Serial.println(yedekle("/test.txt") ? F("Başarılı") : F("Başarısız"));
            break;

        case 'G':
            Serial.println(F("Yedekten geri yükleniyor (test.yedek -> test.txt)..."));
            Serial.println(geri_yukle("/test.txt") ? F("Başarılı") : F("Başarısız"));
            break;

        case 'K':
            Serial.println(F("Kopyalanıyor (test.txt -> kopya.txt)..."));
            Serial.println(kopyala("/test.txt", "/kopya.txt") ? F("Başarılı") : F("Başarısız"));
            break;

        case 'R':
            Serial.println(F("Yeniden adlandırılıyor (kopya.txt -> yenisim.txt)..."));
            Serial.println(yeniden_adlandir("/kopya.txt", "/yenisim.txt") ? F("Başarılı") : F("Başarısız"));
            break;

        case 'Q':
            Serial.println(F("yenisim.txt siliniyor..."));
            sil("/yenisim.txt");
            break;
        }
    }
#else
    Serial.println(F("TEST modu devre dışı bırakılmış. test() fonksiyonu çalışmaz."));
#endif
}
