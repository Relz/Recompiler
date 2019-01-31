# Recompiler
Компилятор для языка программирования "Recode"

# Презентация

https://drive.google.com/open?id=1TgmdQSV1udmM_AjPmM8_GpUIFPEvDamPYiPgvwWZH-M

Презентация описывает работу компилятора. Однако, без комментариев к слайдам, которые были преподнесены аудитории устно, не вижу данную презентацию самодостаточной.

# Настройка среды

## Общий план действий

1. Установить LLVM
1. Установить Git
1. Установить Cmake
1. Скачать исходный код Recompiler
1. Собрать проект Recompiler
1. Запустить Recompiler с необходимыми ему двумя параметрами: предкомпилированная грамматика и исходный код Recode

## Пример выполнения плана действий

### OS: Arch Linux

Перед нами свежеустановленная система с графическим окружением Deepin UI.

#### Установка LLVM

`# pacman -S llvm`

![llvm install](https://user-images.githubusercontent.com/15068331/52066423-914cfd80-2589-11e9-90be-efa196f9cf4c.png)

#### Установка Git

`# pacman -S git`

![git install](https://user-images.githubusercontent.com/15068331/52066455-aaee4500-2589-11e9-946e-07f376a34d02.png)

#### Установка cmake

`# pacman -S cmake`

![cmake install](https://user-images.githubusercontent.com/15068331/52066497-ba6d8e00-2589-11e9-8967-61fc1385dda4.png)

#### Скачивание исходного кода Recompiler

`$ git clone --recurse-submodules -j8 https://github.com/Relz/Recompiler.git`

![clone](https://user-images.githubusercontent.com/15068331/52066521-c8231380-2589-11e9-976e-660379f0012d.png)

#### Сборка проекта Recompiler

`$ cd Recompiler && cmake -Bbuild && cd build && make`

![build project](https://user-images.githubusercontent.com/15068331/52066537-d2dda880-2589-11e9-9d7f-1283461a8e30.png)

#### Запуск Recompiler на одном из примеров

`./Recompiler ../recode_rules.precompiled "../Recode samples/sum matrixes.recode"`

![recode0](https://user-images.githubusercontent.com/15068331/52066586-e852d280-2589-11e9-8166-a61a9151acbb.png)

![recode1](https://user-images.githubusercontent.com/15068331/52066593-eab52c80-2589-11e9-98bc-58b7e8abff0b.png)

![recode2](https://user-images.githubusercontent.com/15068331/52066597-ec7ef000-2589-11e9-8612-d0b6fb676b31.png)

### OS: Windows

Компилятор и его зависимости никак не зависят от среды Linux или какой-либо другой, поэтому он должен успешно собираться и запускаться на OS Windows. Я буду рад, если кто-то создаст мне Pull Request с дополнением этого README для сборки и запуска Recompiler под OS Windows.



