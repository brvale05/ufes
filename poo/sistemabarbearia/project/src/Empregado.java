import java.time.LocalDate;

public class Empregado extends Pessoa {

    private LocalDate dt_adimissao;
    private double salario;

    // Set e Get da data de adimissão
    public void setAdimissao(LocalDate dt){
        this.dt_adimissao = dt;
    }

    public LocalDate getAdimissao(){
        return this.dt_adimissao;
    }

    //Set e Get do salario
    public void setSalario(double salario){
        this.salario = salario;
    }

    public double getSalario(){
        return this.salario;
    }

    //Construtora do Empregado (com o super)
    public Empregado(String nome, String cpf, LocalDate dt_nasc, String telefone, String email, LocalDate adimissao, double salario) throws Exception
    {
        super(nome, cpf, dt_nasc, telefone, email);
        setAdimissao(adimissao);
        setSalario(salario);
    }
    //
    
}
