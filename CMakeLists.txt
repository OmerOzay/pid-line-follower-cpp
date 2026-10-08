cmake_minimum_required(VERSION 3.10)
project(PIDLineFollowerSim VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header dosyalarının dizini
include_directories(include)

# src altındaki tüm cpp dosyalarını otomatik topla
file(GLOB SOURCES "src/*.cpp")

# Çalıştırılabilir hedefi oluştur
add_executable(robot ${SOURCES})