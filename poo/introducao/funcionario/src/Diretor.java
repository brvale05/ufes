public final class Diretor extends Funcionario
{
    private float faturamento;

    public void setFaturamento(float _faturamento) 
    {
        this.faturamento = _faturamento;
    }

    public float getFaturamento() 
    {
        return this.faturamento;
    }

    public float calculaBonus()
    {
        if(getFaturamento() > 100000)
        {
            return 100000/4;
        }
        
        return 0;
    }   

    public Diretor(String _cpf, String _nome, float _salario)
    {
        super(_cpf, _nome, _salario);
    }

    @Override
    public void exibeDados()
    {
        System.out.println("DIRETOR:");
        super.exibeDados();
        System.out.println(getFaturamento());
        System.out.println("BONUS: " + calculaBonus());
    }
}
