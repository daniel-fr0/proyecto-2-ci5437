* Modificaciones

  Se modificó el archivo othello_cut.h, agregando la configuración de las diagonales (dia1 y dia2) de la representacion del problema. También se agregó una función "movs_posibles" a la clase state_t con la cual se puede saber las posiciones de los movimientos posibles de un estado; la función retorna un vector de enteros con las posiciones y funciona de forma similar a la funcion "get_random_move".

* Algoritmos

  Se implementan los algoritmos negamax, negamax con poda alpha-beta y negascout de manera correcta. Tambien se implementa el algoritmo scout, pero no funciona de la forma esperada, puesto que al cabo de ciertos estados, el valor -4 cambia.

* Conclusiones

  Podemos observar que el algoritmo que tuvo mejor rendimiento (menos scout por implementacion incorrecta) fue negascout, puesto que fue el que logró llegar mas cerca a la configuración inicial en menor tiempo que el resto; esto gracias a que pudo revisar una menor cantidad de nodos (ramas) que negamax y negamax ab, disminuyendo en gran medida la cantidad de nodos relevantes a evaluar.
  
