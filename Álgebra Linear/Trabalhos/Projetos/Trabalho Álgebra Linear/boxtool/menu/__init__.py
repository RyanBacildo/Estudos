from boxtool.criptografia import encriptar, desencriptar, alterar_chave, chave_atual

# Função para exibir o menu
def start_menu():
    while True:
        print("\n----- MENU INICIAL -----\n")
        print("1. Encriptar uma mensagem")
        print("2. Desencriptar uma mensagem")
        print("3. Alterar a chave padrão")
        print("4. Sair")
        opcao = input("Escolha uma opção: ")

        if opcao == "1":
            mensagem = input("Digite a mensagem a ser encriptada: ")
            usar_padrao = input("Deseja usar a matriz-chave padrão? (S/N): ").strip().upper()
            if usar_padrao != "S":
                nova_chave_input = input("Digite a nova matriz-chave (exemplo: [[6, 24, 1], [13, 16, 10], [20, 17, 15]]): ")
                try:
                    nova_chave = eval(nova_chave_input)
                    alterar_chave(nova_chave)
                    print("Nova chave definida com sucesso!")
                except Exception as e:
                    print(f"Erro ao definir a nova chave: {e}")
                    continue
            try:
                mensagem_cifrada = encriptar(mensagem)
                print(f"\nMensagem cifrada: {mensagem_cifrada}")
            except Exception as e:
                print(f"Erro ao encriptar: {e}")

        elif opcao == "2":
            mensagem_cifrada = input("Digite a mensagem cifrada: ")
            usar_padrao = input("Deseja usar a matriz-chave padrão? (S/N): ").strip().upper()
            if usar_padrao != "S":
                nova_chave_input = input("Digite a nova matriz-chave (exemplo: [[6, 24, 1], [13, 16, 10], [20, 17, 15]]): ")
                try:
                    nova_chave = eval(nova_chave_input)
                    alterar_chave(nova_chave)
                    print("Nova chave definida com sucesso!")
                except Exception as e:
                    print(f"Erro ao definir a nova chave: {e}")
                    continue
            try:
                mensagem_original = desencriptar(mensagem_cifrada)
                print(f"\nMensagem desencriptada: {mensagem_original}")
            except Exception as e:
                print(f"Erro ao desencriptar: {e}")

        elif opcao == "3":
            print("\nChave atual:", chave_atual)
            nova_chave_input = input("Digite a nova matriz-chave (exemplo: [[6, 24, 1], [13, 16, 10], [20, 17, 15]]): ")
            try:
                nova_chave = eval(nova_chave_input)
                alterar_chave(nova_chave)
                print("Chave alterada com sucesso!")
            except Exception as e:
                print(f"Erro ao alterar a chave: {e}")

        elif opcao == "4":
            print("Saindo do programa...")
            break

        else:
            print("Opção inválida. Tente novamente.")