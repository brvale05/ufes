public class Recurso {
    private String nome;
    private int quantidade;
    private int emUso;

    public Recurso(String nome, int quantidade) {
        setNome(nome);
        setQuantidade(quantidade);
        setEmUso();
    }

    // Consome 1 unidade do recurso
    public void consumir() {
        this.emUso++;
    }

    // Devolve 1 unidade (caso um barbeiro seja demitido, por exemplo)
    public void repor() {
        this.emUso--;
    }

    public boolean estaDisponivel() {
        return this.quantidade > this.emUso;
    }

    public int getEmUso()
    {
        return emUso;
    }

    public void setEmUso()
    {
        this.emUso = 0;
    }

    public void setNome(String _nome)
    {
        this.nome = _nome;
    }

    public String getNome() {
        return this.nome;
    }

    public int getQuantidade() {
        return this.quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    @Override
    public String toString() {
        return "Recurso: " + nome + ", Total: " + quantidade + ", Em Uso: " + emUso;
    }
}
