import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;

public class Barbeiro extends Empregado
{
    
    private List<Reserva> minhasReservas = new ArrayList<>();

    public Barbeiro(String nome, String cpf, LocalDate dt_nasc, String telefone, String email, double salario) throws Exception
    {
        super(nome, cpf, dt_nasc, telefone, email, LocalDate.now(), salario);
    }

    public List<Reserva> listarAgendaComIndices(StatusReserva filtroStatus) {
        System.out.println("Agenda do Barbeiro: " + this.getNome());
        List<Reserva> reservasFiltradas = new ArrayList<>();
        for (Reserva r : this.minhasReservas) {
            if (r.getStatus() == filtroStatus) {
                reservasFiltradas.add(r);
            }
        }
        return reservasFiltradas;
    }

    public void adicionarNaAgenda(Reserva reserva)
    {
        this.minhasReservas.add(reserva);
    }

    public void listarAgenda()
    {
        System.out.println("Agenda do Barbeiro: " + this.getNome());
        for (Reserva r : this.minhasReservas)
        {
            r.exibirReserva();
        }
    }

    public void listarAgenda(StatusReserva filtroStatus)
    {
        int cont=0;

        System.out.println("Agenda do Barbeiro: " + this.getNome());
        for (Reserva r : this.minhasReservas)
        {
            if (r.getStatus() == filtroStatus){
                r.exibirReserva();
                cont++;
            } 
        }
        if(cont == 0){
            System.out.println("==========Agenda vazia==========");
        }
    }

    public boolean estaDisponivel(LocalDateTime data, Servico novoServico)
    {
        LocalDateTime dataFimNovo = data.plusMinutes(novoServico.getDuracao());
        for (Reserva r : this.minhasReservas)
        {

            if (r.getStatus() == StatusReserva.CANCELADA) {
                continue;
            }

            LocalDateTime dataInicioExistente = r.getData();
            LocalDateTime dataFimExistente = dataInicioExistente.plusMinutes(r.getServico().getDuracao());
            // Verifica se tem sobreposicao
            if (data.isBefore(dataFimExistente) && dataFimNovo.isAfter(dataInicioExistente))
            {
                return false; // Barbeiro ocupado nesse horário
            }
        }
        return true;
    }

    public boolean estaDisponivel(Reserva reserva)
    {
        for (Reserva r : this.minhasReservas)
        {

            if (r.getStatus() == StatusReserva.CANCELADA) {
                continue;
            }

            if (r.getData().isEqual(reserva.getData()))
            {
                return false; // Barbeiro ocupado nesse horário
            }
        }
        return true;
    }

    public boolean estaDisponivel(LocalDateTime data)
    {
        for (Reserva r : this.minhasReservas)
        {
            if (r.getData().isEqual(data))
            {
                return false; // Barbeiro ocupado nesse horário
            }
        }
        return true;
    }

    public List<LocalTime> getHorariosDisponiveis(LocalDate data, Servico servico)
    {
        List<LocalTime> horariosLivres = new ArrayList<>();
        // Define o expediente
        LocalTime inicioExpediente = LocalTime.of(13, 0); // Abre as 13:00
        LocalTime fimExpediente = LocalTime.of(18, 0); // Fecha as 18:00
        // Intervalo entre servicos.
        int intervaloEmMinutos = 60;
        LocalTime horaAtual = inicioExpediente;
        // Loop enquanto o horario atual + servico nao passar do fim do expediente
        while (horaAtual.plusMinutes(intervaloEmMinutos).isBefore(fimExpediente) ||
                horaAtual.plusMinutes(intervaloEmMinutos).equals(fimExpediente))
        {
            // Monta a data completa (Dia + Hora do loop)
            LocalDateTime dataHoraTeste = LocalDateTime.of(data, horaAtual);
            // Verifica colisao
            if (this.estaDisponivel(dataHoraTeste, servico))
            {
                horariosLivres.add(horaAtual);
            }
            // Pula para o proximo horario
            horaAtual = horaAtual.plusMinutes(intervaloEmMinutos);
        }
        return horariosLivres;
    }

    public void listaHorariosDisponiveis(LocalDate data, Servico servico)
    {
        List<LocalTime> horariosLivres = getHorariosDisponiveis(data, servico);
        System.out.println("========== Horários Disponíveis ==========");
        for (int i = 0; i < horariosLivres.size(); i++)
        {
            System.out.println("[" + i + "] " + horariosLivres.get(i));
        }
    }

    public void finalizaReserva(Reserva reserva)
    {

        Cliente cliente = reserva.getCliente();

        // Marca a reserva como concluida
        reserva.setStatus(StatusReserva.CONCLUIDA);

        // Notificacao para o cliente
        Notificacao notificacao = new Notificacao(
                "Avaliação Pendente",
                StatusReserva.CONCLUIDA,
                cliente,
                this);
        
        
        cliente.setMinhasNotificacoes(notificacao);
    }

    public Reserva getReservaPorIndice(int indice) throws Exception{
        if (indice >= 0 && indice < minhasReservas.size()) {
            return minhasReservas.get(indice);
        } else {
            throw new Exception("Indice invalido");
        }
    }

    public double calcularMediaAvaliacoes() {
        int soma = 0;
        int count = 0;
        for (Reserva reserva : minhasReservas) {
            if (reserva.getStatus() == StatusReserva.AVALIADO && reserva.getAvaliacao() != null) {
                soma += reserva.getAvaliacao().getNota();
                count++;
            }
        }
        if (count > 0) return (double) soma / count;
        else return 0;
    }

    @Override
    public String toString()
    {
        // return "Barbeiro: " + this.getNome() + ", Rating: " + this.rating;
        return "Barbeiro: " + super.toString() + ", Média de Avaliações: " + String.format("%.2f", this.calcularMediaAvaliacoes());
    }
}
