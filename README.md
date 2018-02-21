[![Build Status](https://travis-ci.org/komissarovrodion21/lab14.svg?branch=master)](https://travis-ci.org/komissarovrodion21/lab14)
## Laboratory work XIV

```
$ open http://www.boost.org/doc/libs/1_64_0/doc/html/process.html
```

### Задание

Написать программу на **C++** для упрощения процесса сборки, установки и упаковки проектов основанных на конфигурационных файлах **CMakeLists.txt**.

Исполняемый файл программы должен иметь название **builder** и поддерживать следующие опции запуска:

```ShellSession
$ ./builder --help
Usage: builder [options]
Allowed options:
  --help                    : выводим вспомогательное сообщение
  --config <Release|Debug>  : указываем конфигурацию сборки (по умолчанию Debug)
  --install                 : добавляем этап установки (в директорию _install)
  --pack                    : добавляем этап упаковки (в архив формата tar.gz)
  --timeout <count>         : указываем время ожидания (в секундах)
```

Примеры запуска программы с описанием эквивалентных запусков процессов программы **CMake**.

```ShellSession
$ ./builder
<=>
#-H. устанавливаем каталог в который сгенерируется файл 
#-B_build указывает директорию для собираемых файлов 
#-D - заменяет команду set 
$ cmake -H. -B_builds -DCMAKE_INSTALL_PREFIX=_install -DCMAKE_BUILD_TYPE=Debug
#--build _builds создает бинарное дерево проекта 
$ cmake --build _builds
```
1
```ShellSession
$ ./builder --config Release
<=>
#-H. устанавливаем каталог в который сгенерируется файл
#-B_build указывает директорию для собираемых файлов
#-D - заменяет команду set
$ cmake -H. -B_builds -DCMAKE_INSTALL_PREFIX=_install -DCMAKE_BUILD_TYPE=Release
#--build _builds создает бинарное дерево проекта
$ cmake --build _builds
```


```ShellSession
$ ./builder --install
<=>
#-H. устанавливаем каталог в который сгенерируется файл
#-B_build указывает директорию для собираемых файлов
#-D - заменяет команду set
$ cmake -H. -B_builds -DCMAKE_INSTALL_PREFIX=_install -DCMAKE_BUILD_TYPE=Debug
#--build _builds создает бинарное дерево проекта
$ cmake --build _builds
#--target указывает необходимые для обработки цели
$ cmake --build _builds --target install
```

```ShellSession
$ ./builder --pack
<=>
#-H. устанавливаем каталог в который сгенерируется файл
#-B_build указывает директорию для собираемых файлов
#-D - заменяет команду set
$ cmake -H. -B_builds -DCMAKE_INSTALL_PREFIX=_install -DCMAKE_BUILD_TYPE=Debug
#--build _builds создает бинарное дерево проекта
$ cmake --build _builds
#--target указывает необходимые для обработки цели
$ cmake --build _builds --target package
```

```ShellSession
$ ./builder --install --pack
<=>
#-H. устанавливаем каталог в который сгенерируется файл
#-B_build указывает директорию для собираемых файлов
#-D - заменяет команду set
$ cmake -H. -B_builds -DCMAKE_INSTALL_PREFIX=_install -DCMAKE_BUILD_TYPE=Debug
#--build _builds создает бинарное дерево проекта
$ cmake --build _builds
#--target указывает необходимые для обработки цели
$ cmake --build _builds --target install
$ cmake --build _builds --target package
```

```ShellSession
$ ./builder --timeout 500
<=>
#-H. устанавливаем каталог в который сгенерируется файл
#-B_build указывает директорию для собираемых файлов
#-D - заменяет команду set
$ cmake -H. -B_builds -DCMAKE_INSTALL_PREFIX=_install -DCMAKE_BUILD_TYPE=Debug
#--build _builds создает бинарное дерево проекта
$ cmake --build _builds
```

### Требования

- [x] 1. Для работы с процессами необходимо использовать библиотеку **Boost.Process**.

- [X] 2. В случае если время ожидания истекает, то программа завершает **все** дочерние запущенные процессы.

- [X] 3. Этап установки запускается, только в случае успешного завершения процесса сборки.

- [X] 4. Этап упаковки запускается, только в случаях успешного завершения процесса сборки и 
успешного завершения процесса установки.

- [X] 5. Стандартные потоки вывода дочерних процессов необходимо перенаправить в стандартный поток 
вывода родительского процесса исполняемого файла **builder**.

### Ссылки

- [Boost.Process](http://www.highscore.de/boost/process/)
- [Boost.Program_options](http://www.boost.org/doc/libs/1_65_0/doc/html/program_options.html)..
