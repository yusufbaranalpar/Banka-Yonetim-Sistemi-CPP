# 🏦 Banka Yönetim Sistemi (C++)

Konsol tabanlı, Nesne Yönelimli Programlama (OOP) mimarisi ve dosya kalıcılığı kullanılarak geliştirilmiş bir banka yönetim sistemi simülasyonu.

## 🚀 Özellikler
- **Hesap Sınıfı (Class):** Kapsülleme (encapsulation), private değişkenler ve kurucu fonksiyon (constructor).
- **Dinamik Liste:** Hesapları bellekte tutmak için `vector` yapısı.
- **Güvenli İşlemler:** Aynı hesap numarasıyla tekrar kayıt açılmasını engelleme, yetersiz bakiye ve negatif tutar kontrolleri.
- **Dosya Kalıcılığı:** Program kapanırken tüm verileri CSV formatında (`hesaplar.txt`) kaydeder, program açıldığında otomatik olarak geri yükler.
- **Hata Yönetimi (Try-Catch):** Bozuk dosya formatlarına karşı programın çökmesini engelleyen güvenli tip dönüşümleri.
- **Tablo Formatı:** `<iomanip>` kütüphanesi ile düzenli konsol çıktısı.

## 🛠️ Menü
1. Yeni Hesap Aç
2. Hesapları Listele
3. Para Yatır
4. Para Çek
5. Çıkış (Verileri Kaydeder)
