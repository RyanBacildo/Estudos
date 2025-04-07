package banco;

public class Pessoa {
    String nome;
    int idade;
    char sexo;
    String cpf;

    public Pessoa() {
    }

    void aniversario() {
        this.idade = this.idade+1;
    }

    void atribuiCPF(String c) {
        this.cpf = c;
    }

    int getIdade() {
        return idade;
    }
}