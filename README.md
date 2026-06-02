# Mini System Bankowy

Prosty symulator systemu bankowego napisany w C++17.

## Funkcje

- Tworzenie kont bankowych (numer, właściciel, saldo)
- Wpłata i wypłata środków
- Wyświetlanie informacji o koncie i listy kont
- Obsługa błędów: brak środków, nieprawidłowe kwoty, nieistniejące konta

## Budowanie

Wymagania: CMake ≥ 3.14, kompilator z obsługą C++17 (GCC, Clang, MSVC).

```bash
cmake -B build
cmake --build build
./build/minibank
```

## Struktura projektu

```
.
├── CMakeLists.txt
├── include/
│   ├── Account.h   # Klasa konta + wyjątki domenowe
│   ├── Bank.h      # Klasa banku zarządzająca kontami
│   └── Menu.h      # Interfejs konsolowy
└── src/
    ├── Account.cpp
    ├── Bank.cpp
    ├── Menu.cpp
    └── main.cpp
```
