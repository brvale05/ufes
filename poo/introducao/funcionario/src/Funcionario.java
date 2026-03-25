public abstract class Funcionario 
{
    private String cpf;
    private String nome;
    private float salario;

    public abstract float calculaBonus();

    public void exibeDados()
    {
        System.out.println(getCpf());
        System.out.println(getNome());
        System.out.println(getSalario());
    }

    public void setCpf(String _cpf) 
    {
        this.cpf = _cpf;
    }

    public String getCpf() 
    {
        return this.cpf;
    }

    public void setNome(String _nome) 
    {
        this.nome = _nome;
    }

    public String getNome() 
    {
        return this.nome;
    }

    public void setSalario(float _salario) 
    {
        this.salario = _salario;
    }

    public float getSalario() 
    {
        return this.salario;
    }

    public Funcionario(String _cpf, String _nome, float _salario)
    {
        setCpf(_cpf);
        setNome(_nome);
        setSalario(_salario);
    }
}
