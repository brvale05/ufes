import java.time.LocalDate;

public class Ponto {

    private EnumPonto tipo_de_pontos;
    private LocalDate instante;
    private Jogador autor_do_ponto;

    public Ponto(EnumPonto tipo, LocalDate instante, Jogador autor)
    {
        setAutor_do_ponto(autor);
        setInstante(instante);
        setTipo_de_pontos(tipo);
    }

    public EnumPonto getTipo_de_pontos() {
        return tipo_de_pontos;
    }

    public void setTipo_de_pontos(EnumPonto tipo_de_pontos) {
        this.tipo_de_pontos = tipo_de_pontos;
    }

    public LocalDate getInstante() {
        return instante;
    }

    public void setInstante(LocalDate instante) {
        this.instante = instante;
    }

    public Jogador getAutor_do_ponto() {
        return autor_do_ponto;
    }

    public void setAutor_do_ponto(Jogador autor_do_ponto) {
        this.autor_do_ponto = autor_do_ponto;
    }

    

}
