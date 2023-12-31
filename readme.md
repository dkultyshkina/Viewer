# :triangular_ruler: Программа "3DViewer"

![C++](https://img.shields.io/badge/C++-Solutions-blue.svg?style=flat&logo=cplusplus) 
![C](https://img.shields.io/badge/C-Solutions-blue.svg?style=flat&logo=c)
![Qt](https://img.shields.io/badge/Qt-blue.svg?style=flat&logo=qt)

**3D VIewer** - это приложение, которое поддерживает различные функции: просмотр файлов формата .obj и другие возможности для работы с выбранной пользователем 3D моделью

![GIF-изображение модели города с использованием приложения 3DViewer](images/CityModel.gif)

<p align="center"> GIF-изображение модели города с использованием приложения 3DViewer </p>

<br>

## 1. Назначение программы

<br>

![GIF-изображение модели куба с использованием приложения 3DViewer](images/CudeModel2.gif)

<p align="center">GIF-изображение модели куба с использованием приложения 3DViewer </p>

<br>

Данная программа предназаначена для выполнения **следующих функций**:

- загрузки каркасных моделей из файла формата obj с поддержкой списка вершин и поверхностей;
- перемещения выбранной каркасной модели на заданное расстояние относительно осей X, Y, Z;
- поворота выбранной каркасной модели на заданный угол относительно своих осей X, Y, Z;
- маштабирования каркасной мoдели на заданное значение.

<br>

Для удобства взаимодействия пользователя с программой был разработан графический интерфейс, который содержит:

- кнопку для выбора файла с моделью и поле для вывода его названия;
- зону визуализации каркасной модели;
- кнопки и поля ввода для перемещения модели;
- кнопки и поля ввода для поворота модели;
- кнопки и поля ввода для масштабирования модели;
- информацию о загруженной модели - название файла, количество вершин и ребер.

В качестве специального режима реализованы "настройки", которые позволяют:

- настраивать тип проекции (параллельная и центральная);
- настраивать тип (сплошная, пунктирная), цвет и толщину ребер, способ отображения (отсутствует, круг, квадрат), цвет и размер вершин;
- выбирать цвет фона;
- сохранять настройки между перезапусками программы.

В качестве специального режима реализована "запись", которая: 

- позволяет сохранять полученные изображения в файл в форматах bmp и jpeg
- позволяет по специальной кнопке записывать небольшие "скринкасты" - текущие пользовательские аффинные преобразования загруженного объекта в gif-анимацию (640x480, 10fps, 5s)

## 2. Условия выполнения программы

- Операционная система - **MacOS**.

<br>

![GIF-изображение модели бокала с использованием приложения 3DViewer](images/GlassModel.gif)

<p align="center"> GIF-изображение модели бокала с использованием приложения 3DViewer </p>

<br>

## 3. Выполнение программы

<br>

![GIF-изображение модели бокала с использованием приложения 3DViewer](images/CudeModel.gif)

<p align="center"> GIF-изображение модели бокала с использованием приложения 3DViewer </p>

<br>

### Для выполнения программы требуется установить ее. Это можно сделать, выполнив следующую последовательность действий:

<br>

- Необходимо ввести **make install** в командной строке в рабочем каталоге **3DViewer/src** и нажать **Enter**;
- После загрузки перейти в созданный каталог **build**;
- Открыть приложение **"3Dviewer"**.

<br>

### Для завершения работы программы нажать красную кнопку с крестиком на верхней панели приложения. Для удаления приложения:

<br>

- Необходимо ввести **make uninstall** в командной строке в рабочем каталоге **3DViewer/src**** и нажать **Enter**;
- Далее ввести **make clean** в командной строке в рабочем каталоге **3DViewer/src** и нажать **Enter**.

<br>

### Для помещения компонентов программы в архив:

<br>

- Необходимо ввести **make dist** в командной строке в рабочем каталоге **3DViewer/src** и нажать **Enter**.

<br>

### Для проведения тестов над программой требуется:

- Необходимо ввести **make tests** в командной строке в рабочем каталоге **3DViewer/src** и нажать **Enter**.

<br>

### Для просмотра отчета с покрытием тестами программы требуется:

- Необходимо ввести **make gcov_report** в командной строке в рабочем каталоге **3DViewer/src** и нажать **Enter**.

<br>

### Для просмотра отчета с покрытием тестами программы требуется:

- Необходимо ввести **make gcov_report** в командной строке в рабочем каталоге **3DViewer/src** и нажать **Enter**.

<br>

### Для просмотра соответствия кода с Google-style:

- Необходимо ввести **make clang-format** в командной строке в рабочем каталоге **3DViewer/src** и нажать **Enter**.

<br>

### Для просмотра текста программы на утечки на *Linux*

- Необходимо ввести **make valgrind** в командной строке в рабочем каталоге **3DViewer/src** и нажать **Enter**.

<br>

### Для очистки рабочего каталога 

- Необходимо ввести **make clean** в командной строке в рабочем каталоге **3DViewer/src** и нажать **Enter**.

<br>

### Для просмотра документации

- Необходимо ввести **make html** в командной строке в рабочем каталоге **3DViewer/src** и нажать **Enter**.

<br>

## Выполнение функций:

<br>

![Изображение модели бокала с использованием приложения 3DViewer](images/GlassModel.jpeg)

<p align="center"> Изображение модели бокала с использованием приложения 3DViewer </p>

<br>

- *загрузка каркасной модели из файла формата obj с поддержкой списка вершин и поверхностей*.

<br>

Для загрузки модели необходимо нажать командную кнопку "Открыть файл" и выбрать требуемый файл с расширением .obj, в котором должен содержаться список вершин и поверхностей.

<br>

- *перемещение выбранной каркасной модели на заданное расстояние относительно осей X, Y, Z*.

<br>

Для перемещения требуется выбрать значение X, Y, Z и указать его в соответствующих полях напротив командной кнопки "Перемещение модели". В противном случае, будет указано базовое значение перемещения 0 по неуказанным полям.

<br>

- *поворот выбранной каркасной модели на заданный угол относительно своих осей X, Y, Z*.

<br>

Для перемещения требуется выбрать значение X, Y, Z и указать его в соответствующих полях напротив командной кнопки "Поворот модели". В противном случае, будет указано базовое значение поворота 0 по неуказанным полям.

<br>

- *маштабирования каркасной мoдели на заданное значение*.

<br>

Для изменения маштаба модели требуется выбрать значение и указать его в соответствующем поле напротив командной кнопки "Маштабирование модели". В противном случае, будет указано базовое значение поворота 0 по неуказанному полю.

<br>

- *настройки тип проекции (параллельная и центральная)*.

<br>

Для настройки типа проекции необходимо выбрать из выпадающего поля требуемое значение после текста "Проекция" и нажать "Применить" в "View|Color". Поле с числовым значением будет доступно только после нажатия значения типа "Параллельная" для изменения маштаба модели. 

<br>

- *настроек типа (сплошная, пунктирная), цвета и толщины ребер, способа отображения (отсутствует, круг, квадрат), цвета и размера вершин*.

<br>

Для настройки данных параметров (тип, толщина) необходимо выбрать из выпадающих полей требуемые значения или указать числа в полях ввода после соответсвующих текстовых меток и нажать "Применить" в "View|Color". 

<br>

Для настройки цвета необходимо указать числа в полях ввода (R - red, G - green, B - blue)  после соответсвующих текстовых меток "Фон" и нажать "Применить" в "View|Color". 

<br>

- *настройки цвета фона*.

<br>

Для настройки данного параметра необходимо указать числа в полях ввода (R - red, G - green, B - blue)  после соответсвующей текстовой метки "Фон" и нажать "Применить" в "View|Color". 

<br>

- *сохранения настроек между перезапусками программы*.

<br>

Сохранение происходит автоматически.

<br>

- *позволяет сохранять полученные изображения в файл в форматах bmp и jpeg*.

<br>

В "Save | Download" необходимо нажать "Сохранить" под текстом "Сохранить полученное изображение" и выбрать в появившимся окне - место и формат сохраняемого изображения.

<br>

- *позволяет по специальной кнопке записывать небольшие "скринкасты" - текущие пользовательские аффинные преобразования загруженного объекта в gif-анимацию (640x480, 10fps, 5s)*.

<br>

В "Save | Download" необходимо нажать "Сохранить" под текстом "Загрузить объект в gif-анимацию", в течение 5 секунд программа будет записывать изображение. После окончания записи необходимо выбрать в появившимся окне место, куда будет загружено сохраняемое изображение.

<br>

## Графический интерфейс

<br>

![Изображение экрана графического интерфеса 3DViewer](images/ScreenFirst.png)

<p align="center"> Изображение экрана графического интерфеса 3DViewer </p>

<br>

![Изображение экрана графического интерфеса 3DViewer](images/ScreenSecond.png)

<p align="center"> Изображение экрана графического интерфеса 3DViewer </p>

<br>

![Изображение экрана графического интерфеса 3DViewer](images/ScreenThird.png)

<p align="center"> Изображение экрана графического интерфеса 3DViewer </p>


Created by seastarw and superboy
 



