#include <assert.h>
#include "Conversion.h"

/*
 * ConversionTest.c — Pruebas del modulo Conversion
 *
 * Mismas restricciones que StringTest.c:
 * solo assert, literales, sin salida a stdout.
 */

int main(void) {

    /* ── ToInteger — tiene un bug, estos tests ya estan activos ─────────── */
    assert(ToInteger("0") == 0);
    assert(ToInteger("1") == 1);
    assert(ToInteger("42") == 42);
    assert(ToInteger("-7") == -7);
    assert(ToInteger("100") == 100);

    /* ── Operacion libre — IsInteger ────────────────────────────────────── */
    assert(IsInteger("0") == 1);
    assert(IsInteger("42") == 1);
    assert(IsInteger("-7") == 1);
    assert(IsInteger("") == 0);
    assert(IsInteger("-") == 0);
    assert(IsInteger("4a") == 0);
    assert(IsInteger("--5") == 0);

    return 0;
}