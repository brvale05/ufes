// Por enquanto, defini o enum como público. Dependendo ele pode ser só da classe Reserva.
public enum StatusReserva {
    AGENDADA(1),
    CONFIRMADA(2),
    CANCELADA(3),
    CONCLUIDA(4),
    AVALIADO(5);

    private final int codigo;

    // Enum é tipo uma classe, então pode ter construtor
    StatusReserva(int codigo) {
        this.codigo = codigo;
    }

    public int getCodigo() {
        return codigo;
    }
}
