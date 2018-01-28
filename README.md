[![Build Status](https://travis-ci.org/komissarovrodion21/lab10.svg?branch=master)](https://travis-ci.org/komissarovrodion21/lab11)
## Laboratory work XI
Данная лабораторная работа посвещена изучению компонентов **Boost** на примере `program_options`

```ShellSession
$ open http://www.boost.org/doc/libs/1_65_0/doc/html/program_options.html
```

## Tasks

- [X] 1. Создать публичный репозиторий с названием **lab11** на сервисе **GitHub**
- [X] 2. Выполнить инструкцию учебного материала
- [X] 3. Ознакомиться со ссылками учебного материала
- [X] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial
Делаем первоначальные настройки, добавляя значения переменным окружения
```ShellSession
#Устанавливаем значение переменной окружения GITHUB_USERNAME
$ export GITHUB_USERNAME=komissarovrodion21
$ alias edit=nano
```

```ShellSession
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
```

Проводим первоначальные настройки для соединения с репозиторием 11 лабораторной работы
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab10 lab11 #клонирование удаленного репозитория 10 лабораторной в локальный каталог 11 лабораторной
$ cd lab11 #меняем директорию на lab11
$ git remote remove origin #Отключаемся от удаленного репозитория 10 лабораторной
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab11 #подключаемся к удаленному репозиторию 11 лабораторной

```
#Подключаем пакеты boost::program_options через Hunter и редактируем demo.cpp, используя пакет boost::program_options для выполнения дальнейших команд
```ShellSession
# boost::program_options
$ edit CMakeLists.txt #редактируем CMakeLists.txt
$ edit sources/demo.cpp #редактируем sources/demo.cpp

```

Работа с CMake
```ShellSession
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install #-H. устанавливаем каталог в который сгенерируется файл CMakeLists.txt,-B_build указывает директорию для собираемых файлов,-D - заменяет команду set
$ cmake --build _build --target install #--build _build создает бинарное дерево проекта, --target указывает необходимые для обработки цели
$ mkdir artifacts && cd artifacts #создаем директорию artifacts меняем директорию на artifacts

```
Создаем default.log
```ShellSession

$ echo "text1 text2 text3" | ../_install/bin/demo #c помощью программы записываем "text1 text2 text3" в default.log
$ test -f default.log #проверяем наличие данного файла
#Если 0, то файл существует, что соответствует истине
$ echo $?
0
```
Создаем config.log
```ShellSession
$ mkdir ${HOME}/.config #создаем директорию ${HOME}/.config
$ echo "output=config.log" > ${HOME}/.config/demo.cfg #вводим в demo.cfg значение output=config.log для дальнейшего вывода
$ echo "text1 text2 text3" | ../_install/bin/demo #с помощью нашей программы записываем "text1 text2 text3" в config.log
$ test -f config.log#проверяем наличие данного файла
#Если 0, то файл существует, что соответствует истине
$ echo $?
0
```
Создаем env.log
```ShellSession
$ export DEMO_OUTPUT=env.log #экспортируем глобальную переменную окружения DEMO_OUTPUT
$ echo "text1 text2 text3" | ../_install/bin/demo #с помощью нашей программы записываем "text1 text2 text3" в env.log
$ test -f env.log#проверяем наличие данного файла
#Если 0, то файл существует, что соответствует истине
$ echo $?
0
```
Создаем arg.log
```ShellSession
$ echo "text1 text2 text3" | ../_install/bin/demo --output arg.log #с помощью нашей программы записываем "text1 text2 text3" в arg.log, задавая его с помощью --output
$ test -f arg.log #проверяем наличие данного файла
#Если 0, то файл существует, что соответствует истине
$ echo $?
0
```
Редактируем README.md
```ShellSession
#редактируем README.md
gsed -i 's/lab10/lab11/g' README.md
```
Редактируем .travis.yml
```ShellSession
$ cat >> .travis.yml <<EOF
- cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
- cmake --build _build --target install
- mkdir artifacts && cd artifacts
- echo "text1 text2 text3" | ../_install/bin/demo
- test -f default.log
- mkdir ${HOME}/.config
- echo "output=config.log" > ${HOME}/.config/demo.cfg
- echo "text1 text2 text3" | ../_install/bin/demo
- test -f config.log
- export DEMO_OUTPUT=env.log
- echo "text1 text2 text3" | ../_install/bin/demo
- test -f env.log
- echo "text1 text2 text3" | ../_install/bin/demo --output arg.log
- test -f arg.log
EOF
```
Отправка на удаленный репозиторий 11 лабораторной работы
```ShellSession
#Добавляем все отредактированные файлы в подтвержденные
$ git add .
Создаем коммит с сообщением
$ git commit -m"changed format output"
#Выгружаем локальный репозиторий в удаленный репозиторий 11 лабораторной
$ git push origin master
```
Работа с Travis
```ShellSession
#Авторизуемся своим GITHUB аккаунтом
$ travis login --auto
#Включаем репозиторий в Travis
$ travis enable
```

## Report

```ShellSession
$ popd
$ export LAB_NUMBER=11
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [String Algorithms](http://www.boost.org/doc/libs/1_65_0/doc/html/string_algo.html)
- [Date Time](http://www.boost.org/doc/libs/1_65_0/doc/html/date_time.html)
- [DLL](http://www.boost.org/doc/libs/1_65_0/doc/html/boost_dll.html)
- [Heap](http://www.boost.org/doc/libs/1_65_0/doc/html/heap.html)
- [Interprocess](http://www.boost.org/doc/libs/1_65_0/doc/html/interprocess.html)
- [Lockfree](http://www.boost.org/doc/libs/1_65_0/doc/html/lockfree.html)
- [Lexicalcast](http://www.boost.org/doc/libs/1_65_0/doc/html/boost_lexical_cast.html)
- [Property Tree](http://www.boost.org/doc/libs/1_65_0/doc/html/property_tree.html)

```
Copyright (c) 2017 Братья Вершинины
```
