#include "classe.h"

void aplicarTaxa(float *preco) {
    if (*preco > VALOR_BASE) {
        *preco += (*preco / 100.0 * DEZ_PORCENTO);
    } else {
        *preco += (*preco / 100.0 * CINCO_PORCENTO);
    }
}
