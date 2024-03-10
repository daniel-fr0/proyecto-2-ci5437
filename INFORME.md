# Informe

## Modificaciones

Se modificó el archivo othello_cut.h, agregando la configuración de las diagonales (dia1 y dia2) de la representacion del problema. También se agregó una función "movs_posibles" a la clase state_t con la cual se puede saber las posiciones de los movimientos posibles de un estado; la función retorna un vector de enteros con las posiciones y funciona de forma similar a la funcion "get_random_move".

## Algoritmos

Se implementan los algoritmos negamax, negamax con poda alpha-beta, scout y negascout de manera correcta. Los resultados de los algoritmos verifican esto al mostrar que en cada caso se obtiene el valor de -4, que es el esperado como solucion para este problema.

## Resultados experimentales

### Negamax
| Starting Depth | Move | Value | #Expanded | #Generated | Seconds | #Generated/Second |
| -------------- | ---- | ----- | --------- | ---------- | ------- | ----------------- |
| 34 | White moves | -4 | 0 | 1 | 0 | inf | 
| 33 | Black moves | -4 | 1 | 2 | 1.00001e-06 | 1.99998e+06 | 
| 32 | White moves | -4 | 3 | 5 | 1.00001e-06 | 4.99996e+06 | 
| 31 | Black moves | -4 | 4 | 6 | 9.99949e-07 | 6.0003e+06 | 
| 30 | White moves | -4 | 9 | 13 | 3.00002e-06 | 4.3333e+06 | 
| 29 | Black moves | -4 | 10 | 14 | 2.99996e-06 | 4.66672e+06 | 
| 28 | White moves | -4 | 64 | 91 | 1.9e-05 | 4.78948e+06 | 
| 27 | Black moves | -4 | 125 | 177 | 3.3e-05 | 5.36363e+06 | 
| 26 | White moves | -4 | 744 | 1049 | 0.000201 | 5.21891e+06 | 
| 25 | Black moves | -4 | 3168 | 4498 | 0.000865 | 5.2e+06 | 
| 24 | White moves | -4 | 8597 | 11978 | 0.002209 | 5.42236e+06 | 
| 23 | Black moves | -4 | 55127 | 76826 | 0.01483 | 5.18044e+06 | 
| 22 | White moves | -4 | 308479 | 428402 | 0.085451 | 5.01342e+06 | 
| 21 | Black moves | -4 | 2525249 | 3478735 | 0.676624 | 5.14131e+06 | 
| 20 | White moves | -4 | 9459570 | 13078933 | 2.65183 | 4.93204e+06 | 
| 19 | Black moves | -4 | 65121519 | 90647895 | 18.9327 | 4.78789e+06 | 
| 18 | White moves | -4 | 625084814 | 876269598 | 185.91 | 4.71341e+06 | 
| 17 | Black moves | -4 | 3999381161 | 1305006091 | 1165.07 | 1.12011e+06 | 

### Negamax con poda alfa-beta
| Starting Depth | Move | Value | #Expanded | #Generated | Seconds | #Generated/Second |
| -------------- | ---- | ----- | --------- | ---------- | ------- | ----------------- |
| 34 | White moves | -4 | 0 | 1 | 9.99949e-07 | 1.00005e+06 | 
| 33 | Black moves | -4 | 1 | 2 | 1.00001e-06 | 1.99998e+06 | 
| 32 | White moves | -4 | 3 | 5 | 2.00002e-06 | 2.49998e+06 | 
| 31 | Black moves | -4 | 4 | 6 | 1.00001e-06 | 5.99995e+06 | 
| 30 | White moves | -4 | 9 | 13 | 2.99991e-06 | 4.33347e+06 | 
| 29 | Black moves | -4 | 10 | 14 | 3.00002e-06 | 4.66663e+06 | 
| 28 | White moves | -4 | 21 | 27 | 7.00005e-06 | 3.85711e+06 | 
| 27 | Black moves | -4 | 62 | 82 | 1.8e-05 | 4.55555e+06 | 
| 26 | White moves | -4 | 186 | 238 | 5.5e-05 | 4.32728e+06 | 
| 25 | Black moves | -4 | 769 | 1003 | 0.000234 | 4.28633e+06 | 
| 24 | White moves | -4 | 1152 | 1502 | 0.000345 | 4.35362e+06 | 
| 23 | Black moves | -4 | 3168 | 4068 | 0.001106 | 3.67812e+06 | 
| 22 | White moves | -4 | 7031 | 9130 | 0.002248 | 4.06139e+06 | 
| 21 | Black moves | -4 | 76021 | 98755 | 0.023294 | 4.2395e+06 | 
| 20 | White moves | -4 | 98129 | 127644 | 0.031111 | 4.10286e+06 | 
| 19 | Black moves | -4 | 205017 | 267604 | 0.063989 | 4.18203e+06 | 
| 18 | White moves | -4 | 960343 | 1259430 | 0.291508 | 4.3204e+06 | 
| 17 | Black moves | -4 | 1549785 | 2031924 | 0.481427 | 4.22063e+06 | 
| 16 | White moves | -4 | 22325108 | 29501798 | 7.04395 | 4.18825e+06 | 
| 15 | Black moves | -4 | 32949019 | 43574643 | 10.6008 | 4.11051e+06 | 
| 14 | White moves | -4 | 82016158 | 107642871 | 26.6811 | 4.03442e+06 | 
| 13 | Black moves | -4 | 315074162 | 415909956 | 99.328 | 4.18724e+06 | 
| 12 | White moves | -4 | 2230058150 | 2931981147 | 697.149 | 4.20568e+06 |  

### Scout
| Starting Depth | Move | Value | #Expanded | #Generated | Seconds | #Generated/Second |
| -------------- | ---- | ----- | --------- | ---------- | ------- | ----------------- |
| 34 | White moves | -4 | 0 | 1 | 1.00001e-06 | 999992 | 
| 33 | Black moves | -4 | 1 | 2 | 2.00002e-06 | 999992 | 
| 32 | White moves | -4 | 3 | 4 | 3.99991e-06 | 1.00002e+06 | 
| 31 | Black moves | -4 | 4 | 5 | 3.00002e-06 | 1.66665e+06 | 
| 30 | White moves | -4 | 14 | 17 | 9.99996e-06 | 1.70001e+06 | 
| 29 | Black moves | -4 | 15 | 18 | 8.99995e-06 | 2.00001e+06 | 
| 28 | White moves | -4 | 26 | 29 | 1.6e-05 | 1.8125e+06 | 
| 27 | Black moves | -4 | 64 | 78 | 3.89999e-05 | 2e+06 | 
| 26 | White moves | -4 | 314 | 371 | 0.00014 | 2.65e+06 | 
| 25 | Black moves | -4 | 1334 | 1622 | 0.000487 | 3.3306e+06 | 
| 24 | White moves | -4 | 2011 | 2458 | 0.000725 | 3.39035e+06 | 
| 23 | Black moves | -4 | 3232 | 3939 | 0.001204 | 3.2716e+06 | 
| 22 | White moves | -4 | 10214 | 12827 | 0.003249 | 3.94798e+06 | 
| 21 | Black moves | -4 | 42358 | 53358 | 0.01405 | 3.79772e+06 | 
| 20 | White moves | -4 | 68853 | 87634 | 0.021553 | 4.06598e+06 | 
| 19 | Black moves | -4 | 157458 | 202509 | 0.049043 | 4.12921e+06 | 
| 18 | White moves | -4 | 497954 | 645204 | 0.159289 | 4.05052e+06 | 
| 17 | Black moves | -4 | 911296 | 1185365 | 0.307551 | 3.85421e+06 | 
| 16 | White moves | -4 | 6096169 | 7963120 | 2.0448 | 3.89433e+06 | 
| 15 | Black moves | -4 | 23572285 | 30894777 | 7.83372 | 3.94382e+06 | 
| 14 | White moves | -4 | 57114374 | 74495053 | 19.1722 | 3.88558e+06 | 
| 13 | Black moves | -4 | 211427675 | 276746695 | 68.7142 | 4.02751e+06 | 
| 12 | White moves | -4 | 545805549 | 712796412 | 180.685 | 3.94498e+06 | 

### Negascout
| Starting Depth | Move | Value | #Expanded | #Generated | Seconds | #Generated/Second |
| -------------- | ---- | ----- | --------- | ---------- | ------- | ----------------- |
| 34 | White moves | -4 | 0 | 1 | 1.00001e-06 | 999992 | 
| 33 | Black moves | -4 | 1 | 2 | 2.00002e-06 | 999992 | 
| 32 | White moves | -4 | 3 | 5 | 2.00002e-06 | 2.49998e+06 | 
| 31 | Black moves | -4 | 4 | 6 | 2.00002e-06 | 2.99998e+06 | 
| 30 | White moves | -4 | 14 | 20 | 4.00003e-06 | 4.99996e+06 | 
| 29 | Black moves | -4 | 15 | 21 | 3.99991e-06 | 5.25011e+06 | 
| 28 | White moves | -4 | 26 | 34 | 8.00006e-06 | 4.24997e+06 | 
| 27 | Black moves | -4 | 64 | 84 | 2e-05 | 4.19999e+06 | 
| 26 | White moves | -4 | 312 | 398 | 9.1e-05 | 4.37363e+06 | 
| 25 | Black moves | -4 | 1275 | 1668 | 0.000385 | 4.33247e+06 | 
| 24 | White moves | -4 | 1894 | 2465 | 0.000578 | 4.2647e+06 | 
| 23 | Black moves | -4 | 3051 | 3898 | 0.000954 | 4.08595e+06 | 
| 22 | White moves | -4 | 9316 | 12067 | 0.002809 | 4.29584e+06 | 
| 21 | Black moves | -4 | 37959 | 48674 | 0.011786 | 4.12982e+06 | 
| 20 | White moves | -4 | 63522 | 81826 | 0.020039 | 4.08334e+06 | 
| 19 | Black moves | -4 | 142545 | 184361 | 0.045035 | 4.09373e+06 | 
| 18 | White moves | -4 | 466053 | 606378 | 0.157657 | 3.84619e+06 | 
| 17 | Black moves | -4 | 869928 | 1134797 | 0.290277 | 3.90936e+06 | 
| 16 | White moves | -4 | 5517551 | 7223328 | 1.93426 | 3.73441e+06 | 
| 15 | Black moves | -4 | 19704698 | 25833440 | 6.78626 | 3.80673e+06 | 
| 14 | White moves | -4 | 47600175 | 62053925 | 16.3269 | 3.80072e+06 | 
| 13 | Black moves | -4 | 185296093 | 242589301 | 61.8079 | 3.92489e+06 | 
| 12 | White moves | -4 | 477000927 | 623019805 | 161.629 | 3.85462e+06 | 


## Analisis
Podemos observar en primer lugar que el algoritmo que obtuvo el menor tiempo fue negascout, que es el algoritmo que combina la poda alfa-beta con la poda de scout.

Podemos comparar el rendimiento de los algoritmos si los comparamos en la misma profundidad, vamos a tomar la profundidad 17, puesto que es la mayor profundidad alcanzada por todos los algoritmos medida en estos experimentos.
| Algorithm | Starting Depth | Move | Value | #Expanded | #Generated | Seconds | #Generated/Second |
| --------- | -------------- | ---- | ----- | --------- | ---------- | ------- | ----------------- |
| negamax | 17 | Black moves | -4 | 3999381161 | 1305006091 | 1165.07 | 1.12011e+06 |
| negamax a-b | 17 | Black moves | -4 | 1549785 | 2031924 | 0.481427 | 4.22063e+06 | 
| scout | 17 | Black moves | -4 | 911296 | 1185365 | 0.307551 | 3.85421e+06 |
| negascout | 17 | Black moves | -4 | 869928 | 1134797 | 0.290277 | 3.90936e+06 |

Aqui podemos ver que el menor tiempo realizado fue por negascout, demostrando su eficiencia en tiempo. La diferencia en tiempo no es tan grande para apreciar una ganancia significativa en la eficiencia en tiempo con respecto a scout, quien quedo en segundo lugar, pero se puede apreciar una diferencia en la cantidad de nodos que se exploran.

En cuanto a los **nodos expandidos**, negascout logra demostrar su eficiencia de busqueda al aplicar la poda de scout y alfa-beta, siendo asi el algoritmo que menos nodos explora en esta profundidad.

Por otro lado, al comparar los resultados de negamax y negamax a-b, podemos ver en practica el uso de la poda alfa-beta para disminuir la cantidad de nodos que explorar, puesto que se aprecia una disminución bastante significativa en la cantidad de nodos generados y expandidos, y por ende en el tiempo de ejecución. Esto coincide con lo esperado en la teoria, puesto que la poda alfa-beta se encarga de podar ramas que de otra forma serian exploradas de forma inecesaria para mejorar la solución.

Luego, si hacemos otra comparacion, esta vez en la profundidad 12, en la que los algoritmos con poda logran resolver el problema en todavia relativamente poco tiempo, podemos observar lo siguiente:
| Algorithm | Starting Depth | Move | Value | #Expanded | #Generated | Seconds | #Generated/Second |
| --------- | -------------- | ---- | ----- | --------- | ---------- | ------- | ----------------- |
| negamax a-b | 12 | White moves | -4 | 2230058150 | 2931981147 | 697.149 | 4.20568e+06 |
| scout | 12 | White moves | -4 | 545805549 | 712796412 | 180.685 | 3.94498e+06 |
| negascout | 12 | White moves | -4 | 477000927 | 623019805 | 161.629 | 3.85462e+06 |

Podemos ver que en este problema en particular esta resultando mas eficiente la poda que realiza scout que la que poda por alfa-beta, esto puede ser debido a la forma en que se generan los nodos en el problema, que hace que la poda de scout sea mas eficiente en este caso. Luego, al juntar los dos metodos en el algoritmo negascout podemos ver una mejora mas grande todavia en la eficiencia de busqueda, puesto que este en particular muestra otra vez haber sido el algoritmo en explorar la menor cantidad de nodos en esta profundidad y el que logra el menor tiempo de ejecución.

## Conclusiones

Podemos observar que el algoritmo que tuvo mejor rendimiento fue negascout, puesto que fue el que logró llegar mas cerca a la configuración inicial en menor tiempo que el resto; esto gracias a que pudo revisar(generar) una menor cantidad de nodos, disminuyendo en gran medida la cantidad de nodos relevantes a evaluar(expandir). Esto demuestra que la combinación de las podas alfa-beta y scout, las cuales pudimos observar que resultaron ser eficientes en sus respectivos algoritmos, logra una mejora significativa en la eficiencia de busqueda, tal como se esperaba en la teoria.

Cabe aclarar que ningun algoritmo logró llegar al estado inicial en la cantidad de tiempo que se le permitió para los experimentos, pero viendo los patrones podemos decir que lograran llegar a este estado de forma correcta si se les permite.