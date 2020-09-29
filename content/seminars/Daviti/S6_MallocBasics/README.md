---
nav_order: 6
title: malloc-ის გამოყენება
parent: დავითი
grand_parent: სემინარები
---

# malloc-ის გამოყენება
[გარჩეული სავარჯიშო](/exercises/malloc_concatAll/problem.pdf)
სემინარის კოდები შეგიძლიათ იხილოთ [აქ](https://github.com/freeuni-paradigms/freeuni-paradigms.github.io/tree/master/content/seminars/Daviti/S6_MallocBasics)

### პირობა
`concatStrings.c`-ში დავწერეთ `ConcatStrings` ფუნქციის იმპლემენტაცია. გადმოგვეცემა ორი char * და ეს ორი სტრინგი უნდა მივაწებოთ ერთმანეთს და დავაბრუნოთ ახალი სტრინგი

`scheme.c`-ში დავწერეთ `ConcatAll` ფუნქციის იმპლემენტაცია. გადმოგვეცემა კოლექციის საწყისი წვერო და უნდა დავაბრუნოთ ამ კოლექციაში შემავალი ყველა სტრინგის თანმიმდევრული კონკატენაცია.


### გატესტვა
დაწერილი კოდი შეგიძლიათ გატესტოთ შემდეგი ბრძანებით
```
gcc scheme.h concatStrings.c concatStrings_test.c
./a.out
```