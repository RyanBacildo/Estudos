package banco;

public class main {
    public main(String[] args) {
    }

    public static void main(String[] args) {
        Pessoa p1 = new Pessoa();
        p1.nome = "Ryan Lima Bacildo";
        p1.cpf = "010.101.010-10";
        p1.sexo = 'M';
        p1.idade = 18;

        Pessoa p2 = new Pessoa();
        p2.nome = "Hilário";
        p2.cpf = "000.000.000-00";
        p2.sexo = 'M';
        p2.idade = 20;

        Conta c1 = new Conta();
        c1.titular = p1;
        c1.numero = "1324-5";
        c1.saldo = 100.0;
        c1.limite = 200.0;

        Conta c2 = new Conta();
        c2.titular = p2;
        c2.numero = "1234-5";
        c2.saldo = 150.0;
        c2.limite = 200.0;

        c1.extrato();
        c2.extrato();

        c1.sacar(150);
        c1.transferir(100, c2);
        c1.sacar(100);
        c1.depositar(100);

    }
}