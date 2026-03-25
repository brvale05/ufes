import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public abstract class Pessoa 
{
    private String nome;
    private String cpf;
    private LocalDate dt_nasc;
    private String telefone;
    private String email;
    private List<Notificacao> minhasNotificacoes = new ArrayList<>();

    public void setNome(String nome) 
    {
        this.nome = nome;
    }

    public String getNome() 
    {
        return this.nome;
    }

    public void setCpf(String cpf) throws Exception
    {
        if (cpf == null || cpf.length() != 11){
            throw new Exception("O cpf deve conter 11 dígitos");
        }
        this.cpf = cpf;
    }

    public String getCpf() 
    {
        return this.cpf;
    }

    public void setDt_nasc(LocalDate dt_nasc) throws Exception {
    // Verifica se a data recebida é posterior (isAfter) à data de hoje
    if (dt_nasc.isAfter(LocalDate.now())) {
        throw new Exception("Erro: A data de nascimento não pode ser no futuro.");
    }
    this.dt_nasc = dt_nasc;
}

    public LocalDate getDt_nasc() 
    {
        return this.dt_nasc;
    }

    public void setTelefone(String telefone) throws Exception 
    {
        if(telefone == null || !telefone.matches("\\d{2}9\\d{8}")){

            throw new Exception("O número de telefone deve conter 11 dígitos e conter o dígito 9 após o DDD");
        }
        this.telefone = telefone;
    }

    public String getTelefone() 
    {
        return this.telefone;
    }

    public void setEmail(String email) 
    {
        this.email = email;
    }

    public String getEmail() 
    {
        return this.email;
    }

    public Pessoa(String nome, String cpf, LocalDate dt_nasc, String telefone, String email) throws Exception
    {
        setNome(nome);
        setCpf(cpf);
        setDt_nasc(dt_nasc);
        setTelefone(telefone);
        setEmail(email);
    }

    public List<Notificacao> getMinhasNotificacoes() {
        return minhasNotificacoes;
    }

    public void setMinhasNotificacoes(Notificacao noti) {
        this.minhasNotificacoes.add(noti);
    }

    public void imprimeNotificacoes(){
        for(Notificacao n: this.minhasNotificacoes){
            n.notificaPessoa();
        }
        this.getMinhasNotificacoes().removeAll(minhasNotificacoes);
    }


    @Override
    public String toString() {
        return "Nome: " + nome + " | CPF: " + cpf + " | Data de Nascimento: " + dt_nasc + " | Telefone: " + telefone + " | Email: " + email;
    }
}
