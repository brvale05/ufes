public class Cliente 
{
    private String nome;  
    private String cpf;
    private String telefone;
    private Endereco endereco;
    
    public void setNome(String _nome)
    {
        this.nome = _nome;
    }

    public String getNome()
    {
        return this.nome;
    }

    public void setCpf(String _cpf)
    {
        this.cpf = _cpf;
    }

    public String getCpf()
    {
        return this.cpf;
    }

    public void setTelefone(String _telefone)
    {
        this.telefone = _telefone;
    }

    public String getTelefone()
    {
        return this.telefone;
    }

    public void setEndereco(Endereco address)
    {
        this.endereco = address;
    }

    public Endereco getEndereco()
    {
        return this.endereco;
    }

    public Cliente(String _nome, String _cpf, String _telefone)
    {
        setNome(_nome);
        setCpf(_cpf);
        setTelefone(_telefone);
    }
    
}