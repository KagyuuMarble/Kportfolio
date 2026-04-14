public class Aluno extends Pessoa
{
   private String ra;
   private int disciplinas;
   private boolean matricula;
   
   //construct
   public Aluno(String nome, String telefone, Data nascimento, String ra)
   {
      super(nome, telefone, nascimento);
      this.ra = ra;
   }
   public Aluno(String nome, Data nascimento, String ra)
   {
      super(nome, nascimento);
      this.ra = ra;
   }
   
   
   //gets and sets
   public String getRa()
   {
      return this.ra;
   }
   public int getDisciplinas()
   {
      return this.disciplinas;
   }
   public boolean getMatricula()
   {
      return this.matricula;
   }
   public double getCargaSemanal()
   {
      return this.disciplinas * 4.0;
   }
   public void setRa(String ra)
   {
      this.ra = ra;
   }
   public void setDisciplinas(int disciplinas)
   {
      this.disciplinas = disciplinas;
   }
   
   
   //metodos
   public void matricular(int disciplinas)
   {
      this.disciplinas = disciplinas;
      this.matricula = true;
   }
   
   
   //metodo toString
   public String toString()
   {
      if(matricula == true)
      {
         return super.toString() +
         "Registro Academico:\t" + ra + "\n" +
         "disciplinas:\t" + disciplinas;
      }
      else
      {
         return "nao matriculado";
      }
   }
}