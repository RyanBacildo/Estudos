from boxtool.matrizes import *

chave_atual = [[6, 24, 1], [13, 16, 10], [20, 17, 15]]

def texto_para_numeros(texto):
    return [ord(char) - ord('A') for char in texto]

def numeros_para_texto(numeros):
    return "".join([chr(num + ord('A')) for num in numeros])

def encriptar(texto):
    global chave_atual
    n = len(chave_atual)
    texto = texto.replace(" ", "").upper()
    if len(texto) % n != 0:
        texto += "X" * (n - len(texto) % n)
    numeros = texto_para_numeros(texto)
    blocos = [numeros[i:i + n] for i in range(0, len(numeros), n)]
    texto_cifrado = []
    for bloco in blocos:
        resultado = multiplicar_matriz_vetor(chave_atual, bloco)
        texto_cifrado.extend(resultado)
    return numeros_para_texto(texto_cifrado)

def desencriptar(texto_cifrado):
    global chave_atual
    n = len(chave_atual)
    texto_cifrado = texto_cifrado.replace(" ", "").upper()
    numeros = texto_para_numeros(texto_cifrado)
    blocos = [numeros[i:i + n] for i in range(0, len(numeros), n)]
    inversa = matriz_inversa_mod(chave_atual)
    texto_original = []
    for bloco in blocos:
        resultado = multiplicar_matriz_vetor(inversa, bloco)
        texto_original.extend(resultado)
    return numeros_para_texto(texto_original)

def alterar_chave(nova_chave):
    global chave_atual
    if matriz_valida(nova_chave):
        chave_atual = nova_chave
    else:
        raise ValueError("A nova matriz-chave não é válida (não é inversível mod 26).")