# C++ Memory Management \& Object Lifecycle Practice
Этот проект — учебная реализация системы управления соревнованиями (**Competition Manager**), созданная для глубокой проработки механизмов управления памятью в C++ и отношений между объектами.
**Ключевая цель:** Демонстрация различий между **Stack** (автоматическая память), **Heap** (динамическая память) и **Static** (глобальное состояние), а также реализация паттернов владения ресурсами (RAII, Композиция vs Агрегация).

## 🏗 Архитектура и Технические решения
Проект моделирует взаимодействие трех сущностей с разным временем жизни и правами доступа.
### 1. `Participant` (Участник)
* **Static Counter:** Реализован глобальный подсчет активных экземпляров через `static` поле. Позволяет отслеживать утечки памяти (Memory Leaks) в реальном времени.
* **RAII Logging:** Конструктор и деструктор логируют создание и уничтожение объекта, показывая текущее количество "живых" участников.
* **Инкапсуляция:** Полное сокрытие данных, доступ только через константные методы.
### 2. `CompetitionSettings` (Настройки)
* **Immutable Object:** Настройки соревнования (название, лимит участников) задаются один раз при создании и являются константами (`const`).
* **Композиция:** Объект настроек жестко связан с менеджером. Он создается и умирает вместе с ним (Stack-like behavior inside class).
### 3. `CompetitionManager` (Менеджер)
* **Агрегация:** Менеджер владеет динамически созданными участниками (`std::vector<Participant*>`).
* **Manual Memory Management:** В деструкторе менеджера реализована очистка памяти (вызов `delete` для каждого участника), что предотвращает утечки.
* **Validation Logic:** Метод `dispatch_participant` проверяет лимит участников перед выделением памяти.

## 🚀 Сценарии использования (Use Cases)
В `main.cpp` реализован комплексный тест-драйв:
1. **Global Scope Check:** Проверка, что счетчик объектов равен 0 до начала работы.
2. **Heap Allocation:** Создание участников через `new` внутри менеджера. Они живут до тех пор, пока жив менеджер.
3. **Stack Allocation (Scope Test):** В методе `perform_check_up()` создается временный объект "Inspector" на стеке. Демонстрируется, что он уничтожается **сразу** при выходе из блока, не дожидаясь завершения программы.
4. **Cleanup Verification:** При выходе менеджера из области видимости автоматически вызывается деструктор, который удаляет всех участников и настройки. Финальная проверка подтверждает отсутствие утечек памяти (Global count = 0).

## 🛠 Сборка и Запуск
Проект написан на стандартном C++ (C++11/14/17 compatible) и не требует сторонних библиотек.
### С помощью g++
```bash
g++ main.cpp headers/*.cpp -Iheaders -o competition_app ; .\competition_app.exe
```
## 📋 Пример вывода
Логи наглядно показывают порядок вызова конструкторов/деструкторов:
```text
Global count: 0

--- Scope start ---
The setting was successfully created with the name 'Super Cup'.
The participant 'Alice' created! (Active participant: 1)
The participant 'Bob' created! (Active participant: 2)

--- Stack test ---
The participant 'Inspector' created! (Active participant: 3)
Info about participant:
	name:	Inspector

Participant Inspector deleted! Number of living objects left: '2' <-- Удален автоматически!
Check up finished!

--- Score end ---
Participant Alice deleted! Number of living objects left: '1' <-- Очистка Heap
Participant Bob deleted! Number of living objects left: '0'   <-- Очистка Heap
All participants have been removed!
The setting with name 'Super Cup' destroyed.

--- End main ---
Global count: 0
```
***
*Проект выполнен в рамках закрепления темы "Управление памятью и отношения классов" (C++ Core).*