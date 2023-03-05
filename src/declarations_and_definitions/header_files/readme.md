# Header files

## __Three core rules__

## 1) __Idemopotence__

* ### The header files in multiple translation units should not break the build

* ### Either use __include guards__ or the __#pragma once__ directive

## 2) __Self containment__

* ### If you need to use any kind functionality from the header, __you should not include any other headers explicitly, rather use them within this header file__

* ### Make it possible to include __only one header from your project code to your translation unit__

## 3)  __Minimality__

* ### If you remove something from a header file, __this shouldnt break the build__

* ### Include only project headers in your implementation in order to make it portable, including eg __stdio should inly happen for FILE*__

## 4) __Include what you use__