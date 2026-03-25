import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Notificacao {
    private String titulo; // desnecessário provavelmente
    private StatusReserva status;
    private Pessoa destinatario;
    private Pessoa remetente;
    private LocalDateTime dataEnvio;
    private boolean lida; // desnecessario provavelmente

    public Notificacao(String _titulo, StatusReserva _status, Pessoa _destinatario, Pessoa _remetente) {
        this.titulo = _titulo;
        this.status = _status;
        this.destinatario = _destinatario;
        this.remetente = _remetente;
        this.dataEnvio = LocalDateTime.now();
        this.lida = false;
    }

    // Joga a notificação na tela 
    public void notificaPessoa() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("(dd/MM/yyyy HH:mm)");
        String dataFormatada = this.dataEnvio.format(formatter);
        System.out.printf("\n%s ", dataFormatada); // Notificar == jogar na saída
        switch (this.status) {
            case AGENDADA:
                System.out.printf("Olá %s, sua reserva com %s foi AGENDADA.\n", this.destinatario.getNome(),
                        this.remetente.getNome());
                break;

            case CONFIRMADA:
                System.out.printf("Olá %s, sua reserva com %s foi CONFIRMADA.\n", this.destinatario.getNome(),
                        this.remetente.getNome());
                break;

            case CANCELADA:
                System.out.printf("Olá %s, sua reserva com %s foi CANCELADA.\n", this.destinatario.getNome(),
                        this.remetente.getNome());
                break;

            case CONCLUIDA:
                System.out.printf("Olá %s, ficamos sabendo que sua reserva com %s foi feita!\n", this.destinatario.getNome(), this.remetente.getNome());
                System.out.println("Não se esqueça de deixar sua avaliação!");
                break;
        
            default:
            // Possível exceção aqui.
                break;
        }
    }

    // Getters e Setters
    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String _titulo) {
        titulo = _titulo;
    }

    public Pessoa getDestinatario() {
        return destinatario;
    }

    public void setDestinatario(Pessoa _destinatario) {
        destinatario = _destinatario;
    }

    public Pessoa getRemetente() {
        return remetente;
    }

    public void setRemetente(Pessoa _remetente) {
        remetente = _remetente;
    }

    public LocalDateTime getDataEnvio() {
        return dataEnvio;
    }

    public void setDataEnvio(LocalDateTime _dataEnvio) {
        dataEnvio = _dataEnvio;
    }

    public boolean isLida() {
        return lida;
    }

    public void setLida(boolean _lida) {
        lida = _lida;
    }

    public StatusReserva getStatus() {
        return status;
    }

    public void setStatus(StatusReserva status) {
        this.status = status;
    }
}
