cmake_minimum_required(VERSION 3.15)

# Называем проект
project(IdiomNVI)

# Фиксируем стандарт C++17 глобально
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Устанавливаем высокий уровень предупреждений: /W4 - высокий уровень предупреждений, /WX - трактовать предупреждения как ошибки (опционально, но полезно)
if(MSVC)
    add_compile_options(/W4) 
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Указываем компилятору, где искать заголовочные файлы
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# ==========================================
# ==========================================
add_executable(Idiom_NVI
    src/main.cpp

    # --- Лабораторная работа №1 (GUI using NVI) ---
    src/Lab1/Widget.cpp
    src/Lab1/ButtonWidget.cpp
    src/Lab1/TextWidget.cpp
    src/Lab1/UIEngine.cpp

    include/Lab1/Widget.hpp
    include/Lab1/ButtonWidget.hpp
    include/Lab1/TextWidget.hpp
    include/Lab1/UIEngine.hpp

    # --- Лабораторная работа №2 (Extending default behavior via NVI) ---
    src/Lab2/DataExporter.cpp
    src/Lab2/JsonExporter.cpp
    src/Lab2/XmlExporter.cpp
    src/Lab2/ExportManager.cpp

    include/Lab2/DataExporter.hpp
    include/Lab2/RawExporter.hpp
    include/Lab2/JsonExporter.hpp
    include/Lab2/XmlExporter.hpp
    include/Lab2/ExportManager.hpp

    # --- Лабораторная работа №3 (Freezing NVI using the final specifier) ---
    src/Lab3/NetworkProcessor.cpp
    src/Lab3/HttpProcessor.cpp
    src/Lab3/FtpProcessor.cpp
    src/Lab3/NetworkManager.cpp

    include/Lab3/NetworkProcessor.hpp
    include/Lab3/HttpProcessor.hpp
    include/Lab3/FtpProcessor.hpp
    include/Lab3/NetworkManager.hpp
)

# ==========================================
# Лабораторная работа №2 ()
# ==========================================


# ==========================================
# Лабораторная работа №3 ()
# ==========================================