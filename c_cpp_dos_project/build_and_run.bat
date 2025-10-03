@echo off
setlocal
REM Build main + libmath using g++ (MinGW/MSYS2)
if not exist bin mkdir bin
g++ main.cpp libmath.c -std=c++17 -O2 -o bin\program.exe
if errorlevel 1 (
  echo Build failed.
  exit /b 1
)
echo Build OK. Running program...
bin\program.exe
endlocal
