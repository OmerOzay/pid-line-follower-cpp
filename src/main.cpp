#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cmath>    
#include <string>

#include "PIDController.h"
#include "Robot.h"
#include "Track.h"

// Hem çizginin (target_y) hem robotun (robot_y) haritadaki yerini çizen fonksiyon
void drawWorldConsole(double target_y, double robot_y) {
    const int width = 35;
    int center = width / 2;
    
    // Y ekseni konumunu konsol karakterlerine ölçekleme
    double scale = 2.0;
    int line_pos  = center + static_cast<int>(std::round(target_y * scale));
    int robot_pos = center + static_cast<int>(std::round(robot_y * scale));

    std::string view(width, ' ');

    // Çizginin konumu ( . )
    if (line_pos >= 0 && line_pos < width) {
        view[line_pos] = '.';
    }

    // Robotun konumu ( R veya O )
    if (robot_pos >= 0 && robot_pos < width) {
        if (robot_pos == line_pos) {
            view[robot_pos] = 'O'; // Robot çizginin tam üstündeyse
        } else {
            view[robot_pos] = 'R';
        }
    }

    std::cout << " [" << view << "]";
}

int main() {
    PIDController pid(1.5, 0.02, 0.8);
    Robot robot(0.0, 3.0, 15.0);
    Track track;

    double dt = 0.1;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "--- PID Cizgi Izleme Simulasyonu (Harita Gorunumu) ---\n\n";

    for (int step = 0; step < 100; ++step) {
        double robot_x = robot.getX();
        double robot_y = robot.getY();

        // 1. Çizgi ve Sensör Hatası
        double target_y = track.getLineY(robot_x);
        double error = target_y - robot_y;

        // 2. PID Hesabı
        double correction = pid.calculate(error, dt);

        // 3. Motorları ve Robot Fiziğini Güncelle
        robot.setMotorSpeeds(correction);
        robot.update(dt);

        // 4. Konsol Çıktısı
        std::cout << "Adim: " << std::setw(3) << step
                  << " | Hata: " << std::setw(6) << error;
        
        drawWorldConsole(target_y, robot_y);

        std::cout << " | Sol M.: " << std::setw(5) << robot.getLeftSpeed()
                  << " | Sag M.: " << std::setw(5) << robot.getRightSpeed() << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }

    return 0;
}