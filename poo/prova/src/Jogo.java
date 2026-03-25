import java.util.ArrayList;
import java.util.List;

public class Jogo {

    private Mandante time_mandante;
    private Visitante time_visitante;
    private List<Ponto> pontos = new ArrayList<>();

    private static int qtd_pontos = 0;

    public Jogo(Mandante mandante, Visitante visitante) {
        setTime_mandante(mandante);
        setTime_visitante(visitante);
    }

    public int getQtdPontos()
    {
        return qtd_pontos;
    }

    public void registraPonto(Ponto ponto) {
        this.pontos.add(ponto);
        qtd_pontos++;
    }

    public Mandante getTime_mandante() {
        return time_mandante;
    }

    public void setTime_mandante(Mandante time_mandante) {
        this.time_mandante = time_mandante;
    }

    public Visitante getTime_visitante() {
        return time_visitante;
    }

    public void setTime_visitante(Visitante time_visitante) {
        this.time_visitante = time_visitante;
    }

}
