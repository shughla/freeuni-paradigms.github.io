---
nav_order: 2
title: 2. ლინუქსი, კომპილაცია
parent: გვანცა
grand_parent: სემინარები
---

# გამოყენებული კოდები და მათი გაშვების ინსტრუქცია

## [unix basics](https://github.com/freeuni-paradigms/freeuni-paradigms.github.io/tree/master/content/seminars/Gvantsa/S2_linux_compilation/script.sh)
[გამოყენებული ჰენდაუთი](https://freeuni-paradigms.github.io/content/handouts/unix_basic_commands.pdf)

`script.sh` ფაილის გაშვება
```
./script.sh
```

## [compilation](https://github.com/freeuni-paradigms/freeuni-paradigms.github.io/tree/master/content/seminars/Gvantsa/S2_linux_compilation/compilation)
[გამოყენებული ჰენდაუთი](https://freeuni-paradigms.github.io/content/handouts/compilation_process.pdf)


```C
gcc -E hw.c -o hw.i //პრეპროცესინგი
gcc -S hw.c -o hw.s //კომპილაცია
gcc -c hw.c -o hw.o //ესემბლერი
gcc hw.c -o hw.out
```

## [makefile](https://github.com/freeuni-paradigms/freeuni-paradigms.github.io/tree/master/content/seminars/Gvantsa/S2_linux_compilation/word-games)
[გამოყენებული ჰენდაუთი](https://freeuni-paradigms.github.io/content/handouts/make_utility.pdf)

```
make
./word-games
```