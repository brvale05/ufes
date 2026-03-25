import java.time.LocalDate;
import java.time.Period;

public class Jogador {

    private String cpf;
    private String nome;
    private LocalDate data_de_nasc;

    public int calculaIdade(LocalDate data_nasc) {
        LocalDate data_atual = LocalDate.now();
        int idade = Period.between(data_nasc, data_atual).getYears();

        return idade;
    }

    public LocalDate getData_de_nasc() {
        return data_de_nasc;
    }

    public void setData_de_nasc(LocalDate data_de_nasc) throws Exception {
        if (this.calculaIdade(data_de_nasc) > 16) {
            this.data_de_nasc = data_de_nasc;
        } else {
            throw new Exception("Idade inferior a 16 anos");
        }
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) throws Exception {

        if (cpf.length() != 11 || cpf == null) {
            throw new Exception("CPF invalido");
        } else {
            this.cpf = cpf;
        }

    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Jogador(String cpf, String nome, LocalDate data_nasc) throws Exception {
        setCpf(cpf);
        setNome(nome);
        setData_de_nasc(data_nasc);
    }


    public Jogador(String cpf, String nome) throws Exception {
        setCpf(cpf);
        setNome(nome);
    }


}
