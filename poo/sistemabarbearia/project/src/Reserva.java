import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Reserva {
    private LocalDateTime data;
    private Cliente cliente;
    private Barbeiro barbeiro;
    private Servico servico;
    private StatusReserva status; // Usando o enum StatusReserva
    private Avaliacao avaliacao; // Coloquei a avaliação como atributo da reserva

    public Reserva(LocalDateTime _data, Cliente _cliente, Barbeiro _barbeiro, Servico _servico) {
        setData(_data);
        setCliente(_cliente);
        setBarbeiro(_barbeiro);
        setServico(_servico);
        setAvaliacao(null);
        setStatus(StatusReserva.AGENDADA);
    }

    public void avaliaReserva(int _nota, String _comentario) throws Exception{
        // Lançar exceção pra null
        this.avaliacao = new Avaliacao(_nota, _comentario);
        this.setStatus(StatusReserva.AVALIADO);

    }

    public void exibirReserva() {
        System.out.println("==========-- Detalhes da Reserva ==========--");

        System.out.println("Tipo de Serviço: " + this.servico.getnome());

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("(dd/MM/yyyy HH:mm)");
        String dataFormatada = this.data.format(formatter);
        System.out.println("Data e Hora: " + dataFormatada);

        System.out.println("Cliente: " + this.cliente.getNome());
        System.out.println("Barbeiro: " + this.barbeiro.getNome());
        
        System.out.println("Tempo do Serviço: " + this.servico.getDuracao() + " minutos");
        System.out.println("Status da Reserva: " + this.status);
        if (this.avaliacao != null) {
            System.out.println("Avaliação da Reserva:");
            this.avaliacao.exibirAvaliacao();
        } else {
            System.out.println("Avaliação da Reserva: Ainda não avaliada.");
        }
        System.out.println("====================================================================================================-");
    }

    public Boolean verificaSePodeAvaliar(){
        return this.getStatus() == StatusReserva.CONCLUIDA;
    }

    public Boolean verificaSePodeCancelar(){
        return this.getStatus() == StatusReserva.AGENDADA;
    }

    // Getters e setters
    public Barbeiro getBarbeiro() {
        return this.barbeiro;
    }

    public Cliente getCliente() {
        return this.cliente;
    }

    public LocalDateTime getData() {
        return this.data;
    }

    public Servico getServico() {
        return this.servico;
    }

    public StatusReserva getStatus() {
        return this.status;
    }

    public void setBarbeiro(Barbeiro barbeiro) {
        this.barbeiro = barbeiro;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public void setData(LocalDateTime data) {
        this.data = data;
    }

    public void setServico(Servico servico) {
        this.servico = servico;
    }

    public void setStatus(StatusReserva status) {
        this.status = status;
    }

    public Avaliacao getAvaliacao() {
        return this.avaliacao;
    }

    public void setAvaliacao(Avaliacao avaliacao) {
        this.avaliacao = avaliacao;
    }

}
