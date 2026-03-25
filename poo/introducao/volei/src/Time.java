import java.util.ArrayList;
import java.util.List;

public class Time
{
    private String nome;
    private List<Jogador> jogadores = new ArrayList<>(3);

    public String getNome()
    {
        return this.nome;
    }

    public void setNome(String _nome)
    {
        this.nome = _nome;
    }

    public void addJogador(Jogador player) throws Exception
    {
        if(!player.getTime().getNome().equals(this.nome))
        {
            throw new Exception("Jogador deve pertencer ao time.");
        }
        else if(this.jogadores.size() >= 3)
        {
            throw new Exception("Time ja possui 3 jogadores.");
        }
    }

    public void removeJogador(Jogador player)
    {
        this.jogadores.remove(player);
    }
}
