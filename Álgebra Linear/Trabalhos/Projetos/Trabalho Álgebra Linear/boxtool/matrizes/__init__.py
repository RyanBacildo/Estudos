def inverso_modular(a, m):
    for i in range(m):
        if (a * i) % m == 1:
            return i
    return None
    
def determinante_3x3(matriz):
    a, b, c = matriz[0]
    d, e, f = matriz[1]
    g, h, i = matriz[2]
    det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g)
    return det

def matriz_valida(chave):
    det = determinante_3x3(chave)
    det_mod = det % 26
    return inverso_modular(det_mod, 26) is not None

def matriz_adjunta(matriz):
    a, b, c = matriz[0]
    d, e, f = matriz[1]
    g, h, i = matriz[2]

    cofator_11 = (e * i - f * h)
    cofator_12 = -(d * i - f * g)
    cofator_13 = (d * h - e * g)
    cofator_21 = -(b * i - c * h)
    cofator_22 = (a * i - c * g)
    cofator_23 = -(a * h - b * g)
    cofator_31 = (b * f - c * e)
    cofator_32 = -(a * f - c * d)
    cofator_33 = (a * e - b * d)

    adjunta = [
        [cofator_11, cofator_21, cofator_31],
        [cofator_12, cofator_22, cofator_32],
        [cofator_13, cofator_23, cofator_33]
    ]
    return adjunta

def matriz_inversa_mod(matriz):
    det = determinante_3x3(matriz)
    det_mod = det % 26
    inv_det = inverso_modular(det_mod, 26)
    if inv_det is None:
        raise ValueError("A matriz não é inversível mod 26.")

    adjunta = matriz_adjunta(matriz)
    inversa = [[(inv_det * adjunta[i][j]) % 26 for j in range(3)] for i in range(3)]
    return inversa

def multiplicar_matriz_vetor(matriz, vetor):
    resultado = [
        (matriz[0][0] * vetor[0] + matriz[0][1] * vetor[1] + matriz[0][2] * vetor[2]) % 26,
        (matriz[1][0] * vetor[0] + matriz[1][1] * vetor[1] + matriz[1][2] * vetor[2]) % 26,
        (matriz[2][0] * vetor[0] + matriz[2][1] * vetor[1] + matriz[2][2] * vetor[2]) % 26
    ]
    return resultado