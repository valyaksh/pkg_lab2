# pkg_lab2
Отчет по лабораторной №2 - "Чтение информации из графических файлов" 
  
Задачи:
Написать приложение, считывающее из графического файла/файлов основную информацию об изображении. Где нужно отобразить следующее : 
- имя файла; 
- размер изображения (в пикселях); 
- разрешение (dot/inch); 
- глубина цвета; 
- cжатие 
 
Использованные языки и среды программирования:
- C++  
- Qt Creator  “Qt 6.4.3 for macOS"” 
 
Объекты приложения:
1.LineEdit -  отображающий путь к текущему файлу/папке 
2.PushButton, при нажатии которой можно сделать множестенный выбор, интересующих файлов 
3.ListView- pабочее окно, где можно свободно перемещаться по папкам 
4.TableWidget - для хранения параметров извлекаемых из изображения 
 
Используемые библиотеки:
1.QDir - для работы с объектами файловой системы 
2.QModelIndex - для разработки рабочей области 
3.QListView - использован как  рабочая область с перемещениями в папки 
4.QImageWriter, QImageReader - для измерения параметров изображения 
5.QTableWidget - представление информации в виде таблицы 
6.QFileDialog - функционал для множественного выбора файлов 

Функционал:
- Возможность свободного перемещение по файловой системе. 
- Отображение в таблице, такой информации как: имя файла, размер файла(в пикселях),разрешение (dot/inch), глубина цвета, сжатие(для файлов, где оно применимо) только для графических файлов. 
- Возможность выбора папки с несколькими изображениями и описание всех изображений в таблице при выборе кнопеи “Папки”. 

Основные файлы:
- file.cpp
- file.h
- main.cpp
- file.ui
