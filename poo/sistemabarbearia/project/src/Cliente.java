import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.List;

public class Cliente extends Pessoa
{
    private List<Reserva> minhasReservas = new ArrayList<>();

    public Cliente(String nome, String cpf, LocalDate dt_nasc, String telefone, String email) throws Exception
    {
        super(nome, cpf, dt_nasc, telefone, email);
    }

    public void adicionarNaAgenda(Reserva reserva)
    {
        this.minhasReservas.add(reserva);
    }

    public void listarAgenda()
    {
        System.out.println("Agenda do Cliente: " + this.getNome());
        for (Reserva r : this.minhasReservas)
        {
            r.exibirReserva();
        }
    }

    public void avaliaReserva(Reserva reserva, int nota, String comentario) throws Exception
    {
        if (this.minhasReservas.contains(reserva) == false)
        {
            throw new Exception("Reserva não pertence a este cliente.");
        } else if (reserva.getStatus() == StatusReserva.AVALIADO)
        {
            throw new Exception("A reserva já foi avaliada.");      
        } else if (reserva.getStatus() != StatusReserva.CONCLUIDA)
        {
            throw new Exception("A reserva ainda não foi concluída. Não é possível avaliar.");
        } else
        {
            reserva.avaliaReserva(nota, comentario);
        }
    }

    public void cancelarReserva(Reserva reserva) throws Exception
    {
        // Verificaa se a reserva pertence ao cliente
        if (!this.minhasReservas.contains(reserva))
        {
            throw new Exception("Esta reserva não foi encontrada na sua agenda.");
        }
        // Verifica se ja nao foi processada
        if (reserva.getStatus() == StatusReserva.CANCELADA)
        {
            throw new Exception("Esta reserva já se encontra cancelada.");
        }
        if (reserva.getStatus() == StatusReserva.CONCLUIDA)
        {
            throw new Exception("Não é possível cancelar uma reserva já concluída.");
        }
        // Verificaa antecedencia (ex: 2 horas)
        long horasAteReserva = ChronoUnit.HOURS.between(LocalDateTime.now(), reserva.getData());
        // Se a reserva for no passado ou faltar menos de 2 horas
        if (horasAteReserva < 2)
        {
            throw new Exception("Cancelamento negado. A política exige antecedência mínima de 2 horas.");
        }

        Barbeiro barbeiro = reserva.getBarbeiro();
        // Efetivar o cancelamento
        reserva.setStatus(StatusReserva.CANCELADA);
        // Notificar o Barbeiro
        Notificacao notificacao = new Notificacao(
                "Cancelamento de Reserva",
                StatusReserva.CANCELADA,
                barbeiro, // Destinatário (Barbeiro)
                this // Remetente (Cliente)
        );

        barbeiro.setMinhasNotificacoes(notificacao);
        System.out.println("Reserva cancelada com sucesso.");
    }

    public Reserva getReservaPorIndice(int indice)
    {
        if (indice >= 0 && indice < this.minhasReservas.size())
        {
            return this.minhasReservas.get(indice);
        }
        return null;
    }

    // Melhoria na listagem para mostrar índices no menu
    public Boolean listarAgendaComIndices()
    {
        System.out.println("========== Agenda de " + this.getNome() + " ==========");
        if (minhasReservas.isEmpty())
        {
            System.out.println("Nenhuma reserva encontrada.");
            return false;
        } else
        {
            for (int i = 0; i < minhasReservas.size(); i++)
            {
                Reserva r = minhasReservas.get(i);
                System.out.println("[" + i + "] " + r.getServico().getnome() + " - " +
                        r.getData().format(java.time.format.DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm")) +
                        " (" + r.getStatus() + ")");
            }
            return true;
        }
    }

    public List<Reserva> listarAgendaComIndices(StatusReserva filtroReserva)
    {
        System.out.println("========== Agenda de " + this.getNome() + " ==========");
        ArrayList<Reserva> reservasFiltradas = new ArrayList<>();
        for (Reserva r : this.minhasReservas)
        {
            if (r.getStatus() == filtroReserva) reservasFiltradas.add(r);
        }
        return reservasFiltradas;
    }

    @Override
    public String toString()
    {
        return "Cliente: " + super.toString();
    }
}
