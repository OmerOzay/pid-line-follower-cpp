# 🤖 Saf C++ PID Çizgi İzleyen Robot Simülasyonu

Harici hiçbir kütüphane (ROS, OpenCV, GUI vb.) kullanılmadan, tamamen **saf C++17** standart kütüphanesi ile geliştirilmiş otonom çizgi izleyen robot simülasyonu. Proje, diferansiyel sürüş kinematiğini ve PID kontrol algoritmasını kullanarak sinüs dalgası şeklindeki bir rotayı takip eder.

## 📌 Öne Çıkan Özellikler
- **Saf C++17:** Tamamen standart C++ kütüphaneleri (`<iostream>`, `<cmath>`, `<thread>` vb.) kullanılarak yazılmıştır; hiçbir harici bağımlılık gerektirmez.
- **Modüler Mimari:** Temiz Nesne Yönelimli Programlama (OOP) prensipleriyle `PIDController`, `Robot` ve `Track` sınıflarına ayrılmıştır.
- **PID Kontrol Sistemi:** Ayarlanabilir Oransal-İntegral-Türev ($K_p$, $K_i$, $K_d$) kontrolcüsü.
- **Diferansiyel Sürüş Kinematiği:** İki tekerlekli robotun tekerlek hızları ve yön açısına ($\theta$) dayalı gerçekçi fizik modeli.
- **Terminal Görselleştirmesi:** Çizginin konumu, robotun anlık durumu ve sağ/sol motor hızlarının canlı ASCII karakterleri ile terminalde gösterimi.

## 📁 Proje Yapısı
```text
.
├── CMakeLists.txt
├── README.md
├── include/
│   ├── PIDController.h
│   ├── Robot.h
│   └── Track.h
└── src/
    ├── PIDController.cpp
    ├── Robot.cpp
    ├── Track.cpp
    └── main.cpp