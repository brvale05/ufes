public class Avaliacao {
    private int nota;
    private String comentario;

    public Avaliacao(int _nota, String _comentario) throws Exception{
        if(_nota < 0 || _nota > 5){
            throw new Exception("Nota invalida");
        } else {
            this.nota = _nota;
            this.comentario = _comentario;
        }
    }

    public void exibirAvaliacao() {
        System.out.println("Nota: " + this.nota);
        System.out.println("Comentário: " + this.comentario);
    }

    // Getters e setters
    public int getNota() {
        return nota;
    }

    public void setNota(int _nota) {
        nota = _nota;
    }

    public String getComentario() {
        return comentario;
    }

    public void setComentario(String _comentario) {
        comentario = _comentario;
    }
}
