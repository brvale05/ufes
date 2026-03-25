public class Servico
{
    private int duracao;
    private double valor;
    private String nome;

    public Servico(int duracao, double valor, String nome)
    {
        this.duracao = duracao;
        this.valor = valor;
        this.nome = nome;
    }

    public int getDuracao()
    {
        return duracao;
    }

    public void setDuracao(int duracao)
    {
        this.duracao = duracao;
    }

    public double getValor()
    {
        return valor;
    }

    public void setValor(double valor)
    {
        this.valor = valor;
    }

    public String getnome()
    {
        return nome;
    }

    public void setnome(String nome)
    {
        this.nome = nome;
    }


    @Override
    public String toString() {
        return "Serviço: " + this.getnome() + ", Duração: " + this.getDuracao()+ " minutos, Valor: R$ " + String.format("%.2f", this.getValor());
    }
}
