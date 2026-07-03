Проект демонстрирует продвинутые механизмы инкапсуляции, привилегированного доступа и сокрытия внутренней реализации - демонстрирует систему,  в которой одни классы имеют привилегированный доступ к данным других (Friendship), а вспомогательные механизмы полностью скрыты от внешнего мира (Nested Classes)..
## 🎯 Цели практики
* **Friendship:** Настройка "доверенных" отношений между классами для доступа к приватным данным.
* **Nested Classes:** Сокрытие вспомогательных механизмов в `private` секции.
* **Operator Overloading:** Перегрузка `<<` с прямым доступом к приватным полям.
* **API Design:** Публичный интерфейс скрывает сложную внутреннюю логику.

## 🏗 Архитектура системы
### 1. `Participant` (Основная сущность)
* **Закрытые данные:** `score`, `name` — недоступны извне.
* **Friend Access:** Только `CompetitionLogger` и `operator<<` имеют право читать приватные поля.
* **RAII Lifecycle:** Логирование создания/уничтожения.

### 2. `CompetitionLogger` (Системный наблюдатель)
* **Статический утилитный класс:** Не хранит состояния, только логирует.
* **Deep Inspection:** Метод `log_deep_scan` читает приватные поля напрямую, выводит адрес памяти и внутренние данные.
* **Const Correctness:** Работает с `const` объектами.

### 3. `CompetitionManager` (Оркестратор)
* **Внешний API:** Методы `add_participant()` и конструктор.
* **Скрытый механизм:** Вложенный класс `DataProcessor` (в `private`) валидирует данные перед добавлением.
* **Memory Ownership:** Управляет динамически выделенными участниками (Heap).
* **Printable:** Поддерживает `std::cout << manager`.

## 🔧 Ключевые особенности реализации
```
public API (пользователь видит):
├── CompetitionManager::add_participant(points, name)
└── CompetitionLogger::log_deep_scan(participant)

private implementation (скрыто):
├── CompetitionManager::DataProcessor::is_valid_score(score)
└── Friend access к приватным полям Participant
```

## 🚀 Сборка и запуск
```bash
g++ main.cpp headers/*.cpp -Iheaders -o logging_sys_app; .\logging_sys_app.exe
./oop_practice3
```

## 📋 Пример вывода
```
*** The created class object participant ***
	Participant::Participant: the participant 'Alice' created!
Participant
	name: Alice
	score: 5

*** Call CompetitionLogger::log_deep_scan ***
Info from class 'Participant':
	name: Alice
	score: 5
	address: 0x7ffd12345678

*** Competition Manager VALID ***
	Checking the value of points to assign to a participant.
	CompetitionManager::CompetitionManager: the point value '1' saved!
The manager contains elements:
	Participant::Participant: Bob created!
Participant
	name: Bob
	score: 1

	The adding participant INVALID score '0'.
	Checking value of points...
	CompetitionManager::add_participant: ERROR - score > 0!
The manager contains elements:
[только Bob, Back не добавлен]

*** End of program ***
	Participant::~Participant: Bob deleted!
	CompetitionManager::~CompetitionManager: all removed!
	Participant::~Participant: Alice deleted!
```
