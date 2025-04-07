package banco;

public class Conta {
    String numero;
    Pessoa titular;
    double saldo;
    double limite;

    public Conta() {
    }

    double disponivel() {
        return this.saldo + this.limite;
    }

    void extrato() {
        System.out.println("\n*** EXTRATO DA CONTA ***");

        System.out.println("Conta: " + this.numero);
        System.out.println("Titular: " + this.titular.cpf);
        System.out.println("Saldo disponível pra saque: " + this.disponivel());

        System.out.println("\n");
    }

    void sacar(double valor) {
        if (valor<= this.saldo) {
            this.saldo = this.saldo - valor;
            System.out.println("\nSaque de " + valor + " realizado com sucesso.");
            System.out.println("Novo salvo: " + this.saldo);
        }
        else {
            System.out.println("\nErro: nao foi possivel sacar " + valor);
            System.out.println("Valor disponivel para saque: "+ valor);
        }
    }

    void depositar(double valor) {
        this.saldo = this.saldo + valor;
        System.out.println("\nDeposito de " + valor + " realizado com sucesso.");
        System.out.println("Novo saldo: " + this.saldo);
    }

    void transferir(double valor, Conta destino) {
        if (valor<= this.disponivel()) {
            this.saldo = this.saldo - valor;
            destino.depositar(valor);

            System.out.println("\nTransferencia de " + valor + " realizada com sucesso.");
            System.out.println("Origem: " + this.numero + " - Destino: " + destino.numero);
        }
        else {
            System.out.println("\nErro: nao foi possivel transferir " + valor);
            System.out.println("Valor disponivel para transferencia: " + this.disponivel());
        }
    }
}
