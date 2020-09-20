---
nav_order: 1
title: 1. შესავალი
parent: გვანცა
grand_parent: სემინარები
---

# შესავალი

ლინუქსის შელის ინსტრუქციები შეგიძლიათ იხილოთ [აქ](https://ubuntu.com/tutorials/command-line-for-beginners)

# გამოყენებული კოდები და მათი გაშვების ინსტრუქცია

## [c_examples](https://github.com/freeuni-paradigms/freeuni-paradigms.github.io/tree/master/content/seminars/Gvantsa/S1_Introduction/c_examples)

კოდის დასაკომპილირებლად გამოიყენეთ ბრძანება
```
gcc <ფაილის სახელი>
./a.out
```

მაგალითად:
```
gcc strings.c
./a.out
```

თუ გინდათ რომ გამშვებ ფაილს 'a.out' არ ერქვას გამოიყენეთ -o ფლეგი კომპილაციისას მაგალითად:
```
gcc strings.c -o strings
./strings
```

## [gcd](https://github.com/freeuni-paradigms/freeuni-paradigms.github.io/tree/master/content/seminars/Gvantsa/S1_Introduction/gcd)
C კოდის დაკომპილირება და გაშვება
```
gcc gcd.c -o gcd
./gcd
```

C++ კოდის დაკომპილირება და გაშვება
```
g++ gcd.cpp -o gcd
./gcd
```

Java კოდის დაკომპილირება და გაშვება
```
javac GCD.java
java GCD
```

python კოდის გაშვება
```
python gcd.py
```