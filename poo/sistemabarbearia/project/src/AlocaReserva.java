import java.time.LocalDateTime;

public class AlocaReserva {

    public void realizarAgendamento(Cliente cliente, Barbeiro barbeiro, Servico servico, LocalDateTime data) throws Exception 
    {
        if (!barbeiro.estaDisponivel(data, servico)) {
            throw new Exception("Barbeiro já está ocupado");
        }

        Reserva novaReserva = new Reserva(data, cliente, barbeiro, servico);

        // Registra nas agendas
        barbeiro.adicionarNaAgenda(novaReserva);
        cliente.adicionarNaAgenda(novaReserva);

    }
}
