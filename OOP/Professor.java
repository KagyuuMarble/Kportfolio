public class Professor extends Funcionario
{
   private int horasAula;
   //constructs
   public Professor(String nome, String telefone, Data nascimento, String registro, double salario, int horasAula)
   {
      super(nome, telefone, nascimento, registro, salario);
      this.horasAula = horasAula;
   }
   public Professor(String nome, Data nascimento, String registro, double salario, int horasAula)
   {
      super(nome, nascimento, registro, salario);
      this.horasAula = horasAula;
   }

   //gets and sets
   public int getHorasAula()
   {
      return horasAula;
   }
   public void setHorasAula(int aux)
   {
      this.horasAula = horasAula;
   }
   public double getSalarioComBonificacao()
   {
      return super.getSalario() + bonificar();
   }
   //metodos
   public double bonificar()
   {
      return horasAula*10;
   }
   //metodo toString
   public String toString()
   {
      return super.toString() + "Horas Aula:\t" +
                                horasAula + "\n";
   }
}