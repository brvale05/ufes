public class Endereco
{
    private String logradouro;
    private String cidade;
    private String estado;
    private String cep;

    public void setLogradouro(String _logradouro)
    {
        this.logradouro = _logradouro;
    }

    public String getLogradouro()
    {
        return this.logradouro;
    }

    public void setCidade(String _cidade)
    {
        this.cidade = _cidade;
    }

    public String getCidade()
    {
        return this.cidade;
    }

    public void setEstado(String _estado)
    {
        this.estado = _estado;
    }

    public String getEstado()
    {
        return this.estado;
    }

    public void setCep(String _cep)
    {
        this.cep = _cep;
    }

    public String getCep()
    {
        return this.cep;
    }

    public Endereco(String _logradouro, String _cidade, String _estado, String _cep)
    {
        setLogradouro(_logradouro);
        setCidade(_cidade);
        setEstado(_estado);
        setCep(_cep);
    }
}