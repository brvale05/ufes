public class Jogador
{
    private String cpf;
    private String nome;
    private String dt_nasc;
    private Time time;

    public String getCpf()
    {
        return cpf;
    }

    public void setCpf(String cpf) throws Exception
    {
        if (cpf.length() == 11)
        {
            this.cpf = cpf;
        } else
        {
            throw new Exception("CPF invalido");
        }
    }

    public String getNome()
    {
        return nome;
    }

    public void setNome(String nome)
    {
        this.nome = nome;
    }

    public String getDt_nasc()
    {
        return dt_nasc;
    }

    public void setDt_nasc(String dt_nasc)
    {
        this.dt_nasc = dt_nasc;
    }

    public Jogador(String _cpf, String _nome, String dt_nasc) throws Exception
    {
        setCpf(_cpf);
        setNome(_nome);
        setDt_nasc(dt_nasc);
    }

    public Jogador(String _cpf, String dt_nasc) throws Exception
    {
        setCpf(_cpf);
        setDt_nasc(dt_nasc);
    }

    public Time getTime()
    {
        return this.time;
    }

    public void setTime(Time _time)
    {
        this.time = _time;
    }
}
