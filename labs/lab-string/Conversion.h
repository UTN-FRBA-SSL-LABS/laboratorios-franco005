#ifndef CONVERSION_H
#define CONVERSION_H

/*
 * Conversion.h — Operaciones de conversion entre tipos
 *
 * Nota de diseño: ToInteger no forma parte de la biblioteca String
 * porque su dominio de entrada es String pero su codominio es Integer,
 * cruzando la frontera entre tipos. Se separa aqui para mantener
 * la cohesion de cada modulo.
 */

/* ToInteger: String -> Integer
 * Pre:  s != NULL, s representa un entero valido en base 10
 *       (digitos con signo '-' opcional al inicio)
 * Post: devuelve el valor entero correspondiente a la cadena */
int ToInteger(const char *s);

/* IsInteger: String -> Boolean
 * Pre:  s != NULL
 * Post: devuelve 1 si s es un entero valido en base 10 (signo '-' opcional
 *       al inicio seguido de al menos un digito decimal), 0 si no */
int IsInteger(const char *s);

#endif