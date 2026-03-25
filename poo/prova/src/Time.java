import java.util.ArrayList;
import java.util.List;

public abstract class Time {

    private static final int MAX_JOGADORES = 3;
    private List<Jogador> jogadores;

    public Time(Jogador j1, Jogador j2, Jogador j3) {
        this.jogadores = new ArrayList<>(MAX_JOGADORES);
        this.jogadores.add(j1);
        this.jogadores.add(j2);
        this.jogadores.add(j3);
    }

    public List<Jogador> getJogadores() {
        return jogadores;
    }

}
