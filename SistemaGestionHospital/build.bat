@echo off
echo Compilando SistemaGestionHospital...
g++ -std=c++17 src/*.cpp -Iinclude -o SistemaGestionHospital
if %errorlevel% neq 0 (
    echo Error de compilacion
    pause
) else (
    echo Compilacion exitosa
    SistemaGestionHospital.exe
    pause
)
