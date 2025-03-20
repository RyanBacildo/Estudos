import numpy as np
import math

def gerar_matriz_valida(dimensao):
    while True:
        # Gera uma matriz aleatória com valores entre 0 e 25
        matriz = np.random.randint(0, 26, size=(dimensao, dimensao))
        det = int(np.round(np.linalg.det(matriz)))  # Calcula o determinante
        det = det % 26  # Reduz o determinante módulo 26
        if math.gcd(det, 26) == 1:  # Verifica se o determinante é coprimo com 26
            return matriz

# Exemplo de uso
matriz_valida = gerar_matriz_valida(3)
print("Matriz válida:\n", matriz_valida)