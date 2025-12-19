cmake_minimum_required(VERSION 3.10)
project(my_app)

# Находим файлы
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

# Указываем C++ стандарт
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ищем libpqxx
find_package(libpqxx REQUIRED)

# Создаем исполняемый файл
add_executable(my_app ${SOURCES} ${HEADERS})

# Подключаем заголовочные файлы
target_include_directories(my_app PRIVATE include)

# Линкуем библиотеки - ОБРАТИТЕ ВНИМАНИЕ НА ЭТУ СТРОКУ
target_link_libraries(my_app PRIVATE libpqxx::pqxx)