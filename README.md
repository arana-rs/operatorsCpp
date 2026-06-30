# Práctica: Sobrecarga de operadores en C++

Este repositorio contiene el código base para implementar una clase `Fraction`.
El objetivo es estudiar constructores, invariantes, métodos `const` y sobrecarga de operadores como funciones miembro y funciones no miembro.

## Estructura

```text
.
|-- Makefile
|-- README.md
|-- include
|   `-- Fraction.h
|-- src
|   `-- Fraction.cc
`-- tests
    `-- main.cc
```

## Compilar

```bash
make
```

## Ejecutar pruebas

```bash
make run
```

Al inicio, varias pruebas fallarán porque `src/Fraction.cc` contiene funciones marcadas con `TODO`.
La meta del laboratorio es completar esas funciones hasta que todas las pruebas pasen.

## Limpiar

```bash
make clean
```

## Tareas principales

Complete la implementación de:

- `normalize()`
- `operator+=` y `operator-=` como funciones miembro
- `operator+`, `operator-`, `operator*` y `operator/` como funciones no miembro
- operadores de comparación
- `operator<<`
- `operator>>`

## Preguntas conceptuales

Responda estas preguntas en este mismo archivo, debajo de cada enunciado.

### 1. ¿Por qué `operator+=` se implementa naturalmente como función miembro?

Respuesta: Porque su objetivo es modificar directamente el objeto `this` agregandole los valores de otro, y que sea
miembro facilita la modificacion de sus campos sin recurir a un _setter_.

### 2. ¿Por qué `operator+` puede implementarse como función no miembro?

Respuesta: Porque no tiene la necesidad de modificar ninguno de los operandos y devolver
un objeto nuevo.

### 3. ¿Por qué `operator<<` debe implementarse como función no miembro?

Respuesta: Aparte de que no se necesita modificar `Function` para activar el operador `<<`
se da en el orden `cout << f` asi que la implementacion se le hace a `cout` y no a `f`.

### 4. ¿Qué significa que un método sea `const`?

Respuesta: Que no se tiene intencion de que el objeto sea modificable y cualquier funcion
o modificacion hara que el compilador o LSP marque error.

### 5. ¿Qué invariante debe mantener la clase `Fraction`?

Respuesta: Son tres el numerador tiene que tener el signo de la fraccion con el denominador
siempre positivo, el denominador nunca tiene que ser cero y tiene que estar en forma reducida.

### 6. ¿Qué debe ocurrir si se intenta construir una fracción con denominador cero?

Respuesta: Lanza una excepcion.

### 7. ¿Por qué `operator>>` no debe modificar el objeto si la entrada es inválida?

Respuesta: Porque garantiza de que si es invalida no modifique el estado anterior del `f`
que se le paso (`cin >> f`).
