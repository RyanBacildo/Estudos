def main():
  arquivo = "bdveiculos.txt"
  marca = {}
  marcas = {}
  veiculos = []
  
  arq = open(arquivo, "rt")
  
  linha = arq.readline().strip()
  while linha != "":
    placa=linha
    linha = arq.readline().strip()
    modelo=linha
    linha = arq.readline().strip()
    marca=linha
    linha = arq.readline().strip()
    km=linha
    veiculos.append(placa)
    veiculos.append(modelo)
    veiculos.append(km)
    

    if marca in marcas:
      marcas[marca].append((placa,modelo,km))
    else:
      marcas[marca] = [(placa,modelo,km)]

    linha = arq.readline().strip()
  
  arq.close()
  print(marcas)
  return 0
main()