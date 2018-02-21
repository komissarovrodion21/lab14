[![Build Status](https://travis-ci.org/komissarovrodion21/lab10.svg?branch=master)](https://travis-ci.org/komissarovrodion21/lab13)

# Комиссаров Родион ИУ8-33
### Задание

Написать программы на **C++** для сериализации и десериализации структуры `Person`.

Структура `Person` определяется следующим образом:

```cpp
struct Email {
  std::string nickname;
  std::string server;
};

struct Person {
  std::string  first_name;
  std::string  last_name;
  Email        email;
  size_t       age;
  std::string  phone;
};
```

Результат проверки валидации при помощи выполения команды yamllint config.yaml
```ShellSession
$ config.yaml
$  1:1       warning  missing document start "---"  (document-start)
```
